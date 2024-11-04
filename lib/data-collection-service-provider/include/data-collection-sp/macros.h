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

/** \addtogroup dcsp
 * @{
 */
/** \cond DOXY_PRIVATE_MACROS */
/** Concatenate strings in the precompiler (actual implementation)
 * \private
 *
 * Use _DC_CONCAT(a,b) instead.
 *
 * \see _DC_CONCAT
 */
#define _DC_CONCAT_IMPL(a,b) a ## b
/** Concatenate strings in the precompiler
 * \private
 */
#define _DC_CONCAT(a,b) _DC_CONCAT_IMPL(a,b)

/** Quote a value in the precompiler to use as a string (actual implementation)
 * \private
 *
 * Use _DC_STRING(a) instead.
 *
 * \see _DC_STRING
 */
#define _DC_STRING_IMPL(a) #a
/** Quote a value in the precompiler to use as a string
 * \private
 */
#define _DC_STRING(a) _DC_STRING_IMPL(a)

/** Create a type name from a class name
 * \private
 */
#define _DC_TYPENAME(cls) _DC_CONCAT(cls, _t)

/** Create a struct name from a class name
 * \private
 */
#define _DC_STRUCTNAME(cls) _DC_CONCAT(cls, _s)

/** Create a method name for a class
 * \private
 */
#define _DC_METHODNAME(cls,method) _DC_CONCAT(_DC_CONCAT(cls, _), method)

/** \endcond */
/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_MACROS_H */
