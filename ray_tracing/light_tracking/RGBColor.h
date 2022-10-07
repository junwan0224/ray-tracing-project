//
//  RGBColor.h
//  light_tracking
//
//  Created by wan andy on 14-8-22.
//  Copyright (c) 2014年 Wan Andy. All rights reserved.
//

#ifndef light_tracking_RGBColor_h
#define light_tracking_RGBColor_h

//                               R      G     B
#define Color_Black        0.0,    0.0,   0.0    //黑色
#define Color_IvoryBlack  0.16,   0.14,  0.13    //象牙黑
#define Color_Gray         0.75,  0.75,  0.75    //灰色
#define Color_ColdGray    0.50,  0.54,  0.53    //冷灰
#define Color_SlateGray   0.44,  0.50,  0.41    //石板灰
#define Color_WarmGray  0.50,  0.50,  0.41    //暖灰
#define Color_SkyBlue     0.53,  0.81,   0.92   //天空蓝
#define Color_KongQueBlue 0.2,  0.63,  0.79   //孔雀蓝
#define Color_White        1.0,    1.0,    1.0    //白色
#define Color_StoneBlue   0.42,  0.35,  0.80   //石板蓝
#define Color_Cobalt       0.24,  0.35,  0.67     //钴色
#define Color_MyPavement 0.38, 0.38,  0.38  //自定义路面颜色
#define Color_Orange      0.99,  0.5,    0.25  //桔黄色
#define Color_SoftOrange 0.96, 0.87,   0.70    //淡黄色
#define Color_Red          1.00,  0.00,  0.00    //红色

class RGBColor{
public:
    RGBColor (float rr=0, float gg=0, float bb=0): r(rr), g(gg), b(bb) {};
    RGBColor& operator = (const RGBColor& color);
    RGBColor& operator += (const RGBColor& color);
    RGBColor& operator -= (const RGBColor& color);
    RGBColor& operator *= (const RGBColor& color);
    RGBColor& operator *= (float a);
    RGBColor& operator /= (float a);
    float r, g, b;
};

RGBColor max_to_one (const RGBColor& color);
RGBColor operator + (const RGBColor& color1, const RGBColor& color2);
RGBColor operator - (const RGBColor& color1, const RGBColor& color2);
RGBColor operator * (const RGBColor& color1, const RGBColor& color2);
RGBColor operator * (const RGBColor& color, float a);
RGBColor operator * (float a, const RGBColor& color);
RGBColor operator / (const RGBColor& color, float a);
RGBColor operator ^ (const RGBColor& color, float p);

/*
 #define Color_heise          0.0000  0.0000  0.0000  //  黑色
 #define Color_xiangyahei     0.1608  0.1412  0.1294  //  象牙黑
 #define Color_huise          0.7529  0.7529  0.7529,   0.0  //  灰色
 #define Color_lenghuise      0.5020  0.5412  0.5294,   0.0  //  冷灰
 #define Color_shibanhuise    0.4392  0.5020  0.4118,   0.0  //  石板灰
 #define Color_nuanhuise      0.5020  0.5020  0.4118,   0.0  //  暖灰色
 #define Color_gudongbaise    1.0000  1.0000  1.0000,   0.0  //  白色
 #define Color_meihongse      0.8667  0.6275  0.8667,   0.0  //梅红色
 #define Color_danzise        0.8549  0.4392  0.8392,   0.0  //淡紫色
 #define Color_huzise         0.6000  0.2000  0.9804,   0.0  //湖紫色
 #define Color_jasoase        0.6275  0.4000  0.8275,   0.0  //jasoa
 #define Color_ziluolanse     0.5412  0.1686  0.8863,   0.0  //紫罗蓝色
 #define Color_zise           0.6275  0.1255  0.9412,   0.0  //紫色
 #define Color_tianlanse      0.9412  1.0000  1.0000,   0.0  //  天蓝色
 #define Color_baiyanse       0.9608  0.9608  0.9608,   0.0  //  白烟
 #define Color_baixingrense   1.0000  0.9216  0.8039,   0.0  //  白杏仁
 #define Color_gudongbaise    0.9804  0.9216  0.8431,   0.0  //  古董白
 #define Color_cornsilk       1.0000  0.9725  0.8627,   0.0  //  cornsilk
 #define Color_dankese     0.9882  0.9020  0.7882,   0.0  //  蛋壳色
 #define Color_huabaise     1.0000  0.9804  0.9412,   0.0  //  花白
 #define Color_gainsboro    0.8627  0.8627  0.8627,   0.0  //  gainsboro
 #define Color_ghostWhite   0.9725  0.9725  1.0000 ,   0.0  //  ghostWhite
 #define Color_milouchengse  0.9412  1.0000  0.9412,   0.0  //  蜜露橙
 #define Color_xiangyabaise   0.9804  1.0000  0.9412,   0.0  //  象牙白
 #define Color_yamase      0.9804  0.9412  0.9020,   0.0  //  亚麻色
 #define Color_navajoWhite    1.0000  0.8706  0.6784,   0.0  //  navajoWhite
 #define Color_old_lace    0.9922  0.9608  0.9020,   0.0  //  old lace
 #define Color_gehongse     0.8902  0.0902  0.0510,   0.0  //  镉红
 #define Color_gechengse   1.0000  0.3804  0.0118 ,   0.0  //  镉橙色
 #define Color_chengse    1.0000  0.3804  0.0000 ,   0.0  //  橙色
 #define Color_guase     0.8902  0.6588  0.4118  ,   0.0  //  瓜色
 #define Color_huanghuase   0.8549  0.6471  0.4118 ,   0.0  // 黄花色
 #define Color_jinhuangse   1.0000  0.8431  0.0000,   0.0  //  金黄色
 #define Color_forumgold   1.0000  0.8902  0.5176,   0.0  //  forumgold
 #define Color_dougello   0.9216  0.5569  0.3333,   0.0  //  dougello
 #define Color_gehuangse   1.0000  0.6000  0.0706 ,   0.0  //  镉黄
 #define Color_xiangjiaose   0.8902  0.8118  0.3412,  0.0  //  香蕉色
 #define Color_huangse    1.0000  1.0000  0.0000,   0.0  //  黄色
 #define Color_shenhongse   1.0000  0.0000  1.0000 ,   0.0  //  深红色
 #define Color_juhongse      1.0000  0.2706  0.000,    0.0  //  桔红
 #define Color_fanqiehongse  1.0000  0.3882  0.2784,   0.0  //  蕃茄红
 #define Color_chenghongse  0.9804  0.5020  0.4471,   0.0  //  橙红色
 #define Color_caomeise    0.5294  0.1490  0.3412,   0.0  //  草莓色
 #define Color_zhuanhongse   0.6118  0.4000  0.1216,   0.0  //  砖红
 #define Color_hongse         1.0000  0.0000  0.0000,   0.0  //  红色
 #define Color_xuebaise       1.0000  0.9804  0.9804 ,   0.0  //  雪白
 #define Color_haibeikese     1.0000  0.9608  0.9333,   0.0  //  海贝壳色
 #define Color_fenhongse    1.0000  0.7529  0.7961,   0.0  //  粉红
 #define Color_lise       0.6902  0.1882  0.3765 ,   0.0   //  栗色
 #define Color_yinduhongse   0.6902  0.0902  0.1216,   0.0  //  印度红
 #define Color_naihuozhuanhongse  0.6980  0.1333  0.1333,   0.0  //  耐火砖红
 #define Color_shanhuse       1.0000  0.4980  0.3137 ,   0.0    //  珊瑚色
 #define Color_wuzeimozongse  0.3686  0.1490  0.0706 ,   0.0  // 乌贼墨棕色
 #define Color_biaotuzongse  0.4510  0.2902  0.0706,   0.0  //  标土棕
 #define Color_xiaogongtuse  0.7804  0.3804  0.0784,   0.0  // 肖贡土色
 #define Color_meiguihong   0.7373  0.5608  0.5608,   0.0  //  玫瑰红
 #define Color_huanghese    0.9412  0.9020  0.5490,   0.0  //  黄褐色
 #define Color_ruse      1.0000  0.4902  0.2510,   0.0     //  肉色
 #define Color_qiaokelise   0.8235  0.4118  0.1176,   0.0  //  巧克力色
 #define Color_duanzongtuse  0.5294  0.2000  0.1412,   0.0  //  锻棕土色
 #define Color_duannonghuangtuse 0.5412  0.2118  0.0588 ,   0.0  //  锻浓黄土色
 #define Color_mise     0.6392  0.5804  0.5020,   0.0    //  米色
 #define Color_zongse    0.5020  0.1647  0.1647,   0.0   //  棕色
 #define Color_danhuangse  0.9608  0.8706  0.7020,   0.0  // 淡黄色
 #define Color_juhuangse   1.0000  0.5020  0.0000,   0.0  //  桔黄色
 #define Color_huluobuse   0.9294  0.5686  0.1294,   0.0  //  胡萝卜色
 #define Color_lanse      0.0000  0.0000  1.0000,   0.0    // 蓝色
 #define Color_zonghese    0.8235  0.7059  0.5490,   0.0  //  棕褐色
 #define Color_sazongse    0.9569  0.6431  0.3765,   0.0  //  沙棕色
 #define Color_mazongse    0.5451  0.2706  0.0745 ,   0.0  //  马棕色
 #define Color_hese      0.6275  0.3216  0.1765,   0.0   //  赫色
 #define Color_guse     0.2392  0.3490  0.6706,   0.0    //  钴色
 #define Color_dodger_blue  0.1176  0.5647  1.0000,   0.0  // dodger_blue
 #define Color_jackie_blue  0.0431  0.0902  0.2745,   0.0  //  jackie_blue
 #define Color_menglan    0.0118  0.6588  0.6196,   0.0    //  锰蓝色
 #define Color_shenlanse   0.0980  0.0980  0.4392,   0.0  //深蓝色
 #define Color_qianhuilanse 0.6902  0.8784  0.9020,   0.0  // 浅灰蓝色
 #define Color_tulerqiyuse  0.0000  0.7804  0.5490,   0.0  //  土耳其玉色
 #define Color_kongquelan  0.2000  0.6314  0.7882 ,   0.0  //孔雀蓝
 #define Color_pinlan    0.2549  0.4118  0.8824,   0.0  //  品蓝色
 #define Color_shibanlan   0.4157  0.3529  0.8039,   0.0  //  石板蓝色
 #define Color_tianlanse   0.5294  0.8078  0.9216,   0.0  //  天蓝色
 #define Color_qingse    0.0000  1.0000  1.0000,   0.0    //  青色
 #define Color_lvtuse    0.2196  0.3686  0.0588 ,   0.0  //  绿土色
 #define Color_dianqingse  0.0314  0.1804  0.3294,   0.0  //  靛青
 #define Color_bilvse    0.4980  1.0000  0.8314,   0.0   // 碧绿色
 #define Color_qinglvse   0.2510  0.8784  0.8157,   0.0  //  青绿色
 #define Color_lvse     0.0000  1.0000  0.0000 ,   0.0   //  绿色
 #define Color_anlvse    0.1882  0.5020  0.0784,   0.0   //  暗绿色
 #define Color_hailvse    0.1804  0.5451  0.3412,   0.0   //  海绿色
 #define Color_nenlvse    0.0000  1.0000  0.4980 ,   0.0  // 嫩绿色
 #define Color_huanglvse   0.4980  1.0000  0.0000,   0.0  //  黄绿色
 #define Color_gulvse    0.2392  0.5686  0.2510,   0.0   //  钴绿色
 #define Color_cuilvse    0.0000  0.7882  0.3412,   0.0  // 翠绿色
 #define Color_shenlinlv   0.1333  0.5451  0.1333,   0.0  //  森林绿
 #define Color_caodilvse   0.4863  0.9882  0.0000,   0.0  //  草地绿
 #define Color_suanchenglv  0.1961  0.8039  0.1961,   0.0  //  酸橙绿
 #define Color_bohese    0.7412  0.9882  0.7882,   0.0    //  薄荷色
 #define Color_caolvse    0.4196  0.5569  0.1373,   0.0   //  草绿色
*/

#endif
