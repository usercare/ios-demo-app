#import "ViewController.h"

#import <UserCareSDK/UserCareSDK.h>
#import "AppDelegate.h"

typedef NS_ENUM(NSUInteger, UCAlertType){
    kAlertCustomEvent = 0,
    kAlertPurchaseEvent,
    kAlertPurchaseFailedEvent,
    kAlertCrashEvent
};

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
    
    [UCManager setDeviceId:[NSString stringWithFormat:@"ifv:%@", [UIDevice currentDevice].identifierForVendor.UUIDString]];
    
    UCManagerSettings *settings = [[UCManagerSettings alloc] init];
    
    settings.appId = @"input_app_id";
    settings.eventsAPIKey = @"input_API_key";
    settings.pushNotificationToken = pushToken;
    
    if (![self validateSettings: settings]) {
        return;
    }
    
    self.usercareInstance = [UCManager startServiceWithSettings:settings completion:^{
        dispatch_async(dispatch_get_main_queue(), ^{
            
            if (self.openFAQButton) [self.openFAQButton removeFromSuperview];
            
            self.openFAQButton = [self.usercareInstance createFAQButton];
            
            [self.view addSubview:self.openFAQButton];
          
            self.openFAQButton.center = self.view.center;
            self.launchSDKButton.enabled = NO;
            self.sendCustomEventButton.enabled = YES;
            self.sendPurchaseEventButton.enabled = YES;
            self.sendPurchaseFailedEventButton.enabled = YES;
            self.sendCrashEventButton.enabled = YES;
            
            self.openLandingPageButton.enabled = self.usercareInstance.isLandingPageEnabled;
            self.openChatButton.enabled = self.usercareInstance.isLiveChatEnabled;
        });
        
    } failure:^(NSError *error) {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Initialization failed" message:[NSString stringWithFormat:@"Error: %@", error.localizedDescription] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        alert.delegate = self;
        [alert show];
    }];
}

- (BOOL) validateSettings: (UCManagerSettings *)settings
{
    if ([@"input_app_id" isEqualToString:settings.appId] || [@"input_API_key" isEqualToString:settings.eventsAPIKey]) {
        NSLog(@"Warning: please define Application ID and Events API key!");
        return NO;
    }
    
    return YES;
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

- (IBAction)sendCustomEvent:(id)sender
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Send custom event" message:@"Input event name without spaces." delegate:self cancelButtonTitle:@"Send" otherButtonTitles:nil];
    alert.alertViewStyle = UIAlertViewStylePlainTextInput;
    alert.tag = kAlertCustomEvent;
    [alert show];
}

- (IBAction)sendPurchaseEvent:(id)sender
{
    [self showAlert:@"Purchase event" message:@"Would you like to purchase 25 coins?" sendTitle:@"Purchase" withType:kAlertPurchaseEvent];
}

- (IBAction)sendPurchaseFailedEvent:(id)sender
{
    [self showAlert:@"Purchase failed event" message:@"Would you like to purchase 25 coins?" sendTitle:@"Purchase" withType:kAlertPurchaseFailedEvent];
}

- (IBAction)sendCrashEvent:(id)sender
{
        [self showAlert:@"Crash event" message:@"Would you like to crash the app?" sendTitle:@"Crash" withType:kAlertCrashEvent];
}

- (void)purchaseItem:(BOOL)isSuccessful
{
    NSString *eventType = isSuccessful ? kUCEventPurchaseSuccess : kUCEventPurchaseFailed;
    UCEvent *event = [[UCEvent alloc] initWithEventType:eventType];
    event.title = @"25 Coins";
    event.price = @(4.99);
    event.priceCurrency = @"USD";
    event.productId = @"25coins";
    event.transactionId = [[NSUUID UUID] UUIDString];
    event.transactionTime = [UCUtils currentFormattedTimeForEvents];
    
    [[UCEventLogger sharedInstance] sendEventWithEvent:event];
}

- (void)showAlert:(NSString *)title message:(NSString *)message sendTitle:(NSString *)sendTitle withType:(UCAlertType)alertType
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title message:message delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles: sendTitle, nil];
    alert.tag = alertType;
    [alert show];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    switch (alertView.tag) {
        case kAlertCustomEvent:
            [[UCEventLogger sharedInstance] sendEvent:[[alertView textFieldAtIndex:0] text] withCustomParameters:nil];
            break;
        case kAlertPurchaseEvent:
            [self purchaseItem:YES];
            break;
        case kAlertPurchaseFailedEvent:
            [self purchaseItem:NO];
            break;
        case kAlertCrashEvent:
            @throw [NSException exceptionWithName:@"UC Demo App Crash"
                                           reason:@"Test crash event"
                                         userInfo:nil];
            break;
        default:
            break;
    }
    
}

#pragma mark - UCDelegate methods

- (void)onActionMessageReceived:(UCActionEntity *)actionEntity
{

}
- (void)usercareSdkFailedWithError:(NSError *)error
{

}
- (void)usercareSdkFailedWithError:(NSError *)error withStatusCode:(NSInteger)statusCode
{

}

- (void)onSystemMessageReceived:(NSString *)message
{
    
}

- (void)onSupporterMessageReceived:(NSString *)message
{
    
}

@end
