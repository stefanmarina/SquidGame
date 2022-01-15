#include"People.h"

#include <fstream>
#include<stdlib.h>
#include<sstream>
#include<string>


//void People::SavePlayer()
//{
//
//}

void Player::SavePlayer(int last)
{

	std::fstream file;
	file.open("Player.txt", std::ios::app);

	file.seekg(0, std::ios::end);
	if (file.tellg() != 0)
		file << std::endl;
	file.seekg(0, std::ios::beg);

	std::cout << "Give the last Name of the player: ";
	std::cin >> LastName;
	std::cout << std::endl;
	file << LastName << ";";

	std::cout << "Give the first Name of the player: ";
	std::cin >> FirstName;
	std::cout << std::endl;
	file << FirstName << ";";

	std::cout << "Give the city of residence: ";
	std::cin >> City;
	std::cout << std::endl;
	file << City << ";";

	
	
	///for automatic addition of players
	//for (int i = 0; i < 8; i++)
	//	file << static_cast<char>('A' - 1 + (rand() % 25 + 1));
	//file << ";";
	//for (int i = 0; i < 7; i++)
	//	file << static_cast<char>('a' - 1 + (rand() % 25 + 1));
	//file << ";";
	//for (int i = 0; i < 6; i++)
	//	file << static_cast<char>('A' - 1 + (rand() % 25 + 1));
	//file << ";";
	////Debt
	//file << rand() % 90000 + 10000 << ";";

	//Weight
	file << rand() % 50 + 50 << ";";

	file <<last + 1;

}

void Supervisor::SaveVisor(int last)
{
	std::fstream file;
	file.open("Visor.txt", std::ios::app);

	file.seekg(0, std::ios::end);
	if (file.tellg() != 0)
		file << std::endl;
	file.seekg(0, std::ios::beg);


	std::cout << "Give the last Name of the supervisor: ";
	std::cin >> LastName;
	std::cout << std::endl;
	file << LastName << ";";

	std::cout << "Give the first Name of the supervisor: ";
	std::cin >> FirstName;
	std::cout << std::endl;
	file << FirstName << ";";

	std::cout << "Give the city of residence: ";
	std::cin >> City;
	std::cout << std::endl;
	file << City << ";";

	///for automatic addition of Supervisors
	/*for (int i = 0; i < 8; i++)
		file << static_cast<char>('a' - 1 + (rand() % 25 + 1));
	file << ";";
	for (int i = 0; i < 7; i++)
		file << static_cast<char>('A' - 1 + (rand() % 25 + 1));
	file << ";";
	for (int i = 0; i < 6; i++)
		file << static_cast<char>('a' - 1 + (rand() % 25 + 1));
	file << ";";*/

	//Debt
	file << rand() % 90000 + 10000 << ";";

	//Weight
	file << rand() % 50 + 50 << ";";

	int p = rand() % 3 + 1;

	if (p == 1)
		file << "Rectangle" << ";";
	else if (p == 2)
		file << "Triangle" << ";";
	else if (p == 3)
		file << "Circle" << ";";

	file << last + 1;

	//file << rand() % 98 + 1;
}

int Player::LastPlayer()
{
	std::fstream file;
	file.open("Player.txt", std::ios::in);
	file.seekg(0, std::ios::end);

	if (file.tellg() == 0)
		return 0;
	std::string searchID;

 	for (int i = -1; searchID.find(";") == std::string::npos; i--)
	{
		file.seekg(i, std::ios::end);
		file >> searchID;
	}
	file.close();
	searchID.erase(0, 1);

	int ID;
	std::stringstream I(searchID);
	I >> ID;

	return ID;
}
int Supervisor::LastVisor()
{
	std::fstream file;
	file.open("Visor.txt", std::ios::in);
	file.seekg(0, std::ios::end);

	if (file.tellg() == 0)
		return 0;
	std::string searchID;

	for (int i = -1; searchID.find(";") == std::string::npos; i--)
	{
		file.seekg(i, std::ios::end);
		file >> searchID;
	}
	file.close();
	searchID.erase(0, 1);

	int ID;
	std::stringstream I(searchID);
	I >> ID;

	return ID;
}


