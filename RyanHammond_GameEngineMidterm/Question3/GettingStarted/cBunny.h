#ifndef _cBunny_HG_
#define _cBunny_HG_

//#include "LoadMesh.h"
#include "iAnimal.h"

class cBunny : public iAnimal
{
public:
	struct preferences
	{
		std::string pref1 = "Fruit";
		std::string pref2 = "NONE";
		std::string pref3 = "NONE";
	};
	cBunny();
	virtual ~cBunny() {}

	virtual void GetTransform(glm::mat4& transform);
	virtual void SetPosition(glm::vec3& position);
	virtual void GetMeshEntry(sMeshEntry& meshEntry);
	virtual void SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex);
	virtual void GetColor(glm::vec4& color);
	virtual void SetColor(glm::vec4& colorIn);
	virtual int GetID();
	virtual void SetID(int ID);
	virtual void Scale(float scale);
	virtual void Update(float dt);

	virtual void setMediator(iMediator* mediator);

	virtual int GetType();
private:
	glm::mat4 m_eTransform;
	float m_eLinearSpeed;
	float m_eAngularSpeed;
	sMeshEntry m_eMeshEntry;
	glm::vec4 m_eColor;
	float m_calories;
	float m_maxCalories;
	float m_reproduceTime;
	float m_reproduceTimer;
	int m_ID;

	iMediator* m_pMediator;
	int m_type;		//4 = bunny, 5 = fox, 6 = tiger
};

#endif