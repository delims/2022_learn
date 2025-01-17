//
//  _03_25.cpp
//  cpp11_test
//
//  Created by delims on 2022/3/25.
//

//#include <function>
#include <future>
#include <iostream>
#include <thread>
#include <functional>
#include <unistd.h>

using namespace std;

struct obj {
    obj(){
        printf("obj constructor \n");
    }
    obj(const obj &o) {
        printf("obj copy \n");
    }
    void func() {
        printf("obj func \n");

    }
};


void func(std::future<obj>& fut) {
//    obj x = fut.get();
//    printf("value:%f\n",x);
//    cout << "value: " << x << endl;
//    x.func();
    fut.get().func();
    
//    cout << "child" << std::this_thread::get_id() << endl;
}

static int func2() {
    
    
    return 2;
}

static void func1() {
    
    func2();
}



void _03_25() {

    func1();
//    int arr[2][2] = {{1,2},{3,4}};
//    int **ptr = (int**)arr;
//    printf("%d\n",*ptr);
//    printf("%p\n",arr);
//    printf("%p\n",arr[0]);
//    printf("%p\n",arr[1]);
    
//    auto f = [](){
//        printf("hello \n");
//    };
    
//    auto f2 = [](int a){
//    };

//    f();

//    printf("%p\n",func);
//    printf("%p\n",f);
//    printf("%p\n",f2);
    
    obj o;

    std::promise<obj> prom;
    std::future<obj> fut = prom.get_future();
    
    std::thread t(func,std::ref(fut));
    
//    prom.set_value(144);
    
    t.detach();
    
    
    sleep(4);
    
    prom.set_value(o);
    
//    cout << "main:" << std::this_thread::get_id() << endl;

    sleep(3);

}


//    A a;
//    printf("%p \n",&a);
//    printf("%p \n",&testCopy(a));

//    int array[] = {1,10,2,6,76,4,8};
//    size_t size = sizeof(array)/sizeof(int);
//    printf("size = %d \n",size);
//    insert_sort(array, size);
//
//    for(int x : array) {
//        printf("%d \n",x);
//    }

//
//
//    char a[] = "1225";
//    char b[] = "12";
//
//    printf("%d\n",strcmp(a, b));
//    printf("%d\n",'2');


//    list<int> l;

//    std::vector<int> vl;
//    vl.shrink_to_fit();

//    printf("%d %d\n",sizeof(unsigned),sizeof('\0'));


//    int *p = (int*)malloc(4);
//    *p = 12467890;
//    printf("%p,%d\n",p,*p);
//    p = (int*)realloc(p, 400);
//    printf("%p,%d\n",p,*p);



//    while (1) {
//        malloc(1000);
//        calloc(<#size_t __count#>, <#size_t __size#>)
//        realloc(void *__ptr, <#size_t __size#>)
//    }

//    try {
//        void *uy = malloc(1000000000000000000L);
//    } catch (...) {
//        printf("exception\n");
//    }
//    printf("%d \n",u89);

//    A a;
//    A b = a;
//    A c;
//    c = a;
//    A a,b,c;
//
//    auto func = [=,&a,&b,&c](int i) {
//        if (i == 1) {
//            printf("%d \n",a.value);
//        } if (i == 2) {
//            printf("%d \n",b.value);
//        }if (i == 3) {
//            printf("%d \n",c.value);
//        }
//    };
//
//    func(1);


//    int *i = new int[10]();
//
//    int a;


// insert code here...
//    std::cout << "Hello, World!\n";

//    int arr[] = {22,31,1,45,3,4,6,221,56};
//
//    bubble_sort(arr, sizeof(arr)/sizeof(int));
//
//    for (int i = 0; i < sizeof(arr)/sizeof(int); i ++) {
//        printf("%d \n",arr[i]);
//    }
//
//
//    auto func = []() {
//        for (int i = 0; i <= 10; ++i) {
//            cout << i << "  ";
//        }
//    };
//
//    thread t(func);
//    if (t.joinable()) {
//        t.join();
//    }

//    auto res = std::async(func, 5);
//    vector<int> a(100,0);


//    cout << "\n";


//void *memcpy(void *dest,void *src,size_t n) {
//    char *dp = (char*)dest;
//    char *sp = (char*)src;
//    while (n --) *dp ++ = *sp ++;
//    return dest;
//}


int func(int in) { return in + 1; }

void bubble_sort(int *array, int size) {
    int temp;
    for (int i = 0; i < size - 1; i ++ ) {
        for (int j = i + 1 ; j < size; j ++) {
            if (array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void insert_sort(int *array, int size) {
    for (int i = 1; i < size; i ++) {
        int value = array[i];
        int j;
        for (j = i-1; j >= 0; j--) {
            if (array[j] > value) {
                array[j+1] = array[j];
            }
        }
        array[j+1] = value;
    }
}

//class Apple {
//public:
//    Apple() = default;
//    Apple(Apple& app) {
//        printf("copy -\n");
//    }
//    Apple& operator=(Apple &app) {
//        printf("= copy \n");
//        return <#expression#>;
//    }
//};

class A
{
public:
    int value = 1;
    A(){
        printf("constructor\n");
    };//构造函数
    A(const A& a) { //拷贝构造函数
        printf("copy - constructor \n");
    };
    ~A() = default;//析构函数
    A& operator=(const A& a)  //赋值运算符重载
    {
        printf("operator copy \n");
        return *this;
    }
    A* operator &()//取地址运算符重载
    {
        return this;
    }
    const A* operator &() const//const修饰的取地址运算符重载
    {
        return this;
    }
};

class Apple {
public:
//    Apple(){};
//    Apple(const Apple& apple) {
//    }
//    Apple& operator=(const Apple& apple) {
//        return *this;
//    }
//    Apple* operator&() {
//        return this;
//    }
//    const Apple* operator&() const {
//        return this;
//    }
//    ~Apple(){}
};

//static A qingbing;
//
//A testCopy(A a) {
////    printf("%p \n",&a);
//    return qingbing;
//}
