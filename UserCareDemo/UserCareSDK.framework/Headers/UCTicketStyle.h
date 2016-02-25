#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class UCTextStyle;
@class UCTicketItemStyle;
@class UCImageStyle;
@class UCTicketImageTextStyle;
@class UCHeaderStyle;
@class UCButtonStyle;

@interface UCTicketStyle : NSObject

@property (nonatomic, strong) UCTextStyle *textStyle;
@property (nonatomic, copy) NSString *openNewButtonImageUrl;

@property (nonatomic, strong) UCImageStyle *sectionStyle;
@property (nonatomic, strong) UCImageStyle *myTicketsBackgroundStyle;
@property (nonatomic, strong) UCButtonStyle *addTicketButtonStyle;
@property (nonatomic, strong) UCButtonStyle *myTicketsButtonStyle;
@property (nonatomic, strong) UCButtonStyle *myTicketsLiveChatButtonStyle;
@property (nonatomic, strong) UCTicketItemStyle *openTicketStyle;
@property (nonatomic, strong) UCTicketItemStyle *closedTicketStyle;
@property (nonatomic, strong) UCTicketImageTextStyle *bonusesStyle;
@property (nonatomic, strong) UCTicketImageTextStyle *messagesStyle;
@property (nonatomic, strong) UCHeaderStyle *headerStyle;
@property (nonatomic, strong) UCHeaderStyle *detailsHeaderStyle;

+ (UCTicketStyle *)styleWithDictionary:(NSDictionary *)dictionary;
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
