#include "cPlantBuilder.h"
#include "cPlantFactory.h"

cPlantBuilder::~cPlantBuilder()
{

}

cPlantBuilder::cPlantBuilder()
{
	return;
}

cPlantBuilder* cPlantBuilder::mPTheOneBuilder = 0;

cPlantBuilder* cPlantBuilder::getInstance(void)	//Singleton Step 1
{
	if (cPlantBuilder::mPTheOneBuilder == 0)
	{
		cPlantBuilder::mPTheOneBuilder = new cPlantBuilder();
	}
	return cPlantBuilder::mPTheOneBuilder;
}

void cPlantBuilder::shutDown(void)
{
	// Do we have an instance?
	if (cPlantBuilder::mPTheOneBuilder != 0)
	{	// Yes, so get rid of it
		delete cPlantBuilder::mPTheOneBuilder;
	}
	return;
}

iPlant* cPlantBuilder::createPlant(std::string type)
{
	iPlant* pThePlant = 0;

	cPlantFactory* pPlantFactory = new cPlantFactory();

	if (type ==	"Strawberry")
	{
		pThePlant = pPlantFactory->CreatePlant("Strawberry");

	}
	else if (type == "Pineapple")
	{
		pThePlant = pPlantFactory->CreatePlant("Pineapple");
	}
	else if (type == "Watermelon")
	{
		pThePlant = pPlantFactory->CreatePlant("Watermelon");
	}

	delete pPlantFactory;

	return pThePlant;
}