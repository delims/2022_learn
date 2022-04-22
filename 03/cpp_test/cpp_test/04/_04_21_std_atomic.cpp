//
//  _04_21_std_atomic.cpp
//  cpp_test
//
//  Created by delims on 2022/4/21.
//

#include <stdio.h>
#include <mutex>
#include <atomic>

using namespace std;


void _04_21() {
    atomic<int> a = 1;
    
    a ++;
    
}



class rwlock {
private:
    std::mutex _lock;
    atomic<int> status;
public:
    void writeLock() {
        
    }
    
    void readLock() {
        
    }
    
    void unlock() {
        
    }
};
