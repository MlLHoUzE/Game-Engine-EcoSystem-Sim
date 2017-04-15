#ifndef _cUnicorn_HG_
#define _cUnicorn_HG_

//#include "LoadMesh.h"
#include "iAnimal.h"

class cUnicorn : public iAnimal
{
public:
	struct preferences
	{
		int pref1;
		int pref2;
		int pref3;
	};
	cUnicorn();
	virtual ~cUnicorn() {}

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
	virtual float getCalories();
private:
	glm::mat4 m_eTransform;
	float m_eLinearSpeed;
	float m_eAngularSpeed;
	sMeshEntry m_eMeshEntry;
	glm::vec4 m_eColor;
	float m_calories;
	float m_maxCalories;
	float m_deadCalories;
	float m_reproduceTime;
	float m_reproduceTimer;
	int m_ID;
	bool bActivate;
	bool bIsDead;
	iMediator* m_pMediator;
	int m_type;		//4 = Unicorn, 5 = fox, 6 = tiger
	preferences m_prefs;
};

#endif