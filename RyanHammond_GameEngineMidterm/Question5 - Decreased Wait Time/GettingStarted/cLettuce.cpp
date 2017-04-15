#include "cLettuce.h"
#include "global.h"


cLettuce::cLettuce()
{
	m_eTransform = glm::mat4(1.0f);
	m_eMeshEntry = sMeshEntry();
	m_eMeshEntry.BaseIndex = 0;
	m_eMeshEntry.BaseVertex = 0;
	m_eMeshEntry.NumIndices = 0;

	m_calories = 250;
	m_spawnTime = getRandFloat(1.5f, 7.5f);
	m_timeToSpoil = 40.f;
	m_hasFruit = false;
	m_spoilTimer = 0.f;
	m_currentSpawnTime = 0.f;
	m_type = 3;
}
//cEnemy::~cEnemy() {}


void cLettuce::GetTransform(glm::mat4& transform)
{
	transform = m_eTransform;
}

void cLettuce::SetPosition(glm::vec3& position)
{
	m_eTransform = glm::translate(m_eTransform, position);
}

void cLettuce::GetMeshEntry(sMeshEntry& meshEntry)
{
	meshEntry = m_eMeshEntry;
}

void cLettuce::SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex)
{
	m_eMeshEntry.NumIndices = NumIndices;
	m_eMeshEntry.BaseIndex = BaseIndex;
	m_eMeshEntry.BaseVertex = BaseVertex;
}
void cLettuce::GetColor(glm::vec4& color)
{
	color = m_eColor;
}
void cLettuce::SetColor(glm::vec4& colorIn)
{
	m_eColor = colorIn;
}


void cLettuce::Scale(float scale)
{
	m_eTransform = glm::scale(m_eTransform, glm::vec3(scale, scale, scale));
}

void cLettuce::Update(float dt)
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

cFruit* cLettuce::checkForFruit()
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

int cLettuce::getType()
{
	return m_type;
}

float cLettuce::getCalories()
{
	if (m_hasFruit)
		return m_calories;
	else
		return 0;
}

void cLettuce::setEaten(bool bIsEaten)
{
	m_hasFruit = bIsEaten;
	delete this->m_fruit;
}