#include "AFN.h"
#include<fstream>
void switchstari(std::string stare_curenta, char litera, std::string tuple_elem_first,std::string tuple_elem_third,char cuv)
{
	if (tuple_elem_first == stare_curenta && litera == cuv)
	{
		stare_curenta = tuple_elem_third;
		
	}
}

void AFN::verificare(std::string cuvant,int nr_elemen_tuple3)
{
	std::string stare_curenta = Stare_initiala;
	for (int index = 0; index < cuvant.size(); index++)
	{
		if (stare_curenta == "$")
		{
			std::cout << "Blocaj";
			return;
		}

		for (const auto& index2 : Delta)
		{
			std::string tuple1 = std::get<0>(index2);
			char tuple2 = std::get<1>(index2);
			std::vector<std::string> tuple3= std::get<2>(index2);
			if (tuple1 == stare_curenta && tuple2 == cuvant[index])
			{
				stare_curenta = tuple3[nr_elemen_tuple3];
			}
		}
	}
	for (int index = 0; index < Final.size(); index++)
	{
		if (stare_curenta == Final[index])
		{
			std::cout << "DA";
			return;
		}
	}
	if (stare_curenta == "$")
	{
		std::cout << "Blocaj";
		return;
	}
	std::cout << "NU";
}

void AFN::citire_fisier()
{
	std::ifstream f("Text.txt");
	int nr_stari;
	f >> nr_stari;
	for (int index = 0; index < nr_stari; index++)
	{
		std::string stare_aux;
		f >> stare_aux;
		Stari.push_back(stare_aux);
	}


	f.get();
	char aux;
	do
	{
		f >> aux;
		if (aux != ' ')
			Sigma.push_back(aux);

	} while (f.peek() != '\n');
	f.get();
	
	f >> Stare_initiala;
	int nr_stari_finale;
	f >> nr_stari_finale;
	for (int index = 0; index < nr_stari_finale; index++)
	{
		std::string finala_aux;
		f >> finala_aux;
		Final.push_back(finala_aux);
	}
	int nr_tranzitii;
	f >> nr_tranzitii;
	for (int index = 0; index < nr_tranzitii; index++)
	{
		std::string elem1;
		char elem2;
		std::vector<std::string> elem3;
		f >> elem1 >> elem2;
		do
		{
			std::string auxiliar;
			f >> auxiliar;
			elem3.push_back(auxiliar);

		} while (f.peek() != '\n');
		f.get();
		Delta.push_back({ elem1,elem2,elem3 });
	}
}
std::ostream& operator<<(std::ostream& afisare, AFN& afn)
{
	afisare << "STARI :" << "     ";
	for (int index = 0; index < afn.Stari.size(); index++)
	{
		afisare << afn.Stari[index] << " ";
	}
	afisare << std::endl;
	afisare << "SIGMA:   ";
	for (int index = 0; index < afn.Sigma.size(); index++)
	{
		afisare << afn.Sigma[index] << " ";
	}
	afisare << std::endl;
	afisare << "Stare initiala: " << afn.Stare_initiala << std::endl;
	afisare << "STARI FINALE: ";
	for (int index = 0; index < afn.Final.size(); index++)
		afisare << afn.Final[index];
	afisare << std::endl;
	afisare << "TRANZITII: " << std::endl;
	for (const auto& index : afn.Delta)
	{
		afisare << std::get<0>(index) << " ";
		afisare << std::get<1>(index) << " ";
		for (int index2 = 0; index2 < std::get<2>(index).size(); index2++)
			afisare << std::get<2>(index)[index2] << " ";
		std::cout  << std::endl;

	}
	return afisare;
}

