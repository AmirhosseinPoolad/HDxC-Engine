//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#include <glad/glad.h> 
#include <GLFW\glfw3.h>
#include <iostream>
#include <math.h>
#include "shader.h"
#include "GameObject.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	/*glm::mat4 model = glm::mat4(1.0f); //local transform matrix
	model = glm::translate(model, glm::vec3(400.0f, 300.0f, 0.0f));
	model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(50, 50, 50));
	

	glm::mat4 projection;
	projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);

	glm::mat4 transform = projection * model;
	*/

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

	//this is how you make a new object
	Shader ourShader("vertex_shader.vert", "fragment_shader.frag"); //you make a shader
	Sprite ourSprite("container.jpg", &ourShader, 800, 600); //you make a sprite
	Transform Trans1(pos1, glm::vec2(32, 32)); //you make the transform
	GameObject Object1(&ourSprite,&Trans1); //you make an object
	//remember that shaders and sprites (and technically transforms) can be reused!

	Transform Trans2(pos2, glm::vec2(64, 64));
	GameObject Object2(&ourSprite, &Trans2);

	Transform Trans3(pos3, glm::vec2(16, 16));
	GameObject Object3(&ourSprite, &Trans3); //1 sprite, 1 shader, 3 objects!
	
	
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT);

		Object1.Render(projection);
		Object2.Render(projection);
		Object3.Render(projection);

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

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}