#pragma once

#include <memory>

template <class T>

class Array
{
public:
    Array() : _size(0), _array{nullptr} {}

    Array(const Array &other)
    {
        _size = other._size;
        _array = std::shared_ptr<T[]>(new T[_size]);

        for (size_t i{0}; i < _size; ++i)
            _array[i] = other._array[i];
    }

    Array(const std::initializer_list<T> &t)
    {
        _array = std::shared_ptr<T[]>(new T[t.size()]);
        size_t i{0};
        for (auto &c : t)
            _array[i++] = c;
        _size = t.size();
    }

    T& operator[](size_t index){
        if((index < 0) || (index >= _size)){
            throw std::logic_error("Invalid array index!");
        }
        return _array[index];
    }

    size_t size() const{
        return _size;
    }



    void del_ind(int num){
        int d = 0;
        int s = this->_size;
        if((num > 0) && (num < s)) {
            std::shared_ptr<T[]> array1 = std::shared_ptr<T[]>(new T[s - 1]);
            for (int i = 0; i < s; i++) {
                if(i == num) {
                    d = 1;
                }
                else
                    array1[i - d] = _array[i];
            }
            this->_array = array1;
            this->_size = s - 1 ;
        }
        else{
            throw std::logic_error("Invalid index!");
        }
    }




    ~Array() noexcept
    {
        if (_size > 0)
        {
            _size = 0;
            for (int i = 0; i < _size; i++) {
                delete _array[i].get();
            }
            _array = nullptr;
        }
    }

private:
    size_t _size;
    std::shared_ptr<T[]> _array;
};