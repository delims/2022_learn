//
//  _04_28.cpp
//  cpp_test
//
//  Created by delims on 2022/4/28.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/*
C/C++上机题：
1.写一个函数处理文件路径：输入任何一个路径字符串，把它转换成不含.和..的绝对文件路径，对不合法的路径/错误的路径给出提示
比如：c:\1\2\..\3\.\1.txt  输出c:\1\3\1.txt
比如：c:\1\3\1.txt  输出c:\1\3\1.txt
2.把一个文本文件中的内容做如下转换后（假定文件大小不大于10M字节），生成另一个新的文件
把文件中的所有*号提前，放在文件的最前面，其它内容不变，保存为一个新文件
比如：hello *wor*ld*  处理后新文件的内容为:***hello world
要求：
1.上面两个功能由main函数调用
2.注意程序执行效率、可维护性（易维护/易读懂/）、可移植性(主要指源码在Windows和Linux上都可编译通过)
3.代码风格好，注释合理到位，完成时间不得超过2小时（应届毕业生可以是2.5小时）
4.思路清晰易懂，时间和空间开销尽量最优化
5.使用C语言实现,不得使用C++语言
 */
#define BOOL int
#define true 1
#define false 0

struct Node{
    struct Node *pre;
    struct Node *next;
    const char *value;
};

BOOL is_double_dot(const char *name) {
    return strlen(name) == 2 && name[0] == '.' && name[1] == '.';
}

BOOL is_single_dot(const char *name) {
    return strlen(name) == 1 && name[0] == '.';
}
BOOL is_available_path(const char *name) {
    size_t len = strlen(name);
    if (len == 0) return false;
    for (int i = 0 ;i < len ;i ++) {
        if (name[i] == '/') return false;
        if (name[i] == '*') return false;
        if (name[i] == '?') return false;
        if (name[i] == '=') return false;
    }
    return true;
}

char *handle_path(const char *path) {
    size_t len = strlen(path);
    char *src = (char*)malloc(len+1);
    if(src == NULL) {
        printf("malloc failure \n");return NULL;
    }
    strcpy(src, path);
    for (int i = 0 ;i < len; i ++) {
        if (src[i] == '\\') src[i] = '\0';
    }
    
    struct Node dummy;
    memset(&dummy, 0, sizeof(struct Node));
    struct Node *pre = &dummy;
    struct Node *cur = pre;
    cur->value = src;
    
    for (int i = 0; i < len; i ++) {
        if (src[i] != 0) continue;
        cur->next = (struct Node*)malloc(sizeof(struct Node));
        if(cur->next == NULL) {
            printf("malloc failure \n");return NULL;
        }
        memset(cur->next, 0, sizeof(struct Node));
        cur->next->pre = cur;
        cur = cur->next;
        cur->value = src + i + 1;
    }
    
    struct Node *temp = pre;
    while (temp && temp->value) {
        if (is_available_path(temp->value) == false) return NULL;
        if (is_double_dot(temp->value)) {
            if (temp->pre == NULL || temp->pre->value == NULL) return NULL;
            if (temp->next == NULL ) return NULL;
            
            struct Node *temp1 = temp;
            struct Node *temp2 = temp->pre;
            struct Node *next = temp->next;
            
            temp->next->pre = temp->pre->pre;
            temp->pre->pre->next = temp->next;
            temp = next;
            
            free(temp1);
            free(temp2);
        } else if (is_single_dot(temp->value)) {
            if (temp->next == NULL ) return NULL;
            
            struct Node *next = temp->next;
            struct Node *temp1 = temp;
            
            temp->next->pre = temp->pre;
            temp->pre->next = temp->next;
            
            free(temp1);
            temp = next;
        } else temp = temp->next;
//        printf("%s \n",temp->value);
//        temp = temp->next;
    }
    
    char *res = (char*)malloc(len+1);
    if(res == NULL) {
        printf("malloc failure \n");return NULL;
    }
    memset(res, 0, len+1);
    temp = pre;
    int i = 0;
    while (temp && temp->value) {
//        printf("%s \n",temp->value);
        strcpy(res+i, temp->value);
        i += strlen(temp->value);
        struct Node *next = temp->next;
        if (temp != pre) free(temp);
        temp = next;
        if (temp) res[i++] = '\\';
    }
//    printf("%s \n",res);
    return res;
}


void move_star_forward(const char *path) {
    char star = '*';
    int in_fd = open(path, O_RDONLY);
    if (in_fd < 0) {
        printf("error: %s \n",strerror(errno));
        return;
    }
    char c;
    int star_count = 0;
    while (read(in_fd, &c, 1) == 1) {
        if (c == star) star_count ++;
    }
    lseek(in_fd, 0, SEEK_SET);
    
    char *out_path = (char*)malloc(strlen(path) + 5);
    if(out_path == NULL) {
        printf("malloc failure \n");
        close(in_fd);
        return;
    }
    
    strcpy(out_path, path);
    strcat(out_path, ".out");
    
    int out_fd = open(out_path,O_RDWR | O_CREAT, S_IRWXU);
    free(out_path);
    if (out_fd < 0) {
        printf("error: %s \n",strerror(errno));
        return;
    }
    
    while (star_count--) {
        if(write(out_fd, &star, 1) < 1) {
            printf("write file error: %s \n",strerror(errno));
            return;
        }
    }
    
    while (read(in_fd, &c, 1) == 1) {
        if (c != star)
        if(write(out_fd, &c, 1) < 1) {
            printf("write file error: %s \n",strerror(errno));
            return;
        }
    }
    close(in_fd);
    close(out_fd);
}


void _04_28(void)
{
    
//    move_star_forward("/Users/delims/Desktop/1.txt");
//    handle_path("c:\\1\\2\\..\\3\\.\\1.txt");
    
    char *output = handle_path("c:\\1\\2\\..\\3\\4\\..\\5\\.\\1.txt");
    if (output) {
        printf("%s\n",output);
        free(output);
    } else {
        printf("unavailable path \n");
    }
}


