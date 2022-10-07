//
//  ThinLens.h
//  light_tracking
//
//  Created by wan andy on 14-10-5.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__ThinLens__
#define __light_tracking__ThinLens__

#include "Camera.h"
#include "ImageTexture.h"

class ThinLens: public Camera{
public:
    ThinLens();
    void set_lens_radius(float nradius);
    void set_view_distance(float nd);
    void set_focal_distance(float nf);
    void set_zoom(float nzoom);
    void set_sampler(Sampler* sp);
    void set_img (ImageTexture* m){
        img = m;
    }
    Vector3D ray_direction(const Point2D& pixel_point, const Point2D& lens_point) const;
    virtual void render_scene(World& w);
    
    Sampler* sampler_ptr;
private:
    ImageTexture* img;
    float lens_radius;
    float d;
    float f;
    float zoom;
};

#endif /* defined(__light_tracking__ThinLens__) */
