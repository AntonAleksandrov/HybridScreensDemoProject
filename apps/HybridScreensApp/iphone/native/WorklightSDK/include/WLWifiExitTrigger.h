/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLWifiExitTrigger_H_
#import "AbstractWifiAreaTrigger.h"
#import "WLConfidenceLevel.h"
@protocol WLTriggerCallback;

/**
 * A trigger for exiting an area. The device must first have been inside the area and
 * then exited the area in order for the trigger to activate. In order to re-activate
 * the device must first enter the area.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLWifiExitTrigger : AbstractWifiAreaTrigger {
}


- (id) init  ;
- (WLWifiExitTrigger*) clone  ;
- (WLWifiExitTrigger*) setAreaAccessPoints : (NSMutableArray*) areaFilters ;
- (WLWifiExitTrigger*) setOtherAccessPointsAllowed : (BOOL) otherAccessPointsAllowed ;
- (WLWifiExitTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLWifiExitTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLWifiExitTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;
- (WLWifiExitTrigger*) setConfidenceLevel : (WLConfidenceLevel) confidenceLevel ;

@end

