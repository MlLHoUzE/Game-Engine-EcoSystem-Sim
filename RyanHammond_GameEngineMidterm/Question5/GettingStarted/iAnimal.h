#ifndef _iAnimal_HG_
#define _iAnimal_HG_


#include "LoadMesh.h"
#include "iMediator.h"

class iAnimal
{
public:
	//	iShip();
	virtual ~iAnimal() {};

	virtual void setMediator(iMediator* pMediator) = 0;

	virtual void GetTransform(glm::mat4& transform) = 0;
	virtual void SetPosition(glm::vec3& position) = 0;
	virtual void GetMeshEntry(sMeshEntry& meshEntry) = 0;
	virtual void SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex) = 0;
	virtual void GetColor(glm::vec4& color) = 0;
	virtual void SetColor(glm::vec4& colorIn) = 0;
	virtual int GetID() = 0;
	virtual void SetID(int ID) = 0;
	virtual void Scale(float scale) = 0;
	virtual void Update(float dt) = 0;
	virtual float getCalories() = 0;


	virtual int GetType() = 0;

};



#endif
