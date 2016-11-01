#ifndef sevenSegmentDisplay_lib_by_HackerInside
#define sevenSegmentDisplay_lib_by_HackerInside

#include <Arduino.h>

#ifndef common_constants_for_xSegmentDisplay_lib_by_HackerInside //This makes it possible to use more of my libraries to display segments in the same code
#define common_constants_for_xSegmentDisplay_lib_by_HackerInside

#define COMMON_CATHODE	0 //this is one of the values that the variable displayType can assume
#define COMMON_ANODE	1 //this is one of the values that the variable displayType can assume

const uint8_t DP = 255; //this is used to identify the decimal point segment in the setSegment method

#endif // common_constants_for_xSegmentDisplay_lib_by_HackerInside

class sevenSegmentDisplay
{
	public:
	
		sevenSegmentDisplay(bool displayType, uint8_t A, uint8_t B, uint8_t C, uint8_t D, uint8_t E, uint8_t F, uint8_t G, uint8_t DP);
		
		void off();
		void set(uint8_t symbol);
		void setSegment(uint8_t segment, bool value);
		
	protected:
		
		uint8_t segmentPin[8];
		bool displayType;
	
	private:
		
		//uint8_t segmentPin[8];
		const bool symbolMap[31][7] //this array maps the state of each segment for each simbol
		{
		//	{a,b,c,d,e,f,g},
			{1,1,1,1,1,1,0}, // zero
			{0,1,1,0,0,0,0}, // one
			{1,1,0,1,1,0,1}, // two
			{1,1,1,1,0,0,1}, // three
			{0,1,1,0,0,1,1}, // four
			{1,0,1,1,0,1,1}, // five
			{1,0,1,1,1,1,1}, // six
			{1,1,1,0,0,0,0}, // seven
			{1,1,1,1,1,1,1}, // eight
			{1,1,1,1,0,1,1}, // nine
			
			{1,1,1,0,1,1,1}, // A
			{0,0,1,1,1,1,1}, // b
			{1,0,0,1,1,1,0}, // C
			{0,0,0,1,1,0,1}, // c
			{0,1,1,1,1,0,1}, // d
			{1,0,0,1,1,1,1}, // E
			{1,0,0,0,1,1,1}, // F
			//G not allowed
			{0,1,1,0,1,1,1}, // H
			{0,0,1,0,1,1,1}, // h
			{0,0,0,0,1,1,0}, // I
			{0,1,1,1,0,0,0}, // J
			//K not allowed
			{0,0,0,1,1,1,0}, // L
			//M not allowed
			{0,0,1,0,1,0,1}, // n
			{0,0,1,1,1,0,1}, // o
			{1,1,0,0,1,1,1}, // P
			{1,1,1,0,0,1,1}, // q
			{0,0,0,0,1,0,1}, // r
			//S is equal to five
			{0,0,0,1,1,1,1}, // t
			{0,1,1,1,1,1,0}, // U
			{0,0,1,1,1,0,0}, // u
			//V not allowed
			//W not allowed
			//X not allowed
			{0,1,1,1,0,1,1}, // y
			//Z not allowed
		};
};

#endif // sevenSegmentDisplay_lib_by_HackerInside