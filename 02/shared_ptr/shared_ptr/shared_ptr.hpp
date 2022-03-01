//
//  shared_ptr.hpp
//  shared_ptr
//
//  Created by delims on 2022/2/25.
//

#ifndef shared_ptr_hpp
#define shared_ptr_hpp

#include <stdio.h>

#define PTR_MASK 0x7fffffffffff
#pragma pack(1)
template <typename T>
class shared_ptr {
public:
    shared_ptr():ptr(0),count_ptr(0){}
    shared_ptr(const shared_ptr<T> &another) {
        count_ptr = another.count_ptr;
        ptr = another.ptr;
        retain();
    }
    shared_ptr(T *p) {
        ptr = PTR_MASK & (uintptr_t)p;
        count_ptr = PTR_MASK & (long)new int(1);
    }
    T* operator-> (){
        return (T*)ptr;
    }
    
    T& operator *(){
        return *(T*)ptr;;
    }
    
    shared_ptr<T>& operator =(const shared_ptr<T> &anther) {
        if (ptr && retain_count()) release();
        ptr = anther.ptr;
        count_ptr = anther.count_ptr;
        retain();
    }
    
    void retain() {
        ++*(int*)count_ptr;
    }
    void release() {
        --*(int*)count_ptr;
        if (retain_count() == 0) {
            delete (T*)ptr;
            delete (int*)count_ptr;
        }
    }
    int retain_count(){
        return *(int*)count_ptr;
    }
    ~shared_ptr() {
        release();
    }
private:
    uintptr_t count_ptr  :48;
    uintptr_t ptr        :48;
};

#endif /* shared_ptr_hpp */

