#ifndef COLLISIONS_CLASS_H
#define COLLISIONS_CLASS_H

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include"GameObject.h"

class Collisions
{
	public:
		bool hasCollided(GameObject& ball, GameObject& paddle);
		Collisions();

};


#endif 

