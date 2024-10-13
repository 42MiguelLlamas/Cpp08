#include "Span.hpp"

Span::Span(): n(0), len(0)
{
	this->array = new int[0];
	std::cout << "Default constructor called." << std::endl;
}

Span::Span(unsigned int n): n(n), len(0)
{
	this->array = new int[n];
	std::cout << "Length constructor called." << std::endl;
}

Span::Span(const Span &src) : n(src.n), len(src.len)
{
	this->array = new int[n];
	for (unsigned int i = 0; i < len; i++)
	{
		this->array[i] = src.array[i];
	}
	std::cout << "Copy constructor called." << std::endl;
}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;
	this->array = new int[n];
	this->len = src.len;
	this->n = src.n;
	for (unsigned int i = 0; i < len; i++)
	{
		this->array[i] = src.array[i];
	}
	std::cout << "Copy assignment operator called." << std::endl;
	return *this;
}

Span::~Span()
{
	delete[] this->array;
	std::cout << "Destructor called." << std::endl;
}


const char *Span::FullSpanException::what(void) const throw()
{
	return "Array is already full! ";
};

const char *Span::EmptyException::what(void) const throw()
{
	return "Array is empty.";
};

void Span::addNumber()
{
	if (len == n)
		throw (Span::FullSpanException());
  	int randValue = std::rand();
	this->array[len] = randValue;
	this->len++;
}

unsigned int Span::longestSpan()
{
	if (len == 0 || len == 1)
		throw (Span::EmptyException());
	unsigned int longest = 0;
	unsigned int diff = 0;
	for (unsigned int i = 0; i < len; i++)
	{
		if (this->array[i] > this->array[i + 1])
			diff = this->array[i] - this->array[i + 1];
		else
			diff = this->array[i + 1] - this->array[i];
		if (diff > longest)
			longest = diff;
	}
	return longest;
}

unsigned int Span::shortestSpan()
{
	if (len == 0 || len == 1)
		throw (Span::EmptyException());
	unsigned int shortest = std::numeric_limits<long long>::max();
	unsigned int diff = 0;
	for (unsigned int i = 0; i < len; i++)
	{
		if (this->array[i] > this->array[i + 1])
			diff = this->array[i] - this->array[i + 1];
		else
			diff = this->array[i + 1] - this->array[i];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

void Span::print()
{
	for (unsigned int i = 0; i < len; i++)
	{
		std::cout << this->array[i] << ", ";
	}
	std::cout<<std::endl;
}