//
//  Square.cpp
//  light_tracking
//
//  Created by wan andy on 15-1-23.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#include "Square.h"
#include "ShadeRec.h"
#include <map>
#include <cmath>
#include <iostream>
#include <cassert>

using std::multimap;
using std::pair;
using std::cout;
using std::endl;

KdSquare::KdSquare(double maxx, double minx, double maxy, double miny, double maxz, double minz, double l): points(0), contains(0) {
    points.push_back(maxx);
    points.push_back(minx);
    points.push_back(maxy);
    points.push_back(miny);
    points.push_back(maxz);
    points.push_back(minz);
    level = l;
    isleave = true;
    children1 = nullptr;
    children2 = nullptr;
}

void KdSquare::split() {
    cout << level << endl;
    if (isleave)
        return;
    
    int i = level % 3;
    multimap <double, TriangleSurface *> mapping;
    int size = (int) contains.size();
    cout << "start mapping: " << size << endl;
    if (i == 0)
        for (int j = 0; j < size; ++ j)
            mapping.insert( pair <double, TriangleSurface*> (contains[j] -> center . x, contains[j]) );
    else if (i == 1)
        for (int j = 0; j < size; ++ j)
            mapping.insert( pair <double, TriangleSurface*> (contains[j] -> center . y, contains[j]) );
    else
        for (int j = 0; j < size; ++ j)
            mapping.insert( pair <double, TriangleSurface*> (contains[j] -> center . z, contains[j]) );
    cout << "finish mapping" << endl;
    
    multimap<double, TriangleSurface*>::iterator iter = mapping.begin();
    multimap<double, TriangleSurface*>::iterator iterdiv = mapping.begin();
    multimap<double, TriangleSurface*>::iterator end = mapping.end();
    double maxx = iter -> second -> maxx();
    double minx = iter -> second -> minx();
    double maxy = iter -> second -> maxy();
    double miny = iter -> second -> miny();
    double maxz = iter -> second -> maxz();
    double minz = iter -> second -> minz();
    int num = 1;
    unsigned creteria = size / 2;
    while (num < creteria){
        ++ iter;
        ++ num;
        double tmaxx = iter -> second -> maxx();
        double tminx = iter -> second -> minx();
        double tmaxy = iter -> second -> maxy();
        double tminy = iter -> second -> miny();
        double tmaxz = iter -> second -> maxz();
        double tminz = iter -> second -> minz();
        maxx = ( tmaxx > maxx ? tmaxx  : maxx ) ;
        minx = ( tminx < minx ? tminx  : minx ) ;
        maxy = ( tmaxy > maxy ? tmaxy  : maxy ) ;
        miny = ( tminy < miny ? tminy  : miny ) ;
        maxz = ( tmaxz > maxz ? tmaxz  : maxz ) ;
        minz = ( tminz < minz ? tminz  : minz ) ;
    }
    cout << "   finish dividing 1" << endl;
    children1 = new KdSquare (maxx, minx, maxy, miny, maxz, minz, level + 1);
    
    iterdiv = ++ iter;
    ++ num;
    maxx = iter -> second -> maxx();
    minx = iter -> second -> minx();
    maxy = iter -> second -> maxy();
    miny = iter -> second -> miny();
    maxz = iter -> second -> maxz();
    minz = iter -> second -> minz();
    
    while (iter != end){
        ++ iter;
        if (iter == end)
            break;
        ++ num;
        double tmaxx = iter -> second -> maxx();
        double tminx = iter -> second -> minx();
        double tmaxy = iter -> second -> maxy();
        double tminy = iter -> second -> miny();
        double tmaxz = iter -> second -> maxz();
        double tminz = iter -> second -> minz();
        maxx = ( tmaxx > maxx ? tmaxx  : maxx ) ;
        minx = ( tminx < minx ? tminx  : minx ) ;
        maxy = ( tmaxy > maxy ? tmaxy  : maxy ) ;
        miny = ( tminy < miny ? tminy  : miny ) ;
        maxz = ( tmaxz > maxz ? tmaxz  : maxz ) ;
        minz = ( tminz < minz ? tminz  : minz ) ;
    }
    cout << "   finish dividing 2" << endl;
    children2 = new KdSquare (maxx, minx, maxy, miny, maxz, minz, level + 1);
    cout << children2 -> points[1];
    
    num = 0;
    iter = mapping.begin();
    while (iter != iterdiv){
        children1 -> contains . push_back(iter -> second);
        ++ iter;
        ++ num;
    }
    cout << "   finish sizing 1: " << children1 -> contains.size() << endl;
    while (iter != end){
        children2 -> contains . push_back(iter -> second);
        ++ iter;
        ++ num;
    }
    cout << "   finish sizing 2: " << children2 -> contains.size() << endl;
    if (children1 -> contains . size() > stopnum)
        children1 -> isleave = false;
    if (children2 -> contains . size() > stopnum)
        children2 -> isleave = false;
    mapping.clear();
    contains.clear();
    children1 -> split();
    children2 -> split();
}

bool KdSquare::squarehit(const Ray& ray) const{
    double t1 = (points[0] - ray.o.x) / ray.d.x ;
    double t2 = (points[1] - ray.o.x) / ray.d.x ;
    if (ray.d.x == 0){
        t1 = INFINITY;
        t2 = -INFINITY;
    }
    double t3 = (points[2] - ray.o.y) / ray.d.y ;
    double t4 = (points[3] - ray.o.y) / ray.d.y ;
    if (ray.d.y == 0){
        t3 = INFINITY;
        t4 = -INFINITY;
    }
    double t5 = (points[4] - ray.o.z) / ray.d.z ;
    double t6 = (points[5] - ray.o.z) / ray.d.z ;
    if (ray.d.z == 0){
        t5 = INFINITY;
        t6 = -INFINITY;
    }
    double temp = 0;
    if (t1 < t2){
        temp = t1;
        t1 = t2;
        t2 = temp;
    }
    if (t3 < t4){
        temp = t3;
        t3 = t4;
        t4 = temp;
    }
    if (t5 < t6){
        temp = t5;
        t5 = t6;
        t6 = temp;
    }
    double tminu = (t2 > t4 ? t2 : t4);
    tminu = (tminu > t6 ? tminu : t6);
    double tmaxu = (t1 < t3 ? t1 : t3);
    tmaxu = (tmaxu < t5 ? tmaxu : t5);
    if (tminu < tmaxu && tminu > kEpsilon)
        return true;
    else
        return false;
}

bool KdSquare::hit (const Ray& ray, double& tmin, ShadeRec& sr, bool func) const{
    tmin = INFINITY;
    if (isleave){
        if ( ! squarehit(ray) )
            return false;
        bool hitted = false;
        int size = (int) contains.size();
        Normal storenormal;
        for (int i = 0; i < size; ++ i){
            double t = 0;
            if ( contains[i] -> hit(ray, t, sr) && (t < tmin) ){
                hitted = true;
                tmin = t;
                storenormal = sr.normal;
            }
        }
        if (hitted){
            sr.normal = storenormal;
            return true;
        }
        else
            return false;
    }
    if ( ! squarehit(ray) )
        return false;
    Normal storenormal;
    bool hitted = false;
    double t = 0;
    if ( children1 -> hit(ray, t, sr, func) ){
        tmin = t;
        storenormal = sr.normal;
        hitted = true;
    }
    if ( children2 -> hit(ray, t, sr, func) ){
        sr.normal = ( t < tmin ? sr.normal : storenormal);
        tmin = (t < tmin ? t : tmin);
        hitted = true;
    }
    else
        sr.normal = storenormal;
    return hitted;
}