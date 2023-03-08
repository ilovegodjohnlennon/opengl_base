#pragma once

#include "VAO.hpp"
#include "Texture.hpp"


class PlaneMesh
{
private:
    VAO vao;
    Texture texture;

public:
    PlaneMesh(const std::vector<VertexPos>& vertices, const std::string& texturePath):
        vao({{vertices[0], 0.0f, 0.0f},
             {vertices[1], 1.0f, 0.0f},
             {vertices[2], 1.0f, 1.0f},
             {vertices[3], 0.0f, 1.0f}},
             {0U, 1U, 2U, 
              0U, 2U, 3U}),
        texture(texturePath)
    {

    }

    void draw(const Shader& shader)
    {
        texture.bind();
        vao.draw(shader);
    }
};