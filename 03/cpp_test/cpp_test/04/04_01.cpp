//
//  04_01.cpp
//  cpp_test
//
//  Created by delims on 2022/4/1.
//

#include "04_01.hpp"

//class __04_01
//{
//    char member;
//};




static void func1() {
    int a = 100;
    int b = 200;
    b = a + b;
}

static void func2(float a, double b) {
//    char a,b;
//    short c;
//    int e;
//    long d;

    float x1 = a;
    float x2 = a;
    float y1 = b;
    float y2 = b;

    
    
    printf("%f\n",a);
//    printf("%p\n",&b);
//    printf("%p\n",&c);
//    printf("%p\n",&d);
//    printf("%p\n",&e);
//    printf("%p\n",&f);
//    printf("%p\n",&h);

//    printf("%d  \n",a);
}

union _04_01_union {
    float f;
    unsigned int i;
};


void _04_01() {
    
//    func1();
//    func2(12.27,56.898);
    
//    float m = 12.465;
//    float y = 3344.6675;
//    int b = 0x12345;
    
//    cpp_test`_04_01:
//        0x100002660 <+0>:  pushq  %rbp
//        0x100002661 <+1>:  movq   %rsp, %rbp
//    ->  0x100002664 <+4>:  movss  0x95e0(%rip), %xmm0       ; xmm0 = mem[0],zero,zero,zero
//        0x10000266c <+12>: movss  %xmm0, -0x4(%rbp)
//        0x100002671 <+17>: popq   %rbp
//        0x100002672 <+18>: retq
    
    
//    0x100002660 <+0>:  pushq  %rbp
//    0x100002661 <+1>:  movq   %rsp, %rbp
//->  0x100002664 <+4>:  movss  0x95e0(%rip), %xmm0       ; xmm0 = mem[0],zero,zero,zero
//    0x10000266c <+12>: movss  %xmm0, -0xc(%rbp)
//    0x100002671 <+17>: leaq   -0xc(%rbp), %rax
//    0x100002675 <+21>: movq   %rax, -0x8(%rbp)
//    0x100002679 <+25>: popq   %rbp
//    0x10000267a <+26>: retq

    
//    float &&m = 12365.123;
    
//    float &&n = 2.34;
//    long &&x = 0xaaaaaa12a;
    
//    _04_01_union u;
//    u.i = 0x4015c28f;
//    u.i = 0x4641347e;
    
    
//     0a 00 00 00 8f c2 15 40 7e 34 41 46
    
//    __04_01 _1,_2;
    
//    printf("%f\n",u.f);
//    printf("%p\n",&n);
//    printf("%p\n",&x);

    
//    0x100002680 <+0>:  pushq  %rbp                保护rbp
//    0x100002681 <+1>:  movq   %rsp, %rbp          更新 rbp
//->  0x100002684 <+4>:  movl   -0x4(%rbp), %eax
//    0x100002687 <+7>:  movl   %eax, %ecx
//    0x100002689 <+9>:  addl   $0x1, %ecx
//    0x10000268c <+12>: movl   %ecx, -0x4(%rbp)
//    0x10000268f <+15>: movl   %eax, -0x8(%rbp)
//    0x100002692 <+18>: popq   %rbp
//    0x100002693 <+19>: retq       // rip = (%rsp); rsp = rsp + 8;


    
//    printf("%p \n%p\n",&_1,&_2);
}
