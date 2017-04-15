#ifndef _iPlant_HG_
#define _iPlant_HG_


#include "LoadMesh.h"
#include "cFruit.h"

class iPlant
{
public:
	//	iShip();
	virtual ~iPlant() {};

	virtual void GetTransform(glm::mat4& transform) = 0;
	virtual void SetPosition(glm::vec3& position) = 0;
	virtual void GetMeshEntry(sMeshEntry& meshEntry) = 0;
	virtual void SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex) = 0;
	virtual void GetColor(glm::vec4& color) = 0;
	virtual void SetColor(glm::vec4& colorIn) = 0;
	virtual void Scale(float scale) = 0;
	virtual void Update(float dt) = 0;
	virtual cFruit* checkForFruit() = 0;

	

};



#endif
