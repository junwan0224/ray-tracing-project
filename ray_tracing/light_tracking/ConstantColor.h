//
//  ConstantColor.h
//  light_tracking
//
//  Created by wan andy on 15-1-18.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_ConstantColor_h
#define light_tracking_ConstantColor_h

#include "Texture.h"

class ConstantColor: public Texture {
public:
    ConstantColor (RGBColor ncolor = RGBColor (Color_Red)){
        color = ncolor;
    }
    void set_color (const RGBColor & c){
        color = c;
    }
    virtual RGBColor get_color (const ShadeRec& sr) const{
        return color;
    }
private:
    RGBColor color;
};

#endif
