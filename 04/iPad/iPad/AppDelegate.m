//
//  AppDelegate.m
//  iPad
//
//  Created by delims on 2022/4/4.
//

#import "AppDelegate.h"
#import "ViewController.h"

@interface AppDelegate ()

@property (nonatomic,readwrite) UIWindow *window;
@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.window = [UIWindow.alloc initWithFrame:UIScreen.mainScreen.bounds];
    
    self.window.rootViewController = [UINavigationController.alloc initWithRootViewController:ViewController.new];

    [self.window makeKeyAndVisible];
    
    return YES;
}


#pragma mark - UISceneSession lifecycle


@end
