#pragma once

#include "..\API.h"

#include <glad\glad.h>
#include <string>
#include <iostream>

namespace Utilities {

	GE_API GLenum GLCheckError(const char* file, int line);
	void APIENTRY GLDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, void *userParam);

}

#define GL_CHECK_ERROR() Utilities::GLCheckError(__FILE__, __LINE__)