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
    VAO(const std::vector<Vertex>& vertices)
    {
        glGenVertexArrays(1, &id);
        glBindVertexArray(id);

        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

        // 0th attribute
        // consists of 3 floats
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(0);

        vertexCount = vertices.size();
    }

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