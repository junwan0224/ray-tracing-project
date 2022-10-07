//
//  RGBColor.cpp
//  light_tracking
//
//  Created by wan andy on 14-8-30.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#include "RGBColor.h"

RGBColor max_to_one (const RGBColor& color){
    float max_value = 0;
    max_value = (color.r > color.g ? color.r : color.g);
    max_value = (color.b > max_value ? color.b : max_value);
    if (max_value > 1)
        return color / max_value;
    else
        return color;
}

RGBColor operator + (const RGBColor& color1, const RGBColor& color2){
    RGBColor outp (color1.r+color2.r, color1.g+color2.g, color1.b+color2.b);
    return outp;
}

RGBColor operator - (const RGBColor& color1, const RGBColor& color2){
    RGBColor outp (color1.r-color2.r, color1.g-color2.g, color1.b-color2.b);
    return outp;
}

RGBColor operator * (const RGBColor& color1, const RGBColor& color2){
    RGBColor outp (color1.r*color2.r, color1.g*color2.g, color1.b*color2.b);
    return outp;
}

RGBColor operator * (const RGBColor& color, float a){
    RGBColor outp (color.r*a, color.g*a, color.b*a);
    return outp;
}

RGBColor operator * (float a, const RGBColor& color){
    RGBColor outp (color.r*a, color.g*a, color.b*a);
    return outp;
}

RGBColor operator / (const RGBColor& color, float a){
    RGBColor outp (color.r/a, color.g/a, color.b/a);
    return outp;
}

RGBColor operator ^ (const RGBColor& color, float p){
    RGBColor outp (color.r, color.g, color.b);
    for (int i=1;i<p;i++){
        outp.r *= color.r;
        outp.g *= color.g;
        outp.b *= color.b;
    }
    return outp;
}

RGBColor& RGBColor::operator += (const RGBColor& color){
    r += color.r;
    g += color.g;
    b += color.b;
    return *this;
}

RGBColor& RGBColor::operator -= (const RGBColor& color){
    r -= color.r;
    g -= color.g;
    b -= color.b;
    return *this;
}

RGBColor& RGBColor::operator *= (const RGBColor& color){
    r *= color.r;
    g *= color.g;
    b *= color.b;
    return *this;
}

RGBColor& RGBColor::operator *= (float a){
    r *= a;
    g *= a;
    b *= a;
    return *this;
}

RGBColor& RGBColor::operator /= (float a){
    r /= a;
    g /= a;
    b /= a;
    return *this;
}

RGBColor& RGBColor::operator = (const RGBColor& color){
    r = color.r;
    g = color.g;
    b = color.b;
    return *this;
}