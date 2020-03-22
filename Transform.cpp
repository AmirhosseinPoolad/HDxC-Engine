#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Transform.h"

Transform::Transform(glm::vec3 pos, glm::vec2 spriteScale) {
	modelMatrix = glm::mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, pos);
	position = pos;
	modelMatrix = glm::scale(modelMatrix, glm::vec3(spriteScale, 1.0f));
	width = spriteScale.x;
	height = spriteScale.y;
}

void Transform::Translate(glm::vec3 pos) {
	modelMatrix = glm::translate(modelMatrix, pos);
	position += pos;
}

void Transform::Rotate(float deg, glm::vec3 axis) {
	modelMatrix = glm::rotate(modelMatrix, glm::radians(deg), axis);
}

void Transform::Scale(glm::vec3 scale) {
	modelMatrix = glm::scale(modelMatrix, scale);
}
glm::mat4 Transform::GetTransMatrix(glm::mat4 cameraMatrix) {
	return cameraMatrix * modelMatrix;
	//return glm::value_ptr(transform);
}