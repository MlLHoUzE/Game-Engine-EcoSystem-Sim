#include "cWatermelon.h"
#include "global.h"


cWatermelon::cWatermelon()
{
	m_eTransform = glm::mat4(1.0f);
	m_eLinearSpeed = getRandFloat(0.05f, 0.25f);
	m_eAngularSpeed = 1.0f;
	m_eMeshEntry = sMeshEntry();
	m_eMeshEntry.BaseIndex = 0;
	m_eMeshEntry.BaseVertex = 0;
	m_eMeshEntry.NumIndices = 0;
}
//cEnemy::~cEnemy() {}


void cWatermelon::GetTransform(glm::mat4& transform)
{
	transform = m_eTransform;
}

void cWatermelon::SetPosition(glm::vec3& position)
{
	m_eTransform = glm::translate(m_eTransform, position);
}

void cWatermelon::GetMeshEntry(sMeshEntry& meshEntry)
{
	meshEntry = m_eMeshEntry;
}

void cWatermelon::SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex)
{
	m_eMeshEntry.NumIndices = NumIndices;
	m_eMeshEntry.BaseIndex = BaseIndex;
	m_eMeshEntry.BaseVertex = BaseVertex;
}
void cWatermelon::GetColor(glm::vec4& color)
{
	color = m_eColor;
}
void cWatermelon::SetColor(glm::vec4& colorIn)
{
	m_eColor = colorIn;
}

void cWatermelon::Scale(float scale)
{
	m_eTransform = glm::scale(m_eTransform, glm::vec3(scale, scale, scale));
}

void cWatermelon::Update(float dt)
{
	glm::vec3 direction;

	glm::mat4 targetTransform;
	gPlayer->GetTransform(targetTransform);
	glm::vec3 targetPosition = glm::vec3(targetTransform[3].x, targetTransform[3].y, targetTransform[3].z);
	glm::vec3 myPos = glm::vec3(m_eTransform[3].x, m_eTransform[3].y, m_eTransform[3].z);

	direction = glm::normalize(targetPosition - myPos);



	checkState(targetTransform, direction);

	float linearSpeed = m_eLinearSpeed;

	/*switch (mState)
	{
	case STATE_SEEK:
	linearSpeed *= -1.0f;
	break;
	case STATE_FLEE:

	break;
	}*/

	m_eTransform = glm::translate(m_eTransform, direction * (linearSpeed * dt));

	//check soft bounds
	if (m_eTransform[3].x < gAreaInfo->Min.x)
	{
		m_eTransform[3].x = gAreaInfo->Max.x;
	}
	else if (m_eTransform[3].x > gAreaInfo->Max.x)
	{
		m_eTransform[3].x = gAreaInfo->Min.x;
	}

	if (m_eTransform[3].z < gAreaInfo->Min.z)
	{
		m_eTransform[3].z = gAreaInfo->Max.z;
	}
	else if (m_eTransform[3].z > gAreaInfo->Max.z)
	{
		m_eTransform[3].z = gAreaInfo->Min.z;
	}


}

void cWatermelon::checkState(glm::mat4 targetTransform, glm::vec3 direction)
{
	glm::vec3 targetForward;
	targetForward = glm::vec3(targetTransform[2].x, targetTransform[2].y, targetTransform[2].z);
	float dotResult = glm::dot(targetForward, direction);
	if (dotResult <= 0)	//player is looking away from me
	{
		//seek
		//		mState = STATE_SEEK;

		//change colour
		SetColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	}
	else if (dotResult > 0)//player is looking at me
	{
		//flee
		//mState = STATE_FLEE;
		//change colour

		SetColor(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	}
}