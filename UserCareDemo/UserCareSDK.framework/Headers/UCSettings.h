#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UCButtonStyle;
@class UCFAQStyle;
@class UCLiveChatStyle;
@class UCTicketStyle;

extern NSString * const kUCJSONKeyFAQ;
extern NSString * const kUCJSONKeyLink;

extern NSString * const kUCBackgroundImageRepeat;
extern NSString * const kUCBackgroundImageRepeatX;
extern NSString * const kUCBackgroundImageRepeatY;
extern NSString * const kUCBackgroundImageNoRepeatFit;
extern NSString * const kUCBackgroundImageNoRepeatFill;
extern NSString * const kUCBackgroundImageNoRepeatCenter;
extern NSString * const kUCBackgroundImageNoRepeatCrop;

@interface UCSettings : NSObject

- (id)initWithStatusDictionary:(NSDictionary *)dictionary;

@property (nonatomic, assign) BOOL isLiveChatEnabled;
@property (nonatomic, assign) BOOL isVIPLoungeEnabled;
@property (nonatomic, assign) BOOL isFAQEnabled;
@property (nonatomic, assign) BOOL isLandingPageEnabled;
@property (nonatomic, assign) BOOL isMyTicketsEnabled;

@property (nonatomic, assign) BOOL faqShouldDisplayVipLounge;

@property (nonatomic, strong) NSNumber *sessionContinuationInterval;
@property (nonatomic, strong) NSNumber *customerAppIdForEvents;

@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSString *badgeCount;
@property (nonatomic, strong) NSString *VIPLoungeURL;
@property (nonatomic, strong) NSString *landingPageURL;

//UI Customization

@property (nonatomic, strong) UCButtonStyle *vipLoungeButtonStyle;
@property (nonatomic, strong) UCButtonStyle *landingPageButtonStyle;

@property (nonatomic, strong) UCFAQStyle *FAQStyle;
@property (nonatomic, strong) UCLiveChatStyle *liveChatStyle;
@property (nonatomic, strong) UCTicketStyle *ticketStyle;

@end
