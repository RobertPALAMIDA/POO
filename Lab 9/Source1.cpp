#include<iostream>
#include<list>
#include<iterator>
#include<sstream>
#include<fstream>
using namespace std;

class Cerc {
private:
	float raza;
public:
	Cerc(int raza) 
	{
		this->raza = raza; 
	}
	float get_aria()
	{
		return 3.14 * raza * raza;
	}
	float get_perimetru()
	{
		return 2 * 3.14 * raza;
	}
};

class Dreptunghi {
private:
	float lungime, latime;
public:
	Dreptunghi(int lungime, int latime) 
	{
		this->lungime = lungime;
		this->latime = latime;
	}

	float get_aria()
	{
		return lungime * latime;
	}
	float get_perimetru()
	{
		return 2 * (lungime + latime);
	}
};

template<class T>
class Calcul
{
public:
	float get_aria(T obiect)
	{
		return obiect.get_aria();
	}
	float get_perimetru(T obiect)
	{
		return obiect.get_perimetru();
	}
};

int main()
{
	Cerc c(10);
	Dreptunghi d(10,5);
	Calcul <Cerc>calculator1;
	Calcul <Dreptunghi>calculator2;
	cout <<  calculator1.get_aria(c)<<endl;
	cout << calculator2.get_perimetru(d)<<endl;
	return 0;
}