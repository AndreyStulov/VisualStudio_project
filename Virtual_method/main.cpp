#include<iostream>
#include<string>
using namespace std;

class Msg
{
public:
	Msg(string msg)
	{
		this->msg = msg;
	}
	virtual string GetMsg()
	{
		return msg;
	}


private:
	string msg;
};

class BracketMsg : public Msg
{
public:
	BracketMsg(string msg) :Msg(msg)
	{
	}
	string GetMsg() override
	{
		return "[" + ::Msg::GetMsg() + "]";
	}
};

class Printer
{
public:
	void PrintMsg(Msg *msg)
	{
		cout << msg->GetMsg() << endl;
	}
};

int main()
{
	setlocale(0, "");

	BracketMsg mmm("Привет");

	Printer p;
	p.PrintMsg(&mmm);




	return 0;
	system("pause");
}