#pragma once
#include "Sprite.h"
#include "Transform.h"


class GameObject {
public:
	GameObject(Sprite* sprite, Transform* trans);
	//~GameObject();
	void Render(glm::mat4 camMat);
	Sprite* g_sprite;
	Transform* g_transform;
};