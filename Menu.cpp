#include<iostream>
#include<iomanip>

#include"Menu.h"
#include"People.h"
#include"Start.h"


void Menu::Run()
{
	Player Player1;
	Supervisor Visor1;


	std::cout << std::setw(30) << "Welcome to Squid Game!" << std::endl;
	std::string Option;
	while (1)
	{
		Menu:
		ShowMenu();
		std::cout << "Chose an option\n";
		std::cin >> Option;
		try 
		{
			throw Option;
		}
		catch (std::string Option)
		{
			if (Option == "1")
			{
				std::cout << "Let the game start\n";

				Start start1;

				start1.GamePreparation();
				std::cout << "       First Game\n        Red Light Green light\n";
				std::cout << "Au ramas in competitie:\n";
				start1.RedLightGreenLight();

				std::cout << "Next Game?(y/n)\n";
				std::string YN;
				std::cin >> YN;
				if (YN == "y")
					start1.TugOfWar();

			}
			else if (Option == "2")
			{
				int last = Player1.LastPlayer();
				if (last < 99)
				{
					std::cout << "Let's add a player\n";
					Player1.SavePlayer(last); 
					goto Menu;
				}
				else
				{
					std::cout << "The maximum numbers of players has been reached!\n";
					goto Menu;
				}
			}
			else if (Option == "3")
			{
				int last = Visor1.LastVisor();
				if (last < 9)
				{
					std::cout << "Let's add a supervisor\n";
					Visor1.SaveVisor(last);
					goto Menu;
				}
				else
				{
					std::cout << "The maximum numbers of supervisors has been reached!\n";
					goto Menu;
				}
			}
			else if (Option == "4")
				exit(0);
			else
			{
				std::cout << "Wrong input!\n";
				goto Menu;
			}
			
		}
		catch (...)
		{
			std::cout << "Wrong input!\n";
			goto Menu;
		}
	}


}

void Menu::ShowMenu()
{
	std::cout << "1.Start Game" << std::endl;
	std::cout << "2.Add Player" << std::endl;
	std::cout << "3.Add Supervisor" << std::endl;
	std::cout << "4.Exit" << std::endl;
}
