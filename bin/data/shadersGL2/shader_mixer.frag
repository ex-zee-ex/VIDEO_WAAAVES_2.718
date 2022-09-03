#version 120
const float PI=3.1415926535;
const float TWO_PI=6.2831855;
//NEXT UP
//PIXELS FOR CH2



uniform sampler2DRect ch1Tex;
uniform sampler2DRect ch2Tex;

uniform sampler2DRect fb0;
uniform sampler2DRect fb1;
uniform sampler2DRect fb2;
uniform sampler2DRect fb3;

uniform sampler2DRect fb0Mask;
uniform sampler2DRect fb1Mask;
uniform sampler2DRect fb2Mask;
uniform sampler2DRect fb3Mask;

//ch1 NEW
uniform vec2 ch1Dimensions;
uniform float ch1AspectRatio;
uniform vec2 ch1Center;

uniform float ch1Scale;
uniform vec3 ch1HsbAttenuate;
uniform float ch1QuantizeAmount;
uniform float ch1QuantizeAmountDenom;
uniform int ch1QuantizeSwitch;
uniform int ch1HueInvert;
uniform int ch1SaturationInvert;
uniform int ch1BrightInvert;
uniform int ch1HMirror;
uniform int ch1VMirror;

uniform int ch1PixelSwitch;
uniform int ch1XPixelScale;
uniform int ch1YPixelScale;
uniform float ch1PixelMix;
uniform float ch1PixelBrightscale;


//ch2 NEW
uniform vec2 ch2Dimensions;
uniform float ch2AspectRatio;
uniform vec2 ch2Center;

uniform float ch2Scale;
uniform vec3 ch2HsbAttenuate;
uniform float ch2QuantizeAmount;
uniform float ch2QuantizeAmountDenom;
uniform int ch2QuantizeSwitch;
uniform int ch2HueInvert;
uniform int ch2SaturationInvert;
uniform int ch2BrightInvert;

//mixnkey
uniform int ch2KeyOrder;
uniform int ch2KeyMode;
uniform int ch2MixType;
uniform int ch2MixOverflow;

uniform float ch2LumakeyLevel;
uniform float ch2ChromakeyRed;
uniform float ch2ChromakeyGreen;
uniform float ch2ChromakeyBlue;
uniform float ch2KeyThreshold;
uniform float ch2KeySoft;
uniform float ch2Mix;

uniform int ch2PixelSwitch;
uniform int ch2XPixelScale;
uniform int ch2YPixelScale;
uniform float ch2PixelMix;
uniform float ch2PixelBrightscale;

//fb0
uniform float fb0LumakeyLevel;
uniform float fb0KeyThreshold;
uniform float fb0ChromakeyRed;
uniform float fb0ChromakeyGreen;
uniform float fb0ChromakeyBlue;
uniform int fb0KeyMode;
uniform float fb0KeySoft;
uniform	float fb0Mix;
uniform	int fb0MixType;
uniform int fb0KeyOrder;
uniform int fb0MixOverflow;

uniform float fb0MaskX;
uniform float fb0MaskY;
uniform float fb0MaskZ;
uniform float fb0MaskRotate;
uniform float fb0MaskTileAmount;
uniform int fb0MaskTileMode;
uniform int fb0MaskTexmod;
uniform float fb0MaskTexmodOffset;
uniform int fb0MaskTexmodQuantizeAmount;
uniform float fb0MaskTexmodQuantizeInvert;
uniform float fb0MaskTexmodQuantizeMix;

uniform vec3 fb0HsbInvert;

uniform vec3 fb0HsbOffset;
uniform vec3 fb0HsbAttenuate;
uniform float fb0HueShaper;
uniform vec3 fb0PowMap;

uniform vec3 fb0ColorQuantize;
uniform vec3 fb0ColorQuantizeDenom;
uniform vec3 fb0ColorQuantizeMix;
uniform float fb0HueDitherMix;
uniform float fb0HueDitherAmount;
uniform float fb0SaturationDitherMix;
uniform float fb0SaturationDitherAmount;
uniform float fb0BrightDitherMix;
uniform float fb0BrightDitherAmount;

uniform int fb0SaturationOverflow;
uniform int fb0BrightOverflow;

uniform vec3 fb0_rescale;
uniform float fb0Rotate;
uniform vec4 fb0ShearMatrix;
uniform int fb0RotateMode;
uniform float fb0FisheyeAmount;
uniform vec2 fb0FisheyeCenter;
uniform float fb0SpiralAmount;
uniform float fb0SpiralAngle;
uniform vec2 fb0SpiralCenter;
uniform float fb0KaleidoscopeSegments;
uniform float fb0KaleidoscopeSlice;

//fb0 tex mod
//to do color quantize texmods we will need to do some division lol

uniform float fb0LumakeyLevelTexmod;
uniform float fb0ChromakeyRedTexmod;
uniform float fb0ChromakeyGreenTexmod;
uniform float fb0ChromakeyBlueTexmod;
uniform float fb0KeyThresholdTexmod;
uniform float fb0KeySoftTexmod;
uniform float fb0MixTexmod;

uniform float fb0MaskXTexmod;
uniform float fb0MaskYTexmod;
uniform float fb0MaskZTexmod;
uniform float fb0MaskRotateTexmod;
uniform float fb0MaskTileAmountTexmod;

uniform vec3 fb0HsbOffsetTexmod;
uniform vec3 fb0HsbAttenuateTexmod;
uniform vec3 fb0HsbPowMapTexmod;
uniform float fb0HueShaperTexmod;

uniform vec3 fb0ColorQuantizeTexmod;
uniform vec3 fb0ColorQuantizeDenomTexmod;
uniform vec3 fb0ColorQuantizeMixTexmod;

uniform float fb0HueDitherMixTexmod;
uniform float fb0HueDitherAmountTexmod;
uniform float fb0SaturationDitherMixTexmod;
uniform float fb0SaturationDitherAmountTexmod;
uniform float fb0BrightDitherMixTexmod;
uniform float fb0BrightDitherAmountTexmod;

uniform vec3 fb0RescaleTexmod;
uniform float fb0RotateTexmod;
uniform vec4 fb0ShearMatrixTexmod;

uniform float fb0FisheyeAmountTexmod;
uniform vec2 fb0FisheyeCenterTexmod;
uniform float fb0SpiralAmountTexmod;
uniform float fb0SpiralAngleTexmod;
uniform vec2 fb0SpiralCenterTexmod;
uniform float fb0KaleidoscopeSegmentsTexmod;
uniform float fb0KaleidoscopeSliceTexmod;

uniform vec2 fb0TexmodLogic;

uniform int fb0PixelSwitch;
uniform int fb0XPixelScale;
uniform int fb0YPixelScale;
uniform float fb0PixelMix;
uniform float fb0PixelBrightscale;

uniform vec2 fb0_pixel_texmod_logic;
uniform int fb0XPixelScaleTexmod;
uniform int fb0YPixelScaleTexmod;
uniform float fb0PixelMixTexmod;
uniform float fb0PixelBrightscaleTexmod;










//fb1
uniform float fb1LumakeyLevel;
uniform float fb1KeyThreshold;
uniform float fb1ChromakeyRed;
uniform float fb1ChromakeyGreen;
uniform float fb1ChromakeyBlue;
uniform int fb1KeyMode;
uniform float fb1KeySoft;
uniform    float fb1Mix;
uniform    int fb1MixType;
uniform int fb1KeyOrder;
uniform int fb1MixOverflow;

uniform float fb1MaskX;
uniform float fb1MaskY;
uniform float fb1MaskZ;
uniform float fb1MaskRotate;
uniform float fb1MaskTileAmount;
uniform int fb1MaskTileMode;
uniform int fb1MaskTexmod;
uniform float fb1MaskTexmodOffset;
uniform int fb1MaskTexmodQuantizeAmount;
uniform float fb1MaskTexmodQuantizeInvert;
uniform float fb1MaskTexmodQuantizeMix;

uniform vec3 fb1HsbInvert;

uniform vec3 fb1HsbOffset;
uniform vec3 fb1HsbAttenuate;
uniform float fb1HueShaper;
uniform vec3 fb1PowMap;

uniform vec3 fb1ColorQuantize;
uniform vec3 fb1ColorQuantizeDenom;
uniform vec3 fb1ColorQuantizeMix;
uniform float fb1HueDitherMix;
uniform float fb1HueDitherAmount;
uniform float fb1SaturationDitherMix;
uniform float fb1SaturationDitherAmount;
uniform float fb1BrightDitherMix;
uniform float fb1BrightDitherAmount;

uniform int fb1SaturationOverflow;
uniform int fb1BrightOverflow;

uniform vec3 fb1_rescale;
uniform float fb1Rotate;
uniform vec4 fb1ShearMatrix;
uniform int fb1RotateMode;
uniform float fb1FisheyeAmount;
uniform vec2 fb1FisheyeCenter;
uniform float fb1SpiralAmount;
uniform float fb1SpiralAngle;
uniform vec2 fb1SpiralCenter;
uniform float fb1KaleidoscopeSegments;
uniform float fb1KaleidoscopeSlice;

//fb1 tex mod
//to do color quantize texmods we will need to do some division lol

uniform float fb1LumakeyLevelTexmod;
uniform float fb1ChromakeyRedTexmod;
uniform float fb1ChromakeyGreenTexmod;
uniform float fb1ChromakeyBlueTexmod;
uniform float fb1KeyThresholdTexmod;
uniform float fb1KeySoftTexmod;
uniform float fb1MixTexmod;

uniform float fb1MaskXTexmod;
uniform float fb1MaskYTexmod;
uniform float fb1MaskZTexmod;
uniform float fb1MaskRotateTexmod;
uniform float fb1MaskTileAmountTexmod;

uniform vec3 fb1HsbOffsetTexmod;
uniform vec3 fb1HsbAttenuateTexmod;
uniform vec3 fb1HsbPowMapTexmod;
uniform float fb1HueShaperTexmod;

uniform vec3 fb1ColorQuantizeTexmod;
uniform vec3 fb1ColorQuantizeDenomTexmod;
uniform vec3 fb1ColorQuantizeMixTexmod;

uniform float fb1HueDitherMixTexmod;
uniform float fb1HueDitherAmountTexmod;
uniform float fb1SaturationDitherMixTexmod;
uniform float fb1SaturationDitherAmountTexmod;
uniform float fb1BrightDitherMixTexmod;
uniform float fb1BrightDitherAmountTexmod;

uniform vec3 fb1RescaleTexmod;
uniform float fb1RotateTexmod;
uniform vec4 fb1ShearMatrixTexmod;

uniform float fb1FisheyeAmountTexmod;
uniform vec2 fb1FisheyeCenterTexmod;
uniform float fb1SpiralAmountTexmod;
uniform float fb1SpiralAngleTexmod;
uniform vec2 fb1SpiralCenterTexmod;
uniform float fb1KaleidoscopeSegmentsTexmod;
uniform float fb1KaleidoscopeSliceTexmod;

uniform vec2 fb1TexmodLogic;

uniform int fb1PixelSwitch;
uniform int fb1XPixelScale;
uniform int fb1YPixelScale;
uniform float fb1PixelMix;
uniform float fb1PixelBrightscale;

uniform vec2 fb1_pixel_texmod_logic;
uniform int fb1XPixelScaleTexmod;
uniform int fb1YPixelScaleTexmod;
uniform float fb1PixelMixTexmod;
uniform float fb1PixelBrightscaleTexmod;










//fb2
//fb2
uniform float fb2LumakeyLevel;
uniform float fb2KeyThreshold;
uniform float fb2ChromakeyRed;
uniform float fb2ChromakeyGreen;
uniform float fb2ChromakeyBlue;
uniform int fb2KeyMode;
uniform float fb2KeySoft;
uniform    float fb2Mix;
uniform    int fb2MixType;
uniform int fb2KeyOrder;
uniform int fb2MixOverflow;

uniform float fb2MaskX;
uniform float fb2MaskY;
uniform float fb2MaskZ;
uniform float fb2MaskRotate;
uniform float fb2MaskTileAmount;
uniform int fb2MaskTileMode;
uniform int fb2MaskTexmod;
uniform float fb2MaskTexmodOffset;
uniform int fb2MaskTexmodQuantizeAmount;
uniform float fb2MaskTexmodQuantizeInvert;
uniform float fb2MaskTexmodQuantizeMix;

uniform vec3 fb2HsbInvert;

uniform vec3 fb2HsbOffset;
uniform vec3 fb2HsbAttenuate;
uniform float fb2HueShaper;
uniform vec3 fb2PowMap;

uniform vec3 fb2ColorQuantize;
uniform vec3 fb2ColorQuantizeDenom;
uniform vec3 fb2ColorQuantizeMix;
uniform float fb2HueDitherMix;
uniform float fb2HueDitherAmount;
uniform float fb2SaturationDitherMix;
uniform float fb2SaturationDitherAmount;
uniform float fb2BrightDitherMix;
uniform float fb2BrightDitherAmount;

uniform int fb2SaturationOverflow;
uniform int fb2BrightOverflow;

uniform vec3 fb2_rescale;
uniform float fb2Rotate;
uniform vec4 fb2ShearMatrix;
uniform int fb2RotateMode;
uniform float fb2FisheyeAmount;
uniform vec2 fb2FisheyeCenter;
uniform float fb2SpiralAmount;
uniform float fb2SpiralAngle;
uniform vec2 fb2SpiralCenter;
uniform float fb2KaleidoscopeSegments;
uniform float fb2KaleidoscopeSlice;

//fb2 tex mod
//to do color quantize texmods we will need to do some division lol

uniform float fb2LumakeyLevelTexmod;
uniform float fb2ChromakeyRedTexmod;
uniform float fb2ChromakeyGreenTexmod;
uniform float fb2ChromakeyBlueTexmod;
uniform float fb2KeyThresholdTexmod;
uniform float fb2KeySoftTexmod;
uniform float fb2MixTexmod;

uniform float fb2MaskXTexmod;
uniform float fb2MaskYTexmod;
uniform float fb2MaskZTexmod;
uniform float fb2MaskRotateTexmod;
uniform float fb2MaskTileAmountTexmod;

uniform vec3 fb2HsbOffsetTexmod;
uniform vec3 fb2HsbAttenuateTexmod;
uniform vec3 fb2HsbPowMapTexmod;
uniform float fb2HueShaperTexmod;

uniform vec3 fb2ColorQuantizeTexmod;
uniform vec3 fb2ColorQuantizeDenomTexmod;
uniform vec3 fb2ColorQuantizeMixTexmod;

uniform float fb2HueDitherMixTexmod;
uniform float fb2HueDitherAmountTexmod;
uniform float fb2SaturationDitherMixTexmod;
uniform float fb2SaturationDitherAmountTexmod;
uniform float fb2BrightDitherMixTexmod;
uniform float fb2BrightDitherAmountTexmod;

uniform vec3 fb2RescaleTexmod;
uniform float fb2RotateTexmod;
uniform vec4 fb2ShearMatrixTexmod;

uniform float fb2FisheyeAmountTexmod;
uniform vec2 fb2FisheyeCenterTexmod;
uniform float fb2SpiralAmountTexmod;
uniform float fb2SpiralAngleTexmod;
uniform vec2 fb2SpiralCenterTexmod;
uniform float fb2KaleidoscopeSegmentsTexmod;
uniform float fb2KaleidoscopeSliceTexmod;

uniform vec2 fb2TexmodLogic;

uniform int fb2PixelSwitch;
uniform int fb2XPixelScale;
uniform int fb2YPixelScale;
uniform float fb2PixelMix;
uniform float fb2PixelBrightscale;

uniform vec2 fb2_pixel_texmod_logic;
uniform int fb2XPixelScaleTexmod;
uniform int fb2YPixelScaleTexmod;
uniform float fb2PixelMixTexmod;
uniform float fb2PixelBrightscaleTexmod;



//fb3
uniform float fb3LumakeyLevel;
uniform float fb3KeyThreshold;
uniform float fb3ChromakeyRed;
uniform float fb3ChromakeyGreen;
uniform float fb3ChromakeyBlue;
uniform int fb3KeyMode;
uniform float fb3KeySoft;
uniform    float fb3Mix;
uniform    int fb3MixType;
uniform int fb3KeyOrder;
uniform int fb3MixOverflow;

uniform float fb3MaskX;
uniform float fb3MaskY;
uniform float fb3MaskZ;
uniform float fb3MaskRotate;
uniform float fb3MaskTileAmount;
uniform int fb3MaskTileMode;
uniform int fb3MaskTexmod;
uniform float fb3MaskTexmodOffset;
uniform int fb3MaskTexmodQuantizeAmount;
uniform float fb3MaskTexmodQuantizeInvert;
uniform float fb3MaskTexmodQuantizeMix;

uniform vec3 fb3HsbInvert;

uniform vec3 fb3HsbOffset;
uniform vec3 fb3HsbAttenuate;
uniform float fb3HueShaper;
uniform vec3 fb3PowMap;

uniform vec3 fb3ColorQuantize;
uniform vec3 fb3ColorQuantizeDenom;
uniform vec3 fb3ColorQuantizeMix;
uniform float fb3HueDitherMix;
uniform float fb3HueDitherAmount;
uniform float fb3SaturationDitherMix;
uniform float fb3SaturationDitherAmount;
uniform float fb3BrightDitherMix;
uniform float fb3BrightDitherAmount;

uniform int fb3SaturationOverflow;
uniform int fb3BrightOverflow;

uniform vec3 fb3_rescale;
uniform float fb3Rotate;
uniform vec4 fb3ShearMatrix;
uniform int fb3RotateMode;
uniform float fb3FisheyeAmount;
uniform vec2 fb3FisheyeCenter;
uniform float fb3SpiralAmount;
uniform float fb3SpiralAngle;
uniform vec2 fb3SpiralCenter;
uniform float fb3KaleidoscopeSegments;
uniform float fb3KaleidoscopeSlice;

//fb3 tex mod
//to do color quantize texmods we will need to do some division lol

uniform float fb3LumakeyLevelTexmod;
uniform float fb3ChromakeyRedTexmod;
uniform float fb3ChromakeyGreenTexmod;
uniform float fb3ChromakeyBlueTexmod;
uniform float fb3KeyThresholdTexmod;
uniform float fb3KeySoftTexmod;
uniform float fb3MixTexmod;

uniform float fb3MaskXTexmod;
uniform float fb3MaskYTexmod;
uniform float fb3MaskZTexmod;
uniform float fb3MaskRotateTexmod;
uniform float fb3MaskTileAmountTexmod;

uniform vec3 fb3HsbOffsetTexmod;
uniform vec3 fb3HsbAttenuateTexmod;
uniform vec3 fb3HsbPowMapTexmod;
uniform float fb3HueShaperTexmod;

uniform vec3 fb3ColorQuantizeTexmod;
uniform vec3 fb3ColorQuantizeDenomTexmod;
uniform vec3 fb3ColorQuantizeMixTexmod;

uniform float fb3HueDitherMixTexmod;
uniform float fb3HueDitherAmountTexmod;
uniform float fb3SaturationDitherMixTexmod;
uniform float fb3SaturationDitherAmountTexmod;
uniform float fb3BrightDitherMixTexmod;
uniform float fb3BrightDitherAmountTexmod;

uniform vec3 fb3RescaleTexmod;
uniform float fb3RotateTexmod;
uniform vec4 fb3ShearMatrixTexmod;

uniform float fb3FisheyeAmountTexmod;
uniform vec2 fb3FisheyeCenterTexmod;
uniform float fb3SpiralAmountTexmod;
uniform float fb3SpiralAngleTexmod;
uniform vec2 fb3SpiralCenterTexmod;
uniform float fb3KaleidoscopeSegmentsTexmod;
uniform float fb3KaleidoscopeSliceTexmod;

uniform vec2 fb3TexmodLogic;

uniform int fb3PixelSwitch;
uniform int fb3XPixelScale;
uniform int fb3YPixelScale;
uniform float fb3PixelMix;
uniform float fb3PixelBrightscale;

uniform vec2 fb3_pixel_texmod_logic;
uniform int fb3XPixelScaleTexmod;
uniform int fb3YPixelScaleTexmod;
uniform float fb3PixelMixTexmod;
uniform float fb3PixelBrightscaleTexmod;







uniform float delaymix;


uniform float ch1_h_mirror;

//vidmixervariables


uniform float width;
uniform float height;


varying vec2 texCoordVarying;


//variables from gui
uniform int channel1;
uniform int channel2;

uniform int mix1;
uniform int mix2;



//mix1 variables
uniform float mix1blend1;

uniform float mix1keybright;
uniform float mix1keythresh;





//channel2 variablesfrom gui
uniform float channel2hue_x;
uniform float channel2saturation_x;
uniform float channel2bright_x;

uniform float channel2hue_powmap;
uniform float channel2sat_powmap;
uniform float channel2bright_powmap;


uniform int channel2satwrap;
uniform int channel2brightwrap;


uniform int ch2hue_inverttoggle;
uniform int ch2sat_inverttoggle;
uniform int ch2bright_inverttoggle;


uniform int cam2HorizontalMirror;
uniform int cam2VerticalMirror;


uniform int fb0HorizontalMirror;
uniform int fb0VerticalMirror;

uniform int fb1HorizontalMirror;
uniform int fb1VerticalMirror;

uniform int fb2HorizontalMirror;
uniform int fb2VerticalMirror;

uniform int fb3HorizontalMirror;
uniform int fb3VerticalMirror;




uniform int fb0_toroid_switch;
uniform int fb1_toroid_switch;
uniform int fb2_toroid_switch;
uniform int fb3_toroid_switch;

uniform float ps;
uniform float qq;



//DITHER!!
const int indexMatrix4x4[16] = int[](0,  8,  2,  10,
                                     12, 4,  14, 6,
                                     3,  11, 1,  9,
                                     15, 7,  13, 5);

const int indexMatrix8x8[64] = int[](0,  32, 8,  40, 2,  34, 10, 42,
                                     48, 16, 56, 24, 50, 18, 58, 26,
                                     12, 44, 4,  36, 14, 46, 6,  38,
                                     60, 28, 52, 20, 62, 30, 54, 22,
                                     3,  35, 11, 43, 1,  33, 9,  41,
                                     51, 19, 59, 27, 49, 17, 57, 25,
                                     15, 47, 7,  39, 13, 45, 5,  37,
                                     63, 31, 55, 23, 61, 29, 53, 21);

float[2] closestColors(float inColor,float paletteSize){
	float ret[2];
	float closest=-2.0;
	float secondClosest=-2.0;
	float temp;

	//float paletteSize=8;

	for(int i=0;i<paletteSize;i++){
		temp=i/paletteSize;
		float tempDistance=distance(temp,inColor);
		if( tempDistance<distance(closest,inColor) ){
			secondClosest=closest;
			closest=temp;
		}
		else{
			if( tempDistance<distance(secondClosest,inColor) ){
				secondClosest=temp;
			}
		}
	
	}

	ret[0]=closest;
	ret[1]=secondClosest;

	return ret;
}

float dither2(float inColor,vec2 inCoord,float ditherPalette){
	//index value
	int x=int(mod(inCoord.x,4));
	int y=int(mod(inCoord.y,4));
	//float indexValue=indexMatrix4x4[(x+y*4)]*.0625;
	float indexValue=indexMatrix8x8[(x+y*8)]*.015625;

	float[2] cs=closestColors(inColor,ditherPalette);

	float closestColor=cs[0];
	float secondClosestColor = cs[1];
	float colorDiff=distance(inColor,closestColor) / distance(secondClosestColor,closestColor);
	
	return (colorDiff < indexValue) ? closestColor : secondClosestColor;
}

vec3 rgb2hsv(vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));
    
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

float colorQuantize(float inColor, float amount, float amountInvert){
	
	inColor=inColor*amount;
	inColor=floor(inColor);
	inColor=inColor*amountInvert;

	return inColor;
}


float hueShaper(float inHue,float shaper){
	inHue=fract(abs(inHue+shaper*sin(inHue*0.3184713) ));
	return inHue;
}

vec3 fb_hsbop(vec3 c,vec3 hsbx,vec3 huex,vec3 modswitch,float bright_fold_switch)
{
    
    int sat_fold_switch=0;
    
    c.r=abs(c.r*hsbx.r+huex.z*sin(c.r/3.14));
    c.r=fract(mod(c.r,1.0)+huex.y);
    c.g=c.g*hsbx.g;
    c.b=c.b*hsbx.b;
    
    
	//so dunno if i want to keep this part, probably not!
    if(c.g>1.0){
        
        if(sat_fold_switch==1){
            c.g=fract(c.g);
        }
        if(sat_fold_switch==0){
            c.g=1.0;
        }
    }

    if(c.b>1.0){
        if(bright_fold_switch==1){
            if(c.b>1){
                c.b=1.0-fract(c.b);
            }
        }
        if(bright_fold_switch==0){
            c.b=1.0;
        }
    }
    
    
    if(modswitch.r==1.0){ c.r=1.0-c.r;}
    if(modswitch.g==1.0){ c.g=1.0-c.g;}
    if(modswitch.b==1.0){ c.b=1.0-c.b;}
    //do some overflow stuffs
    if(abs(c.x)>1.0){  
        c.x=fract(c.x);
        c.x=abs(c.x);
    }
    
    //so here is where we will add: clamp, wrap, fold stuffs
	//default for hue will be wrap i think
    if(c.y>1.0){c.y=1.0;}
    if(c.z>1.0){c.z=1.0;}
    
    if(c.y<.0){c.y=0.0;}
    if(c.z<.0){c.z=0.0;}

    return c;
    
}


//a function for all hsb operations to be invoked by each channel

//change every like hsb thing out there to a vec3 duh
vec3 channel_hsboperations(vec3 c,float hue_x,float sat_x, float bright_x
                           ,float hue_powmap, float sat_powmap, float bright_powmap
                           ,int satwrap,int brightwrap,int hueinvert,int satinvert,int brightinvert)
{
    
    //attenuators
    c.x=c.x*hue_x;
    c.y=c.y*sat_x;
    c.z=c.z*bright_x;
    
    //deal with underflows
    if(c.x<0){
        if(hueinvert==0){ c.x=1.0-abs(c.x);}
        if(hueinvert==1){c.x=abs(1.0-abs(c.x));}
    }

    if(c.y<0){
        if(satinvert==0){ c.y=1.0-abs(c.y);}
        if(satinvert==1){c.y=abs(1.0-abs(c.y));}
        
    }

    if(c.z<0){
        if(brightinvert==0){ c.z=1.0-abs(c.z);}
        if(brightinvert==1){c.z=abs(1.0-abs(c.z));}
    }
    
    //and over flows
    if(satwrap==1.0){
        if(abs(c.y)>1.0){
            c.y=fract(c.y);
        }
    }
    
    if(brightwrap==1.0){
        if(abs(c.z)>1.0){
            c.z=fract(c.z);
        }
    }
    
    if(satwrap==0.0){
        if(c.y>1.0){
            c.y=1;
        }
    }
    
    if(brightwrap==0.0){
        if(c.z>1.0){
            c.z=1;
        }
    }

    c.x=fract(c.x);
    
    //powmaps
    //c.x=pow((c.x),hue_powmap);
    c.y=pow((c.y),sat_powmap);
    c.z=pow((c.z),bright_powmap);

    
    return c;
}



vec4 mix_rgb(vec4 ch1, vec4 ch2, int mixswitch,float blend, float lumavalue, float lumathresh, float bright1){

    vec4 mixout=mix(ch1,ch2,blend);
        
    if((bright1> lumavalue-lumathresh) && (bright1<lumavalue+lumathresh)){
        mixout=ch2;
    }

	//testing adding an outline to the lumakey
	if(bright1==(lumavalue-lumathresh) || bright1==(lumavalue+lumathresh)){
        vec4 outlineRGB=vec4(0.0,0.0,0.0,1.0);
		mixout=outlineRGB;
    }

    //mixout=vec3(mixhue,mixsat,mixbright);
    return mixout;
}//endmixfunction

float wrap(float inColor){

	if(inColor<0.0){
		inColor=1.0-abs(inColor);
	}

	if(inColor>1.0){
		inColor=fract(inColor);
	}

	return inColor;
}

float foldover(float inColor){

	if(inColor<0.0){
		inColor=abs(inColor);
	}

	if(inColor>1.0){
		inColor=1.0-(fract(inColor));
	}

	if(inColor<0.0){
		inColor=abs(inColor);
	}
	return inColor;
}
//MIX
//fg is foreground color, bg is background
//mixmodes 0=lerp, 1=add/subtrac, 2=mult, 3=nothing interesting?
//mixOverflowModes 0-clamp,1 wrap,2 fold?;
//notes: do we want to try anything different for subtractive?
//keying notes: keyvalue is vec3, if we want to lumakey we have the rgb values for keyvalue be constant

//ADD outline/DSK thingy
vec4 mixnKeyVideo(vec4 fg, vec4 bg, float amount, int selectMixMode, float keyThreshold,
float keySoft,vec3 keyValue,int keyOrder,int mixOverflow,vec4 mask,int keyMaskSwitch){
	//vec3 fgHsb=rgb2hsb(vec3(fg.rgb));
	//float fgBright=rgb2hsv(vec3(fg.rgb)).z;

	//might need to troubleshoot order of operations here??
	//keying
	if(keyOrder==1){
		vec4 dummy=fg;
		fg=bg;
		bg=dummy;
	}

	vec4 outColor=vec4(0.0,0.0,0.0,1.0);
	//lerp
	if(selectMixMode==0){
		outColor=mix(fg, bg, amount);
	}
	//addsubtrack
	if(selectMixMode==1){
		outColor.rgb=fg.rgb+amount*bg.rgb;
	}

	//difference
	if(selectMixMode==2){
		outColor.rgb=abs(fg.rgb-amount*bg.rgb);
	}

	//mult
	if(selectMixMode==3){
		outColor.rgb=mix(fg.rgb,fg.rgb*bg.rgb,amount);
	}

	//dodge
	if(selectMixMode==4){
		outColor.rgb=mix(fg.rgb,fg.rgb/(1.00001-bg.rgb),amount);
	}

	//clamp, wrap, fold
	if(mixOverflow==0){
		outColor.rgb=clamp(outColor.rgb,0.0,1.0);
	}

	if(mixOverflow==1){
		//outColor.rgb=fract(abs(outColor.rgb));
		outColor.r=wrap(outColor.r);
		outColor.g=wrap(outColor.g);
		outColor.b=wrap(outColor.b);
	}

	if(mixOverflow==2){
	//foldover
		outColor.r=foldover(outColor.r);
		outColor.g=foldover(outColor.g);
		outColor.b=foldover(outColor.b);
	}
	//alpha, i think this is NAM??
	/*
	if(selectMixMode==3){
		fg.a=mix(fg.a,fgHsb.z,amount);
		outColor=mix(fg,fg*bg,amount);
	}
	//OK I HAVE AN IDEA
	//key between fg and bg with max(fg,bg*amount) as a test
	//NAM??
	if(selectMixMode==3){
		fg.a=mix(fg.a,fgHsb.z,amount);
		outColor=mix(fg,fg*bg,amount);
	}
	*/
	

	float chromaDistance=distance(keyValue,fg.rgb);
	float lower=chromaDistance-keyThreshold;

	if( chromaDistance < keyThreshold ){
		//outColor=mix(bg,fg,keySoft*(abs(keyValue-lower)/lower));

		//i don't quite think this is working, lets try something else some 
		//other time...I think the way to do it is to have generated a blur earlier in the
		//chain, and use the blurred value to 
		outColor=mix(bg,outColor,keySoft*abs(1.0-(chromaDistance-keyThreshold)));
		//outColor=bg;
		//outColor=mix(bg,fg,keySoft*abs(1.0-(chromaDistance-keyThreshold)));
	 }

	 //add an outline to the key value
	 //lets add the ability to thicken it as well
	 //this kinda looks like shit but maybe also with a blur?
	 /*
	 vec4 keyOutlineColor = vec4(0.0,1.0,0.0,1.0);
	 float outlineThreshold=.01;
	 if( abs(chromaDistance-keyThreshold)<= outlineThreshold ){
		outColor=keyOutlineColor;
	 }
	*/


	//so masking will be a different mode than luma or chromakeying so
	//will need to have a different switch for that integrated in here lol
	
	//taking for granted that the mask is in greyscale so any rgb value can be
	//used as test
	//starting off with 1 (white) returns fg and 0 (black) returns bg
	if(keyMaskSwitch==1){
		outColor=mix(outColor,bg,mask.g);
	}
	return outColor;
}

uniform float inverseWidth;
uniform float inverseHeight;
vec2 rotate(vec2 coord,float theta,int mode){

	vec2 rotate_coord=vec2(0,0);
	//this version does not preserve aspect ratio
	if(mode==0){
		vec2 center_coord=vec2(coord.x-width/2,coord.y-height/2);
		float spiral=abs(coord.x+coord.y)/2*width;
		coord.x=spiral+coord.x;
		coord.y=spiral+coord.y;
		rotate_coord.x=center_coord.x*cos(theta)-center_coord.y*sin(theta);
		rotate_coord.y=center_coord.x*sin(theta)+center_coord.y*cos(theta);
    
		rotate_coord=rotate_coord+vec2(width/2,height/2);
	}
	//so lets try one that does and see what happens
	//so this works, can try switchable versions for a bit and see how one feels
	//while this preserves the aspect ratio of what feeds into it,
	//the other version is always circular which is def fun a lot of time.
	if(mode==1){
		vec2 center_coord=vec2((coord.x-width/2)*inverseWidth,(coord.y-height/2)*inverseHeight);
		float spiral=abs(coord.x+coord.y)/2*width;
		coord.x=spiral+coord.x;
		coord.y=spiral+coord.y;
		rotate_coord.x=center_coord.x*cos(theta)-center_coord.y*sin(theta);
		rotate_coord.y=center_coord.x*sin(theta)+center_coord.y*cos(theta);
    
		//rotate_coord=rotate_coord+vec2(width/2,height/2);
		rotate_coord.x=width*rotate_coord.x+width/2;
		rotate_coord.y=height*rotate_coord.y+height/2;
	}

    return rotate_coord;
    
    
}//endrotate

//takes in coords and shears them
vec2 shear(vec2 inCoord, vec4 shearMatrix){
	inCoord.x-=0.5;
	inCoord.y-=0.5;

	inCoord.x=shearMatrix.x*inCoord.x+shearMatrix.y*inCoord.y;
	inCoord.y=shearMatrix.z*inCoord.x+shearMatrix.w*inCoord.y;

	inCoord.x+=0.5;
	inCoord.y+=0.5;
	return inCoord;
}

//note that when we normalize we can just pass things like amnt and center in as -1 to 1...
vec2 fisheye(vec2 inCoord,float amnt,vec2 center){
	inCoord.x=inCoord.x/width;
	inCoord.y=inCoord.y/height;

	inCoord=2.0*inCoord-1.0;

	float theta=atan(inCoord.y,inCoord.x);
	//add center offsets here for controls?
	float radius=distance(inCoord,vec2(center.x,center.y));
	//float radius=distance(inCoord,vec2(.5,.2));

	//add gui controls for amnt
	float c3=5.0;
	radius=pow(radius,(amnt+1/c3)*c3);
	inCoord.x=radius*cos(theta);
	inCoord.y=radius*sin(theta);

	inCoord*=.5;
	inCoord+=.5;
	
	inCoord.x*=width;
	inCoord.y*=height;
	return inCoord;
}


vec2 spiralize(vec2 inCoord, float amount, float angle, vec2 center){
	inCoord.x=inCoord.x/width;
	inCoord.y=inCoord.y/height;

	inCoord=2.0*inCoord-1.0;

	float radius=distance(inCoord,vec2(center.x,center.y));
	radius = (amount-radius)/amount;
	float theta=radius*angle;
	float s=sin(theta);
	float c=cos(theta);
	//dang rewrite all the matrix shit this way ya goof
	inCoord= vec2( dot( inCoord, vec2(c,-s) )
				 , dot( inCoord, vec2(s, c) ) );

	inCoord*=.5;
	inCoord+=.5;

	inCoord.x*=width;
	inCoord.y*=height;
	return inCoord;
}

vec2 kaleidoscope(vec2 inCoord, float segment, float slice){
	if(segment>0.0){
	//question: can we rotate the coords in here to select which portion of the screen we
	//are kaleidoscoping from??
		inCoord=rotate(inCoord,slice,1);

		inCoord.x=inCoord.x/width;
		inCoord.y=inCoord.y/height;

		inCoord=2.0*inCoord-1.0;
	
		float radius=sqrt( dot(inCoord,inCoord) );
		float angle=atan(inCoord.y,inCoord.x);
		float segmentAngle=TWO_PI/segment;
		angle-=segmentAngle*floor(angle/segmentAngle);
		angle=min(angle,segmentAngle-angle);
		inCoord=radius*vec2(cos(angle),sin(angle));

		inCoord=.5*(inCoord+1.0);
		inCoord.x*=width;
		inCoord.y*=height;

		inCoord=rotate(inCoord,-slice,1);
	}
	return inCoord;
}
//pixelatefunction
//WHAT TO fixe
//aspect ratio!
vec4 pixelate(float x_scale, float y_scale, vec2 coord,sampler2DRect pixelTex,float pixelMixxx,vec4 c,float brightscale){
    vec4 pixel_color=texture2DRect(pixelTex,coord);
    vec2 pixelScaleCoord= coord;
    x_scale=floor(x_scale*((1-brightscale)+(brightscale)*(.33*pixel_color.r+.5*pixel_color.g+.16*pixel_color.b)));
    
    y_scale=floor(y_scale*((1-brightscale)+(brightscale)*(.33*pixel_color.r+.5*pixel_color.g+.16*pixel_color.b)));
    
	//old
    //pixelScaleCoord.x=coord.x/width;
    //pixelScaleCoord.y=coord.y/height;

	//new1-this fixes nothing lol
    pixelScaleCoord.x=coord.x/width;
    pixelScaleCoord.y=coord.y/width;
    
    pixelScaleCoord.x=floor(x_scale*pixelScaleCoord.x)/x_scale;
    pixelScaleCoord.y=floor(y_scale*pixelScaleCoord.y)/y_scale;
    
	//old
    //pixelScaleCoord.x=width*pixelScaleCoord.x +(width/x_scale)*.5;
    //pixelScaleCoord.y=height*pixelScaleCoord.y +(height/y_scale)*.5;

	//new1
    pixelScaleCoord.x=width*pixelScaleCoord.x +(width/x_scale)*.5;
    pixelScaleCoord.y=width*pixelScaleCoord.y +(width/y_scale)*.5;
    
    pixel_color=texture2DRect(pixelTex,pixelScaleCoord);
    
	//something weird going on with pixelS
	//when i try the lock thing for square pixelS
	//low values like 13 have x size way larger than y
	//around 100 has squarish pixelS
	//and around 200 has y larger than x

    return mix(c,pixel_color,pixelMixxx);
    
}



vec2 wrapCoord(vec2 coord){
    
    if(abs(coord.x)>width){coord.x=abs(width-coord.x);}
    if(abs(coord.y)>height){coord.y=abs(height-coord.y);}
    
    coord.x=mod(coord.x,width);
    coord.y=mod(coord.y,height);
    
   
    
    return coord;
}

vec2 mirrorCoord(vec2 coord){

    //trying out a different kind of wrapping for rotations
    if(coord.x>width){coord.x=width-mod(coord.x,width);}
    if(coord.y>height){coord.y=height-mod(coord.y,height);}
    
    if(coord.x<0){coord.x=abs(coord.x);}
    if(coord.y<0){coord.y=abs(coord.y);}
    
    return coord;
}

void main()
{
    
    ///NEW STUFF to replace the cam1/cam2/ndi nonsense, inputs all go through ch1tex or ch2tex
    vec4 ch1Color=vec4(0,0,0,0);
    vec2 ch1Coords=texCoordVarying;
    
    //rescaling stuff for aspect ratios
    //rescale from center remember lol
    
	if(ch1HMirror==1){
        if(ch1Coords.x>width/2){ch1Coords.x=abs(width-ch1Coords.x);}
    }
    if(ch1VMirror==1){
        if(ch1Coords.y>height/2){ch1Coords.y=abs(height-ch1Coords.y);}
    }

    ch1Coords-=ch1Center;
    ch1Coords*=ch1Scale;
    ch1Coords+=ch1Center;
    
    ch1Color=texture2DRect(ch1Tex,ch1Coords);

    //clamp,wrap,mirror
    if(ch1Coords.x>ch1Dimensions.x || ch1Coords.y>ch1Dimensions.y){
        ch1Color=vec4(0.0,0.0,0.0,1.0);
    }
    if(ch1Coords.x<0 || ch1Coords.y<0){
        ch1Color=vec4(0.0,0.0,0.0,1.0);
    }
    
	if(ch1PixelSwitch==1){
		ch1Color=pixelate(ch1XPixelScale,
                           ch1YPixelScale,
                           ch1Coords,ch1Tex,
                           ch1PixelMix,
                           ch1Color,
                           ch1PixelBrightscale);
    }

    //do the color stuffs here
    
    //CH1Color
    vec3 ch1ColorHsb=rgb2hsv(ch1Color.rgb);
    
    ch1ColorHsb=ch1ColorHsb*(1.0+ch1HsbAttenuate);
    
    if(ch1HueInvert==1){
        ch1ColorHsb.x=1.0-ch1ColorHsb.x;
    }
    if(ch1SaturationInvert==1){
        ch1ColorHsb.y=1.0-ch1ColorHsb.y;
    }
    if(ch1BrightInvert==1){
        ch1ColorHsb.z=1.0-ch1ColorHsb.z;
    }
    
    if(ch1QuantizeSwitch==1){
        //ch1ColorHsb.x=colorQuantize(ch1ColorHsb.x,ch1QuantizeAmount,ch1QuantizeDenom);
        //ch1ColorHsb.y=colorQuantize(ch1ColorHsb.y,ch1QuantizeAmount,ch1QuantizeDenom);
        ch1ColorHsb.z=colorQuantize(ch1ColorHsb.z,ch1QuantizeAmount,ch1QuantizeAmountDenom);
    }
    
    ch1Color.rgb=hsv2rgb(ch1ColorHsb);
    
    
    
    //ch2
	 ///NEW STUFF to replace the cam1/cam2/ndi nonsense, inputs all go through ch2tex or ch2tex
    vec4 ch2Color=vec4(0,0,0,0);
	
    vec2 ch2Coords=texCoordVarying;
    
    //rescaling stuff for aspect ratios
    //rescale from center remember lol
    
    ch2Coords-=ch2Center;
    ch2Coords*=ch2Scale;
    ch2Coords+=ch2Center;
    
    ch2Color=texture2DRect(ch2Tex,ch2Coords);
    
    //clamp,wrap,mirror
    if(ch2Coords.x>ch2Dimensions.x || ch2Coords.y>ch2Dimensions.y){
        ch2Color=vec4(0.0,0.0,0.0,1.0);
    }
    if(ch2Coords.x<0 || ch2Coords.y<0){
        ch2Color=vec4(0.0,0.0,0.0,1.0);
    }

	if(ch2PixelSwitch==1){
		ch2Color=pixelate(ch2XPixelScale,
                           ch2YPixelScale,
                           ch2Coords,ch2Tex,
                           ch2PixelMix,
                           ch2Color,
                           ch2PixelBrightscale);
    }
    
    //do the color stuffs here
    
    //ch2Color
    vec3 ch2ColorHsb=rgb2hsv(ch2Color.rgb);
    
    ch2ColorHsb=ch2ColorHsb*(1.0+ch2HsbAttenuate);
    
    if(ch2HueInvert==1){
        ch2ColorHsb.x=1.0-ch2ColorHsb.x;
    }
    if(ch2SaturationInvert==1){
        ch2ColorHsb.y=1.0-ch2ColorHsb.y;
    }
    if(ch2BrightInvert==1){
        ch2ColorHsb.z=1.0-ch2ColorHsb.z;
    }
    
    if(ch2QuantizeSwitch==1){
        //ch2ColorHsb.x=colorQuantize(ch2ColorHsb.x,ch2QuantizeAmount,ch2QuantizeDenom);
        //ch2ColorHsb.y=colorQuantize(ch2ColorHsb.y,ch2QuantizeAmount,ch2QuantizeDenom);
        ch2ColorHsb.z=colorQuantize(ch2ColorHsb.z,ch2QuantizeAmount,ch2QuantizeAmountDenom);
    }
    
    ch2Color.rgb=hsv2rgb(ch2ColorHsb);
    
    
    
    
    
    
    
    
    //center should be a variable sent that displaces where yr center is wished to be
    //move this over to the cpp
    vec2 center=vec2(width/2,height/2);
    
    
    
    
    
    
    //fb0 GEOMETRY
    float fb0Texmod=fb0TexmodLogic.x*ch1ColorHsb.z+fb0TexmodLogic.y*ch2ColorHsb.z;

    vec2 fb0_coord=texCoordVarying;//vec2(texCoordVarying.x-center.x,texCoordVarying.y-center.y);
	fb0_coord=kaleidoscope(fb0_coord,fb0KaleidoscopeSegments+fb0KaleidoscopeSegmentsTexmod*fb0Texmod,
                           fb0KaleidoscopeSlice+fb0KaleidoscopeSliceTexmod*fb0Texmod);
	if(fb0HorizontalMirror==1){
        if(fb0_coord.x>width/2){fb0_coord.x=abs(width-fb0_coord.x);}
    }//endifhflip1
    if(fb0VerticalMirror==1){
        if(fb0_coord.y>height/2){fb0_coord.y=abs(height-fb0_coord.y);}
    }//endifvflip1

	fb0_coord-=center;
    fb0_coord=fb0_coord*(fb0_rescale.z+fb0RescaleTexmod.z*fb0Texmod);
    fb0_coord.xy=fb0_rescale.xy+fb0_coord.xy;
    fb0_coord.x=fb0RescaleTexmod.x*(fb0Texmod)+fb0_coord.x+center.x;
    fb0_coord.y=fb0RescaleTexmod.y*(fb0Texmod)+fb0_coord.y+center.y;

    

	//test out with shear, fisheye, rotate, and spiral in different orders
	fb0_coord=rotate(fb0_coord,fb0Rotate+fb0RotateTexmod*fb0Texmod,fb0RotateMode);
	fb0_coord=shear(fb0_coord,fb0ShearMatrix+fb0ShearMatrixTexmod*fb0Texmod);
	fb0_coord=fisheye(fb0_coord,fb0FisheyeAmount+fb0FisheyeAmountTexmod*fb0Texmod,
                      fb0FisheyeCenter+fb0FisheyeCenterTexmod*fb0Texmod);
	fb0_coord=spiralize(fb0_coord,fb0SpiralAmount+fb0SpiralAmountTexmod*fb0Texmod,
                        fb0SpiralAngle+fb0SpiralAngleTexmod*fb0Texmod,
                        fb0SpiralCenter+fb0SpiralCenterTexmod*fb0Texmod);

    if(fb0_toroid_switch==1){
        fb0_coord=wrapCoord(fb0_coord);
    }
    
    if(fb0_toroid_switch==2){
        fb0_coord=mirrorCoord(fb0_coord);
    }
 
    vec4 fb0Color = texture2DRect(fb0,fb0_coord);
    
    if(abs(fb0_coord.x-width/2)>=width/2||abs(fb0_coord.y-height/2)>=height/2){
        fb0Color=vec4(0,0,0,1.0);
    }
    
    if(fb0PixelSwitch==1){
		fb0Color=pixelate(fb0XPixelScale+fb0XPixelScaleTexmod*fb0Texmod,
                           fb0YPixelScale+fb0YPixelScaleTexmod*fb0Texmod,
                           fb0_coord,fb0,
                           fb0PixelMix+fb0PixelMixTexmod*fb0Texmod,
                           fb0Color,
                           fb0PixelBrightscale+fb0PixelBrightscaleTexmod*fb0Texmod);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    //fb1 GEOMETRY
    float fb1Texmod=fb1TexmodLogic.x*ch1ColorHsb.z+fb1TexmodLogic.y*ch2ColorHsb.z;
    
    vec2 fb1_coord=texCoordVarying;//vec2(texCoordVarying.x-center.x,texCoordVarying.y-center.y);
    fb1_coord=kaleidoscope(fb1_coord,fb1KaleidoscopeSegments+fb1KaleidoscopeSegmentsTexmod*fb1Texmod,
                           fb1KaleidoscopeSlice+fb1KaleidoscopeSliceTexmod*fb1Texmod);
	if(fb1HorizontalMirror==1){
        if(fb1_coord.x>width/2){fb1_coord.x=abs(width-fb1_coord.x);}
    }//endifhflip1
    if(fb1VerticalMirror==1){
        if(fb1_coord.y>height/2){fb1_coord.y=abs(height-fb1_coord.y);}
    }//endifvflip1

    fb1_coord-=center;
    fb1_coord=fb1_coord*(fb1_rescale.z+fb1RescaleTexmod.z*fb1Texmod);
    fb1_coord.xy=fb1_rescale.xy+fb1_coord.xy;
    fb1_coord.x=fb1RescaleTexmod.x*(fb1Texmod)+fb1_coord.x+center.x;
    fb1_coord.y=fb1RescaleTexmod.y*(fb1Texmod)+fb1_coord.y+center.y;
    
    
    
    //test out with shear, fisheye, rotate, and spiral in different orders
    fb1_coord=rotate(fb1_coord,fb1Rotate+fb1RotateTexmod*fb1Texmod,fb1RotateMode);
    fb1_coord=shear(fb1_coord,fb1ShearMatrix+fb1ShearMatrixTexmod*fb1Texmod);
    fb1_coord=fisheye(fb1_coord,fb1FisheyeAmount+fb1FisheyeAmountTexmod*fb1Texmod,
                      fb1FisheyeCenter+fb1FisheyeCenterTexmod*fb1Texmod);
    fb1_coord=spiralize(fb1_coord,fb1SpiralAmount+fb1SpiralAmountTexmod*fb1Texmod,
                        fb1SpiralAngle+fb1SpiralAngleTexmod*fb1Texmod,
                        fb1SpiralCenter+fb1SpiralCenterTexmod*fb1Texmod);
    
    if(fb1_toroid_switch==1){
        fb1_coord=wrapCoord(fb1_coord);
    }
    
    if(fb1_toroid_switch==2){
        fb1_coord=mirrorCoord(fb1_coord);
    }
    
    vec4 fb1Color = texture2DRect(fb1,fb1_coord);
    
    if(abs(fb1_coord.x-width/2)>=width/2||abs(fb1_coord.y-height/2)>=height/2){
        fb1Color=vec4(0,0,0,1.0);
    }
    
    if(fb1PixelSwitch==1){
        fb1Color=pixelate(fb1XPixelScale+fb1XPixelScaleTexmod*fb1Texmod,
                          fb1YPixelScale+fb1YPixelScaleTexmod*fb1Texmod,
                          fb1_coord,fb1,
                          fb1PixelMix+fb1PixelMixTexmod*fb1Texmod,
                          fb1Color,
                          fb1PixelBrightscale+fb1PixelBrightscaleTexmod*fb1Texmod);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
    //fb2 GEOMETRY
    float fb2Texmod=fb2TexmodLogic.x*ch1ColorHsb.z+fb2TexmodLogic.y*ch2ColorHsb.z;
    
    vec2 fb2_coord=texCoordVarying;//vec2(texCoordVarying.x-center.x,texCoordVarying.y-center.y);
    fb2_coord=kaleidoscope(fb2_coord,fb2KaleidoscopeSegments+fb2KaleidoscopeSegmentsTexmod*fb2Texmod,
                           fb2KaleidoscopeSlice+fb2KaleidoscopeSliceTexmod*fb2Texmod);
    
	if(fb2HorizontalMirror==1){
        if(fb2_coord.x>width/2){fb2_coord.x=abs(width-fb2_coord.x);}
    }//endifhflip1
    if(fb2VerticalMirror==1){
        if(fb2_coord.y>height/2){fb2_coord.y=abs(height-fb2_coord.y);}
    }//endifvflip1
	fb2_coord-=center;
    fb2_coord=fb2_coord*(fb2_rescale.z+fb2RescaleTexmod.z*fb2Texmod);
    fb2_coord.xy=fb2_rescale.xy+fb2_coord.xy;
    fb2_coord.x=fb2RescaleTexmod.x*(fb2Texmod)+fb2_coord.x+center.x;
    fb2_coord.y=fb2RescaleTexmod.y*(fb2Texmod)+fb2_coord.y+center.y;
    
   
    
    //test out with shear, fisheye, rotate, and spiral in different orders
    fb2_coord=rotate(fb2_coord,fb2Rotate+fb2RotateTexmod*fb2Texmod,fb2RotateMode);
    fb2_coord=shear(fb2_coord,fb2ShearMatrix+fb2ShearMatrixTexmod*fb2Texmod);
    fb2_coord=fisheye(fb2_coord,fb2FisheyeAmount+fb2FisheyeAmountTexmod*fb2Texmod,
                      fb2FisheyeCenter+fb2FisheyeCenterTexmod*fb2Texmod);
    fb2_coord=spiralize(fb2_coord,fb2SpiralAmount+fb2SpiralAmountTexmod*fb2Texmod,
                        fb2SpiralAngle+fb2SpiralAngleTexmod*fb2Texmod,
                        fb2SpiralCenter+fb2SpiralCenterTexmod*fb2Texmod);
    
    if(fb2_toroid_switch==1){
        fb2_coord=wrapCoord(fb2_coord);
    }
    
    if(fb2_toroid_switch==2){
        fb2_coord=mirrorCoord(fb2_coord);
    }
    
    vec4 fb2Color = texture2DRect(fb2,fb2_coord);
    
    if(abs(fb2_coord.x-width/2)>=width/2||abs(fb2_coord.y-height/2)>=height/2){
        fb2Color=vec4(0,0,0,1.0);
    }
    
    if(fb2PixelSwitch==1){
        fb2Color=pixelate(fb2XPixelScale+fb2XPixelScaleTexmod*fb2Texmod,
                          fb2YPixelScale+fb2YPixelScaleTexmod*fb2Texmod,
                          fb2_coord,fb2,
                          fb2PixelMix+fb2PixelMixTexmod*fb2Texmod,
                          fb2Color,
                          fb2PixelBrightscale+fb2PixelBrightscaleTexmod*fb2Texmod);
    }
    
    
    
    
    
    
    
    //fb3 GEOMETRY
    float fb3Texmod=fb3TexmodLogic.x*ch1ColorHsb.z+fb3TexmodLogic.y*ch2ColorHsb.z;
    
    vec2 fb3_coord=texCoordVarying;//vec2(texCoordVarying.x-center.x,texCoordVarying.y-center.y);
    fb3_coord=kaleidoscope(fb3_coord,fb3KaleidoscopeSegments+fb3KaleidoscopeSegmentsTexmod*fb3Texmod,
                           fb3KaleidoscopeSlice+fb3KaleidoscopeSliceTexmod*fb3Texmod);
    
	if(fb3HorizontalMirror==1){
        if(fb3_coord.x>width/2){fb3_coord.x=abs(width-fb3_coord.x);}
    }//endifhflip1
    if(fb3VerticalMirror==1){
        if(fb3_coord.y>height/2){fb3_coord.y=abs(height-fb3_coord.y);}
    }//endifvflip1
	fb3_coord-=center;
    fb3_coord=fb3_coord*(fb3_rescale.z+fb3RescaleTexmod.z*fb3Texmod);
    fb3_coord.xy=fb3_rescale.xy+fb3_coord.xy;
    fb3_coord.x=fb3RescaleTexmod.x*(fb3Texmod)+fb3_coord.x+center.x;
    fb3_coord.y=fb3RescaleTexmod.y*(fb3Texmod)+fb3_coord.y+center.y;
    
    
    
    //test out with shear, fisheye, rotate, and spiral in different orders
    fb3_coord=rotate(fb3_coord,fb3Rotate+fb3RotateTexmod*fb3Texmod,fb3RotateMode);
    fb3_coord=shear(fb3_coord,fb3ShearMatrix+fb3ShearMatrixTexmod*fb3Texmod);
    fb3_coord=fisheye(fb3_coord,fb3FisheyeAmount+fb3FisheyeAmountTexmod*fb3Texmod,
                      fb3FisheyeCenter+fb3FisheyeCenterTexmod*fb3Texmod);
    fb3_coord=spiralize(fb3_coord,fb3SpiralAmount+fb3SpiralAmountTexmod*fb3Texmod,
                        fb3SpiralAngle+fb3SpiralAngleTexmod*fb3Texmod,
                        fb3SpiralCenter+fb3SpiralCenterTexmod*fb3Texmod);
    
    if(fb3_toroid_switch==1){
        fb3_coord=wrapCoord(fb3_coord);
    }
    
    if(fb3_toroid_switch==2){
        fb3_coord=mirrorCoord(fb3_coord);
    }
    
    vec4 fb3Color = texture2DRect(fb3,fb3_coord);
    
    if(abs(fb3_coord.x-width/2)>=width/2||abs(fb3_coord.y-height/2)>=height/2){
        fb3Color=vec4(0,0,0,1.0);
    }
    
    if(fb3PixelSwitch==1){
        fb3Color=pixelate(fb3XPixelScale+fb3XPixelScaleTexmod*fb3Texmod,
                          fb3YPixelScale+fb3YPixelScaleTexmod*fb3Texmod,
                          fb3_coord,fb3,
                          fb3PixelMix+fb3PixelMixTexmod*fb3Texmod,
                          fb3Color,
                          fb3PixelBrightscale+fb3PixelBrightscaleTexmod*fb3Texmod);
    }
    
    
    
    
    
    vec4 color = vec4(0.0, 0.0, 0.0, 0.0);

    
    
    
    
    
    
    vec3 fb0ColorHsb=rgb2hsv(vec3(fb0Color.r,fb0Color.g,fb0Color.b));
    vec3 fb1ColorHsb=rgb2hsv(vec3(fb1Color.r,fb1Color.g,fb1Color.b));
    
    vec3 fb2ColorHsb=rgb2hsv(vec3(fb2Color.r,fb2Color.g,fb2Color.b));
    vec3 fb3ColorHsb=rgb2hsv(vec3(fb3Color.r,fb3Color.g,fb3Color.b));
    
    
    
    
    
    
    
    
    
    
    //fb0 COLOR
	//shaper
 	fb0ColorHsb.x=hueShaper(fb0ColorHsb.x,fb0HueShaper+fb0Texmod*fb0HueShaperTexmod);
	//attenuate & offset
	fb0ColorHsb=(fb0ColorHsb+fb0HsbOffset+fb0Texmod*fb0HsbOffsetTexmod)*(fb0HsbAttenuate+fb0Texmod*fb0HsbAttenuateTexmod);
	//posterize
	
	
	//something in here is making fb0 all black
	//something to do with fb0ColorQuantizeDenomTexmod
	//actually i don't think we can do texmods for these ones...now that i think about it
	/*
	fb0ColorHsb.x=mix( fb0ColorHsb.x,colorQuantize( fb0ColorHsb.x,
		fb0ColorQuantize.x+fb0ColorQuantizeTexmod.x*fb0Texmod,
		fb0ColorQuantizeDenom.x),
		fb0ColorQuantizeMix.x);
		/*
	fb0ColorHsb.y=mix(fb0ColorHsb.y,colorQuantize(fb0ColorHsb.y,
		fb0ColorQuantize.y+fb0ColorQuantizeTexmod.y*fb0Texmod,
		fb0ColorQuantizeDenom.y+fb0ColorQuantizeDenomTexmod.y*fb0Texmod),
		fb0ColorQuantizeMix.y+fb0ColorQuantizeMixTexmod.y*fb0Texmod);

	fb0ColorHsb.z=mix(fb0ColorHsb.z,colorQuantize(fb0ColorHsb.z,
		fb0ColorQuantize.z+fb0ColorQuantizeTexmod.z*fb0Texmod,
		fb0ColorQuantizeDenom.z+fb0ColorQuantizeDenomTexmod.z*fb0Texmod),
		fb0ColorQuantizeMix.z+fb0ColorQuantizeMixTexmod.z*fb0Texmod);
	*/
	
	fb0ColorHsb.x=mix(fb0ColorHsb.x,colorQuantize(fb0ColorHsb.x,fb0ColorQuantize.x,fb0ColorQuantizeDenom.x),fb0ColorQuantizeMix.x);	
	fb0ColorHsb.y=mix(fb0ColorHsb.y,colorQuantize(fb0ColorHsb.y,fb0ColorQuantize.y,fb0ColorQuantizeDenom.y),fb0ColorQuantizeMix.y);	
	fb0ColorHsb.z=mix(fb0ColorHsb.z,colorQuantize(fb0ColorHsb.z,fb0ColorQuantize.z,fb0ColorQuantizeDenom.z),fb0ColorQuantizeMix.z);
	//dither2
	/*
	something in here is causing a fatal error lol  lets just not
	fb0ColorHsb.x=mix(fb0ColorHsb.x,dither2(fb0ColorHsb.x,fb0_coord,fb0HueDitherAmount+fb0HueDitherAmountTexmod*fb0Texmod),
				fb0HueDitherMix +fb0HueDitherMixTexmod*fb0Texmod );
	fb0ColorHsb.y=mix(fb0ColorHsb.y,dither2(fb0ColorHsb.y,fb0_coord,fb0SaturationDitherAmount+fb0SaturationDitherAmountTexmod*fb0Texmod),
				fb0SaturationDitherMix +fb0SaturationDitherMixTexmod*fb0Texmod );
	fb0ColorHsb.z=mix(fb0ColorHsb.z,dither2(fb0ColorHsb.z,fb0_coord,fb0BrightDitherAmount+fb0BrightDitherAmountTexmod*fb0Texmod),
				fb0BrightDitherMix +fb0BrightDitherMixTexmod*fb0Texmod );
	*/
	fb0ColorHsb.x=mix(fb0ColorHsb.x,dither2(fb0ColorHsb.x,fb0_coord,fb0HueDitherAmount),fb0HueDitherMix );
	fb0ColorHsb.y=mix(fb0ColorHsb.y,dither2(fb0ColorHsb.y,fb0_coord,fb0SaturationDitherAmount),fb0SaturationDitherMix );
	fb0ColorHsb.z=mix(fb0ColorHsb.z,dither2(fb0ColorHsb.z,fb0_coord,fb0BrightDitherAmount),fb0BrightDitherMix  );
	//powmap
	

	//invert
	if(fb0HsbInvert.x==1){
		fb0ColorHsb.x=1.0-fb0ColorHsb.x;
	}
	if(fb0HsbInvert.y==1){
		fb0ColorHsb.y=1.0-fb0ColorHsb.y;
	}
	if(fb0HsbInvert.z==1){
		fb0ColorHsb.z=1.0-fb0ColorHsb.z;
	}
	//clamp/wrap/fold
	if(fb0SaturationOverflow==0){
		fb0ColorHsb.y=clamp(fb0ColorHsb.y,0.0,1.0);
	}
	if(fb0SaturationOverflow==1){
		fb0ColorHsb.y=wrap(fb0ColorHsb.y);
	}
	if(fb0SaturationOverflow==2){
		fb0ColorHsb.y=foldover(fb0ColorHsb.y);
	}
	if(fb0BrightOverflow==0){
		fb0ColorHsb.z=clamp(fb0ColorHsb.z,0.0,1.0);
	}
	if(fb0BrightOverflow==1){
		fb0ColorHsb.z=wrap(fb0ColorHsb.z);
	}
	if(fb0BrightOverflow==2){
		fb0ColorHsb.z=foldover(fb0ColorHsb.z);
	}
	fb0ColorHsb=pow(fb0ColorHsb,fb0PowMap+fb0Texmod*fb0HsbPowMapTexmod);

    
    
    
    
    
    
    

    
    //fb1 COLOR
    //shaper
    fb1ColorHsb.x=hueShaper(fb1ColorHsb.x,fb1HueShaper+fb1Texmod*fb1HueShaperTexmod);
    //attenuate & offset
    fb1ColorHsb=(fb1ColorHsb+fb1HsbOffset+fb1Texmod*fb1HsbOffsetTexmod)*(fb1HsbAttenuate+fb1Texmod*fb1HsbAttenuateTexmod);
    //posterize
    
    
    //something in here is making fb1 all black
    //something to do with fb1ColorQuantizeDenomTexmod
    //actually i don't think we can do texmods for these ones...now that i think about it
    /*
     fb1ColorHsb.x=mix( fb1ColorHsb.x,colorQuantize( fb1ColorHsb.x,
     fb1ColorQuantize.x+fb1ColorQuantizeTexmod.x*fb1Texmod,
     fb1ColorQuantizeDenom.x),
     fb1ColorQuantizeMix.x);
     /*
     fb1ColorHsb.y=mix(fb1ColorHsb.y,colorQuantize(fb1ColorHsb.y,
     fb1ColorQuantize.y+fb1ColorQuantizeTexmod.y*fb1Texmod,
     fb1ColorQuantizeDenom.y+fb1ColorQuantizeDenomTexmod.y*fb1Texmod),
     fb1ColorQuantizeMix.y+fb1ColorQuantizeMixTexmod.y*fb1Texmod);
     
     fb1ColorHsb.z=mix(fb1ColorHsb.z,colorQuantize(fb1ColorHsb.z,
     fb1ColorQuantize.z+fb1ColorQuantizeTexmod.z*fb1Texmod,
     fb1ColorQuantizeDenom.z+fb1ColorQuantizeDenomTexmod.z*fb1Texmod),
     fb1ColorQuantizeMix.z+fb1ColorQuantizeMixTexmod.z*fb1Texmod);
     */
    
    fb1ColorHsb.x=mix(fb1ColorHsb.x,colorQuantize(fb1ColorHsb.x,fb1ColorQuantize.x,fb1ColorQuantizeDenom.x),fb1ColorQuantizeMix.x);
    fb1ColorHsb.y=mix(fb1ColorHsb.y,colorQuantize(fb1ColorHsb.y,fb1ColorQuantize.y,fb1ColorQuantizeDenom.y),fb1ColorQuantizeMix.y);
    fb1ColorHsb.z=mix(fb1ColorHsb.z,colorQuantize(fb1ColorHsb.z,fb1ColorQuantize.z,fb1ColorQuantizeDenom.z),fb1ColorQuantizeMix.z);
    //dither2
    /*
     something in here is causing a fatal error lol  lets just not
     fb1ColorHsb.x=mix(fb1ColorHsb.x,dither2(fb1ColorHsb.x,fb1_coord,fb1HueDitherAmount+fb1HueDitherAmountTexmod*fb1Texmod),
     fb1HueDitherMix +fb1HueDitherMixTexmod*fb1Texmod );
     fb1ColorHsb.y=mix(fb1ColorHsb.y,dither2(fb1ColorHsb.y,fb1_coord,fb1SaturationDitherAmount+fb1SaturationDitherAmountTexmod*fb1Texmod),
     fb1SaturationDitherMix +fb1SaturationDitherMixTexmod*fb1Texmod );
     fb1ColorHsb.z=mix(fb1ColorHsb.z,dither2(fb1ColorHsb.z,fb1_coord,fb1BrightDitherAmount+fb1BrightDitherAmountTexmod*fb1Texmod),
     fb1BrightDitherMix +fb1BrightDitherMixTexmod*fb1Texmod );
     */
    fb1ColorHsb.x=mix(fb1ColorHsb.x,dither2(fb1ColorHsb.x,fb1_coord,fb1HueDitherAmount),fb1HueDitherMix );
    fb1ColorHsb.y=mix(fb1ColorHsb.y,dither2(fb1ColorHsb.y,fb1_coord,fb1SaturationDitherAmount),fb1SaturationDitherMix );
    fb1ColorHsb.z=mix(fb1ColorHsb.z,dither2(fb1ColorHsb.z,fb1_coord,fb1BrightDitherAmount),fb1BrightDitherMix  );
    //powmap
    
    
    //invert
    if(fb1HsbInvert.x==1){
        fb1ColorHsb.x=1.0-fb1ColorHsb.x;
    }
    if(fb1HsbInvert.y==1){
        fb1ColorHsb.y=1.0-fb1ColorHsb.y;
    }
    if(fb1HsbInvert.z==1){
        fb1ColorHsb.z=1.0-fb1ColorHsb.z;
    }
    //clamp/wrap/fold
    if(fb1SaturationOverflow==0){
        fb1ColorHsb.y=clamp(fb1ColorHsb.y,0.0,1.0);
    }
    if(fb1SaturationOverflow==1){
        fb1ColorHsb.y=wrap(fb1ColorHsb.y);
    }
    if(fb1SaturationOverflow==2){
        fb1ColorHsb.y=foldover(fb1ColorHsb.y);
    }
    if(fb1BrightOverflow==0){
        fb1ColorHsb.z=clamp(fb1ColorHsb.z,0.0,1.0);
    }
    if(fb1BrightOverflow==1){
        fb1ColorHsb.z=wrap(fb1ColorHsb.z);
    }
    if(fb1BrightOverflow==2){
        fb1ColorHsb.z=foldover(fb1ColorHsb.z);
    }
    fb1ColorHsb=pow(fb1ColorHsb,fb1PowMap+fb1Texmod*fb1HsbPowMapTexmod);

    
    
    
    
    
    
    
    
    
    //fb2 COLOR
    //shaper
    fb2ColorHsb.x=hueShaper(fb2ColorHsb.x,fb2HueShaper+fb2Texmod*fb2HueShaperTexmod);
    //attenuate & offset
    fb2ColorHsb=(fb2ColorHsb+fb2HsbOffset+fb2Texmod*fb2HsbOffsetTexmod)*(fb2HsbAttenuate+fb2Texmod*fb2HsbAttenuateTexmod);
    //posterize
    
    
    //something in here is making fb2 all black
    //something to do with fb2ColorQuantizeDenomTexmod
    //actually i don't think we can do texmods for these ones...now that i think about it
    /*
     fb2ColorHsb.x=mix( fb2ColorHsb.x,colorQuantize( fb2ColorHsb.x,
     fb2ColorQuantize.x+fb2ColorQuantizeTexmod.x*fb2Texmod,
     fb2ColorQuantizeDenom.x),
     fb2ColorQuantizeMix.x);
     /*
     fb2ColorHsb.y=mix(fb2ColorHsb.y,colorQuantize(fb2ColorHsb.y,
     fb2ColorQuantize.y+fb2ColorQuantizeTexmod.y*fb2Texmod,
     fb2ColorQuantizeDenom.y+fb2ColorQuantizeDenomTexmod.y*fb2Texmod),
     fb2ColorQuantizeMix.y+fb2ColorQuantizeMixTexmod.y*fb2Texmod);
     
     fb2ColorHsb.z=mix(fb2ColorHsb.z,colorQuantize(fb2ColorHsb.z,
     fb2ColorQuantize.z+fb2ColorQuantizeTexmod.z*fb2Texmod,
     fb2ColorQuantizeDenom.z+fb2ColorQuantizeDenomTexmod.z*fb2Texmod),
     fb2ColorQuantizeMix.z+fb2ColorQuantizeMixTexmod.z*fb2Texmod);
     */
    
    fb2ColorHsb.x=mix(fb2ColorHsb.x,colorQuantize(fb2ColorHsb.x,fb2ColorQuantize.x,fb2ColorQuantizeDenom.x),fb2ColorQuantizeMix.x);
    fb2ColorHsb.y=mix(fb2ColorHsb.y,colorQuantize(fb2ColorHsb.y,fb2ColorQuantize.y,fb2ColorQuantizeDenom.y),fb2ColorQuantizeMix.y);
    fb2ColorHsb.z=mix(fb2ColorHsb.z,colorQuantize(fb2ColorHsb.z,fb2ColorQuantize.z,fb2ColorQuantizeDenom.z),fb2ColorQuantizeMix.z);
    //dither2
    /*
     something in here is causing a fatal error lol  lets just not
     fb2ColorHsb.x=mix(fb2ColorHsb.x,dither2(fb2ColorHsb.x,fb2_coord,fb2HueDitherAmount+fb2HueDitherAmountTexmod*fb2Texmod),
     fb2HueDitherMix +fb2HueDitherMixTexmod*fb2Texmod );
     fb2ColorHsb.y=mix(fb2ColorHsb.y,dither2(fb2ColorHsb.y,fb2_coord,fb2SaturationDitherAmount+fb2SaturationDitherAmountTexmod*fb2Texmod),
     fb2SaturationDitherMix +fb2SaturationDitherMixTexmod*fb2Texmod );
     fb2ColorHsb.z=mix(fb2ColorHsb.z,dither2(fb2ColorHsb.z,fb2_coord,fb2BrightDitherAmount+fb2BrightDitherAmountTexmod*fb2Texmod),
     fb2BrightDitherMix +fb2BrightDitherMixTexmod*fb2Texmod );
     */
    fb2ColorHsb.x=mix(fb2ColorHsb.x,dither2(fb2ColorHsb.x,fb2_coord,fb2HueDitherAmount),fb2HueDitherMix );
    fb2ColorHsb.y=mix(fb2ColorHsb.y,dither2(fb2ColorHsb.y,fb2_coord,fb2SaturationDitherAmount),fb2SaturationDitherMix );
    fb2ColorHsb.z=mix(fb2ColorHsb.z,dither2(fb2ColorHsb.z,fb2_coord,fb2BrightDitherAmount),fb2BrightDitherMix  );
    //powmap
    
    
    //invert
    if(fb2HsbInvert.x==1){
        fb2ColorHsb.x=1.0-fb2ColorHsb.x;
    }
    if(fb2HsbInvert.y==1){
        fb2ColorHsb.y=1.0-fb2ColorHsb.y;
    }
    if(fb2HsbInvert.z==1){
        fb2ColorHsb.z=1.0-fb2ColorHsb.z;
    }
    //clamp/wrap/fold
    if(fb2SaturationOverflow==0){
        fb2ColorHsb.y=clamp(fb2ColorHsb.y,0.0,1.0);
    }
    if(fb2SaturationOverflow==1){
        fb2ColorHsb.y=wrap(fb2ColorHsb.y);
    }
    if(fb2SaturationOverflow==2){
        fb2ColorHsb.y=foldover(fb2ColorHsb.y);
    }
    if(fb2BrightOverflow==0){
        fb2ColorHsb.z=clamp(fb2ColorHsb.z,0.0,1.0);
    }
    if(fb2BrightOverflow==1){
        fb2ColorHsb.z=wrap(fb2ColorHsb.z);
    }
    if(fb2BrightOverflow==2){
        fb2ColorHsb.z=foldover(fb2ColorHsb.z);
    }
    fb2ColorHsb=pow(fb2ColorHsb,fb2PowMap+fb2Texmod*fb2HsbPowMapTexmod);
    
    

    
    
    
    
    
    
    
   
    
    //fb3 COLOR
    //shaper
    fb3ColorHsb.x=hueShaper(fb3ColorHsb.x,fb3HueShaper+fb3Texmod*fb3HueShaperTexmod);
    //attenuate & offset
    fb3ColorHsb=(fb3ColorHsb+fb3HsbOffset+fb3Texmod*fb3HsbOffsetTexmod)*(fb3HsbAttenuate+fb3Texmod*fb3HsbAttenuateTexmod);
    //posterize
    
    
    //something in here is making fb3 all black
    //something to do with fb3ColorQuantizeDenomTexmod
    //actually i don't think we can do texmods for these ones...now that i think about it
    /*
     fb3ColorHsb.x=mix( fb3ColorHsb.x,colorQuantize( fb3ColorHsb.x,
     fb3ColorQuantize.x+fb3ColorQuantizeTexmod.x*fb3Texmod,
     fb3ColorQuantizeDenom.x),
     fb3ColorQuantizeMix.x);
     /*
     fb3ColorHsb.y=mix(fb3ColorHsb.y,colorQuantize(fb3ColorHsb.y,
     fb3ColorQuantize.y+fb3ColorQuantizeTexmod.y*fb3Texmod,
     fb3ColorQuantizeDenom.y+fb3ColorQuantizeDenomTexmod.y*fb3Texmod),
     fb3ColorQuantizeMix.y+fb3ColorQuantizeMixTexmod.y*fb3Texmod);
     
     fb3ColorHsb.z=mix(fb3ColorHsb.z,colorQuantize(fb3ColorHsb.z,
     fb3ColorQuantize.z+fb3ColorQuantizeTexmod.z*fb3Texmod,
     fb3ColorQuantizeDenom.z+fb3ColorQuantizeDenomTexmod.z*fb3Texmod),
     fb3ColorQuantizeMix.z+fb3ColorQuantizeMixTexmod.z*fb3Texmod);
     */
    
    fb3ColorHsb.x=mix(fb3ColorHsb.x,colorQuantize(fb3ColorHsb.x,fb3ColorQuantize.x,fb3ColorQuantizeDenom.x),fb3ColorQuantizeMix.x);
    fb3ColorHsb.y=mix(fb3ColorHsb.y,colorQuantize(fb3ColorHsb.y,fb3ColorQuantize.y,fb3ColorQuantizeDenom.y),fb3ColorQuantizeMix.y);
    fb3ColorHsb.z=mix(fb3ColorHsb.z,colorQuantize(fb3ColorHsb.z,fb3ColorQuantize.z,fb3ColorQuantizeDenom.z),fb3ColorQuantizeMix.z);
    //dither2
    /*
     something in here is causing a fatal error lol  lets just not
     fb3ColorHsb.x=mix(fb3ColorHsb.x,dither2(fb3ColorHsb.x,fb3_coord,fb3HueDitherAmount+fb3HueDitherAmountTexmod*fb3Texmod),
     fb3HueDitherMix +fb3HueDitherMixTexmod*fb3Texmod );
     fb3ColorHsb.y=mix(fb3ColorHsb.y,dither2(fb3ColorHsb.y,fb3_coord,fb3SaturationDitherAmount+fb3SaturationDitherAmountTexmod*fb3Texmod),
     fb3SaturationDitherMix +fb3SaturationDitherMixTexmod*fb3Texmod );
     fb3ColorHsb.z=mix(fb3ColorHsb.z,dither2(fb3ColorHsb.z,fb3_coord,fb3BrightDitherAmount+fb3BrightDitherAmountTexmod*fb3Texmod),
     fb3BrightDitherMix +fb3BrightDitherMixTexmod*fb3Texmod );
     */
    fb3ColorHsb.x=mix(fb3ColorHsb.x,dither2(fb3ColorHsb.x,fb3_coord,fb3HueDitherAmount),fb3HueDitherMix );
    fb3ColorHsb.y=mix(fb3ColorHsb.y,dither2(fb3ColorHsb.y,fb3_coord,fb3SaturationDitherAmount),fb3SaturationDitherMix );
    fb3ColorHsb.z=mix(fb3ColorHsb.z,dither2(fb3ColorHsb.z,fb3_coord,fb3BrightDitherAmount),fb3BrightDitherMix  );
    //powmap
    
    
    //invert
    if(fb3HsbInvert.x==1){
        fb3ColorHsb.x=1.0-fb3ColorHsb.x;
    }
    if(fb3HsbInvert.y==1){
        fb3ColorHsb.y=1.0-fb3ColorHsb.y;
    }
    if(fb3HsbInvert.z==1){
        fb3ColorHsb.z=1.0-fb3ColorHsb.z;
    }
    //clamp/wrap/fold
    if(fb3SaturationOverflow==0){
        fb3ColorHsb.y=clamp(fb3ColorHsb.y,0.0,1.0);
    }
    if(fb3SaturationOverflow==1){
        fb3ColorHsb.y=wrap(fb3ColorHsb.y);
    }
    if(fb3SaturationOverflow==2){
        fb3ColorHsb.y=foldover(fb3ColorHsb.y);
    }
    if(fb3BrightOverflow==0){
        fb3ColorHsb.z=clamp(fb3ColorHsb.z,0.0,1.0);
    }
    if(fb3BrightOverflow==1){
        fb3ColorHsb.z=wrap(fb3ColorHsb.z);
    }
    if(fb3BrightOverflow==2){
        fb3ColorHsb.z=foldover(fb3ColorHsb.z);
    }
    fb3ColorHsb=pow(fb3ColorHsb,fb3PowMap+fb3Texmod*fb3HsbPowMapTexmod);
    

	
	//convert back to vec4 rgb
    
    
    
    //switch on and off alpha in here... and test a lot more

    fb0Color=vec4(vec3(hsv2rgb(fb0ColorHsb)),1.0);
    fb1Color=vec4(vec3(hsv2rgb(fb1ColorHsb)),1.0);
    fb2Color=vec4(vec3(hsv2rgb(fb2ColorHsb)),1.0);
    fb3Color=vec4(vec3(hsv2rgb(fb3ColorHsb)),1.0);
    
    //next we do the mixxxing

    
    
    
    
    
    //rescaling masks stuff
    //need switch these from being hardcoded at some point
    float maskWidth=1280.0;
    float maskHeight=720.0;
    float maskWidthRatio=maskWidth/width;
    float maskHeightRatio=maskHeight/height;
    vec2 maskCenter=vec2(center.x*maskWidthRatio,center.y*maskHeightRatio);
    
    
	//fb0 wipes and masks
    vec4 fb0MaskColor=vec4(0,0,0,0);
	
	//standard mask modes
	if(fb0MaskTexmod!=4){
        vec2 fb0MaskCoords=texCoordVarying;
        
        //rescale to fit for different sizes
        fb0MaskCoords.x=maskWidthRatio*fb0MaskCoords.x;
        fb0MaskCoords.y=maskHeightRatio*fb0MaskCoords.y;
        
        fb0MaskCoords=fb0MaskCoords-maskCenter;
		fb0MaskCoords=fb0MaskCoords*(fb0MaskZ+fb0MaskZTexmod*fb0Texmod);

		if(fb0MaskTileMode==1){
			fb0MaskCoords+=maskCenter;
			fb0MaskCoords=mod(fb0MaskCoords,vec2((fb0MaskTileAmount+fb0MaskTileAmountTexmod*fb0Texmod)*width,
						(fb0MaskTileAmount+fb0MaskTileAmountTexmod*fb0Texmod)*height));
			fb0MaskCoords-=maskCenter;
		}

		if(fb0MaskTileMode==3){
			fb0MaskCoords+=maskCenter;
			fb0MaskCoords=spiralize(fb0MaskCoords,1.0,1.57,vec2(0,0));
			fb0MaskCoords=mod(fb0MaskCoords,vec2((fb0MaskTileAmount+fb0MaskTileAmountTexmod*fb0Texmod)*width,
						(fb0MaskTileAmount+fb0MaskTileAmountTexmod*fb0Texmod)*height));
			fb0MaskCoords-=maskCenter;
		}

		fb0MaskCoords+=vec2(fb0MaskX+fb0MaskXTexmod*fb0Texmod,fb0MaskY+fb0MaskYTexmod*fb0Texmod)+maskCenter;
		
        //FIXXX THIS, try scaling coords back out and then back in ugh
        fb0MaskCoords.x=fb0MaskCoords.x/maskWidthRatio;
        fb0MaskCoords.y=fb0MaskCoords.y/maskHeightRatio;
        fb0MaskCoords=rotate(fb0MaskCoords,fb0MaskRotate+fb0MaskRotateTexmod*fb0Texmod,0);
        fb0MaskCoords.x=maskWidthRatio*fb0MaskCoords.x;
        fb0MaskCoords.y=maskHeightRatio*fb0MaskCoords.y;
	
		if(fb0MaskTileMode==2){
			fb0MaskCoords=mod(fb0MaskCoords,vec2((fb0MaskTileAmount+fb0MaskTileAmountTexmod*fb0Texmod)*width,
						(fb0MaskTileAmount+fb0MaskTileAmountTexmod*fb0Texmod)*height));
		}

		
		fb0MaskColor=texture2DRect(fb0Mask, fb0MaskCoords);
	}
	
	//texmod mask mode
	if(fb0MaskTexmod==4){
		float fb0TexmodQuantized=colorQuantize(fb0Texmod+fb0MaskTexmodOffset,fb0MaskTexmodQuantizeAmount,fb0MaskTexmodQuantizeInvert);
		fb0MaskColor=mix(vec4(fb0Texmod,fb0Texmod,fb0Texmod,1.0),vec4(fb0TexmodQuantized,fb0TexmodQuantized,fb0TexmodQuantized,1.0),fb0MaskTexmodQuantizeMix);
	}
    
    
    
    
    
    
    
    //fb1 wipes and masks
    vec4 fb1MaskColor=vec4(0,0,0,0);
    
    //standard mask modes
    if(fb1MaskTexmod!=4){
        vec2 fb1MaskCoords=texCoordVarying;
        
        //rescale to fit for different sizes
        fb1MaskCoords.x=maskWidthRatio*fb1MaskCoords.x;
        fb1MaskCoords.y=maskHeightRatio*fb1MaskCoords.y;
        
        fb1MaskCoords=fb1MaskCoords-maskCenter;
        fb1MaskCoords=fb1MaskCoords*(fb1MaskZ+fb1MaskZTexmod*fb1Texmod);
        
        if(fb1MaskTileMode==1){
            fb1MaskCoords+=vec2(maskCenter);
            fb1MaskCoords=mod(fb1MaskCoords,vec2((fb1MaskTileAmount+fb1MaskTileAmountTexmod*fb1Texmod)*width,
                                                 (fb1MaskTileAmount+fb1MaskTileAmountTexmod*fb1Texmod)*height));
            fb1MaskCoords-=vec2(maskCenter);
        }
        
        if(fb1MaskTileMode==3){
            fb1MaskCoords+=vec2(maskCenter);
            fb1MaskCoords=spiralize(fb1MaskCoords,1.0,1.57,vec2(0,0));
            fb1MaskCoords=mod(fb1MaskCoords,vec2((fb1MaskTileAmount+fb1MaskTileAmountTexmod*fb1Texmod)*width,
                                                 (fb1MaskTileAmount+fb1MaskTileAmountTexmod*fb1Texmod)*height));
            fb1MaskCoords-=vec2(maskCenter);
        }
        
        fb1MaskCoords+=vec2(fb1MaskX+fb1MaskXTexmod*fb1Texmod,fb1MaskY+fb1MaskYTexmod*fb1Texmod)+maskCenter;
        
        
        fb1MaskCoords.x=fb1MaskCoords.x/maskWidthRatio;
        fb1MaskCoords.y=fb1MaskCoords.y/maskHeightRatio;
        fb1MaskCoords=rotate(fb1MaskCoords,fb1MaskRotate+fb1MaskRotateTexmod*fb1Texmod,0);
        fb1MaskCoords.x=maskWidthRatio*fb1MaskCoords.x;
        fb1MaskCoords.y=maskHeightRatio*fb1MaskCoords.y;
        
        if(fb1MaskTileMode==2){
            fb1MaskCoords=mod(fb1MaskCoords,vec2((fb1MaskTileAmount+fb1MaskTileAmountTexmod*fb1Texmod)*width,
                                                 (fb1MaskTileAmount+fb1MaskTileAmountTexmod*fb1Texmod)*height));
        }

        fb1MaskColor=texture2DRect(fb1Mask, fb1MaskCoords);
    }
    
    //texmod mask mode
    if(fb1MaskTexmod==4){
        float fb1TexmodQuantized=colorQuantize(fb1Texmod+fb1MaskTexmodOffset,fb1MaskTexmodQuantizeAmount,fb1MaskTexmodQuantizeInvert);
        fb1MaskColor=mix(vec4(fb1Texmod,fb1Texmod,fb1Texmod,1.0),vec4(fb1TexmodQuantized,fb1TexmodQuantized,fb1TexmodQuantized,1.0),fb1MaskTexmodQuantizeMix);
    }
    
    
    
    
    
    
    
    //fb2 wipes and masks
    vec4 fb2MaskColor=vec4(0,0,0,0);
    
    //standard mask modes
    if(fb2MaskTexmod!=4){
        vec2 fb2MaskCoords=texCoordVarying;
        
        //rescale to fit for different sizes
        fb2MaskCoords.x=maskWidthRatio*fb2MaskCoords.x;
        fb2MaskCoords.y=maskHeightRatio*fb2MaskCoords.y;
        
        fb2MaskCoords=fb2MaskCoords-maskCenter;
        fb2MaskCoords=fb2MaskCoords*(fb2MaskZ+fb2MaskZTexmod*fb2Texmod);
        
        if(fb2MaskTileMode==1){
            fb2MaskCoords+=vec2(maskCenter);
            fb2MaskCoords=mod(fb2MaskCoords,vec2((fb2MaskTileAmount+fb2MaskTileAmountTexmod*fb2Texmod)*width,
                                                 (fb2MaskTileAmount+fb2MaskTileAmountTexmod*fb2Texmod)*height));
            fb2MaskCoords-=vec2(maskCenter);
        }
        
        if(fb2MaskTileMode==3){
            fb2MaskCoords+=vec2(maskCenter);
            fb2MaskCoords=spiralize(fb2MaskCoords,1.0,1.57,vec2(0,0));
            fb2MaskCoords=mod(fb2MaskCoords,vec2((fb2MaskTileAmount+fb2MaskTileAmountTexmod*fb2Texmod)*width,
                                                 (fb2MaskTileAmount+fb2MaskTileAmountTexmod*fb2Texmod)*height));
            fb2MaskCoords-=vec2(maskCenter);
        }
        
        fb2MaskCoords+=vec2(fb2MaskX+fb2MaskXTexmod*fb2Texmod,fb2MaskY+fb2MaskYTexmod*fb2Texmod)+maskCenter;
        
        
        fb2MaskCoords.x=fb2MaskCoords.x/maskWidthRatio;
        fb2MaskCoords.y=fb2MaskCoords.y/maskHeightRatio;
        fb2MaskCoords=rotate(fb2MaskCoords,fb2MaskRotate+fb2MaskRotateTexmod*fb2Texmod,0);
        fb2MaskCoords.x=maskWidthRatio*fb2MaskCoords.x;
        fb2MaskCoords.y=maskHeightRatio*fb2MaskCoords.y;
        
        if(fb2MaskTileMode==2){
            fb2MaskCoords=mod(fb2MaskCoords,vec2((fb2MaskTileAmount+fb2MaskTileAmountTexmod*fb2Texmod)*width,
                                                 (fb2MaskTileAmount+fb2MaskTileAmountTexmod*fb2Texmod)*height));
        }
        
        fb2MaskColor=texture2DRect(fb2Mask, fb2MaskCoords);
    }
    
    //texmod mask mode
    if(fb2MaskTexmod==4){
        float fb2TexmodQuantized=colorQuantize(fb2Texmod+fb2MaskTexmodOffset,fb2MaskTexmodQuantizeAmount,fb2MaskTexmodQuantizeInvert);
        fb2MaskColor=mix(vec4(fb2Texmod,fb2Texmod,fb2Texmod,1.0),vec4(fb2TexmodQuantized,fb2TexmodQuantized,fb2TexmodQuantized,1.0),fb2MaskTexmodQuantizeMix);
    }
    
    
    
    
    
    
    
    
    
    
    //fb3 wipes and masks
    vec4 fb3MaskColor=vec4(0,0,0,0);
    
    //standard mask modes
    if(fb3MaskTexmod!=4){
        vec2 fb3MaskCoords=texCoordVarying;
        
        //rescale to fit for different sizes
        fb3MaskCoords.x=maskWidthRatio*fb3MaskCoords.x;
        fb3MaskCoords.y=maskHeightRatio*fb3MaskCoords.y;
        
        fb3MaskCoords=fb3MaskCoords-maskCenter;
        fb3MaskCoords=fb3MaskCoords*(fb3MaskZ+fb3MaskZTexmod*fb3Texmod);
        
        if(fb3MaskTileMode==1){
            fb3MaskCoords+=vec2(maskCenter);
            fb3MaskCoords=mod(fb3MaskCoords,vec2((fb3MaskTileAmount+fb3MaskTileAmountTexmod*fb3Texmod)*width,
                                                 (fb3MaskTileAmount+fb3MaskTileAmountTexmod*fb3Texmod)*height));
            fb3MaskCoords-=vec2(maskCenter);
        }
        
        if(fb3MaskTileMode==3){
            fb3MaskCoords+=vec2(maskCenter);
            fb3MaskCoords=spiralize(fb3MaskCoords,1.0,1.57,vec2(0,0));
            fb3MaskCoords=mod(fb3MaskCoords,vec2((fb3MaskTileAmount+fb3MaskTileAmountTexmod*fb3Texmod)*width,
                                                 (fb3MaskTileAmount+fb3MaskTileAmountTexmod*fb3Texmod)*height));
            fb3MaskCoords-=vec2(maskCenter);
        }
        
        fb3MaskCoords+=vec2(fb3MaskX+fb3MaskXTexmod*fb3Texmod,fb3MaskY+fb3MaskYTexmod*fb3Texmod)+maskCenter;
        
        
        fb3MaskCoords.x=fb3MaskCoords.x/maskWidthRatio;
        fb3MaskCoords.y=fb3MaskCoords.y/maskHeightRatio;
        fb3MaskCoords=rotate(fb3MaskCoords,fb3MaskRotate+fb3MaskRotateTexmod*fb3Texmod,0);
        fb3MaskCoords.x=maskWidthRatio*fb3MaskCoords.x;
        fb3MaskCoords.y=maskHeightRatio*fb3MaskCoords.y;
        
        if(fb3MaskTileMode==2){
            fb3MaskCoords=mod(fb3MaskCoords,vec2((fb3MaskTileAmount+fb3MaskTileAmountTexmod*fb3Texmod)*width,
                                                 (fb3MaskTileAmount+fb3MaskTileAmountTexmod*fb3Texmod)*height));
        }
        
        fb3MaskColor=texture2DRect(fb3Mask, fb3MaskCoords);
    }
    
    //texmod mask mode
    if(fb3MaskTexmod==4){
        float fb3TexmodQuantized=colorQuantize(fb3Texmod+fb3MaskTexmodOffset,fb3MaskTexmodQuantizeAmount,fb3MaskTexmodQuantizeInvert);
        fb3MaskColor=mix(vec4(fb3Texmod,fb3Texmod,fb3Texmod,1.0),vec4(fb3TexmodQuantized,fb3TexmodQuantized,fb3TexmodQuantized,1.0),fb3MaskTexmodQuantizeMix);
    }
    
    
    
    
    
    
    
    //ch1 into ch1
    vec4 mixout_color=ch1Color;
    
	//ch2 mix and key
    vec3 keyValue=vec3(ch2LumakeyLevel,
		ch2LumakeyLevel,
		ch2LumakeyLevel);
    
    if(ch2KeyMode==1){
		keyValue=vec3(ch2ChromakeyRed,
		ch2ChromakeyGreen,
		ch2ChromakeyBlue);
	}
    mixout_color=mixnKeyVideo(ch1Color,ch2Color,ch2Mix,
		ch2MixType,ch2KeyThreshold,
		ch2KeySoft,
		keyValue,
		ch2KeyOrder,ch2MixOverflow,vec4(0,0,0,0),0);
    
    
    
    //fb0 mix and key
	keyValue=vec3(fb0LumakeyLevel+fb0LumakeyLevelTexmod*fb0Texmod,
		fb0LumakeyLevel+fb0LumakeyLevelTexmod*fb0Texmod,
		fb0LumakeyLevel+fb0LumakeyLevelTexmod*fb0Texmod);

	int maskSwitch=0;

	if(fb0KeyMode==1){
		keyValue=vec3(fb0ChromakeyRed+fb0ChromakeyRedTexmod*fb0Texmod,
		fb0ChromakeyGreen+fb0ChromakeyGreenTexmod*fb0Texmod,
		fb0ChromakeyBlue+fb0ChromakeyBlueTexmod*fb0Texmod);
	}
	if(fb0KeyMode==2){
		maskSwitch=1;
	}

	mixout_color=mixnKeyVideo(mixout_color,fb0Color,fb0Mix+fb0MixTexmod*fb0Texmod,
		fb0MixType,fb0KeyThreshold+fb0KeyThresholdTexmod*fb0Texmod,
		fb0KeySoft+fb0KeySoftTexmod*fb0Texmod,
		keyValue,
		fb0KeyOrder,fb0MixOverflow,fb0MaskColor,maskSwitch);

    
    
    
    
    
    
    
    
    
    
    
    //fb1 mixing
    
    keyValue=vec3(fb1LumakeyLevel+fb1LumakeyLevelTexmod*fb1Texmod,
                  fb1LumakeyLevel+fb1LumakeyLevelTexmod*fb1Texmod,
                  fb1LumakeyLevel+fb1LumakeyLevelTexmod*fb1Texmod);
    
    maskSwitch=0;
    
    if(fb1KeyMode==1){
        keyValue=vec3(fb1ChromakeyRed+fb1ChromakeyRedTexmod*fb1Texmod,
                      fb1ChromakeyGreen+fb1ChromakeyGreenTexmod*fb1Texmod,
                      fb1ChromakeyBlue+fb1ChromakeyBlueTexmod*fb1Texmod);
    }
    if(fb1KeyMode==2){
        maskSwitch=1;
    }
    
    mixout_color=mixnKeyVideo(mixout_color,fb1Color,fb1Mix+fb1MixTexmod*fb1Texmod,
                              fb1MixType,fb1KeyThreshold+fb1KeyThresholdTexmod*fb1Texmod,
                              fb1KeySoft+fb1KeySoftTexmod*fb1Texmod,
                              keyValue,
                              fb1KeyOrder,fb1MixOverflow,fb1MaskColor,maskSwitch);
    
    
    
    
    
    
    
    
    
    
    
    
    //fb2

    //fb2 mixing
    
    keyValue=vec3(fb2LumakeyLevel+fb2LumakeyLevelTexmod*fb2Texmod,
                  fb2LumakeyLevel+fb2LumakeyLevelTexmod*fb2Texmod,
                  fb2LumakeyLevel+fb2LumakeyLevelTexmod*fb2Texmod);
    
    maskSwitch=0;
    
    if(fb2KeyMode==1){
        keyValue=vec3(fb2ChromakeyRed+fb2ChromakeyRedTexmod*fb2Texmod,
                      fb2ChromakeyGreen+fb2ChromakeyGreenTexmod*fb2Texmod,
                      fb2ChromakeyBlue+fb2ChromakeyBlueTexmod*fb2Texmod);
    }
    if(fb2KeyMode==2){
        maskSwitch=1;
    }
    
    mixout_color=mixnKeyVideo(mixout_color,fb2Color,fb2Mix+fb2MixTexmod*fb2Texmod,
                              fb2MixType,fb2KeyThreshold+fb2KeyThresholdTexmod*fb2Texmod,
                              fb2KeySoft+fb2KeySoftTexmod*fb2Texmod,
                              keyValue,
                              fb2KeyOrder,fb2MixOverflow,fb2MaskColor,maskSwitch);
    
    
    
    
    
    
    
    
    
    //fb3 mixing
    
    keyValue=vec3(fb3LumakeyLevel+fb3LumakeyLevelTexmod*fb3Texmod,
                  fb3LumakeyLevel+fb3LumakeyLevelTexmod*fb3Texmod,
                  fb3LumakeyLevel+fb3LumakeyLevelTexmod*fb3Texmod);
    
    maskSwitch=0;
    
    if(fb3KeyMode==1){
        keyValue=vec3(fb3ChromakeyRed+fb3ChromakeyRedTexmod*fb3Texmod,
                      fb3ChromakeyGreen+fb3ChromakeyGreenTexmod*fb3Texmod,
                      fb3ChromakeyBlue+fb3ChromakeyBlueTexmod*fb3Texmod);
    }
    if(fb3KeyMode==2){
        maskSwitch=1;
    }
    
    mixout_color=mixnKeyVideo(mixout_color,fb3Color,fb3Mix+fb3MixTexmod*fb3Texmod,
                              fb3MixType,fb3KeyThreshold+fb3KeyThresholdTexmod*fb3Texmod,
                              fb3KeySoft+fb3KeySoftTexmod*fb3Texmod,
                              keyValue,
                              fb3KeyOrder,fb3MixOverflow,fb3MaskColor,maskSwitch);
    
    
    
    
    
    
    
    
    
    
    
    
    gl_FragColor = mixout_color;
   
    //gl_FragColor = ch1Color;
 
}
