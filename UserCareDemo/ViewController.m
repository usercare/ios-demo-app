//
//  ViewController.m
//  UserCareDemo
//
//  Created by andrey.bolshakov on 10/1/15.
//  Copyright © 2015 UserCare. All rights reserved.
//

#import "ViewController.h"

#import <UserCareSDK/UserCareSDK.h>
#import "AppDelegate.h"

@interface UCManager ();

+ (void)setServerPort:(NSInteger)newPort;

+ (NSInteger)getServerPort;

+ (void)setServerURL:(NSString *)serverURL;

+ (NSString *)getServerURL;

@end

@interface ViewController ()

@property (nonatomic, strong) UCManager *usercareInstance;


@end

@implementation ViewController

- (void)appStartedWithPushMessage:(NSDictionary *)message
{
    [self initializeSDK];
    
    [self.usercareInstance receivedPushNotification:message];
}

- (void)receivedPushMessage:(NSDictionary *)message
{
    [self.usercareInstance receivedPushNotification:message];
}

- (void)initializeSDK
{
    NSData *pushToken = ((AppDelegate *) [UIApplication sharedApplication].delegate).pushToken;
    UCManagerSettings *settings = [[UCManagerSettings alloc] init];
    
    settings.appId = @"input_app_id";
    settings.eventsAPIKey = @"input_API_key";
    settings.pushNotificationToken = pushToken;
    
    self.usercareInstance = [UCManager startServiceWithSettings:settings completion:^{
        dispatch_async(dispatch_get_main_queue(), ^{
            
            if (self.openFAQButton) [self.openFAQButton removeFromSuperview];
            
            self.openFAQButton = [self.usercareInstance createFAQButton];
            
            [self.view addSubview:self.openFAQButton];
          
            self.openFAQButton.center = self.view.center;
            self.launchSDKButton.enabled = NO;
            
            
            self.openLandingPageButton.enabled = self.usercareInstance.isLandingPageEnabled;
            self.openChatButton.enabled = self.usercareInstance.isLiveChatEnabled;
 
        });
        
    } failure:^(NSError *error) {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Initialization failed" message:[NSString stringWithFormat:@"Error: %@", error.localizedDescription] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        alert.delegate = self;
        [alert show];
    }];
    
}

- (IBAction)initSDK:(id)sender
{
    [self initializeSDK];
}
- (IBAction)openChat:(id)sender
{
    [self.usercareInstance presentLiveChatWithParent:self];
}
- (IBAction)openLandingPage:(id)sender
{
    [self.usercareInstance presentLandingPageWithParent:self];
}


@end
