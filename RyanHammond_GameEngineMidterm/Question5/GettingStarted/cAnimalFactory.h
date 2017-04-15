#ifndef _cAnimalFactory_HG_
#define _cAnimalFactory_HG_

// ONLY include the INTERFACE
// +++NEVER+++ the implementation (cpp) file
#include "iAnimal.h"	

#include <string>

class cAnimalFactory
{
public:
	// Returns a pointer to the INTERFACE type
	// Take some well known type (like int, string)
	iAnimal* CreateAnimal(std::string typeOfEnemy);

};

#endif