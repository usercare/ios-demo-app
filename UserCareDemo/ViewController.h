#import <UIKit/UIKit.h>
#import <UserCareSDK/UserCareSDK.h>

@interface ViewController : UIViewController <UCDelegate>

- (void)appStartedWithPushMessage:(NSDictionary *)message;
- (void)receivedPushMessage:(NSDictionary *)message;

- (IBAction)initSDK:(id)sender;
- (IBAction)openChat:(id)sender;
- (IBAction)openLandingPage:(id)sender;
- (IBAction)sendCustomEvent:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *launchSDKButton;

@property (weak, nonatomic) IBOutlet UIButton *openChatButton;
@property (weak, nonatomic) IBOutlet UIButton *openLandingPageButton;
@property (weak, nonatomic) IBOutlet UIButton *purchasesButton;
@property (weak, nonatomic) IBOutlet UIButton *sendCustomEventButton;

@property (weak, nonatomic) UIButton *openFAQButton;

@end

