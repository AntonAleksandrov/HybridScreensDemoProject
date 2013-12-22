/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLWifiConnectTrigger_H_
#import "AbstractWifiFilterTrigger.h"
@class WLWifiAccessPointFilter;
@protocol WLTriggerCallback;

/**
 * A trigger that activates when connecting for the first time to an access point that
 * passes the policy's filters. The trigger can re-activate only after disconnecting
 * or connecting to an access point which doesn't pass the policy's filters.
 * @see WLWifiAcquisitionPolicy#setAccessPointFilters(java.util.List)
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls. 
 */
@interface WLWifiConnectTrigger : AbstractWifiFilterTrigger {
}


- (id) init  ;
- (WLWifiConnectTrigger*) clone  ;
- (WLWifiConnectTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLWifiConnectTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLWifiConnectTrigger*) setConnectedAccessPoint : (WLWifiAccessPointFilter*) connectedAccessPoint ;
- (WLWifiConnectTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;

@end

