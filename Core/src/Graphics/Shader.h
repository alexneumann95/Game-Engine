#pragma once

#include "..\Common.h"
#include "..\Maths\mat4.h"

#include <glad\glad.h>
#include <vector>
#include <fstream>
#include <sstream>

namespace Graphics {

	struct GE_API ShaderDesc
	{
		GLenum Type;
		std::string SourceFile;

		ShaderDesc(GLenum type, const std::string& sourceFile) : Type(type), SourceFile(sourceFile)
		{

		}
	};

	class GE_API Shader final
	{
	public:
		Shader(const std::vector<ShaderDesc> descs);
		~Shader();

		void Use() const;
		unsigned int Get() const;

		void SetUniform(const std::string& name, int value);
		void SetUniform(const std::string& name, const Maths::mat4& matrix);
	private:
		void CreateShaderProgram();
		void GetShaderSource(const std::string& file, std::string& source);
		bool CheckShaderCompilation(unsigned int shader);
		bool CheckProgramLinkage();
		void LogShaderCompError(unsigned int shader, const std::string& file);
		void LogProgramLinkError();
	private:
		unsigned int m_Program;
		std::vector<ShaderDesc> m_Descs;
	};

}