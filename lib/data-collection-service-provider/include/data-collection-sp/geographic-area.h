/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_GEOGRAPHIC_AREA_H
#define DATA_COLLECTION_GEOGRAPHIC_AREA_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "ogs-core.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Constants *****/

/***** Enumerations *****/

typedef enum {
    DATA_COLLECTION_SHAPE_POINT=1,
    DATA_COLLECTION_SHAPE_POINT_UNCERTAINTY_CIRCLE,
    DATA_COLLECTION_SHAPE_POINT_UNCERTAINTY_ELLIPSE,
    DATA_COLLECTION_SHAPE_POLYGON,
    DATA_COLLECTION_SHAPE_POINT_ALTITUDE,
    DATA_COLLECTION_SHAPE_POINT_ALTITUDE_UNCERTAINTY,
    DATA_COLLECTION_SHAPE_ELLIPSOID_ARC
} data_collection_shape_type_e;

/***** Opaque Types *****/

typedef struct data_collection_geographic_area_s data_collection_geographic_area_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

typedef struct data_collection_geographic_coord_s {
    ogs_lnode_t node;
    double longitude_degrees; /** Range -180.0 to 180.0 */
    double latitude_degrees;  /** Range -90.0 to 90.0 */
} data_collection_geographic_coord_t;

typedef struct data_collection_uncertainty_ellipse_s {
    double semi_major_meters;
    double semi_minor_meters;
    int orientation_major_degrees;
} data_collection_uncertainty_ellipse_t;

typedef struct data_collection_uncertainty_ellipsoid_s {
    double semi_major_meters;
    double semi_minor_meters;
    double vertical_meters;
    int orientation_major_degrees;
} data_collection_uncertainty_ellipsoid_t;

/***** Library function API *****/

/** Create a new Point GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point(data_collection_geographic_coord_t *point);

/** Create a new Point with Uncertainty Circle GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_uncertainty_circle(data_collection_geographic_coord_t *point, double radius_in_meters);

/** Create a new Point with Uncertainty Ellipse GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_uncertainty_ellipse(data_collection_geographic_coord_t *point, data_collection_uncertainty_ellipse_t *uncertainty_ellipse, int confidence_percent);

/** Create a new Polygon GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_polygon(ogs_list_t *geographic_coords);

/** Create a new Point Altitude GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_altitude(data_collection_geographic_coord_t *point, double altitude_meters_above_sea);

/** Create a new Point Altitude with Uncertainty GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_altitude_uncertainty(data_collection_geographic_coord_t *point, double altitude_meters_above_sea, data_collection_uncertainty_ellipse_t *uncertainty_ellipse, double uncertainty_altitude_meters, int confidence_percent);

/** Create a new Ellipsoid Arc GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_ellipsoid_arc(data_collection_geographic_coord_t *point, int inner_radius_meters, double uncertainty_radius_meters, int offset_angle_degrees, int included_angle_degrees, int confidence_percent);

/** Destroy a GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_geographic_area_free(data_collection_geographic_area_t*);

/** Get the type of the GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_shape_type_e data_collection_geographic_area_shape_type(const data_collection_geographic_area_t*);

/** Get the type name of the GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_geographic_area_shape_name(const data_collection_geographic_area_t*);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_DATA_GEOGRAPHIC_AREA_H */
