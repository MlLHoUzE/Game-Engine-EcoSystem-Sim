#include "cAnimalFactory.h"

// HERE you include the SPECFIC classes
// ONLY here, NEVER in the .h file
#include "cBunny.h"

#include "cFox.h"   //Factory step 2
#include "cTiger.h"
#include "cUnicorn.h"

// Returns a pointer to the INTERFACE type
// Take some well known type (like int, string)
iAnimal* cAnimalFactory::CreateAnimal(std::string typeOfEnemy)
{
	iAnimal* pAnimalToReturn = 0;	// Or NULL or nullprt

	if (typeOfEnemy == "Bunny")
	{
		pAnimalToReturn = new cBunny();
	}
	else if (typeOfEnemy == "Fox")
	{
		pAnimalToReturn = new cFox();	//Factory step 3
	}
	else if (typeOfEnemy == "Tiger")
	{
		pAnimalToReturn = new cTiger();
	}
	else if (typeOfEnemy == "Unicorn")
	{
		pAnimalToReturn = new cUnicorn();
	}

	return pAnimalToReturn;
}
