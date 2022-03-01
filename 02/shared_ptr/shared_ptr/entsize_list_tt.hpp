//
//  entsize_list_tt.hpp
//  shared_ptr
//
//  Created by delims on 2022/3/1.
//

#ifndef entsize_list_tt_hpp
#define entsize_list_tt_hpp

typedef unsigned int uint32_t;

#include <stdio.h>

template <typename Element, typename List, uint32_t FlagMask>
struct entsize_list_tt {
    uint32_t entsizeAndFlags;
    uint32_t count;
    Element first;
    
    uint32_t entsize() const {
        return entsizeAndFlags & ~FlagMask;
    }
    
    uint32_t flags() const {
        return entsizeAndFlags & FlagMask;
    }
    
    Element& getOrEnd(uint32_t i) const {
        __cpp_static_assert(i <= count);
        return  *(Element*)((char*)&first + i*entsize());
    }
    
    Element& get(uint32_t i) {
        __cpp_static_assert(i < count);
        getOrEnd(i);
    }
    size_t byteSize() const {
        return byteSize(entsize(), count);
    }
    
    static size_t byteSize(uint32_t entsize, uint32_t count) {
        return sizeof(entsize_list_tt) + (count-1)*entsize;
    }
//    List *duplicate() const {
//        auto *dup = (List*)calloc(this->byteSize(),1);
//        dup->entsizeAndFlags = this->entsizeAndFlags;
//        dup->count = this->count;
//        std::copy()
//    }
    
    struct iterator;
    const iterator begin() const {
        return iterator(*static_cast<const List*>(this),0);
    }
    
};

#endif /* entsize_list_tt_hpp */
