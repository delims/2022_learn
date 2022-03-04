//
//  allocator.hpp
//  stl
//
//  Created by delims on 2022/3/3.
//

#ifndef allocator_hpp
#define allocator_hpp

#include <new>
#include <cstddef> //for ptrdiff_t
#include <cstdlib>
#include <iostream>

#include <stdio.h>
using namespace std;

namespace delims {

template <class T>
inline T* allocate(ptrdiff_t size, T*) {
    T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));
    if (tmp == 0) {
        cout << "out of memory" << endl;
        exit(1);
    }
    return tmp;
}

template <class T>
inline void deallocate(T* buffer) {
    ::operator delete(buffer);
}




template <class T1, class T2>
inline void construct(T1 * p, const T2& value) {
    new(p) T1(value);
}

template <class T>
inline void destroy(T* ptr) {
    ptr->~T();
}


template <class T>
class allocator {
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    
    pointer allocate(size_type n) {
        return allocate(n,0);
    }
    
    
    
};

}




#endif /* allocator_hpp */
