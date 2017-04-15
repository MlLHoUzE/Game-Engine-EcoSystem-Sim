// glfw needs these guys :(
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "externals.h"
#include "global.h"
#include "LoadShaders.h"
#include "LoadMesh.h"
#include "LoadTexture.h"
#include "Update.h"
#include "cPlantBuilder.h"
#include "cAnimalBuilder.h"
#include "cFruit.h"

sMeshEntry monkeyMesh;
sMeshEntry bunnyMesh;
sMeshEntry foxMesh;
sMeshEntry tigerMesh;
sMeshEntry animalMesh;
sMeshEntry boxMesh;

void Callback_WindowResize(GLFWwindow* window, int width, int height);
void CreateTheBuffers(std::vector<sMeshVertex>& vertices, std::vector<unsigned int>& indices);
void BindTheBuffers();
void DrawBufferEntry(sMeshEntry& entry);
bool SetUpTheShader();
void Update();
void DrawScene();
float getRandFloat(float LO, float HIGH);

int main()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	gCamera = new cCamera();
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	//create the Player
	gPlayer = cPlayer::getInstance();

	gAreaInfo = new cAreaInfo();

	

	
	

	// Open a window and create its OpenGL context
	gWindow = glfwCreateWindow(1024, 768, "Artificial Intelligence Proj 1: By Ryan Hammond", NULL, NULL);
	if (gWindow == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(gWindow);
	
	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}


	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(gWindow, GLFW_STICKY_KEYS, GL_TRUE);
	glfwPollEvents();

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	// Load the shader
	if (!SetUpTheShader())
	{
		std::cout << "Oh no! The shaders didn't load!!" << std::endl;
		system("pause");
		return -1;
	}
	// the texture
	//GLuint texture = LoadDDS("uvmap.DDS");
	// load the mesh buffers
	std::vector<sMeshVertex> vertices;
	std::vector<unsigned int> indices;
	bool success = false;
	success = LoadMesh("assets/suzanne.obj", indices, vertices, monkeyMesh);
	{	//create player
		gPlayer->SetMeshEntry(monkeyMesh.NumIndices, monkeyMesh.BaseIndex, monkeyMesh.BaseVertex);
		gPlayer->SetColor(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
	}
	success = LoadMesh("assets/Turret_Low_N.ply", indices, vertices, monkeyMesh);

	success = LoadMesh("assets/box.obj", indices, vertices, gFruitMesh);
	//create 10 enemies
	cPlantBuilder* pPlantBuilder = cPlantBuilder::getInstance();
	
	for (int index = 0; index != 165; index++)
	{
		iPlant* plant;

		plant = pPlantBuilder->createPlant("Strawberry");	//Factory Step 1

		plant->SetPosition(glm::vec3(getRandFloat(gAreaInfo->Min.x, gAreaInfo->Max.x),
			getRandFloat(gAreaInfo->Min.y, gAreaInfo->Max.y),
			getRandFloat(gAreaInfo->Min.z, gAreaInfo->Max.z)));
		plant->Scale(0.1f);
		plant->SetMeshEntry(monkeyMesh.NumIndices, monkeyMesh.BaseIndex, monkeyMesh.BaseVertex);
		plant->SetColor(glm::vec4(1.0, 0.0, 0.0, 1.0));
		gPlants.push_back(plant);
	}
	for (int index = 0; index != 165; index++)
	{
		iPlant* plant;
		plant = pPlantBuilder->createPlant("Pineapple");

		plant->SetPosition(glm::vec3(getRandFloat(gAreaInfo->Min.x, gAreaInfo->Max.x),
									getRandFloat(gAreaInfo->Min.y, gAreaInfo->Max.y),
									getRandFloat(gAreaInfo->Min.z, gAreaInfo->Max.z)));
		plant->Scale(0.1f);
		plant->SetMeshEntry(monkeyMesh.NumIndices, monkeyMesh.BaseIndex, monkeyMesh.BaseVertex);
		plant->SetColor(glm::vec4(0.0, 1.0, 0.0, 1.0));
		gPlants.push_back(plant);
	}
	for (int index = 0; index != 165; index++)
	{
		iPlant* plant;
		plant = pPlantBuilder->createPlant("Watermelon");

		plant->SetPosition(glm::vec3(getRandFloat(gAreaInfo->Min.x, gAreaInfo->Max.x),
			getRandFloat(gAreaInfo->Min.y, gAreaInfo->Max.y),
			getRandFloat(gAreaInfo->Min.z, gAreaInfo->Max.z)));
		plant->Scale(0.1f);
		plant->SetMeshEntry(monkeyMesh.NumIndices, monkeyMesh.BaseIndex, monkeyMesh.BaseVertex);
		plant->SetColor(glm::vec4(0.0, 0.0, 1.0, 1.0));
		gPlants.push_back(plant);
	}
	success = LoadMesh("assets/Vader_Tie_Low_N.ply", indices, vertices, bunnyMesh);
	success = LoadMesh("assets/Y-Wing_Low_N.ply", indices, vertices, foxMesh);
	success = LoadMesh("assets/X-Wing_Attack_Low_N.ply", indices, vertices, tigerMesh);

	cAnimalBuilder* pAnimalBuilder = cAnimalBuilder::getInstance();
	for (int index = 0; index != 60; index++)
	{
		iAnimal* animal;
		float animalScale;
		if (index < 20)
		{
			animal = pAnimalBuilder->createAnimal("Bunny");
			animalMesh = bunnyMesh;
			animalScale = 3.f;
		}
		else if (index < 40)
		{
			animal = pAnimalBuilder->createAnimal("Fox");
			animalMesh = foxMesh;
			animalScale = 1.f;
		}
		else
		{
			animal = pAnimalBuilder->createAnimal("Tiger");
			animalMesh = tigerMesh;
			animalScale = 1.5f;
		}
		animal->SetPosition(glm::vec3(getRandFloat(gAreaInfo->Min.x, gAreaInfo->Max.x),
			getRandFloat(gAreaInfo->Min.y, gAreaInfo->Max.y),
			getRandFloat(gAreaInfo->Min.z, gAreaInfo->Max.z)));
		animal->Scale(animalScale);
		animal->SetMeshEntry(animalMesh.NumIndices, animalMesh.BaseIndex, animalMesh.BaseVertex);
		animal->SetColor(glm::vec4(0.0, 0.0, 0.0, 1.0));
		gAnimals.push_back(animal);
	}


	

	//success = LoadMesh("assets/SoccerBall.obj", indices, vertices, monkeyMesh);
	//success = LoadMesh("assets/soccerball3.obj", indices, vertices, monkeyMesh);
	//success = LoadMesh("assets/apple.ply", indices, vertices, monkeyMesh);
	success = LoadMesh("assets/box.obj", indices, vertices, boxMesh);
	if (!success)
	{
		std::cout << "we couldn't load the model!" << std::endl;
		system("pause");
		return -1;
	}
	
	CreateTheBuffers(vertices, indices);
	
	
	do {
		// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Update();
		DrawScene();

		// Swap buffers
		glfwSwapBuffers(gWindow);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(gWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(gWindow) == 0);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	delete gCamera;
	gCamera = 0;
	return 0;
}

// this is just terrible
void DrawTheFloor()
{
	glm::mat4 boxMat;
	boxMat = glm::scale(boxMat, glm::vec3(1000.f, 0.25f, 1000.f));
	glm::vec4 boxColorLight(9.f, 9.f, 9.f, 1.f);
	glm::vec4 boxColorDark(0.2f, 0.2f, 0.2f, 1.f);
	glm::vec4 red(1.f, 0.f, 0.f, 1.f);
	glm::vec4 blue(0.f, 0.f, 1.f, 1.f);

	// per item uniforms
	//glUniformMatrix4fv(gUniformId_ModelMatrix, 1, GL_FALSE, glm::value_ptr(boxMat));
	//glUniform4fv(gUniformId_ModelColor, 1, glm::value_ptr(boxColorLight));

	glm::vec3 center(-0.f, -1.4f, -0.f);
	glm::vec3 xStep(1.f, 0.f, 0.f);
	glm::vec3 zStep(0.f, 0.f, 1.f);
	glm::vec4 color = boxColorLight;
	glUniformMatrix4fv(gUniformId_ModelMatrix, 1, GL_FALSE, glm::value_ptr(boxMat));
	glUniform4fv(gUniformId_ModelColor, 1, glm::value_ptr(color));

	DrawBufferEntry(boxMesh);
	/*for (int i = gAreaInfo->Min.x; i <= gAreaInfo->Max.x; i++)
	{
		for (int k = gAreaInfo->Min.z; k <= gAreaInfo->Max.z; k++)
		{
			glm::vec3 pos = center + xStep * (float)i + zStep * (float)k;
			glm::vec4 color = (i * k) % 2 == 0 ? boxColorDark : boxColorLight;
			if (i * k == 0 && i + k != 0)
			{
				if (i == 0) color = blue;
				else color = red;
			}
			boxMat[3].x = pos.x;  boxMat[3].y = pos.y; boxMat[3].z = pos.z;

			glUniformMatrix4fv(gUniformId_ModelMatrix, 1, GL_FALSE, glm::value_ptr(boxMat));
			glUniform4fv(gUniformId_ModelColor, 1, glm::value_ptr(color));

			DrawBufferEntry(boxMesh);
		}
	}*/
	
}

void DrawScene()
{
	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
	glm::vec4 eye;
	gCamera->GetProjectionMatrix(projectionMatrix);
	gCamera->GetViewMatrix(viewMatrix);
	gCamera->GetEyePosition(eye);

	BindTheBuffers();
	glUseProgram(gProgramID);
	
	// per frame uniforms
	glUniformMatrix4fv(gUniformId_PojectionMatrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(gUniformId_ViewMatrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glm::vec4 eye4(eye.x, eye.y, eye.z, eye.w);
	glUniform4fv(gUniformId_EyePosition, 1, glm::value_ptr(eye4));
	
	DrawTheFloor();

	for (int index = 0; index != gPlants.size(); index++)
	{
		iPlant* curPlant = gPlants[index];
		
		glm::mat4 curTransform;
		curPlant->GetTransform(curTransform);
		glm::vec4 curColor;
		curPlant->GetColor(curColor);
		sMeshEntry curMeshEntry;
		curPlant->GetMeshEntry(curMeshEntry);
		glUniformMatrix4fv(gUniformId_ModelMatrix, 1, GL_FALSE, glm::value_ptr(curTransform));
		glUniform4fv(gUniformId_ModelColor, 1, glm::value_ptr(curColor));
		DrawBufferEntry(curMeshEntry);
		cFruit* curFruit = curPlant->checkForFruit();
		if (curFruit)
		{
			glm::mat4 curTransform;
			curFruit->GetTransform(curTransform);
			glm::vec4 curColor;
			curFruit->GetColor(curColor);
			sMeshEntry curMeshEntry;
			curFruit->GetMeshEntry(curMeshEntry);
			glUniformMatrix4fv(gUniformId_ModelMatrix, 1, GL_FALSE, glm::value_ptr(curTransform));
			glUniform4fv(gUniformId_ModelColor, 1, glm::value_ptr(curColor));
			DrawBufferEntry(curMeshEntry);
			//draw the fruit
		}
	}

	for (int index = 0; index != gAnimals.size(); index++)
	{
		iAnimal* curAnimal = gAnimals[index];
		glm::mat4 curTransform;
		curAnimal->GetTransform(curTransform);
		glm::vec4 curColor;
		curAnimal->GetColor(curColor);
		sMeshEntry curMeshEntry;
		curAnimal->GetMeshEntry(curMeshEntry);
		glUniformMatrix4fv(gUniformId_ModelMatrix, 1, GL_FALSE, glm::value_ptr(curTransform));
		glUniform4fv(gUniformId_ModelColor, 1, glm::value_ptr(curColor));
		DrawBufferEntry(curMeshEntry);
	}

	//draw the player
	glm::mat4 curTransform;
	gPlayer->GetTransform(curTransform);
	glm::vec4 curColor;
	gPlayer->GetColor(curColor);
	sMeshEntry curMeshEntry;
	gPlayer->GetMeshEntry(curMeshEntry);
	glUniformMatrix4fv(gUniformId_ModelMatrix, 1, GL_FALSE, glm::value_ptr(curTransform));
	glUniform4fv(gUniformId_ModelColor, 1, glm::value_ptr(curColor));
	DrawBufferEntry(curMeshEntry);
	//for each entity
	//grab teh entitty
	//get physics stuff, pass the transform as model matrix
	//get the render stuff, pass the color, and render the mesh

	// per item uniforms
	//glUniformMatrix4fv(gUniformId_ModelMatrix, 1, GL_FALSE, glm::value_ptr(gMonkeyMatrix));
	//glUniform4fv(gUniformId_ModelColor, 1, glm::value_ptr(gMonkeyColor));

	//DrawBufferEntry(monkeyMesh);
}

bool SetUpTheShader()
{
	// Create and compile our GLSL program from the shaders
	gProgramID = LoadShaders("SimpleShader.vert", "SimpleShader.frag");
	if (!gProgramID)
	{
		std::cout << "Oh no! The shaders didn't load!!" << std::endl;
		return false;
	}
	
	// per item
	gUniformId_ModelMatrix = glGetUniformLocation(gProgramID, "ModelMatrix");
	gUniformId_ModelColor = glGetUniformLocation(gProgramID, "ModelColor");
	// per frame
	gUniformId_ViewMatrix = glGetUniformLocation(gProgramID, "ViewMatrix");
	gUniformId_PojectionMatrix = glGetUniformLocation(gProgramID, "ProjectionMatrix");
	gUniformId_EyePosition = glGetUniformLocation(gProgramID, "EyePosition");


	return true;
}

void Callback_WindowResize(GLFWwindow* window, int width, int height)
{
	gCamera->WindowResize(width, height);
}

void CreateTheBuffers(std::vector<sMeshVertex>& vertices, std::vector<unsigned int>& indices)
{
	glGenVertexArrays(1, &gVertexBufferID);
	glBindVertexArray(gVertexBufferID);

	glGenBuffers(1, &gTexCoordBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, gTexCoordBufferID);

	glGenBuffers(1, &gNormalBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, gNormalBufferID);

	int bytesInVertexArray = vertices.size() * sizeof(sMeshVertex);
	glBufferData(GL_ARRAY_BUFFER, bytesInVertexArray, &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &gIndexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIndexBufferID);

	int bytesInIndexArray = indices.size() * sizeof(GLuint);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, bytesInIndexArray, &indices[0], GL_STATIC_DRAW);

	BindTheBuffers();
}

void BindTheBuffers()
{
	glBindVertexArray(gVertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, gTexCoordBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, gNormalBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIndexBufferID);

	glEnableVertexAttribArray(0); // Position
	glEnableVertexAttribArray(1); // TexCoord
	glEnableVertexAttribArray(2); // Normal

	glVertexAttribPointer(0,		// index or "slot" in the shader
		4,							// Number of variables: vec4 would be 4 32-bit variables
		GL_FLOAT,					// Type: vec4 is float
		GL_FALSE,					// "normalize" the values (or not)
		sizeof(sMeshVertex),			// Number of bytes per vertex (the "stride")
		(GLvoid*)0);				// Offset from vertex (position is first, so offset = 0

	int offsetToTexCoordsInBytes = sizeof(((sMeshVertex*)0)->Position);
	glVertexAttribPointer(1,
		4,
		GL_FLOAT,
		GL_FALSE,
		sizeof(sMeshVertex),
		(GLvoid*)offsetToTexCoordsInBytes);		// Offset in bytes to TexCoords

	int offsetToNormalInBytes = offsetToTexCoordsInBytes + sizeof(((sMeshVertex*)0)->TexCoord);
	glVertexAttribPointer(2,
		4,
		GL_FLOAT,
		GL_FALSE,
		sizeof(sMeshVertex),
		(GLvoid*)offsetToNormalInBytes);		// Offset in bytes to Normal
}

void DrawBufferEntry(sMeshEntry& entry)
{
	glDrawElementsBaseVertex(GL_TRIANGLES,
		entry.NumIndices,
		GL_UNSIGNED_INT,
		(void*)(sizeof(unsigned int) * entry.BaseIndex),
		entry.BaseVertex);
}

//float getRandFloat(float LO, float HIGH)
//{
//	float r3 = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HIGH - LO)));
//
//	return r3;
//}