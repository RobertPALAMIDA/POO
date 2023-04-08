#include<iostream>
#include<list>
#include<iterator>
#include<sstream>
using namespace std;

class Carti_Tehnice; //instantiere clasa derivata
class Carti_Literatura; //instantiere clasa derivata

class Carti { //clasa de baza
private:
	string autor, titlu, imprumutat;
	int tip;
public:
	Carti() {};
	Carti(string autor, string titlu, string imprumutat,int tip) {
		this->autor = autor;
		this->titlu = titlu;
		this->imprumutat = imprumutat;
		this->tip = tip;
	}
	friend void adaugare_ordonata(list<Carti*>& lista_carti); //functie adaugare ordonata
	friend class Carti_Tehnice; 
	friend class Carti_Literatura;
	friend void afisare_lista(list<Carti*> lista_carti); //functie afisare
	friend void afisare_last_ct(list<Carti*> lista_carti);
};

class Carti_Tehnice : public Carti { //clasa derivata
private:
	string limba;
	int an_apartie;
public:
	Carti_Tehnice() {};
	Carti_Tehnice(string autor, string titlu, string imprumutat,int tip, string limba, int an_apartie) :Carti(autor, titlu, imprumutat,tip)
	{
		this->limba = limba;
		this->an_apartie = an_apartie;
	}
	string afisare1()
	{
		return "Autor: " + this->autor + ",Titlu: " + this->titlu + ", Imprumutat: " + this->imprumutat + ", Limba: " + this->limba + ", An aparitie: " + to_string(this->an_apartie);
	}
	friend void afisare_lista(list<Carti*> lista_carti);
	friend void afisare_last_ct(list<Carti*> lista_carti);
};

class Carti_Literatura :public Carti {
private:
	int nr_pag;
public:
	Carti_Literatura() {};
	Carti_Literatura(string autor, string titlu, string imprumutat, int tip, int nr_pag) :Carti(autor, titlu, imprumutat, tip)
	{
		this->nr_pag = nr_pag;
	}
	string afisare2()
	{
		return "Autor: " + this->autor + ",Titlu: " + this->titlu + ", Imprumutat: " + this->imprumutat + ", Numar de pagini: " + to_string(this->nr_pag);
	}
	friend void afisare_lista(list<Carti*> lista_carti);
};

void adaugare_ordonata(list<Carti*>& lista_carti)
{
	Carti* c;
	int opt, an_aparitie=0,nr_pag;
	string autor, titlu,limba,imprumutat;
	cout << "\n1.Carte Tehnica \n2.Carte de literatura \n Optiunea dorita: ";
	cin >> opt;
	if (opt == 1)
	{
		cout << "Introduceti autorul cartii: ";
		cin >> autor;
		cout << "Introduceti titlul cartii: ";
		cin >> titlu;
		cout << "Introduceti daca cartea este imprumutata sau nu: ";
		cin >> imprumutat;
		cout << "Introduceti limba in care este scrisa cartea: ";
		cin >> limba;
		cout << "Introduceti anul aparitiei: ";
		cin >> an_aparitie;
		auto ct = new Carti_Tehnice(autor, titlu,imprumutat, 1, limba, an_aparitie);
		c = ct;
		if (lista_carti.size() > 0)
		{
			auto i = lista_carti.begin();
			if (c->autor.compare((*i)->autor) < 0)
			{
				lista_carti.push_front(c);
			}
			else
			{
				auto urm = next(i, 1);
				while (urm != lista_carti.end() && (*urm)->autor.compare(c->autor) < 0)
				{
					i++;
					urm = next(i, 1);
				}
				lista_carti.insert(urm, c);
			}
		}
		else
		{
			lista_carti.push_back(c);
		}
	}
		else if (opt == 2)
	{
		cout << "Introduceti autorul cartii: ";
		cin >> autor;
		cout << "Introduceti titlul cartii: ";
		cin >> titlu;
		cout << "Introduceti daca cartea este imprumutata sau nu: ";
		cin >> imprumutat;
		cout << "Numarul de pagini: ";
		cin >> nr_pag;
		auto cl = new Carti_Literatura(autor, titlu, imprumutat,2, nr_pag);
		c = cl;
		if (lista_carti.size() > 0)
		{
			auto i = lista_carti.begin();
			if (c->autor.compare((*i)->autor) < 0)
			{
				lista_carti.push_front(c);
			}
			else
			{
				auto urm = next(i, 1);
				while (urm != lista_carti.end() && (*urm)->autor.compare(c->autor) < 0)
				{
					i++;
					urm = next(i, 1);
				}
				lista_carti.insert(urm, c);
			}
		}
		else
		{
			lista_carti.push_back(c);
		}
	}
}


void afisare_lista(list<Carti*> lista_carti) //functie afisare lista
{
	list<Carti*>::iterator i;
	for (i = lista_carti.begin(); i != lista_carti.end(); i++)
	{
		Carti* c = *i;
		if (c->tip == 1)
		{
			
			Carti_Tehnice* ct;
			ct = (Carti_Tehnice*)c;
			cout << ct->afisare1() << endl;
		}
		else
		{
			Carti_Literatura* cl;
			cl = (Carti_Literatura*)c;
			cout << cl->afisare2() << endl;
		}
	}
}

/*void afisare_last_ct(list<Carti*> lista_carti) //functie afisare ultima carte tehnica
{
	list<Carti*>::iterator i;
	int ok = 1;
	do
	for (auto i = lista_carti.end(); i != lista_carti.begin(); i--)
	{
		Carti* c = *i;
		if (c->tip == 1)
		{

			Carti_Tehnice* ct;
			ct = (Carti_Tehnice*)c;
			cout << ct->afisare1() << endl;
			ok = 0;
		}
	
	}while (ok == 1);
}*/

int main()
{
	int opt;
	list<Carti*>lista_carti;
	while (1) //MENIU
	{
		cout << "\n1.Adaugare ordonata carte";
		cout << "\n2.Afisare carti";
		//cout << "\n3.Afisare cea mai recenta carte tehnica introdusa";
		cout << "\n0.Iesire";
		cout << "\nOptiunea dorita: ";
		cin >> opt;
		switch (opt)
		{
		case 1:adaugare_ordonata(lista_carti);
			break;
		case 2:afisare_lista(lista_carti);
			break;
		//case 3:afisare_last_ct(lista_carti);
		//	break;
		case 0:exit(0);
		default:cout << "Optiune invalida!";
		}
	}

	system("pause");
	return 0;
}