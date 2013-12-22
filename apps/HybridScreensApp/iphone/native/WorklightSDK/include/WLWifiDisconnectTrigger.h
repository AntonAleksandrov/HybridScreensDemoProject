/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLWifiDisconnectTrigger_H_
#import "AbstractWifiFilterTrigger.h"
@class WLWifiAccessPointFilter;
@protocol WLTriggerCallback;

/**
 * A trigger that activates when disconnecting for the first time from an access point that
 * passes the policy's filters. The trigger can re-activate only after connecting
 * to an access point which passes the policy's filters.
 * @see WLWifiAcquisitionPolicy#setAccessPointFilters(java.util.List)
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLWifiDisconnectTrigger : AbstractWifiFilterTrigger {
}


- (id) init  ;
- (WLWifiDisconnectTrigger*) clone  ;
- (WLWifiDisconnectTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLWifiDisconnectTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLWifiDisconnectTrigger*) setConnectedAccessPoint : (WLWifiAccessPointFilter*) connectedAccessPoint ;
- (WLWifiDisconnectTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;

@end

