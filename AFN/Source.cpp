#include<iostream>
#include"AFN.h"
#include<fstream>
int main()
{

	AFN afn;
	std::ifstream f("Text.txt");
	afn.citire_fisier();
	std::cout << afn;
	std::cout << std::endl;
	
	
	std::string decizie;

	std::cout << "Vreti sa cititi un cuvant?";
	std::cin >> decizie;
	while (decizie == "da")
	{


		std::string cuvant;
		std::cout << "Cititi un cuvant" << std::endl;
		std::cin >> cuvant;
		afn.verificare(cuvant, 0);
		std::cout << std::endl;
		std::cout << "Vreti sa cititi un cuvant?";
		std::cin >> decizie;
	}
	*/


	return 0;
}