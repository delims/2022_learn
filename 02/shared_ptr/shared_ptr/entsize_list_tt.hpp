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
    
    iterator begin() {
        return iterator(*static_cast<const List*>(this),0);
    }
    
    const iterator end() const {
        return iterator(*static_cast<const List*>(this),count);
    }
    
    iterator end() {
        return iterator(*this,count);
    }

    
    struct iterator {
        uint32_t entsize;
        uint32_t index;
        Element *element;
        
        typedef Element value_type;
        typedef Element* pointer;
        typedef Element& reference;
        typedef uintptr_t difference_type;
        
        
        iterator(){}
        
        iterator(const List& list, uint32_t start = 0) : entsize(list.entsize()),index(start),element(&list.getOrEnd(start)){}
        
        const iterator& operator += (uintptr_t delta) {
            element = (Element*)((char*)element + delta * entsize);
            index += delta;
            return *this;
        }
        
        const iterator& operator -= (uintptr_t delta) {
            element = (Element*)((char*)element - delta * entsize);
            index -= delta;
            return *this;
        }
        
        const iterator& operator - (uintptr_t delta) {
            return (*this) -= delta;
        }
        
        const iterator& operator + (uintptr_t delta) {
            return (*this) += delta;
        }
        
        const iterator& operator --(int) {
            *this -= 1; return *this;
        }
        
        const iterator& operator ++(int) {
            *this += 1; return *this;
        }
        
        const iterator& operator --() {
            iterator result(*this);
            *this -= 1;
            return result;
        }
        const iterator& operator ++() {
            iterator result(*this);
            *this += 1;
            return result;
        }
        
        uintptr_t operator - (const iterator &rhs) {
            return this->index - rhs.index;
        }
        
        Element* operator *() {
            return element;
        }
        Element& operator ->() {
            return *element;
        }
        
        operator Element& () const {
            return *element;
        }
        
        bool operator == (const iterator& rhs) {
            return this->element == rhs.element;
        }
        
        bool operator != (const iterator& rhs) {
            return this->element == rhs.element;
        }
        
        bool operator < (const iterator& rhs) {
            return this->element < rhs.element;
        }
        
        bool operator > (const iterator& rhs) {
            return element > rhs.element;
        }

    };
    
    
};

#endif /* entsize_list_tt_hpp */
