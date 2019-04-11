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

	//Perimetr of rectangle 2(A+B)
	double PerOfBase()
	{
		return (this->Get_Side_A() + this->Get_Side_B()) * 2;
	}

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
		this->Half_p = (Get_Side_A() + Side_C * 2) / 2;
		this->TempApofem = Half_p * (Half_p - Get_Side_A())*(Half_p - Get_Side_C())*(Half_p - Get_Side_C());
		if (TempApofem>0)
		{
			this->Apofem = (sqrt(TempApofem)) * 2 / Get_Side_A();
		}
		else
		{
			this->Apofem = 0;
		}
		
	}

	//Getters
	int Get_Side_C() 
	{ return this->Side_C; }

	int Get_Apofem()
	{
		return this->Apofem;
	}

	double Area() override
	{
		if (Apofem!=0)
		{
			return 0.5 * Rectangle::PerOfBase()*Apofem + Rectangle::Area();
		}
		else
		{
			return 0;
		}
	}
	

private:
	int Side_C;
	double Half_p, TempApofem, Apofem;
	
};


int main()
{
	setlocale(0, "");
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		Rectangle A;
		cout << "Создан новый Прямоугольник!\nСторона А = " << A.Get_Side_A()
			<< "\nСторона Б = " << A.Get_Side_B()
			<< "\nПлощадь = " << A.Area() << endl << endl;

		Circle B;
		cout << "Создан новый Круг!\nРадиус = " << B.Get_Radius() << "\nПлощадь = " << B.Area() << endl << endl;

		Pyramid C;
		cout << "Создана новая Пирамида!\nСторона А = " << C.Get_Side_A()
			<< "\nСторона Б = " << C.Get_Side_B()
			<< "\nСторона C = "<< C.Get_Side_C()
			<< "\nПлощадь = " << C.Area() << endl << endl;
	}

	return 0;
	system("pause");
}
