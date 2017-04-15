#include "cTiger.h"
#include "global.h"


cTiger::cTiger()
{
	m_eTransform = glm::mat4(1.0f);
	m_eLinearSpeed = 6.f;
	m_eAngularSpeed = 1.0f;
	m_eMeshEntry = sMeshEntry();
	m_eMeshEntry.BaseIndex = 0;
	m_eMeshEntry.BaseVertex = 0;
	m_eMeshEntry.NumIndices = 0;
	m_calories = 500000;
	m_maxCalories = 500000;
	m_deadCalories = m_maxCalories * 0.05;
	m_reproduceTime = 200.f;
	m_reproduceTimer = 0.0f;
	m_type = 6;
	bActivate = false;
	m_prefs.pref1 = gPreferences::BUNNY;
	m_prefs.pref2 = gPreferences::FOX;
	m_prefs.pref3 = gPreferences::STRAWBERRY;
	bIsDead = false;
}
//cEnemy::~cEnemy() {}


void cTiger::GetTransform(glm::mat4& transform)
{
	transform = m_eTransform;
}

void cTiger::SetPosition(glm::vec3& position)
{
	m_eTransform = glm::translate(m_eTransform, position);
}

void cTiger::GetMeshEntry(sMeshEntry& meshEntry)
{
	meshEntry = m_eMeshEntry;
}

void cTiger::SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex)
{
	m_eMeshEntry.NumIndices = NumIndices;
	m_eMeshEntry.BaseIndex = BaseIndex;
	m_eMeshEntry.BaseVertex = BaseVertex;
}
void cTiger::GetColor(glm::vec4& color)
{
	color = m_eColor;
}
void cTiger::SetColor(glm::vec4& colorIn)
{
	m_eColor = colorIn;
}

int cTiger::GetID()
{
	return m_ID;
}

void cTiger::SetID(int ID)
{
	m_ID = ID;
}

void cTiger::Scale(float scale)
{
	m_eTransform = glm::scale(m_eTransform, glm::vec3(scale, scale, scale));
}

void cTiger::Update(float dt)
{
	if (secondCounter > 1)
	{
		
		m_calories -= 2500;

		float difference = m_maxCalories - m_calories;
		float percentage = difference / m_maxCalories;
		this->m_eColor.r *= percentage * 100;
		if (m_calories < m_maxCalories * 0.9f && !bIsDead)
			bActivate = true;
		if (m_calories < 0)
		{
			bIsDead = true;
			bActivate = false;
		}
		
	}

	
	if (bActivate && !bIsDead)
	{
		m_reproduceTimer += dt;
		if (m_reproduceTimer > m_reproduceTime)
		{
			m_pMediator->spawnAnimal(m_ID);
			m_reproduceTimer = 0;
		}
		int targetID = -1;
		int targetType = -1;
		glm::mat4 targetTransform = m_pMediator->FindFood(m_ID, m_prefs.pref1, m_prefs.pref2, m_prefs.pref3, targetID, targetType);
		if (targetTransform != glm::mat4(NULL))
		{
			glm::vec3 direction;
			glm::vec3 targetPosition = glm::vec3(targetTransform[3].x, targetTransform[3].y, targetTransform[3].z);
			glm::vec3 myPos = glm::vec3(m_eTransform[3].x, m_eTransform[3].y, m_eTransform[3].z);

			direction = glm::normalize(targetPosition - myPos);

			float linearSpeed = m_eLinearSpeed;

			m_eTransform = glm::translate(m_eTransform, direction * (linearSpeed * dt));
		}
		if (glm::abs(targetTransform[3].x - m_eTransform[3].x) < 0.1f && glm::abs(targetTransform[3].z - m_eTransform[3].z) < 0.1f)
		{
			float caloriesGained = 0;
			caloriesGained = m_pMediator->eat(m_ID, targetID, targetType);
			m_calories += caloriesGained;
		}
	}
}

void cTiger::setMediator(iMediator* mediator)
{
	m_pMediator = mediator;
}

int cTiger::GetType()
{
	return m_type;
}

float cTiger::getCalories()
{
	if (m_calories < m_deadCalories)
	{
		return m_deadCalories;
	}
	else
	{
		return m_calories;
	}
}