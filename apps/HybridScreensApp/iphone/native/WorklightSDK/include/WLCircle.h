/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLCircle_H_
#import <Foundation/Foundation.h>
#import "WLArea.h"
@class WLCoordinate;
@protocol AreaVisitor;

/**
 * A circle, defined by its center point and a radius.
 * This class is immutable.
 */
@interface WLCircle : NSObject  <WLArea> {
	@private
/**
	 * The circle's radius in meters
	 */
	double radius;
/**
	 * The circle's center
	 */
	WLCoordinate* center;
}



/**
	 * Creates a new circle
	 * 
	 * @param center The circle's center
	 * @param radius The circle's radius (in meters)
	 */
- (id)initWithCenter:(WLCoordinate*)center radius:(double)radius;
- (int) hash  ;
- (BOOL) isEqual : (NSObject*) obj ;
/**
	 * @exclude
	 */
- (NSObject*) accept : (id<AreaVisitor>) visitor ;
/**
      * @return the circle's radius in meters.
      */
- (double) getRadius  ;
/**
      * @return the center of the circle.
      */
- (WLCoordinate*) getCenter  ;

@end

