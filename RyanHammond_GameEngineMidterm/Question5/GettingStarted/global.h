#pragma once
#include "externals.h"
#include "cCamera.h"
#include "cPlayer.h"
#include "cAreaInfo.h"
#include "cPlantFactory.h"
#include "cAnimalFactory.h"

enum gPreferences
{
	STRAWBERRY,
	PINEAPPLE,
	WATERMELON,
	LETTUCE,
	BUNNY,
	FOX,
	TIGER
};

extern GLFWwindow* gWindow;

extern float secondCounter;
extern int gAnimalID;

extern cCamera* gCamera;

extern cAreaInfo* gAreaInfo;

extern sMeshEntry gFruitMesh;

extern cPlantFactory* gPlantFactory;
extern cAnimalFactory* gAnimalFactory;


extern std::vector<iPlant*> gPlants;
extern std::vector<iAnimal*> gAnimals;
extern cPlayer* gPlayer;
//extern cAreaInfo* gAreaInfo;


extern glm::mat4 gMonkeyMatrix;
extern glm::vec4 gMonkeyColor;

extern GLuint gVertexBufferID;
extern GLuint gTexCoordBufferID;
extern GLuint gNormalBufferID;
extern GLuint gIndexBufferID;

extern GLuint gProgramID;
extern GLuint gUniformId_ModelMatrix;
extern GLuint gUniformId_ViewMatrix;
extern GLuint gUniformId_PojectionMatrix;
extern GLuint gUniformId_ModelColor;
extern GLuint gUniformId_EyePosition;


float getRandFloat(float LO, float HIGH);

