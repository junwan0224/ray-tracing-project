//
//  Square.h
//  light_tracking
//
//  Created by wan andy on 15-1-23.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__Square__
#define __light_tracking__Square__

#include "Point3D.h"
#include "Vector3D.h"
#include "GeometricObject.h"
#include "TriangleSurface.h"
#include "Plane.h"
#include <vector>

class Ray;
class Material;
using std::vector;

class KdSquare {
public:
    vector<double> points;
    KdSquare* children1;
    KdSquare* children2;
    unsigned level;
    bool isleave;
    vector<TriangleSurface *> contains; // this is preset by father
public:
    KdSquare (): points(0), level(0), isleave(true), contains(0) {
        children1 = nullptr;
        children2 = nullptr;
    }
    KdSquare(double maxx, double minx, double maxy, double miny, double maxz, double minz, double l);
    ~ KdSquare (){
        if (isleave){
            for (int i = 0; i < contains.size(); ++ i)
                delete contains[i];
        }
        else {
            delete children1;
            delete children2;
        }
    }
    void split ();
    bool hit (const Ray& ray, double& tmin, ShadeRec& sr, bool func = false) const;
    bool squarehit(const Ray& ray) const;
    constexpr static double kEpsilon = 0.000025;
    constexpr static unsigned stopnum = 8;
};

#endif /* defined(__light_tracking__Square__) */
