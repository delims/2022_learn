//
//  cache_t.hpp
//  shared_ptr
//
//  Created by delims on 2022/3/2.
//

#ifndef cache_t_hpp
#define cache_t_hpp
#include <string.h>
#include <stdio.h>

struct bucket_t;

typedef unsigned int mask_t;

struct cache_t {
    struct bucket_t *_buckets;
    mask_t _mask;
    mask_t _occupied;
public:
    struct bucket_t *buckets() {return _buckets;}
    mask_t mask() {return _mask;}
    mask_t occupied() {return _occupied;}
    void incrementOccupied() {_occupied ++;}
    void setBucketsAndMask(struct bucket_t *newBuckets, mask_t newMask) {
        _buckets = newBuckets;
        _mask = newMask;
        _occupied = 0;
    }
    void initializeToEmpty() {
        memset(this, 0, sizeof(*this));
//        _buckets = (bucket_t*)&_objc_empty_cahce;
    }
    mask_t capacity() {
        return mask()? mask() + 1 : 0;
    }
    bool isConstantEmptyCache() {
//        return occupied() == 0 && buckets() == emptyBucketsForCapacity(capacity(), false);
        return occupied() == 0;
    }
    bool canBeFreed() {return !isConstantEmptyCache();}
    
    static size_t bytesForCapacity(unsigned int cap) {
//        return sizeof(bucket_t) * (cap + 1);
        return 0;
    }
};

#endif /* cache_t_hpp */
