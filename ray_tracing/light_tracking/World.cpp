//
//  World.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "World.h"
#include "Tracer.h"
#include "GeometricObject.h"
#include "Sphere.h"
#include "Plane.h"
#include "Cylinder.h"
#include "Square.h"
#include "TriangleSurface.h"
#include "TriangleObject.h"
#include "Jittered.h"
#include "Regular_Sampler.h"
#include "PureRandom.h"
#include "MultiJittered.h"
#include "Pinhole.h"
#include "ThinLens.h"
#include "Light.h"
#include "Ambient.h"
#include "AmbientOccuder.h"
#include "Directional.h"
#include "PointLight.h"
#include "Material.h"
#include "Matte.h"
#include "Phong.h"
#include "Reflective.h"
#include "ImageTexture.h"
#include "GridTexture.h"
#include "PlaneMap.h"
#include "CylinderMap.h"
#include "SphericalMap.h"
#include "GridMap.h"
#include "ShadeRec.h"
#include "Constant.h"

using namespace std;

float kHugeValue = 100000;

void build_texture_balls (World & w);
void build_four_balls (World & w);
void build_animals (World & w);
void build_enhance (World & w);

void World::build(){
    build_texture_balls(*this);
    //build_animals(*this);
    //build_enhance(*this);
    //build_four_balls(*this);
}

World::World(): object_list(0), light_list(0){
    tracer_ptr = new Tracer (this);
    camera_ptr = NULL;
    ambient_ptr = new Ambient();
}

void World::add_object(GeometricObject* object){
    object_list.push_back(object);
}

void World::add_light(Light* light){
    light_list.push_back(light);
}

void World::save() const{
    vp.display();
}

ShadeRec World::hit_objects(const Ray& ray){
    ShadeRec sr(*this);
    double t;
    float tmin = kHugeValue;
    Point3D hit_point;
    Normal normal;
    int num_objects = (int)object_list.size();
    Point3D storelocal;
    for (int i = 0; i < num_objects; i++){
        if ( object_list[i]->hit(ray, t, sr) && (t < tmin) ){
            sr.hit_an_object = true;
            tmin = t;
            sr.material_ptr = object_list[i]->get_material();
            sr.hit_point = ray.o + t * ray.d;
            normal = sr.normal;
            storelocal = sr.local_hit_point;
        }
    }
    sr.local_hit_point = storelocal;
    if (sr.hit_an_object)
        sr.normal = normal;
    return sr;
}

World& World::operator = (const World& w){
    vp = w.vp;
    background_color = w.background_color;
    tracer_ptr = w.tracer_ptr;
    return *this;
}

void presetting (World & w){
    w.background_color = RGBColor(Color_Black);
    w.vp.num_samples = 16;
    w.vp.hres = 1300;
    w.vp.vres = 800;
    w.vp.pixel_size = 1.0;
    w.vp.gamma = 1.8;
    w.vp.inv_gamma = 1/w.vp.gamma;
    w.vp.max_depth = 15;
    w.vp.sample_ptr = nullptr;
    vector<RGBColor> temp (w.vp.vres, w.background_color);
    vector<vector<RGBColor>> temp2 (w.vp.hres, temp);
    w.vp.pixel = temp2;
    
    Mapping* newmap = new GridMap (1);
    ImageTexture* i = new ImageTexture ("/Users/michael/Desktop/pic3.jpg");
    i -> setmapping(newmap);
    
    w.vp.set_sampler(new Jittered(w.vp.num_samples));
    w.vp.sample_ptr->generate_samples();
    w.vp.sample_ptr->setup_shuffled_indices();
    
    MultiJittered* ambient_sampler = new MultiJittered (w.vp.num_samples);
    ambient_sampler -> generate_samples();
    ambient_sampler -> setup_shuffled_indices();
    AmbientOccluder* occular_ptr = new AmbientOccluder ();
    occular_ptr -> set_ls(1.0);
    occular_ptr -> set_color(RGBColor(Color_White));
    occular_ptr -> set_min(RGBColor(Color_Black));
    occular_ptr -> set_sampler(ambient_sampler);
    w.set_ambient_light(occular_ptr);
    
    ThinLens* thin_lens_ptr = new ThinLens ();
    thin_lens_ptr->set_eye(Point3D(0, 0, -1000));
    thin_lens_ptr->set_lootat(Point3D(-10, 0, 0));
    thin_lens_ptr->set_up(Vector3D(0, 1, 0));
    thin_lens_ptr->set_view_distance(600.0);
    thin_lens_ptr->set_focal_distance(1000.0);
    thin_lens_ptr->set_lens_radius(1.0);
    thin_lens_ptr->set_zoom(1.0);
    thin_lens_ptr->set_img(i);
    thin_lens_ptr->compute_uvw();
    thin_lens_ptr->set_sampler(new MultiJittered(w.vp.num_samples));
    thin_lens_ptr->sampler_ptr->generate_samples();
    thin_lens_ptr->sampler_ptr->setup_shuffled_indices();
    thin_lens_ptr->sampler_ptr->map_samples_to_unit_disk();
    w.camera_ptr = thin_lens_ptr;
    
    /*
     Pinhole* pinhole_ptr = new Pinhole();
     pinhole_ptr->set_eye(Point3D(300, 400, 500));
     pinhole_ptr->set_lootat(Point3D(0, 0, -50));
     pinhole_ptr->set_up(Vector3D(0, 1, 0));
     pinhole_ptr->set_exposure_time(1.0);
     pinhole_ptr->set_view_distance(400);
     pinhole_ptr->set_zoom(1);
     pinhole_ptr->compute_uvw();
     camera_ptr = pinhole_ptr;
     */
}

void build_four_balls (World & w){
    presetting (w);
    
    Matte* matte_ptr = new Matte ();
    matte_ptr -> set_ka (0.25);
    matte_ptr -> set_kd (0.65);
    matte_ptr -> set_cd (RGBColor(Color_Red));
    Matte* matte_ptr2 = new Matte ();
    matte_ptr2 -> set_ka (0.25);
    matte_ptr2 -> set_kd (0.65);
    matte_ptr2 -> set_cd (RGBColor(Color_KongQueBlue));
    Phong* phong_ptr = new Phong ();
    phong_ptr -> set_ka (0.25);
    phong_ptr -> set_kd (0.65);
    phong_ptr -> set_ks (0.2);
    phong_ptr -> set_cd (RGBColor(Color_White));
    Phong* phong_ptr2 = new Phong ();
    phong_ptr2 -> set_ka (0.25);
    phong_ptr2 -> set_kd (0.6);
    phong_ptr2 -> set_ks (0.4);
    phong_ptr2 -> set_cd (RGBColor(Color_KongQueBlue));
    Reflective* reflective_ptr = new Reflective ();
    reflective_ptr -> set_ka (0.25);
    reflective_ptr -> set_kd (0.5);
    reflective_ptr -> set_cd(RGBColor(Color_White));
    reflective_ptr -> set_ks(0.15);
    reflective_ptr -> set_expg(100);
    reflective_ptr -> set_kr(0.75);
    reflective_ptr -> set_cr(RGBColor (Color_White));
    
    PointLight* light_ptr = new PointLight ();
    light_ptr -> set_loc(800, 800, 600);
    w.add_light(light_ptr);
    PointLight* light_ptr2 = new PointLight ();
    light_ptr2 -> set_loc(-800, 800, 600);
    w.add_light(light_ptr2);
    PointLight* light_ptr3 = new PointLight ();
    light_ptr3 -> set_loc(0, 1600, 2000);
    w.add_light(light_ptr3);
    
    GeometricObject* plane1 = new Plane (Point3D(0, -1500, 0), Vector3D(0, 1, 0));
    GeometricObject* plane2 = new Plane (Point3D(0, 0, 3000), Vector3D(0, 0, -1));
    GeometricObject* sphere1 = new Sphere (Point3D(0, 246.4, 400), 200);
    GeometricObject* sphere2 = new Sphere (Point3D(-200, -100, 400), 200);
    GeometricObject* sphere3 = new Sphere (Point3D(200, -100, 400), 200);
    GeometricObject* sphere4 = new Sphere (Point3D(0, 0, 200), 200);
    plane1 -> set_material(phong_ptr);
    plane2 -> set_material(phong_ptr);
    sphere1 -> set_material(phong_ptr2);
    sphere2 -> set_material(phong_ptr2);
    sphere3 -> set_material(reflective_ptr);
    sphere4 -> set_material(reflective_ptr);
    w.add_object(plane1);
    w.add_object(plane2);
    w.add_object(sphere1);
    w.add_object(sphere2);
    w.add_object(sphere3);
    w.add_object(sphere4);
}

void build_texture_balls (World & w){
    presetting (w);
    
    Mapping* newmap = new CylinderMap ();
    ImageTexture* t1 = new ImageTexture ("/Users/michael/Desktop/pic.jpg");
    t1 -> setmapping(newmap);
    
    GridTexture* t2 = new GridTexture ( );
    t2 -> setlength( 300 );
    
    Mapping* newmap2 = new GridMap (10);
    ImageTexture* t3 = new ImageTexture ("/Users/michael/Desktop/pic2.jpg");
    t3 -> setmapping(newmap2);
    
    Phong* phong_ptr = new Phong ();
    phong_ptr -> set_ka (0.25);
    phong_ptr -> set_kd (0.95);
    phong_ptr -> set_ks (0.2);
    phong_ptr -> set_cd ( RGBColor(Color_KongQueBlue) );
    Phong* phong_ptr2 = new Phong ();
    phong_ptr2 -> set_ka (0.25);
    phong_ptr2 -> set_kd (0.6);
    phong_ptr2 -> set_ks (0.4);
    phong_ptr2 -> set_cd (t1);
    Reflective* reflective_ptr1 = new Reflective ();
    reflective_ptr1 -> set_ka (0.25);
    reflective_ptr1 -> set_kd (0.5);
    reflective_ptr1 -> set_cd(t3);
    reflective_ptr1 -> set_ks(0.15);
    reflective_ptr1 -> set_expg(100);
    reflective_ptr1 -> set_kr(0.75);
    reflective_ptr1 -> set_cr(RGBColor (Color_SkyBlue));
    Reflective* reflective_ptr2 = new Reflective ();
    reflective_ptr2 -> set_ka (0.25);
    reflective_ptr2 -> set_kd (0.5);
    reflective_ptr2 -> set_cd(RGBColor (Color_KongQueBlue));
    reflective_ptr2 -> set_ks(0.15);
    reflective_ptr2 -> set_expg(100);
    reflective_ptr2 -> set_kr(0.75);
    reflective_ptr2 -> set_cr(RGBColor (Color_White));
    
    PointLight* light_ptr = new PointLight ();
    light_ptr -> set_loc(8000, 8000, 6000);
    w.add_light(light_ptr);
    PointLight* light_ptr2 = new PointLight ();
    light_ptr2 -> set_loc(-8000, 8000, 6000);
    w.add_light(light_ptr2);
    PointLight* light_ptr3 = new PointLight ();
    light_ptr3 -> set_loc(0, 16000, 20000);
    w.add_light(light_ptr3);
    PointLight* light_ptr4 = new PointLight ();
    light_ptr4 -> set_loc(0, 0, -10000);
    w.add_light(light_ptr4);
    
    GeometricObject* cylinder = new Cylinder (600, 520, Point3D(0, 500, 2500));
    GeometricObject* triangleo = new TriangleObject ("/Users/michael/My File/Workspace/mesh simplify/test data/bunny.fine.obj", Point3D(-1400, -200, 850), 4000, Vector3D (-1, 0, 0), Vector3D (0, 1, 0), Vector3D (0, 0, -1));
    GeometricObject* triangleo2 = new TriangleObject ("/Users/michael/My File/Workspace/mesh simplify/test data/horse.fine.90k.obj", Point3D(1400, 200, 850), 400, Vector3D (0, 0, 1), Vector3D (-1, 0, 0), Vector3D (0, 1, 0));
    
    GeometricObject* plane1 = new Plane (Point3D(0, -2000, 0), Vector3D(0, 1, 0));
    GeometricObject* plane2 = new Plane (Point3D(0, 0, 8000), Vector3D(0, 0, -1));
    GeometricObject* sphere1 = new Sphere (Point3D(-700, -100, 800), 200);
    GeometricObject* sphere2 = new Sphere (Point3D(-850, -100, 3000), 300);
    GeometricObject* sphere3 = new Sphere (Point3D(700, -100, 800), 200);
    GeometricObject* sphere4 = new Sphere (Point3D(850, -100, 3000), 300);
    plane1 -> set_material(reflective_ptr1);
    plane2 -> set_material(phong_ptr);
    sphere1 -> set_material(reflective_ptr2);
    sphere2 -> set_material(reflective_ptr2);
    sphere3 -> set_material(reflective_ptr2);
    sphere4 -> set_material(reflective_ptr2);
    cylinder -> set_material (phong_ptr2);
    triangleo -> set_material(phong_ptr);
    triangleo2 -> set_material(phong_ptr);
    w.add_object(triangleo);
    w.add_object(triangleo2);
    w.add_object(plane1);
    //w.add_object(plane2);
    w.add_object(cylinder);
    w.add_object(sphere1);
    w.add_object(sphere2);
    w.add_object(sphere3);
    w.add_object(sphere4);
}

void build_animals (World & w){
    presetting (w);
    
    Mapping* newmap = new CylinderMap ();
    ImageTexture* t1 = new ImageTexture ("/Users/michael/Desktop/pic.jpg");
    t1 -> setmapping(newmap);
    
    GridTexture* t2 = new GridTexture ( );
    t2 -> setlength( 300 );
    
    Mapping* newmap2 = new GridMap (10);
    ImageTexture* t3 = new ImageTexture ("/Users/michael/Desktop/pic2.jpg");
    t3 -> setmapping(newmap2);
    
    Phong* phong_ptr = new Phong ();
    phong_ptr -> set_ka (0.25);
    phong_ptr -> set_kd (0.95);
    phong_ptr -> set_ks (0.2);
    phong_ptr -> set_cd ( RGBColor(Color_KongQueBlue) );
    Phong* phong_ptr2 = new Phong ();
    phong_ptr2 -> set_ka (0.25);
    phong_ptr2 -> set_kd (0.6);
    phong_ptr2 -> set_ks (0.4);
    phong_ptr2 -> set_cd (t1);
    Reflective* reflective_ptr1 = new Reflective ();
    reflective_ptr1 -> set_ka (0.25);
    reflective_ptr1 -> set_kd (0.5);
    reflective_ptr1 -> set_cd(t3);
    reflective_ptr1 -> set_ks(0.15);
    reflective_ptr1 -> set_expg(100);
    reflective_ptr1 -> set_kr(0.75);
    reflective_ptr1 -> set_cr(RGBColor (Color_SkyBlue));
    Reflective* reflective_ptr2 = new Reflective ();
    reflective_ptr2 -> set_ka (0.25);
    reflective_ptr2 -> set_kd (0.5);
    reflective_ptr2 -> set_cd(RGBColor (Color_KongQueBlue));
    reflective_ptr2 -> set_ks(0.15);
    reflective_ptr2 -> set_expg(100);
    reflective_ptr2 -> set_kr(0.75);
    reflective_ptr2 -> set_cr(RGBColor (Color_White));
    
    PointLight* light_ptr = new PointLight ();
    light_ptr -> set_loc(8000, 8000, 6000);
    w.add_light(light_ptr);
    PointLight* light_ptr2 = new PointLight ();
    light_ptr2 -> set_loc(-8000, 8000, 6000);
    w.add_light(light_ptr2);
    PointLight* light_ptr3 = new PointLight ();
    light_ptr3 -> set_loc(0, 16000, 20000);
    w.add_light(light_ptr3);
    PointLight* light_ptr4 = new PointLight ();
    light_ptr4 -> set_loc(0, 0, -10000);
    w.add_light(light_ptr4);
    
    GeometricObject* cylinder = new Cylinder (600, 520, Point3D(0, 500, 2500));
    GeometricObject* triangleo = new TriangleObject ("/Users/michael/My File/Workspace/mesh simplify/test data/bunny.fine.obj", Point3D(-1000, -200, 850), 5000, Vector3D (-1, 0, 0), Vector3D (0, 1, 0), Vector3D (0, 0, -1));
    GeometricObject* triangleo2 = new TriangleObject ("/Users/michael/My File/Workspace/mesh simplify/test data/horse.fine.90k.obj", Point3D(1000, 200, 850), 500, Vector3D (0, 0, 1), Vector3D (-1, 0, 0), Vector3D (0, 1, 0));
    
    GeometricObject* plane1 = new Plane (Point3D(0, -2000, 0), Vector3D(0, 1, 0));
    GeometricObject* plane2 = new Plane (Point3D(0, 0, 8000), Vector3D(0, 0, -1));
    GeometricObject* sphere1 = new Sphere (Point3D(-700, -100, 800), 200);
    GeometricObject* sphere2 = new Sphere (Point3D(-850, -100, 3000), 300);
    GeometricObject* sphere3 = new Sphere (Point3D(700, -100, 800), 200);
    GeometricObject* sphere4 = new Sphere (Point3D(850, -100, 3000), 300);
    plane1 -> set_material(reflective_ptr1);
    plane2 -> set_material(phong_ptr);
    sphere1 -> set_material(reflective_ptr2);
    sphere2 -> set_material(reflective_ptr2);
    sphere3 -> set_material(reflective_ptr2);
    sphere4 -> set_material(reflective_ptr2);
    cylinder -> set_material (phong_ptr2);
    triangleo -> set_material(phong_ptr);
    triangleo2 -> set_material(phong_ptr);
    w.add_object(triangleo);
    w.add_object(triangleo2);
    //w.add_object(plane1);
    //w.add_object(plane2);
    //w.add_object(cylinder);
    //w.add_object(sphere1);
    //w.add_object(sphere2);
    //w.add_object(sphere3);
    //w.add_object(sphere4);
}

void build_enhance (World & w){
    presetting (w);
    
    Mapping* newmap = new CylinderMap ();
    ImageTexture* t1 = new ImageTexture ("/Users/michael/Desktop/pic.jpg");
    t1 -> setmapping(newmap);
    
    GridTexture* t2 = new GridTexture ( );
    t2 -> setlength( 300 );
    
    Mapping* newmap2 = new GridMap (10);
    ImageTexture* t3 = new ImageTexture ("/Users/michael/Desktop/pic2.jpg");
    t3 -> setmapping(newmap2);
    
    Phong* phong_ptr = new Phong ();
    phong_ptr -> set_ka (0.25);
    phong_ptr -> set_kd (0.95);
    phong_ptr -> set_ks (0.2);
    phong_ptr -> set_cd ( RGBColor(Color_KongQueBlue) );
    Phong* phong_ptr2 = new Phong ();
    phong_ptr2 -> set_ka (0.25);
    phong_ptr2 -> set_kd (0.6);
    phong_ptr2 -> set_ks (0.4);
    phong_ptr2 -> set_cd (t1);
    Reflective* reflective_ptr1 = new Reflective ();
    reflective_ptr1 -> set_ka (0.25);
    reflective_ptr1 -> set_kd (0.5);
    reflective_ptr1 -> set_cd(t3);
    reflective_ptr1 -> set_ks(0.15);
    reflective_ptr1 -> set_expg(100);
    reflective_ptr1 -> set_kr(0.75);
    reflective_ptr1 -> set_cr(RGBColor (Color_SkyBlue));
    Reflective* reflective_ptr2 = new Reflective ();
    reflective_ptr2 -> set_ka (0.25);
    reflective_ptr2 -> set_kd (0.5);
    reflective_ptr2 -> set_cd(RGBColor (Color_KongQueBlue));
    reflective_ptr2 -> set_ks(0.15);
    reflective_ptr2 -> set_expg(100);
    reflective_ptr2 -> set_kr(0.75);
    reflective_ptr2 -> set_cr(RGBColor (Color_White));
    
    PointLight* light_ptr = new PointLight ();
    light_ptr -> set_loc(8000, 8000, 6000);
    w.add_light(light_ptr);
    PointLight* light_ptr2 = new PointLight ();
    light_ptr2 -> set_loc(-8000, 8000, 6000);
    w.add_light(light_ptr2);
    PointLight* light_ptr3 = new PointLight ();
    light_ptr3 -> set_loc(0, 16000, 20000);
    w.add_light(light_ptr3);
    PointLight* light_ptr4 = new PointLight ();
    light_ptr4 -> set_loc(0, 0, -10000);
    w.add_light(light_ptr4);
    
    GeometricObject* cylinder = new Cylinder (600, 520, Point3D(0, 500, 2500));
    GeometricObject* triangleo = new TriangleObject ("/Users/michael/My File/Workspace/mesh simplify/test data/bunny.fine.obj", Point3D(-1400, -200, 850), 4000, Vector3D (-1, 0, 0), Vector3D (0, 1, 0), Vector3D (0, 0, -1));
    GeometricObject* triangleo2 = new TriangleObject ("/Users/michael/My File/Workspace/mesh simplify/test data/horse.fine.90k.obj", Point3D(1400, 200, 850), 400, Vector3D (0, 0, 1), Vector3D (-1, 0, 0), Vector3D (0, 1, 0));
    
    GeometricObject* plane1 = new Plane (Point3D(0, -2000, 0), Vector3D(0, 1, 0));
    GeometricObject* plane2 = new Plane (Point3D(0, 0, 8000), Vector3D(0, 0, -1));
    GeometricObject* sphere1 = new Sphere (Point3D(-700, -100, 800), 200);
    GeometricObject* sphere2 = new Sphere (Point3D(-850, -100, 3000), 300);
    GeometricObject* sphere3 = new Sphere (Point3D(700, -100, 800), 200);
    GeometricObject* sphere4 = new Sphere (Point3D(850, -100, 3000), 300);
    plane1 -> set_material(reflective_ptr1);
    plane2 -> set_material(phong_ptr);
    sphere1 -> set_material(reflective_ptr2);
    sphere2 -> set_material(reflective_ptr2);
    sphere3 -> set_material(reflective_ptr2);
    sphere4 -> set_material(reflective_ptr2);
    cylinder -> set_material (phong_ptr2);
    triangleo -> set_material(phong_ptr);
    triangleo2 -> set_material(phong_ptr);
    //w.add_object(triangleo);
    //w.add_object(triangleo2);
    w.add_object(plane1);
    //w.add_object(plane2);
    w.add_object(cylinder);
    w.add_object(sphere1);
    w.add_object(sphere2);
    w.add_object(sphere3);
    w.add_object(sphere4);
}

