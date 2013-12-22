/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLWifiVisibleAccessPointsChangeTrigger_H_
#import "WLWifiTrigger.h"
@class WLWifiAcquisitionPolicy;
@protocol WLTriggerCallback;

/**
 * A trigger for tracking changes to the visible access points.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLWifiVisibleAccessPointsChangeTrigger : WLWifiTrigger {
}


- (id) init  ;
- (BOOL) validate : (WLWifiAcquisitionPolicy*) policy ;
- (WLWifiVisibleAccessPointsChangeTrigger*) clone  ;
- (WLWifiVisibleAccessPointsChangeTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLWifiVisibleAccessPointsChangeTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLWifiVisibleAccessPointsChangeTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;

@end

