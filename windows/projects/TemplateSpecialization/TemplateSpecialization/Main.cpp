#include <iostream>

// These templates are not used directly by the user
namespace not_used 
{
	// Original, will throw compiler error since func is not implemented
	template<typename T, typename P>
	struct temp_impl {
		void func(T t, P p);
	};

	// Template for double & int
	template<>
	struct temp_impl<double, int> {
		void func(double d, int i)
		{
			std::cout << "This calls the double & int template" << std::endl;
			std::cout << "d : " << d << "\n\t i : " << i << std::endl;
		}
	};

	// Template for int & double
	template<>
	struct temp_impl<int, double> {
		void func(int i, double d)
		{
			std::cout << "This calls the int & double template" << std::endl;
			std::cout << "i : " << i << "\n\t d : " << d << std::endl;
		}
	};

	// Template for int & char
	template<>
	struct temp_impl<int, char> {
		void func(int i, char c)
		{
			std::cout << "This calls the int & char template" << std::endl;
			std::cout << "i : " << i << "\n\t c : " << c << std::endl;
		}
	};

}

// This is the only template the user uses
template<typename T, typename P>
struct temp_call {

	void temp(T t, P p)
	{
		not_used::temp_impl<T, P> temp_var;
		temp_var.func(t, p);
	}
};

int main()
{
	std::cout << "This program shows template partial specialization" << std::endl;

	temp_call<double, int> test_1;
	test_1.temp(3.14, 1);

	temp_call<int, double> test_2;
	test_2.temp(4, 1.25);

	temp_call<int, char> test_3;
	test_3.temp(65, 'A');

	// This call will complain since there isn't
	// a template specialized for double & char
	//temp_call<double, char> test_4;
	//test_4.temp(9.01, 'A');

	return 0;
}