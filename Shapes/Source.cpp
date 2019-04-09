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

	//������� �������� 1\2�L+�������_���������, ��� L - �������
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

	//���������� �������� ��������� ����� ������� �������� �������� ������� � = (a+b+c)/2
	//��� � - ������������, � b c - ������� ��������, ��� b = c ��� ��� � ����������� � ������� �������
	double Half_P()
	{
		return (this->Get_Side_A() + this->Get_Side_C() * 2) / 2;
	}

	//������������� ������� ��� ����������� ������� �������� (�(�-�)(�-b)(p-c), ��� � - ���������,
	// b = c(������ �������), � - ������� ����������� � �������,
	double TempApofem()
	{
		return this->Half_P()*
			(this->Half_P() - this->Get_Side_A())*
			(this->Half_P() - this->Get_Side_C())*
			(this->Half_P() - this->Get_Side_C());
	}

	//����� ������� �������� �� ������� 2\�*������_��_(�(�-�)(�-b)(p-c), ��� � - ���������,
	// b = c(������ �������), � - ������� ����������� � �������, � - ������������ �()
	double ApofemaOfPyramid()
	{
		if (this->TempApofem() < 0) { return 0; }

		else { return sqrt(this->TempApofem()) * 2 / this->Get_Side_A(); }
	}

	//�������� ��������� �������� 2(A+B)
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
		cout << "������ ����� �������������!\n������� � = " << A.Get_Side_A()
			<< "\n������� � = " << A.Get_Side_B()
			<< "\n������� = " << A.Area() << endl << endl;

		Circle B;
		cout << "������ ����� ����!\n������ = " << B.Get_Radius() << "\n������� = " << B.Area() << endl << endl;

		Pyramid C;
		cout << "������� ����� ��������!\n������� � = " << C.Get_Side_A()
			<< "\n������� � = " << C.Get_Side_B()
			<< "\n������� C = "<< C.Get_Side_C()
			<< "\n������� = " << C.AreaPyramid() << endl << endl;
	}

	return 0;
	system("pause");
}