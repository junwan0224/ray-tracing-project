//
//  ImageTexture.h
//  light_tracking
//
//  Created by wan andy on 15-1-18.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_ImageTexture_h
#define light_tracking_ImageTexture_h

#include "Texture.h"
#include "Mapping.h"
#include "iostream"
#include <vector>

using std::string;
using std::vector;

class ImageTexture: public Texture {
public:
    ImageTexture (string file);
    void setimage (string file);
    void setmapping (Mapping* mapping);
    virtual RGBColor get_color (const ShadeRec & sr) const;
    virtual RGBColor get_color (int i, int j) const;
private:
    int vres;
    int hres;
    vector< vector<RGBColor> > color;
    Mapping * mapping_ptr;
};

#endif
