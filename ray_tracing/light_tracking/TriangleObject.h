//
//  TriangleObject.h
//  light_tracking
//
//  Created by wan andy on 15-1-23.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef __light_tracking__TriangleObject__
#define __light_tracking__TriangleObject__

#include "GeometricObject.h"
#include "Point3D.h"
#include "Square.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Triangle {
    Triangle (unsigned p11, unsigned p22, unsigned p33): p1 (p11), p2 (p22), p3 (p33) {};
    unsigned p1;
    unsigned p2;
    unsigned p3;
};

class TriangleObject: public GeometricObject {
public:
    TriangleObject (string filename, Point3D p, double s,
                    Vector3D v1 = Vector3D (1, 0, 0), Vector3D v2 = Vector3D (0, 1, 0),
                    Vector3D v3 = Vector3D (0, 0, 1));
    virtual bool shadow_hit (const Ray& ray, float &tmin) const { return true; };
    virtual bool hit (const Ray& ray, double &tmin, ShadeRec& sr) const;
    virtual double get_kEpsilon() const { return kEpsilon;};
private:
    KdSquare root;
    vector< TriangleSurface* > surface;
    Point3D pos;
    double scale;
    constexpr static double kEpsilon = 0.000025;
};



#endif /* defined(__light_tracking__TriangleObject__) */
