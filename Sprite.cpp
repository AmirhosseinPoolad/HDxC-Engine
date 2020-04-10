#include "Sprite.h"
#include <glad/glad.h> 
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


Sprite::Sprite(const char* texture_path, Shader* shader) {
	s_shader = shader;

	glGenBuffers(1, &s_VBO); //generating the VBO, VAO and EBO
	glGenVertexArrays(1, &s_VAO);
	glBindVertexArray(s_VAO);
	glGenBuffers(1, &s_EBO);

	unsigned char* data = stbi_load("container.jpg", &t_width, &t_height, &nr_channel, 0);

	glGenTextures(1, &s_texture);
	glBindTexture(GL_TEXTURE_2D, s_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, t_width, t_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(s_texture);
	stbi_image_free(data);

	//hard coded for now, change later
	float vertices[] = {
		// positions                   uv coords
		  0.5f,  0.5f, 0.0f,           1.0f, 1.0f,
		  0.5f, -0.5f, 0.0f,           1.0f, 0.0f,
		 -0.5f,  0.5f, 0.0f,           0.0f, 1.0f,
		 -0.5f, -0.5f, 0.0f,           0.0f, 0.0f
	};

	unsigned int indices[] = {
	0, 1, 2,
	1, 2, 3
	};

	glBindBuffer(GL_ARRAY_BUFFER, s_VBO); //bind the vbo so the vao knows about it later
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //put vertex data in vbo
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_EBO); // same, but with the vao
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); //put indices in ebo
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); //tells the vao how to proccess vertex position data.
	glEnableVertexAttribArray(0); //actually enable the attrib pointer above, so it gets to the vertex shader
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float))); //uv coord data
	glEnableVertexAttribArray(1);

}

Sprite::~Sprite() {
	glDeleteVertexArrays(1, &s_VAO);
	glDeleteBuffers(1, &s_VBO);
	glDeleteBuffers(1, &s_EBO);
}

void Sprite::SpriteRender(glm::mat4 trans) {
	s_shader->use();
	s_shader->setMat4("transform", trans);
	glBindVertexArray(s_VAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, s_texture);
	s_shader->setInt("texture", 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}