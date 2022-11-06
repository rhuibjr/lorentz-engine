#include "graphics/mesh.hpp"
#include "graphics/graphics.hpp"

// TODO magic
namespace lorentz::graphics
{
    VBO::VBO()
    {
        glGenBuffers(1, &this->handle);
    }

    void VBO::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, this->handle);
    }

    void VBO::destroy()
    {
    }

    VAO::VAO()
    {
        glGenVertexArrays(1, &this->handle);
    }

    void VAO::bind()
    {
        glBindVertexArray(this->handle);
    }

    void VAO::destroy()
    {
    }

    /* Mesh */
    void Mesh::create()
    {
        this->vbo = VBO();
        this->vao = VAO();
        
        this->vbo.bind();
        this->vao.bind();

        glBufferData(
            GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0],
            GL_STATIC_DRAW);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);  

    }

    void Mesh::use()
    {
        this->vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void Mesh::destroy()
    {
        
    }
    
} // namespace lorentz::graphics
