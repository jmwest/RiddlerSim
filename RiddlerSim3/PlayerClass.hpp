//
//  PlayerClass.hpp
//  Riddler Sim
//
//  Created by John West on 9/14/20.
//

#ifndef PlayerClass_hpp
#define PlayerClass_hpp

#include <stdio.h>
#include <vector>
#include "CastleClass.hpp"

using namespace std;

class Player {
	vector<Castle> castle_arr;
	int wins = 0;
	int losses = 0;
	int ties = 0;
	
public:
	Player ();
	Player (int init_array[13]);
	Castle* Get_Castle(const int &num);
	
	void Set_wins(int num);
	void Set_losses(int num);
	void Set_ties(int num);
	
	void Incr_wins();
	void Incr_losses();
	void Incr_ties();
	
	int Get_wins();
	int Get_losses();
	int Get_ties();
	
	float Get_win_percentage();
	
	void Print_Player();
};

#endif /* PlayerClass_hpp */
