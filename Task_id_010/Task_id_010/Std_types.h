

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char      uint8;    /*             0 --  255            */
typedef signed char        sint8;    /*          -128 -- +127            */
typedef unsigned short     uint16;   /*             0 --  65,535         */
typedef signed short       sint16;   /*       -32,768 -- +32,767         */
typedef unsigned long      uint32;	 /*             0 --  4,294,967,295  */
typedef signed long        sint32;   /*-2,147,483,648 -- +2,147,483,647  */

typedef unsigned long long uint64;	 /* 0 -- 18,446,744,073,709,551,615  */
typedef signed long long   sint64;	 /*   -((2^64)/2) -- +(((2^64)/2)-1) */
typedef float              float32;	 /* 32 bit float number */
typedef double             float64;	 /* 64 bit float number */

#endif /* STD_TYPES_H_ */