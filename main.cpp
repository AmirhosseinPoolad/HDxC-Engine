#include <glad/glad.h> 
#include <GLFW\glfw3.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "shader.h"
#include "GameObject.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, GameObject* obj);

int main()
{
	glm::mat4 projection;
	projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}



	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glm::vec3 pos1(400.0f, 300.0f, 0.0f);
	glm::vec3 pos2(300.0f, 300.0f, 0.0f);
	glm::vec3 pos3(200.0f, 400.0f, 0.0f);

	

	std::vector<GameObject*> gameObjects;

	//this is how you make a new object
	Shader ourShader("vertex_shader.vert", "fragment_shader.frag"); //you make a shader
	Sprite ourSprite("container.jpg", &ourShader); //you make a sprite
	Transform Trans1(pos1, glm::vec2(64, 64)); //you make the transform
	GameObject Object1(&ourSprite,&Trans1,&gameObjects); //you make an object
	//the last argument is the list of objects you use for rendering.
	//remember that shaders and sprites (and technically transforms) can be reused!
	
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window,&Object1);

		glClear(GL_COLOR_BUFFER_BIT);

		for (GameObject* obj : gameObjects) {
			obj->Render(projection);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window, GameObject* obj)
{

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}