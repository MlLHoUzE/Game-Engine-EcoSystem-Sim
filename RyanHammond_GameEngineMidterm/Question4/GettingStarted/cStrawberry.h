#ifndef _cStrawberry_HG_
#define _cStrawberry_HG_


#include "iPlant.h"
#include "cFruit.h"

class cStrawberry : public iPlant
{
public:
	cStrawberry();
	virtual ~cStrawberry() {}

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
	virtual float getCalories();
	virtual void setEaten(bool bIsEaten);

	

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
	int m_type;	//1 = strawberry, 2 = pineapple, 3 = watermelon
	cFruit* m_fruit;

};

#endif