#include <iostream>
#include <memory>
#include <list>
#include <utility>
#include <array>

#define SIZE_B 1024

using std::array;

namespace My_Allocator {
    template <class T>
    class Allocator {
    private:
        array<T, SIZE_B> _used_blocks;
        array<T*, SIZE_B> _free_blocks;
        size_t _free_count;

    public:
        static constexpr size_t max_count = SIZE_B;
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;

        Allocator() {   

            for (size_t i = 0; i < max_count; i++) {
                _free_blocks[i] = &_used_blocks[i];
            }
            _free_count = max_count;
        }

        ~Allocator() {
#ifdef DEBUG
            if (_free_count < max_count)
                std::cout << "allocator: Memory leak?" << std::endl;
            else
                std::cout << "allocator: Memory freed" << std::endl;
#endif

        }

        template <class U>//аллокатор другого типа
        struct rebind {
            using other = Allocator<U>;
        };

        T *allocate(size_t n) {
            T *result = nullptr;
            if (_free_count > 0) {
                result = (T *)_free_blocks[--_free_count];
            }
            else {
                throw std::logic_error("allocator: No memory exception :-)");
            }
            return result;
        }

        void deallocate(T *pointer, size_t) {
#ifdef DEBUG
            std::cout << "allocator: Deallocate block " << std::endl;
#endif      
            if (_free_count + 1 >= max_count) {
                return; 
            }
            _free_blocks[_free_count++] = pointer;
        }
        template <typename U, typename... Args>
        void construct(U *p, Args &&...args) {
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p) {
            p->~T();
        }
    }; 

    template <class T, class U>
    constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs) {
        return true;
    }

    template <typename T, typename U, size_t BLOCK_COUNT>
    constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs) {
        return false;
    }
}