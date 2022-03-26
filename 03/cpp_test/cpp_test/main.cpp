//
//  main.cpp
//  cpp_test
//
//  Created by delims on 2022/3/1.
//

#include <iostream>
#include <sys/fcntl.h>
#include <vector>
#include <thread>

//extern void _03_07();
//extern void _03_14();
//extern void _03_18();
extern void _03_21();

struct ABC {
    ABC(int &i,int &j):a(i),b(j){}
    int &a;
    int &b;
};

//快速排序
void quick_sort1(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];
            
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort1(s, l, i - 1); // 递归调用
        quick_sort1(s, i + 1, r);
    }
}

void quick_sort(int s[],int l ,int r)
{
    if (l >= r) return;
    int i = l, j = r, x = s[i];
    while (i < j) {
        while (i < j && s[j] >= x) j--;
        if (i < j) s[i++] = s[j];
        while (i < j && s[i] < x) i++;
        if (i < j) s[j--] = s[i];
    }
    s[i] = x;
    quick_sort(s, l, i-1);
    quick_sort(s, i+1, r);
}

class X {
public:
    int x = 0xeeeeeeeeU;
    void func(){
        std::cout << "end \n" << std::endl;
    }
};

class A : public  X{
public:
    int a;
};

class B : public X{
public:
    int c;
};

class C : public  X {
//    virtual void func1() {};
public:
    int b = 0xffffffffU;
    void func(){
        std::cout << "i am c\n" << std::endl;
    }
};


class QingBing {
public:
    QingBing *ptr;
};

int main(int argc, const char * argv[]) {
    
//    QingBing a;
//    int i;
//    int j;
//    ABC a(i,j);
//
//    int array[] = {2,4,5,2,34523,453,65,65,67,67,34,32,2,34,5,11,2,34,534,46,67,78,43};
//
//
//    quick_sort(array, 0, sizeof(array)/sizeof(int)-1);
//
//    for (int x: array) printf("%d ",x);
    
//    C c;
//    c.X::func();
//
//    char *str = "0.361r";
//    char *p;
//    int d = strtod(str, &str);
//    printf("%lu :%s \n",d,str);

    
    
//    _03_09(argv[1]);
    
//    _03_14();
    
    _03_21();

//    c.a = 120;
    
//    printf("%lu \n",sizeof(c));
//    printf("%lu \n",c.a);

//    printf("%d\n",sizeof(a));
    
    return 0;
}

