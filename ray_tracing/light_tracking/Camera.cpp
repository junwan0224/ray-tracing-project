//
//  Camera.cpp
//  light_tracking
//
//  Created by wan andy on 14-9-29.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "Camera.h"
#include "iostream"

using namespace std;

void Camera::set_eye(const Point3D& e){
    eye = e;
}

void Camera::set_lootat(const Point3D& look){
    lookat = look;
}

void Camera::set_up(const Vector3D& u){
    up = u;
}

void Camera::set_exposure_time(float time){
    exposure_time = time;
}

void Camera::compute_uvw(){
    if (eye.x == lookat.x && eye.z == lookat.z){
        if (eye.y > lookat.y){
            w = Vector3D(0, 1, 0);
            u = Vector3D(0, 0, 1);
            v = Vector3D(1, 0, 0);
        }
        else{
            w = Vector3D(0, -1, 0);
            u = Vector3D(0, 0, -1);
            v = Vector3D(-1, 0, 0);
        }
    }
    else{
        w = eye - lookat;
        w.normalize();
        u = up ^ w;
        u.normalize();
        v = w ^ u;
    }
}
