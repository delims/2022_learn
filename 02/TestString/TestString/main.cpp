//
//  main.cpp
//  TestString
//
//  Created by delims on 2022/1/26.
//

#include <iostream>
#include <vector>
#include <stdarg.h>
using namespace std;



struct Fruit {
    virtual void color() {
        
    };
    virtual void shape() {
        
    };
    
    ~Fruit(){
        printf("Fruit release \n");

    }
};


struct Apple : public Fruit{
public:
//    virtual void color() override{
//
//    };
//    string a;
    int weight;
//    string b;
    ~Apple(){
        printf("apple release \n");
    }
    
    explicit Apple(Apple const &a) {
        printf("copy constructor const -- %s\n",__func__);
    }
    Apple(Apple &a) {
        printf("copy constructor & -- %s\n",__func__);
    };
    Apple() {
        printf("default constructor -- %s\n",__func__);
    }
    
    void operator=(Apple &a) {
        printf("operator = -- %s\n",__func__);
    }
    
    void Test() {
        printf("%s \n",__func__);
    }
    static void Test_static() {
        printf("%s \n",__func__);
    }
    Apple operator++() {
        printf("operator = ++A %s\n",__func__);
        return *this;
    }

    Apple operator++(int a) {
        printf("operator = A++ %s arg= %d\n",__func__,a);
        return *this;
    }
    
    void qingbing1(const Apple &&a){
        
//        Apple b;
//        a = b;
        printf("qingbing1 \n");
//        Apple b = a;
    }

};

//union isa_t {
//    isa_t(){}
//    isa_t(uintptr_t value) : bits(value){}
//    uintptr_t cls;
//    uintptr_t bits;
//    struct {
//        ISA_BITFIELD;
//    };
//};



void test(Apple *a){
    
//    string c = "123456";
//    c += "7890";
//    c += "123456";
//    c += "123";
    
//    A x;
    
//    x.a = "12345";
//    x.a += "12345";
//    x.a += "123";
//
//    cout << x.a << endl;
//
//    memcpy(a, &x, sizeof(x));
//    memcpy(&b, &c, size(c));
}

void b(){
    
}

void testAppleCopy(int c){
    
//    printf("c= %p \n", c);
}

//void func(int a,...) {
//
////    printf("%s \n","hello");
//    va_list list;
//    va_start(list, a);
//
//    for (int i = 0 ; i < 11; i ++) {
//        printf("%d \n",va_arg(list, long));
//    }
//    va_end(list);
//}

//template<typename T, typename... Args>
//void foo(const T& t, const Args&... rest) {
//    std::cout << sizeof(T) << endl;
//    cout << sizeof...(Args) << endl;//打印可变参数数量
//    cout << sizeof...(rest) << endl;//打印可变参数数量
//}


union obj{
    struct {
        int *p;
        int a;
        int b;
    };
//    struct {
//        int b;
//        int c;
//    };
    Apple f;
    obj(){
        memset(this, 0, 16);
    }
};


int main2(int argc, const char * argv[]) {
    
//    Apple a;
//
//    obj o;
//    o.f = a;
//    o.f.weight = 56982;
//
//    printf("%p \n",o.p);
//    printf("%d \n",o.a);
//    printf("%d \n",o.b);

    
    
    
//    obj o;
    
//    o.a = 1245667;
//    printf("%p \n",&(o.b));
//    printf("%p \n",&(o.a));
//    printf("%p \n",&(o.c));

    
//    int &&b = 10;
    
//    printf("%p \n",&b);
//    0x7ff7bfeff31c
    
    
//    testAppleCopy(10);
    
//    int &&a = 10;
//    int b = 10;
////    int &c = b;
//
//    printf("%p \n",&a);
//    printf("%p \n",&b);

//    foo(a,a,a,a,a);
    
    // insert code here...
//    std::cout << "Hello, World!\n";
    
//    Apple a;
//    Apple b(a);
//    testAppleCopy(a);

//    Apple b = a;
//    Apple a;
//    testAppleCopy(a);
    
//    Apple c = a;
    
//    Apple d = a;

    
//    printf("%p \n",&Apple::Test);
//
//    printf("%p \n",&Apple::Test_static);
//    printf("%p \n",Apple::Test_static);

    
//    func(1,2,3);
//    d = a;
    
//    Apple c = a;
    
//    c = a;
    
//    vector<Apple> arr;
//    arr.clear();
//    arr.push_back(a);
//
//    arr.push_back(a);
//    c = a;
//    ++ c;
//    c ++;
//    string a = "abcde";
//    string b = "";
//    string a = "";
//    test(&a);
//    printf("%s \n",a.c_str());
//    cout << a << endl;
    
//    A a;
//    test(&a);

//    cout << a.a << endl;
    
//    printf("PATH : %s\n", getenv("HOME"));
//    printf("NSZombiesEnabled : %s\n", getenv("DYLD_INSERT_LIBRARIES"));

//    char s[80];// = {0};
    
//    asprintf(s, "%d--%d--%d",1,1,1);
//    printf("%s\n",s);
    
//    printf("\n");
    
//    for (int i = 0 ; i < 100; i ++) {
//        printf("%d \n",*(s+i));
//    }
    return 0;
    
}


class Base {
public:
    int m_tag;
public:
    Base(int tag) : m_tag(tag) {}
    
    void print() {
        cout << "Base::print() called" << endl;
        printf("this = %p \n",this);
    }
    
    virtual void vPrint1() {
        cout << "Base::vPrint1() called" << endl;
    }
    virtual void vPrint2() {
        cout << "Base::vPrint2() called" << endl;
//        printf("this = %p \n",this);

    }
    virtual void vPrint3() {
        cout << "Base::vPrint3() called" << endl;
    }
    virtual void vPrint4() {
        cout << "Base::vPrint4() called" << endl;
    }
    virtual void vPrint5() {
        cout << "Base::vPrint5() called" << endl;
    }
    virtual void vfun1() {
        cout << "Base::vfun1() called" << endl;
    }
    virtual void vfun2() {
        cout << "Base::vfun2() called" << endl;
    }
    virtual void vfun3() {
        cout << "Base::vfun3() called" << endl;
    }
    virtual void vfun4() {
        cout << "Base::vfun4() called" << endl;
    }
    virtual void printTag() {
        cout << "Base::m_tag of this instance is: " << m_tag << endl;
    }
};

//class Derived : public Base {
//public:
//    Derived(int tag) : Base(tag) {
//        m_tag = 1500;
//    }
//
//    void print() {
//        cout << "Derived1::print() called" << endl;
//    }
//
//    void vPrint() {
//        cout << "Derived::vPrint() called" << endl;
//    }
//    void printTag() {
//        cout << "Derived::m_tag of this instance is: " << m_tag << endl;
//    }
//};

int drink2(int n) {
    int water = 0;
    int cover = 0;
    int bottle = 0;
    
    while (n >= 2 || cover >= 4 || bottle >= 2) {
        if (n >= 2) {
            n -= 2;
            cover ++;
            bottle ++;
            water ++;
        }
        if (cover >= 4) {
            cover -= 4;
            cover ++;
            bottle ++;
            water ++;
        }
        if (bottle >= 2) {
            bottle -= 2;
            cover ++;
            bottle ++;
            water ++;
        }
    }
    
    return water;
    
}
int drink(int money) {
    int bottles = money / 2;
    int res = 0;
    for(int i = 1; i <= bottles; i++) {
        res++;
        if(i % 2 == 0) {
            bottles++;
        }
        if(i % 4 == 0) {
            bottles++;
        }
    }
    return res;
}



int main(int argc, const char * argv[]) {
    
//    std::shared_ptr<int> ptr = std::make_shared<int>(1200);
//    {
//        std::shared_ptr<int> ptr2 = ptr;
//        printf("%d \n",ptr.use_count());
//
//    }
    
    Apple a;
    
//    char str[] = "";
//
//    printf("%s %d \n",__func__,sizeof(str));
//    printf("%p \n","123");
//    printf("%p \n","123");
//    printf("%p \n","123");

//    printf("%d \n",ptr.use_count());
//    Apple a;
//    vector<Apple> v;
//    v.push_back(a);

//    a.qingbing1(std::move(a));
    
//    auto a = 1.234;
//
//    printf("%s \n",typeid(a).name());
//
//    1 + 0.5 + 0.25
//    1.75
//
    
//    printf("%s \n",argv[0]);
//    Base *foo = new Base(1200);
//
//    foo->print();
//    foo->Base::print();
//    foo->Base::vPrint();
//    foo->vPrint();
//
//    foo->printTag();
//
//    Derived foo2(1);
//    foo2.Base::print();
    
    
//    printf("%lx \n", *(unsigned long*)foo);
//    printf("%ld \n\n", *((int *)foo + 2));

//    printf("%lx \n", **(unsigned long**)foo);
//    printf("%lx \n", *(*(unsigned long**)foo + 1)); //100004048
//    printf("%lx \n", *(*(unsigned long**)foo + 2)); //100004048
//    printf("%lx \n", *(*(unsigned long**)foo + 3)); //100004048
//    printf("%lx \n", *(*(unsigned long**)foo + 4)); //100004048
//    printf("%lx \n", *(*(unsigned long**)foo + 5)); //100004048
//    printf("%lx \n", *(*(unsigned long**)foo + 6)); //100004048
//    printf("%lx \n", *(*(unsigned long**)foo + 7)); //100004048
//    printf("%lx \n\n", *(*(unsigned long**)foo + 8));

//    printf("%ld \n", foo->m_tag);

    
    
//    printf("%p \n",&Base::print);
//    printf("%d \n",&Base::vPrint1);
//    printf("%d \n",&Base::vPrint2);
//    printf("%d \n",&Base::vPrint3);
//    printf("%d \n",&Base::vPrint4);
//    printf("%d \n",&Base::vPrint5);
//
//
//
//
//
//    void (Base:: *vPrint)(void) = &Base::vfun3;
//    long offset;
//    memcpy(&offset, &vPrint, 8);
//    printf("offset = %p \n",offset);
//
//    long vp = *(long *)foo;
//
//    printf("vtable = %p \n",vp);
//    printf("foo    = %p \n",foo);
//
//    long* funcp = (long*)(vp + offset -1);
//
//    printf("func   = %p \n",funcp);
//
//    void (*func)(void*);
//    memcpy(&func, funcp, 8);
//
//    func(foo);
    
//    long off;
//
//    printf("vp = %p \n",vp);
//    vp += off;
//
//    printf("vp = %p \n",vp);
//
//    printf("offset = %p \n",offset);
//
//    void(*func)(Base *);
//    memcpy(&func, vp, 8);
//    printf("func = %p \n",vp);
//    printf("func = %p \n",func);
//
//    func(foo);
    
//    void (*func1)(void*) = &Base::print;
    
    
    
//    printf("p =  %p \n",&Base::print);
//
//    void (Base:: *p)() = &Base::print;
//
//    printf("p =  %p \n",p);
//
//    void (*func1)(void*);
//    memcpy(&func1, &p, 8);
//
//    func1(foo);
//
//    printf("%p \n",&Base::print);
//    printf("%p \n",&Base::vPrint);
    

}



char *strcpy(char *dest, const char *src)
{
    assert(dest!= NULL && src!=NULL);
    char *address = dest;
    while ((*address ++ = *src ++) != 0);
    return address;
}
