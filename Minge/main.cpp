#include <iostream>
#include <algorithm>
#include <vector>
#include "Mingi.h"

int main()
{
	Mingi mingi("sport");
	mingi.addBall("nike");
	mingi.addBall("Adidas");

	Mingi mingi2("copii");
	mingi2.addBall("Miki");
	mingi2.addBall("Cruela");

	//copy constructor
	Mingi mingi3 = mingi2;
	mingi3.show();

	//assignment copy constructor
	mingi2 = mingi;
	mingi2.show();

	//std::move
	mingi = std::move(mingi3);
	mingi.show();
	mingi3.show();

	//vector
	std::vector<Mingi> vect {mingi, mingi2};

	//cautare dupa nume
	std::string nume = "nike";
	std::cout << " search for " << nume << std::endl;
	std::find_if(vect.begin(), vect.end(), [&, nume](Mingi& source) -> bool {
	
		for (auto ballName : source.ballList_)
			if (nume == ballName)
			{
				std::cout << nume << " found!" << std::endl;
				return true;
			}
			else return false;
	
	
	}), vect.end();


	//deletion
	nume = "sport";

	vect.erase(std::remove_if(vect.begin(), vect.end(), [nume](Mingi& source) -> bool { return source.getName() == nume; std::cout << nume << " deleted! " << std::endl; }), vect.end());
		
		

	std::cin.get();
}