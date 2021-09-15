//
//  main.cpp
//  RiddlerSim3
//
//  Created by John West on 9/25/20.
//  Copyright © 2020 John West. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include "CastleClass.hpp"
#include "PlayerClass.hpp"

using namespace std;

int CastleCompare (Castle *x, Castle *y);
int PlayerConquest (Player &x, Player &y);
void Battle (vector<Player> &players);
void FindTopPlayers (vector<Player> &winners, vector<Player> &players, const int num);
bool PlayerCompare(Player x, Player y);

int main() {
	
	int player_counter = 0;
	int start[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int null_start[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	vector<Player> players (100000, start);
	vector<Player> winners;
	
	bool first_loop = false;
	bool not_all_loops = true;
	
	create:
	for (int one = start[0]; one < 3; ++one) {
		for (int two = start[1]; two < 5; ++two) {
			for (int three = start[2]; three < 7; ++three) {
				for (int four = start[3]; four < 9; ++four) {
					for (int five = start[4]; five < 11; ++five) {
						for (int six = start[5]; six < 13; ++six) {
							for (int seven = start[6]; seven < 15; ++seven) {
								for (int eight = start[7]; eight < 17; ++eight) {
									for (int nine = start[8]; nine < 19; ++nine) {
										for (int ten = start[9]; ten < 21; ++ten) {
											for (int eleven = start[10]; eleven < 23; ++eleven) {
												for (int twelve = start[11]; twelve < 25; ++twelve) {
													for (int thirteen = start[12]; thirteen < 31; ++thirteen) {
														
														if (one + two + three + four + five + six + seven
															+ eight + nine + ten + eleven + twelve +
															thirteen == 100) {
															
															int arr[13] = {one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen};
															players.at(player_counter) = Player(arr);
															++player_counter;
															
															if (first_loop) {
																first_loop = false;
																for (int i = 0; i < 13; ++i) {
																	start[i] = 0;
																}
															}
															
															if (player_counter == 100000) {
																player_counter = 0;
																first_loop = true;
																start[0] = one;
																start[1] = two;
																start[2] = three;
																start[3] = four;
																start[4] = five;
																start[5] = six;
																start[6] = seven;
																start[7] = eight;
																start[8] = nine;
																start[9] = ten;
																start[10] = eleven;
																start[11] = twelve;
																start[12] = thirteen;
																
																goto play;
															}
														}
														
														if (one + two + three + four + five + six + seven
														+ eight + nine + ten + eleven + twelve + thirteen == 186) {
															not_all_loops = false;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	play:
	Battle(players);
	
	tally:
	FindTopPlayers(winners, players, 10);
	
	players = vector<Player> (100000, null_start);
	
	if (not_all_loops) {
		goto create;
	}
	
	finalround:
	Battle(winners);
	
	vector<Player> BigChungus;
	FindTopPlayers(BigChungus, winners, 1);
	
	BigChungus.at(0).Print_Player();
	
return 0;
}

int CastleCompare (Castle *x, Castle *y) {
	
	if (x->Get_Soldiers() > y->Get_Soldiers()) {
		return 1;
	}
	else if (x->Get_Soldiers() < y->Get_Soldiers()) {
		return 0;
	}
	else {
		return 2;
	}
}

int PlayerConquest (Player &x, Player &y) {
	
	int x_points = 0;
	int x_halfp = 0;
	int y_points = 0;
	int y_halfp = 0;
	
	int res = 0;
	int points = 0;
	
	for (int i = 12; i >= 0; --i) {
		res = CastleCompare(x.Get_Castle(i), y.Get_Castle(i) );
		points = x.Get_Castle(i)->Get_Points();
		
		if (res == 1) {
			x_points = x_points + points;
		}
		else if (res == 0) {
			y_points = y_points + points;
		}
		else {
			if (points % 2 == 1) {
				x_points = x_points + (points / 2);
				y_points = y_points + (points / 2);
				
				if (x_halfp > 0) {
					x_halfp = 0;
					x_points = x_points + 1;
				}
				else {
					x_halfp = 1;
				}
				
				if (y_halfp > 0) {
					y_halfp = 0;
					y_points = y_points + 1;
				}
				else {
					y_halfp = 1;
				}
			}
			else {
				x_points = x_points + (points / 2);
				y_points = y_points + (points / 2);
			}
		}
		
		if ( (x_points > 45) or (y_points > 45) ) {
			break;
		}
	}
	
	if (x_points > y_points) {
		return 1;
	}
	else if (x_points < y_points) {
		return 0;
	}
	else {
		if (x_halfp > y_halfp) {
			return 1;
		}
		else if (x_halfp < y_halfp) {
			return 0;
		}
		else {
			return 2;
		}
	}
}

void Battle (vector<Player> &players) {
	
	int result = 0;
	
	vector<Player>::iterator it1 = players.begin();
	vector<Player>::iterator it2;
	
	for (; it1 != players.end(); ++it1) {
		it2 = it1;
		++it2;
		
		for (; it2 != players.end(); ++it2) {
			result = PlayerConquest(*it1, *it2);
			
			if (result == 1) {
				it1->Incr_wins();
				it2->Incr_losses();
			}
			else if (result == 0) {
				it1->Incr_losses();
				it2->Incr_wins();
			}
			else {
				it1->Incr_ties();
				it2->Incr_ties();
			}
		}
	}
	
	return;
}

void FindTopPlayers (vector<Player> &winners, vector<Player> &players, const int num) {
	
	sort(players.begin(), players.end(), PlayerCompare);
	
	for (vector<Player>::reverse_iterator rit = players.rbegin(); rit != players.rbegin() + num; ++rit) {
		winners.push_back(*rit);
	}
	
	return;
}

bool PlayerCompare(Player x, Player y) {
	return x.Get_win_percentage() < y.Get_win_percentage();
}
