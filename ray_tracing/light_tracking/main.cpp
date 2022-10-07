//
//  main.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-21.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include <iostream>

#include "Point2D.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "RGBColor.h"
#include "Ray.h"

#include "GeometricObject.h"
#include "Sampler.h"
#include "Regular_Sampler.h"
#include "Jittered.h"
#include "PureRandom.h"
#include "MultiJittered.h"

#include "Camera.h"
#include "Pinhole.h"
#include "ThinLens.h"

#include "BRDF.h"

#include "Texture.h"
#include "ConstantColor.h"
#include "ImageTexture.h"
#include "SphericalMap.h"

#include "Plane.h"
#include "Sphere.h"

#include "ViewPlane.h"
#include "ShadeRec.h"
#include "Tracer.h"
#include "World.h"

using namespace std;

int main(int argc, const char * argv[])
{
    srand((unsigned)time(NULL));
    World world;
    world.build();
    world.camera_ptr->render_scene(world);
    world.save();
    return 0;
}

