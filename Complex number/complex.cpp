#include <iostream>
using namespace std;

class Complex {
	double real_;
	double imaginery_;

	friend ostream& operator<<(ostream& out, const Complex&);
public:
	Complex(double = 0.0, double = 0.0);

	Complex& setReal(double);
	Complex& setImaginery(double);
	double getReal() const;
	double getImaginery() const;
	double mod();

	bool operator!();
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex operator*(const Complex&);
};

Complex operator+(const Complex&, const Complex&);
Complex operator+(const Complex&, double);
Complex operator+(double, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, double);
Complex operator*(double, const Complex&);

Complex::Complex(double real, double imaginery)
: real_(real), imaginery_(imaginery)
{}

Complex& Complex::setReal(double real)
{
	real_ = real;
	return *this;
}

Complex& Complex::setImaginery(double imaginery)
{
	imaginery_ = imaginery;
	return *this;
}

double Complex::getReal() const
{
	return real_;
}

double Complex::getImaginery() const
{
	return imaginery_;
}

double Complex::mod()
{
	return sqrt((real_*real_) + (imaginery_*imaginery_));
}

bool Complex::operator!()
{
	return (real_ == 0) && (imaginery_ == 0);
}

Complex& Complex::operator+=(const Complex& other)
{
	real_ += other.real_;
	imaginery_ += other.imaginery_;
	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	real_ -= other.real_;
	imaginery_ -= other.imaginery_;
	return *this;
}

Complex operator+(const Complex& left, const Complex& right)
{
	Complex c(left);
	return c += right;
}

Complex operator+(const Complex& complex, double real)
{
	Complex c(complex);
	c.setReal(c.getReal() + real);
	return c;
}

Complex operator+(double real, const Complex& complex)
{
	return complex + real;
}

Complex operator-(const Complex& left, const Complex& right)
{
	Complex c(left);
	return c -= right;
}

Complex Complex::operator*(const Complex& other)
{
	Complex c;
	c.real_ = (real_*other.real_) - (imaginery_*other.imaginery_);
	c.imaginery_ = (real_*other.imaginery_) + (imaginery_*other.real_);
	return c;
}

Complex operator*(const Complex& complex, double real)
{
	Complex c(complex);
	c.setReal(c.getReal() * real);
	c.setImaginery(c.getImaginery() * real);
	return c;
}

Complex operator*(double real, const Complex& complex)
{
	return complex * real;
}

ostream& operator<<(ostream& out, const Complex& complex)
{
	if (complex.real_ != 0)
	{
		out << complex.real_;
	}
	if (complex.imaginery_ != 0)
	{
		if (complex.imaginery_ > 0)
			out << "+";
		out << complex.imaginery_ << "i";
	}
	return out;
}

int main()
{
	Complex c1(3, -2);
	Complex c2(4, 16);

	cout << c1*c2 << endl;

	Complex c3;

	cout << !c3 << endl;

	return 0;
}