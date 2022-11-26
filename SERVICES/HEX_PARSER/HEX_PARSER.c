/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : SERVICES				******************/
/*************	 SWC   	 : HEX_PARSER			******************/
/*************	 Date    : 21 Nov 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "HEX_PARSER.h"

static u8 HEXP_u8ASCII_To_HEX(u8 Copy_u8HexValue)
{
	u8 Local_u8HexValue = 0;


	if(Copy_u8HexValue >= '0' && Copy_u8HexValue <= '9')
	{
		Local_u8HexValue = Copy_u8HexValue - '0';
	}
	else if(Copy_u8HexValue >= 'A' && Copy_u8HexValue <= 'F')
	{
		Local_u8HexValue = Copy_u8HexValue - 'A' + 10;
	}
	else if(Copy_u8HexValue >= 'a' && Copy_u8HexValue <= 'f')
	{
		Local_u8HexValue = Copy_u8HexValue - 'a' + 10;
	}
	else
	{
		// entered hex value is invalid
		Local_u8HexValue = -1;//255
	}

	return Local_u8HexValue;
}

// :100000000050002021020008270200082B020008EF
//   (:)        (10)               (0000)            (00)        (0050002021020008270200082B020008)     (EF)        (\n)
// (start)   (Byte Count)     (Relative Address)  (Record Type)				(Data)                    (CheckSum)    (End)


void HEXP_Get_Data(u8* Copy_u8HexRecord/*takes one hex record*/, u16* Copy_u16Data/*return Data*/)
{
	u8 Local_u8DigitLow, Local_u8DigitHigh, Local_u8ByteCount = 0, Local_u8Index, Local_u8Digit0, Local_u8Digit1, Local_u8Digit2, Local_u8Digit3, Local_u8DataCounter = 0;
	u32  Local_u32Address = HEXP_RECORD_ADDRESS;
	if(Copy_u8HexRecord[0] == HEXP_STARTING_DELIMITER)
	{
		// Get the Bytes Count
		Local_u8DigitLow  = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[2]);
		Local_u8DigitHigh = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[1]);
		Local_u8ByteCount = Local_u8DigitLow | (Local_u8DigitHigh << 4);
		// Get the Address
		Local_u8Digit0 = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[6]);
		Local_u8Digit1 = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[5]);
		Local_u8Digit2 = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[4]);
		Local_u8Digit3 = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[3]);
		Local_u32Address = Local_u32Address & 0xFFFF0000;
		Local_u32Address |= Local_u8Digit0 | (Local_u8Digit1 << 4) | (Local_u8Digit2 << 8) | (Local_u8Digit3 << 12);
		// Get the Actual Data
		for(Local_u8Index=0; Local_u8Index<Local_u8ByteCount/2; Local_u8Index++) // Divide them By 2 to get eight iteration each one with 4 byes to get the full 16 bytes
		{
			Local_u8Digit0 = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[Local_u8Index*4 + 9]);
			Local_u8Digit1 = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[Local_u8Index*4 + 10]);
			Local_u8Digit2 = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[Local_u8Index*4 + 11]);
			Local_u8Digit3 = HEXP_u8ASCII_To_HEX(Copy_u8HexRecord[Local_u8Index*4 + 12]);

			// The Flash Memory works in Big Endian mode, So
			// ABCD => 10 11 12 13
			//         12 13 10 11
			Copy_u16Data[Local_u8DataCounter] = (Local_u8Digit0 << 4) | (Local_u8Digit1) | (Local_u8Digit2 << 12) | (Local_u8Digit3 << 8);
			Local_u8DataCounter++;
		}
	}
	else
	{
		// Error : The Record doesn't start with the STARTING_DELIMITER
	}
}


#if 0
// 05A -> 0510
// Under Testing
static void HEXP_u8Convert_Whole_HEX_To_Decimal(u8* Copy_u8HexRecord, u8* Copy_u8DecimalRecord)
{
	u8 Local_u8Index=0;
	// loop until reaching the ENDING_DELIMITER
	while(Copy_u8HexRecord[Local_u8Index] != ENDING_DELIMITER)
	{
		Copy_u8DecimalRecord[Local_u8Index] = HEXP_u8HEX_To_Decimal(Copy_u8HexRecord[Local_u8Index]);
		Local_u8Index++;
	}
	// Adding '\n' to terminate the Record
//	Copy_u8DecimalRecord[++Local_u8Index] = '\n';
}





// here the input(Copy_u32Record) must be from the HEXP_u8Convert_Whole_HEX_To_Decimal function
HEXP_DataType_t HEXP_Extract_Data_From_One_Record(u8* Copy_u8Record, u8* Copy_u8Data)
{
	HEXP_DataType_t Local_returnVal = HEXP_Code;
	u8 Local_u8Index=0;

	// Check starting with STARTING_DELIMITER
	if(Copy_u8Record[Local_u8Index] == STARTING_DELIMITER)
	{
		// loop until reaching the ENDING_DELIMITER
		while(Copy_u8Record[++Local_u8Index] != ENDING_DELIMITER)
		{
			// FAIL FAST ->



			Local_u8Index++;
		}

	}
	else
	{
		// Error : doesn't start with the STARTING_DELIMITER
	}

	return Local_returnVal;
}

*/

#endif






