#include "Shader.h"
#include "..\Managers\FileManager.h"

namespace Graphics {

	Shader::Shader(const std::vector<ShaderDesc> desc) : m_Descs(desc)
	{
		CreateShaderProgram();
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_Program);
	}

	void Shader::Use() const
	{
		glUseProgram(m_Program);
	}

	unsigned int Shader::Get() const
	{
		return m_Program;
	}

	void Shader::CreateShaderProgram()
	{
		m_Program = glCreateProgram();
		std::vector<unsigned int> shaderIDs;
		
		for (ShaderDesc desc : m_Descs)
		{
			unsigned int shader = glCreateShader(desc.Type);

			std::string source = "";
			GetShaderSource(desc.SourceFile, source);
			if (source == "")
			{
				LogError("Unable to load shader source file: " + desc.SourceFile);
				return;
			}
			const char* shaderSource = source.c_str();
			glShaderSource(shader, 1, &shaderSource, NULL);

			glCompileShader(shader);
			if (!CheckShaderCompilation(shader))
				LogShaderCompError(shader, desc.SourceFile);

			glAttachShader(m_Program, shader);
			shaderIDs.push_back(shader);
		}

		glLinkProgram(m_Program);
		if (!CheckProgramLinkage())
			LogProgramLinkError();

		// Clean up
		for (unsigned int shader : shaderIDs)
		{
			glDetachShader(m_Program, shader);
			glDeleteShader(shader);
		}
	}

	void Shader::GetShaderSource(const std::string& file, std::string& source)
	{
		std::ifstream f(Managers::FileManager::Instance()->GetExeDirectory() + "shaders\\" + file);
		if (f.fail())
			return;

		std::stringstream stream;
		stream << f.rdbuf();
		source = stream.str(); 
		f.close();
	}

	bool Shader::CheckShaderCompilation(unsigned int shader)
	{
		int success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		return (success == GL_TRUE) ? true : false;
	}

	bool Shader::CheckProgramLinkage()
	{
		int success;
		glGetProgramiv(m_Program, GL_LINK_STATUS, &success);
		return (success == GL_TRUE) ? true : false;
	}

	void Shader::LogShaderCompError(unsigned int shader, const std::string& file)
	{
		char infoLog[1024];
		glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
		LogError("Shader failed to compile (" + file + ")! Reason: \n\t" + std::string(infoLog));
	}

	void Shader::LogProgramLinkError()
	{
		char infoLog[1024];
		glGetProgramInfoLog(m_Program, 1024, nullptr, infoLog);
		LogError("Program failed to link! Reason: \n\t" + std::string(infoLog));
	}

}