#include "cPineapple.h"
#include "global.h"


cPineapple::cPineapple()
{
	m_eTransform = glm::mat4(1.0f);
	m_eMeshEntry = sMeshEntry();
	m_eMeshEntry.BaseIndex = 0;
	m_eMeshEntry.BaseVertex = 0;
	m_eMeshEntry.NumIndices = 0;

	m_calories = 1000;
	m_spawnTime = getRandFloat(5.f, 15.f);
	m_timeToSpoil = 75.f;
	m_hasFruit = false;
	m_spoilTimer = 0.f;
	m_currentSpawnTime = 0.f;
	m_type = 1;
}
//cEnemy::~cEnemy() {}


void cPineapple::GetTransform(glm::mat4& transform)
{
	transform = m_eTransform;
}

void cPineapple::SetPosition(glm::vec3& position)
{
	m_eTransform = glm::translate(m_eTransform, position);
}

void cPineapple::GetMeshEntry(sMeshEntry& meshEntry)
{
	meshEntry = m_eMeshEntry;
}

void cPineapple::SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex)
{
	m_eMeshEntry.NumIndices = NumIndices;
	m_eMeshEntry.BaseIndex = BaseIndex;
	m_eMeshEntry.BaseVertex = BaseVertex;
}
void cPineapple::GetColor(glm::vec4& color)
{
	color = m_eColor;
}
void cPineapple::SetColor(glm::vec4& colorIn)
{
	m_eColor = colorIn;
}


void cPineapple::Scale(float scale)
{
	m_eTransform = glm::scale(m_eTransform, glm::vec3(scale, scale, scale));
}

void cPineapple::Update(float dt)
{
	if (m_hasFruit)
	{
		m_spoilTimer += dt;
		if (m_spoilTimer > m_timeToSpoil)
		{
			m_hasFruit = false;
			delete this->m_fruit;
			m_spoilTimer = 0.f;
		}
	}
	else
	{
		m_currentSpawnTime += dt;
		if (m_currentSpawnTime > m_spawnTime)
		{
			this->m_fruit = new cFruit();
			m_fruit->SetPosition(glm::vec3(m_eTransform[3].x, m_eTransform[3].y + 4, m_eTransform[3].z));
			m_fruit->SetColor(glm::vec4(0.0, 1.0, 1.0, 1.0));
			m_fruit->Scale(1.f);
			this->m_hasFruit = true;
			this->m_currentSpawnTime = 0.f;
		}
	}
}

cFruit* cPineapple::checkForFruit()
{
	if (m_hasFruit)
	{
		return m_fruit;
	}
	else
	{
		return nullptr;
	}
}

int cPineapple::getType()
{
	return m_type;
}

float cPineapple::getCalories()
{
	if (m_hasFruit)
		return m_calories;
	else
		return 0;
}

void cPineapple::setEaten(bool bIsEaten)
{
	m_hasFruit = bIsEaten;
}