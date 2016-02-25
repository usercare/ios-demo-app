#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

@class UCCustomButton;
@class UCLiveChatClient;
@class UCActionEntity;
@class UCSettings;

typedef void(^UCInitializeSuccessfulBlock)(void);
typedef void(^UCInitializeFailedBlock)(NSError *error);

@protocol UCDelegate <NSObject>

- (void)onActionMessageReceived:(UCActionEntity *)actionEntity;
- (void)onSystemMessageReceived:(NSString *)message;
- (void)onSupporterMessageReceived:(NSString *)message;
- (void)usercareSdkFailedWithError:(NSError *)error;
- (void)usercareSdkFailedWithError:(NSError *)error withStatusCode:(NSInteger)statusCode;

@end

/** Model class containing initialization settings for UserCare SDK. Initialize instance of it, set required parameters and pass to startServiceWithSettings: completion:failure:
 */
@interface UCManagerSettings : NSObject

/** Push notifications token received on device registration.
 */
@property (nonatomic, strong) NSData *pushNotificationToken;

/** Application identifier received from UserCare.
 */
@property (nonatomic, strong) NSString *appId;

/** Customer identifier received from UserCare.
 */
@property (nonatomic, strong) NSString *customerId;

/**
  Key for Events.
 */
@property (nonatomic, strong) NSString *eventsAPIKey;

/**
 Optional property. Will be seen in agent panel. Unless specified here SDK will prompt user to enter it upon opening live chat.
 */
@property (nonatomic, strong) NSString *customerFirstName;

/**
 Optional property. Will be seen in agent panel. Unless specified here SDK will prompt user to enter it upon opening live chat.
 */
@property (nonatomic, strong) NSString *customerLastName;

/**
 Optional property. Will be seen in agent panel. Unless specified here SDK will prompt user to enter it upon opening live chat.
 */
@property (nonatomic, strong) NSString *customerEmail;

@end

/** 
 Main interface of UserCareSDK. Initialize it with startServiceWithSettings: completion:failure:
 */
@interface UCManager : NSObject

/**
  @brief Delegate for SDK callbacks.
 **/
@property (nonatomic, weak) id <UCDelegate> delegate;

/** This value may be false if SDK is not yet initialized, if live chat is disabled on agent panel or if user is ineligible for it.
 Method presentLiveChatWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the live chat feature is available currently for this user.
 **/
@property (nonatomic, readonly) BOOL isLiveChatEnabled;

/** This value may be false if SDK is not yet initialized or if user is ineligible for vip lounge.
 Method presentVipLoungeWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the vip lounge feature is available currently for this user.
 **/
@property (nonatomic, readonly) BOOL isVIPLoungeEnabled;

/** This value may be false if SDK is not yet initialized or if FAQ section is not filled on server side.
 Method presentFAQWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the FAQ feature is available currently for this user.
 **/
@property (nonatomic, readonly) BOOL isFAQEnabled;

/** This value may be false if SDK is not yet initialized or if landing page is disabled on agent panel.
 Method presentLandingPageWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the landing page is available currently for this user.
 **/
@property (nonatomic, readonly) BOOL isLandingPageEnabled;

/** This value may be false if SDK is not yet initialized or if user has no tickets yet.
 Method presentMyTicketsWithParent: will have no effect in such case.
  @brief A Boolean indicating whether the my tickets feature is available currently for this user.
 **/
@property (nonatomic, readonly) BOOL isMyTicketsEnabled;

@property (nonatomic, strong) UCSettings *settings;

/**
    @brief Shows  SDK contact us screen if possible. Property isLiveChatEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentLiveChatWithParent:(UIViewController *)parent;

/**
    Shows  SDK FAQ if possible. Property isFAQEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentFAQWithParent:(UIViewController *)parent;

/**
    Shows  SDK's contact us screen if possible. Property isVipLoungeEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentVipLoungeWithParent:(UIViewController *)parent;

/**
    Shows  SDK's landing page if possible. Property isLandingPageEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentLandingPageWithParent:(UIViewController *)parent;

/**
    Shows  SDK's landing page if possible. Property isMyTicketsEnabled indicates whether this function is available.
    @param parent - Your ViewController that will be used as parent to present SDK navigation stack.
 */
- (void)presentMyTicketsWithParent:(UIViewController *)parent;


- (void)openURL:(NSString *)url;

/** 
    @brief Starts service. Immediately triggers settings and update requests to server
    @param settings - your Manager Settings. Create them and customize.
    @param completionBlock - completion block called after successful init.
    @param failureBlock - failure block called if something goes wrong during initialization.
    @return pointer to instance of UC

 */
+ (UCManager *)startServiceWithSettings:(UCManagerSettings *)settings completion:(UCInitializeSuccessfulBlock)completionBlock failure:(UCInitializeFailedBlock)failureBlock;

/**
* Creates VIP lounge button. Can be called anytime, returns invisible button if VIP lounge is unavailable. Visibility will be updated automatically.
    @return pointer to VIP lounge button

*/
- (UIButton *)createVIPLoungeButton;

/**
Creates live chat button. Can be called anytime, returns invisible button if live chat is unavailable. Visibility will be updated automatically.
    @return pointer to live chat button

*/
- (UIButton *)createLiveChatButton;

/**
  Creates faq button. Can be called anytime, returns invisible button if live faq is unavailable. Visibility will be updated automatically.
    @return pointer to faq button
 
 */
- (UIButton *)createFAQButton;

/**
  Creates landingPage button. Can be called anytime, returns invisible button if live faq is unavailable. Visibility will be updated automatically.
    @return pointer to faq button

 */
- (UIButton *)createLandingPageButton;

/**
  Creates my tickets button. Can be called anytime, returns invisible button if live faq is unavailable. Visibility will be updated automatically.
    @return pointer to faq button
 */

- (UIButton *)createMyTicketsButton;

/**
Notifies SDK that chat push notification was received
    @param userInfo - data dictionary from application: didReceiveRemoteNotification:

*/
- (void)receivedPushNotification:(NSDictionary *)userInfo;

/**

Receives entry point for chat interface.

    @return pointer to live chat interface

*/
- (UCLiveChatClient *)getChatClient;

#pragma clang diagnostic pop

@end
