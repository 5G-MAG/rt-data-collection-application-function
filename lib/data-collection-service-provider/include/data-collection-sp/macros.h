/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_MACROS_H
#define DATA_COLLECTION_MACROS_H

#define _DC_CONCAT_IMPL(a,b) a ## b
#define _DC_CONCAT(a,b) _DC_CONCAT_IMPL(a,b)
#define _DC_STRING_IMPL(a) #a
#define _DC_STRING(a) _DC_STRING_IMPL(a)
#define _DC_TYPENAME(cls) _DC_CONCAT(cls, _t)
#define _DC_STRUCTNAME(cls) _DC_CONCAT(cls, _s)
#define _DC_METHODNAME(cls,method) _DC_CONCAT(_DC_CONCAT(cls, _), method)

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_MACROS_H */
