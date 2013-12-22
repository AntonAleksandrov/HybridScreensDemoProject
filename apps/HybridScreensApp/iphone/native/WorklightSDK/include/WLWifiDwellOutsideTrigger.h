/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLWifiDwellOutsideTrigger_H_
#import "AbstractWifiDwellTrigger.h"
#import "WLConfidenceLevel.h"
@class AbstractWifiAreaTrigger;
@protocol WLTriggerCallback;

/**
 * A trigger definition for dwelling a period of time outside an area. In order to re-activate
 * the device must first enter the area. The area is defined by the visibility
 * of a set of given access points.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLWifiDwellOutsideTrigger : AbstractWifiDwellTrigger {
}


- (id) init  ;
- (WLWifiDwellOutsideTrigger*) clone  ;
- (WLWifiDwellOutsideTrigger*) setAreaAccessPoints : (NSMutableArray*) areaFilters ;
- (WLWifiDwellOutsideTrigger*) setOtherAccessPointsAllowed : (BOOL) otherAccessPointsAllowed ;
- (WLWifiDwellOutsideTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLWifiDwellOutsideTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLWifiDwellOutsideTrigger*) setDwellingTime : (long long) dwellingTime ;
- (WLWifiDwellOutsideTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;
/**
	 * Confidence levels are not supported for the Dwell Outside trigger.
	 * This method always throws an UnsupportedOperationException.
	 * @throws UnsupportedOperationException
	 */
- (AbstractWifiAreaTrigger*) setConfidenceLevel : (WLConfidenceLevel) confidenceLevel ;

@end

