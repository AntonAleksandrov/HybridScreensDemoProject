/*
 *  Licensed Materials - Property of IBM
 *  5725-I43 (C) Copyright IBM Corp. 2011, 2013. All Rights Reserved.
 *  US Government Users Restricted Rights - Use, duplication or
 *  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>

@interface WLAnalytics : NSObject

@property (strong, nonatomic) NSMutableDictionary *config;

+ (WLAnalytics *) sharedSingleton;

// Methods called from the Cordova Plugin
- (void) setHeaders:(NSDictionary*) headers;
- (void) enableAnalytics;
- (void) disableAnalytics;
- (void) setPostMessageUrl:(NSString*) postMessageurl;
- (void) resetConfig;

// Methods called from Worklight runtime
- (BOOL) initAnalytics;

// Methods and functions exposed for unit testing
- (NSString *) initStringWithCookieNameAndValueFrom: (NSHTTPCookie *)cookie;
void TLFUncaughtExceptionHandler(NSException *exception);

@end
