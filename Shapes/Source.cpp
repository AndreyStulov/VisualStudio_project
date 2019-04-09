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

	//Площадь пирамиды 1\2рL+площадь_основания, где L - апофема
	double AreaPyramid()
	{
		if (ApofemaOfPyramid() == 0) {return 0;}

		else 
		{
			return 1/2 * PerOfBase()*ApofemaOfPyramid();
		}
	}

private:
	int Side_C;

	//Нахождение Половины периметра одной стороны пирамиды согласно формулы р = (a+b+c)/2
	//где р - полупериметр, а b c - стороны пирамиды, где b = c так как с прилегающая к вершине сторона
	double Half_P()
	{
		return (this->Get_Side_A() + this->Get_Side_C() * 2) / 2;
	}

	//Промежуточная функция для определения апофемы пирамиды (р(р-а)(р-b)(p-c), где а - основание,
	// b = c(равные стороны), с - сторона прилегающая к вершине,
	double TempApofem()
	{
		return this->Half_P()*
			(this->Half_P() - this->Get_Side_A())*
			(this->Half_P() - this->Get_Side_C())*
			(this->Half_P() - this->Get_Side_C());
	}

	//Поиск апофемы пирамиды по формуле 2\а*корень_из_(р(р-а)(р-b)(p-c), где а - основание,
	// b = c(равные стороны), с - сторона прилегающая к вершине, р - полупериметр Р()
	double ApofemaOfPyramid()
	{
		if (this->TempApofem() < 0) { return 0; }

		else { return sqrt(this->TempApofem()) * 2 / this->Get_Side_A(); }
	}

	//Периметр основания пирамиды 2(A+B)
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
		cout << "Создан новый Прямоугольник!\nСторона А = " << A.Get_Side_A()
			<< "\nСторона Б = " << A.Get_Side_B()
			<< "\nПлощадь = " << A.Area() << endl << endl;

		Circle B;
		cout << "Создан новый Круг!\nРадиус = " << B.Get_Radius() << "\nПлощадь = " << B.Area() << endl << endl;

		Pyramid C;
		cout << "Создана новая Пирамида!\nСторона А = " << C.Get_Side_A()
			<< "\nСторона Б = " << C.Get_Side_B()
			<< "\nСторона C = "<< C.Get_Side_C()
			<< "\nПлощадь = " << C.AreaPyramid() << endl << endl;
	}

	return 0;
	system("pause");
}