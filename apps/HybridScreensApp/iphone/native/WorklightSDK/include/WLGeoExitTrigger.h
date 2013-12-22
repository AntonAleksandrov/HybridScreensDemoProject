/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLGeoExitTrigger_H_
#import "AbstractGeoAreaTrigger.h"
#import "WLConfidenceLevel.h"
@protocol WLArea;
@protocol WLTriggerCallback;

/**
 * A trigger for entering an area. The device must first have been inside the area and
 * then exited the area at the given confidence level in order for the trigger to activate. In order to re-activate
 * the device must first enter the area.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLGeoExitTrigger : AbstractGeoAreaTrigger {
}


- (id) init  ;
- (WLGeoExitTrigger*) clone  ;
- (WLGeoExitTrigger*) setBufferZoneWidth : (double) bufferZoneWidth ;
- (WLGeoExitTrigger*) setArea : (id<WLArea>) area ;
- (WLGeoExitTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLGeoExitTrigger*) setConfidenceLevel : (WLConfidenceLevel) confidenceLevel ;
- (WLGeoExitTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLGeoExitTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;

@end

