/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLAcquisitionFailureCallbacksConfiguration_H_
#import <Foundation/Foundation.h>
@protocol WLGeoFailureCallback;
@protocol WLWifiFailureCallback;

/**
 * Configuration of the callbacks to be called when there is an acquisition failure.
 * <p>
 * This class, like most classes used for configuring location services, returns
 * a reference to this object from its setters, to enable chaining calls. 
 */
@interface WLAcquisitionFailureCallbacksConfiguration : NSObject  <NSCopying> {
	@private
	id<WLGeoFailureCallback> geoFailureCallback;
	id<WLWifiFailureCallback> wifiFailureCallback;
}


- (id) init  ;
/**
	 * @return The wifi failure callback. The default is <code>null</code>.
	 */
- (id<WLWifiFailureCallback>) getWifiFailureCallback  ;
/**
	 * @return The geo failure callback. The default is <code>null</code>.
	 */
- (id<WLGeoFailureCallback>) getGeoFailureCallback  ;
/**
	 * Sets the wifi failure callback.
	 * 
	 * @param wifiFailureCallbacks the callback to set.
	 * @return A reference to this object.
	 */
- (WLAcquisitionFailureCallbacksConfiguration*) setWifiFailureCallback : (id<WLWifiFailureCallback>) wifiFailureCallbacks ;
/**
	 * Sets the geo failure callback.
	 * 
	 * @param geoFailureCallbacks the callback to set.
	 * @return A reference to this object.
	 */
- (WLAcquisitionFailureCallbacksConfiguration*) setGeoFailureCallback : (id<WLGeoFailureCallback>) geoFailureCallbacks ;
- (WLAcquisitionFailureCallbacksConfiguration*) clone  ;
- (int) hash  ;
- (BOOL) isEqual : (NSObject*) obj ;

@end

