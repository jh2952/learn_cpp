// Write an integer array class 'IntArray' (no std::array or std::vector
// allowed). Users should pass in the size of the array when it is created,
// and the array should be dynamically allocated.

// Create any constructors or overloaded operators neccessary to make the 
// the program run correctly.

// - main() & fillArray() provided by the question -

// Expected Output:
// 5 8 2 3 6    
// 5 8 2 3 6

#include <iostream>

class IntArray
{
private:
	int* m_data{};
	int m_length{};

	void deepCopy(const IntArray& arr)
	{
		delete[] m_data; // Clear space for copy

		m_length = arr.m_length; // Set new length

		if (arr.m_data)
		{
			m_data = new int[m_length]; // Generate new memory for copy

			for (int index{ 0 }; index < m_length; ++index)
				m_data[index] = arr.m_data[index]; // Copy
		}
		else
			m_data = nullptr;
	}

public:
	IntArray(int length) : m_length{ length }
	{
		m_data = new int[m_length];
	}

	// Contents contained within are explicitly defined to avoid
	// memberwise intialization.

	IntArray(const IntArray& arr)
	{
		deepCopy(arr);
	}

	IntArray& operator=(const IntArray& arr)
	{
		if (this != &arr)
		{
			deepCopy(arr);
		}
		return *this;
	}

	//

	~IntArray()
	{
		delete[] m_data;
	}

	int& operator[](int a)
	{
		return m_data[a];
	}

	friend std::ostream& operator<<(std::ostream& out, IntArray& arr);

};

std::ostream& operator<<(std::ostream& out, IntArray& arr)
{
	for (int index{ 0 }; index < arr.m_length; ++index)
	{
		out << arr.m_data[index] << ' ';
	}

	return out;
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	// If we did not define copy assignment as we did above, we would
	// have a & b pointing to the same address. the following line of code
	// - intended to only effect a - would change b. This is why we avoid
	// memberwise initialization. 

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}
