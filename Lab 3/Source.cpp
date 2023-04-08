#include <iostream>
#include <conio.h>

using namespace std;

class Persoana
{
	string nume;
	int varsta;
public:
	Persoana() {};
	Persoana(string nume, int varsta)
	{
		this->nume = nume;
		this->varsta = varsta;
	}
	void afisare()
	{
		cout << "Nume: " << nume << endl << "Varsta: " << varsta << endl;
	}
};

class Student :public Persoana
{
	int an_studiu;
public:
	Student() {};
	Student(string nume, int varsta, int an_studiu) :Persoana(nume, varsta)
	{
		this->an_studiu = an_studiu;
	}
	void afisare()
	{
		cout << "An de studiu: " << an_studiu << endl;
	}
};

class Student_licenta :public Student
{
	string specializare;
public:
	Student_licenta() {};
	Student_licenta(string nume, int varsta, int an_studiu, string specializare) :Student(nume, varsta, an_studiu)
	{
		this->specializare = specializare;
	}
	void afisare()
	{
		Persoana::afisare();
		Student::afisare();
		cout << "Specializare: " << specializare << endl;
	}
};

class Student_master :public Student
{
	string specializare;
public:
	Student_master(string nume, int varsta, int an_studiu, string specializare) :Student(nume, varsta, an_studiu)
	{
		this->specializare = specializare;
	}
	void afisare()
	{
		Persoana::afisare();
		Student::afisare();
		cout << "Specializare: " << specializare<<endl;
	}
};

class Doctorand :public Student
{
	int nr_ore;
public:
	Doctorand() {};
	Doctorand(string nume, int varsta, int an_studiu,int nr_ore):Student(nume,varsta,an_studiu)
	{
		this->nr_ore = nr_ore;
	}
	void afisare()
	{
		Persoana::afisare();
		Student::afisare();
		cout << "Numar ore lucrate: " << nr_ore<<endl;
	}
};



class Angajat :public Persoana
{
	string departament;
public:
	Angajat() {};
	Angajat(string nume, int varsta, string departament) :Persoana(nume, varsta)
	{
		this->departament = departament;
	}
	void afisare()
	{
		cout << "Departament: " << departament << endl;
	}
};

class Profesor: public Angajat
{
	int salar;
public:
	Profesor() {};
	Profesor(string nume, int varsta, string departament, int salar) :Angajat(nume, varsta, departament)
	{
		this->salar = salar;
	}
	void afisare()
	{
		Persoana::afisare();
		Angajat::afisare();
		cout << "Salar: " << salar << endl;
	}
};

class Inginer: public Angajat
{
	string domeniu;
public:
	Inginer() {};
	Inginer(string nume, int varsta, string departament, string domeniu) :Angajat(nume, varsta, departament)
	{
		this->domeniu = domeniu;
	}
	void afisare()
	{
		Persoana::afisare();
		Angajat::afisare();
		cout << "Domeniu: " << domeniu << endl;
	}
};
int main()
{
	int opt1, opt2;
	string nume, specializare, departament, domeniu;
	int varsta, an_studiu, salar;

}