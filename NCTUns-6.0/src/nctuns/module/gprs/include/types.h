/*
 * Copyright (c) from 2000 to 2009
 * 
 * Network and System Laboratory 
 * Department of Computer Science 
 * College of Computer Science
 * National Chiao Tung University, Taiwan
 * All Rights Reserved.
 * 
 * This source code file is part of the NCTUns 6.0 network simulator.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation is hereby granted (excluding for commercial or
 * for-profit use), provided that both the copyright notice and this
 * permission notice appear in all copies of the software, derivative
 * works, or modified versions, and any portions thereof, and that
 * both notices appear in supporting documentation, and that credit
 * is given to National Chiao Tung University, Taiwan in all publications 
 * reporting on direct or indirect use of this code or its derivatives.
 *
 * National Chiao Tung University, Taiwan makes no representations 
 * about the suitability of this software for any purpose. It is provided 
 * "AS IS" without express or implied warranty.
 *
 * A Web site containing the latest NCTUns 6.0 network simulator software 
 * and its documentations is set up at http://NSL.csie.nctu.edu.tw/nctuns.html.
 *
 * Project Chief-Technology-Officer
 * 
 * Prof. Shie-Yuan Wang <shieyuan@csie.nctu.edu.tw>
 * National Chiao Tung University, Taiwan
 *
 * 09/01/2009
 */

#ifndef __TYPE_H
#define __TYPE_H

#include <iostream>
#include <exception>

typedef unsigned short ushort;
typedef unsigned long  ulong;
typedef unsigned char  uchar;

#define ASSERTION(exp, str) do { \
    if ( !(exp) ) {   \
        printf("<Assertion failed>" );  \
        printf("%s", (str) );   \
        assert(0);    \
    }\
} while(0)

#define IS_NULL_STR(ep, str, ret_val) do {      \
        if ( !(ep) ) {                          \
                printf("%s\n",(str));           \
                return (ret_val);               \
            }                                   \
    }while(0)

#define IS_NULL(ep, ret_val) do {     \
            if ( !(ep) ) {            \
                return (ret_val);     \
            }                         \
    }while(0)

#endif
