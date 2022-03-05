//
//  main.m
//  objc_test
//
//  Created by delims on 2022/2/24.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

union isa_t {
    isa_t(){}
    isa_t(uintptr_t value):bits(value){}
    uintptr_t bits;
    Class cls;
    struct {
        uintptr_t nonpointer        : 1;                                         \
        uintptr_t has_assoc         : 1;                                         \
        uintptr_t has_cxx_dtor      : 1;                                         \
        uintptr_t shiftcls          : 44; /*MACH_VM_MAX_ADDRESS 0x7fffffe00000*/ \
        uintptr_t magic             : 6;                                         \
        uintptr_t weakly_referenced : 1;                                         \
        uintptr_t deallocating      : 1;                                         \
        uintptr_t has_sidetable_rc  : 1;                                         \
        uintptr_t extra_rc          : 8;
    };
};

struct obj_object {
    isa_t isa;
};

struct obj_class : public obj_object {
    Class superclass;
    long cache1;
    long cache2;
    uintptr_t bits;
};

struct class_ro {
    uint32_t flags;
    uint32_t instanceStart;
    uint32_t instanceSize;
#ifdef __LP64__
    uint32_t reserved;
#endif

    const uint8_t * ivarLayout;
    
    const char * name;
//    method_list_t * baseMethodList;
//    protocol_list_t * baseProtocols;
//    const ivar_list_t * ivars;
    uintptr_t foot[3];

    const uint8_t * weakIvarLayout;
//    property_list_t *baseProperties;
    uintptr_t foot1[1];


//    method_list_t *baseMethods() const {
//        return baseMethodList;
//    }
};


struct class_rw {
    // Be warned that Symbolication knows the layout of this structure.
    uint32_t flags;
    uint32_t version;

    const class_ro *ro;

//    method_array_t methods;
//    property_array_t properties;
//    protocol_array_t protocols;

    int foot[3];
    
    Class firstSubclass;
    Class nextSiblingClass;

    char *demangledName;

#if SUPPORT_INDEXED_ISA
    uint32_t index;
#endif

//    void setFlags(uint32_t set)
//    {
//        OSAtomicOr32Barrier(set, &flags);
//    }
//
//    void clearFlags(uint32_t clear)
//    {
//        OSAtomicXor32Barrier(clear, &flags);
//    }
//
//    // set and clear must not overlap
//    void changeFlags(uint32_t set, uint32_t clear)
//    {
//        assert((set & clear) == 0);
//
//        uint32_t oldf, newf;
//        do {
//            oldf = flags;
//            newf = (oldf | set) & ~clear;
//        } while (!OSAtomicCompareAndSwap32Barrier(oldf, newf, (volatile int32_t *)&flags));
//    }
};

#define FAST_DATA_MASK          0x00007ffffffffff8UL


@interface Apple : NSObject
- (void)test;
@end
@implementation Apple

- (void)func1{
    printf("%s\n",__func__);
}

- (void)test{
    SEL s = @selector(func1);
//    SEL s = (SEL)"func1";
    [self performSelector:s];
}

@end

class_rw* printClassInfo(obj_class *cls) {
    printf("cls info isa   %p \n",cls->isa);
    printf("cls info super %p \n",cls->superclass);
    printf("cls info bits  %p \n",cls->bits);
    printf("cls rw   bits  %p \n",cls->bits);
    return (class_rw*)(cls->bits & FAST_DATA_MASK);
}

obj_class* findIsa(uintptr_t o){
//    static uintptr_t last = 0;
//    if (last == o) return ;
//    last = o;
    
    obj_object *p = (obj_object*)o;
    if (p->isa.nonpointer) {
        printf("obj 0x%012lx [instance] isa->\n",p);
//        findIsa(p->isa.shiftcls << 3);
        return (obj_class*)(p->isa.shiftcls << 3);
    } else {
        printf("cls 0x%012lx [%s] isa->\n",p,NSStringFromClass((__bridge_transfer Class)p).UTF8String);
//        findIsa(p->isa.bits);
        return (obj_class*)(p->isa.bits);
    }
}

void printStrings(const char *p) {
    printf("%s \n",p);
    static int count = 0;
    count ++ ;
    if (count > 15) return;;
    printStrings(p + strlen(p) + 1);
}


int main(int argc, const char * argv[]) {
//    @autoreleasepool {
//        // insert code here...
//        NSLog(@"Hello, World!");
//    }
//    int j = 0;
//    printf("    %p \n",findIsa);
//    printf("    %p \n",&j);

    Apple *a = [[Apple alloc]init];
    Apple *a1 = a;
    
    obj_object *b;
    memcpy(&b, &a, sizeof(a));
    
    obj_class *cls = findIsa((uintptr_t)a);
    class_rw *rw =  printClassInfo(cls);
    
    const class_ro *ro = rw->ro;
    
    printf("%p %s \n",ro->name,ro->name);
    printf("%d \n",(ro->name + strlen(ro->name))[0]);
    printf("%s \n",ro->name + strlen(ro->name) + 1);

//    printStrings(ro->name);
    printf("%s \n",ro->name);
    
    char *p = "abcdefj";
    
//    printf("%c \n",(p+2)[-89]);
    SEL sel = @selector(format:);
    Apple *app = [[Apple alloc] init];
    [app test];

    
//    for (int i = 0; i < 1000; i ++) {
//        dispatch_async(dispatch_get_global_queue(0, 0), ^{
//            sleep(100);
//        });
//    }
//
//    sleep(1000);
//    printf("%x \n" ,b->isa.extra_rc);
//    printf("%x \n" ,b->isa.nonpointer);
//    printf("%lx \n",b->isa.shiftcls << 3);
//    printf("%lx \n", Apple.class);
//
//    obj_class *c =(obj_class*)(b->isa.shiftcls << 3);
//
//    NSLog(@"%@",NSStringFromClass((__bridge Class)c));
//
//    printf("= %lx \n" ,c->isa.nonpointer);
//    printf("= %lx \n" ,c->isa.extra_rc);
//    printf("= %lx \n" ,c->isa.bits);
//
//    printf("= %lx \n" ,c->superclass);
//    printf("= %lx \n", NSObject.class);
//
//    obj_class *nsobject =(__bridge obj_class*)(NSObject.class);
//
//
//    printf("|= %lx \n", nsobject->isa.bits);

    
    printf("stack size = %d KB \n",NSThread.currentThread.stackSize >> 10);
    NSLog(@"%@",NSThread.currentThread.name);
    printf("\n");
    return 0;
}
