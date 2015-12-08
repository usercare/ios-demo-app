//
//  ViewController.h
//  UserCareDemo
//
//  Created by andrey.bolshakov on 10/1/15.
//  Copyright © 2015 UserCare. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

- (void)appStartedWithPushMessage:(NSDictionary *)message;
- (void)receivedPushMessage:(NSDictionary *)message;

- (IBAction)initSDK:(id)sender;
- (IBAction)openChat:(id)sender;
- (IBAction)openLandingPage:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *launchSDKButton;

@property (weak, nonatomic) IBOutlet UIButton *openChatButton;
@property (weak, nonatomic) IBOutlet UIButton *openLandingPageButton;

@property (weak, nonatomic) UIButton *openFAQButton;

@end

