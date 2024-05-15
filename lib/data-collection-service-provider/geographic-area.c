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

_DC_WRAPPED_OPENAPI_NODE_TYPE_START(geographic_area, geographic_area)
_DC_WRAPPED_OPENAPI_NODE_TYPE_END(geographic_area);

/***** Library function API *****/

/** Create a new Point GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point(data_collection_geographic_coord_t *point)
{
    data_collection_geographic_area_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, create)();

    dc_api_geographical_coordinates_t *gc_point = dc_api_geographical_coordinates_create(point->longitude_degrees, point->latitude_degrees);
    ogs_assert(gc_point);
    ogs_free(point);

    dc_api_point_t *api_point = dc_api_point_create(dc_api_supported_gad_shapes_VAL_POINT, gc_point);
    ogs_assert(api_point);

    dc_api_geographic_area_t *openapi = dc_api_geographic_area_point_create(api_point);
    ogs_assert(openapi);

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(geographic_area, create_zero)(openapi));

    return ret;
}

/** Create a new Point with Uncertainty Circle GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_uncertainty_circle(data_collection_geographic_coord_t *point, double radius_in_meters)
{
    data_collection_geographic_area_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, create)();

    dc_api_geographical_coordinates_t *gc_point = dc_api_geographical_coordinates_create(point->longitude_degrees, point->latitude_degrees);
    ogs_assert(gc_point);
    ogs_free(point);

    dc_api_point_uncertainty_circle_t *api_point = dc_api_point_uncertainty_circle_create(dc_api_supported_gad_shapes_VAL_POINT_UNCERTAINTY_CIRCLE, gc_point, radius_in_meters);
    ogs_assert(api_point);

    dc_api_geographic_area_t *openapi = dc_api_geographic_area_point_uncertainty_circle_create(api_point);
    ogs_assert(openapi);

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(geographic_area, create_zero)(openapi));

    return ret;
}

/** Create a new Point with Uncertainty Ellipse GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_uncertainty_ellipse(data_collection_geographic_coord_t *point, data_collection_uncertainty_ellipse_t *uncertainty_ellipse, int confidence_percent)
{
    data_collection_geographic_area_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, create)();

    dc_api_geographical_coordinates_t *gc_point = dc_api_geographical_coordinates_create(point->longitude_degrees, point->latitude_degrees);
    ogs_assert(gc_point);
    ogs_free(point);

    dc_api_uncertainty_ellipse_t *ue = dc_api_uncertainty_ellipse_create(uncertainty_ellipse->orientation_major_degrees, uncertainty_ellipse->semi_major_meters, uncertainty_ellipse->semi_minor_meters);
    ogs_assert(ue);
    ogs_free(uncertainty_ellipse);

    dc_api_point_uncertainty_ellipse_t *pue = dc_api_point_uncertainty_ellipse_create(dc_api_supported_gad_shapes_VAL_POINT_UNCERTAINTY_ELLIPSE, confidence_percent, gc_point, ue);
    ogs_assert(pue);

    dc_api_geographic_area_t *openapi = dc_api_geographic_area_point_uncertainty_ellipse_create(pue);
    ogs_assert(openapi);
  
    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(geographic_area, create_zero)(openapi));

    return ret;
}

/** Create a new Polygon GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_polygon(ogs_list_t *geographic_coords)
{
    data_collection_geographic_area_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, create)();

    OpenAPI_list_t *list = OpenAPI_list_create();
    ogs_assert(list);

    data_collection_geographic_coord_t *node, *next;
    ogs_list_for_each_safe(geographic_coords, next, node) {
        dc_api_geographical_coordinates_t *gc_point = dc_api_geographical_coordinates_create(node->longitude_degrees, node->latitude_degrees);
        ogs_assert(gc_point);
        OpenAPI_list_add(list, gc_point);
        ogs_list_remove(geographic_coords, node);
        ogs_free(node);
    }
    ogs_free(geographic_coords);

    dc_api_polygon_t *poly = dc_api_polygon_create(dc_api_supported_gad_shapes_VAL_POLYGON, list);
    ogs_assert(poly);

    dc_api_geographic_area_t *openapi = dc_api_geographic_area_polygon_create(poly);
    ogs_assert(openapi);

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(geographic_area, create_zero)(openapi));
  
    return ret;
}

/** Create a new Point Altitude GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_altitude(data_collection_geographic_coord_t *point, double altitude_meters_above_sea)
{
    data_collection_geographic_area_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, create)();

    dc_api_geographical_coordinates_t *gc_point = dc_api_geographical_coordinates_create(point->longitude_degrees, point->latitude_degrees);
    ogs_assert(gc_point);
    ogs_free(point);

    dc_api_point_altitude_t *pa = dc_api_point_altitude_create(dc_api_supported_gad_shapes_VAL_POINT_ALTITUDE, altitude_meters_above_sea, gc_point);
    ogs_assert(pa);

    dc_api_geographic_area_t *openapi = dc_api_geographic_area_point_altitude_create(pa);
    ogs_assert(openapi);

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(geographic_area, create_zero)(openapi));

    return ret;
}

/** Create a new Point Altitude with Uncertainty GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_point_altitude_uncertainty(data_collection_geographic_coord_t *point, double altitude_meters_above_sea, data_collection_uncertainty_ellipse_t *uncertainty_ellipse, double uncertainty_altitude_meters, int confidence_percent)
{
    data_collection_geographic_area_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, create)();

    dc_api_geographical_coordinates_t *gc_point = dc_api_geographical_coordinates_create(point->longitude_degrees, point->latitude_degrees);
    ogs_assert(gc_point);
    ogs_free(point);

    dc_api_uncertainty_ellipse_t *ue = dc_api_uncertainty_ellipse_create(uncertainty_ellipse->orientation_major_degrees, uncertainty_ellipse->semi_major_meters, uncertainty_ellipse->semi_minor_meters);
    ogs_assert(ue);
    ogs_free(uncertainty_ellipse);

    dc_api_point_altitude_uncertainty_t *pau = dc_api_point_altitude_uncertainty_create(dc_api_supported_gad_shapes_VAL_POINT_ALTITUDE_UNCERTAINTY, altitude_meters_above_sea, confidence_percent, gc_point, uncertainty_altitude_meters, ue);
    ogs_assert(pau);

    dc_api_geographic_area_t *openapi = dc_api_geographic_area_point_altitude_uncertainty_create(pau);
    ogs_assert(openapi);

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(geographic_area, create_zero)(openapi));

    return ret;
}

/** Create a new Ellipsoid Arc GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_geographic_area_t* data_collection_geographic_area_create_ellipsoid_arc(data_collection_geographic_coord_t *point, int inner_radius_meters, double uncertainty_radius_meters, int offset_angle_degrees, int included_angle_degrees, int confidence_percent)
{
    data_collection_geographic_area_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, create)();

    dc_api_geographical_coordinates_t *gc_point = dc_api_geographical_coordinates_create(point->longitude_degrees, point->latitude_degrees);
    ogs_assert(gc_point);
    ogs_free(point);

    dc_api_ellipsoid_arc_t *ea = dc_api_ellipsoid_arc_create(dc_api_supported_gad_shapes_VAL_ELLIPSOID_ARC, confidence_percent, included_angle_degrees, inner_radius_meters, offset_angle_degrees, gc_point, uncertainty_radius_meters);
    ogs_assert(ea);

    dc_api_geographic_area_t *openapi = dc_api_geographic_area_ellipsoid_arc_create(ea);
    ogs_assert(openapi);

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(geographic_area, create_zero)(openapi));

    return ret;
}

/** Destroy a GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_geographic_area_free(data_collection_geographic_area_t *area)
{
    if (!area) return;

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, free)(area);
}

/** Get the type of the GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_shape_type_e data_collection_geographic_area_shape_type(const data_collection_geographic_area_t *area)
{
    if (area) {
        const dc_api_geographic_area_t *obj = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, const_openapi)(area);
        if (obj) {
            return (data_collection_shape_type_e)*(obj->shape_ptr);
        }
    }

    return 0;
}

/** Get the type name of the GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_geographic_area_shape_name(const data_collection_geographic_area_t *area)
{
    if (!area) return NULL;
    const dc_api_geographic_area_t *obj = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(geographic_area, const_openapi)(area);
    if (!obj) return NULL;
    return dc_api_supported_gad_shapes_ToString(*(obj->shape_ptr));
}

/***** Library internal functions  *****/

_DC_WRAPPED_OPENAPI_NODE_BODY(geographic_area, geographic_area)

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
