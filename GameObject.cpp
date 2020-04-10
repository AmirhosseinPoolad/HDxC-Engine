#include "GameObject.h"
#include <vector>

GameObject::GameObject(Sprite* sprite, Transform* trans, std::vector<GameObject*>* objs) {
	g_sprite = sprite;
	g_transform = trans;
	objList = objs;
	objs->push_back(this);
}

void GameObject::Render(glm::mat4 camMat) {
	g_sprite->SpriteRender(g_transform->GetTransMatrix(camMat));
}