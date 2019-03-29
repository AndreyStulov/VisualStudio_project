#include<iostream>
#include<string>
using namespace std;

class Component
{
public:
	Component(string CompanyName)
	{
		cout << "конструктор Component" << endl;
		this->CompanyName = CompanyName;
	}
	string CompanyName;
};

class GPU : public Component
{
public:
	GPU(string CompanyName): Component(CompanyName)
	{
		cout << "конструктор GPU" << endl;
	}
};

class Memory : public Component
{
public:
	Memory(string CompanyName) : Component(CompanyName)
	{
		cout << "конструктор Memory" << endl;
	}
};

class GraphicCard :public GPU, public Memory
{
public:
	GraphicCard(string GPUCompanyName, string MemoryCompanyName) :GPU(GPUCompanyName), Memory(MemoryCompanyName)
	{
		cout << "конструктор GraphicCard" << endl;
	}
};

int main()
{
	setlocale(0, "");

	GraphicCard GC("AMD", "Samsung");





	return 0;
	system("pause");
}