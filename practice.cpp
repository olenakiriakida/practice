#include <iostream>
using namespace std;

class Deque
{
	int* data;
	unsigned int max_count;
	unsigned int real_count = 0;

public:
	Deque(unsigned int max_count)
	{
		this->max_count = max_count;
		data = new int[max_count];
	}

	~Deque()
	{
		if (data != nullptr)
			delete[] data;
	}

	void Clear()
	{
		real_count = 0;
	}

	bool IsEmpty() const
	{
		return real_count == 0;
	}

	bool IsFull() const
	{
		return real_count == max_count;
	}

	int GetCount() const
	{
		return real_count;
	}

	void PushBack(int value) 
	{
		if (!IsFull())
			data[real_count++] = value;
	}

	void PushFront(int value) 
	{
		if (!IsFull())
		{
			for (int i = real_count; i > 0; i--)
				data[i] = data[i - 1];
			data[0] = value;
			real_count++;
		}
	}

	int PopBack() 
	{
		if (!IsEmpty())
		{
			int last = data[real_count - 1];
			real_count--;
			return last;
		}
		else
		{
			throw "Queue is empty!";
		}
	}

	int PopFront() 
	{
		if (!IsEmpty())
		{
			int first = data[0];
			for (int i = 1; i < real_count; i++)
				data[i - 1] = data[i];

			real_count--;
			return first;
		}
		else
		{
			throw "Queue is empty!";
		}
	}

	void Print() const
	{
		cout << "---------------------------------------\n";
		for (int i = 0; i < real_count; i++)
			cout << data[i] << "  ";
		cout << "\n";
		cout << "---------------------------------------\n";
	}
};

int main()
{
	Deque q(25);

	for (int i = 0; i < 5; i++)
		q.PushBack(rand() % 90 + 10);

	q.Print(); // 33 44 55 66 77

	q.PopFront();

	q.Print(); // 44 55 66 77

	for (int i = 0; i < 2; i++)
		q.PushFront(rand() % 90 + 10); // 22 33 44 55 66 77

	q.Print(); 

	for (int i = 0; i < 3; i++) // 22 33 44 
		q.PopBack();

	q.Print(); 
}