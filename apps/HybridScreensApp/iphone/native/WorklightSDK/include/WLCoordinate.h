/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLCoordinate_H_
#import <Foundation/Foundation.h>

/**
 * A coordinate on the globe
 */
@interface WLCoordinate : NSObject {
	@private
	double latitude;
	double longitude;
	double accuracy;
	NSNumber* altitude;
	NSNumber* altitudeAccuracy;
	NSNumber* heading;
	NSNumber* speed;
}



/**
	 * @param latitude The coordinate's latitude value
	 * @param longitude The coordinate's longitude value
	 */
- (id)initWithLatitude:(double)latitude longitude:(double)longitude;
/**
	 * @param latitude The coordinate's latitude value
	 * @param longitude The coordinate's longitude value
	 * @param accuracy The coordinate's accuracy
	 */
- (id)initWithLatitude:(double)latitude longitude:(double)longitude accuracy:(double)accuracy;
- (id)initWithLatitude:(double)latitude longitude:(double)longitude altitude:(NSNumber*)altitude accuracy:(double)accuracy altitudeAccuracy:(NSNumber*)altitudeAccuracy heading:(NSNumber*)heading speed:(NSNumber*)speed;
- (NSString*) description  ;
- (int) hash  ;
- (BOOL) isEqual : (NSObject*) obj ;
/**
      * @return the coordinate's latitude.
      */
- (double) getLatitude  ;
/**
      * @return the coordinate's longitude.
      */
- (double) getLongitude  ;
/**
      * @return The coordinate's accuracy, in meters.
      */
- (double) getAccuracy  ;
/**
      * @return The coordinate's altitude, in meters. Optional - may be null.
      */
- (NSNumber*) getAltitude  ;
/**
      * @return The coordinate's altitude accuracy, in meters. Optional - may be null.
      */
- (NSNumber*) getAltitudeAccuracy  ;
/**
      * @return The coordinate's heading, in degrees [0-360). Optional - may be null.
      */
- (NSNumber*) getHeading  ;
/**
      * @return The coordinate's speed, in meters per second. Optional - may be null.
      */
- (NSNumber*) getSpeed  ;

@end

