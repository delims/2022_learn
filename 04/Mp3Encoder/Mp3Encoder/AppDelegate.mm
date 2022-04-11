//
//  AppDelegate.m
//  Mp3Encoder
//
//  Created by delims on 2022/4/11.
//

#import "AppDelegate.h"
#import "ViewController.h"


@interface AppDelegate ()

@end

@implementation AppDelegate

static UIWindow *window = nil;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    window = [UIWindow.alloc initWithFrame:UIScreen.mainScreen.bounds];
    window.rootViewController = [UINavigationController.alloc initWithRootViewController:ViewController.alloc.init];
    [window makeKeyAndVisible];
    return YES;
}


@end
