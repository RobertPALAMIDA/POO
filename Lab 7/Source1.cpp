#include<iostream>
#include<list>
#include<iterator>
#include<sstream>
using namespace std;

class Copil;

class Persoana {
private:
	string nume;
	int varsta;
public:
	Persoana() {};
	Persoana(string nume, int varsta)
	{
		this->nume = nume;
		this->varsta = varsta;
	}
	friend void adaugare_ordonata(list<Copil*>& lista_copii, string nume, int varsta, string scoala, int clasa, string joc_preferat);
	friend class Copil;
};

class Elev {
private:
	string scoala;
	int clasa;
public:
	Elev() {};
	Elev(string scoala, int clasa)
	{
		this->scoala = scoala;
		this->clasa = clasa;
	}
	friend class Copil;
};

class Copil : public Persoana, public Elev {
private:
	string joc_preferat;
public:
	Copil() {};
	Copil(string nume, int varsta, string scoala, int clasa, string joc_preferat):Persoana(nume, varsta), Elev(scoala, clasa)
	{
		this->joc_preferat = joc_preferat;
	}
	string afisare()
	{
		return "Nume: " + this->nume + ", Varsta: " + to_string(this->varsta) + ", Scoala: " + this->scoala + ", Clasa: " + to_string(this->clasa) + ", Jocul Preferat: " + this->joc_preferat;
	}
	friend void cautare(list<Copil*>& lista_copii, string joc_preferat);
};


void adaugare_ordonata(list<Copil*>& lista_copii, string nume, int varsta, string scoala, int clasa, string joc_preferat)
{
	Copil *p;
	auto c = new Copil(nume,varsta,scoala,clasa,joc_preferat);
	p=c;
	if (lista_copii.size() > 0)
	{
		auto i = lista_copii.begin();
		if (p->nume.compare((*i)->nume) < 0)
		{
			lista_copii.push_front(p);
		}
		else
		{
			auto urm = next(i, 1);
			while (urm != lista_copii.end() && (*urm)->nume.compare(p->nume) < 0)
			{
				i++;
				urm = next(i, 1);
			}
			lista_copii.insert(urm, p);
		}
	}
	else
	{
		lista_copii.push_back(p);
	}
}

void afisare(list<Copil*> lista_copii) //functie afisare lista
{
	list<Copil*>::iterator i;
	for (i = lista_copii.begin(); i != lista_copii.end(); i++)
	{
		Copil* c = *i;
		cout << c->afisare() << endl;
	}
}

void cautare(list<Copil*>& lista_copii, string joc_preferat) //functie cautare in functie de jocul preferat
{
	auto i = lista_copii.begin();
	while (i != lista_copii.end())
	{
		Copil* c = *i;
		i++;

		if (c->joc_preferat.compare(joc_preferat) == 0)
		{
			cout << c->afisare() << endl;
		}
	}
}

int main()
{
		int opt1;
		list<Copil*>lista_copii;
		string nume, scoala, joc_preferat;
		int varsta, clasa;

		Copil* c = new Copil;

		while (1) //MENIU
		{
			cout << "\n1.Adaugare ordonata copil";
			cout << "\n2.Afisare copii";
			cout << "\n3.Cautare dupa joc preferat";
			cout << "\n0.Iesire";
			cout << "\nOptiunea dorita: ";
			cin >> opt1;
			switch (opt1) 
			{
			case 1:cout << "Introduceti numele copilului: ";
				cin >> nume;
				cout << "Introduceti varsta copilului: ";
				cin >> varsta;
				cout << "Introduceti scoala la care merge copilul: ";
				cin >> scoala;
				cout << "Introduceti in ce clasa se afla copilul: ";
				cin >> clasa;
				cout << "Introduceti jocul preferat al copilului: ";
				cin >> joc_preferat;
				adaugare_ordonata(lista_copii, nume, varsta, scoala, clasa, joc_preferat);
				break;
			case 2:afisare(lista_copii);
				break;
			case 3:
				cout << "Introduceti jocul preferat cautat: ";
				cin >> joc_preferat;
				cautare(lista_copii, joc_preferat);
				break;
			case 0:exit(0);
			default:cout << "Optiune invalida!";
			}
		}

	system("pause");
	return 0;
}