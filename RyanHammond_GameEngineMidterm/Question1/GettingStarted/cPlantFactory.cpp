#include "cPlantFactory.h"

// HERE you include the SPECFIC classes
// ONLY here, NEVER in the .h file
#include "cStrawberry.h"

#include "cPineapple.h"   //Factory step 2
#include "cWatermelon.h"

// Returns a pointer to the INTERFACE type
// Take some well known type (like int, string)
iPlant* cPlantFactory::CreatePlant(std::string typeOfEnemy)
{
	iPlant* pPlantToReturn = 0;	// Or NULL or nullprt

	if (typeOfEnemy == "Strawberry")
	{
		pPlantToReturn = new cStrawberry();
	}
	else if (typeOfEnemy == "Pineapple")
	{
		pPlantToReturn = new cPineapple();	//Factory step 3
	}
	else if (typeOfEnemy == "Watermelon")
	{
		pPlantToReturn = new cWatermelon();
	}

	return pPlantToReturn;
}
