#ifndef _SOUND_H_
#define _SOUND_H_

/*****************************************************************************
*
*   Tone definition. Each tone are set up with a value which will give the 
*   right frequency when applied to a 16-bits timer with PWM. These values are based
*   on a CLKcpu running @ 1Mhz.
*
*   First find the frequency for all tones. 
*
*   Formula:    ToneX = Bf * 2^(ToneX/12)
*   
*   ToneX: the actual tone, e.g. C0 = 3
*   Bf: Basefrequency = 220Hz (A)
*
*       
*   E.g: For tone C0 this would be:     C0 = 220 * 2^(3/12)
*                                       C0 = 261,6256...
*
*   Now we must find which value to put in a 16-bits timer with PWM to achieve 
*   this frequency
*
*   Formula:    Timer value = 1Mhz / ToneHz / 2
*
*   E.g: For tone C0 this would be:     Timer value = 1000000 / 261,6256... / 2
*                                       Timer value = 1911
*
*   Set up a 16-bits timer to run at Phase/Freq-correct PWM
*
*****************************************************************************/
#define a   2273        
#define xa  2145        
#define ax  2145        
#define b   2024        
#define c0  1911        
#define xc0 1804        
#define cx0 1804
#define d0  1703
#define xd0 1607
#define dx0 1607
#define e0  1517
#define f0  1432
#define xf0 1351
#define fx0 1351
#define g0  1275
#define xg0 1204
#define gx0 1204
#define a0  1136
#define xa0 1073
#define ax0 1073
#define b0  1012
#define c1  956
#define xc1 902
#define cx1 902
#define d1  851
#define xd1 804
#define dx1 804
#define e1  758
#define f1  716
#define xf1 676
#define fx1 676
#define g1  638
#define xg1 602
#define gx1 602
#define a1  568
#define xa1 536
#define ax1 536
#define b1  506
#define c2  478
#define xc2 451
#define cx2 451
#define d2  426
#define xd2 402
#define dx2 402
#define e2  379
#define f2  356
#define xf2 338
#define fx2 338
#define g2  319
#define xg2 301
#define gx2 301
#define a2  284
#define xa2 268
#define ax2 268
#define b2  253
#define c3  239
#define xc3 225
#define cx3 225
#define d3  213
#define xd3 201
#define dx3 201
#define e3  190
#define f3  179
#define xf3 169
#define fx3 169
#define g3  159
#define xg3 150
#define gx3 150
#define a3  142
#define xa3 134
#define ax3 134
#define b3  127
#define c4  119

#define p   5

// Define songs 

const unsigned short FurElise[] =
 		{
             8,e2, 8,xd2, 8,e2, 8,xd2, 8,e2, 8,b1, 8,d2, 8,c2, 4,a1, 8,p,
             8,c1, 8,e1, 8,a1, 4,b1, 8,p, 8,e1, 8,xg1, 8,b1, 4,c2, 8,p, 8,e1,
             8,e2, 8,xd2, 8,e2, 8,xd2, 8,e2, 8,b1, 8,d2, 8,c2, 4,a1, 8,p, 8,c1,
             8,e1, 8,a1, 4,b1, 8,p, 8,e1, 8,c2, 8,b1, 4,a1, 0x0FFFF
         };
         
const unsigned short Mozart[] =
         {
             16,xf1, 16,e1, 16,xd1, 16,e1, 4,g1, 16,a1, 16,g1, 16,xf1, 16,g1,
             4,b1, 16,c2, 16,b1, 16,xa1, 16,b1, 16,xf2, 16,e2, 16,xd2, 16,e2,
             16,xf2, 16,e2, 16,xd2, 16,e2, 4,g2, 8,e2, 8,g2, 32,d2, 32,e2,
             16,xf2, 8,e2, 8,d2, 8,e2, 32,d2, 32,e2, 16,xf2, 8,e2, 8,d2, 8,e2,
             32,d2, 32,e2, 16,xf2, 8,e2, 8,d2, 8,xc2, 4,b1, 0x0FFFF
         };

const unsigned short Minuet[] =
         {
             4,d2, 8,g1, 8,a1, 8,b1, 8,c2, 4,d2, 4,g1, 4,g1, 4,e2, 8,c2,
             8,d2, 8,e2, 8,xf2, 4,g2, 4,g1, 4,g1, 4,c2, 8,d2, 8,c2, 8,b1,
             8,a1, 4,b1, 8,c2, 8,b1, 8,a1, 8,g1, 4,xf1, 8,g1, 8,a1, 8,b1,
             8,g1, 4,b1, 2,a1, 0x0FFFF
                 };

 const unsigned short AuldLangSyne[] =
         {
             4,g2, 2,c3, 8,c3, 4,c3, 4,e3, 2,d3, 8,c3, 4,d3, 8,e3, 8,d3, 2,c3,
             8,c3, 4,e3, 4,g3, 2,a3, 8,p, 4,a3, 2,g3, 8,e3, 4,e3, 4,c3, 2,d3,
             8,c3, 4,d3, 8,e3, 8,d3, 2,c3, 8,a2, 4,a2, 4,g2, 2,c3, 4,p, 0x0FFFF
           };

 const unsigned short Alert1[] =
         {
             32,400, 32,397, 32,394, 32,391, 32,388, 32,385, 32,382, 32,379,
             32,376, 32,373, 32,370, 32,367, 32,364, 32,361, 32,358, 32,355,
             32,352, 32,349, 32,346, 32,343, 32,340, 32,337, 32,334, 32,331,
             32,328, 32,325, 32,322, 32,319, 32,316, 32,313, 32,310, 32,307,
             32,304, 32,301, 32,298, 32,298, 32,301, 32,304, 32,307, 32,310,
             32,313, 32,316, 32,319, 32,322, 32,325, 32,328, 32,331, 32,334,
             32,337, 32,340, 32,343, 32,346, 32,349, 32,352, 32,355, 32,358,
             32,361, 32,364, 32,367, 32,370, 32,373, 32,376, 32,379, 32,382,
             32,385, 32,388, 32,391, 32,394, 32,397, 32,400, 10000
            };
const unsigned short Alert2[]=
                 {
                 		4,c2, 4,g2, 0x0FFFF
                 };       
#endif
