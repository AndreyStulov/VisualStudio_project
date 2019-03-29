#include<iostream>
#include<string>
using namespace std;

template <typename T>
//													 Main class
class List 
{
public:
	List();
	~List();

	//												  Method Prototype
	void push_back(T data);
	void pop_front();
	void clear();


	//												Getter
	int GetSize() { return Size; }

	//												 Prototype of Overload []
	T & operator [](const int index);

private:

	template <typename T>
	//													Pressitioner
	class Node
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
//														Constructor
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <typename T>
//														Destructor
List<T>::~List()
{
	List::clear();
}

template<typename T>
//														Method
void List<T>::push_back(T data)
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
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;

	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		List<T>::pop_front();

	}
}

template<typename T>
//														Overload operator []
T & List<T>::operator[](const int index)
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

	//														Auto-pusher
	for (int i = 0; i < numberCount; i++)
	{
		lst.push_back(rand()%10);
	}

	//														Out all elements
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << "\t";
	}

	cout << endl << endl;

	return 0;
	system("pause");
}