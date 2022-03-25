//
//  _03_25.cpp
//  cpp11_test
//
//  Created by delims on 2022/3/25.
//

#include "_03_25.hpp"

//#include <function>
#include <future>
#include <iostream>
#include <thread>
#include <functional>
#include <unistd.h>

using namespace std;

struct obj {
    obj(){
        printf("obj constructor \n");
    }
    obj(const obj &o) {
        printf("obj copy \n");
    }
    void func() {
        printf("obj func \n");

    }
};


void func(std::future<obj>& fut) {
//    obj x = fut.get();
//    printf("value:%f\n",x);
//    cout << "value: " << x << endl;
//    x.func();
    fut.get().func();
    
//    cout << "child" << std::this_thread::get_id() << endl;
}


void _03_25() {

//    int arr[2][2] = {{1,2},{3,4}};
//    int **ptr = (int**)arr;
//    printf("%d\n",*ptr);
//    printf("%p\n",arr);
//    printf("%p\n",arr[0]);
//    printf("%p\n",arr[1]);
    
//    auto f = [](){
//        printf("hello \n");
//    };
    
//    auto f2 = [](int a){
//    };

//    f();

//    printf("%p\n",func);
//    printf("%p\n",f);
//    printf("%p\n",f2);
    
    obj o;

    std::promise<obj> prom;
    std::future<obj> fut = prom.get_future();
    
    std::thread t(func,std::ref(fut));
    
//    prom.set_value(144);
    
    t.detach();
    
    
    sleep(4);
    
    prom.set_value(o);
    
//    cout << "main:" << std::this_thread::get_id() << endl;

    sleep(3);

}
