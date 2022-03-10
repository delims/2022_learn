//
//  main.cpp
//  mutext
//
//  Created by delims on 2022/3/9.
//

#include <iostream>
#include <mutex>

#include <chrono>
#include <thread>
using namespace std;

mutex _mutex;


int counter = 0;
void increase(int time) {
    for (int i = 0; i < time; i ++) {
        int a = i;
        int b = a;
        a = b;
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        std::lock_guard<std::mutex> _guard(_mutex);
//        _mutex.lock();
        counter++;
//        _mutex.unlock();
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
        
    int &&a = 10000;
    int &b = a;
    a = 100;
    printf("%d %p \n",a,&a);
    printf("%d %p \n",b,&b);

    
    
//    int x = 100;
//
//    int &a = x;
//    int &b = x;
//
//    printf("%d %p \n",a,&a);
//    printf("%d %p \n",a,&b);

    
//    std::thread t1(increase,10000);
//    std::thread t2(increase,10000);
//    t1.join();
//    t2.join();
//    std::cout << counter << std::endl;;
    
    return 0;
}

//int x = 100;
//
//int &&a = 10000;
//int &&b = 10000;
//
//printf("%d %p \n",a,&a);
//printf("%d %p \n",a,&b);
