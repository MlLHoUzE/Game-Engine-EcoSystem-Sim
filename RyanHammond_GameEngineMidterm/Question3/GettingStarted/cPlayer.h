#ifndef _cPlayer_HG_
#define _cPlayer_HG_

#include "LoadMesh.h"

class cPlayer
{
public:

	virtual ~cPlayer() {}
	static cPlayer* getInstance(void);
	static void shutDown(void);

	virtual void GetTransform(glm::mat4& transform);
	virtual void SetPosition(glm::vec3& position);
	virtual void GetMeshEntry(sMeshEntry& meshEntry);
	virtual void SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex);
	virtual void GetColor(glm::vec4& color);
	virtual void SetColor(glm::vec4& colorIn);

	virtual void Scale(float scale);
	virtual void Update(float dt);
private:
	cPlayer();
	glm::mat4 m_transform;
	float m_linearSpeed;
	float m_angularSpeed;
	sMeshEntry m_meshEntry;
	glm::vec4 m_color;
	static cPlayer* m_pTheOneThing;
};

#endif