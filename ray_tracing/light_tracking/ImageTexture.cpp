//
//  ImageTexture.cpp
//  light_tracking
//
//  Created by wan andy on 15-1-18.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#include "Constant.h"
#include "ImageTexture.h"
#include "IncludeCImg.h"
#include <vector>

using std::vector;
using namespace std;
using namespace cimg_library;

ImageTexture::ImageTexture(string file): color(0) {
    const char * ctr = file.c_str();
    CImg<unsigned char> image (ctr);
    vres = image.width();
    hres = image.height();
    mapping_ptr = nullptr;
    for (int i = 0; i < hres; ++ i){
        color.push_back( vector<RGBColor> (0) );
        for (int j = 0; j < vres; ++ j){
            float r = image(j, i, 0, 0) / 255.0;
            float g = image(j, i, 0, 1) / 255.0;
            float b = image(j, i, 0, 2) / 255.0;
            color[i].push_back( RGBColor(r, g, b) );
        }
    }
    image.clear();
};

void ImageTexture::setimage (string file){
    color.clear();
    const char * ctr = file.c_str();
    CImg<unsigned char> image (ctr);
    vres = image.width();
    hres = image.height();
    for (int i = 0; i < hres; ++ i){
        color.push_back( vector<RGBColor> (0) );
        for (int j = 0; j < vres; ++ j){
            float r = image(i, j, 0, 0) / 255.0;
            float g = image(i, j, 0, 1) / 255.0;
            float b = image(i, j, 0, 2) / 255.0;
            color[i].push_back( RGBColor(r, g, b) );
        }
    }
}

void ImageTexture::setmapping (Mapping* mapping){
    if (mapping_ptr){
        delete mapping_ptr;
        mapping_ptr = nullptr;
    }
    mapping_ptr = mapping;
}

RGBColor ImageTexture::get_color (int i, int j) const {
    int row = i % hres;
    int column = j % vres;
    return color[row][column];
}

RGBColor ImageTexture::get_color (const ShadeRec& sr) const {
    int row, column;
    if (mapping_ptr != NULL){
        bool success = mapping_ptr -> get_pixel_coordinates (sr.local_hit_point, hres, vres, row, column);
        if (success)
            return color[row][column];
    }
    return RGBColor(Color_SkyBlue);
}
