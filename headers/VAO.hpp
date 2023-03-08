#pragma once

#include "Shader.hpp"
#include "Vertex.hpp"
#include "libs/glad/include/glad/gl.h"
#include <vector>
#include <iostream>

class VAO
{
private:
    GLuint id;
    int indexCount = 0;
public:
    VAO(const std::vector<Vertex>& vertices, const std::vector<uint>& indices);


    void bind() const
    {
        glBindVertexArray(id);
    }

    void draw(const Shader& shader) const
    {
        shader.use();
        bind();
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
        // glDrawArrays(GL_TRIANGLES, 0, indexCount);
    }
};