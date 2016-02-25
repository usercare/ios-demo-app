#import "ViewController.h"

#import <UserCareSDK/UserCareSDK.h>
#import "AppDelegate.h"
#import "PurchasesViewController.h"

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
            self.purchasesButton.enabled = YES;
            
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

- (IBAction)sendCustomEvent:(id)sender {
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Send custom event" message:@"Input event name without spaces." delegate:self cancelButtonTitle:@"Send" otherButtonTitles:nil];
    alert.alertViewStyle = UIAlertViewStylePlainTextInput;
    [alert show];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [[UCEventLogger sharedInstance] sendEvent:[[alertView textFieldAtIndex:0] text] withCustomParameters:nil];
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
