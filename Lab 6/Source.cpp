#include<iostream>
#include<list>
#include<iterator>
#include<sstream>
using namespace std;

class Scaner;
class Imprimanta;

class Articole {
private:
	string producator, cod_produs;
	float rezolutie, dimensiune;
	Articole *urm;
public:
	Articole() {};
	Articole(string producator, string cod_produs, float rezolutie, float dimensiune)
	{
		this->producator = producator;
		this->cod_produs = cod_produs;
		this->rezolutie = rezolutie;
		this->dimensiune = dimensiune;
	}

	virtual void afisare()
	{
		cout << "Afisare";
	}

	friend class Scaner;
	friend class Imprimanta;
	friend void adaugare_ordonata1(list<Articole*>& articole, string producator, string cod_produs, float rezolutie, float dimensiune, string soft_inclus, int viteza_scanare);
	friend void adaugare_ordonata2(list<Articole*>& articole, string producator, string cod_produs, float rezolutie, float dimensiune, string format, string tip);
};

class Scaner:public Articole {
private:
	string soft_inclus;
	int viteza_scanare;
public:
	Scaner() {};
	Scaner(string producator, string cod_produs, float rezolutie, float dimensiune, string soft_inclus, int viteza_scanare) : Articole(producator, cod_produs, rezolutie, dimensiune)
	{
		this->soft_inclus = soft_inclus;
		this->viteza_scanare = viteza_scanare;
	}
	string afisare1()
	{
		return "Producator: " + this->producator + ", Cod produs: " + this->cod_produs + ", Rezolutie: " + to_string(this->rezolutie) + ", Dimensiune: " + to_string(this->dimensiune) + ", Soft inclus: " + this->soft_inclus + ", Viteza scanare " + to_string(viteza_scanare);

	}
};

class Imprimanta :public Articole {
private:
	string format, tip;
public:
	Imprimanta(string producator, string cod_produs, float rezolutie, float dimensiune, string format, string tip) : Articole(producator, cod_produs, rezolutie, dimensiune)
	{
		this->format = format;
		this->tip = tip;
	}
};

void adaugare_ordonata1(list<Articole*>& articole, string producator, string cod_produs, float rezolutie, float dimensiune, string soft_inclus, int viteza_scanare)
{
	Articole* art;
	auto scaner = new Scaner(producator, cod_produs, rezolutie, dimensiune, soft_inclus, viteza_scanare);
	art = scaner;
	if (articole.size() > 0)
	{
		auto i = articole.begin();
		if(art->producator.compare((*i)->producator)<0)
		{
			articole.push_front(art);
		}
		else
		{
			auto urm = next(i, 1);
			while (urm != articole.end() && (*urm)->producator.compare(art->producator) < 0)
			{
				i++;
				urm = next(i, 1);
			}
			articole.insert(urm, art);
		}
	}
	else
	{
		articole.push_back(art);
	}
}

void adaugare_ordonata2(list<Articole*>& articole, string producator, string cod_produs, float rezolutie, float dimensiune, string format, string tip)
{
	Articole* art;
	auto imp = new Imprimanta(producator, cod_produs, rezolutie, dimensiune, format, tip);
	art = imp;
	if (articole.size() > 0)
	{
		auto i = articole.begin();
		if (art->producator.compare((*i)->producator) < 0)
		{
			articole.push_front(art);
		}
		else
		{
			auto urm = next(i, 1);
			while (urm != articole.end() && (*urm)->producator.compare(art->producator) < 0)
			{
				i++;
				urm = next(i, 1);
			}
			articole.insert(urm, art);
		}
	}
	else
	{
		articole.push_back(art);
	}
}

void afisare(list<Articole*> articole) //functie afisare lista
{
	list<Articole*>::iterator i;
	for (i = articole.begin(); i != articole.end(); i++)
	{
		Articole *c=*i;
		Scaner *s;
		s =(Scaner *)c;
		cout << s->afisare1() << endl;
	}
}

int main()
{
	list<Articole*>articole;
	string producator, cod_produs, soft_inclus;
	float rezolutie, dimensiune;  
	int viteza_scanare;

	adaugare_ordonata1(articole, "Samsung", "123104", 12, 22, "Soft", 24);
	adaugare_ordonata2(articole, "Philips", "21124", 14, 21, "A4", "Landscape");
	afisare(articole);
	system("pause");
	return 0;
}