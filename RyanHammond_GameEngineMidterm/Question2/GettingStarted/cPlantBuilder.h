#ifndef _cPlantBuilder_HG_
#define _cPlantBuilder_HG_

#include <string>
#include "iPlant.h"

class cPlantBuilder
{
public:
	~cPlantBuilder();

	static cPlantBuilder* getInstance(void);

	static void shutDown(void);

	iPlant* createPlant(std::string type);

private:
	cPlantBuilder();

	static cPlantBuilder* mPTheOneBuilder;
};

#endif
