//
//  main.cpp
//  file_to_binary_text
//
//  Created by delims on 2022/3/6.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    // insert code here...

//    while (1) {
//        int c = getchar();
//        if (c == 'K') abort();
//        printf("%d \n",c);
//    }

//    clock_t cl = clock();
//    sleep(2);
//    t = time(0);
//    t = t - 100;
    
    time_t rawtime;
//    struct tm *info;
    char buffer[80];
  
    time( &rawtime );
  
    struct tm *info = localtime( &rawtime );
  
    strftime(buffer, 80, "%Y%m%d %H%M%S", info);
    printf("格式化的日期 & 时间 : |%s|\n", buffer );
   
    return 0;
}

