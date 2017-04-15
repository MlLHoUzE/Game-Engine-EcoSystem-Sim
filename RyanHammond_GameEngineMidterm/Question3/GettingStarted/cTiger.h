#ifndef _cTiger_HG_
#define _cTiger_HG_

//#include "LoadMesh.h"
#include "iAnimal.h"

class cTiger : public iAnimal
{
public:
	struct preferences
	{
		int pref1;
		int pref2;
		int pref3;
	};
	cTiger();
	virtual ~cTiger() {}

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
	int m_type;		//4 = bunny, 5 = fox, 6 = tiger
	iMediator* m_pMediator;

	preferences m_prefs;

};

#endif#pragma once
