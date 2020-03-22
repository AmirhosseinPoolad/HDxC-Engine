#include "GameObject.h"

GameObject::GameObject(Sprite* sprite, Transform* trans) {
	g_sprite = sprite;
	g_transform = trans;
}

void GameObject::Render(glm::mat4 camMat) {
	g_sprite->SpriteRender(g_transform->GetTransMatrix(camMat));
}