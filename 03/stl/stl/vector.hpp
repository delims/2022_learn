//
//  vector.hpp
//  stl
//
//  Created by delims on 2022/3/4.
//

#ifndef vector_hpp
#define vector_hpp

#include <cstddef>

#include <stdio.h>
#include <string.h>

namespace delims {




template <class T>
class vector {
public:
    typedef T           value_type;
    typedef value_type* pointer;
    typedef value_type* iterator;
    typedef value_type& reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;
protected:
    iterator start;
    iterator finish;
    iterator end_of_storage;
    
    void deallocate() {
        if (start) {
            
        }
    }
    
public:
    iterator begin() {return start;}
    iterator end() {return finish;}
    size_type size() { return size_type(finish - start);}
    size_type capacity() const {return size_type(end_of_storage - start);}
        
    void fill_initialize(size_type n, const T& value) {
        
    }
    
    vector():start(0),finish(0),end_of_storage(0){}
    vector(size_type n, const T& value) {
        
        for (int i = 0; i < n; i ++) {
            this->push_back(value);
        }
    }
    
    void push_back(const T& value) {
        if (finish == end_of_storage) expand();
        construct(finish++, value);
    }
    
    void pop_back() {
        destroy(finish--);
    }

    iterator allocate_and_fill (size_type n, const T& value) {
    }
    
    reference operator[](int i) {
        return *(start + i);
    }
    reference at(int i) {
        return *(start + i);
    }
    void resize(size_type size) {
        
    }
    void expand() {
        const size_type old_capacity = capacity();
        const size_type new_capacity = old_capacity ? 2 * old_capacity : 1;
        iterator new_start = allocate(new_capacity);
        iterator new_finish = new_start;
        uninitialized_copy(start, finish, new_start);
        new_finish = new_start + size();
        end_of_storage = new_start + new_capacity;
        start = new_start;
        finish = new_finish;
    }
    
    inline void construct(iterator p,const T& value) {
        new (p) T(value);
    }
    inline void destroy(iterator ptr) {
        ptr->~T();
    }
    
    iterator allocate(size_type n) {
        return (iterator)(::operator new(n * sizeof(T)));
    }
    
    iterator uninitialized_copy(iterator src_start, iterator src_end, iterator new_start) {
        memcpy(new_start, src_start, (src_end - src_start)*sizeof(value_type));
        return new_start;
    }
    
private:
    size_type value_size() {
        return sizeof(value_type);
    }
};


}

#endif /* vector_hpp */
