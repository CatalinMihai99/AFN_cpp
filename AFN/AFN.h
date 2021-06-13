#pragma once
#include <tuple>
#include<vector>
#include<iostream>
#include<string>
#include<fstream>


class AFN
{



	
	private:
		std::vector<std::string> Stari;
		//std::string Sigma;
		std::vector<char> Sigma;
		std::string Stare_initiala;
		std::vector<std::tuple<std::string, char, std::vector<std::string>>> Delta;
		std::vector<std::string> Final;

	 public:
		 void verificare(std::string cuvant,int nr_element_tuple3);
		 void citire_fisier();
		friend std::ostream& operator<<(std::ostream& afisare, AFN& afd);

	


};

