/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLGeoDwellInsideTrigger_H_
#import "AbstractGeoDwellTrigger.h"
#import "WLConfidenceLevel.h"
@protocol WLArea;
@protocol WLTriggerCallback;

/**
 * A trigger definition for dwelling a period of time inside an area. In order to re-activate
 * the device must first leave the area.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLGeoDwellInsideTrigger : AbstractGeoDwellTrigger {
}


- (id) init  ;
- (WLGeoDwellInsideTrigger*) clone  ;
- (WLGeoDwellInsideTrigger*) setBufferZoneWidth : (double) bufferZoneWidthInMeters ;
- (WLGeoDwellInsideTrigger*) setArea : (id<WLArea>) area ;
- (WLGeoDwellInsideTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLGeoDwellInsideTrigger*) setConfidenceLevel : (WLConfidenceLevel) confidenceLevel ;
- (WLGeoDwellInsideTrigger*) setDwellingTime : (long long) dwellingTime ;
- (WLGeoDwellInsideTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLGeoDwellInsideTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;

@end

