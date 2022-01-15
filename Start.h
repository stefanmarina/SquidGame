#ifndef _Start_
#define _Start_

#include<vector>
#include<string>

class Start 
{
private:
	std::vector<std::string> Competitor;
	std::vector<std::string> Guard;
	

public:
	Start();
	~Start();

	void read(std::vector<std::string> &v, const std::string f);
	std::vector<std::string> GetData(std::vector<std::string>& v,int i);
	int TotalDebt();
	void GamePreparation();

	void ShowPlayers();

	void RedLightGreenLight();

	void TugOfWar();
	int ComputeWeight(std::vector<std::string>& v);

	void Marbles();

	void Genken();
	int *GetNumber(std::vector<std::string>& v);
};



#endif // !_Start_

