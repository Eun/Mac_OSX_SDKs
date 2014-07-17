//
//  MKMultiPoint.h
//  MapKit
//
//  Copyright (c) 2010-2013, Apple Inc. All rights reserved.
//

#import <MapKit/MKFoundation.h>
#import <MapKit/MKShape.h>
#import <MapKit/MKGeometry.h>
#import <MapKit/MKTypes.h>

MK_CLASS_AVAILABLE(10_9, 4_0)
@interface MKMultiPoint : MKShape

@property (nonatomic, readonly) MKMapPoint *points;
@property (nonatomic, readonly) NSUInteger pointCount;

// Unproject and copy points into the provided array of coordinates that
// must be large enough to hold range.length coordinates.
- (void)getCoordinates:(CLLocationCoordinate2D *)coords range:(NSRange)range;

@end
