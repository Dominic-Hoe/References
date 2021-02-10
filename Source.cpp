#include<iostream>

#define LOG(x) std::cout << x << std::endl

void Increment(int* value) {
	// Careful - without dereferencing the pointer, you could be incrementing the pointer rather than
	// the actual value in memory.

	(*value)++;

	// Order of operations means that you have to dereference the pointer FIRST before modifying the value
	// otherwise you'll be back at square one modifying the pointer.
}

int main() {
	int a = 5;

	// To create a reference to the above variable, declare the type of the variable and then an ampersand...
	// The ampersand is part of the type declaration and not part of the existing variable

	// int& ref = a;

	// References are more or less the same as pointers.
	// ref == a. Similar to pointers.

	// ref = 2;

	// Calling the function copies the value a (5) to the function.
	/*
		How it would look:
		void Increment(int value)
		{
			int value = 5;
			value++;
		}
	*/

	// Instead of creating a brand new value, what can be done instead is using pointers.
	// The function will instead see the memory address of the value, so rather than
	// creating a brand new variable and incrementing that, it instead directly modifies
	// the memory.

	Increment(&a);
	LOG(a);
	
	std::cin.get();
}

// Another way of doing so to make the code look cleaner is as follows.
/*

	void Increment(int& value) {
		value++;
	}

	Increment(a);
	LOG(a); == 6

	This is what references are, and it makes the code look cleaner.
	Internally when compiled, the code will look identical to the code written above, however
	references provide a cleaner solution.
*/