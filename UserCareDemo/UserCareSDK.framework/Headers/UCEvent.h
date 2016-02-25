#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

static NSString *const kUCEventTypeKey = @"type";
static NSString *const kUCLatitudeKey = @"lat";
static NSString *const kUCLongitudeKey = @"lon";

static NSString *const kUCUsercareKey = @"usercare";
static NSString *const kUCLocationKey = @"location";
static NSString *const kUCCoordinatesKey = @"coordinates";

static NSString *const kUCCustomerIdKey = @"customerId";
static NSString *const kUCProductIdKey = @"productId";
static NSString *const kUCTitleKey = @"title";
static NSString *const kUCTransactionTimeKey = @"transactionTime";
static NSString *const kUCPriceKey = @"price";
static NSString *const kUCEventCustomerAppIdKey = @"customerAppId";
static NSString *const kUCPriceCurrencyKey = @"priceCurrency";
static NSString *const kUCTransactionIdKey = @"transactionId";
static NSString *const kUCTimestampKey = @"timestamp";
static NSString *const kUCSessionStartTimestampKey = @"start_timestamp";
static NSString *const kUCFinishedKey = @"finished";
static NSString *const kUCCustomDataKey = @"customData";

static NSString *const kUCEventSession = @"session";
static NSString *const kUCEventSessionEnd = @"session_ended";
static NSString *const kUCEventPurchaseSuccess = @"purchased";
static NSString *const kUCEventPurchaseFailed = @"purchase_failed";

@interface UCEvent : NSObject

@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
@property (nonatomic, copy) NSString *timestamp;
@property (nonatomic, copy) NSString *eventType;
@property (nonatomic, copy) NSString *customerId;
@property (nonatomic, copy) NSString *productId;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *transactionTime;
@property (nonatomic, copy) NSNumber *price;
@property (nonatomic, copy) NSNumber *customerAppId;
@property (nonatomic, copy) NSString *priceCurrency;
@property (nonatomic, copy) NSString *transactionId;
@property (nonatomic, strong) NSDictionary *customData;
@property (nonatomic, copy) NSString *sessionStartTimestamp;
@property (nonatomic, copy) NSString *sessionStartId;

- (id)initWithEventType:(NSString *)type;
- (NSDictionary *)dictionaryRepresentation;
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
