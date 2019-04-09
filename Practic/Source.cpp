#include<iostream>
using namespace std;


int main()
{
	setlocale(0, "");

	unsigned long long a, b, c;
	int counter = 1;
	
	a = 0;
	b = 1;
	cout << a << ", " << b << ", ";
	do
	{
		
		c = a + b;
		a = b;
		b = c;
		cout << c << ", ";
		++counter;

	}
	while (counter<100);

	return 0;
	system("pause");
}