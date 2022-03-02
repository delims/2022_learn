//
//  main.cpp
//  shared_ptr
//
//  Created by delims on 2022/2/25.
//

#include <iostream>

#include "shared_ptr.hpp"
using namespace std;

class Apple {
public:
    int weigeht;
    Apple() {
        printf("constructor Apple %p \n",this);
    }
    ~Apple() {
        printf("destructor Apple %p \n",this);
    }
    void print() {
        printf("this is apple \n");
    }
};


template<typename T, typename... Args>
void foo1(const T& t, const Args&... rest) {
    std::cout << sizeof(T) << endl;
    cout << sizeof...(Args) << endl;//打印可变参数数量
    cout << sizeof...(rest) << endl;//打印可变参数数量
}


template <typename... Args>
class Academic {
public:
    void func(Args ... args) {
        printf("count = %ld \n",sizeof...(Args));
        printf("count = %ld \n",sizeof...(args));
    }
};
int main(int argc, const char * argv[]) {
    Academic<int,int,int> aca;
    aca.func(1, 2, 3);
    return 0;
}
    
    
//    printf("%d \n",__cplusplus);
    
//    std::cout << sizeof(shared_ptr<int>) << "\n";
//
//    shared_ptr<Apple> a = new Apple();
//
//    a->weigeht = 100;
//    a->print();
//
//    printf("%d \n",a->weigeht);
    
//    char *p = "12345";
//    ((int*)p) ++;
    

    //    Apple *a = new Apple();
    //    delete a;
    
//    printf("%d \n",a.retain_count());
//
//    shared_ptr<Apple> b = a;
//    printf("%d \n",a.retain_count());
//
//    shared_ptr<Apple> c = a;
//    printf("%d \n",a.retain_count());
//
//    shared_ptr<Apple> d = a;
//    printf("%d \n",a.retain_count());
//
    
    
    
    
    
//    printf("\n");
//    printf("\n");
//    printf("\n");
//    printf("\n");


__attribute__((destructor))
void func1() {
    printf("\n\n\n\n" );
}
//
//__attribute__((constructor))
//void func2() {
//    printf("__attribute__((constructor)) \n" );
//}
