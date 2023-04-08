#include <iostream>
#include <list>
#include <iterator>
#include<sstream>
using namespace std;

class LCD;
class LED;

class Monitor{
private:
	string producator;
	int diagonala, pret;
public:
	Monitor() {};
	Monitor(string producator,int diagonala,int pret)
	{
		this->producator = producator;
		this->diagonala = diagonala;
		this->pret = pret;
	}
	friend class LCD;
	friend class LED;
	friend void stergere(list<LCD*>&, string producator);
	friend void stergere(list<LED*>&, string producator);
	friend void cautare(list<LCD*>&, string producator);
	friend void cautare(list<LED*>&, string producator);
	friend void sort(list<LCD*>&);
	friend void sort(list<LED*>&);
};

class LCD :public Monitor{
private:
	int timp_raspuns;
public:
	LCD() {};
	LCD(string producator, int diagonala, int pret, int timp_raspuns):Monitor(producator,diagonala,pret) {
		this->timp_raspuns = timp_raspuns;
	}
	string afisare_LCD()
	{
	return "Producator: " + this->producator + ", Diagonala: " + to_string(this->diagonala) + ", Pret: " + to_string(this->pret)+ ",Timp de raspuns: " + to_string(this->timp_raspuns);
	}
};

class LED :public Monitor {
private:
	string format_ecran, boxe_integrate;
public:
	LED() {};
	LED(string producator, int diagonala, int pret, string format_ecran, string boxe_integrate) :Monitor(producator, diagonala, pret)
	{
		this->format_ecran = format_ecran;
		this->boxe_integrate = boxe_integrate;
	}
	string afisare_LED()
	{
		return "Producator: " + this->producator + ", Diagonala: " + to_string(this->diagonala) + ", Pret: " + to_string(this->pret) + ", Format ecran: " + this->format_ecran + ", Boxe integrate: " + this->boxe_integrate;
	}
};

void afisare1(list<LCD*> monitoare_LCD)
{
	list<LCD*>::iterator i;
	for (i = monitoare_LCD.begin(); i != monitoare_LCD.end(); i++)
	{
		LCD* c = *i;
		cout << c->afisare_LCD() << endl;
	}
}

void afisare2(list<LED*> monitoare_LED)
{
	list<LED*>::iterator i;
	for (i = monitoare_LED.begin(); i != monitoare_LED.end(); i++)
	{
		LED* c = *i;
		cout << c->afisare_LED() << endl;
	}
}

void stergere(list<LED*>& monitoare_LED, string producator)
{
	auto i = monitoare_LED.begin();
	while (i != monitoare_LED.end())
	{
		LED* c = *i; 
		i++; 

		if (c->producator.compare(producator) == 0)
		{
			monitoare_LED.remove(c); 
		}
	}
}

void stergere(list<LCD*>& monitoare_LCD, string producator)
{
	auto i = monitoare_LCD.begin();
	while (i != monitoare_LCD.end())
	{
		LCD* c = *i;
		i++;

		if (c->producator.compare(producator) == 0)
		{
			monitoare_LCD.remove(c); 
		}
	}
}

void cautare(list<LCD*>& monitoare_LCD, string producator)
{
	auto i = monitoare_LCD.begin();
	while (i != monitoare_LCD.end())
	{
		LCD* c = *i;
		i++;

		if (c->producator.compare(producator) == 0)
		{
			cout << c->afisare_LCD() << endl;
		}
	}
}

void cautare(list<LED*>& monitoare_LED, string producator)
{
	auto i = monitoare_LED.begin();
	while (i != monitoare_LED.end())
	{
		LED* c = *i;
		i++;

		if (c->producator.compare(producator) == 0)
		{
			cout << c->afisare_LED() << endl;
		}
	}
}

void sort(list<LCD*>& monitoare_LCD)
{
	monitoare_LCD.sort([](const LCD* a, const LCD* b) { return a->producator < b->producator; });
}

void sort(list<LED*>& monitoare_LED)
{
	monitoare_LED.sort([](const LED* a, const LED* b) { return a->producator < b->producator; });
}

int main()
{
	string producator,format_ecran,boxe_integrate;
	int diagonala, pret, timp_raspuns,opt1,opt2;
	list<LCD*> monitoare_LCD;
	list<LED*> monitoare_LED;
	
	while (1)
	{
		cout << "\n1.Adaugare monitor";
		cout << "\n2.Afisare monitoare";
		cout << "\n3.Stergere monitor";
		cout << "\n4.Cautare monitor";
		cout << "\n5.Ordonare monitoare";
		cout << "\n0.Iesire";
		cout << "\nOptiunea dorita: ";
		cin >> opt1;
		switch (opt1)
		{
		case 1:cout << "\nIntroduceti tipul monitorului pe care doriti sa il introduceti: ";
			cout << "\n1.LCD";
			cout << "\n2.LED";
			cout << "\nOptiunea dorita: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << "Introduceti producatorul: ";
				cin >> producator;
				cout << "Introduceti diagonala: ";
				cin >> diagonala;
				cout << "Introduceti pretul: ";
				cin >> pret;
				cout << "Introduceti timpul de raspuns: ";
				cin >> timp_raspuns;
				LCD* m = new LCD(producator, diagonala, pret, timp_raspuns);
				monitoare_LCD.push_back(m);
			}
			else if (opt2 == 2)
			{
				cout << "Introduceti producatorul: ";
				cin >> producator;
				cout << "Introduceti diagonala: ";
				cin >> diagonala;
				cout << "Introduceti pretul: ";
				cin >> pret;
				cout << "Introduceti formatul ecranului: ";
				cin >> format_ecran;
				cout << "Introduceti daca exista sau nu boxe integrate: ";
				cin >> boxe_integrate;
				LED* m2 = new LED(producator, diagonala, pret, format_ecran, boxe_integrate);
				monitoare_LED.push_back(m2);
			}
			else
				cout << "Optiune Invalida";
			break;
		case 2:
			cout << "\nIntroduceti tipul monitorului pe care il doriti afisat: ";
			cout << "\n1.LCD";
			cout << "\n2.LED";
			cout << "\nOptiunea dorita: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				afisare1(monitoare_LCD);
			}
			else if (opt2 == 2)
			{
				afisare2(monitoare_LED);
			}
			else
				cout << "\nOptiune invalida!";
			break;
		case 3:
			cout << "\nIntroduceti tipul monitorului pe care il doriti afisat: ";
			cout << "\n1.LCD";
			cout << "\n2.LED";
			cout << "\nOptiunea dorita: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << "Introduceti producatorul monitorului LCD pe care il doriti sters: ";
				cin >> producator;
				stergere(monitoare_LCD, producator);
			}
			else if (opt2 == 2)
			{
				cout << "Introduceti producatorul monitorului LED pe care il doriti sters: ";
				cin >> producator;
				stergere(monitoare_LED, producator);
			}
			else
				cout << "Optiune invalida!";
			break;
		case 4:
			cout << "\nIntroduceti tipul de monitor pe care il doriti afisat: ";
			cout << "\n1.LCD";
			cout << "\n2.LED";
			cout << "\nOptiunea dorita: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << "\nIntroduceti numele producatorului pentru a cauta monitorul: ";
				cin >> producator;
				cautare(monitoare_LCD, producator);
			}
			else if (opt2 == 2)
			{
				cout << "\nIntroduceti numele producatorului pentru a cauta monitorul: ";
				cin >> producator;
				cautare(monitoare_LED, producator);
			}
			else
				cout << "Optiune invalida!";
			break;
		case 5:
			cout << "\nIntroduceti tipul de monitor pe care il doriti afisat: ";
			cout << "\n1.LCD";
			cout << "\n2.LED";
			cout << "\nOptiunea dorita: ";
			cin >> opt2;
			if (opt2 == 1)
			{
				sort(monitoare_LCD);
			}
			else if (opt2 == 2)
			{
				sort(monitoare_LED);
			}
			else
				cout << "Optiune invalida!";
			break;
		case 0:exit(0);
		default:cout << "Optiunea invalida!";
			break;
		}
	}

	system("pause");
	return 0;
}