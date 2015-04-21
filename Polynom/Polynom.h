#include <iostream>
#include <vector>

const unsigned int DEFAULT_SIZE = 10;

class Polynom
{
	double* coefs_;
	unsigned int size_;

	void grow(unsigned int);
public:
	Polynom(unsigned int = DEFAULT_SIZE);
	Polynom(std::vector<double>, unsigned int = 0);
	Polynom(const Polynom&);
	~Polynom();

	unsigned int getDegree() const;
	double getCoef(unsigned int) const;
	Polynom& setDegree(unsigned int, double);
	Polynom& setCoef(double, unsigned int);
	void printPolynom(std::ostream& = std::cout) const;

	Polynom& operator+=(const Polynom&);
	Polynom& operator-=(const Polynom&);
	Polynom& operator*=(double);
	Polynom& operator*=(const Polynom&);
	Polynom& operator++();
	Polynom& operator=(const Polynom&);
	double operator()(double);
	double& operator[](unsigned int);
	const double& operator[](unsigned int) const;
};

Polynom operator+(const Polynom&, const Polynom&);
Polynom operator-(const Polynom&, const Polynom&);
Polynom operator*(const Polynom&, double);
Polynom operator*(const Polynom&, const Polynom&);
std::ostream& operator<<(std::ostream&, const Polynom&);