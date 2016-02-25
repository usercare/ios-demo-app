
#ifndef UCCustomizable_h
#define UCCustomizable_h

@protocol UCStyle <NSObject>

+ (id<UCStyle>)styleWithDictionary:(NSDictionary *)dictionary;
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@protocol UCCustomizable <NSObject>

- (void)updateWithStyle:(id<UCStyle>)style;

@end

#endif /* UCCustomizable_h */
