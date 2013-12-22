/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLGeoDwellOutsideTrigger_H_
#import "AbstractGeoDwellTrigger.h"
#import "WLConfidenceLevel.h"
@protocol WLArea;
@protocol WLTriggerCallback;

/**
 * A trigger definition for dwelling a period of time outside an area. In order to re-activate
 * the device must first enter the area.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLGeoDwellOutsideTrigger : AbstractGeoDwellTrigger {
}


- (id) init  ;
- (WLGeoDwellOutsideTrigger*) clone  ;
- (WLGeoDwellOutsideTrigger*) setBufferZoneWidth : (double) bufferZoneWidth ;
- (WLGeoDwellOutsideTrigger*) setArea : (id<WLArea>) area ;
- (WLGeoDwellOutsideTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLGeoDwellOutsideTrigger*) setConfidenceLevel : (WLConfidenceLevel) confidenceLevel ;
- (WLGeoDwellOutsideTrigger*) setDwellingTime : (long long) dwellingTime ;
- (WLGeoDwellOutsideTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLGeoDwellOutsideTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;

@end

