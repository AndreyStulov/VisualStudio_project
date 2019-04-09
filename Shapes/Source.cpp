#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;



class Shape
{
public:
	virtual double Area() = 0;
};

class Rectangle : public Shape
{
public:
	//Constructor
	Rectangle()
	{
		this->Side_A = (rand() % 20)+1;
		this->Side_B = (rand() % 20) + 1;
	}

	//Getters
	int Get_Side_A() {return this->Side_A;}
	int Get_Side_B() {return this->Side_B;}

	//Formula of Area
	double Area() override {return this->Side_A * this->Side_B;}

private:
	int Side_A;
	int Side_B;

};


class Circle : public Shape
{
public:
	const double PI = 3.14;
	//Constructor
	Circle() {this->radius = (rand() % 20) + 1;}

	//Formula of Area
	double Area() override {return PI * this->radius*this->radius;}

	//Getter
	int Get_Radius() { return this->radius; }

private:
	int radius;
};

class Pyramid : public Rectangle
{
public:
	//Constructor
	Pyramid() : Rectangle()
	{
		this->Side_C = (rand() % 20) + 1;
	}

	//Getters
	int Get_Side_C() { return this->Side_C; }

	//Ïëîùàäü ïèðàìèäû 1\2ðL+ïëîùàäü_îñíîâàíèÿ, ãäå L - àïîôåìà
	double AreaPyramid()
	{
		if (ApofemaOfPyramid() == 0) {return 0;}

		else 
		{
			return 1/2 * PerOfBase()*ApofemaOfPyramid() + ::Rectangle::Area();
		}
	}

private:
	int Side_C;

	//Íàõîæäåíèå Ïîëîâèíû ïåðèìåòðà îäíîé ñòîðîíû ïèðàìèäû ñîãëàñíî ôîðìóëû ð = (a+b+c)/2
	//ãäå ð - ïîëóïåðèìåòð, à b c - ñòîðîíû ïèðàìèäû, ãäå b = c òàê êàê ñ ïðèëåãàþùàÿ ê âåðøèíå ñòîðîíà
	double Half_P()
	{
		return (this->Get_Side_A() + this->Get_Side_C() * 2) / 2;
	}

	//Ïðîìåæóòî÷íàÿ ôóíêöèÿ äëÿ îïðåäåëåíèÿ àïîôåìû ïèðàìèäû (ð(ð-à)(ð-b)(p-c), ãäå à - îñíîâàíèå,
	// b = c(ðàâíûå ñòîðîíû), ñ - ñòîðîíà ïðèëåãàþùàÿ ê âåðøèíå,
	double TempApofem()
	{
		return this->Half_P()*
			(this->Half_P() - this->Get_Side_A())*
			(this->Half_P() - this->Get_Side_C())*
			(this->Half_P() - this->Get_Side_C());
	}

	//Ïîèñê àïîôåìû ïèðàìèäû ïî ôîðìóëå 2\à*êîðåíü_èç_(ð(ð-à)(ð-b)(p-c), ãäå à - îñíîâàíèå,
	// b = c(ðàâíûå ñòîðîíû), ñ - ñòîðîíà ïðèëåãàþùàÿ ê âåðøèíå, ð - ïîëóïåðèìåòð Ð()
	double ApofemaOfPyramid()
	{
		if (this->TempApofem() < 0) { return 0; }

		else { return sqrt(this->TempApofem()) * 2 / this->Get_Side_A(); }
	}

	//Ïåðèìåòð îñíîâàíèÿ ïèðàìèäû 2(A+B)
	double PerOfBase()
	{
		return (this->Get_Side_A() + this->Get_Side_B()) * 2;
	}
};


int main()
{
	setlocale(0, "");
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		Rectangle A;
		cout << "Created new Rectangle!\nSide A = " << A.Get_Side_A()
			<< "\nSide B = " << A.Get_Side_B()
			<< "\Area = " << A.Area() << endl << endl;

		Circle B;
		cout << "Created new Circle!\nRadius = " << B.Get_Radius() << "\nArea = " << B.Area() << endl << endl;

		Pyramid C;
		cout << "Created new Pyramid!\nSide A = " << C.Get_Side_A()
			<< "\nSide B = " << C.Get_Side_B()
			<< "\nSide C = "<< C.Get_Side_C()
			<< "\nArea = " << C.AreaPyramid() << endl << endl;
	}

	return 0;
	system("pause");
}
