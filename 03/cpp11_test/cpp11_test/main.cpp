//
//  main.cpp
//  cpp11_test
//
//  Created by delims on 2022/3/3.
//

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
    auto func = []() {
        for (int i = 0; i <= 10; ++i) {
            cout << i << "  ";
        }
    };
    
    thread t(func);
    if (t.joinable()) {
        t.join();
    }
    
    cout << "123" << "  ";

    return 0;
}
