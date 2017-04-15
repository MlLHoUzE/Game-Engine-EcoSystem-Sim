#include "cBunny.h"
#include "global.h"


cBunny::cBunny()
{
	m_eTransform = glm::mat4(1.0f);
	m_eLinearSpeed = 3.33f;
	m_eAngularSpeed = 1.0f;
	m_eMeshEntry = sMeshEntry();
	m_eMeshEntry.BaseIndex = 0;
	m_eMeshEntry.BaseVertex = 0;
	m_eMeshEntry.NumIndices = 0;
	m_calories = 10000;
	m_maxCalories = 10000;
	m_deadCalories = m_maxCalories * 0.05;
	m_reproduceTime = 60.f;
	m_reproduceTimer = 0.0f;
	m_type = 3;
	bActivate = false;
	bIsDead = false;
}
//cEnemy::~cEnemy() {}


void cBunny::GetTransform(glm::mat4& transform)
{
	transform = m_eTransform;
}

void cBunny::SetPosition(glm::vec3& position)
{
	m_eTransform = glm::translate(m_eTransform, position);
}

void cBunny::GetMeshEntry(sMeshEntry& meshEntry)
{
	meshEntry = m_eMeshEntry;
}

void cBunny::SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex)
{
	m_eMeshEntry.NumIndices = NumIndices;
	m_eMeshEntry.BaseIndex = BaseIndex;
	m_eMeshEntry.BaseVertex = BaseVertex;
}
void cBunny::GetColor(glm::vec4& color)
{
	color = m_eColor;
}
void cBunny::SetColor(glm::vec4& colorIn)
{
	m_eColor = colorIn;
}

int cBunny::GetID()
{
	return m_ID;
}

void cBunny::SetID(int ID)
{
	m_ID = ID;
}

void cBunny::Scale(float scale)
{
	m_eTransform = glm::scale(m_eTransform, glm::vec3(scale, scale, scale));
}

void cBunny::Update(float dt)
{
	if (secondCounter > 1)
	{
		
		m_calories -= 50;

		float difference = m_maxCalories - m_calories;
		float percentage = difference / m_maxCalories;
		this->m_eColor.r *= percentage * 100;

		if (m_calories < m_maxCalories / 2 && !bIsDead)
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
		glm::mat4 targetTransform = m_pMediator->FindFood(m_ID, targetID, targetType);
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



void cBunny::setMediator(iMediator* mediator)
{
	m_pMediator = mediator;
}

int cBunny::GetType()
{
	return m_type;
}

float cBunny::getCalories()
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