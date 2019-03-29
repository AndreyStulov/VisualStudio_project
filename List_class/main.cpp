#include<iostream>
#include<string>
using namespace std;

template <typename T>
class List //                                       Main class
{
public:
	List();
	~List();

	void push_back(T data);//                       Method Prototype

	int GetSize() { return Size; }//                Getter

	T & operator [](const int index);//             Prototype of Overload []

private:

	template <typename T>
	class Node//                                    Pressitioner
	{
	public:
		Node *pNext;
		T data;

		Node(T data=T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node <T> *head;
};

template <typename T>
List<T>::List()//                                    Constructor
{
	Size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()//                                   Destructor
{
}

template<typename T>
void List<T>::push_back(T data)//                    Method
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}

		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
T & List<T>::operator[](const int index)//       Overload operator []
{
	int counter = 0;
	
	Node<T> *current = this->head;

	while (current!=nullptr)
	{
		if (counter==index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	setlocale(0, "");

	List<int> lst;

	cout << "Enter lenght of your List: ";

	int numberCount;
	cin >> numberCount;

	for (int i = 0; i < numberCount; i++)//                  Auto-pusher
	{
		lst.push_back(rand()%10);
	}

	for (int i = 0; i < lst.GetSize(); i++)//                Out all elements
	{
		cout << lst[i] << "\t";
	}

	cout << endl << endl;

	return 0;
	system("pause");
}