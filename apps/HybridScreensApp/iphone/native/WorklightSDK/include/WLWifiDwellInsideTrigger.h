/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLWifiDwellInsideTrigger_H_
#import "AbstractWifiDwellTrigger.h"
#import "WLConfidenceLevel.h"
@protocol WLTriggerCallback;

/**
 * A trigger definition for dwelling a period of time inside an area. In order to re-activate
 * the device must first leave the area. The area is defined by the visibility
 * of a set of given access points.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLWifiDwellInsideTrigger : AbstractWifiDwellTrigger {
}


- (id) init  ;
- (WLWifiDwellInsideTrigger*) clone  ;
- (WLWifiDwellInsideTrigger*) setAreaAccessPoints : (NSMutableArray*) areaFilters ;
- (WLWifiDwellInsideTrigger*) setOtherAccessPointsAllowed : (BOOL) otherAccessPointsAllowed ;
- (WLWifiDwellInsideTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLWifiDwellInsideTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLWifiDwellInsideTrigger*) setDwellingTime : (long long) dwellingTime ;
- (WLWifiDwellInsideTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;
- (WLWifiDwellInsideTrigger*) setConfidenceLevel : (WLConfidenceLevel) confidenceLevel ;

@end

