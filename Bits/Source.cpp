#include <bitset>
#include <iostream>
//#define SHOW_DETALS

using namespace std;


unsigned char ReverseBits(unsigned char &number) 
{
	number = (number & 0x55) << 1 | (number & 0xAA) >> 1;

#ifdef SHOW_DETALS 
	bitset <8> binary2(number);
	cout << int(number) << " = " << binary2 << endl;
#endif

	number = (number & 0x33) << 2 | (number & 0xCC) >> 2;

#ifdef SHOW_DETALS 
	bitset <8> binary3(number);
	cout << int(number) << " = " << binary3 << endl;
#endif

	number = (number & 0x0F) << 4 | (number & 0xF0) >> 4;

	return number;
}

int main() 
{
	unsigned char number = 1;
	bitset <8> binary(number);
	cout << int(number)<<" = "<< binary << endl;
	cout << static_cast <int>(ReverseBits(number));
	bitset <8> binary1(number);
	cout << " = " << binary1 << endl;
}