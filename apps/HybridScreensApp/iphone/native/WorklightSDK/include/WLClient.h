/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

//
//  WLClient.h
//  Worklight SDK
//
//  Created by Benjamin Weingarten on 3/4/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WLDelegate.h"
#import "BaseChallengeHandler.h"

@class WLCookieExtractor;
@class WLRequest;
@class WLProcedureInvocationData;
@class WLEventTransmissionPolicy;
@protocol WLDevice;

@interface WLClient : NSObject {
    
@private
	
	// PUSH NOTIFICATION
	NSMutableArray *pending;
	NSMutableDictionary *registeredEventSourceIDs;
    
    //Challenge handlers
    NSMutableDictionary *globalHeaders;
    NSMutableDictionary *challengeHandlers;
    
    // Location Services
    id<WLDevice> wlDevice;
    
    BOOL isInitialized;
}

extern NSMutableDictionary *piggyBackData;

/* 
 * @description
 * Sets an authentication handler that WLClient can use for authentication-related tasks. 
 * This method must be called for WLClient to be able to access protected resources in the Worklight server.
 */
@property (nonatomic, retain) NSMutableDictionary *registeredEventSourceIDs;

@property (nonatomic) BOOL isInitialized;

@property (readwrite) NSInteger interval;

@property (readwrite, retain) NSTimer *timer;

@property (nonatomic) BOOL isResumed;

@property (nonatomic) BOOL isRequestFailed;

@property (readwrite, retain) NSMutableDictionary *userPreferenceMap;

+ (WLClient *) sharedInstance;

/*
 * @description: 
 * Initializes communication with the Worklight Server using the connection properties and application ID 
 * taken from the worklight.plist file. At this point the Server also checks the validity of the application version.
 * This method MUST be called prior to any other WLClient method. When the Server returns a successful response, 
 * the delegate's onSuccess method is called. If an error occurs, the delegeate‚Äôs onFailure method is called.
 * 
 * @param cookieExtractor
 * Optional, can be nil. Used to share the cookies between the native code and the web code in the app.
 */
-(void) wlConnectWithDelegate:(id <WLDelegate>)delegte cookieExtractor:(WLCookieExtractor *) cookieExtractor;
-(void) wlConnectWithDelegate:(id <WLDelegate>)delegte;

/*
 * @description
 * Invokes an adapter procedure. This method is asynchronous. 
 * The response is returned to the callback functions of the provided delegate.
 * If the invocation succeeds, the delegate‚Äôs onInvokeProcedureSuccess is called. 
 * If it fails, the delegate's onInvokeProcedureFailure is called.
 */
-(void) invokeProcedure:(WLProcedureInvocationData *)invocationData withDelegate:(id <WLDelegate>)delegate;
-(void) invokeProcedure:(WLProcedureInvocationData *)invocationData withDelegate:(id <WLDelegate>)delegate options:(NSDictionary *)options;
-(void) sendInvoke:(WLProcedureInvocationData *)invocationData withDelegate:(id <WLDelegate>)delegate options:(NSDictionary *)options;

/*
 * @description
 * Subscribes the application to receive Push Notifications from the specified event source and adapter.
 * 
 * @param deviceToken
 * The token received from the method application:didRegisterForRemoteNotificationsWithDeviceToken:. 
 * The device token should be saved in case unsubscribedWithToken:adapter:eventSource:delegate: should be called.
 */
-(void) subscribeWithToken:(NSData *)deviceToken adapter:(NSString *)adapter eventSource: (NSString *)eventSource eventSourceID: (int)eventSourceID notificationType:(UIRemoteNotificationType) types delegate:(id <WLDelegate>)delegate;
-(void) subscribeWithToken:(NSData *)deviceToken adapter:(NSString *)adapter eventSource: (NSString *)eventSource eventSourceID: (int)eventSourceID notificationType:(UIRemoteNotificationType) types delegate:(id <WLDelegate>)delegate options:(NSDictionary *)options;

/*
 * @description 
 * Unsubscribes to notifications from the specified event source in the specified adapter.
 */ 
-(void) unsubscribeAdapter:(NSString *)adapter eventSource: (NSString *)eventSource delegate:(id <WLDelegate>)delegate;

/*
 * @description 
 * Returns true if the current logged in user on the current device is already subscribed to the given adapter 
 * and event source. This method does not send a query to the server for the information; rather, 
 * it checks the information received from the server in the success response for the login request.
 * If the information has not been received form the server (or if there is no subscription), this method returns false.
 */
-(BOOL) isSubscribedToAdapter:(NSString *)adapter eventSource:(NSString *)eventSource;

/*
 * @description
 * Compares the given deviceToken to the one registered in the Worklight Server with the current logged in 
 * user and current device. If different, sends the server the updated token.
 * The registered device token from the server is received in the success response for the login request, 
 * and thus is considered to be readily available without the need for an additional server call to retrieve. 
 * If a registered device token from the server is not readily available in the application, 
 * this method sends an update to the server with the given deviceToken. 
 */
-(void) updateDeviceToken:(NSData *)deviceToken  delegate:(id <WLDelegate>)delegate;

/*
 * @description
 * Returns the eventSourceID sent by the Worklight Server in the push notification.
 */
-(int) getEventSourceIDFromUserInfo:(NSDictionary *)userInfo;

//-(void)setUserPref:(NSString *)key :(NSString *)value :(id<WLDelegate>)responseListener :(NSMutableDictionary *)options;
//-(void)setUserPrefs :(NSMutableDictionary *)userPrefMap :(id<WLDelegate>)responseListener :(NSMutableDictionary *)options;
//-(void) deleteUserPref :(NSString *)key :(id<WLDelegate>)responseListener :(NSMutableDictionary *)options;
//-(NSString *)getUserPref :(NSString *)key;
//-(BOOL) hasUserPref :(NSString *)key;

/*
 * @description
 * Reports a user activity for auditing or reporting purposes. The activity is stored in the application statistics tables.
 */
-(void) logActivity:(NSString *) activityType;

/*
 * @description
 * Register a challenge handler.
 */
-(void) registerChallengeHandler: (BaseChallengeHandler *) challengeHandler;

/*
 * @description
 * Add a global header
 * Each WlRequest instance will use this header as an HTTP header.
 */
-(void) addGlobalHeader: (NSString *) headerName headerValue:(NSString *)value;

/*
 * @description
 * Remove a global header.
 */
-(void) removeGlobalHeader: (NSString *) headerName;

/*
 * @description
 * Get challenge handler by realm key
 */
-(BaseChallengeHandler *) getChallengeHandlerByRealm: (NSString *) realm;

/*
 * @description
 * Return the global headers
 */
-(NSDictionary *) getGlobalHeaders;

-(NSDictionary *) getAllChallengeHandlers;

-(void) setHeartBeatInterval :(NSInteger)val;

/**
 * Gets the WLDevice instance
 */
-(id<WLDevice>) getWLDevice;


/**
 * Equivalent to <code>[transmitEvent: eventJson immediately: NO]
 * @param event - the event to be transmitted.
 */
- (void) transmitEvent: (NSMutableDictionary*) eventJson;

/**
 * Transmits a provided event object to the server.
 * <p>
 * An event object is added to the transmission buffer. The event object is either transmitted immediately,
 * if the immediate parameter is set to <code>true</code>, otherwise it is transmitted according to the transmission policy.
 * For more information, see <code>WL.Client.setEventTransmissionPolicy</code>. One of the properties for the event object might be the device context, which comprises geo-location and WiFi data.
 * If no device context is transmitted as part of the event, the current device context, as returned by <code>WL.Device.getContext</code>, is added automatically to the event during the transmission process.
 *
 * @param eventJson - The event object that is being transmitted. The event object is either a literate object, or a reference to an object.
 * @param immediately - A boolean flag that indicates whether the transmission should be immediate (<code>true</code>), or should be based on the transmission policy's interval (<code>false</code>).
 *                        If immediate is <code>true</code>, previously buffered events are transmitted, as well as the current event. The default value is <code>false</code>.
 */
- (void) transmitEvent: (NSMutableDictionary*) eventJson immediately: (BOOL) immediately;

/**
* Configures the transmission of events from the client to the server, according to the provided transmission policy.
* @param policy The policy instance which will be used.
*/
- (void) setEventTransmissionPolicy: (WLEventTransmissionPolicy*) policy;

/**
 * Purges the internal event transmission buffer.
 * <p>
 * The internal event transmission buffer is purged, and all events awaiting transmission are permanently lost.
 */
- (void) purgeEventTransmissionBuffer;
@end
