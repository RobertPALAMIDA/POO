#include <iostream>
#include <conio.h>
#include <list>
#include <iterator>

using namespace std;

class Persoana
{
protected:
	string nume;
public:
	Persoana(string nume)
	{
		this->nume = nume;
	}

	virtual void afisare()
	{
		cout << "Numele: " << nume << "\n";
	}
};

class Profesor : public Persoana
{
protected:
    int vechime;
public:
	Profesor(string nume, int vechime) : Persoana(nume)
	{
		this->vechime = vechime;
	}
 void afisare()
	{
		cout << "Nume: " << nume;
		cout << "Vechime in invatamant : " << vechime << "\n";
	}
};

class Student :public Persoana
{
protected:
	int an_studiu;
public:
	Student(string nume, int an_studiu) :Persoana(nume)
	{
		this->an_studiu = an_studiu;
	}

	void afisare()
	{
		cout << "Nume:" << nume << endl;
		cout << "An studiu: " << an_studiu << endl;
	}
};


int main()
{
	list<Profesor*>lista_prof;
	list<Student*>lista_stud;



	system("pause");
	return 0;
}