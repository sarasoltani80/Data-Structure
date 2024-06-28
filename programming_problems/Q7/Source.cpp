#include <iostream>
#include<vector>

using namespace std;

template<class T>
class Stack {
private:
	int top;
	int capacity;
	T* stack;
public:
	Stack(int SCapacity = 10);
	~Stack() { delete[] stack; stack = nullptr; }
	bool IsEmpty() { if (top == -1) return true; else return false; }
	void push(const T& x);
	void pop();
	int StackSize() { return top + 1; }
	void showList();
	int mySearch(T key);
	void SchangeSize();
};

template<class T>
void  Stack<T>::SchangeSize()
{
	T* temp = new T[capacity * 2];
	for (int i = 0; i < capacity; i++)
		temp[i] = stack[i];
	delete[] stack;
	stack = temp;
	capacity = capacity * 2;
}

template<class T>
Stack<T>::Stack(int SCapacity)
{
	if (SCapacity < 1)
		cout << "Capacity must be >0";
	capacity = SCapacity;
	stack = new T[capacity];
	top = -1;
}


template<class T>
void Stack<T>::push(const T& x)
{
	if (top == capacity - 1)
		SchangeSize();
	stack[++top] = x;
}


template<class T>
void Stack<T>::pop()
{
	if (IsEmpty())
	{
		cout << "Stack is empty!";
		return;
	}
	stack[top].~T();
	top--;
}


template<class T>
void Stack<T>::showList()
{
	for (int i = top; i > -1; i--)
		cout << stack[i] << " ";
	cout << endl;
}

template<class T>
int Stack<T>::mySearch(T key)
{
	for (int i = 0; i <= top; i++)
	{
		if (stack[i] == key)return i;
	}
	return -1;
}

template<class T>
class Queue {
private:
	T* queue;
	int front;
	int rear;
	int capacity;
	int size;
public:
	Queue(int Qcapacity = 5)
	{
		capacity = Qcapacity;
		queue = new T[capacity];
		front = rear = size = 0;
	}
	~Queue() { delete[] queue; queue = nullptr; }
	bool IsEmpty() { if (front == rear) return true; else return false; }
	void push(const T& x);
	void pop();
	int QueueSize();
	//void showList();
	int mySearch(T key);
	void  QchangeSize();
};

template<class T>
void Queue<T>::QchangeSize()
{
	T* temp = new T[capacity * 2];
	int j = ((front + 1) % capacity);
	int i;
	for (i = 1; j < capacity; i++, j++)
	{
		temp[i] = queue[j];
		//cout << temp[i]<<"!" << queue[j];
	}
	for (int z = 0; z < front; z++, i++)
	{
		temp[i] = queue[z];
		//cout << temp[i] << "!" << queue[z];
	}
	delete[] queue;
	queue = temp;
	//for (j = 1; j < i; j++)
	//	cout << queue[j]<<endl;
	front = 0;
	rear = i - 1;
	capacity = capacity * 2;
}

template<class T>
int Queue<T>::QueueSize()
{

	if (front <= rear)
	{
		cout << "size: " << (rear - front) << endl;
		return (rear - front);
	}
	else
	{
		cout << "size: " << (capacity - (front - rear)) << endl;
		return (capacity - (front - rear));
	}
}

template<class T>
void  Queue<T>::push(const T& x)
{
	if (front == ((rear + 1) % capacity))
	{
		QchangeSize();
	}
	int w = ((++rear) % capacity);
	queue[w] = x;
	//cout << w << " ";
}

template<class T>
void  Queue<T>::pop()
{
	front++;
	queue[front].~T();
}
template<class T>
int Queue<T>::mySearch(T key)
{

	int i;
	for (i = ((front + 1) % capacity);; i = ((i + 1) % capacity))
	{
		//cout << queue[i] << endl;
		if (i == rear + 1 || i == front)
			return -1;
		if (queue[i] == key)
			return i;
	}

}

int main()
{
	///*
	cout << "STACK:" << endl;
	Stack<int> ST(5);
	ST.push(0);
	ST.push(1);
	ST.push(2);
	ST.push(3);
	ST.push(4);
	ST.showList();
	cout << "Stack has " << ST.StackSize() << " elements." << endl;
	ST.pop();
	ST.showList();
	cout << "Stack has " << ST.StackSize() << " elements." << endl;
	cout << ST.mySearch(2) << endl;//index of 2:2
	cout << ST.mySearch(4) << endl;//vojood nadare chon pop shode pas -1 ro barmigardoone
	ST.push(3); ST.push(3); ST.push(3); ST.push(3);
	cout << "Stack has " << ST.StackSize() << " elements." << endl;
	//*/
	/*
	Stack<vector<int>> SV(5);
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	SV.push(v);
	SV.pop();
	cout << v.front();
	cout << v.front();
	*/
	cout << "QUEUE:" << endl;
	Queue<int> in(5);
	in.push(1); in.push(2); in.push(3); in.push(90); in.QueueSize();
	in.pop(); in.QueueSize();
	in.push(0); in.QueueSize();
	in.push(5); in.push(4); in.push(4); in.push(4); in.push(4); in.QueueSize();
	in.pop(); in.push(4); in.QueueSize();
	cout << in.mySearch(1) << endl;
	cout << in.mySearch(90);
	getchar();
	getchar();
	return 0;
}