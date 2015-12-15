#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"


@class UCCustomButton;
@class UCLiveChatClient;
@class UCBonusEntity;

typedef void(^UCInitializeSuccessfulBlock)(void);
typedef void(^UCInitializeFailedBlock)(NSError *error);


typedef void(^UCBonusReceivedBlock)(NSString *bonusText, NSString *bonusIconURL);


@protocol UCDelegate <NSObject>

- (void)onBonusMessageReceived:(UCBonusEntity *)bonusEntity;
- (void)usercareSdkFailedWithError:(NSError *)error;
- (void)usercareSdkFailedWithError:(NSError *)error withStatusCode:(NSInteger)statusCode;

@end


@interface UCManagerSettings : NSObject

/** *  Push notifications token received on device registration.
 */
@property (nonatomic, strong) NSData *pushNotificationToken;

/** *  Application identifier received from UserCare.
 */
@property (nonatomic, strong) NSString *appId;

/** *  Customer identifier received from UserCare.
 */
@property (nonatomic, strong) NSString *customerId;

/**
  *  Key for Events.
 
 */
@property (nonatomic, strong) NSString *eventsAPIKey;

@property (nonatomic, strong) NSString *customerFirstName;
@property (nonatomic, strong) NSString *customerLastName;
@property (nonatomic, strong) NSString *customerEmail;

@end


@interface UCManager : NSObject

@property (nonatomic, weak) id <UCDelegate> delegate;
@property (nonatomic, strong) UCBonusReceivedBlock bonusReceivedBlock;
@property (nonatomic, readonly) BOOL isLiveChatEnabled;
@property (nonatomic, readonly) BOOL isVIPLoungeEnabled;
@property (nonatomic, readonly) BOOL isFAQEnabled;
@property (nonatomic, readonly) BOOL isLandingPageEnabled;
@property (nonatomic, readonly) BOOL isMyTicketsEnabled;

- (void)presentLiveChatWithParent:(UIViewController *)parent;
- (void)presentFAQWithParent:(UIViewController *)parent;
- (void)presentVipLoungeWithParent:(UIViewController *)parent;
- (void)presentLandingPageWithParent:(UIViewController *)parent;
- (void)presentMyTicketsWithParent:(UIViewController *)parent;
- (void)openURL:(NSString *)url;

/** * Starts service. Immediately triggers settings and update requests to server
  * @return pointer to instance of UC
  * @param settings - your Manager Settings. Create them and customize.
  * @param completionBlock - completion block called after successful init.
  * @param failureBlock - failure block called if something goes wrong during initialization.
 
 */

+ (UCManager *)startServiceWithSettings:(UCManagerSettings *)settings completion:(UCInitializeSuccessfulBlock)completionBlock failure:(UCInitializeFailedBlock)failureBlock;

/**
* Creates VIP lounge button. Can be called anytime, returns invisible button if VIP lounge is unavailable. Visibility will be updated automatically.
* @return pointer to VIP lounge button

*/

- (UIButton *)createVIPLoungeButton;

/**
*  Creates live chat button. Can be called anytime, returns invisible button if live chat is unavailable. Visibility will be updated automatically.
* @return pointer to live chat button

*/

- (UIButton *)createLiveChatButton;

/**
  *  Creates faq button. Can be called anytime, returns invisible button if live faq is unavailable. Visibility will be updated automatically.
  * @return pointer to faq button
 
 */

- (UIButton *)createFAQButton;

/**
  *  Creates landingPage button. Can be called anytime, returns invisible button if live faq is unavailable. Visibility will be updated automatically.
  * @return pointer to faq button

 */

- (UIButton *)createLandingPageButton;

/**
  *  Creates my tickets button. Can be called anytime, returns invisible button if live faq is unavailable. Visibility will be updated automatically.
  * @return pointer to faq button
 */

- (UIButton *)createMyTicketsButton;

/**
*  Notifies Concierge that chat push notification was received
* @param userInfo - data dictionary from application: didReceiveRemoteNotification:

*/

- (void)receivedPushNotification:(NSDictionary *)userInfo;

/**

*  Receives entry point for chat interface.

* @return pointer to live chat interface

*/

- (UCLiveChatClient *)getChatClient;

#pragma clang diagnostic pop

@end
