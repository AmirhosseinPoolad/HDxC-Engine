#pragma once
#include "shader.h"

class Sprite {
public:
	Sprite(const char* texture_path, Shader* shader, int s_width, int s_height);
	~Sprite();
	void SpriteRender(glm::mat4 trans);

private:
	Shader* s_shader;
	int nr_channel, t_width, t_height;
	int	SCREEN_WIDTH, SCREEN_HEIGHT;
	unsigned int s_VBO;
	unsigned int s_VAO;
	unsigned int s_EBO;
	unsigned int s_texture;
};