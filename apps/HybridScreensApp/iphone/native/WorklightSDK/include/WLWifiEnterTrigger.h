/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLWifiEnterTrigger_H_
#import "AbstractWifiAreaTrigger.h"
#import "WLConfidenceLevel.h"
@protocol WLTriggerCallback;

/**
 * A trigger for entering an area. The device must first have been outside the area and
 * then enter the area in order for the trigger to activate. In order to re-activate
 * the device must first leave the area.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLWifiEnterTrigger : AbstractWifiAreaTrigger {
}


- (id) init  ;
- (WLWifiEnterTrigger*) clone  ;
- (WLWifiEnterTrigger*) setAreaAccessPoints : (NSMutableArray*) areaFilters ;
- (WLWifiEnterTrigger*) setOtherAccessPointsAllowed : (BOOL) otherAccessPointsAllowed ;
- (WLWifiEnterTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLWifiEnterTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLWifiEnterTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;
- (WLWifiEnterTrigger*) setConfidenceLevel : (WLConfidenceLevel) confidenceLevel ;

@end

