#pragma once
#include "Sprite.h"
#include "Transform.h"
#include <vector>


class GameObject {
public:
	GameObject(Sprite* sprite, Transform* trans, std::vector<GameObject*>* objList);
	//~GameObject();
	void Render(glm::mat4 camMat);
	Sprite* g_sprite;
	Transform* g_transform;
private:
	std::vector<GameObject*>* objList;
};