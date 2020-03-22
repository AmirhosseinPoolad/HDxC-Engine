#pragma once

class Transform {

public:
	Transform(glm::vec3 pos, glm::vec2 spriteScale);
	void Translate(glm::vec3 pos);
	void Rotate(float deg, glm::vec3 axis);
	void Scale(glm::vec3 scale);
	glm::mat4 GetTransMatrix(glm::mat4 cameraMatrix);
	glm::vec3 position; // please don't change this directly!

private:
	glm::mat4 modelMatrix;
	float width;
	float height;
};