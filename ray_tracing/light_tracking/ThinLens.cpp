//
//  ThinLens.cpp
//  light_tracking
//
//  Created by wan andy on 14-10-5.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Tracer.h"
#include "iostream"
#include "ThinLens.h"

using std::cout;
using std::endl;

ThinLens::ThinLens(){
    lens_radius = d = f = zoom = 0;
    Point3D temp;
    Vector3D ttemp;
    lookat = eye = temp;
    u = v = w = up = ttemp;
    sampler_ptr = nullptr;
}

Vector3D ThinLens::ray_direction(const Point2D& pixel_point, const Point2D& lens_point) const{
    Point2D p (pixel_point.x*f/d, pixel_point.y*f/d);
    Vector3D dir = (p.x - lens_point.x)*u + (p.y - lens_point.y)*v - f*w;
    dir.normalize();
    return dir;
}

void ThinLens::render_scene(World& w){
    Ray ray;
    ViewPlane& vp = w.vp;
    Point2D sp, pp, dp, lp;
    vp.pixel_size /= zoom;
    
    for (int i = 0; i < vp.hres; i++){
        cout << i << endl;
        for (int j = 0; j < vp.vres; j++){
            
            bool success = false;
            for (int n = 0; n < vp.num_samples; n++){
                sp = vp.sample_ptr->sample_unit_square();
                pp.x = vp.pixel_size*( i - 0.5*vp.hres + sp.x );
                pp.y = vp.pixel_size*( j - 0.5*vp.vres + sp.y );
                dp = sampler_ptr->sample_unit_disk();
                lp.x = dp.x * lens_radius;
                lp.y = dp.y * lens_radius;
                
                ray.o = eye + lp.x*u + lp.y*v;
                ray.d = ray_direction(pp, lp);
                bool s = false;
                vp.pixel[i][j] += w.tracer_ptr->tracer_ray(ray, s, 0);
                success = success || s;
            }
            vp.pixel[i][j] /= vp.num_samples;
            if (!success)
                vp.pixel[i][j] = img -> get_color( i, j);
            
        }
    }
}

void ThinLens::set_sampler(Sampler* sp){
    if (sampler_ptr){
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    sampler_ptr = sp;
    sampler_ptr -> map_samples_to_unit_disk();
}

void ThinLens::set_view_distance(float nd){
    d = nd;
}

void ThinLens::set_focal_distance(float nf){
    f = nf;
}

void ThinLens::set_lens_radius(float nradius){
    lens_radius = nradius;
}

void ThinLens::set_zoom(float nzoom){
    zoom = nzoom;
}