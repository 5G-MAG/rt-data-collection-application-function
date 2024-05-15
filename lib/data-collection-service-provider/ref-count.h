/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_REF_COUNT_H
#define DATA_COLLECTION_REF_COUNT_H

#include "data-collection-sp/macros.h"

#define _DC_REFCOUNT_REFNAME(a) _DC_CONCAT(a,_ref)
#define _DC_REFCOUNT_TYPENAME(a) _DC_TYPENAME(_DC_REFCOUNT_REFNAME(a))
#define _DC_REFCOUNT_STRUCTNAME(a) _DC_STRUCTNAME(_DC_REFCOUNT_REFNAME(a))
#define _DC_REFCOUNT_METHODNAME(a,method) _DC_METHODNAME(_DC_REFCOUNT_REFNAME(a),method)
#define _DC_REFCOUNT_TYPE(basecls, refname) \
typedef struct _DC_REFCOUNT_STRUCTNAME(refname) { \
    int ref; \
    _DC_TYPENAME(basecls) *refdata; \
} _DC_REFCOUNT_TYPENAME(refname)

#define _DC_REFCOUNT_PROTO(basecls, refname) \
extern _DC_REFCOUNT_TYPENAME(refname) *_DC_REFCOUNT_METHODNAME(refname,new)(_DC_TYPENAME(basecls) *base); \
extern _DC_REFCOUNT_TYPENAME(refname) *_DC_REFCOUNT_METHODNAME(refname,new0)(_DC_TYPENAME(basecls) *base); \
extern const _DC_TYPENAME(basecls) *_DC_REFCOUNT_METHODNAME(refname,const_data)(const _DC_REFCOUNT_TYPENAME(refname) *ref); \
extern _DC_TYPENAME(basecls) *_DC_REFCOUNT_METHODNAME(refname,data)(_DC_REFCOUNT_TYPENAME(refname) *ref); \
extern _DC_REFCOUNT_TYPENAME(refname) *_DC_REFCOUNT_METHODNAME(refname,ref)(_DC_REFCOUNT_TYPENAME(refname) *ref); \
extern _DC_REFCOUNT_TYPENAME(refname) *_DC_REFCOUNT_METHODNAME(refname,unref)(_DC_REFCOUNT_TYPENAME(refname) *ref); \
extern void _DC_REFCOUNT_METHODNAME(refname,free)(_DC_REFCOUNT_TYPENAME(refname) *ref); \
extern void _DC_REFCOUNT_METHODNAME(refname,del)(_DC_REFCOUNT_TYPENAME(refname) *ref)

#define _DC_REFCOUNT_BODY(basecls, refname) \
extern _DC_REFCOUNT_TYPENAME(refname) *_DC_REFCOUNT_METHODNAME(refname,new)(_DC_TYPENAME(basecls) *base) \
{ \
    _DC_REFCOUNT_TYPENAME(refname) *ret = _DC_REFCOUNT_METHODNAME(refname,new0)(base); \
    return _DC_REFCOUNT_METHODNAME(refname,ref)(ret); \
} \
extern _DC_REFCOUNT_TYPENAME(refname) *_DC_REFCOUNT_METHODNAME(refname,new0)(_DC_TYPENAME(basecls) *base) \
{ \
    _DC_REFCOUNT_TYPENAME(refname) *ret = ogs_calloc(1, sizeof(*ret)); \
    ogs_assert(ret); \
    ret->ref = 0; \
    ret->refdata = base; \
    return ret; \
} \
extern const _DC_TYPENAME(basecls) *_DC_REFCOUNT_METHODNAME(refname,const_data)(const _DC_REFCOUNT_TYPENAME(refname) *ref) \
{ \
    if (!ref) return NULL; \
    return ref->refdata; \
} \
extern _DC_TYPENAME(basecls) *_DC_REFCOUNT_METHODNAME(refname,data)(_DC_REFCOUNT_TYPENAME(refname) *ref) \
{ \
    if (!ref) return NULL; \
    return ref->refdata; \
} \
extern _DC_REFCOUNT_TYPENAME(refname) *_DC_REFCOUNT_METHODNAME(refname,ref)(_DC_REFCOUNT_TYPENAME(refname) *ref) \
{ \
    if (ref && ref->refdata) { \
        ref->ref++; \
    } \
    return ref; \
} \
extern _DC_REFCOUNT_TYPENAME(refname) *_DC_REFCOUNT_METHODNAME(refname,unref)(_DC_REFCOUNT_TYPENAME(refname) *ref) \
{ \
    if (ref && ref->refdata) { \
        if (--ref->ref <= 0) { \
            _DC_METHODNAME(basecls,free)(ref->refdata); \
            ref->refdata = NULL; \
        } \
    } \
    return ref; \
} \
extern void _DC_REFCOUNT_METHODNAME(refname,free)(_DC_REFCOUNT_TYPENAME(refname) *refobj) \
{ \
    if (_DC_REFCOUNT_METHODNAME(refname,unref)(refobj)->ref <= 0) { \
        _DC_REFCOUNT_METHODNAME(refname,del)(refobj); \
    } \
} \
extern void _DC_REFCOUNT_METHODNAME(refname,del)(_DC_REFCOUNT_TYPENAME(refname) *ref) \
{ \
    if (ref) ogs_free(ref); \
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_REF_COUNT_H */
