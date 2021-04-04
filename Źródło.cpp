#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void createText(int tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		tab[i] = rand() % 9 + 0;
	}
}

void printText(int tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << tab[i];
	}
}

void algorytmKarpaRabina(int t[], int w[], int n, int m)
{
	int liczba_pierwsza = 101;
	int liczba_znakow_alfabetu = 10;
	int i, j;
	int pattern = 0; //hasz dla wzorca
	int text = 0; //hasz dla tekstu
	int h = 1;

	for (int i = 0; i < m - 1; i++)
		h = (h * liczba_znakow_alfabetu) % liczba_pierwsza;

	//obliczam hasz dla wzorca i dla okna
	for (i = 0; i < m; i++)
	{
		pattern = (liczba_znakow_alfabetu * pattern + w[i]) % liczba_pierwsza;
		text = (liczba_znakow_alfabetu * text + t[i]) % liczba_pierwsza;
	}

	//przesuwamy wzorzec po tekscie po kolei
	for (i = 0; i < n - m; i++)
	{
		//sprawdzamy czy hasz wzorca i tekstu sa takie same
		if (pattern == text)
		{
			for (j = 0; j < m; j++)
			{
				if (t[i + j] != w[j])
					break;
			}
			if (j == m)
			{
				cout << i << " ";
			}
		}
		//obliczanie haszu dla nastepnego okna
		if (i < n - m)
		{
			text = (liczba_znakow_alfabetu * (text - t[i] * h) + t[i + m]) % liczba_pierwsza;
			//mozemy otrzymac liczbe pozytywna lub negatywna
			if (text < 0)
				text = (text + liczba_pierwsza);
		}
	}
}

int main()
{
	//n-dlugosc tekstu
	//m-dlugosc wzorca

	srand(time(NULL));

	int n;
	n = 10;
	int* tekst = new int[n];
	createText(tekst, n);
	cout << "Tekst:" << endl;
	printText(tekst, n);
	cout << endl;

	int m = 3;
	int* wzorzec = new int[m];
	cout << "Podaj wzorzec skladajacy sie z 3 cyfr:" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> wzorzec[i];
	}

	cout << "Indeksy wszystkich wystapien wzorca w tekscie:" << endl;
	algorytmKarpaRabina(tekst, wzorzec, n, m);
	cout << endl;


	return 0;
}