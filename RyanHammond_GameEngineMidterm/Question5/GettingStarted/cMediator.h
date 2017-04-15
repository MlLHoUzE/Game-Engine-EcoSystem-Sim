#include "iMediator.h"
#include <vector>
#include "iPlant.h"
#include "iAnimal.h"
#include "cAnimalBuilder.h"

class cMediator : public iMediator
{
public:
	virtual glm::mat4 FindFood(int ID, int &targetID, int &targetType);
	virtual glm::mat4 FindFood(int ID, int pref1, int pref2, int &targetID, int &targetType);
	virtual glm::mat4 FindFood(int ID, int pref1, int pref2, int pref3, int &targetID, int &targetType);
	//virtual void setAnimals(std::vector<iAnimal*> animals);
	//virtual void setPlants(std::vector<iPlant*> plants);
	virtual float eat(int ID, int targetID, int targetType);
	virtual void spawnAnimal(int ID);


private:
	//std::vector<iPlant*> m_vec_pPlants;
	//std::vector<iAnimal*> m_vec_pAnimals;
	iPlant* m_pFindPlantByID(int ID);
	iAnimal* m_pFindAnimalByID(int ID);
	void deleteAnimal(int ID);
};