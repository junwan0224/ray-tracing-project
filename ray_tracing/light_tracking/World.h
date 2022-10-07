//
//  World.h
//  light_tracking
//
//  Created by wan andy on 14-8-26.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_World_h
#define light_tracking_World_h

#include "RGBColor.h"
#include "Sphere.h"
#include "ViewPlane.h"
#include "Material.h"
#include "ImageTexture.h"

class Camera;
class Tracer;
class Light;
class GeometricObject;

class World{
public:
    ViewPlane vp;
    RGBColor background_color;
    Tracer* tracer_ptr;
    Camera* camera_ptr;
    Light* ambient_ptr;
    vector<GeometricObject*> object_list;
    vector<Light*> light_list;
public:
    World();
    void build();
    void set_ambient_light (Light* light) {ambient_ptr = light;};
    void add_object (GeometricObject* object);
    void add_light (Light* light);
    void save() const;
    ShadeRec hit_objects (const Ray& ray);
    World& operator = (const World& w);
};

#endif
