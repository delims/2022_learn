//
//  AppDelegate.m
//  iOS_module
//
//  Created by delims on 2022/4/16.
//

#import "AppDelegate.h"
#import "ViewController.h"

@interface AppDelegate ()
@property (nonatomic,strong,readwrite) UIWindow *window;
@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window = [UIWindow.alloc initWithFrame: UIScreen.mainScreen.bounds];
    self.window.rootViewController = [UINavigationController.alloc initWithRootViewController:ViewController.new];
    [self.window makeKeyAndVisible];
    
    // Override point for customization after application launch.
    return YES;
}


#pragma mark - UISceneSession lifecycle


@end
