//
//  _05_11.cpp
//  cpp_test
//
//  Created by delims on 2022/5/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long rabbit(long year) {
    if (year == 1) return 1;
    if (year == 2) return 1;
    long *memo = (long*)malloc(sizeof(long) * year);
    if (memo == NULL) return -1;
    memset(memo, 0, sizeof(long) * year);
    memo[0] = 1;
    memo[1] = 1;
    int i = 2;
    while (i < year) {
        memo[i] = 1;
        for (int j = 0; j <= i - 2; j ++) memo[i] += memo[j];
        i++;
    }
    long res = memo[year-1];
    free(memo);
    return res;
}

void _05_11() {
    
    long year = 15;
    printf("after %ld years, rabbits count = %ld \n\n",year,rabbit(year));
    
}


/*
 50 years count = 12586269025

 1 2 3 4 5
 1 1 2 3 5
 */
