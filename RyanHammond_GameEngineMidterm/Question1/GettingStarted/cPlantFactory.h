#ifndef _cPlantFactory_HG_
#define _cPlantFactory_HG_

// ONLY include the INTERFACE
// +++NEVER+++ the implementation (cpp) file
#include "iPlant.h"	

#include <string>

class cPlantFactory
{
public:
	// Returns a pointer to the INTERFACE type
	// Take some well known type (like int, string)
	iPlant* CreatePlant(std::string typeOfEnemy);

};

#endif