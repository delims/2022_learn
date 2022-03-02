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
using namespace std;
struct Fruit {
    
};

struct Fruit2 {
    
};

//template <typename A>
struct Apple {
    
private:
//    int a;
//    int b;
public:
    void func() {
        printf("%s \n",__func__);
    }
    
    void func() const{
        printf("%s const \n",__func__);
    }
    
//    static void func() {
//        printf("static func size = %d \n",sizeof(Apple));
//    }
    void func2 () {
        printf("func size = %d \n",sizeof(Apple));
    }
    void operator ++() {
        printf("%s\n",__func__);
        func();
    }
    Apple& operator ++(int arg) {
        printf("%s arg = %d \n",__func__,arg);
        return *this;
    }

    Apple& operator & (Apple b) {
        printf("==%s \n",__func__);
        return *this;
    }
    Apple* operator &() {
        printf("===%s \n",__func__);
        return this;
    }
    Apple& operator *(Apple &b) {
        printf("====%s \n",__func__);
        return *this;
    }
//    operator Fruit& () {
//        printf("okkkkkk \n");
//        Fruit f;
//        return f;
//    }
//
//    operator Fruit2& () {
//        printf("okkj \n");
//        Fruit2 f;
//        return f;
//    }
private:
    
//    int a;
//    int b;
//
//    typedef int inttt;
//    inttt abc;
public:
    struct water {
        int count;
        int size;
        void func(){
            printf("%p \n",this);
        }
    };
    
};


//template<typename T, typename... Args>
//void foo(const T& t, const Args&... rest) {
//    std::cout << sizeof(T) << endl;
//    cout << sizeof...(Args) << endl;//打印可变参数数量
//    cout << sizeof...(rest) << endl;//打印可变参数数量
//}

template <typename T,typename... args>
void somefunc(args&... a) {
    std::cout << sizeof...(a) << std::endl;
}

struct array_t {
    long count;
    int *p[0];
    
    void func() {
        printf("%d \n",sizeof(p[0]));
    }
};

template <typename... T>
   void f(T... args)
   {
       for (auto x : {args...})
       {
           std::cout << x << std::endl;
       }
   }

int main(int argc, const char * argv[]) {
    
//    f(1.1,2.3);
    const int &i = 100;
    
    decltype(i) b =100; // decltype(i) 代表 i的类型
    
    auto func = [](int i) -> int {
        return 200 * i;
    };
    auto func2 = []{
        return 100;
    };
//    cout << func2() << endl;
    
    int x = 100;
    auto fix = [=]() mutable {
        x ++;
    };
    
    fix();
    fix();
    
    cout << std::thread::hardware_concurrency() << endl;
//    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << std::thread::hardware_concurrency() << endl;
    
    std::mutex mutex;
    mutex.lock();
    
    mutex.unlock();
    
    cout << __cpluplus << endl;

    std::vector<std::vector<int>> y;
//    array_t arr;
//    printf(" == %d   \n ",sizeof(arr));
//    arr.func();
//    Apple apple;
//    apple.func();
    
//    (const_cast<const Apple &>(apple)).func();
    
//    app.func();
    
//    somefunc<int>(1,2,3,4,5);
//    somefunc(1,2,3,4);
    
    
//    Apple a;
//    a++; // 打印 operator++ arg = 0
//    ++a; // 打印 operator++
//    int fd;
    
//    Apple<long> b;
//    Apple<int>::func();
//    b.func2();
//    (Fruit2)b;
    
//    printf("%d \n",sizeof(b));
    
    
//    a &b ;
//    a * b/;
//    a*a;
//    printf("%d \n",sizeof(a));
    
//    fcntl(fd, F_SETFL,O_NONBLOCK);
//
//    Apple::water water;
//    water.func();
    
    return 0;
}

