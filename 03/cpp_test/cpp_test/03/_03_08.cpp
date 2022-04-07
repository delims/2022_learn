//
//  _03_08.cpp
//  cpp_test
//
//  Created by delims on 2022/3/8.
//

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include <io.h>
#include <stdio.h>
#include <vector>
#include <list>
#include <stack>

void bubble_sort(int array[], size_t size) {
    for (int i = 0; i < size - 1; i ++) {
        for (int j = 0; j < size - 1 - i; j ++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void insert_sort(int array[], size_t size) {
    for (int i = 1; i < size; i ++) {
        int value = array[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (array[j] > value) {
                array[j + 1] = array[j];
            } else break;
        }
        array[j+1] = value;
    }
}




void _03_08(const char* path) {
    

    
//    char buffer[1024] = {0};
    
//    int fd = open(path, O_RDONLY);
//    read(fd, buffer, 1024);
    
//    FILE *f = fopen(path, "r");
//    size_t size = fread(buffer, 1024, 1, f);
    
    
//    printf("%s\n",buffer);
//    std::stack<int> a;
//    a.
//    std::list<int> list;
//    list.push_back(1);
//    list.push_back(1);
//    list.remove(1);
//
//    for (int x : list) {
//
//    }
//
//    int array[] = {23,2,7,5,11,8,3,6,4};
//    size_t size = sizeof(array)/sizeof(int);
//
////    bubble_sort(array, size);
//    insert_sort(array, size);
//
//    for (int x:array) {
//        printf("%d \n",x);
//    }
//
//    std::stack<int> sta;
//
    
    
    
    
//    printf("%lu %p\n",list.size(),list.end());

}
