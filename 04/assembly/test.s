//
//  test.s
//  assembly
//
//  Created by delims on 2022/4/9.
//


# exit.s
#    .section    __TEXT,__text
.text
.globl  _func2
_func2:

pushq  %rbp
movq   %rsp, %rbp
subq   $0x10, %rsp
movq   %rdi, -0x8(%rbp)
leaq   0x93(%rip), %rdi
leaq   0x96(%rip), %rsi
movb   $0x0, %al
callq  *-0x8(%rbp)
addq   $0x10, %rsp
popq   %rbp
retq
