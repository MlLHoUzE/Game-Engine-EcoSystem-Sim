#include "cMediator.h"
#include "global.h"

glm::mat4 cMediator::FindFood(int IDin)
{
	iAnimal* animal = m_pFindAnimalByID(IDin);

	glm::mat4 animalTrans;
	animal->GetTransform(animalTrans);
	glm::vec3 animalPos = glm::vec3(animalTrans[3].x, animalTrans[3].y, animalTrans[3].z);

	iPlant* closest = NULL;
	float closestDistance = 10000;
	float curDistance = 50000;
	//find closest food
	for (int index = 0; index != gPlants.size() ; index++)
	{
		
		if (gPlants[index]->checkForFruit())
		{
			glm::mat4 plantTrans;
			gPlants[index]->GetTransform(plantTrans);
			glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
			curDistance = glm::distance(animalPos, plantPos);
			if (curDistance < closestDistance)
			{
				closest = gPlants[index];
				closestDistance = curDistance;
			}
		}

	}

	if (closest != NULL)
	{
		glm::mat4 returnValue;
		closest->GetTransform(returnValue);

		return returnValue;
	}
	else
	{
		return glm::mat4(NULL);
	}
	
}

glm::mat4 cMediator::FindFood(int ID, int pref1, int pref2)
{
	iAnimal* animal = m_pFindAnimalByID(ID);

	glm::mat4 animalTrans;
	animal->GetTransform(animalTrans);

	glm::vec3 animalPos = glm::vec3(animalTrans[3].x, animalTrans[3].y, animalTrans[3].z);
	iPlant* closest = NULL;
	iAnimal* closestAnimal = NULL;

	float closestDistance = 10000;
	float curDistance = 50000;
	switch (pref1)
	{
	case gPreferences::STRAWBERRY:
		
		//find closest food
		for (int index = 0; index != gPlants.size(); index++)
		{
			if (gPlants[index]->getType() == pref1)
			{
				if (gPlants[index]->checkForFruit())
				{
					glm::mat4 plantTrans;
					gPlants[index]->GetTransform(plantTrans);
					glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
					curDistance = glm::distance(animalPos, plantPos);
					if (curDistance < closestDistance)
					{
						closest = gPlants[index];
						closestDistance = curDistance;
					}
				}
			}

		}
		break;
	case gPreferences::PINEAPPLE:
		//find closest food
		for (int index = 0; index != gPlants.size(); index++)
		{
			if (gPlants[index]->getType() == pref1)
			{
				if (gPlants[index]->checkForFruit())
				{
					glm::mat4 plantTrans;
					gPlants[index]->GetTransform(plantTrans);
					glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
					curDistance = glm::distance(animalPos, plantPos);
					if (curDistance < closestDistance)
					{
						closest = gPlants[index];
						closestDistance = curDistance;
					}
				}
			}

		}
		break;
	case gPreferences::WATERMELON:
		//find closest food
		for (int index = 0; index != gPlants.size(); index++)
		{
			if (gPlants[index]->getType() == pref1)
			{
				if (gPlants[index]->checkForFruit())
				{
					glm::mat4 plantTrans;
					gPlants[index]->GetTransform(plantTrans);
					glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
					curDistance = glm::distance(animalPos, plantPos);
					if (curDistance < closestDistance)
					{
						closest = gPlants[index];
						closestDistance = curDistance;
					}
				}
			}

		}
		break;
	case gPreferences::BUNNY:
		//find closest food
		for (int index = 0; index != gAnimals.size(); index++)
		{
			if (gAnimals[index]->GetType() == pref1)
			{
				glm::mat4 otherTrans;
				gAnimals[index]->GetTransform(otherTrans);
				glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
				curDistance = glm::distance(animalPos, otherPos);
				if (curDistance < closestDistance)
				{
					closestAnimal = gAnimals[index];
					closestDistance = curDistance;
				}
				
			}

		}
		break;
	case gPreferences::FOX:
		//find closest food
		for (int index = 0; index != gAnimals.size(); index++)
		{
			if (gAnimals[index]->GetType() == pref1)
			{
				glm::mat4 otherTrans;
				gAnimals[index]->GetTransform(otherTrans);
				glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
				curDistance = glm::distance(animalPos, otherPos);
				if (curDistance < closestDistance)
				{
					closestAnimal = gAnimals[index];
					closestDistance = curDistance;
				}

			}

		}
		break;
	case gPreferences::TIGER:
		//find closest food
		for (int index = 0; index != gAnimals.size(); index++)
		{
			if (gAnimals[index]->GetType() == pref1)
			{
				glm::mat4 otherTrans;
				gAnimals[index]->GetTransform(otherTrans);
				glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
				curDistance = glm::distance(animalPos, otherPos);
				if (curDistance < closestDistance)
				{
					closestAnimal = gAnimals[index];
					closestDistance = curDistance;
				}

			}

		}
		break;

	}

	if (closest == NULL && closestAnimal == NULL)	//no preference 1 available
	{
		switch (pref2)
		{
		case gPreferences::STRAWBERRY:

			//find closest food
			for (int index = 0; index != gPlants.size(); index++)
			{
				if (gPlants[index]->getType() == pref2)
				{
					if (gPlants[index]->checkForFruit())
					{
						glm::mat4 plantTrans;
						gPlants[index]->GetTransform(plantTrans);
						glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
						curDistance = glm::distance(animalPos, plantPos);
						if (curDistance < closestDistance)
						{
							closest = gPlants[index];
							closestDistance = curDistance;
						}
					}
				}

			}
			break;
		case gPreferences::PINEAPPLE:
			//find closest food
			for (int index = 0; index != gPlants.size(); index++)
			{
				if (gPlants[index]->getType() == pref2)
				{
					if (gPlants[index]->checkForFruit())
					{
						glm::mat4 plantTrans;
						gPlants[index]->GetTransform(plantTrans);
						glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
						curDistance = glm::distance(animalPos, plantPos);
						if (curDistance < closestDistance)
						{
							closest = gPlants[index];
							closestDistance = curDistance;
						}
					}
				}

			}
			break;
		case gPreferences::WATERMELON:
			//find closest food
			for (int index = 0; index != gPlants.size(); index++)
			{
				if (gPlants[index]->getType() == pref2)
				{
					if (gPlants[index]->checkForFruit())
					{
						glm::mat4 plantTrans;
						gPlants[index]->GetTransform(plantTrans);
						glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
						curDistance = glm::distance(animalPos, plantPos);
						if (curDistance < closestDistance)
						{
							closest = gPlants[index];
							closestDistance = curDistance;
						}
					}
				}

			}
			break;
		case gPreferences::BUNNY:
			//find closest food
			for (int index = 0; index != gAnimals.size(); index++)
			{
				if (gAnimals[index]->GetType() == pref2)
				{
					glm::mat4 otherTrans;
					gAnimals[index]->GetTransform(otherTrans);
					glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
					curDistance = glm::distance(animalPos, otherPos);
					if (curDistance < closestDistance)
					{
						closestAnimal = gAnimals[index];
						closestDistance = curDistance;
					}

				}

			}
			break;
		case gPreferences::FOX:
			//find closest food
			for (int index = 0; index != gAnimals.size(); index++)
			{
				if (gAnimals[index]->GetType() == pref2)
				{
					glm::mat4 otherTrans;
					gAnimals[index]->GetTransform(otherTrans);
					glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
					curDistance = glm::distance(animalPos, otherPos);
					if (curDistance < closestDistance)
					{
						closestAnimal = gAnimals[index];
						closestDistance = curDistance;
					}

				}

			}
			break;
		case gPreferences::TIGER:
			//find closest food
			for (int index = 0; index != gAnimals.size(); index++)
			{
				if (gAnimals[index]->GetType() == pref2)
				{
					glm::mat4 otherTrans;
					gAnimals[index]->GetTransform(otherTrans);
					glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
					curDistance = glm::distance(animalPos, otherPos);
					if (curDistance < closestDistance)
					{
						closestAnimal = gAnimals[index];
						closestDistance = curDistance;
					}

				}

			}
			break;

		}
	}
	if (closest != NULL)
	{
		glm::mat4 returnValue;
		closest->GetTransform(returnValue);

		return returnValue;
	}
	else if (closestAnimal != NULL)
	{
		glm::mat4 returnValue;
		closestAnimal->GetTransform(returnValue);

		return returnValue;
	}
	else
	{
		return glm::mat4(NULL);
	}


}

glm::mat4 cMediator::FindFood(int ID, int pref1, int pref2, int pref3)
{
	iAnimal* animal = m_pFindAnimalByID(ID);

	glm::mat4 animalTrans;
	animal->GetTransform(animalTrans);

	glm::vec3 animalPos = glm::vec3(animalTrans[3].x, animalTrans[3].y, animalTrans[3].z);
	iPlant* closest = NULL;
	iAnimal* closestAnimal = NULL;

	float closestDistance = 10000;
	float curDistance = 50000;
	switch (pref1)
	{
	case gPreferences::STRAWBERRY:

		//find closest food
		for (int index = 0; index != gPlants.size(); index++)
		{
			if (gPlants[index]->getType() == pref1)
			{
				if (gPlants[index]->checkForFruit())
				{
					glm::mat4 plantTrans;
					gPlants[index]->GetTransform(plantTrans);
					glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
					curDistance = glm::distance(animalPos, plantPos);
					if (curDistance < closestDistance)
					{
						closest = gPlants[index];
						closestDistance = curDistance;
					}
				}
			}

		}
		break;
	case gPreferences::PINEAPPLE:
		//find closest food
		for (int index = 0; index != gPlants.size(); index++)
		{
			if (gPlants[index]->getType() == pref1)
			{
				if (gPlants[index]->checkForFruit())
				{
					glm::mat4 plantTrans;
					gPlants[index]->GetTransform(plantTrans);
					glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
					curDistance = glm::distance(animalPos, plantPos);
					if (curDistance < closestDistance)
					{
						closest = gPlants[index];
						closestDistance = curDistance;
					}
				}
			}

		}
		break;
	case gPreferences::WATERMELON:
		//find closest food
		for (int index = 0; index != gPlants.size(); index++)
		{
			if (gPlants[index]->getType() == pref1)
			{
				if (gPlants[index]->checkForFruit())
				{
					glm::mat4 plantTrans;
					gPlants[index]->GetTransform(plantTrans);
					glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
					curDistance = glm::distance(animalPos, plantPos);
					if (curDistance < closestDistance)
					{
						closest = gPlants[index];
						closestDistance = curDistance;
					}
				}
			}

		}
		break;
	case gPreferences::BUNNY:
		//find closest food
		for (int index = 0; index != gAnimals.size(); index++)
		{
			if (gAnimals[index]->GetType() == pref1)
			{
				glm::mat4 otherTrans;
				gAnimals[index]->GetTransform(otherTrans);
				glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
				curDistance = glm::distance(animalPos, otherPos);
				if (curDistance < closestDistance)
				{
					closestAnimal = gAnimals[index];
					closestDistance = curDistance;
				}

			}

		}
		break;
	case gPreferences::FOX:
		//find closest food
		for (int index = 0; index != gAnimals.size(); index++)
		{
			if (gAnimals[index]->GetType() == pref1)
			{
				glm::mat4 otherTrans;
				gAnimals[index]->GetTransform(otherTrans);
				glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
				curDistance = glm::distance(animalPos, otherPos);
				if (curDistance < closestDistance)
				{
					closestAnimal = gAnimals[index];
					closestDistance = curDistance;
				}

			}

		}
		break;
	case gPreferences::TIGER:
		//find closest food
		for (int index = 0; index != gAnimals.size(); index++)
		{
			if (gAnimals[index]->GetType() == pref1)
			{
				glm::mat4 otherTrans;
				gAnimals[index]->GetTransform(otherTrans);
				glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
				curDistance = glm::distance(animalPos, otherPos);
				if (curDistance < closestDistance)
				{
					closestAnimal = gAnimals[index];
					closestDistance = curDistance;
				}

			}

		}
		break;

	}

	if (closest == NULL && closestAnimal == NULL)	//no preference 1 available
	{
		switch (pref2)
		{
		case gPreferences::STRAWBERRY:

			//find closest food
			for (int index = 0; index != gPlants.size(); index++)
			{
				if (gPlants[index]->getType() == pref2)
				{
					if (gPlants[index]->checkForFruit())
					{
						glm::mat4 plantTrans;
						gPlants[index]->GetTransform(plantTrans);
						glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
						curDistance = glm::distance(animalPos, plantPos);
						if (curDistance < closestDistance)
						{
							closest = gPlants[index];
							closestDistance = curDistance;
						}
					}
				}

			}
			break;
		case gPreferences::PINEAPPLE:
			//find closest food
			for (int index = 0; index != gPlants.size(); index++)
			{
				if (gPlants[index]->getType() == pref2)
				{
					if (gPlants[index]->checkForFruit())
					{
						glm::mat4 plantTrans;
						gPlants[index]->GetTransform(plantTrans);
						glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
						curDistance = glm::distance(animalPos, plantPos);
						if (curDistance < closestDistance)
						{
							closest = gPlants[index];
							closestDistance = curDistance;
						}
					}
				}

			}
			break;
		case gPreferences::WATERMELON:
			//find closest food
			for (int index = 0; index != gPlants.size(); index++)
			{
				if (gPlants[index]->getType() == pref2)
				{
					if (gPlants[index]->checkForFruit())
					{
						glm::mat4 plantTrans;
						gPlants[index]->GetTransform(plantTrans);
						glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
						curDistance = glm::distance(animalPos, plantPos);
						if (curDistance < closestDistance)
						{
							closest = gPlants[index];
							closestDistance = curDistance;
						}
					}
				}

			}
			break;
		case gPreferences::BUNNY:
			//find closest food
			for (int index = 0; index != gAnimals.size(); index++)
			{
				if (gAnimals[index]->GetType() == pref2)
				{
					glm::mat4 otherTrans;
					gAnimals[index]->GetTransform(otherTrans);
					glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
					curDistance = glm::distance(animalPos, otherPos);
					if (curDistance < closestDistance)
					{
						closestAnimal = gAnimals[index];
						closestDistance = curDistance;
					}

				}

			}
			break;
		case gPreferences::FOX:
			//find closest food
			for (int index = 0; index != gAnimals.size(); index++)
			{
				if (gAnimals[index]->GetType() == pref2)
				{
					glm::mat4 otherTrans;
					gAnimals[index]->GetTransform(otherTrans);
					glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
					curDistance = glm::distance(animalPos, otherPos);
					if (curDistance < closestDistance)
					{
						closestAnimal = gAnimals[index];
						closestDistance = curDistance;
					}

				}

			}
			break;
		case gPreferences::TIGER:
			//find closest food
			for (int index = 0; index != gAnimals.size(); index++)
			{
				if (gAnimals[index]->GetType() == pref2)
				{
					glm::mat4 otherTrans;
					gAnimals[index]->GetTransform(otherTrans);
					glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
					curDistance = glm::distance(animalPos, otherPos);
					if (curDistance < closestDistance)
					{
						closestAnimal = gAnimals[index];
						closestDistance = curDistance;
					}

				}

			}
			break;

		}
	}

	if (closest == NULL && closestAnimal == NULL)	//no preference 1 available
	{
		switch (pref3)
		{
		case gPreferences::STRAWBERRY:

			//find closest food
			for (int index = 0; index != gPlants.size(); index++)
			{
				if (gPlants[index]->getType() == pref3)
				{
					if (gPlants[index]->checkForFruit())
					{
						glm::mat4 plantTrans;
						gPlants[index]->GetTransform(plantTrans);
						glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
						curDistance = glm::distance(animalPos, plantPos);
						if (curDistance < closestDistance)
						{
							closest = gPlants[index];
							closestDistance = curDistance;
						}
					}
				}

			}
			break;
		case gPreferences::PINEAPPLE:
			//find closest food
			for (int index = 0; index != gPlants.size(); index++)
			{
				if (gPlants[index]->getType() == pref3)
				{
					if (gPlants[index]->checkForFruit())
					{
						glm::mat4 plantTrans;
						gPlants[index]->GetTransform(plantTrans);
						glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
						curDistance = glm::distance(animalPos, plantPos);
						if (curDistance < closestDistance)
						{
							closest = gPlants[index];
							closestDistance = curDistance;
						}
					}
				}

			}
			break;
		case gPreferences::WATERMELON:
			//find closest food
			for (int index = 0; index != gPlants.size(); index++)
			{
				if (gPlants[index]->getType() == pref3)
				{
					if (gPlants[index]->checkForFruit())
					{
						glm::mat4 plantTrans;
						gPlants[index]->GetTransform(plantTrans);
						glm::vec3 plantPos = glm::vec3(plantTrans[3].x, plantTrans[3].y, plantTrans[3].z);
						curDistance = glm::distance(animalPos, plantPos);
						if (curDistance < closestDistance)
						{
							closest = gPlants[index];
							closestDistance = curDistance;
						}
					}
				}

			}
			break;
		case gPreferences::BUNNY:
			//find closest food
			for (int index = 0; index != gAnimals.size(); index++)
			{
				if (gAnimals[index]->GetType() == pref3)
				{
					glm::mat4 otherTrans;
					gAnimals[index]->GetTransform(otherTrans);
					glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
					curDistance = glm::distance(animalPos, otherPos);
					if (curDistance < closestDistance)
					{
						closestAnimal = gAnimals[index];
						closestDistance = curDistance;
					}

				}

			}
			break;
		case gPreferences::FOX:
			//find closest food
			for (int index = 0; index != gAnimals.size(); index++)
			{
				if (gAnimals[index]->GetType() == pref3)
				{
					glm::mat4 otherTrans;
					gAnimals[index]->GetTransform(otherTrans);
					glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
					curDistance = glm::distance(animalPos, otherPos);
					if (curDistance < closestDistance)
					{
						closestAnimal = gAnimals[index];
						closestDistance = curDistance;
					}

				}

			}
			break;
		case gPreferences::TIGER:
			//find closest food
			for (int index = 0; index != gAnimals.size(); index++)
			{
				if (gAnimals[index]->GetType() == pref3)
				{
					glm::mat4 otherTrans;
					gAnimals[index]->GetTransform(otherTrans);
					glm::vec3 otherPos = glm::vec3(otherTrans[3].x, otherTrans[3].y, otherTrans[3].z);
					curDistance = glm::distance(animalPos, otherPos);
					if (curDistance < closestDistance)
					{
						closestAnimal = gAnimals[index];
						closestDistance = curDistance;
					}

				}

			}
			break;

		}
	}
	if (closest != NULL)
	{
		glm::mat4 returnValue;
		closest->GetTransform(returnValue);

		return returnValue;
	}
	else if (closestAnimal != NULL)
	{
		glm::mat4 returnValue;
		closestAnimal->GetTransform(returnValue);

		return returnValue;
	}
	else
	{
		return glm::mat4(NULL);
	}

}

iAnimal* cMediator::m_pFindAnimalByID(int ID)
{
	for (int index = 0; index != gAnimals.size(); index++)
	{
		if (ID == gAnimals[index]->GetID())
		{
			return gAnimals[index];
		}
	}
}