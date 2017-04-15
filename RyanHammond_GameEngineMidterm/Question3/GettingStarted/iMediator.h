#ifndef _iMediator_HG_
#define _iMediator_HG_

#include "externals.h"
#include <string>

class iMediator
{
public:
	virtual ~iMediator() {};


	virtual glm::mat4 FindFood(int ID) = 0;
	virtual glm::mat4 FindFood(int ID, int pref1, int pref2) = 0;
	virtual glm::mat4 FindFood(int ID, int pref1, int pref2, int pref3) = 0;
	//virtual void setAnimals(std::vector<iAnimal*> animals) = 0;
	//virtual void setPlants(std::vector<iPlant*> plants) = 0;

	//virtual bool EatFood() = 0;
};

#endif