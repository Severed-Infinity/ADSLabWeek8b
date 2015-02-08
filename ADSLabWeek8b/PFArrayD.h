#include <iostream>

//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
	PFArrayD();
	//Initializes with a capacity of 50.
	PFArrayD(int capacityValue);
	void addElement(double element);
	//Precondition: The array is not full.
	//Postcondition: The element has been added.
	bool full() const { return (capacity == used); }
	//Returns true if the array is full, false otherwise.
	int getCapacity() const { return capacity; }
	int getNumberUsed() const { return used; }
	void emptyArray(){ used = 0; }
	//Empties the array.
	double& operator[](int index);
	//Read and change access to elements 0 through numberUsed - 1.
	PFArrayD& operator =(const PFArrayD& rightSide);
	~PFArrayD();
private:
	double *a; //For an array of doubles
	int capacity; //For the size of the array
	int used; //For the number of array positions currently in use
};
PFArrayD::PFArrayD() :capacity(50), used(0)
{
	a = new double[capacity];
}
PFArrayD::PFArrayD(int size) : capacity(size), used(0)
{
	a = new double[capacity];
}

void PFArrayD::addElement(double element)
{
	if (used >= capacity)
	{
		std::cout << "Attempt to exceed capacity in PFArrayD.\n";
		std::exit(0); //<-- this may be the error
	}
	a[used] = element;
	used++;
}
double& PFArrayD::operator[](int index)
{
	if (index >= used)
	{
		std::cout << "Illegal index in PFArrayD.\n";
		std::exit(0); //<-- this may be the error
	}
	return a[index];
}

PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
	if (capacity != rightSide.capacity)
	{
		delete[] a;
		a = new double[rightSide.capacity];
	}
	capacity = rightSide.capacity;
	used = rightSide.used;
	for (int i = 0; i < used; i++)
		a[i] = rightSide.a[i];
	return *this;
}

PFArrayD::~PFArrayD()
{
	delete[] a;
}

void showPFArrayD(PFArrayD parameter)
{
	std::cout << "The first value is: "
		<< parameter[0] << std::endl;
}

int main()
{

	PFArrayD sample(2);

	sample.addElement(5.5);
	sample.addElement(6.6);

	showPFArrayD(sample);

	std::cout << "After call: " << sample[0] << std::endl;
	std::system("pause");

	return 0;

}
