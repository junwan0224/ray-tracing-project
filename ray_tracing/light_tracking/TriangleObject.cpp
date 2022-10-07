//
//  TriangleObject.cpp
//  light_tracking
//
//  Created by wan andy on 15-1-23.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#include "Constant.h"
#include "TriangleObject.h"
#include "TriangleSurface.h"
#include "ShadeRec.h"
#include <cassert>

using namespace std;

TriangleObject::TriangleObject (string filename, Point3D p, double s, Vector3D v1, Vector3D v2, Vector3D v3): pos (p), scale(s), surface(0){
    vector< Point3D > points (0);
    const char* ctr = filename.c_str();
    FILE* input = fopen (ctr, "r");
    char c = getc(input);
    bool switchtoface = false;
    double x, y, z;
    unsigned u, v, w;
    vector<unsigned> vec(3, 0);
    Vector3D vecc;
    while (c != EOF){
        switch (c) {
            case '#':
                while (c != '\n')
                    c = getc(input);
                break;
            case '\n':
            case '\r':
                break;
            case 'v':
                assert (!switchtoface);
                fscanf(input, " %lf %lf %lf\n", &x, &y, &z);
                vecc = x * v1 + y * v2 + z * v3;
                x = vecc.x * scale + pos.x;
                y = vecc.y * scale + pos.y;
                z = vecc.z * scale + pos.z;
                points.push_back( Point3D (x, y, z) );
                break;
            case 'f':
                switchtoface = true;
                fscanf(input, " %u %u %u\n", &u, &v, &w);
                surface.push_back( new TriangleSurface( points[u - 1], points[v - 1], points[w - 1] ) );
                break;
            default:
                assert (false);
        }
        c = getc(input);
    }
    int size = (int) points.size();
    double maxx = points[0].x;
    double minx = points[0].x;
    double maxy = points[0].y;
    double miny = points[0].y;
    double maxz = points[0].z;
    double minz = points[0].z;
    for (int i = 1; i < size; ++ i){
        maxx = (points[i].x > maxx ? points[i].x : maxx);
        minx = (points[i].x < minx ? points[i].x : minx);
        maxy = (points[i].y > maxy ? points[i].y : maxy);
        miny = (points[i].y < miny ? points[i].y : miny);
        maxz = (points[i].z > maxz ? points[i].z : maxz);
        minz = (points[i].z < minz ? points[i].z : minz);
    }
    root.points.push_back( maxx );
    root.points.push_back( minx );
    root.points.push_back( maxy );
    root.points.push_back( miny );
    root.points.push_back( maxz );
    root.points.push_back( minz );
    root.level = 0;
    if (surface.size() > 8)
        root.isleave = false;
    
    size = (int) surface.size();
    for (int i = 0; i < size; ++ i)
        root.contains.push_back(surface[i]);
    
    root.split();
    
    points.clear();
    //surface.clear();
}

bool TriangleObject::hit (const Ray& ray, double &tmin, ShadeRec& sr) const {
    return root.hit(ray, tmin, sr);
    /*
    bool hitted = false;
    Normal storenormal = sr.normal;
    for (int i = 0; i < surface.size(); ++ i){
        double t = 0;
        if ( surface[i] -> hit(ray, t, sr) && (t < tmin) ){
            hitted = true;
            assert(false);
            tmin = t;
            storenormal = surface[i] -> get_normal();
        }
    }
    if (hitted){
        sr.normal = storenormal;
        return true;
    }
    else if (hit){
        sr.normal = storenormal;
        return true;
    }
    else
        return false;
     */
}

