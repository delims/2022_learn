//
//  AppDelegate.m
//  AVCapture
//
//  Created by delims on 2022/4/11.
//

#import "AppDelegate.h"
#include "ViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

static UIWindow *window = nil;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    if (window == nil) {
        window = [UIWindow.alloc initWithFrame:UIScreen.mainScreen.bounds];
        window.rootViewController = [UINavigationController.alloc initWithRootViewController:ViewController.alloc.init];
        [window makeKeyAndVisible];
    }
    
    return YES;
}


#pragma mark - UISceneSession lifecycle


@end
