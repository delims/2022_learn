//
//  _03_24.c
//  linux
//
//  Created by delims on 2022/3/24.
//

#include "_03_24.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void _03_24(void)
{
//    pid_t pid = getpid();
//    void *p = malloc(10);
    
    int a = 0;
    int b = 0;
    int c = 0;
    printf("%p \n",&a);
    printf("%p \n",&b);
    printf("%p \n",&c);
    int *p = &c;
    
    int *p2 = p + 256 * 4;
    
    printf("%p \n",p2);
    printf("%d \n",*p2);

//    int arr[1024*1024];
//    memset(arr, 0, sizeof(arr));
//    pause();
//    printf("%d\n",pid);
    
}
