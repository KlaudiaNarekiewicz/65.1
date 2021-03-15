#include <iostream>
#include <fstream>

using namespace std;

class ulamki
{
	ifstream plik;
	ofstream plik1;
	
	public:
		ulamki();
		~ulamki();
		void wczytaj();
};

ulamki::ulamki() 
{
	plik.open("dane_ulamki.txt");
	plik1.open("wynik1.txt");
}

void ulamki::wczytaj() 
{
 	double mian,licz;
 	double min, min_mian, min_licz;
	if(plik.good()) 
	{
		plik>>mian;
		plik>>licz;
	
		min = licz/mian;
		min_licz = licz;
		min_mian = mian;
		while(!plik.eof()) 
		{
			
			plik>>mian;	
			plik>>licz;
			if(licz/mian<min) 
			{
				min = licz/mian;
				min_licz = licz;
				min_mian= mian;
			}
			if(licz/mian==min) 
			{
				if(mian<=min_mian) 
				{
					min_licz = licz;
					min_mian = mian;
				}
			}
		}
		cout<<"Zad 65.1"<<min_licz<<" "<<min_mian;
		plik1<<"Zad 65.1"<<min_licz<<" "<<min_mian;
	}
}
	
ulamki::~ulamki() 
{
	plik.close();
	plik1.close();
}

int main(int argc, char** argv) 
{
	ulamki s;
	s.wczytaj();
	
	return 0;
}
