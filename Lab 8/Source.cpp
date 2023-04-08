#include<iostream>
#include<list>
#include<iterator>
#include<sstream>
#include<fstream>
using namespace std;

class Articole { //clasa de Baza
protected:
	string producator, denumire;
	int pret;
	
public:
	int tip_articol;
	Articole(string producator, string denumire,int pret,int tip_articol)
	{
		this->producator = producator;
		this->denumire = denumire;
		this->pret = pret;
		this->tip_articol = tip_articol;
	}
	virtual void afisare()
	{
		cout << "Producator: " << this->producator << ", Denumire: " << this->denumire << ", Pret: " + this->pret;
	}
	friend void citire_fisier_ordonata(list<Articole*>& lista_articole);
	friend void salvare_fisier(list<Articole*>& lista_articole);
	friend istream& operator >> (istream& intrare, Articole*& art);
};


class Creion:public Articole { //clasa derivata Creion
private:
	string tip_mina;
public:
	Creion(string producator, string denumire,int pret,int tip_articol, string tip_mina) :Articole(producator, denumire,pret,tip_articol)
	{
		this->tip_mina = tip_mina;
	}
	void afisare()
	{
		cout << "Producator: " << this->producator << ", Denumire: " << this->denumire << ", Pret: " << this->pret << ", Tip mina: " << this->tip_mina << endl;
	}
	friend void cautare(list<Articole*>lista_articole);
	friend void salvare_fisier(list<Articole*>& lista_articole);
};


class Paste { //clasa Paste pentru a crea lista de culori si durata de viata a pixurilor
protected:
	string culoare;
	int durata_de_viata;
public:
	Paste() {};
	Paste(string culoare, int durata_de_viata)
	{
		this->culoare = culoare;
		this->durata_de_viata = durata_de_viata;
	}
	void afisare_lista_paste()
	{
		cout<< ", Culoarea: " << this->culoare << ", Durata de viata: " << this->durata_de_viata<<endl;
	}
	friend string returnCuloare(list<Paste*> lista_paste);
	friend int returnDurata(list<Paste*> lista_paste);
	
};

void afisare_listaPaste(list<Paste*> lista_paste) //functie afisare lista paste
{
	list<Paste*>::iterator i;
		i = lista_paste.begin();
		Paste* p = *i;
		p->afisare_lista_paste();
}

string returnCuloare(list<Paste*> lista_paste)
{
	list<Paste*>::iterator i;
		i = lista_paste.begin();
		Paste* p = *i;
		return p->culoare;
}

int returnDurata(list<Paste*> lista_paste)
{
	list<Paste*>::iterator i;
		i = lista_paste.begin();
		Paste *p = *i;
		return p->durata_de_viata;
}

class Pix : public Articole{ //clasa derivata Pix
private:
	list <Paste*>lista_paste; //crearea lista paste
public:
	Pix(string producator, string denumire,int pret,int tip_articol, string culoare,int durata_de_viata) :Articole(producator, denumire,pret,tip_articol)
	{
		Paste *p=new Paste(culoare, durata_de_viata);
		lista_paste.push_back(p);
	}
	void afisare()
	{
		cout<< "Producator: " << this->producator << ", Denumire: " << this->denumire << ", Pret: " << this->pret;
		afisare_listaPaste(lista_paste);
	}
	
	string rCuloare() //returneaza Culoarea din lista
	{
		return returnCuloare(lista_paste);
	}
	int rDurata() //returneaza Durata din lista
	{
		return returnDurata(lista_paste);
	}
	friend void salvare_fisier(list<Articole*>& lista_articole);
	friend void stergere(list<Articole*>& lista_articole);
};

class MyException
{
public:
	string str_what;
	int what;

	MyException(string message, int e)
	{
		str_what = message + "\n";
		what = e;
	}
};


istream& operator >> (istream& intrare, Articole*&art)  //supraincarcare operator >>
{
	string producator, denumire, tip_mina, culoare;
	int tip_articol, pret=0, durata_de_viata,opt;
	cout << "Introduceti producatorul articolului: ";
	cin>> producator;
	cout << "Introduceti denumirea articolului: ";
	intrare >> denumire;
	try
	{
		cout << "Introduceti pretul articolului: "; cin >> pret;
		while (cin.fail() || cin.peek() != '\n')
		{
			cout << "Ati introdus litere in pret!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Pret: "; cin >> pret;
		}
		if (pret < 0)
		{
			throw MyException("Pretul nu poate avea valoare negativa!", pret);
		}
	}

	catch (MyException ex)
	{
		cout << ex.str_what;

		do
		{
			cout << "Reintroduceti pretul (valoare pozitiva):\n";
			cout << "Pret: "; cin >> pret;
			while (cin.fail() || cin.peek() != '\n')
			{
				cout << "Ati introdus litere in pret!\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Pret: "; cin >> pret;
			}
		} while (pret < 0);
	}

	try
	{
		cout << "\nAlegeti tipul de articol pe care doriti sa il introduceti:" << "\n1.Creion" << "\n2.Pix" << "\nOptiunea dorita: "; cin >> opt;
		while (cin.fail() || cin.peek() != '\n')
		{
			cout << "Ati introdus litere in optiune!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Optiunea dorita: "; cin >> opt;
		}
		if (opt != 1 && opt != 2)
		{
			throw MyException("Nu exista optiunea dorita!", opt);
		}
	}
		catch(MyException ex)
		{
			cout << ex.str_what;

			do
			{
				cout << "Reintroduceti optiunea (1.Creion / 2.Pix):\n";
				cout << "Optiunea dorita: "; cin >> opt;
				while (cin.fail() || cin.peek() != '\n')
				{
					cout << "Ati introdus litere in optiune!\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Optiunea dorita: "; cin >> opt;
				}
			} while (opt!=1 && opt!=2);
		}
		if (opt == 1)
		{
			cout << "Introduceti tipul minei: ";
			cin >> tip_mina;
			Creion* c = new Creion(producator, denumire, pret, 0, tip_mina);
			art = c;
		}
		else if (opt == 2)
		{
			cout << "Introduceti culoarea pastei: ";
			cin >> culoare;
			cout << "Introduceti durata de viata a pastei: ";
			cin >> durata_de_viata;
			Pix* p = new Pix(producator, denumire, pret, 1, culoare, durata_de_viata);
			art = p;
		}
	return intrare;	
}

void citire_fisier_ordonata(list<Articole*>& lista_articole) //functie citire din fisier
{
	//citire articole existente
	string producator, denumire, tip_mina, culoare;
	int tip_articol, pret, durata_de_viata;
	int opt;
	Articole* art = NULL;
	cout << "\nOptiuni: " << "\n1.Citire din Fisier" << "\n2.Adaugare obiect de tip creion/pix" << "\n Optiunea dorita: ";
	cin >> opt;
	if (opt == 1)
	{
		ifstream f("articole.txt");
		while (f >> producator >> denumire >> pret >> tip_articol) //citire din fisier si crearea obiecte tip Creion sau Pix
		{
			if (tip_articol == 0)
			{
				f >> tip_mina;
				Creion* c = new Creion(producator, denumire, pret, tip_articol, tip_mina);
				art = c;
			}
			else if (tip_articol == 1)
			{
				f >> culoare >> durata_de_viata;
				Pix* p = new Pix(producator, denumire, pret, tip_articol, culoare, durata_de_viata);
				art = p;
			}

			if (lista_articole.size() > 0) //implementare adaugare ordonata
			{
				auto i = lista_articole.begin();
				if (art->producator.compare((*i)->producator) < 0)
				{
					lista_articole.push_front(art);
				}
				else
				{
					auto urm = next(i, 1);
					while (urm != lista_articole.end() && (*urm)->producator.compare(art->producator) < 0)
					{
						i++;
						urm = next(i, 1);
					}
					lista_articole.insert(urm, art);
				}
			}
			else
			{
				lista_articole.push_back(art);
			}
		}
		f.close();
	}
	else if (opt == 2) //adaugare articole noi
	{
		cin >> art;

		if (lista_articole.size() > 0) //implementare adaugare ordonata
		{
			auto i = lista_articole.begin();
			if (art->producator.compare((*i)->producator) < 0)
			{
				lista_articole.push_front(art);
			}
			else
			{
				auto urm = next(i, 1);
				while (urm != lista_articole.end() && (*urm)->producator.compare(art->producator) < 0)
				{
					i++;
					urm = next(i, 1);
				}
				lista_articole.insert(urm, art);
			}
		}
		else
		{
			lista_articole.push_back(art);
		}
	}
}


ostream& operator << (ostream& iesire, Articole *art)  //supraincarcare operator <<
{
	art->afisare();
	return iesire;
}

void afisare_creioane(list<Articole*> lista_articole) //functie afisare obiecte tip creion
{
	list<Articole*>::iterator i;
	for (i = lista_articole.begin(); i != lista_articole.end(); i++)
	{
		
		Articole *art = *i;
		if (art->tip_articol == 0)
			cout << art;
	}
}

void afisare_pixuri(list<Articole*> lista_articole) //functie afisare obiecte tip pix
{
	list<Articole*>::iterator i;
	for (i = lista_articole.begin(); i != lista_articole.end(); i++)
	{
		Articole* art = *i;
		if (art->tip_articol == 1)
			cout << art;
	}
}


void salvare_fisier(list<Articole*>& lista_articole) //functie salvare in fisier
{
	ofstream f("articole_out.txt");
	list<Articole*>::iterator i;
	for(i = lista_articole.begin(); i != lista_articole.end(); i++)
	{
		Articole* art = *i;
		f <<"Producator: "<< art->producator<< ", Denumire: " << art->denumire<<", Pret: "<<art->pret;
			if (art->tip_articol == 0)
				{
				Creion *c=(Creion*)art;
				f <<", Tip mina :" << c->tip_mina<<endl;
				}
			else
			{
				Pix* p = (Pix*)art;
				
				f <<", Culoare:"<< p->rCuloare()<<", Durata de viata: " << p->rDurata()<<endl;
			}
	}
}

void cautare(list<Articole*> lista_articole) //functie cautare in functie de tipul minei
{
	string tip_mina;
	cout << "Introduceti tipul minei cautate: ";
	cin >> tip_mina;
	auto i = lista_articole.begin();
	while (i != lista_articole.end())
	{
		Articole* art = *i;
		Creion* c;
		c = (Creion*)art;
		i++;

		if (c->tip_mina.compare(tip_mina) == 0)
		{
			cout << c;
		}
	}
}

void stergere(list<Articole*>& lista_articole) //functie stergere pix in functie de culoarea pastei
{
	string culoare;
	cout << "Introduceti culoarea pastei pentru pixul pe care doriti sa il stergeti: ";
	cin >> culoare;

	auto i = lista_articole.begin();
	while (i != lista_articole.end())
	{
		Articole* art = *i;
		i++;
		if (art->tip_articol == 1)
		{
			Pix* p;
			p = (Pix*)art;
			if (p->rCuloare().compare(culoare) == 0)
			{
				lista_articole.remove(p);
			}
		}
	}
}


int main()
{
	list<Articole*>lista_articole;
	string tip_mina;
	int opt;
	while (1)
	{
		cout << "\n1.Adaugare articole (creion sau pix) in lista, ordonat, din fisier.";
		cout << "\n2.Afisare creioane pe ecran.";
		cout << "\n3.Afisare pixuri pe ecran.";
		cout << "\n4.Salvarea listei in fisier.";
		cout << "\n5.Cautare creion dupa tip mina";
		cout << "\n6.Stergere pasta dupa culoare pentru un pix dat de la tastatura";
		cout << "\n0.Iesire";
		cout << "\nOptiunea dorita: ";
		cin >> opt;
		switch (opt)
		{
		case 1:	citire_fisier_ordonata(lista_articole);
			break;
		case 2: afisare_creioane(lista_articole);
			break;
		case 3:afisare_pixuri(lista_articole);
			break;
		case 4:salvare_fisier(lista_articole);
			break;
		case 5:cautare(lista_articole);
			break;
		case 6:stergere(lista_articole);
			break;
		case 0:exit(0);
		default:cout << "\nOptiune invalida!";
			break;
		}
	}

	system("pause");
	return 0;
}