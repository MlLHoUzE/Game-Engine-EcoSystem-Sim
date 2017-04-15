#include "Update.h"

void Update()
{
	static double lastTime = glfwGetTime();
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);
	if (deltaTime == 0.f)
	{
		lastTime = currentTime;
		return;
	}

	for (int index = 0; index != gPlants.size(); index++)	//loop through all entities and run their updates
	{
		gPlants[index]->Update(deltaTime);
	}
	gPlayer->Update(deltaTime);
	//refocus camera
	glm::mat4 cameraTargetTransform;
	gPlayer->GetTransform(cameraTargetTransform);
	gCamera->SetTargetTransform(cameraTargetTransform);
	gCamera->Update(deltaTime);

	lastTime = currentTime;	//update for deltaTime
}