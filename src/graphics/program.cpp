#include "program.hpp"
#include "graphics/graphics.hpp"

namespace lorentz::graphics
{

#define LORENTZ_PROGRAM_ELEMENT_SIZE       1
#define LORENTZ_PROGRAM_SHADER_STREAM_TYPE const GLchar *const *
#define LORENTZ_PROGRAM_IS_NULL_TERMINATED NULL

    /* Shaders */
    shader_t Shader::compile(std::string path, u32 type)
    {
        std::ifstream shader_file;
        std::string shader_contents;

        shader_file.open(path);

        /* Reading */
        if (shader_file.is_open()) {
            std::stringstream shader_contents_stream;

            shader_contents_stream << shader_file.rdbuf();

            shader_file.close();
            shader_contents = shader_contents_stream.str();
        } else {
            log(ERROR, TAG_SHADERS, "Cannot open %s ", path.c_str());
            return GL_INVALID_VALUE;
        }

        // Because glShaderSource needs address, the casting is here
        const char *shader_code = shader_contents.c_str();

        /* Compiling */
        shader_t shader = glCreateShader(type);
        glShaderSource(
            shader, LORENTZ_PROGRAM_ELEMENT_SIZE,
            (LORENTZ_PROGRAM_SHADER_STREAM_TYPE)&shader_code,
            LORENTZ_PROGRAM_IS_NULL_TERMINATED);
        glCompileShader(shader);

        /* Checking */
        int linked_succesfully;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &linked_succesfully);

        if (!linked_succesfully)
            log(ERROR, TAG_SHADERS, "Cannot compile %s ", path.c_str());

        return shader;
    }

    /* Program */
    Program::Program(std::array<std::string, 2> shaders)
    {
        /* Compilation */
        this->vertex_shader = Shader::compile(shaders.at(0), GL_VERTEX_SHADER);
        this->fragment_shader =
            Shader::compile(shaders.at(1), GL_FRAGMENT_SHADER);

        /* Linking */
        this->create();
    }

    Program::~Program()
    {
        this->destroy();
    }

    void Program::create()
    {
        log(INFO, TAG_SHADERS, "Creating shaders...");

        if (this->vertex_shader == GL_INVALID_VALUE ||
            this->fragment_shader == GL_INVALID_VALUE) {
            log(ERROR, TAG_SHADERS, "Shaders have an invalid value");
        }

        /* Creating */
        this->program = glCreateProgram();

        /* Linking */
        i32 linked_succesfully;
        glAttachShader(this->program, this->vertex_shader);
        glAttachShader(this->program, this->fragment_shader);
        glLinkProgram(this->program);

        /* Checking */
        glGetProgramiv(this->program, GL_LINK_STATUS, &linked_succesfully);

        if (!linked_succesfully)
            log(ERROR, TAG_SHADERS,
                "Cannot link the vertex and fragment shaders.");
    }

    void Program::destroy()
    {
        glDeleteProgram(this->program);
        glDeleteShader(this->vertex_shader);
        glDeleteShader(this->fragment_shader);
    }

    void Program::use()
    {
        glUseProgram(this->program);
    }

} // namespace lorentz::graphics
