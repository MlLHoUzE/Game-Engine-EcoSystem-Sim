#ifndef _cPineapple_HG_
#define _cPineapple_HG_

//#include "LoadMesh.h"
#include "iPlant.h"

class cPineapple : public iPlant
{
public:
	enum cEnemyState
	{
		//STATE_WANDER,
		//STATE_APPROACH,
		//STATE
		STATE_FLEE,
		STATE_SEEK
	};
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
	virtual void checkState(glm::mat4 targetTransform, glm::vec3 direction);

private:
	glm::mat4 m_eTransform;
	float m_eLinearSpeed;
	float m_eAngularSpeed;
	sMeshEntry m_eMeshEntry;
	glm::vec4 m_eColor;
	//void SeekStep(float dt);
	//void FleeStep(float dt);
	//void MakeADecision();
	cEnemyState mState;
	//float mDecisionTime;
	//float mDecisionCountDown;

};

#endif