/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "ogs-core.h"

#include "openapi/model/dc_api_geographic_area.h"
#include "openapi/model/dc_api_geographical_coordinates.h"
#include "openapi/model/dc_api_supported_gad_shapes.h"

#include "geographic-area-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_geographic_area_s {
    dc_api_geographic_area_t *area;
} data_collection_geographic_area_t;

/***** Library function API *****/

/** Create a new Point GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point(data_collection_geographic_coord_t *point)
{
    data_collection_geographic_area_t *ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);
    
    dc_api_geographical_coordinates_t *gc_point = dc_api_geographical_coordinates_create(point->longitude_degrees, point->latitude_degrees);
    ogs_assert(gc_point);

    ret->area = dc_api_geographic_area_create(dc_api_supported_gad_shapes_VAL_POINT, gc_point, 0.0, 0, NULL, NULL, 0.0, 0.0, 0, 0, 0, 0.0);
    ogs_assert(ret->area);

    return ret;
}

/** Create a new Point with Uncertainty Circle GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_uncertainty_circle(data_collection_geographic_coord_t *point, double radius_in_meters)
{
    data_collection_geographic_area_t *ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    dc_api_geographical_coordinates_t *gc_point = dc_api_geographical_coordinates_create(point->longitude_degrees, point->latitude_degrees);

    ret->area = dc_api_geographic_area_create(dc_api_supported_gad_shapes_VAL_POINT, gc_point, radius_in_meters, 0, NULL, NULL, 0.0, 0.0, 0, 0, 0, 0.0);

    return ret;
}

/** Create a new Point with Uncertainty Ellipse GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_uncertainty_ellipse(data_collection_geographic_coord_t *point, data_collection_uncertainty_ellipse_t *uncertainty_ellipse, int confidence_percent)
{
    /* TODO: implement this */
    return NULL;
}

/** Create a new Polygon GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_polygon(ogs_list_t *geographic_coords)
{
    /* TODO: implement this */
    return NULL;
}

/** Create a new Point Altitude GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_altitude(data_collection_geographic_coord_t *point, double altitude_meters_above_sea)
{
    /* TODO: implement this */
    return NULL;
}

/** Create a new Point Altitude with Uncertainty GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_altitude_uncertainty(data_collection_geographic_coord_t *point, double altitude_meters_above_sea, data_collection_uncertainty_ellipse_t *uncertainty_ellipse, double uncertainty_altitude_meters, int confidence_percent)
{
    /* TODO: implement this */
    return NULL;
}

/** Create a new Ellipsoid Arc GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_ellipsoid_arc(data_collection_geographic_coord_t *point, int inner_radius_meters, double uncertainty_radius_meters, int offset_angle_degrees, int included_angle_degrees, int confidence_percent)
{
    /* TODO: implement this */
    return NULL;
}

/** Destroy a GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_geographic_area_free(data_collection_geographic_area_t *area)
{
    if (!area) return;

    if (area->area) {
        dc_api_geographic_area_free(area->area);
        area->area = NULL;
    }

    ogs_free(area);
}

/** Get the type of the GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_shape_type_e data_collection_geographic_area_shape_type(const data_collection_geographic_area_t *area)
{
    if (area && area->area) {
        return (data_collection_shape_type_e)area->area->shape;
    }

    return 0;
}

/** Get the type name of the GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_geographic_area_shape_name(const data_collection_geographic_area_t *area)
{
    if (!area || !area->area) return NULL;
    return dc_api_supported_gad_shapes_ToString(area->area->shape);
}

/***** Library internal functions  *****/

/** Create GeographicArea from openapi data type */
data_collection_geographic_area_t* geographic_area_from_openapi(dc_api_geographic_area_t *area)
{
    data_collection_geographic_area_t *ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    ret->area = area;

    return ret;
}

/** Remove the openapi data type from GeographicArea */
dc_api_geographic_area_t *geographic_area_move_openapi(data_collection_geographic_area_t *area)
{
    dc_api_geographic_area_t *ret = NULL;

    if (area) {
        ret = area->area;
        area->area = NULL;
    }

    return ret;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
