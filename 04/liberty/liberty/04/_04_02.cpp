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



static void func() {
    long i;
    int value = *((int*)(&i + 4) + 1);
    printf("a = %x\n",value);
}

int _04_02()
{
    float a = 1;
//    int a = 0xabcdef;
    func();
    
    
    
    return 0;
}




//long a;
//int value = *((int*)(&a + 3 + 1) + 1);
//printf("a = %x\n",value);
