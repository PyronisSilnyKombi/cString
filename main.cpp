#include "cString_header.h"


using namespace std;
int main()
{
	//cNapis n("ala ma kota"), tekst(n);
	//cout << n << endl;
	//cout << tekst << endl;
	//cin >> tekst;

	//cNapis tekst_polaczany = n + tekst;
	//cout << n << endl;
	//cout << tekst << endl;
	//cout << tekst_polaczany << endl;

	vector<cNapis> napisy;
	std::fstream plik("Polish.dic.txt", ios::in);
	if (plik.is_open()) {
		cNapis liczba;
		plik >> liczba;
		while (!plik.eof()) {
			
			cNapis tmp;
			plik >> tmp;
			tmp.tolower();
			napisy.push_back(tmp);
		}
	}

	for (int i = 0; i < 1000; i++)
	{
		cout << napisy[i] << endl;
	}

	//for (auto& el : napisy) {
	//	cout << el<< endl;
	//}



	system("pause");
	return 0;
}

/*3. Napisa� funkcj� find_if, wykorzystuj�cej klas� predykatu, kt�ra zawiera dane o zbiorze liter.
algorytm uzywaj�c klasy predykatu powinien znale�� wszystkie wyrazy kt�re mo�na u�o�y� na podstawie danej kombinacji.
*/
//cPredykat pred("atrim");

//auto itr = napisy.begin();

//while (itr != napisy.end()) {

//	itr = find_if(itr, napisy.end(), pred);

//	if (itr != napisy.end()) {

//		std::cout << *itr << std::endl;

//		itr++;

//	}

//}
