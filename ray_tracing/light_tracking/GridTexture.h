//
//  GridTexture.h
//  light_tracking
//
//  Created by wan andy on 15-1-23.
//  Copyright (c) 2015年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_GridTexture_h
#define light_tracking_GridTexture_h

#include "Texture.h"
#include "RGBColor.h"
#include "ShadeRec.h"

using std::cout;
using std::endl;

class GridTexture: public Texture {
public:
    GridTexture (int l = 40, RGBColor c1 = RGBColor (Color_Red),
                 RGBColor c2 = RGBColor (Color_Black)): gridlength (l), color1 (c1), color2 (c2) {};
    void setcolor1 (RGBColor c1){
        color1 = c1;
    }
    void setcolor2 (RGBColor c2){
        color2 = c2;
    }
    void setlength (int l){
        gridlength = l;
    }
    virtual RGBColor get_color (const ShadeRec& sr) const {
        int pos1 = ( (int) sr.local_hit_point.x % gridlength + gridlength ) % gridlength;
        int pos2 = ( (int) sr.local_hit_point.y % gridlength + gridlength ) % gridlength;
        int b1 = ( 2 * pos1 > gridlength ? 0 : 1 );
        int b2 = ( 2 * pos2 > gridlength ? 0 : 1);
        if ( b1 == b2 )
            return color1;
        else
            return color2;
    }
private:
    int gridlength;
    RGBColor color1;
    RGBColor color2;
};

#endif
