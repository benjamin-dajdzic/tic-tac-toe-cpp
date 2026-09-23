#include <iostream>
#include <iomanip>
using namespace std;
const int  redova = 3;
const int  kolona = 3;

class XO {
	char niz[redova][kolona];
	int igracNaPotezu;
	bool krajIgre;

	void OcistiMatricu() {
		for (size_t i = 0; i < redova; i++)
			for (size_t j = 0; j < kolona; j++)
				niz[i][j] = ' ';
}
	void GetKoordinateIzLokacije(int lokacija, int& r, int& k) {
		
		switch (lokacija)
		{
		case 1: r = 0, k = 0; break;
		case 2: r = 0, k = 1; break;
		case 3: r = 0, k = 2; break;
		case 4: r = 1, k = 0; break;
		case 5: r = 1, k = 1; break;
		case 6: r = 1, k = 2; break;
		case 7: r = 2, k = 0; break;
		case 8: r = 2, k = 1; break;
		case 9: r = 2, k = 2; break;
		}
	}
	char GetNaredniZnak() {
		char znak = (igracNaPotezu % 2 == 0) ? 'X' : 'O';
		igracNaPotezu++;
		return znak;
	}
	bool ProvjeriRedove() {
		char znak;
		int brojac;
		for (size_t i = 0; i < redova; i++)
		{
			brojac = 0;
			znak = niz[i][0];
			if (znak != ' ') {
				for (size_t j = 0; j < kolona; j++)
					if (znak == niz[i][j])
						brojac++;
				if (brojac == 3)
					return true;
			}
		}
		return false;
	}
	bool ProvjeriKolone() {
		char znak;
		int brojac;
		for (size_t j = 0; j < kolona; j++)
		{
			brojac = 0;
			znak = niz[0][j];
			if (znak != ' ') {
				for (size_t i = 0; i < redova; i++)
				{
					if (znak == niz[i][j])
						brojac++;
					if (brojac == 3)
						return true;
				}	
			}
		}
		return false;
	}
	bool ProvjeriLDijagonala() {
		char znak = niz[0][0];
		int brojac = 0;
		if (znak == ' ')
			return false;
		for (size_t i = 0; i < redova; i++)
		{
			
			for (size_t j = 0; j < kolona; j++)
				{
					if (i == j && znak == niz[i][j])
						brojac++;
				}
		}
		return brojac == 3;	
	}

	bool ProvjeriDDijagonala() {
		char znak = niz[0][2];
		int brojac = 0;
		if (znak == ' ')
			return false;
		for (size_t i = 0; i < redova; i++)
		{

			for (size_t j = 0; j < kolona; j++)
			{
				if (i + j == redova - 1 && znak == niz[i][j])
					brojac++;
			}
		}
		return brojac == 3;
	}





public:
	XO()
	{
		igracNaPotezu = 1;
		krajIgre = false;
		OcistiMatricu();
	}
	void Prikazi() {
		for (size_t i = 0; i < redova; i++)
		{
			for (size_t j = 0; j < kolona; j++)
				cout << "+---";
			cout << "+" << endl;
			for (size_t j = 0; j < kolona; j++)
				cout << "|" << setw(3) << niz[i][j];
			cout << "|" << endl;
		}
		for (size_t j = 0; j < kolona; j++)
			cout << "+---";
		cout << "+" << endl;
	}
	void Igraj(int lokacija) {
		if (krajIgre)
		{
			cout << "KRAJ IGRE" << endl;
			return;
		}

		int r = 0, k = 0;
		GetKoordinateIzLokacije(lokacija, r, k);
		if (niz[r][k] == ' ') {
			niz[r][k] = GetNaredniZnak();
			if (ProvjeriRedove() || ProvjeriKolone() || ProvjeriLDijagonala() || ProvjeriDDijagonala()) {
				krajIgre = true;
				cout << "KRAJ IGRE" << endl;
			}
		}
		else
			cout << "LOKACIJA ZAUZETA" << endl;
	}
};

void main() {
	XO xo;
	int lokacija;
	do {
		xo.Prikazi();
		cout << "Lokacija -> ";
		cin >> lokacija;
		system("cls");
		xo.Igraj(lokacija);
	} while (1);
}