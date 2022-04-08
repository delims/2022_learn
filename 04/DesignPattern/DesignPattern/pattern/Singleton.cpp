//
//  Singleton.cpp
//  DesignPattern
//
//  Created by delims on 2022/4/7.
//

#include <stdio.h>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

using namespace std;

class Singleton;

std::mutex _lock;

Singleton* instance = NULL;

class Singleton {
public:
    Singleton() {
        printf("create singleton \n");
    }
    static Singleton* shared() {
        if (instance) return instance;
        _lock.lock();
        if (instance == NULL) {
            instance = new Singleton();
        }
        _lock.unlock();
        return instance;
    }
    void print() {
        printf("%p\n",this);
    }
};

void runThread() {
    Singleton *shared = Singleton::shared();
    printf("size = %d\n",sizeof(*shared));
    shared->print();
}

void test_Singleton() {
    
    thread(runThread).detach();
    thread(runThread).detach();
    thread(runThread).detach();
    thread(runThread).detach();
    sleep(10);
    

}
