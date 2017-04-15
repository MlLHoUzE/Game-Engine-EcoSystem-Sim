#ifndef _cAnimalBuilder_HG_
#define _cAnimalBuilder_HG_

#include <string>
#include "iAnimal.h"

class cAnimalBuilder
{
public:
	~cAnimalBuilder();

	static cAnimalBuilder* getInstance(void);

	static void shutDown(void);

	iAnimal* createAnimal(std::string type);

private:
	cAnimalBuilder();

	static cAnimalBuilder* mPTheOneBuilder;
};

#endif
