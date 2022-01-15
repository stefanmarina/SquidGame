#include<string>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<array>
#include<time.h>
#include<stdlib.h>


#include"Start.h"
#include"People.h"



Start::Start()
{
	read(Competitor, "Player.txt");
	read(Guard, "Visor.txt");

}

Start::~Start()
{
	this->Competitor.clear();
	this->Guard.clear();

}

void Start::read(std::vector<std::string>& v, const std::string f) 
{
	std::ifstream file;
	file.open(f);
	std::string line;
	while (getline(file, line)) {
		v.push_back(line);
	}
	file.close();

	
}

std::vector<std::string> Start::GetData(std::vector<std::string>& v, int i)
{

	
	std::string Data = v[i];

	std::string p;

	std::vector<std::string> Competitor1;
	auto j = Data.size();
	i = 0;
	while (Data[i] != ';')
	{
		p.push_back(Data[i]);
		i++;
	}
	Competitor1.insert(Competitor1.end(), p);
	i++;
	p.clear();
		
	while (Data[i] != ';')
	{
		p.push_back(Data[i]);
		i++;
	}
	Competitor1.insert(Competitor1.end(), p);
	i++;
	p.clear();

	while (Data[i] != ';')
	{
		p.push_back(Data[i]);
		i++;
	}
	Competitor1.insert(Competitor1.end(), p);
	i++;
	p.clear();

	while (Data[i] != ';')
	{
		p.push_back(Data[i]);
		i++;
	}
	Competitor1.insert(Competitor1.end(), p);
	i++;
	p.clear();

	while (Data[i] != ';')
	{
		p.push_back(Data[i]);
		i++;
	}
	Competitor1.insert(Competitor1.end(), p);
	i++;
	p.clear();
		
	while (i <= j)
	{
		p.push_back(Data[i]);
		i++;
	}
	Competitor1.insert(Competitor1.end(), p);
	


		return Competitor1;
}


void Start::ShowPlayers()
{
	for (int i = 0; i < Competitor.size(); i++)
		std::cout << Competitor[i] << std::endl;
}




int Start::TotalDebt()
{

	int Total = 0;

	std::vector<std::string> One;
	for (int i = 0; i < Competitor.size(); i++)
	{
		One = GetData(Competitor, i);
		Total += stoi(One[3]);
	}

	return Total;
}

void Start::GamePreparation()
{
	int Total_Debt = TotalDebt();
	
}

void Start::RedLightGreenLight()
{
	int i = 1;
	for (auto it = Competitor.begin(); it < Competitor.end(); ++it)
		if (i % 2 == 0)
		{
			Competitor.erase(it);
			i++;
		}
		else i++;
	ShowPlayers();
}

void Start::TugOfWar()
{
	std::vector<std::string> Team1, Team2, Team3, Team4;

	std::random_shuffle(Competitor.begin(), Competitor.end());
	int i = 0;

	std::cout << Competitor.size();
	while (4 < Competitor.size())
	{
		Team1.insert(Team1.end(),Competitor[1]);
		Competitor.erase(Competitor.begin());
		Team1.insert(Team2.end(), Competitor[1]);
		Competitor.erase(Competitor.begin());
		Team1.insert(Team3.end(), Competitor[1]);
		Competitor.erase(Competitor.begin());
		Team1.insert(Team4.end(), Competitor[1]);
		Competitor.erase(Competitor.begin());
	

	}

	int W1 = ComputeWeight(Team1);
	int W2 = ComputeWeight(Team2);
	int W3 = ComputeWeight(Team3);
	int W4 = ComputeWeight(Team4);

	std::array<int, 4> foo { W1,W2,W3,W4 };

	std::random_shuffle(foo.begin(), foo.end());
	int R1, R2, RR;
	if (foo[0] > foo[1])
		R1 = foo[0];
	else
		R1 = foo[1];

	if (foo[2] > foo[3])
		R2 = foo[2];
	else
		R2 = foo[3];


	if (R1 > R2)
		RR = R1;
	else
		RR = R2;
	int j = Competitor.size();

	if (RR == W1)
	{
		std::cout << "Echipa 1 a castigat!";
		for (i = 0; i < Team1.size(); i++)
			Competitor[j + i] = Team1[i];
	}
	else if (RR == W2)
	{
		std::cout << "Echipa 2 a castigat!";
		for (i = 0; i < Team2.size(); i++)
			Competitor[j + i] = Team2[i];
	}
	else if (RR == W3)
	{
		std::cout << "Echipa 3 a castigat!";
		for (i = 0; i < Team3.size(); i++)
			Competitor[j + i] = Team3[i];
	}
	else if (RR == W4)
	{
		std::cout << "Echipa 4 a castigat!";
		for (i = 0; i < Team4.size(); i++)
			Competitor[j + i] = Team4[i];
	}

	ShowPlayers();
}

int Start::ComputeWeight(std::vector<std::string>& v)
{
	int W = 0;
	std::vector<std::string> One;
	for (int i = 0; i < v.size(); i++)
	{
		One = GetData(Competitor, i);
		W += stoi(One[4]);
	}

	return W;


}

void Start::Marbles()
{
	std::random_shuffle(Competitor.begin(), Competitor.end());

	int size;
	if (Competitor.size() % 2 != 0)
		size = Competitor.size() - 1;
	else
		size = Competitor.size();

	std::vector<std::string> Team1, Team2;

	for (int i = 0; i < size; i++)
	{
		if (i <= size / 2)
		{
			Team1.insert(Team1.end(), Competitor[1]);
			Competitor.erase(Competitor.begin());
		}
		else
		{
			Team2.insert(Team2.end(), Competitor[1]);
			Competitor.erase(Competitor.begin());
		}
	}
	int v1, v2;
	auto b1 = Team1.begin();
	auto b2 = Team2.begin();
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		TryAgain:
		v1 = rand() % 50 + 1;
		v2 = rand() % 50 + 1;
		if (v1 > v2)
		{
			Team1.erase(b1);
			b2++;
		}
		else if (v1 < v2)
		{
			Team2.erase(b2);
			b1++;
		}
		else
			goto TryAgain;
	}

	for (int i = 0; i < Team1.size(); i++)
		Competitor[Competitor.size() + i] = Team1[i];
	for (int i = 0; i < Team2.size(); i++)
		Competitor[Competitor.size() + i] = Team2[i];

	ShowPlayers();
}

int Start::*GetNumber(std::vector<std::string>& v)
{
	std::vector<std::string> Competitor1;

	int z[30];

	for (int i = 0; i < v.size(); i++)
	{
		Competitor1 = GetData(v, i);
		z[i] = stoi(Competitor1[5]);
	}
	int n = sizeof(z) / sizeof(z[0]);
	for (int k = 0; k < n - 1; k++)
		for (int m = k + 1; k < n; k++)
			if (z[k] > z[m])
			{
				auto aux = z[k];
				z[k] = z[m];
				z[m] = aux;
			}
	return z;
}

void Start::Genken()
{

}
