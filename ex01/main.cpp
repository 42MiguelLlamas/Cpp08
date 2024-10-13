#include "Span.hpp"

int main()
{
	std::srand(std::time(0));
	Span A(5);
	Span B(A);
	Span C;
	Span D(1);
	try
	{
		C.addNumber();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	C = A;
	A.addNumber();
	A.addNumber();
	A.addNumber();
	A.addNumber();
	A.addNumber();
	A.print();
	std::cout << "Longest Span: " << A.longestSpan() << std::endl;
	std::cout << "Shortest Span: " << A.shortestSpan() << std::endl;
	try
	{
		A.addNumber();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		D.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		D.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}