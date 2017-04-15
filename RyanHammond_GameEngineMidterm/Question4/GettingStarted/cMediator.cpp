#include "cMediator.h"
#include "global.h"
#include <iostream>

glm::mat4 cMediator::FindFood(int IDin, int &targetID, int &targetType)
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
				targetID = index;
				targetType = gPlants[index]->getType();
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

glm::mat4 cMediator::FindFood(int ID, int pref1, int pref2, int &targetID, int &targetType)
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

						targetID = index;
						targetType = gPlants[index]->getType();
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
						targetID = index;
						targetType = gPlants[index]->getType();
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
						targetID = index;
						targetType = gPlants[index]->getType();
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
					targetID = gAnimals[index]->GetID();
					targetType = gAnimals[index]->GetType();
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
					targetID = gAnimals[index]->GetID();
					targetType = gAnimals[index]->GetType();
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
					targetID = gAnimals[index]->GetID();
					targetType = gAnimals[index]->GetType();
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
							targetID = index;
							targetType = gPlants[index]->getType();
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
							targetID = index;
							targetType = gPlants[index]->getType();
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
							targetID = index;
							targetType = gPlants[index]->getType();
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
						targetID = gAnimals[index]->GetID();
						targetType = gAnimals[index]->GetType();
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
						targetID = gAnimals[index]->GetID();
						targetType = gAnimals[index]->GetType();
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
						targetID = gAnimals[index]->GetID();
						targetType = gAnimals[index]->GetType();
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

glm::mat4 cMediator::FindFood(int ID, int pref1, int pref2, int pref3, int &targetID, int &targetType)
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
						targetID = index;
						targetType = gPlants[index]->getType();
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
						targetID = index;
						targetType = gPlants[index]->getType();
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
						targetID = index;
						targetType = gPlants[index]->getType();
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
					targetID = gAnimals[index]->GetID();
					targetType = gAnimals[index]->GetType();
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
					targetID = gAnimals[index]->GetID();
					targetType = gAnimals[index]->GetType();
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
					targetID = gAnimals[index]->GetID();
					targetType = gAnimals[index]->GetType();
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
							targetID = index;
							targetType = gPlants[index]->getType();
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
							targetID = index;
							targetType = gPlants[index]->getType();
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
							targetID = index;
							targetType = gPlants[index]->getType();
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
						targetID = gAnimals[index]->GetID();
						targetType = gAnimals[index]->GetType();
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
						targetID = gAnimals[index]->GetID();
						targetType = gAnimals[index]->GetType();
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
						targetID = gAnimals[index]->GetID();
						targetType = gAnimals[index]->GetType();
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
							targetID = index;
							targetType = gPlants[index]->getType();
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
							targetID = index;
							targetType = gPlants[index]->getType();
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
							targetID = index;
							targetType = gPlants[index]->getType();
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
						targetID = gAnimals[index]->GetID();
						targetType = gAnimals[index]->GetType();
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
						targetID = gAnimals[index]->GetID();
						targetType = gAnimals[index]->GetType();
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
						targetID = gAnimals[index]->GetID();
						targetType = gAnimals[index]->GetType();
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

	return NULL;
}

iPlant* cMediator::m_pFindPlantByID(int ID)
{
	if(ID >= 0)
	return gPlants[ID];
	else return NULL;
}

float cMediator::eat(int ID, int targetID, int targetType)
{
	
	iAnimal* animal = m_pFindAnimalByID(ID);
	iAnimal* targetAnimal;
	iPlant* targetPlant;
	float returnCalories;
	if (targetType < 3)
	{
		targetPlant = m_pFindPlantByID(targetID);
		if (targetPlant != NULL)
		{
			returnCalories = targetPlant->getCalories();
			targetPlant->setEaten(false);
		}

	}
	else if (targetType < 6)
	{
		std::cout << "eat by:" << ID << "on " << targetID << std::endl;
		targetAnimal = m_pFindAnimalByID(targetID);
		if (targetAnimal == NULL)
			return 0;
		returnCalories = targetAnimal->getCalories();
		deleteAnimal(targetID);
	}
	return returnCalories;
}

void cMediator::deleteAnimal(int ID)
{

	
	std::cout << "Delete Called" << std::endl;
	for ( int index = 0; index != gAnimals.size(); index++)
	{
		if (gAnimals[index]->GetID() == ID)
		{
			gAnimals.erase(gAnimals.begin() + index);
			break;
		}
	}
	gAnimals.shrink_to_fit();
}

void cMediator::spawnAnimal(int ID)
{
	iAnimal* parent = m_pFindAnimalByID(ID);
	cAnimalBuilder* pAnimalBuilder = cAnimalBuilder::getInstance();
	int type = parent->GetType();
	sMeshEntry mesh;
	parent->GetMeshEntry(mesh);
	glm::mat4 transform;
	parent->GetTransform(transform);
	glm::vec3 position = glm::vec3(transform[3].x, transform[3].y, transform[3].z);
	float scale;
	scale = transform[0].x;
	iAnimal* animal;
	switch (type)
	{
	case 3:
		//bunny
		animal = pAnimalBuilder->createAnimal("Bunny");
		break;
	case 4:
		animal = pAnimalBuilder->createAnimal("Fox");
		break;
	case 5:
		animal = pAnimalBuilder->createAnimal("Tiger");
		break;
	default:
		animal = pAnimalBuilder->createAnimal("Bunny");
		break;
	}
	animal->SetMeshEntry(mesh.NumIndices, mesh.BaseIndex, mesh.BaseVertex);
	animal->SetPosition(position);
	animal->Scale(scale);
	animal->setMediator(this);
	animal->SetID(gAnimalID);
	gAnimalID++;
	animal->SetColor(glm::vec4(0.0, 0.0, 0.0, 1.0));
	gAnimals.push_back(animal);
	
}