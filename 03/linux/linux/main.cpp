//
//  main.cpp
//  linux
//
//  Created by delims on 2022/3/24.
//

#include <iostream>

extern "C"
{
extern void _03_24();
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    _03_24();
    
    return 0;
}
