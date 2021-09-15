//
//  RiddlerTest.cpp
//  Riddler Sim
//
//  Created by John West on 9/14/20.
//

#include <stdio.h>
#include <iostream>
#include "CastleClass.hpp"
#include "PlayerClass.hpp"

using namespace std;

int main () {
	
	int player_counter = 0;
	int start[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

	bool first_loop = false;
	
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
															++player_counter;
															
															if (first_loop) {
																first_loop = false;
																for (int i = 0; i < 13; ++i) {
																	start[i] = 0;
																}
															}
															
															if (player_counter < 0) {
																--player_counter;
																cout << "\n\n" << player_counter;
																cout << "\none: " << one;
																cout << "\ntwo: " << two;
																cout << "\nthree: " << three;
																cout << "\nfour: " << four;
																cout << "\nfive: " << five;
																cout << "\nsix: " << six;
																cout << "\nseven: " << seven;
																cout << "\neight: " << eight;
																cout << "\nnine: " << nine;
																cout << "\nten: " << ten;
																cout << "\neleven: " << eleven;
																cout << "\ntwelve: " << twelve;
																cout << "\nthirteen: " << thirteen << "\n";
																goto stop;
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
	}
	stop:
	cout << "\n" << player_counter << "\n";
	
	return 0;
}
