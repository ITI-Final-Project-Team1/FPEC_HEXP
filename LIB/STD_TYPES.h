/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : LIB					******************/
/*************	 SWC   	 : DIO  				******************/
/*************	 Date    : 11 May 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/



#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char 	u8;
typedef unsigned short 	u16;
typedef unsigned int 	u32;

typedef signed char 	s8;
typedef signed short 	s16;
typedef signed int 		s32;

typedef float 			f32;
typedef double 			f64;

#ifndef NULL
#define NULL	((void*)0)
#endif

typedef enum
{
	NO_ERR = 0,
	ERR = 1,
}Err_t;


#endif
