#include "Polynom.h"
#include <cassert>

Polynom::Polynom(unsigned int size)
: size_(size), 
  coefs_(new double[size])
{
	for (int i = 0; i < size_; ++i)
		coefs_[i] = 0.0;
}

Polynom::Polynom(std::vector<double> coefs, unsigned int size)
{	
	size_ = (size == 0) ? coefs.size() : size;
	coefs_ = new double[size_];

	for (int i = 0; i < size_; ++i)
		coefs_[i] = 0.0;

	for (int i = 0; i < coefs.size() && i < size_; ++i)
		coefs_[i] = coefs[i];
}

Polynom::Polynom(const Polynom& other)
: size_(other.size_),
  coefs_(new double[other.size_])
{
	for (int i = 0; i < size_; ++i)
		coefs_[i] = other.coefs_[i];
}

Polynom::~Polynom()
{
	delete[] coefs_;
}

void Polynom::grow(unsigned int size)
{
	Polynom temp(*this);

	delete[] coefs_;
	
	size_ = size;
	coefs_ = new double[size_];

	for (int i = 0; i < temp.size_; ++i)
		coefs_[i] = temp.coefs_[i];

	for (int i = temp.size_; i < size_; ++i)
		coefs_[i] = 0.0;
}

unsigned int Polynom::getDegree() const
{
	for (int i = size_ - 1; i > 0; --i)
	{
		if (coefs_[i] != 0)
			return i;
	}
	return 0;
}

double Polynom::getCoef(unsigned int index) const
{
	if (index <= getDegree())
	{
		return coefs_[index];
	}
	return 0.0;
}

Polynom& Polynom::setDegree(unsigned int deg, double coef)
{
	if (deg >= size_)
	{
		grow(deg + 1);
	}
	coefs_[deg] = coef;
	return *this;
}

Polynom& Polynom::setCoef(double coef, unsigned int index)
{
	assert(index < size_);
	coefs_[index] = coef;
	return *this;
}

void Polynom::printPolynom(std::ostream& out) const
{
	for (int i = getDegree(); i >= 0; --i)
	{
		if (coefs_[i] != 0.0)
		{
			if (i != getDegree())
				out << " + ";
			
			out << coefs_[i];
			
			if (i != 0)
				out << ".x^" << i;
		}
	}
}

Polynom& Polynom::operator+=(const Polynom& other)
{
	if (size_ <= other.getDegree())
	{
		grow(other.getDegree() + 1);
	}

	for (int i = 0; i < other.size_; ++i)
		coefs_[i] += other.coefs_[i];

	return *this;
}

Polynom& Polynom::operator-=(const Polynom& other)
{
	if (size_ <= other.getDegree())
	{
		grow(other.getDegree() + 1);
	}

	for (int i = 0; i < other.size_; ++i)
		coefs_[i] -= other.coefs_[i];

	return *this;
}

Polynom& Polynom::operator*=(double c)
{
	for (int i = 0; i < size_; ++i)
		coefs_[i] *= c;

	return *this;
}

Polynom& Polynom::operator*=(const Polynom& other)
{
	Polynom p;
	for (int i = 0; i <= other.getDegree(); ++i)
	{
		Polynom temp(getDegree() + other.getDegree() + 1);
		for (int k = 0; k <= getDegree(); ++k)
		{
			temp[i + k] = coefs_[k] * other.coefs_[i];
		}
		p += temp;
	}

	delete[] coefs_;
	size_ = p.size_;
	coefs_ = new double[size_];

	for (int i = 0; i < size_; ++i)
		coefs_[i] = p.coefs_[i];

	return *this;
}

Polynom& Polynom::operator++()
{

}

Polynom& Polynom::operator=(const Polynom& other)
{
	if (this != &other)
	{
		delete[] coefs_;

		size_ = other.size_;
		coefs_ = new double[other.size_];

		for (int i = 0; i < size_; ++i)
			coefs_[i] = other.coefs_[i];
	}
	return *this;
}

double Polynom::operator()(double x)
{
	double sum = 0.0;
	for (int i = 0; i <= getDegree(); ++i)
	{
		sum += coefs_[i] * (powf(x,i));
	}
	return sum;
}

double& Polynom::operator[](unsigned int index)
{
	assert(index < size_);
	return coefs_[index];
}

const double& Polynom::operator[](unsigned int index) const
{
	assert(index < size_);
	return coefs_[index];
}

Polynom operator+(const Polynom& p1, const Polynom& p2)
{
	Polynom p = p1;
	return p += p2;
}

Polynom operator-(const Polynom& p1, const Polynom& p2)
{
	Polynom p = p1;
	return p -= p2;
}

Polynom operator*(const Polynom& p1, double c)
{
	Polynom p = p1;
	return p *= c;
}

Polynom operator*(const Polynom& p1, const Polynom& p2)
{
	Polynom p = p1;
	return p *= p2;
}

std::ostream& operator<<(std::ostream& out, const Polynom& p)
{
	p.printPolynom(out);
	return out;
}