/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLGeoPositionChangeTrigger_H_
#import "WLGeoTrigger.h"
@protocol WLTriggerCallback;

/**
 * A trigger for tracking changes in the device's position. It is possible to specify
 * a minimum distance that must be moved before the trigger will activate.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls.
 */
@interface WLGeoPositionChangeTrigger : WLGeoTrigger {
	@private
	double minChangeDistance;
}


- (id) init  ;
/**
	 * @return The sensitivity
	 */
- (double) getMinChangeDistance  ;
/**
	 * After the first acquisition,  this trigger will be activated only when the reported position has changed by at least <code>minChangeDistance</code> amount.
	 * This is different from setting the parameter in {@link WLGeoAcquisitionPolicy#setMinChangeDistance(int)} as other triggers may still activate
	 * due to changes in the device's position, and no power will be saved by using this method. 
	 * @param minChangeDistance the minimum distance in meters which the position must change by in order for this trigger object to be activated.
	 * The value should be greater than that of the parameter set in {@link WLGeoAcquisitionPolicy#setMinChangeDistance(int)}, otherwise it will have no effect.
	 * @return A reference to this object
	 */
- (WLGeoPositionChangeTrigger*) setMinChangeDistance : (double) minChangeDistance ;
- (WLGeoPositionChangeTrigger*) clone  ;
- (WLGeoPositionChangeTrigger*) setCallback : (id<WLTriggerCallback>) callbackFunction ;
- (WLGeoPositionChangeTrigger*) setEvent : (NSMutableDictionary*) event ;
- (WLGeoPositionChangeTrigger*) setTransmitImmediately : (BOOL) transmitImmediately ;

@end

