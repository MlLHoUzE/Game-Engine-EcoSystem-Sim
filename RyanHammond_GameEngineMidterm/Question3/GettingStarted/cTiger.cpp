#include "cTiger.h"
#include "global.h"


cTiger::cTiger()
{
	m_eTransform = glm::mat4(1.0f);
	m_eLinearSpeed = 10.f;
	m_eAngularSpeed = 1.0f;
	m_eMeshEntry = sMeshEntry();
	m_eMeshEntry.BaseIndex = 0;
	m_eMeshEntry.BaseVertex = 0;
	m_eMeshEntry.NumIndices = 0;
	m_calories = 500000;
	m_maxCalories = 500000;
	m_reproduceTime = 200.f;
	m_reproduceTimer = 0.0f;
	m_type = 5;

	m_prefs.pref1 = gPreferences::BUNNY;
	m_prefs.pref2 = gPreferences::FOX;
	m_prefs.pref3 = gPreferences::STRAWBERRY;
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
		float lossAmount = m_calories * 0.005f; //* dt;
		m_calories -= lossAmount;

		float difference = m_maxCalories - m_calories;
		float percentage = difference / m_maxCalories;
		this->m_eColor.r += percentage;
	}
	glm::mat4 targetTransform = m_pMediator->FindFood(m_ID, m_prefs.pref1, m_prefs.pref2, m_prefs.pref3);
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
		this->m_eColor.g = 1.0f;
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
