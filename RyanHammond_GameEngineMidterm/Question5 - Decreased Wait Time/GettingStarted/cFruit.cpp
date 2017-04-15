#include "cFruit.h"
#include "global.h"

cFruit::cFruit()
{
	this->m_eMeshEntry = gFruitMesh;
	m_eTransform = glm::mat4(1.0f);
}

void cFruit::GetTransform(glm::mat4& transform)
{
	transform = m_eTransform;
}
void cFruit::SetPosition(glm::vec3& position)
{
	m_eTransform = glm::translate(m_eTransform, position);
}
void cFruit::GetMeshEntry(sMeshEntry& meshEntry)
{
	meshEntry = m_eMeshEntry;
}
void cFruit::SetMeshEntry(int NumIndices, int BaseIndex, int BaseVertex)
{

}
void cFruit::GetColor(glm::vec4& color)
{
	color = m_eColor;
}
void cFruit::SetColor(glm::vec4& colorIn)
{
	m_eColor = colorIn;
}
void cFruit::Scale(float scale)
{
	m_eTransform = glm::scale(m_eTransform, glm::vec3(scale, scale, scale));
}