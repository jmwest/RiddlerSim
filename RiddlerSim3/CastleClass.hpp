//
//  CastleClass.hpp
//  Riddler Sim
//
//  Created by John West on 9/14/20.
//

#ifndef CastleClass_hpp
#define CastleClass_hpp

#include <stdio.h>

class Castle {
	int points, soldiers;
	
public:
	Castle (int, int);
	int Get_Soldiers();
	int Get_Points();
};

#endif /* CastleClass_hpp */
