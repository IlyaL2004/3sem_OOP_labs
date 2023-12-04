#pragma once

#include <iostream>

template<class T, class ALLOCATOR>
class Queue {
private:
	struct Elem_q;

	using alloc = typename ALLOCATOR::template rebind<Elem_q>::other;

	struct Elem_q {
		T val;
		Elem_q* next;

		Elem_q() noexcept : val(), next(nullptr) {};
		Elem_q(const T & elem) noexcept : val(elem), next(nullptr) {}

		friend std::ostream & operator << (std::ostream & out, const Elem_q & node) {
			out << node.val;
			return out;
		}

		friend bool operator == (const Elem_q & lhs, const Elem_q & rhs) {
			return &lhs.val == &rhs.val;
		}
	};

	struct eraser {
		alloc eras_elem;

		eraser() : eras_elem() {};
		eraser(alloc* another_eraser) : eras_elem(another_eraser) {}

		void operator() (void* ptr) {
			eras_elem.deallocate((Elem_q*)ptr, 1);
		}
	};

public:
	class Iterator {
	private:
		Elem_q* ptr;
	public:
		using iterator_category = std::forward_iterator_tag;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		using const_reference = const T&;
		using difference_type = std::ptrdiff_t;

		Iterator() : ptr(nullptr) {}
		Iterator(Elem_q* another_ptr) : ptr(another_ptr) {}

		Iterator & operator ++ () {
			if (this->ptr != nullptr) {
				this->ptr = this->ptr->next;
				return *this;
			} 
            else {
				throw std::logic_error("Iterator points to nullptr");
			}
		}

		bool operator != (const Iterator & iter_oth) {
			return &iter_oth.ptr->val != &this->ptr->val;
		}

		bool operator == (const Iterator & iter_oth) {
			return &iter_oth.ptr->val == &this->ptr->val;
		}

		Elem_q & operator * () {
			return *ptr;
		}

		friend std::ostream & operator << (std::ostream & out, const Iterator & it) {
			out << *(it.ptr);
			return out;
		}
	};

private:
	Elem_q* first_elem;
	eraser eras_q;

public:

	Queue() : first_elem() {};


	void pop() {
		if (first_elem) {
            Elem_q* next = first_elem->next;
            eras_q.eras_elem.deallocate(first_elem, 1);
            first_elem = next;
		} 
        else {
			throw std::logic_error("Empty!");
		}
	}

	void push(const T & elem) {
		Elem_q* new_elem = eras_q.eras_elem.allocate(sizeof(Elem_q));
		eras_q.eras_elem.construct(new_elem, elem);
		Elem_q* new_element(new_elem);
		if (!(first_elem)){
			//new_element->next = first_elem;
			first_elem = new_element;
		}
		else{
			Elem_q* cur = first_elem;
			while (cur ->next){
				cur = cur->next; 
			}
		cur->next = new_element;
		}
	}

	int size(){
		if (!(first_elem)){
			return 0;
		}
		else{
			int k = 1;
			Elem_q* top_n = first_elem;
			while (top_n ->next){
				k = k+1;
				top_n = top_n->next; 
			}
			return k;
		}
			
	}

	T top() {
		if (first_elem) {
			return first_elem->val;
		} 
        else {
			throw std::logic_error("Queue is empty!");
		}
	}

	Iterator begin() {
		return Iterator(first_elem);
	}

	Iterator end() {
		return Iterator(nullptr);
	}


};