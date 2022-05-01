//
//  _04_24.cpp
//  cpp_test
//
//  Created by delims on 2022/4/24.
//

#include <stdio.h>
#include "../class.h"

void _04_24() {
    
    
    char *p1 = (char*)malloc(100);
    free(p1);
    char *p2 = (char*)malloc(100);
    char *p3 = (char*)malloc(100);

    printf("%p\n",p1);
    printf("%p\n",p2);
    printf("%p\n",p3);
    
    printf("%ld\n",p2-p1);
    printf("%ld\n",p3-p2);
    
    
    char *p_high = p3 + 100 * 2048;
    
    
//    *p_high = 'a';
    memset(p_high, 0, 2048000);
    
//    memset(p2, 0, 100);
//    printf("%d\n",*(int*)(p1-4));

    
   
    

}
