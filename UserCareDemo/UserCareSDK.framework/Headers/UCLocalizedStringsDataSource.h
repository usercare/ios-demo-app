#import <Foundation/Foundation.h>

@interface UCLocalizedStringsDataSource : NSObject

- (id)initWithDictionary:(NSDictionary *)dictionary;

@property (nonatomic, strong) NSString *backToFaq;
@property (nonatomic, strong) NSString *vipLounge;
@property (nonatomic, strong) NSString *negativeSubmit;
@property (nonatomic, strong) NSString *negativeHint;
@property (nonatomic, strong) NSString *negativeTitle;
@property (nonatomic, strong) NSString *negativeText;
@property (nonatomic, strong) NSString *negativeMessageAgent;

@property (nonatomic, strong) NSString *faqSearchTitle;
@property (nonatomic, strong) NSString *faqSearchNoResults;

@property (nonatomic, strong) NSString *faqTopQuestions;
@property (nonatomic, strong) NSString *faqSections;

@property (nonatomic, strong) NSString *faqSearchSectionTitle;
@property (nonatomic, strong) NSString *faqSearchHint;

@property (nonatomic, strong) NSString *faqEscalationMessage;
@property (nonatomic, strong) NSString *faqTitle;

@property (nonatomic, strong) NSString *messagingSocketConnectionError;
@property (nonatomic, strong) NSString *messagingDone;
@property (nonatomic, strong) NSString *messagingSend;
@property (nonatomic, strong) NSString *messagingNewMessage;
@property (nonatomic, strong) NSString *messagingDateFormat;
@property (nonatomic, strong) NSString *greetingMessage;
@property (nonatomic, strong) NSString *messagingHeaderTitle;
@property (nonatomic, strong) NSString *messagingSettingsTitle;

@property (nonatomic, strong) NSString *messagingPromptTitle;
@property (nonatomic, strong) NSString *messagingPromptPlaceholderName;
@property (nonatomic, strong) NSString *messagingPromptPlaceholderSurname;
@property (nonatomic, strong) NSString *messagingPromptPlaceholderEmail;
@property (nonatomic, strong) NSString *messagingPromptInvalid;
@property (nonatomic, strong) NSString *messagingPromptEmpty;

@property (nonatomic, strong) NSString *ticketsTitle;
@property (nonatomic, strong) NSString *ticketsOpenNew;
@property (nonatomic, strong) NSString *ticketsTicketText;
@property (nonatomic, strong) NSString *ticketsOpenText;
@property (nonatomic, strong) NSString *ticketsOpenedText;
@property (nonatomic, strong) NSString *ticketsClosedText;
@property (nonatomic, strong) NSString *ticketsBonusesText;
@property (nonatomic, strong) NSString *ticketsMessagesWaitingText;

@property (nonatomic, strong) NSString *noNetworkAlertText;

@end
