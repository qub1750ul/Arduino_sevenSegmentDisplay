#include "sevenSegmentDisplay.h"

sevenSegmentDisplay::sevenSegmentDisplay(bool _displayType, uint8_t A, uint8_t B, uint8_t C, uint8_t D, uint8_t E, uint8_t F, uint8_t G, uint8_t DP)
{
	displayType = _displayType;

	segmentPin[0] = A;
	segmentPin[1] = B;
	segmentPin[2] = C;
	segmentPin[3] = D;
	segmentPin[4] = E;
	segmentPin[5] = F;
	segmentPin[6] = G;
	segmentPin[7] = DP;
	
	for(uint8_t segment = 0; segment < 7; segment++) pinMode(segmentPin[segment], OUTPUT);
	this->off();
}

void sevenSegmentDisplay::off()
{
	for(uint8_t segment = 0; segment < 7; segment++)
		if( displayType == COMMON_CATHODE ) digitalWrite(segmentPin[segment], LOW);
		else digitalWrite(segmentPin[segment], HIGH);
}

void sevenSegmentDisplay::set(uint8_t symbol)
{	
	// scroll down for the explanation of the switch case
	
	if( symbol > 9 )
		switch( symbol )
		{
			case 'A':
				symbol = 10;
				break;
				
			case 'b':
				symbol = 11;
				break;
				
			case 'C':
				symbol = 12;
				break;
				
			case 'c':
				symbol = 13;
				break;
				
			case 'd':
				symbol = 14;
				break;
				
			case 'E':
				symbol = 15;
				break;
				
			case 'F':
				symbol = 16;
				break;
				
			case 'H':
				symbol = 17;
				break;
				
			case 'h':
				symbol = 18;
				break;
				
			case 'I':
				symbol = 19;
				break;
				
			case 'J':
				symbol = 20;
				break;
				
			case 'L':
				symbol = 21;
				break;
				
			case 'n':
				symbol = 22;
				break;
				
			case 'o':
				symbol = 23;
				break;
				
			case 'P':
				symbol = 24;
				break;
				
			case 'q':
				symbol = 25;
				break;
				
			case 'r':
				symbol = 26;
				break;
				
			case 't':
				symbol = 27;
				break;
				
			case 'U':
				symbol = 28;
				break;
				
			case 'u':
				symbol = 29;
				break;
				
			case 'y':
				symbol = 30;
				break;
				
			default:
				if(symbol > 30)
				{
					this->off();
					return;
				}
		}
	
	/* Because in the symbolMap array, arrays for some alphabetic symbols are missing,
	   the allowed alphabetic symbols are discontinuous and consequently the same is for their ASCII values.
	   This means that the characters that match the relative symbols need to be "manually" remapped 
	   to the correct index number to allow them to match the correct array in the symbolMap array.
	   
	   If it is unclear have a look to the header file.
	*/
	
	for(uint8_t segment = 0; segment < 7; segment++)
		if( displayType == COMMON_CATHODE ) digitalWrite(segmentPin[segment], symbolMap[symbol][segment]);
		else digitalWrite(segmentPin[segment], !symbolMap[symbol][segment]);
}

void sevenSegmentDisplay::setSegment(uint8_t segment, bool value)
{
	if( segment == DP ) segment = 7; //the decimal point is the 7th segment, note that a constant named 'DP' is defined in the header
	else
	{
		if( ( segment < 'A' ) || ( ( segment > 'G' ) && ( segment < 'a' ) ) || ( segment > 'g' ) ) return; //if a non-allowed value is assigned to segment, do nothing
		else if( segment >= 'a' ) segment -= 97;
		else if( segment >= 'A' ) segment -= 65;
	
	/* The variable "segment" can be a char from 'A' to 'G' and from 'a' to 'g'
	
	   Because 'A' represent the first segment ( segment 0 ) and his ASCII value is 65,
	   65 is subtracted in order to make 'A' = 0 and the successive chars in match with the symbolMap index.
	   
	   Likewise 'a' represent the first segment ( segment 0 ) and his ASCII value is 97, then
	   97 is subtracted in order to make 'a' = 0 and the successive chars in match with the symbolMap index.
	*/
		
	} 
	
	if( displayType == COMMON_CATHODE ) digitalWrite(segmentPin[segment], value);
	else digitalWrite(segmentPin[segment], !value);
}
