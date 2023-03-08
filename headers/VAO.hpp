#pragma once

#include "Shader.hpp"
#include "Vertex.hpp"
#include "libs/glad/include/glad/gl.h"
#include <vector>

class VAO
{
private:
    GLuint id = 0;
    int vertexCount = 0;
public:
    VAO(const std::vector<Vertex>& vertices);


    void bind() const
    {
        glBindVertexArray(id);
    }

    void draw(const Shader& shader) const
    {
        shader.use();
        bind();
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }
};