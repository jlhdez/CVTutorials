# Notes

+ Lambdas can create fast functions
```c++
auto quick_function = [](int a) { std::cout << "Arguments : " << a << "\n" << std::endl; };
quick_function(42);
```
+ Lambdas can return values
```c++
auto y = []() { return 21; };
int x = y();
```
+ Lambdas can "capture" variables
```c++
	/// By reference
	auto catch_reference = [&x]() { x++; };
	catch_reference();
	std::cout << "Value of x after catch by reference: " << x << std::endl;
	/// By copying
	auto catch_copy = [x]() { 
		int y = x;
		return ++y; 
	}; /// x cannot be modified inside the lambda if it is by copy
	std::cout << "Value of y after catch by copying: " << catch_copy() << std::endl;

	auto catch_copy_mut = [x]() mutable {
		return  x + 5;
	}; /// but lambda can modify if it is specified by using mutable
	std::cout << "Value of x after catch by copying: " << catch_copy_mut() << std::endl;; 
```
+ Ways to capture
   + `[a]` 
       + *a is captured by copying*
   + `[&a]`
       + *a is captured by copying*
   + `[this]`
       + *captures the current object (\*this)*
   + `[=]`
       + *captures all automatic variables used in the body of the lambda by copy and current object by reference if exists*
   + `[]`
       + *captures nothing*
+ Multiple capture specifiers can also be used
   + e.g. 
     + `[a, &b]` *capture a by copy and b by reference*
     + `[=, &a]` *capture all automatic variables by copy except a by reference* <!--Needs testing-->
