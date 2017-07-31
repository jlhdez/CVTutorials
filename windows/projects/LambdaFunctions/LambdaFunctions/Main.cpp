#include <iostream>

int main()
{
	std::cout << "This project demo examines different ways to use lambda functions \n" << std::endl;

	// Creating a quick function that takes in an integer
	auto quick_function = [](int a) { std::cout << "Arguments : " << a << "\n" << std::endl; };

	// Calling the function
	quick_function(42);
	quick_function(123456789);

	// Lambdas can also return values
	auto y = []() { return 21; };
	int x = y();

	std::cout << "Value returned : " << y() << std::endl;
	std::cout << "Value of x : " << x << std::endl;

	// Lambdas can "catch" variables
	/// By reference
	auto catch_reference = [&x]() { x++; };
	catch_reference();
	std::cout << "\nValue of x after catch by reference: " << x << std::endl;
	/// By copying
	auto catch_copy = [x]() { 
		int y = x;
		return ++y; 
	}; /// x cannot be modified inside the lambda if it is by copy
	std::cout << "Value of y after catch by copying: " << catch_copy() << std::endl;

	auto catch_copy_mut = [x]() mutable {
		return  x + 5;
	}; /// but lambda can modify if it is specified by using mutable
	std::cout << "Value of x after catch by copying: " << catch_copy_mut() << std::endl;


	// Just for looks
	std::cout << std::endl;

	return 0;
}