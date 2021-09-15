//
//  CastleClass.cpp
//  Riddler Sim
//
//  Created by John West on 9/14/20.
//

#include "CastleClass.hpp"

Castle::Castle (int a_points, int b_soldiers) {
	points = a_points;
	soldiers = b_soldiers;
}

int Castle::Get_Soldiers() {
	return soldiers;
}

int Castle::Get_Points() {
	return points;
}
