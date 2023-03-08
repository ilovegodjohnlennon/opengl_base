#include "VAO.hpp"

VAO::VAO(const std::vector<Vertex> &vertices)
{
    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    // 0th attribute
    // consists of 3 floats
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
    glEnableVertexAttribArray(0);

    vertexCount = vertices.size();
}
