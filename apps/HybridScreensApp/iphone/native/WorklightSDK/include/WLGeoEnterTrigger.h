/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLGeoEnterTrigger_H_
#import "AbstractGeoAreaTrigger.h"
#import "WLConfidenceLevel.h"
@protocol WLArea;
@protocol WLTriggerCallback;

/**
 * A trigger for entering an area. The device must first have been outside the area and
 * then enter the area at the given confidence level in order for the trigger to activate. In order to re-activate
 * the device must first leave the area.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLGeoEnterTrigger : AbstractGeoAreaTrigger {
}


- (id) init  ;
- (WLGeoEnterTrigger*) clone  ;
- (WLGeoEnterTrigger*) setBufferZoneWidth : (double) bufferZoneWidth ;
- (WLGeoEnterTrigger*) setArea : (id<WLArea>) area ;
- (WLGeoEnterTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLGeoEnterTrigger*) setConfidenceLevel : (WLConfidenceLevel) confidenceLevel ;
- (WLGeoEnterTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLGeoEnterTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;

@end

