//
//  ViewController.m
//  dispatch
//
//  Created by delims on 2022/3/31.
//

#import "ViewController.h"

#include <semaphore.h>
#include <pthread.h>
#include <objc/runtime.h>
#include <objc/message.h>



@interface ViewController ()
@property (nonatomic,assign) NSInteger age;
@end

@implementation ViewController

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    dispatch_semaphore_t sem = dispatch_semaphore_create(0);
//    dispatch_semaphore_signal(sem);
//
//
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
//        NSLog(@"1");
//        dispatch_semaphore_signal(sem);
//    });
//
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//
//        dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
//        NSLog(@"2");
//        dispatch_semaphore_signal(sem);
//
//    });
    
    __block sem_t sem = 10;
    
//    NSLog(@"%d",sem);
//    sem_wait(&sem);
//    NSLog(@"%d",sem);

//    unsigned int count;
//
//    Method *methodList = class_copyMethodList(UIResponder.class, &count);
//
//    NSLog(@"%d",count);
//    int i = 0;
//    while (count) {
//        Method method = methodList[i++];
//        printf("%s  %s\n",method_getTypeEncoding(method),NSStringFromSelector(method_getName(method)).cString);
//
//
//        count--;
//    }
    
    
    
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        sem_wait(&sem);
//        sleep(1);
//        NSLog(@"1");
//        sem_post(&sem);
//    });
//
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        sem_wait(&sem);
////        sleep(1);
//        NSLog(@"2");
//        sem_post(&sem);
//    });
//
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        sem_wait(&sem);
////        sleep(1);
//        NSLog(@"3");
//        sem_post(&sem);
//    });
    
    [self addObserver:NSObject.new forKeyPath:@"age" options:NSKeyValueObservingOptionNew context:NULL];
    
    // Do any additional setup after loading the view.
}

+ (BOOL)automaticallyNotifiesObserversForKey:(NSString *)key
{
    
 
    SEL m = @selector(cStringUsingEncoding:);
    
    
    printf("%s\n",   ((const char*(*)(id,SEL,int))objc_msgSend)(key,m,4) );
    
    
    return YES;
}

@end
