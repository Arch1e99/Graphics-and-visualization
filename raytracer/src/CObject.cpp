//
//  CObject.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"
#include "CObject.hpp"


/// \fn intersect(CRay ray)
/// \brief Computes intersection between ray and sphere.
/// \param ray Ray parameters.
/// \return Distance from camera position to the closest intersection point, or negative value.
///
float CSphere::intersect(const CRay& ray) {
    float t = -1;
    glm::vec3 v = ray.pos - pos;

    float A = glm::dot(ray.dir, ray.dir);
    float B = (2 * glm::dot(v, ray.dir));
    float C = (glm::dot(v,v) - (r * r));

    float delta = B * B - 4 * A * C;

    if(delta > 0) {
        float t1 = (-B - sqrt(delta)) / (2 * A);
        float t2 = (-B + sqrt(delta)) / (2 * A);

        if(t1 > 0 && t1 < t2){
            t = t1;
        }else if(t2 > 0 && t2 < t1){
            t = t2;
        }
    }

    return t;
}


/// Normal vector to the sphere surface
/// \fn normal(glm::vec3 hit_pos)
/// \brief Surface normal vector at the intersection point.
/// \param hit_pos Intersection point.
/// \return Normal vector parameters.
///


/*
glm::vec3 CSphere::normal(const glm::vec3& hit_pos) {
    glm::vec3 n = {0,0,0};
    
    return n;
}
*/
// wektor normalny dla kuli
glm::vec3 CSphere::normal(const glm::vec3& hit_pos) {
    glm::vec3 n = glm::normalize(hit_pos - pos);

    return n;
}



/// Computes texture mapping coordinates (u,v).
/// \param normal_vec Normalized normal vector at intersection point.
/// \return (u,v) texture coordinates in <0,1> range.
glm::vec2 CSphere::textureMapping(const glm::vec3& normal_vec) {

    float u = 0.5f + std::asin(normal_vec.x) / M_PI;
    float v = 0.5f - std::asin(normal_vec.y) / M_PI;

    return glm::vec2(u, v);
}



/// \fn intersect(CRay ray)
/// \brief Computes intersection between triangle and sphere.
/// \param ray Ray parameters.
/// \return Distance from camera position to the closest intersection point, or negative value.
///
float CTriangle::intersect(const CRay& ray) {
    const float EPS = 0.0000001f;

    glm::vec3 edge1 = v1 - v0;
    glm::vec3 edge2 = v2 - v0;

    glm::vec3 h = glm::cross(ray.dir, edge2);
    float a = glm::dot(edge1, h);

    if (a > -EPS && a < EPS) {
        return -1.0f;
    }

    float f = 1.0f / a;
    glm::vec3 s = ray.pos - v0;
    float u = f * glm::dot(s, h);

    if (u < 0.0f || u > 1.0f) {
        return -1.0f;
    }

    glm::vec3 q = glm::cross(s, edge1);
    float v = f * glm::dot(ray.dir, q);

    if (v < 0.0f || u + v > 1.0f) {
        return -1.0f;
    }

    float t = f * glm::dot(edge2, q);


    if (t > EPS) {
        return t;
    }

    return -1.0f;
}


/// \fn normal(glm::vec3 hit_pos)
/// \brief Surface normal vector at the intersection point.
/// \param hit_pos Intersection point (not used for triangle).
/// \return Normal vector parameters.
///
glm::vec3 CTriangle::normal(const glm::vec3& hit_pos) {
    glm::vec3 u = v1 - v0;
    glm::vec3 v = v2 - v0;
    glm::vec3 n = glm::normalize(glm::cross(u, v));


    return n;
}




