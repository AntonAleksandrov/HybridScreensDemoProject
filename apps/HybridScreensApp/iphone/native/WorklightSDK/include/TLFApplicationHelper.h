/*
 *  Licensed Materials - Property of IBM
 *  5725-I43 (C) Copyright IBM Corp. 2011, 2013. All Rights Reserved.
 *  US Government Users Restricted Rights - Use, duplication or
 *  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */
//
//  TLFApplicationHelper.h
//  TLFLib
//
//  Created by YankeTealeaf on 6/24/13.
//
//

#if !defined TLFAPPLICATIONHELPER_H
#define TLFAPPLICATIONHELPER_H

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TLFPublicDefinitions.h"

@class TLFLib;
@class TLFKillSwitchManager;

@interface TLFApplicationHelper : NSObject <TLFLibDelegate> {
    
	TLFLib *_tlfLib;
	TLFKillSwitchManager *_killSwitchManager;
	
	NSObject<TLFLibDelegate> *__unsafe_unretained _tlfLibDelegate;
	
	BOOL _isTLFEnabled;
    
    NSString* _deviceUniqueIdString;
    NSMutableDictionary* _httpHeaders;
    NSMutableArray* _httpCookies;
}

@property(nonatomic, unsafe_unretained)NSObject<TLFLibDelegate> *TLFLibDelegate;

/*
 Returns the singleton Tealeaf application instance.
 */
+ (TLFApplicationHelper*)sharedInstance;

/**
 Setup the current monitoring level type. The framework remembers this logging level even when the application goes to the background or exits.
 @param monitoringLevelType The new monitoring level type.
 */
- (void)setCurrentMonitoringLevelType:(kTLFMonitoringLevelType)monitoringLevelType;

/**
 Returns the current monitoring level type.
 */
- (kTLFMonitoringLevelType)currentMonitoringLevelType;

/**
 Setup the Kill Switch URL. The URL to check for Kill Switch, when the page is reachable the framework initializes. If the page is not reachable the framework will not initialize.
 @param value String variable which represents the new Kill Switch URL.
 */
- (BOOL)setKillSwitchUrl:(NSString*)value;

/**
 Setup the Post Message URL. The URL for posting data to your server.
 @param value String variable which represents the new Post Message URL.
 */
- (BOOL)setPostMessageUrl:(NSString*)value;

/**
 Requests that the framework post to the server as soon as possible. It is a good idea to call this method after you have finished your own network transmissions. The device shuts down the Wi-Fi and cell radios when there is no activity.
 */
- (void)requestManualServerPost;

/**
 Starts a new Tealeaf Session. For example, if you want a new session to begin after every successful purchase.
 */
- (BOOL)startNewTLFSession;

/**
 Returns the current session ID.
 */
- (NSString*)currentSessionId;

/**
 Returns a BOOL value indicating if Tealeaf Framework is enabled or not.
 */
- (BOOL)isTLFEnabled;

/**
 Returns a string variable which represents the Tealeaf Framework version.
 */
- (NSString*)frameworkVersion;

/**
 DEPRECATED
 Request that the framework display or not the Logger View.
 @param value A BOOL value to indicate if the framework should display the Logger View.
 */
- (void)displayLoggerView:(BOOL)value; //deprecated

/**
 Request that the framework should be enabled.
 */
- (void)enableTealeafFramework;

/**
 Request that the framework should be disabled.
 */
- (void)disableTealeafFramework;

/**
 Loads configuration files located remotely.
 */
- (BOOL)reloadRemoteConfiguration:(NSString*)configURLString levelsConfigURLString:(NSString*) levelsConfigURLString maskingLevelsConfigURLString:(NSString*) maskingLevelsConfigURLString eventsLevelsConfigURLString:(NSString*) eventsLevelsConfigURLString;

/**
 Sets logging level for an event.
 */
- (BOOL)setLogLevel:(NSUInteger)logLevel forEvent:(NSString*) event;

/**
 Gets logging level for an event.
 */
- (NSUInteger)logLevelForEvent:(NSString*) event;

/**
 Sets value of a configurable item in TLFConfigurableItems.plist file.
 */
- (BOOL)setConfigurableItem:(NSString*)configItem value:(id)value;

/**
 Gets value of a configurable item either from TLFConfigurableItems.plist file or in memory data structure.
 */
- (id)valueForConfigurableItem:(NSString*)configItem;

/**
 Gets default value of a configurable item in TLFConfigurableItems.plist file.
 */
- (id)defaultValueForConfigurableItem:(NSString*)configItem;

/**
 Setup the Device ID.
 @param value String variable which represents the new Device ID.
 */
- (BOOL)setDeviceId:(NSString*)value;

/**
 Returns a string variable which represents the Device ID.
 */
- (NSString*)getDeviceId;

/**
 Returns a string variable which represents the current application context.
 */
- (NSString*)applicationContextName;

/**
 Deletes all the logged data
 */
- (void)clearCache;

- (void) setAdditionalHttpHeaders:(NSMutableDictionary*)headers;
- (void) addAdditionalHttpHeader:(NSString*)value forName:(NSString*)name;
- (void) setAdditionalHttpCookies:(NSMutableArray*)cookies;
- (void) addAdditionalHttpCookie:(NSHTTPCookie*)cookie;
-(NSDictionary*) getAdditionalHttpHeaders;
-(NSArray*) getAdditionalHttpCookies;
-(BOOL) sessionizeRequest:(NSMutableURLRequest*)request;
- (BOOL) isTealeafHybridBridgeRequest:(NSURLRequest*)request webView:(UIWebView*)webView;
- (BOOL) InjectTealeafHybridBridgeOnWebViewDidFinishLoad:(UIWebView *)webView;

- (void)sendEvent:(UIEvent*)event;
- (void)sendAction:(SEL)action to:(id)target from:(id)sender forEvent:(UIEvent *)event;

@end

#endif

