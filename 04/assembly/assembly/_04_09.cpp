//
//  _04_09.cpp
//  assembly
//
//  Created by delims on 2022/4/9.
//

#include <stdio.h>

extern "C" {
//extern int test(int a,void *p);
extern void func2(void(*f)(void));

}


static void func3(void) {
    
    printf("%s\n",__func__);
    
}



//{
//
//    printf("%s\n",__func__);
//    f();
//}




static void func1() {
    
//    uintptr_t p = (uintptr_t)func2;
//    printf("%d\n",test(1,(void*)p));
    
//    func2(func3);
//    void *p;
//    p = &p;
//    
//    
//    printf("%p\n",p);
//    printf("%p\n",*****************************(void******************************************)p);

    
}


class Apple {
public:
    void func(){
        
    }
};

void _04_09() {
//    func1();
//
//    Apple a;
//    a.func();
    
    
    printf("%d\n",100);
    
    
}

//0x100003f30 <+0>:  pushq  %rbp
//0x100003f31 <+1>:  movq   %rsp, %rbp
//0x100003f34 <+4>:  subq   $0x10, %rsp
//0x100003f38 <+8>:  movq   %rdi, -0x8(%rbp)
//->  0x100003f3c <+12>: callq  0x100003f50               ; func1 at _04_09.cpp:34
//0x100003f41 <+17>: addq   $0x10, %rsp
//0x100003f45 <+21>: popq   %rbp
//0x100003f46 <+22>: retq

/**
 pushq %rbp
 movq %rsp, %rbp
 subq  $0x10 , $rsp
 movq %rdi, -0x8(%rbp)
 addq $0x10, %rsp
 popq %rbp
 retq
 
 */
