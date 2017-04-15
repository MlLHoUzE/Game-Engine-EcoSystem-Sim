#ifndef _cFruit_HG_
#define _cFruit_HG_

#include "externals.h"
#include "LoadMesh.h"

class cFruit
{
public:
	cFruit();

	void GetTransform(glm::mat4& transform);
	void SetPosition(glm::vec3& position);
	void GetMeshEntry(sMeshEntry& meshEntry);
	void SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex);
	void GetColor(glm::vec4& color);
	void SetColor(glm::vec4& colorIn);
	void Scale(float scale);
private:
	glm::mat4 m_eTransform;
	sMeshEntry m_eMeshEntry;
	glm::vec4 m_eColor;
};

#endif