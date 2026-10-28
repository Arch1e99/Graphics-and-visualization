//
//  CRayTrace.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"

/// \fn compPrimaryRayMatrix(CCamera cam, glm::mat3& m)
/// \brief Computation of the projection matrix.
/// \param cam Camera parameters.
/// \param m Output projection matrix.
///
bool CRayTrace::compPrimaryRayMatrix(const CCamera& cam, glm::mat3& m) {
    glm::vec3 look = cam.lookp - cam.eyep;
    glm::vec3 u = glm::normalize(glm::cross(cam.up,look));
    glm::vec3 v = glm::normalize(glm::cross(u, look));
    glm::vec3 o = glm::normalize(look) * ((float)cam.width / (2.0f * tan(glm::radians(cam.fov / 2.0f)))) - ((float)cam.width/2.0f * u + (float)cam.height/2.0f * v);
    m = {u,v,o};
    return true;
}


/// \fn rayTrace(CScene scene, CRay& ray, COutput& out)
/// \brief Traces single ray.
/// \param scene Object with all scene components including a camera.
/// \param ray Ray parameter (primary and secondary rays).
/// \param out Object with output color and parameters used in recursion.
///
bool CRayTrace::rayTrace(const CScene& scene, CRay& ray, COutput& out) {

    /// looks for the closest object along the ray path
    float tmin = FLT_MAX;
    float EPS = 0.0001f;
    bool is_intersection = false;
    CObject* hit_obj = nullptr;

    for (auto* obj : scene.objectList) {
        float t = obj->intersect(ray);
        if (t > EPS && t < tmin) {
            tmin = t;
            is_intersection = true;
            hit_obj = obj;
        }
    }
    /// returns false if there are no intersection
    if (!is_intersection) {
        //out.col = glm::vec3(0.0f, 0.0f, 0.0f);
        return false;
    }

    //res.col = glm::vec3(0.0f, 0.5f, 0.0f);
    glm::vec3 n;

    glm::vec3 p = ray.pos + tmin * ray.dir;
    //out.col = glm::vec3(0.0f, 0.0f, 0.0f);

    for (auto light : scene.lightList) {
    out.col = out.col + out.energy * light.color * hit_obj->matAmbient;
    n = hit_obj->normal(p);
    glm::vec3 L = glm::normalize(light.pos - p);
    //ZAD 14



        float dist_to_light = glm::length(light.pos - p);

        CRay shadow_ray;
        shadow_ray.pos = p;
        shadow_ray.dir = L;

        bool is_shadow = false;

        for (auto* shadow_obj : scene.objectList) {
            float t_shadow = shadow_obj->intersect(shadow_ray);

            if (t_shadow > EPS && t_shadow < dist_to_light) {
                is_shadow = true;
                break;
            }
        }

        if (is_shadow) {
            continue;
        }




    float cos_angle = glm::dot(n, L);

    if (cos_angle > 0.001f) {
        out.col = out.col + out.energy * light.color * hit_obj->matDiffuse * cos_angle;
        glm::vec3 h = glm::normalize(L + (-ray.dir));
        float cos_beta = glm::dot(n, h);
        if (cos_beta > 0.001f) {
            out.col = out.col + out.energy * light.color * hit_obj->matSpecular * (float)std::pow(cos_beta, hit_obj->matShininess);
        }
    }
    }

    if(hit_obj->isTexture) {
        glm::vec2 uv = hit_obj->textureMapping(n);
        glm::vec3 tex_col = CImage::getTexel(hit_obj->texture , uv.x, uv.y );
        out.col = out.col * tex_col;
    }







    /// computes 3D position of the intersection point

    /// computes normal vector at intersection point

    /// for each light source defined in the scene

        /// computes if the intersection point is in the shadows

        /// computes diffuse color component

        /// computes specular color component

    /// adds texture for textured spheres

    /// computes ambient color component

    /// if the surface is reflective

        /// if out.tree >= MAX_RAY_TREE return from function

        /// computes the secondary ray parameters (reflected ray)

        /// recursion
        //   rayTrace(scene, secondary_ray, out);
    const int MAX_RAY_TREE = 1;
    const float MIN_RAY_ENERGY = 0.01f;

    if (hit_obj->reflectance > 0.0f && out.tree < MAX_RAY_TREE && out.energy > MIN_RAY_ENERGY) {

        out.tree++;
        out.energy = out.energy * hit_obj->reflectance;

        CRay secondary_ray = reflectedRay(ray, n, p);

        rayTrace(scene, secondary_ray, out);
    }

    return true;
}


/// \fn reflectedRay(CRay ray, glm::vec3 n, glm::vec3 pos)
/// \brief Computes parameters of the ray reflected at the surface point with given normal vector.
/// \param ray Input ray.
/// \param n Surface normal vector.
/// \param pos Position of reflection point.
/// \return Reflected ray.
///
CRay CRayTrace::reflectedRay(const CRay& ray, const glm::vec3& n, const glm::vec3& pos) {
    glm::vec3 v = ray.dir;

    glm::vec3 r = v - 2.0f * glm::dot(v, n) * n;
    CRay reflected_ray;
    reflected_ray.pos = pos;
    reflected_ray.dir = glm::normalize(r);

    return reflected_ray;
}

