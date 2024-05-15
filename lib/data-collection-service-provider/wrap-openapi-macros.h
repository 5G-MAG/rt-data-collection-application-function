/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_WRAP_OPENAPI_MACROS_H
#define DATA_COLLECTION_WRAP_OPENAPI_MACROS_H

#include "ogs-core.h"

#include "ref-count.h"
#include "data-collection-sp/macros.h"

/* External Library API names */
#define _DC_PUBLIC_NAME(name) _DC_CONCAT(data_collection_,name)
#define _DC_PUBLIC_TYPENAME(name) _DC_TYPENAME(_DC_PUBLIC_NAME(name))
#define _DC_PUBLIC_STRUCTNAME(name) _DC_STRUCTNAME(_DC_PUBLIC_NAME(name))
#define _DC_PUBLIC_METHODNAME(name,method) _DC_METHODNAME(_DC_PUBLIC_NAME(name),method)

/* OpenAPI object wrapper names */
#define _DC_OPENAPI_REF_NAME(name) _DC_CONCAT(name, _openapi)
#define _DC_OPENAPI_REF_STRUCTNAME(name) _DC_REFCOUNT_STRUCTNAME(_DC_OPENAPI_REF_NAME(name))
#define _DC_OPENAPI_REF_TYPENAME(name) _DC_REFCOUNT_TYPENAME(_DC_OPENAPI_REF_NAME(name))
#define _DC_OPENAPI_REF_FIELDNAME(name) _DC_REFCOUNT_FIELDNAME(_DC_OPENAPI_REF_NAME(name))
#define _DC_OPENAPI_REF_METHODNAME(name,method) _DC_REFCOUNT_METHODNAME(_DC_OPENAPI_REF_NAME(name), method)

/* OpenAPI generated objects names */
#define _DC_OPENAPI_NAME(name) _DC_CONCAT(dc_api_,name)
#define _DC_OPENAPI_TYPENAME(name) _DC_TYPENAME(_DC_OPENAPI_NAME(name))
#define _DC_OPENAPI_STRUCTNAME(name) _DC_STRUCTNAME(_DC_OPENAPI_NAME(name))
#define _DC_OPENAPI_METHODNAME(name, method) _DC_METHODNAME(_DC_OPENAPI_NAME(name), method)

/* Ref counted object list names */
#define _DC_REFLNODE_NAME(name) _DC_CONCAT(name, _ref_lnode)
#define _DC_REFLNODE_LISTNAME(name) _DC_CONCAT(name, _refs)
#define _DC_REFDTYPE_LIST_PARAMNAME(name) _DC_CONCAT(name, s)
#define _DC_REFLNODE_STRUCTNAME(name) _DC_STRUCTNAME(_DC_REFLNODE_NAME(name))
#define _DC_REFLNODE_TYPENAME(name) _DC_TYPENAME(_DC_REFLNODE_NAME(name))
#define _DC_REFLNODE_METHODNAME(name, method) _DC_METHODNAME(_DC_REFLNODE_NAME(name), method)

#define _DC_REFCOUNT_FIELDNAME(name) _DC_CONCAT(name, _ref)

/* Wrapped type name */
#define _DC_WRAPPED_OPENAPI_NODE_NAME(name) name
#define _DC_WRAPPED_OPENAPI_NODE_TYPENAME(name) _DC_PUBLIC_TYPENAME(name)
#define _DC_WRAPPED_OPENAPI_NODE_STRUCTNAME(name) _DC_PUBLIC_STRUCTNAME(name)
#define _DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, method) _DC_METHODNAME(_DC_WRAPPED_OPENAPI_NODE_NAME(name), method)

/***** Struct helpers *****/
#define _DC_OPENAPI_REF_TYPE(name, openapiname) _DC_REFCOUNT_TYPE(_DC_OPENAPI_NAME(openapiname), _DC_OPENAPI_REF_NAME(name))

#define _DC_REFLNODE_LIST_FIELD(name) ogs_list_t _DC_REFLNODE_LISTNAME(name)

#define _DC_REFLNODE_TYPE(name) \
typedef struct _DC_REFLNODE_STRUCTNAME(name) { \
    ogs_lnode_t node; \
    _DC_OPENAPI_REF_TYPENAME(name) *refobj; \
} _DC_REFLNODE_TYPENAME(name)

#define _DC_WRAPPED_OPENAPI_NODE_TYPE_START(name, openapiname) \
_DC_OPENAPI_REF_TYPE(name, openapiname); \
_DC_REFLNODE_TYPE(name); \
typedef struct _DC_WRAPPED_OPENAPI_NODE_STRUCTNAME(name) { \
    _DC_REFLNODE_TYPENAME(name) node;

#define _DC_WRAPPED_OPENAPI_NODE_TYPE_END(name) \
} _DC_WRAPPED_OPENAPI_NODE_TYPENAME(name)

/* Add a complex object reference to the wrapped structure */
#define _DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT(name) \
_DC_OPENAPI_REF_TYPENAME(name) *_DC_OPENAPI_REF_FIELDNAME(name)

/* Add a list of complex object references to the wrapped structure */
#define _DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT_LIST(name) \
_DC_REFLNODE_LIST_FIELD(name)

/* Create wrapper with no complex child objects/lists */
#define _DC_WRAPPED_OPENAPI_NODE_SIMPLE_TYPE(name, openapiname) \
_DC_WRAPPED_OPENAPI_NODE_TYPE_START(name, openapiname) \
_DC_WRAPPED_OPENAPI_NODE_TYPE_END(name)

/***** Internal function helpers *****/

#define _DC_WRAPPED_OPENAPI_NODE_PROTO(name, openapiname) \
typedef struct _DC_OPENAPI_REF_STRUCTNAME(name) _DC_OPENAPI_REF_TYPENAME(name); \
_DC_OPENAPI_REF_PROTO(name, openapiname); \
_DC_REFLNODE_PROTO(name); \
extern _DC_PUBLIC_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, create)(); \
extern _DC_PUBLIC_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, set_ref)(_DC_PUBLIC_TYPENAME(name) *obj, _DC_OPENAPI_REF_TYPENAME(name) *ref); \
extern _DC_OPENAPI_REF_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, get_ref)(_DC_PUBLIC_TYPENAME(name) *obj); \
extern const _DC_OPENAPI_REF_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, get_const_ref)(const _DC_PUBLIC_TYPENAME(name) *obj); \
extern _DC_PUBLIC_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, ref)(_DC_PUBLIC_TYPENAME(name) *obj); \
extern void _DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, unref)(_DC_PUBLIC_TYPENAME(name) *obj); \
extern void _DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, free)(_DC_PUBLIC_TYPENAME(name) *obj); \
extern _DC_OPENAPI_TYPENAME(openapiname) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, openapi)(_DC_PUBLIC_TYPENAME(name) *obj); \
extern const _DC_OPENAPI_TYPENAME(openapiname) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, const_openapi)(const _DC_PUBLIC_TYPENAME(name) *obj); \
extern cJSON *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, openapi_json)(const _DC_PUBLIC_TYPENAME(name) *obj); \
extern char *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, serialise)(const _DC_PUBLIC_TYPENAME(name) *obj)

#define _DC_WRAPPED_OPENAPI_NODE_BODY(name, openapiname) \
_DC_OPENAPI_REF_BODY(name, openapiname); \
_DC_REFLNODE_BODY(name); \
extern _DC_PUBLIC_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, create)() \
{ \
    _DC_PUBLIC_TYPENAME(name) *ret = ogs_calloc(1, sizeof(*ret)); \
    ogs_assert(ret); \
    return ret; \
} \
 \
extern _DC_PUBLIC_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, set_ref)(_DC_PUBLIC_TYPENAME(name) *obj, _DC_OPENAPI_REF_TYPENAME(name) *ref) \
{ \
    if (obj) { \
        obj->node.refobj = _DC_OPENAPI_REF_METHODNAME(name, ref)(ref); \
    } \
    return obj; \
} \
 \
extern _DC_OPENAPI_REF_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, get_ref)(_DC_PUBLIC_TYPENAME(name) *obj) \
{ \
    if (!obj) return NULL; \
    return _DC_REFLNODE_METHODNAME(name, ref)(&obj->node); \
} \
 \
extern const _DC_OPENAPI_REF_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, get_const_ref)(const _DC_PUBLIC_TYPENAME(name) *obj) \
{ \
    if (!obj) return NULL; \
    return _DC_REFLNODE_METHODNAME(name, const_ref)(&obj->node); \
} \
 \
extern _DC_PUBLIC_TYPENAME(name) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, ref)(_DC_PUBLIC_TYPENAME(name) *obj) \
{ \
    if (!obj) return NULL; \
    _DC_REFLNODE_METHODNAME(name, ref)(&obj->node); \
    return obj; \
} \
 \
extern void _DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, unref)(_DC_PUBLIC_TYPENAME(name) *obj) \
{ \
    if (!obj) return; \
    _DC_REFLNODE_METHODNAME(name, unref)(&obj->node); \
} \
 \
extern void _DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, free)(_DC_PUBLIC_TYPENAME(name) *obj) \
{ \
    if (!obj) return; \
    _DC_REFLNODE_METHODNAME(name, unref)(&obj->node); \
    ogs_free(obj); \
} \
 \
extern _DC_OPENAPI_TYPENAME(openapiname) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, openapi)(_DC_PUBLIC_TYPENAME(name) *obj) \
{ \
    _DC_OPENAPI_TYPENAME(openapiname) *ret = NULL; \
    if (obj) { \
        _DC_OPENAPI_REF_TYPENAME(name) *ref = _DC_REFLNODE_METHODNAME(name, ref)(&obj->node); \
        ret = _DC_OPENAPI_REF_METHODNAME(name,openapi)(ref); \
        _DC_OPENAPI_REF_METHODNAME(name,unref)(ref); \
    } \
    return ret; \
} \
 \
extern const _DC_OPENAPI_TYPENAME(openapiname) *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, const_openapi)(const _DC_PUBLIC_TYPENAME(name) *obj) \
{ \
    if (!obj) return NULL; \
    return _DC_OPENAPI_REF_METHODNAME(name, const_openapi)(_DC_REFLNODE_METHODNAME(name, const_ref)(&obj->node)); \
} \
 \
extern cJSON *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, openapi_json)(const _DC_PUBLIC_TYPENAME(name) *obj) \
{ \
    if (!obj) return NULL; \
    const _DC_OPENAPI_TYPENAME(openapiname) *openapi = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, const_openapi)(obj); \
    return _DC_OPENAPI_METHODNAME(openapiname,convertResponseToJSON)(openapi); \
} \
 \
extern char *_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, serialise)(const _DC_PUBLIC_TYPENAME(name) *obj) \
{ \
    cJSON *json = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, openapi_json)(obj); \
    char *ret = cJSON_Print(json); \
    cJSON_Delete(json); \
    return ret; \
}

#define _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT(obj, fieldtype, fnparam, localvar) \
do { \
    if (obj) { \
        if (obj->_DC_OPENAPI_REF_FIELDNAME(fieldtype)) _DC_OPENAPI_REF_METHODNAME(fieldtype, unref)(obj->_DC_OPENAPI_REF_FIELDNAME(fieldtype)); \
        obj->_DC_OPENAPI_REF_FIELDNAME(fieldtype) = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(fieldtype, get_ref)(fnparam); \
        localvar = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(fieldtype, openapi)(fnparam); \
        _DC_WRAPPED_OPENAPI_NODE_METHODNAME(fieldtype, free)(fnparam); \
    } \
} while(0)

#define _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT(name, obj, fieldtype, openapifield) \
do { \
    if (obj) { \
        if (obj->_DC_OPENAPI_REF_FIELDNAME(fieldtype)) { \
            if (_DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, openapi)(obj)->openapifield == _DC_OPENAPI_REF_METHODNAME(fieldtype, openapi)(obj->_DC_OPENAPI_REF_FIELDNAME(fieldtype))) { \
                _DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, openapi)(obj)->openapifield = NULL; \
            } \
            _DC_OPENAPI_REF_METHODNAME(fieldtype, unref)(obj->_DC_OPENAPI_REF_FIELDNAME(fieldtype)); \
            obj->_DC_OPENAPI_REF_FIELDNAME(fieldtype) = NULL; \
        } \
    } \
} while(0)

#define _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT_LIST(obj, fieldtype, fnparam, localvar) \
do { \
    if (obj && fnparam) { \
        _DC_WRAPPED_OPENAPI_NODE_TYPENAME(fieldtype) *next, *node; \
        localvar = OpenAPI_list_create(); \
        ogs_assert(localvar); \
        ogs_list_for_each_safe(fnparam, next, node) { \
            ogs_list_remove(fnparam, node); \
            ogs_list_add(&obj->_DC_REFLNODE_LISTNAME(fieldtype), node); \
            OpenAPI_list_add(localvar, _DC_WRAPPED_OPENAPI_NODE_METHODNAME(fieldtype, openapi)(node)); \
        } \
        ogs_free(fnparam); \
    } \
} while(0)

#define _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT_LIST(name, openapiname, obj, fieldtype, openapitype, openapifield) \
do { \
    if (obj) { \
        _DC_WRAPPED_OPENAPI_NODE_TYPENAME(fieldtype) *next, *node; \
        _DC_OPENAPI_TYPENAME(openapiname) *openapi = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(name, openapi)(obj); \
        ogs_list_for_each_safe(&obj->_DC_REFLNODE_LISTNAME(fieldtype), next, node) { \
            _DC_OPENAPI_TYPENAME(openapitype) *subobj = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(fieldtype, openapi)(node); \
            OpenAPI_lnode_t *oapinode; \
            ogs_list_remove(&obj->_DC_REFLNODE_LISTNAME(fieldtype), node); \
            OpenAPI_list_for_each(openapi->openapifield, oapinode) { \
                if (oapinode->data == subobj) { \
                    OpenAPI_list_remove(openapi->openapifield, oapinode); \
                } \
            } \
            _DC_WRAPPED_OPENAPI_NODE_METHODNAME(fieldtype, free)(node); \
        } \
    } \
} while(0)

#define _DC_REFLNODE_PROTO(name) \
typedef struct _DC_OPENAPI_REF_STRUCTNAME(name) _DC_OPENAPI_REF_TYPENAME(name); \
typedef struct _DC_REFLNODE_STRUCTNAME(name) _DC_REFLNODE_TYPENAME(name); \
extern _DC_OPENAPI_REF_TYPENAME(name) *_DC_REFLNODE_METHODNAME(name,ref)(_DC_REFLNODE_TYPENAME(name) *refnode); \
extern const _DC_OPENAPI_REF_TYPENAME(name) *_DC_REFLNODE_METHODNAME(name,const_ref)(const _DC_REFLNODE_TYPENAME(name) *refnode); \
extern void _DC_REFLNODE_METHODNAME(name,unref)(_DC_REFLNODE_TYPENAME(name) *refnode)

#define _DC_REFLNODE_BODY(name) \
extern _DC_OPENAPI_REF_TYPENAME(name) *_DC_REFLNODE_METHODNAME(name,ref)(_DC_REFLNODE_TYPENAME(name) *refnode) \
{ \
    if (!refnode) return NULL; \
    return _DC_OPENAPI_REF_METHODNAME(name, ref)(refnode->refobj); \
} \
 \
extern const _DC_OPENAPI_REF_TYPENAME(name) *_DC_REFLNODE_METHODNAME(name,const_ref)(const _DC_REFLNODE_TYPENAME(name) *refnode) \
{ \
    if (!refnode) return NULL; \
    return refnode->refobj; \
} \
 \
extern void _DC_REFLNODE_METHODNAME(name,unref)(_DC_REFLNODE_TYPENAME(name) *refnode) \
{ \
    if (refnode) { \
        _DC_OPENAPI_REF_METHODNAME(name,unref)(refnode->refobj); \
        refnode->refobj = NULL; \
    } \
}

#define _DC_OPENAPI_REF_PROTO(name, openapiname) \
_DC_REFCOUNT_PROTO(_DC_OPENAPI_NAME(openapiname), _DC_OPENAPI_REF_NAME(name)); \
extern _DC_OPENAPI_TYPENAME(openapiname) *_DC_OPENAPI_REF_METHODNAME(name, openapi)(_DC_OPENAPI_REF_TYPENAME(name) *ref); \
extern const _DC_OPENAPI_TYPENAME(openapiname) *_DC_OPENAPI_REF_METHODNAME(name, const_openapi)(const _DC_OPENAPI_REF_TYPENAME(name) *ref); \
extern _DC_OPENAPI_REF_TYPENAME(name) *_DC_OPENAPI_REF_METHODNAME(name, create_zero)(_DC_OPENAPI_TYPENAME(openapiname) *openapi)

#define _DC_OPENAPI_REF_BODY(name, openapiname) \
_DC_REFCOUNT_BODY(_DC_OPENAPI_NAME(openapiname), _DC_OPENAPI_REF_NAME(name)) \
extern _DC_OPENAPI_TYPENAME(openapiname) *_DC_OPENAPI_REF_METHODNAME(name, openapi)(_DC_OPENAPI_REF_TYPENAME(name) *ref) \
{ \
    return _DC_REFCOUNT_METHODNAME(_DC_OPENAPI_REF_NAME(name), data)(ref); \
} \
 \
extern const _DC_OPENAPI_TYPENAME(openapiname) *_DC_OPENAPI_REF_METHODNAME(name, const_openapi)(const _DC_OPENAPI_REF_TYPENAME(name) *ref) \
{ \
    return _DC_REFCOUNT_METHODNAME(_DC_OPENAPI_REF_NAME(name), const_data)(ref); \
} \
 \
extern _DC_OPENAPI_REF_TYPENAME(name) *_DC_OPENAPI_REF_METHODNAME(name, create_zero)(_DC_OPENAPI_TYPENAME(openapiname) *openapi) \
{ \
    return _DC_REFCOUNT_METHODNAME(_DC_OPENAPI_REF_NAME(name), new0)(openapi); \
}

#define _DC_REFDTYPE_LIST_PARAM(name) ogs_list_t *_DC_REFDTYPE_LIST_PARAMNAME(name)

#define _DC_REFLNODE_IMPORT(name, openapi_list, parent_obj) \
do { \
    if (_DC_REFDTYPE_LIST_PARAMNAME(name)) { \
        _DC_PUBLIC_TYPENAME(name) *next, *node; \
        openapi_list = OpenAPI_list_create(); \
        ogs_list_for_each_safe(_DC_REFDTYPE_LIST_PARAMNAME(name), next, node) { \
            ogs_list_remove(_DC_REFDTYPE_LIST_PARAMNAME(name), node); \
            ogs_list_add(&parent_obj->_DC_REFLNODE_LISTNAME(name), _DC_METHODNAME(name,get_ref)(node)); \
            OpenAPI_list_add(openapi_list, _DC_METHODNAME(name,openapi)(node)); \
            _DC_PUBLIC_METHODNAME(name,free)(node); \
        } \
        ogs_free(_DC_REFDTYPE_LIST_PARAMNAME(name)); \
    } \
} while(0)

#define _DC_REFLNODE_PREFREE(name, parent_obj, parent_field) \
do { \
    if (ogs_list_first(&parent_obj->_DC_REFLNODE_LISTNAME(name)) != NULL) { \
        /* remove ref'd name from openapi object and unref the sub-object */ \
        _DC_REFLNODE_TYPENAME(name) *next, *node; \
        ogs_list_for_each_safe(&parent_obj->_DC_REFLNODE_LISTNAME(name), next, node) { \
            ogs_list_remove(&parent_obj->_DC_REFLNODE_LISTNAME(name), node); \
            if (parent_obj->parent_field) { \
                OpenAPI_lnode_t *openapi_node; \
                void *target = _DC_OPENAPI_REF_METHODNAME(name,data)(node->refobj); \
                OpenAPI_list_for_each(parent_obj->parent_field->_DC_REFDTYPE_LIST_PARAMNAME(name), openapi_node) { \
                    if (openapi_node->data == target) { \
                        OpenAPI_list_remove(parent_obj->parent_field->_DC_REFDTYPE_LIST_PARAMNAME(name), openapi_node); \
                        break; \
                    } \
                } \
            } \
            _DC_OPENAPI_REF_METHODNAME(name,unref)(node->refobj); \
        } \
    } \
} while(0)

#define _DC_REFLNODE_ADD(name, parent_obj, parent_field, param) \
do { \
    _DC_REFLNODE_TYPENAME(name) *node = NULL; \
    node = ogs_calloc(1,sizeof(*node)); \
    ogs_assert(node); \
    node->refobj = _DC_METHODNAME(name,get_ref)(param); \
    OpenAPI_list_add(parent_obj->parent_field->_DC_REFDTYPE_LIST_PARAMNAME(name), _DC_OPENAPI_REF_METHODNAME(name,data)(node->refobj)); \
    ogs_list_add(&parent_obj->_DC_REFLNODE_LISTNAME(name), node); \
    _DC_PUBLIC_METHODNAME(name,free)(param); \
} while(0)

#define _DC_REFLNODE_REMOVE(name, parent_obj, parent_field, param) \
do { \
    _DC_REFLNODE_TYPENAME(name) *node, *next; \
    ogs_list_for_each_safe(&parent_obj->_DC_REFLNODE_LISTNAME(name), next, node) {  \
        if (node->refobj == (const void*)_DC_METHODNAME(name,get_const_ref)) { \
            ogs_list_remove(&parent_obj->_DC_REFLNODE_LISTNAME(name), node);\
            _DC_OPENAPI_REF_METHODNAME(name,unref)(node->refobj); \
        } \
    } \
    if (parent_obj->parent_field) { \
        OpenAPI_lnode_t *openapi_node; \
        const void *target = _DC_OPENAPI_REF_METHODNAME(name,const_data)(_DC_METHODNAME(name,get_const_ref)(param)); \
        OpenAPI_list_for_each(parent_obj->parent_field->_DC_REFDTYPE_LIST_PARAMNAME(name), openapi_node) { \
            if (openapi_node->data == target) { \
                OpenAPI_list_remove(parent_obj->parent_field->_DC_REFDTYPE_LIST_PARAMNAME(name), openapi_node); \
                break; \
            } \
        } \
    } \
} while(0)


/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_WRAP_OPENAPI_MACROS_H */
