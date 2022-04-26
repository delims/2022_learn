//
//  _04_25.cpp
//  cpp_test
//
//  Created by delims on 2022/4/25.
//

#include <stdio.h>
#include <mutex>

#include <thread>
using namespace std;


class ReadWriteLock {
private:
    std::mutex readMutex;
    std::mutex writeMutex;
    int readCount;//已读数量
public:
    ReadWriteLock(): readCount(0) {}
    
    void readLock() {
        readMutex.lock();
        if (++readCount == 1) {
            writeMutex.lock();
        }
        readMutex.unlock();
    }
    
    void readUnlock() {
        readMutex.lock();
        if (--readCount == 0) {
            writeMutex.unlock();
        }
        readMutex.unlock();
    }
    
    void writeLock() {
        writeMutex.lock();
    }
    void writeUnlock() {
        writeMutex.unlock();
    }
};

void write_func() {
    
}

void _04_25() {
    
//    vector<int> res(1,2);
    
//    printf("%d \n",res.size());
    
    
    
}
