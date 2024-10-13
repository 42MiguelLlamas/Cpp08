#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <limits>

class Span
{
	private:
		unsigned int n;
		unsigned int len;
		int *array;

	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span &src);
		Span &operator=(const Span &src);
		void addNumber();
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void print();
		class FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class EmptyException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};



#endif