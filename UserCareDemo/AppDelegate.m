#import "AppDelegate.h"
#import "ViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[UIApplication sharedApplication] setApplicationIconBadgeNumber:0];
    if (launchOptions[UIApplicationLaunchOptionsRemoteNotificationKey]) {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t) (2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            ViewController *root = (ViewController *) ((UINavigationController*)[UIApplication sharedApplication].keyWindow.rootViewController);
            [root appStartedWithPushMessage:launchOptions];
        });
    }
    
    [self registerAppForNotifications];
    
    return YES;
}

- (void)registerAppForNotifications
{
    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)])
    {
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
        [[UIApplication sharedApplication] registerForRemoteNotifications];
    }
    else
    {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated"
        [[UIApplication sharedApplication] registerForRemoteNotificationTypes:UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeSound];
#pragma clang diagnostic pop
        
    }
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    [[UCManager push] didReceiveRemoteNotification:userInfo];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    [[UCManager push] registeredForPushNotifications:deviceToken];
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{
    
}

@end
