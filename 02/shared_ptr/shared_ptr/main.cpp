//
//  main.cpp
//  shared_ptr
//
//  Created by delims on 2022/2/25.
//

#include <iostream>

#include "shared_ptr.hpp"

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



int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    printf("%d \n",__cplusplus);
    
    std::cout << sizeof(shared_ptr<int>) << "\n";
    
    shared_ptr<Apple> a = new Apple();
    
    a->weigeht = 100;
    a->print();
    
    printf("%d \n",a->weigeht);
    
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
    return 0;
}

__attribute__((destructor))
void func1() {
    printf("\n\n\n\n" );
}
//
//__attribute__((constructor))
//void func2() {
//    printf("__attribute__((constructor)) \n" );
//}
