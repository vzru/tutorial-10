// RU ZHANG 100421055 //
// Alvin Aniwa 100603501 //
// Gurmukh Sandhu 100624009 //
// Kyle Disante 100617178 //
#pragma once

#include "GameObject.h"
#include "HTRLoader.h"
#include "TTK\OBJMesh.h"

// Forward declare the HTRLoader class
// This is necessary because SkinnedGameObject references HTRLoader and HTRLoader references SkinnedGameObject
class HTRLoader;

class SkinnedGameObject : public GameObject
{
	// Let the HTRLoader class access private and protected member variables
	friend class HTRLoader;

protected:
	int m_pCurrentFrame;
	HTRLoader* m_pHTRAnimation;
	JointDescriptor* m_pJointAnimation; // The animation for this specific joint

	std::shared_ptr<TTK::OBJMesh> m_pBindMesh; // Mesh in t-pose
	std::shared_ptr<TTK::OBJMesh> m_pSkinnedMesh;

public:
	SkinnedGameObject();
	~SkinnedGameObject();

	void setXRayJoints(bool xray);

	bool m_pPlaying, m_pDrawMesh, m_pDrawBindPose, m_pXrayJoints;

	void initializeSkeletonFromHTR(std::string htrFilePath, std::string skinWeightFilePath, std::shared_ptr<TTK::OBJMesh> bindMesh);

	glm::mat4 m_pJointToBindMat;
	glm::mat4 getJointToBindMatrix();

	virtual void update(float dt);
	void draw();
};