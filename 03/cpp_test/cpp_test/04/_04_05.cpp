//
//  _04_05.cpp
//  cpp_test
//
//  Created by delims on 2022/4/5.
//

#include "_04_05.hpp"
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <errno.h>


class _Apple {
public:
//    _Apple(int x,int y){}
    int a;
    int b;
//    _Apple(int x,int y):a(x),b(y) {
//        cpp_test`_Apple::_Apple:
//            0x10000b470 <+0>:  pushq  %rbp
//            0x10000b471 <+1>:  movq   %rsp, %rbp
//            0x10000b474 <+4>:  movq   %rdi, -0x8(%rbp)//this
//            0x10000b478 <+8>:  movl   %esi, -0xc(%rbp)//a
//            0x10000b47b <+11>: movl   %edx, -0x10(%rbp)//b
//            0x10000b47e <+14>: movq   -0x8(%rbp), %rax //this
//            0x10000b482 <+18>: movl   -0xc(%rbp), %ecx //move a to ecx
//            0x10000b485 <+21>: movl   %ecx, (%rax)  // move a to this position
//            0x10000b487 <+23>: movl   -0x10(%rbp), %ecx //move b to ecx
//            0x10000b48a <+26>: movl   %ecx, 0x4(%rax) move b to (this+0x4) postion
//        ->  0x10000b48d <+29>: popq   %rbp
//            0x10000b48e <+30>: retq
//
//        _Apple(int x,int y) {
//        a = x;
//        b = y;
//        cpp_test`_Apple::_Apple:
//            0x10000b470 <+0>:  pushq  %rbp
//            0x10000b471 <+1>:  movq   %rsp, %rbp
//            0x10000b474 <+4>:  movq   %rdi, -0x8(%rbp)
//            0x10000b478 <+8>:  movl   %esi, -0xc(%rbp)
//            0x10000b47b <+11>: movl   %edx, -0x10(%rbp)
//            0x10000b47e <+14>: movq   -0x8(%rbp), %rax
//        ->  0x10000b482 <+18>: movl   -0xc(%rbp), %ecx
//            0x10000b485 <+21>: movl   %ecx, (%rax)
//            0x10000b487 <+23>: movl   -0x10(%rbp), %ecx
//            0x10000b48a <+26>: movl   %ecx, 0x4(%rax)
//            0x10000b48d <+29>: popq   %rbp
//            0x10000b48e <+30>: retq
//    }
    
};


void _04_05() {
    
//    _Apple a;
    
//    int x;
//    int y;
//
    
    
    
    
//    key_t key = ftok("./", 88);
//
//    int shid = shmget(IPC_PRIVATE, 8, IPC_CREAT);
//    printf("ret = %d  %s \n",shid,strerror(errno));
//    void *p = shmat(shid, nullptr, SHM_R);
//    printf("ret = %p  %s \n",p,strerror(errno));

}
