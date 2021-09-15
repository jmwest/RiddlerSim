//
//  PlayerClass.cpp
//  Riddler Sim
//
//  Created by John West on 9/14/20.
//

#include "PlayerClass.hpp"
#include <iostream>

Player::Player () {
	castle_arr = vector<Castle> (13, Castle(0,0));
	
	for (int i = 0; i < 13; ++i) {
		castle_arr[i] = Castle(i+1, 0);
	}
	
	wins = 0;
	losses = 0;
	ties = 0;
}

Player::Player (int init_array[13]) {
	castle_arr = vector<Castle> (13, Castle(0,0));
	
	for (int i = 0; i < 13; ++i) {
		castle_arr[i] = Castle(i+1, init_array[i]);
	}
	
	wins = 0;
	losses = 0;
	ties = 0;
}

Castle* Player::Get_Castle(const int &num) {
	return &castle_arr[num];
}

void Player::Set_wins(int num) {
	wins = num;
	return;
}

void Player::Set_losses(int num) {
	losses = num;
	return;
}

void Player::Set_ties(int num) {
	ties = num;
	return;
}

void Player::Incr_wins() {
	++wins;
	return;
}

void Player::Incr_losses() {
	++losses;
	return;
}

void Player::Incr_ties() {
	++ties;
	return;
}

int Player::Get_wins() {
	return wins;
}

int Player::Get_losses() {
	return losses;
}

int Player::Get_ties() {
	return ties;
}

float Player::Get_win_percentage() {
	return wins + (ties / 2);
}

void Player::Print_Player() {
	std::cout << "\nCastles:";
	std::cout << "\n1: " << castle_arr[0].Get_Soldiers();
	std::cout << "\n2: " << castle_arr[1].Get_Soldiers();
	std::cout << "\n3: " << castle_arr[2].Get_Soldiers();
	std::cout << "\n4: " << castle_arr[3].Get_Soldiers();
	std::cout << "\n5: " << castle_arr[4].Get_Soldiers();
	std::cout << "\n6: " << castle_arr[5].Get_Soldiers();
	std::cout << "\n7: " << castle_arr[6].Get_Soldiers();
	std::cout << "\n8: " << castle_arr[7].Get_Soldiers();
	std::cout << "\n9: " << castle_arr[8].Get_Soldiers();
	std::cout << "\n10: " << castle_arr[9].Get_Soldiers();
	std::cout << "\n11: " << castle_arr[10].Get_Soldiers();
	std::cout << "\n12: " << castle_arr[11].Get_Soldiers();
	std::cout << "\n13: " << castle_arr[12].Get_Soldiers();
	std::cout << "\n\nW/L/T: " << wins << "/" << losses << "/" << ties;
	std::cout << "\n\nWin Percent: " << Get_win_percentage();
	std::cout << "\nCongratulations, Big Chungus!\n\n";
	
	return;
}
