#ifndef GAMEOBJECT_CLASS_H
#define GAMEOBJECT_CLASS_H

#include<iostream>
#include<glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<GLFW/glfw3.h>

#include"Shader.h"
#include"Texture.h"
#include"VAO.h"

class GameObject
{
public:
	glm::vec2 pos;
	glm::vec2 scale;
	glm::mat4 Model;

	GameObject(glm::vec2 Pos, glm::vec2 Scale);

	void Draw(Shader& shader, VAO& VAO, Texture& Tex);
	void Inputs(float dtime);
};

#endif