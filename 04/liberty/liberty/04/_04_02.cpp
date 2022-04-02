//
//  _04_02.cpp
//  liberty
//
//  Created by delims on 2022/4/2.
//

#include "_04_02.hpp"

#include <string.h>



void func3() {
    int a;
    int b;
    printf("you invoke func3 \n");
}

//void func2() {
//    long a = 1;
//    long *p = &a;
//    uintptr_t addr = (uintptr_t)func3;
//    *(p+2) = addr;
//}

void func1() {
        
    long a = 1;
    long *p = &a;
    uintptr_t addr = (uintptr_t)func3;
    *(p+2) = addr;
}






int _04_02()
{
    func1();
    
    return 0;
    
}
