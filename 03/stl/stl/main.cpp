//
//  main.cpp
//  stl
//
//  Created by delims on 2022/3/3.
//

#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <cstdio>
#include <pthread.h>
#include "vector.hpp"

using namespace std;

//template <class T>
//union func_union {
//    void* (*func)(void*);
//    void* (T::*p)();
//    func_union(void*(T::*p)(void)) {
//        this->p = p;
//    };
//};

class People {
public:
    People() {
        cout << "constructor " << endl;
    }
    ~People() {
        cout << "destructor " << endl;
    }
    union {
        void* (*f)(void*);
        void (People::*p)();
    };
    void func() {
        std::cout << "I am child thread " << std::this_thread::get_id() << endl;
//        return nullptr;
    }
    void func2() {
        pthread_t thread;
        p = &People::func;
        pthread_create(&thread, NULL, f , this);
        pthread_join(thread, NULL);
        std::cout << "I am parent thread " << std::this_thread::get_id() << endl;
    }
};

//class A {
//public:
//    long a;
//
//    A() {
//        printf("%p\n",this);
//    };
//    A(const A& a) {
//        printf("copy \n");
//        printf("%p \n",this);
//    };
//    void f() const {
//        delete this;
//    }
//    ~A(){
//        printf("delete \n");
//    }
//};



int main(int argc, const char * argv[]) {
    
    

//    delims::vector<int> mytest;
//    mytest.push_back(1);
//    printf("%d\n",mytest.size());
//    mytest.push_back(2);
//    printf("%d\n",mytest.size());
//    mytest.push_back(2);
//    printf("%d\n",mytest.size());
//
    
//    A *a = new A();
    
//    a->f();
//    auto func = [=]() {
//
//        if (0) {
//            a.f();
//            b.f();
////            c.f();
////            d.f();
////            e.f();
//        }
//    };
    
//    func();
    
    
    
//    People p;
//    p.func2();
    
//    People *p = (People*)::operator new(sizeof(People));
//    new(p) People();
//    p->People::People();
    
//    p->~People();
//    ::operator delete(p);
//    system("pause");
//    int arr[]  = {1,2,3,4,5,6};
//
//    printf("%d \n",&arr[4] - &arr[3]);
//    printf("%p \n",&arr[4]);
//    printf("%p \n",&arr[3]);
    
//    int abc(100);
//    printf("%d \n",abc);

    
    
    return 0;
}
