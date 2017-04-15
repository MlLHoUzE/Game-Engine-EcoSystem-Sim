#include "cWatermelon.h"
#include "global.h"


cWatermelon::cWatermelon()
{
	m_eTransform = glm::mat4(1.0f);
	m_eMeshEntry = sMeshEntry();
	m_eMeshEntry.BaseIndex = 0;
	m_eMeshEntry.BaseVertex = 0;
	m_eMeshEntry.NumIndices = 0;
	m_calories = 10000;
	m_spawnTime = getRandFloat(10.f, 25.f);
	m_timeToSpoil = 60.f;
	m_hasFruit = false;
	m_spoilTimer = 0.f;
	m_currentSpawnTime = 0.f;
	m_type = 2;
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


cFruit* cWatermelon::checkForFruit()
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

int cWatermelon::getType()
{
	return m_type;
}