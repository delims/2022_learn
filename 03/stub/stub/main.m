//
//  main.m
//  stub
//
//  Created by delims on 2022/3/31.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    NSString * appDelegateClassName;
    
//    NSString *str1 = @"123456";
//    NSString *str2 = @"123456";

//    NSLog(@"\n%p\n%p\n",str1,str2);
    
    NSLog(@"1");
    NSLog(@"2");

    
    
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}
