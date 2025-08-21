#ifndef SPRITE_RENDER_CLASS_H
#define SPRITE_RENDER_CLASS_H

#include<glad/glad.h>	
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include"Shader.h"
#include"Texture.h"

class Sprite_Render
{
	public:
		Sprite_Render(Shader &s);
		~Sprite_Render();

		void Draw(Texture &texture, glm::vec2 position,
			glm::vec2 size = glm::vec2(1.0f, 1.0f), float rotate = 0.0f,
			glm::vec3 color = glm::vec3(1.0f));

	private:
		Shader &shader;
		GLuint quadVAO;
};

#endif