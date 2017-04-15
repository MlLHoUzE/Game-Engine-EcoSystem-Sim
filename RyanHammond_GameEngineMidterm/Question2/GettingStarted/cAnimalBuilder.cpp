#include "cAnimalBuilder.h"
#include "cAnimalFactory.h"

cAnimalBuilder::~cAnimalBuilder()
{

}

cAnimalBuilder::cAnimalBuilder()
{
	return;
}

cAnimalBuilder* cAnimalBuilder::mPTheOneBuilder = 0;

cAnimalBuilder* cAnimalBuilder::getInstance(void)	//Singleton Step 1
{
	if (cAnimalBuilder::mPTheOneBuilder == 0)
	{
		cAnimalBuilder::mPTheOneBuilder = new cAnimalBuilder();
	}
	return cAnimalBuilder::mPTheOneBuilder;
}

void cAnimalBuilder::shutDown(void)
{
	// Do we have an instance?
	if (cAnimalBuilder::mPTheOneBuilder != 0)
	{	// Yes, so get rid of it
		delete cAnimalBuilder::mPTheOneBuilder;
	}
	return;
}

iAnimal* cAnimalBuilder::createAnimal(std::string type)
{
	iAnimal* pTheAnimal = 0;

	cAnimalFactory* pAnimalFactory = new cAnimalFactory();

	if (type == "Bunny")
	{
		pTheAnimal = pAnimalFactory->CreateAnimal("Bunny");

	}
	else if (type == "Fox")
	{
		pTheAnimal = pAnimalFactory->CreateAnimal("Fox");
	}
	else if (type == "Tiger")
	{
		pTheAnimal = pAnimalFactory->CreateAnimal("Tiger");
	}

	delete pAnimalFactory;

	return pTheAnimal;
}