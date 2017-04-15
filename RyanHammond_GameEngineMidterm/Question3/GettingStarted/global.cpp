#include "global.h"
#include <iostream>

GLFWwindow* gWindow = 0;

cCamera* gCamera = 0;
std::vector<iPlant*> gPlants;
std::vector<iAnimal*> gAnimals;
cPlayer* gPlayer = 0;

cAreaInfo* gAreaInfo = 0;

float secondCounter = 0;

cPlantFactory* gPlantFactory = 0;
cAnimalFactory* gAnimalFactory = 0;

sMeshEntry gFruitMesh;

glm::mat4 gMonkeyMatrix;
glm::vec4 gMonkeyColor(1.f, 0.6f, 0.8f, 1.f);

GLuint gVertexBufferID = 0;
GLuint gTexCoordBufferID = 0;
GLuint gNormalBufferID = 0;
GLuint gIndexBufferID = 0;

GLuint gProgramID = 0;
GLuint gUniformId_ModelMatrix = 0;
GLuint gUniformId_ViewMatrix = 0;
GLuint gUniformId_PojectionMatrix = 0;
GLuint gUniformId_ModelColor = 0;
GLuint gUniformId_EyePosition = 0;


float getRandFloat(float LO, float HIGH)
{
	float r3 = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HIGH - LO)));

	return r3;
}
