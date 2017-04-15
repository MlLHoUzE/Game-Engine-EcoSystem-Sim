#ifndef _cPineapple_HG_
#define _cPineapple_HG_

//#include "LoadMesh.h"
#include "iPlant.h"
#include "cFruit.h"

class cPineapple : public iPlant
{
public:
	cPineapple();
	virtual ~cPineapple() {}

	virtual void GetTransform(glm::mat4& transform);
	virtual void SetPosition(glm::vec3& position);
	virtual void GetMeshEntry(sMeshEntry& meshEntry);
	virtual void SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex);
	virtual void GetColor(glm::vec4& color);
	virtual void SetColor(glm::vec4& colorIn);
	virtual void Scale(float scale);
	virtual void Update(float dt);
	virtual cFruit* checkForFruit();
	virtual int getType();


private:
	glm::mat4 m_eTransform;
	sMeshEntry m_eMeshEntry;
	glm::vec4 m_eColor;

	int m_calories;
	float m_spawnTime;
	float m_timeToSpoil;
	bool m_hasFruit;
	float m_currentSpawnTime;
	float m_spoilTimer;
	cFruit* m_fruit;

	int m_type;	//1 = strawberry, 2 = pineapple, 3 = watermelon
};

#endif