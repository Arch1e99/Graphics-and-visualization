//
//  CScene.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"

#include<fstream>

/// \fn create(void)
/// \brief Adds components to the scene.
///

void CScene::create() {
    
    lightList.clear(); // clears vector with the light data
    objectList.clear(); // clears vector of pointers to objects
    
    // add camera, light sources, and objects
    cam.eyep = {0,-4,10};
    cam.lookp = {0,0,0};
    cam.up = {0,1,0};
    cam.fov = 50.0f;
    cam.width = 500;
    cam.height = 400;

    /*
    CSphere* sphere = new CSphere({-2.5,1.3,-3}, 1.0);
    objectList.push_back(sphere);
    CSphere* sphere2 = new CSphere({0,0,0}, 1.6);
    objectList.push_back(sphere2);
    */


    /*
    // ZAD 10
    CLight light1(glm::vec3(-3.0f, -2.0f, 8.0f));
    light1.color = glm::vec3(0.6f, 0.6f, 0.6f);
    lightList.push_back(light1);
    // ZAD 10
    // T1 (Red)
    CTriangle* t1 = new CTriangle(glm::vec3(-4.0f, 1.5f, 1.0f), glm::vec3(-2.0f, 2.5f, -1.0f), glm::vec3(-3.5f, 3.5f, 0.0f));
    t1->matAmbient = glm::vec3(0.8f, 0.1f, 0.1f);
    t1->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t1->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t1);

    // T2 (Green)
    CTriangle* t2 = new CTriangle(glm::vec3(-0.5f, 1.5f, -1.0f), glm::vec3(0.5f, 1.5f, -1.0f), glm::vec3(0.0f, 3.5f, -6.0f));
    t2->matAmbient = glm::vec3(0.1f, 0.8f, 0.1f);
    t2->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t2->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t2);

    // T3 (Blue)
    CTriangle* t3 = new CTriangle(glm::vec3(2.0f, 2.0f, 0.0f), glm::vec3(4.0f, 1.5f, -2.0f), glm::vec3(2.5f, 3.5f, 2.0f));
    t3->matAmbient = glm::vec3(0.1f, 0.1f, 0.8f);
    t3->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t3->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t3);

    // T4 (Yellow)
    CTriangle* t4 = new CTriangle(glm::vec3(-4.5f, -1.0f, -3.0f), glm::vec3(-3.5f, 0.5f, -4.0f), glm::vec3(-4.2f, 1.0f, -1.0f));
    t4->matAmbient = glm::vec3(0.8f, 0.8f, 0.1f);
    t4->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t4->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t4);

    // T5 (Magenta)
    CTriangle* t5 = new CTriangle(glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(1.5f, -0.5f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    t5->matAmbient = glm::vec3(0.8f, 0.1f, 0.8f);
    t5->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t5->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t5);

    // T6 (Cyan)
    CTriangle* t6 = new CTriangle(glm::vec3(3.0f, -1.0f, -2.0f), glm::vec3(4.5f, 1.0f, -4.0f), glm::vec3(4.5f, -1.0f, -2.0f));
    t6->matAmbient = glm::vec3(0.1f, 0.8f, 0.8f);
    t6->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t6->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t6);

    // T7 (Orange)
    CTriangle* t7 = new CTriangle(glm::vec3(-3.5f, -2.0f, 1.0f), glm::vec3(-2.0f, -3.5f, -1.0f), glm::vec3(-4.0f, -3.5f, -2.0f));
    t7->matAmbient = glm::vec3(0.9f, 0.5f, 0.1f);
    t7->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t7->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t7);

    // T8 (Dark grey)
    CTriangle* t8 = new CTriangle(glm::vec3(-1.5f, -2.5f, -2.0f), glm::vec3(1.5f, -2.0f, -3.0f), glm::vec3(0.0f, -3.5f, -1.0f));
    t8->matAmbient = glm::vec3(0.2f, 0.2f, 0.2f);
    t8->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t8->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t8);

    // T9 (White)
    CTriangle* t9 = new CTriangle(glm::vec3(2.5f, -2.0f, 2.0f), glm::vec3(3.5f, -4.0f, -1.0f), glm::vec3(3.0f, -1.5f, -4.0f));
    t9->matAmbient = glm::vec3(0.9f, 0.9f, 0.9f);
    t9->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t9->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t9);

    // T10 (Grey)
    CTriangle* t10 = new CTriangle(glm::vec3(-7.0f, -2.0f, -15.0f), glm::vec3(2.0f, 5.0f, -10.0f), glm::vec3(-3.0f, 7.0f, -12.0f));
    t10->matAmbient = glm::vec3(0.7f, 0.7f, 0.7f);
    t10->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
    t10->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(t10);
     */




    //ZAD 12
    /*
    CLight light1(glm::vec3(-3.0f, -2.0f, 8.0f));
    light1.color = glm::vec3(0.6f, 0.6f, 0.6f);
    lightList.push_back(light1);
    */

    /*
       // Ambient
       CSphere* sphere = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
       sphere->matAmbient = glm::vec3(0.5f, 0.0f, 0.0f);
       sphere->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
       sphere->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
       sphere->matShininess = 30.0f;
       objectList.puback(sphere);


       // Diffuse
       CSphere* sphere2 = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
       sphere2->matAmbient = glm::vec3(0.0f, 0.0f, 0.0f);
       sphere2->matDiffuse = glm::vec3(0.7f, 0.0f, 0.0f);
       sphere2->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
       sphere2->matShininess = 0.0f;
       objectList.push_back(sphere2);

       // Specular
       CSphere* sphere3 = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
       sphere3->matAmbient = glm::vec3(0.0f, 0.0f, 0.0f);
       sphere3->matDiffuse = glm::vec3(0.0f, 0.0f, 0.0f);
       sphere3->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
       sphere3->matShininess = 30.0f;
       objectList.push_back(sphere3);


       //Model Blinna_Phonga
       CSphere* sphere4 = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
       sphere4->matAmbient = glm::vec3(0.1f, 0.0f, 0.0f);
       sphere4->matDiffuse = glm::vec3(0.6f, 0.0f, 0.0f);
       sphere4->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
       sphere4->matShininess = 30.0f;
       objectList.push_back(sphere4);

       //Model Blinna_Phonga shininese = 10
       CSphere* sphere5 = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
       sphere5->matAmbient = glm::vec3(0.1f, 0.0f, 0.0f);
       sphere5->matDiffuse = glm::vec3(0.6f, 0.0f, 0.0f);
       sphere5->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
       sphere5->matShininess = 10.0f;
       objectList.push_back(sphere5);

       //Model Blinna_Phonga shininese = 50
       CSphere* sphere6 = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
       sphere6->matAmbient = glm::vec3(0.1f, 0.0f, 0.0f);
       sphere6->matDiffuse = glm::vec3(0.6f, 0.0f, 0.0f);
       sphere6->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
       sphere6->matShininess = 50.0f;
       objectList.push_back(sphere6);

*/
    /*
    //ZAD 13
    CSphere* sphere7 = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
    sphere7->matAmbient = glm::vec3(0.1f, 0.0f, 0.0f);
    sphere7->matDiffuse = glm::vec3(0.6f, 0.0f, 0.0f);
    sphere7->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
    sphere7->matShininess = 30.0f;

    sphere7->isTexture = true;
    sphere7->texture = CImage::createTexture(400, 400);
    objectList.push_back(sphere7);
*/

    //ZAD 14
    /*
    CSphere* s1 = new CSphere(glm::vec3(-1.0f, 0.0f, 3.0f), 0.4f);
    s1->matAmbient = glm::vec3(0.0f, 0.1f, 0.0f);
    s1->matDiffuse = glm::vec3(0.0f, 0.6f, 0.0f);
    s1->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
    s1->matShininess = 30.0f;
    objectList.push_back(s1);

    CSphere* s2 = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
    s2->matAmbient = glm::vec3(0.1f, 0.0f, 0.0f);
    s2->matDiffuse = glm::vec3(0.6f, 0.0f, 0.0f);
    s2->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
    s2->matShininess = 30.0f;
    objectList.push_back(s2);

    CSphere* s3 = new CSphere(glm::vec3(-3.0f, -2.0f, -2.0f), 0.6f);
    s3->matAmbient = glm::vec3(0.0f, 0.0f, 0.1f);
    s3->matDiffuse = glm::vec3(0.0f, 0.0f, 0.6f);
    s3->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
    s3->matShininess = 30.0f;
    objectList.push_back(s3);

    CTriangle* triangle1 = new CTriangle(glm::vec3(5.0f, 5.0f, -5.0f), glm::vec3(-5.0f, 5.0f, -5.0f), glm::vec3(-5.0f, -5.0f, -5.0f));
    triangle1->matAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    triangle1->matDiffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    triangle1->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(triangle1);

    CTriangle* triangle2 = new CTriangle(glm::vec3(5.0f, 5.0f, -5.0f), glm::vec3(-5.0f, -5.0f, -5.0f), glm::vec3(5.0f, -5.0f, -5.0f));
    triangle2->matAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    triangle2->matDiffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    triangle2->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    objectList.push_back(triangle2);
    */

    //ZAD 16 tab 1.10

    CLight light1(glm::vec3(-3.0f, -2.0f, 8.0f));
    light1.color = glm::vec3(0.6f, 0.6f, 0.6f);
    lightList.push_back(light1);

    CSphere* s1zad16 = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
    s1zad16->matAmbient = glm::vec3(0.1f, 0.0f, 0.0f);
    s1zad16->matDiffuse = glm::vec3(0.6f, 0.0f, 0.0f);
    s1zad16->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
    s1zad16->matShininess = 30.0f;
    s1zad16->reflectance = 0;
    objectList.push_back(s1zad16);

    CTriangle* t1zad16 = new CTriangle(glm::vec3(5.0f, 5.0f, -5.0f), glm::vec3(-5.0f, 5.0f, -5.0f), glm::vec3(-5.0f, -5.0f, -5.0f));
    t1zad16->matAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    t1zad16->matDiffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    t1zad16->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    t1zad16->reflectance = 1;
    objectList.push_back(t1zad16);

    CTriangle* t2zad16 = new CTriangle(glm::vec3(5.0f, 5.0f, -5.0f), glm::vec3(-5.0f, -5.0f, -5.0f), glm::vec3(5.0f, -5.0f, -5.0f));
    t2zad16->matAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    t2zad16->matDiffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    t2zad16->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    t2zad16->reflectance = 1;
    objectList.push_back(t2zad16);


    /*
    CLight light1(glm::vec3(-3.0f, -2.0f, 8.0f));
    light1.color = glm::vec3(0.6f, 0.6f, 0.6f);
    lightList.push_back(light1);

    CLight light2(glm::vec3(5.0f, -2.0f, 8.0f));
    light2.color = glm::vec3(0.3f, 0.3f, 0.3f);
    lightList.push_back(light2);

    CSphere* s1zad16 = new CSphere(glm::vec3(-1.0f, 0.0f, 3.0f), 0.4f);
    s1zad16->matAmbient = glm::vec3(0.0f, 0.1f, 0.0f);
    s1zad16->matDiffuse = glm::vec3(0.0f, 0.6f, 0.0f);
    s1zad16->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
    s1zad16->matShininess = 30.0f;
    s1zad16->reflectance = 0;
    objectList.push_back(s1zad16);

    CSphere* s2zad16 = new CSphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.6f);
    s2zad16->matAmbient = glm::vec3(0.1f, 0.0f, 0.0f);
    s2zad16->matDiffuse = glm::vec3(0.6f, 0.0f, 0.0f);
    s2zad16->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
    s2zad16->matShininess = 30.0f;
    s2zad16->reflectance = 0;
    objectList.push_back(s2zad16);

    CSphere* s3zad16 = new CSphere(glm::vec3(-3.0f, -2.0f, -2.0f), 0.6f);
    s3zad16->matAmbient = glm::vec3(0.0f, 0.0f, 0.1f);
    s3zad16->matDiffuse = glm::vec3(0.0f, 0.0f, 0.6f);
    s3zad16->matSpecular = glm::vec3(0.7f, 0.7f, 0.7f);
    s3zad16->matShininess = 30.0f;
    s3zad16->reflectance = 0;
    objectList.push_back(s3zad16);


    CTriangle* t1zad16 = new CTriangle(glm::vec3(5.0f, 5.0f, -5.0f), glm::vec3(-5.0f, 5.0f, -5.0f), glm::vec3(-5.0f, -5.0f, -5.0f));
    t1zad16->matAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    t1zad16->matDiffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    t1zad16->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    t1zad16->reflectance = 1;
    objectList.push_back(t1zad16);

    CTriangle* t2zad16 = new CTriangle(glm::vec3(5.0f, 5.0f, -5.0f), glm::vec3(-5.0f, -5.0f, -5.0f), glm::vec3(5.0f, -5.0f, -5.0f));
    t2zad16->matAmbient = glm::vec3(0.1f, 0.1f, 0.1f);
    t2zad16->matDiffuse = glm::vec3(0.4f, 0.4f, 0.4f);
    t2zad16->matSpecular = glm::vec3(0.0f, 0.0f, 0.0f);
    t2zad16->reflectance = 1;
    objectList.push_back(t2zad16);

*/

}

