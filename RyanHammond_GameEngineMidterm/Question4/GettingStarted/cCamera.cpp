#include "cCamera.h"
#include "global.h"
#include "Input.h"

cCamera::cCamera()
{
	mWidth = 1000;
	mHeight = 1000;

	mZoomSpeed = 20.f;
	mDistance = 500.f;
	mMinDistance = 5.f;
	mMaxDistance = 1000.f;
	mOffset = glm::vec3(0.f, 100.f, -10.f);
	mOffset = glm::normalize(mOffset);

	mPanOffset = glm::vec3(0.1f, 0.0f, 0.0f);
	mPanOffset = glm::normalize(mPanOffset);
	mPanSpeed = 0.001f;
	mPanDistance = 0.f;
	mPanMax = 0.5f;
	mPanMin = -0.5f;
}
cCamera::~cCamera()
{

}

void cCamera::GetProjectionMatrix(glm::mat4& projOut)
{
	// set up the projection matrix
	projOut = glm::perspective(0.8f, (float)mWidth / (float)mHeight, 0.1f, 100000.f);

	
}
void cCamera::GetViewMatrix(glm::mat4& viewOut)
{
	viewOut = mViewMatrix;
}

void cCamera::GetEyePosition(glm::vec4& eyeOut)
{
	eyeOut.x = mViewMatrix[3].x;
	eyeOut.y = mViewMatrix[3].y;
	eyeOut.z = mViewMatrix[3].z;
	eyeOut.w = 1.f;
}

void cCamera::WindowResize(int width, int height)
{
	mWidth = width;
	mHeight = height;
}

void cCamera::Update(float dt)
{
	bool pressUp = nInput::IsKeyPressed::UP();
	bool pressDown = nInput::IsKeyPressed::DOWN();
	bool pressLeft = nInput::IsKeyPressed::LEFT();
	bool pressRight = nInput::IsKeyPressed::RIGHT();
	//bool pressUp = glfwGetKey(gWindow, GLFW_KEY_UP) == GLFW_PRESS;
	//bool pressDown = glfwGetKey(gWindow, GLFW_KEY_DOWN) == GLFW_PRESS;

	if (pressDown != pressUp)	//if pressing both do nothing, if pressing neither do nothing
	{
		float zoomSpeed = mZoomSpeed;
		if (pressUp) zoomSpeed *= -1.f;
		mDistance += zoomSpeed * dt;
		if (mDistance < mMinDistance) mDistance = mMinDistance;
		if (mDistance > mMaxDistance) mDistance = mMaxDistance;
	}

	/*if (pressRight != pressLeft)
	{
		float panSpeed = mPanSpeed;
		if (pressRight) panSpeed *= -1.f;
		mPanDistance += panSpeed * dt;
		if (mPanDistance < mPanMin) mPanDistance = mPanMin;
		if (mPanDistance > mPanMax) mPanDistance = mPanMax;
	}*/

	if (pressRight)
	{
		//mPanDistance -= mPanSpeed;
		mOffset.x -= mPanSpeed;
		if (mOffset.x < mPanMin) mOffset.x = mPanMin;
	}
	if (pressLeft)
	{
		mOffset.x += mPanSpeed;
		if (mOffset.x > mPanMax) mOffset.x = mPanMax;
	}

	

	UpdateView();
}

void cCamera::UpdateView()
{
	glm::vec3 up(0.f, 1.f, 0.f);

	glm::vec4 eye4(mTargetTransform[3].x, mTargetTransform[3].y, mTargetTransform[3].z, 1.f);
	// set up the view matrix
	glm::vec3 target(mTargetTransform[3].x, mTargetTransform[3].y, mTargetTransform[3].z);
	glm::vec4 offset(mOffset.x, mOffset.y, mOffset.z, 0.f);
	offset = mTargetTransform * offset;
	offset = glm::normalize(offset) * mDistance;	//in case of scaling renormalize
	glm::vec3 eye(target.x + offset.x, target.y + offset.y, target.z + offset.z);
	mViewMatrix = glm::lookAtRH(eye, target, up);
}
void cCamera::SetTargetTransform(glm::mat4& targetTransform)
{
	mTargetTransform = targetTransform;
}