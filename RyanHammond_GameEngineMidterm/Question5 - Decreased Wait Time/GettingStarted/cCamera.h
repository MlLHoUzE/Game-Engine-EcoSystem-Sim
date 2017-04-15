#ifndef _cCamera_HG_
#define _cCamera_HG_

#include "externals.h"

//class iCamera
//{
//public:
//	virtual ~iCamera() {}
//	virtual void GetProjectionMatrix(glm::mat4& projOut) = 0;
//	virtual void GetViewMatrix(glm::mat4& viewOut) = 0;
//	virtual void GetEyePosition(glm::vec4& eyeOut) = 0;
//};

class cCamera
{
public:
	cCamera();
	~cCamera();

	void GetProjectionMatrix(glm::mat4& projOut);
	void GetViewMatrix(glm::mat4& viewOut);
	void GetEyePosition(glm::vec4& eyeOut);
	void WindowResize(int width, int height);

	void Update(float dt);
	void SetTargetTransform(glm::mat4& targetTransform);
private:
	void UpdateView();
	int mWidth;
	int mHeight;
	glm::mat4 mTargetTransform;

	glm::vec3 mOffset;
	float mZoomSpeed;
	float mDistance;
	float mMaxDistance;
	float mMinDistance;
	glm::mat4 mViewMatrix;

	glm::vec3 mPanOffset;
	float mPanSpeed;
	float mPanDistance;
	float mPanMax;
	float mPanMin;

	

};

#endif