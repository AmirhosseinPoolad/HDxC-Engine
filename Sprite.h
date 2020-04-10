#pragma once
#include "shader.h"

class Sprite {
public:
	Sprite(const char* texture_path, Shader* shader);
	~Sprite();
	void SpriteRender(glm::mat4 trans);

private:
	Shader* s_shader;
	int nr_channel, t_width, t_height;
	unsigned int s_VBO;
	unsigned int s_VAO;
	unsigned int s_EBO;
	unsigned int s_texture;
};