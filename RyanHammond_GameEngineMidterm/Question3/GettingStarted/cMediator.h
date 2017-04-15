#include "iMediator.h"
#include <vector>
#include "iPlant.h"
#include "iAnimal.h"

class cMediator : public iMediator
{
public:
	virtual glm::mat4 FindFood(int ID);
	virtual glm::mat4 FindFood(int ID, int pref1, int pref2);
	virtual glm::mat4 FindFood(int ID, int pref1, int pref2, int pref3);
	//virtual void setAnimals(std::vector<iAnimal*> animals);
	//virtual void setPlants(std::vector<iPlant*> plants);

private:
	//std::vector<iPlant*> m_vec_pPlants;
	//std::vector<iAnimal*> m_vec_pAnimals;

	iPlant* m_pFindPlantByID(int ID);
	iAnimal* m_pFindAnimalByID(int ID);
};