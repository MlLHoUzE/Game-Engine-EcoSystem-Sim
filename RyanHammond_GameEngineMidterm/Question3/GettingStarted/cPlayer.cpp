#include "cPlayer.h"
#include "Input.h"

cPlayer::cPlayer()
{
	m_transform = glm::mat4(1.0f);
	m_linearSpeed = 20.f;
	m_angularSpeed = 1.0f;
	m_meshEntry = sMeshEntry();
	m_meshEntry.BaseIndex = 0;
	m_meshEntry.BaseVertex = 0;
	m_meshEntry.NumIndices = 0;
}

cPlayer* cPlayer::m_pTheOneThing = 0;

cPlayer* cPlayer::getInstance(void)	//Singleton step 2
{
	// Is the pointer still 0, NULL
	if (cPlayer::m_pTheOneThing == 0)
	{	// Yup. 
		cPlayer::m_pTheOneThing = new cPlayer();
	}
	return cPlayer::m_pTheOneThing;
}

void cPlayer::shutDown(void)
{
	// Do we have an instance?
	if (cPlayer::m_pTheOneThing != 0)
	{	// Yes, so get rid of it
		delete cPlayer::m_pTheOneThing;
	}
	return;
}

void cPlayer::GetTransform(glm::mat4& transform)
{
	transform = m_transform;
}

void cPlayer::SetPosition(glm::vec3& position)
{
	glm::translate(m_transform, position);
}

void cPlayer::GetMeshEntry(sMeshEntry& meshEntry)
{
	meshEntry = m_meshEntry;
}

void cPlayer::SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex)
{
	m_meshEntry.NumIndices = NumIndices;
	m_meshEntry.BaseIndex = BaseIndex;
	m_meshEntry.BaseVertex = BaseVertex;
}

void cPlayer::GetColor(glm::vec4& color)
{
	color = m_color;
}

void cPlayer::SetColor(glm::vec4& colorIn)
{
	m_color = colorIn;
}

void cPlayer::Scale(float scale)
{

}
void cPlayer::Update(float dt)
{
	bool pressW = nInput::IsKeyPressed::W();
	bool pressS = nInput::IsKeyPressed::S();
	bool pressA = nInput::IsKeyPressed::A();
	bool pressD = nInput::IsKeyPressed::D();
	//camera controls:
	//up/down = zoom in/zoom out
	//left/right = pan left/pan right

	float linearSpeed = m_linearSpeed;
	float angularSpeed = m_angularSpeed;
	//movement controls:
	// w/s = forward / backward
	if (pressW != pressS)
	{
		if (pressS) linearSpeed *= -1.f;
		m_transform = glm::translate(m_transform, glm::vec3(0.0f, 0.0f, linearSpeed * dt));
		//SetPosition(glm::vec3(linearSpeed, 0.f, 0.f));
	}

	if (m_transform[3].x < gAreaInfo->Min.x)
	{
		m_transform[3].x = gAreaInfo->Max.x;
	}
	else if (m_transform[3].x > gAreaInfo->Max.x)
	{
		m_transform[3].x = gAreaInfo->Min.x;
	}

	if (m_transform[3].z < gAreaInfo->Min.z)
	{
		m_transform[3].z = gAreaInfo->Max.z;
	}
	else if (m_transform[3].z > gAreaInfo->Max.z)
	{
		m_transform[3].z = gAreaInfo->Min.z;
	}

	if (pressA != pressD)
	{
		if (pressD) angularSpeed *= -1.f;
		m_transform = glm::rotate(m_transform, angularSpeed*dt, glm::vec3(0.f, 1.f, 0.f));
	}




}