#ifndef _People_
#define _People_

#include<iostream>


class People
{
protected:
	std::string LastName;
	std::string FirstName;
	std::string City;
	int Debt;
	float Weight;
public:
//	void SavePlayer();
	

};

class Player : public People
{
protected:
	int CompetitionNumber;
public:
	void SavePlayer(int last);
	int LastPlayer();
};

class Supervisor : public People
{
protected:
	std::string Masc;
public:
	void SaveVisor(int last);
	int LastVisor(); 
};

#endif // !_People_