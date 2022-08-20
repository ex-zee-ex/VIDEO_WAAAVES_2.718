#pragma once

#include "ofMain.h"
//#include "ofxDatGui.h"
#include "ofxImGui.h"

class GuiApp : public ofBaseApp{
    
public:
public:
    void setup();
    void update();
    void draw();
  
	
	int outWidth = 1280;
	int outHeight = 720;

	float fisheyeC = .05;
	float fisheyeXC = .15;
	float fisheyeYC = .15;

	float spiralAmountC=1.0;
	float spiralAngleC=2.0;
	float spiralXC=.15;
	float spiralYC=.15;
	int kaleidoscopeC = 21;

	int quantizeC = 16;

	
    ofxImGui::Gui gui;
    

    
    //ch11New
	int channel1_select = 0;

	void ch1ResetAll();
	void ch1ResetAllParameters();
	void ch1ResetAllLfo();
	
	//ch1 adjust
    float ch1Scale=1.0;
    ofVec3f ch1HsbAttenuate;
    int ch1Quantize=32;
    bool ch1QuantizeSwitch=false;
    bool ch1HueInvert=false;
    bool ch1BrightInvert=false;
    bool ch1SaturationInvert=false;
	bool ch1HMirror = false;
	bool ch1VMirror = false;


	//ch1 pixels
	bool ch1PixelSwitch = 0;
	bool ch1PixelXYLock = 1;
	int ch1XPixelScale = 64;
	int ch1YPixelScale = 64;
	float ch1PixelMix = 1;
	float ch1PixelBrightscale = 0;

	//ch1 adjust lfo
	float ch1ScaleLfoTheta = .0;
	float ch1ScaleLfoAmp = .0;
	ofVec3f ch1HsbAttenuateLfoTheta;
	ofVec3f ch1HsbAttenuateLfoAmp;
	float ch1QuantizeLfoTheta = 0;
	float ch1QuantizeLfoAmp = 0;

	//ch1 pixel lfo
	float ch1XPixelScaleLfoTheta = 0;
	float ch1XPixelScaleLfoAmp = 0;
	float ch1YPixelScaleLfoTheta = 0;
	float ch1YPixelScaleLfoAmp = 0;
	float ch1PixelMixLfoTheta = 0;
	float ch1PixelMixLfoAmp = 0;
	float ch1PixelBrightscaleLfoTheta = 0;
	float ch1PixelBrightscaleLfoAmp = 0;
    
    //ch2
	int channel2_select = 1;

	void ch2ResetAll();
	void ch2ResetAllParameters();
	void ch2ResetAllLfo();
	int ch2KeyOrder = 0;
	int ch2KeyMode = 0;
	int ch2MixType = 0;
	int ch2MixOverflow = 0;

	float ch2LumakeyLevel = 0;
	float ch2ChromakeyRed = 0;
	float ch2ChromakeyGreen = 0;
	float ch2ChromakeyBlue = 0;
	float ch2KeyThreshold = 0;
	float ch2KeySoft = 0;
	float ch2Mix = 0;


	float ch2Scale = 1.0;
	ofVec3f ch2HsbAttenuate;
	int ch2Quantize = 32;
	bool ch2QuantizeSwitch = false;
	bool ch2HueInvert = false;
	bool ch2BrightInvert = false;
	bool ch2SaturationInvert = false;
    
	//ch2 pixels
	bool ch2PixelSwitch = 0;
	bool ch2PixelXYLock = 1;
	int ch2XPixelScale = 64;
	int ch2YPixelScale = 64;
	float ch2PixelMix = 1;
	float ch2PixelBrightscale = 0;

	//ch2 adjust lfo
	float ch2ScaleLfoTheta = .0;
	float ch2ScaleLfoAmp = .0;
	ofVec3f ch2HsbAttenuateLfoTheta;
	ofVec3f ch2HsbAttenuateLfoAmp;
	float ch2QuantizeLfoTheta = 0;
	float ch2QuantizeLfoAmp = 0;

	//ch2 pixel lfo
	float ch2XPixelScaleLfoTheta = 0;
	float ch2XPixelScaleLfoAmp = 0;
	float ch2YPixelScaleLfoTheta = 0;
	float ch2YPixelScaleLfoAmp = 0;
	float ch2PixelMixLfoTheta = 0;
	float ch2PixelMixLfoAmp = 0;
	float ch2PixelBrightscaleLfoTheta = 0;
	float ch2PixelBrightscaleLfoAmp = 0;
    
    
    //fb0
	int fb0DelayAmount = 0;

	//fb0MixnKey
	void fb0ResetAll();
	void fb0ResetAllParameters();
	void fb0ResetAllLfo();
	int fb0KeyOrder = 0;
	int fb0KeyMode = 0;
	int fb0MixType = 0;
	int fb0MixOverflow = 0;
	int fb0MaskSelect = 0;
	int fb0MaskTileMode = 0;

	float fb0LumakeyLevel = 0;
	float fb0ChromakeyRed = 0;
	float fb0ChromakeyGreen = 0;
	float fb0ChromakeyBlue = 0;
	float fb0KeyThreshold = 0;
	float fb0KeySoft = 0;
	float fb0Mix = 0;
	float fb0MaskX = 0;
	float fb0MaskY = 0;
	float fb0MaskZ = 1.0;
	float fb0MaskRotate = 0;
	float fb0MaskTileAmount = 1.0;
	float fb0MaskTexmodOffset = 0;
	int fb0MaskTexmodQuantizeAmount = 1.0;
	float fb0MaskTexmodQuantizeMix = 1.0;

	//fb0 mixNKey texmod
	float fb0LumakeyLevelTexmod = 0.0;
	float fb0ChromakeyRedTexmod = 0;
	float fb0ChromakeyGreenTexmod = 0;
	float fb0ChromakeyBlueTexmod = 0;
	float fb0KeyThresholdTexmod = 0.0;
	float fb0KeySoftTexmod = 0;
	float fb0MixTexmod = .0;
	float fb0MaskXTexmod = 0;
	float fb0MaskYTexmod = 0;
	float fb0MaskZTexmod = 0.0;
	float fb0MaskRotateTexmod = 0;
	float fb0MaskTileAmountTexmod = 0.0;

	//fb0MixnKeyLfo
	float fb0_delay_lfo_theta = 0;
	float fb0DelayLfoAmp = 0;
	float fb0MixLfoTheta = 0;
	float fb0MixLfoAmp = 0;

	float fb0LumakeyLevelLfoTheta = 0;
	float fb0LumakeyLevelLfoAmp = 0;
	
	float fb0ChromakeyRedLfoTheta = 0;
	float fb0ChromakeyRedLfoAmp = 0;
	float fb0ChromakeyGreenLfoTheta = 0;
	float fb0ChromakeyGreenLfoAmp = 0;
	float fb0ChromakeyBlueLfoTheta = 0;
	float fb0ChromakeyBlueLfoAmp = 0;

	float fb0KeyThresholdLfoTheta = 0;
	float fb0KeyThresholdLfoAmp = 0;
	float fb0KeySoftLfoTheta = 0;
	float fb0KeySoftLfoAmp = 0;

	float fb0MaskXLfoTheta = 0;
	float fb0MaskXLfoAmp = 0;
	float fb0MaskYLfoTheta = 0;
	float fb0MaskYLfoAmp = 0;
	float fb0MaskZLfoTheta = 0.0;
	float fb0MaskZLfoAmp = 0.0;
	float fb0MaskRotateLfoTheta = 0;
	float fb0MaskRotateLfoAmp = 0;
	float fb0MaskTileAmountLfoTheta = 0.0;
	float fb0MaskTileAmountLfoAmp = 0.0;

	float fb0MaskTexmodOffsetLfoTheta = 0;
	float fb0MaskTexmodOffsetLfoAmp = 0;
	float fb0MaskTexmodQuantizeAmountLfoTheta = 0.0;
	float fb0MaskTexmodQuantizeAmountLfoAmp = 0.0;
	float fb0MaskTexmodQuantizeMixLfoTheta = 0.0;
	float fb0MaskTexmodQuantizeMixLfoAmp = 0.0;
	

   //fb0Color
	bool fb0HueInvert = 0;
	bool fb0SaturationInvert = 0;
	bool fb0BrightInvert = 0;
	int fb0SaturationOverflow = 0;
	int fb0BrightOverflow = 0;

	float fb0HueOffset = 0.0;
	float fb0SaturationOffset = 0.0;
	float fb0BrightOffset = 0.0;
    float fb0HueAttenuate=10.0;
    float fb0SaturationAttenuate=10.0;
    float fb0BrightAttenuate=10.0;
	float fb0HueShaper = 0.0;
	float fb0HuePowMap = 1.0;
	float fb0SaturationPowMap = 1.0;
	float fb0BrightPowMap = 1.0;
    
	int fb0HueQuantize = 128;
	int fb0SaturationQuantize = 128;
	int fb0BrightQuantize = 128;
	float fb0HueQuantizeMix = 0.0;
	float fb0SaturationQuantizeMix = 0.0;
	float fb0BrightQuantizeMix = 0.0;
	float fb0HueDitherMix = 0.0;
	int fb0HueDitherAmount = 64;
	float fb0SaturationDitherMix = 0.0;
	int fb0SaturationDitherAmount =64;
	float fb0BrightDitherMix = 0.0;
	int fb0BrightDitherAmount = 64;
	
	

	//fb0ColorRanges
	int fb0HueDitherRange = 128;
	int fb0SaturationDitherRange = 128;
	int fb0BrightDitherRange = 128;
	int fb0HueQuantizeRange = 128;
	int fb0SaturationQuantizeRange = 128;
	int fb0BrightQuantizeRange = 128;
	float fb0HueShaperRange = 0.25;
	float fb0HueOffsetRange = .25;
	float fb0SaturationOffsetRange = 0.25;
	float fb0BrightOffsetRange = 0.25;
	float fb0HueAttenuateRange = 2.0;
	float fb0SaturationAttenuateRange = 2.0;
	float fb0BrightAttenuateRange = 2.0;
	float fb0HuePowMapRange = .25;
	float fb0SaturationPowMapRange = .25;
	float fb0BrightPowMapRange = .25;


	//fb0 color texmod


	//fb0ColorLfo

	float fb0HueOffsetLfoTheta = 0.0;
	float fb0SaturationOffsetLfoTheta = 0.0;
	float fb0BrightOffsetLfoTheta = 0.0;
	float fb0HueAttenuateLfoTheta = 0.0;
	float fb0SaturationAttenuateLfoTheta = 0.0;
	float fb0BrightAttenuateLfoTheta = 0.0;
	float fb0HueShaperLfoTheta = 0.0;
	float fb0HuePowMapLfoTheta = 0;
	float fb0SaturationPowMapLfoTheta = .0;
	float fb0BrightPowMapLfoTheta = .0;

	float fb0HueQuantizeLfoTheta = 0;
	float fb0SaturationQuantizeLfoTheta = 0;
	float fb0BrightQuantizeLfoTheta = 0;
	float fb0HueQuantizeMixLfoTheta = 0.0;
	float fb0SaturationQuantizeMixLfoTheta = 0.0;
	float fb0BrightQuantizeMixLfoTheta = 0.0;
	float fb0HueDitherMixLfoTheta = 0.0;
	float fb0HueDitherAmountLfoTheta = 0;
	float fb0SaturationDitherMixLfoTheta = 0.0;
	float fb0SaturationDitherAmountLfoTheta = 0;
	float fb0BrightDitherMixLfoTheta = 0.0;
	float fb0BrightDitherAmountLfoTheta = 0;

	

	float fb0HueOffsetLfoAmp = 0.0;
	float fb0SaturationOffsetLfoAmp = 0.0;
	float fb0BrightOffsetLfoAmp = 0.0;
	float fb0HueAttenuateLfoAmp = 0.0;
	float fb0SaturationAttenuateLfoAmp = 0.0;
	float fb0BrightAttenuateLfoAmp = 0.0;
	float fb0HueShaperLfoAmp = 0.0;
	float fb0HueQuantizeLfoAmp = 0;
	float fb0SaturationQuantizeLfoAmp = 0;
	float fb0BrightQuantizeLfoAmp = 0;
	float fb0HueQuantizeMixLfoAmp = 0.0;
	float fb0SaturationQuantizeMixLfoAmp = 0.0;
	float fb0BrightQuantizeMixLfoAmp = 0.0;
	float fb0HueDitherMixLfoAmp = 0.0;
	float fb0HueDitherAmountLfoAmp = 0;
	float fb0SaturationDitherMixLfoAmp = 0.0;
	float fb0SaturationDitherAmountLfoAmp = 0;
	float fb0BrightDitherMixLfoAmp = 0.0;
	float fb0BrightDitherAmountLfoAmp = 0;
	float fb0HuePowMapLfoAmp = 0;
	float fb0SaturationPowMapLfoAmp = .0;
	float fb0BrightPowMapLfoAmp = .0;

	//next up
	//GEOMETRY

	//fb0ColorTexmods
	float fb0HueOffsetTexmod = 0.0;
	float fb0SaturationOffsetTexmod = 0.0;
	float fb0BrightOffsetTexmod = 0.0;
	float fb0HueAttenuateTexmod = 0.0;
	float fb0SaturationAttenuateTexmod = 0.0;
	float fb0BrightAttenuateTexmod = 0.0;
	float fb0HueShaperTexmod = 0.0;
	float fb0HuePowMapTexmod = .0;
	float fb0SaturationPowMapTexmod = .0;
	float fb0BrightPowMapTexmod = .0;

    
    //delete these
	float fb0HueQuantizeTexmod = 0;
	float fb0SaturationQuantizeTexmod = 0;
	float fb0BrightQuantizeTexmod = 0;
	float fb0HueQuantizeMixTexmod = 0.0;
	float fb0SaturationQuantizeMixTexmod = 0.0;
	float fb0BrightQuantizeMixTexmod = 0.0;
	float fb0HueDitherMixTexmod = 0.0;
	float fb0HueDitherAmountTexmod = 0;
	float fb0SaturationDitherMixTexmod = 0.0;
	float fb0SaturationDitherAmountTexmod = 0;
	float fb0BrightDitherMixTexmod = 0.0;
	float fb0BrightDitherAmountTexmod = 0;
	

	//fb0 geo1
    float fb0XDisplace=0.0;
    float fb0YDisplace=0.0;
    float fb0ZDisplace=100.0;
    float fb0Rotate=0;
	ofVec4f fb0ShearMatrix;

	float fb0FisheyeAmount = 0;
	float fb0FisheyeX = 0;
	float fb0FisheyeY = 0;
	float fb0SpiralAmount = 0;
	float fb0SpiralAngle = 0;
	float fb0SpiralX = 0;
	float fb0SpiralY = 0;
	int fb0KaleidoscopeSegments = 0;
	float fb0KaleidoscopeSlice = 0;
	bool fb0RotateMode = 0;
	bool fb0HorizontalMirror = 0;
	bool fb0VerticalMirror = 0;
	int fb0_toroid_switch = 0;
    
    //fb0 geo rangemods
    float fb0XDisplaceRange=40;
    float fb0YDisplaceRange=40;
    float fb0ZDisplaceRange=10;
    float fb0ZRotateRange= PI;
	ofVec4f fb0ShearMatrixRange;
	
	float fb0FisheyeAmountRange = .15;
	float fb0FisheyeXRange = .25;
	float fb0FisheyeYRange = .25;
	float fb0SpiralAmountRange = .15;
	float fb0SpiralAngleRange = PI;
	float fb0SpiralXRange = .25;
	float fb0SpiralYRange = .25;
	int fb0KaleidoscopeSegmentsRange = 21;
	float fb0KaleidoscopeSliceRange = PI;
    
	//fb0 geo1 Lfo
	float fb0XDisplaceLfoTheta = 0.0;
	float fb0YDisplaceLfoTheta = 0.0;
	float fb0ZDisplaceLfoTheta = 0.0;
	float fb0RotateLfoTheta = 0;
	ofVec4f fb0ShearMatrixLfoTheta;
    
    float fb0XDisplaceLfoAmp = 0.0;
    float fb0YDisplaceLfoAmp = 0.0;
    float fb0ZDisplaceLfoAmp = 0.0;
    float fb0RotateLfoAmp = 0;
    ofVec4f fb0ShearMatrixLfoAmp;

    //fb0 geo2 Lfo
	float fb0FisheyeAmountLfoTheta = 0;
	float fb0FisheyeXLfoTheta = 0;
	float fb0FisheyeYLfoTheta = 0;
	float fb0SpiralAmountLfoTheta = 0;
	float fb0SpiralAngleLfoTheta = 0;
	float fb0SpiralXLfoTheta = 0;
	float fb0SpiralYLfoTheta = 0;
	float fb0KaleidoscopeSegmentsLfoTheta = 0;
	float fb0KaleidoscopeSliceLfoTheta = 0;

	float fb0FisheyeAmountLfoAmp = 0;
	float fb0FisheyeXLfoAmp = 0;
	float fb0FisheyeYLfoAmp = 0;
	float fb0SpiralAmountLfoAmp = 0;
	float fb0SpiralAngleLfoAmp = 0;
	float fb0SpiralXLfoAmp = 0;
	float fb0SpiralYLfoAmp = 0;
	float fb0KaleidoscopeSegmentsLfoAmp = 0;
	float fb0KaleidoscopeSliceLfoAmp = 0;

    //fbo geo 1 texmods
    float fb0XDisplaceTexmod=0.0;
    float fb0YDisplaceTexmod=0.0;
    float fb0ZDisplaceTexmod=0;
    float fb0RotateTexmod=0;
    ofVec4f fb0ShearMatrixTexmod;
    
    float fb0FisheyeAmountTexmod = 0;
    float fb0FisheyeXTexmod = 0;
    float fb0FisheyeYTexmod = 0;
    float fb0SpiralAmountTexmod = 0;
    float fb0SpiralAngleTexmod = 0;
    float fb0SpiralXTexmod = 0;
    float fb0SpiralYTexmod = 0;
    float fb0KaleidoscopeSegmentsTexmod = 0;
    float fb0KaleidoscopeSliceTexmod = 0;
    
    
    //fb0 pixels
    bool fb0PixelXYLock = 1;
    bool fb0PixelSwitch=0;
    int fb0XPixelScale=64;
    int fb0YPixelScale=64;
    float fb0PixelMix=1;
    float fb0PixelBrightscale=0;
    
    //fb0 pixel lfo
    float fb0XPixelScaleLfoTheta=0;
    float fb0XPixelScaleLfoAmp=0;
    float fb0YPixelScaleLfoTheta=0;
    float fb0YPixelScaleLfoAmp=0;
    float fb0PixelMixLfoTheta=0;
    float fb0PixelMixLfoAmp=0;
    float fb0PixelBrightscaleLfoTheta=0;
    float fb0PixelBrightscaleLfoAmp=0;
    
    //fb0 pixel texmods
    int  fb0XPixelScaleTexmod=0;
    int fb0YPixelScaleTexmod=0;
    float fb0PixelMixTexmod=0;
    float fb0PixelBrightscaleTexmod=0;
    
    
    //fb0 texmods
    int fb0TexmodSelect=2;
    bool fb0TexmodSwitch=false;
    


    
   
    


    
    
    //fb1
    int fb1DelayAmount = 0;
    
    //fb1MixnKey
    void fb1ResetAll();
    void fb1ResetAllParameters();
    void fb1ResetAllLfo();
    int fb1KeyOrder = 0;
    int fb1KeyMode = 0;
    int fb1MixType = 0;
    int fb1MixOverflow = 0;
    int fb1MaskSelect = 0;
    int fb1MaskTileMode = 0;
    
    float fb1LumakeyLevel = 0;
    float fb1ChromakeyRed = 0;
    float fb1ChromakeyGreen = 0;
    float fb1ChromakeyBlue = 0;
    float fb1KeyThreshold = 0;
    float fb1KeySoft = 0;
    float fb1Mix = 0;
    float fb1MaskX = 0;
    float fb1MaskY = 0;
    float fb1MaskZ = 1.0;
    float fb1MaskRotate = 0;
    float fb1MaskTileAmount = 1.0;
    float fb1MaskTexmodOffset = 0;
    int fb1MaskTexmodQuantizeAmount = 1.0;
    float fb1MaskTexmodQuantizeMix = 1.0;
    
    //fb1 mixNKey texmod
    float fb1LumakeyLevelTexmod = 0.0;
    float fb1ChromakeyRedTexmod = 0;
    float fb1ChromakeyGreenTexmod = 0;
    float fb1ChromakeyBlueTexmod = 0;
    float fb1KeyThresholdTexmod = 0.0;
    float fb1KeySoftTexmod = 0;
    float fb1MixTexmod = .0;
    float fb1MaskXTexmod = 0;
    float fb1MaskYTexmod = 0;
    float fb1MaskZTexmod = 0.0;
    float fb1MaskRotateTexmod = 0;
    float fb1MaskTileAmountTexmod = 0.0;
    
    //fb1MixnKeyLfo
    float fb1_delay_lfo_theta = 0;
    float fb1DelayLfoAmp = 0;
    float fb1MixLfoTheta = 0;
    float fb1MixLfoAmp = 0;
    
    float fb1LumakeyLevelLfoTheta = 0;
    float fb1LumakeyLevelLfoAmp = 0;
    
    float fb1ChromakeyRedLfoTheta = 0;
    float fb1ChromakeyRedLfoAmp = 0;
    float fb1ChromakeyGreenLfoTheta = 0;
    float fb1ChromakeyGreenLfoAmp = 0;
    float fb1ChromakeyBlueLfoTheta = 0;
    float fb1ChromakeyBlueLfoAmp = 0;
    
    float fb1KeyThresholdLfoTheta = 0;
    float fb1KeyThresholdLfoAmp = 0;
    float fb1KeySoftLfoTheta = 0;
    float fb1KeySoftLfoAmp = 0;
    
    float fb1MaskXLfoTheta = 0;
    float fb1MaskXLfoAmp = 0;
    float fb1MaskYLfoTheta = 0;
    float fb1MaskYLfoAmp = 0;
    float fb1MaskZLfoTheta = 0.0;
    float fb1MaskZLfoAmp = 0.0;
    float fb1MaskRotateLfoTheta = 0;
    float fb1MaskRotateLfoAmp = 0;
    float fb1MaskTileAmountLfoTheta = 0.0;
    float fb1MaskTileAmountLfoAmp = 0.0;
    
    float fb1MaskTexmodOffsetLfoTheta = 0;
    float fb1MaskTexmodOffsetLfoAmp = 0;
    float fb1MaskTexmodQuantizeAmountLfoTheta = 0.0;
    float fb1MaskTexmodQuantizeAmountLfoAmp = 0.0;
    float fb1MaskTexmodQuantizeMixLfoTheta = 0.0;
    float fb1MaskTexmodQuantizeMixLfoAmp = 0.0;
    
    
    //fb1Color
    bool fb1HueInvert = 0;
    bool fb1SaturationInvert = 0;
    bool fb1BrightInvert = 0;
    int fb1SaturationOverflow = 0;
    int fb1BrightOverflow = 0;
    
    float fb1HueOffset = 0.0;
    float fb1SaturationOffset = 0.0;
    float fb1BrightOffset = 0.0;
    float fb1HueAttenuate=10.0;
    float fb1SaturationAttenuate=10.0;
    float fb1BrightAttenuate=10.0;
    float fb1HueShaper = 0.0;
    float fb1HuePowMap = 1.0;
    float fb1SaturationPowMap = 1.0;
    float fb1BrightPowMap = 1.0;
    
    int fb1HueQuantize = 128;
    int fb1SaturationQuantize = 128;
    int fb1BrightQuantize = 128;
    float fb1HueQuantizeMix = 0.0;
    float fb1SaturationQuantizeMix = 0.0;
    float fb1BrightQuantizeMix = 0.0;
    float fb1HueDitherMix = 0.0;
    int fb1HueDitherAmount = 64;
    float fb1SaturationDitherMix = 0.0;
    int fb1SaturationDitherAmount =64;
    float fb1BrightDitherMix = 0.0;
    int fb1BrightDitherAmount = 64;
    
    
    
    //fb1ColorRanges
    int fb1HueDitherRange = 128;
    int fb1SaturationDitherRange = 128;
    int fb1BrightDitherRange = 128;
    int fb1HueQuantizeRange = 128;
    int fb1SaturationQuantizeRange = 128;
    int fb1BrightQuantizeRange = 128;
    float fb1HueShaperRange = 0.25;
    float fb1HueOffsetRange = .25;
    float fb1SaturationOffsetRange = 0.25;
    float fb1BrightOffsetRange = 0.25;
    float fb1HueAttenuateRange = 2.0;
    float fb1SaturationAttenuateRange = 2.0;
    float fb1BrightAttenuateRange = 2.0;
    float fb1HuePowMapRange = .25;
    float fb1SaturationPowMapRange = .25;
    float fb1BrightPowMapRange = .25;
    
    
    //fb1 color texmod
    
    
    //fb1ColorLfo
    
    float fb1HueOffsetLfoTheta = 0.0;
    float fb1SaturationOffsetLfoTheta = 0.0;
    float fb1BrightOffsetLfoTheta = 0.0;
    float fb1HueAttenuateLfoTheta = 0.0;
    float fb1SaturationAttenuateLfoTheta = 0.0;
    float fb1BrightAttenuateLfoTheta = 0.0;
    float fb1HueShaperLfoTheta = 0.0;
    float fb1HuePowMapLfoTheta = 0;
    float fb1SaturationPowMapLfoTheta = .0;
    float fb1BrightPowMapLfoTheta = .0;
    
    float fb1HueQuantizeLfoTheta = 0;
    float fb1SaturationQuantizeLfoTheta = 0;
    float fb1BrightQuantizeLfoTheta = 0;
    float fb1HueQuantizeMixLfoTheta = 0.0;
    float fb1SaturationQuantizeMixLfoTheta = 0.0;
    float fb1BrightQuantizeMixLfoTheta = 0.0;
    float fb1HueDitherMixLfoTheta = 0.0;
    float fb1HueDitherAmountLfoTheta = 0;
    float fb1SaturationDitherMixLfoTheta = 0.0;
    float fb1SaturationDitherAmountLfoTheta = 0;
    float fb1BrightDitherMixLfoTheta = 0.0;
    float fb1BrightDitherAmountLfoTheta = 0;
    
    
    
    float fb1HueOffsetLfoAmp = 0.0;
    float fb1SaturationOffsetLfoAmp = 0.0;
    float fb1BrightOffsetLfoAmp = 0.0;
    float fb1HueAttenuateLfoAmp = 0.0;
    float fb1SaturationAttenuateLfoAmp = 0.0;
    float fb1BrightAttenuateLfoAmp = 0.0;
    float fb1HueShaperLfoAmp = 0.0;
    float fb1HueQuantizeLfoAmp = 0;
    float fb1SaturationQuantizeLfoAmp = 0;
    float fb1BrightQuantizeLfoAmp = 0;
    float fb1HueQuantizeMixLfoAmp = 0.0;
    float fb1SaturationQuantizeMixLfoAmp = 0.0;
    float fb1BrightQuantizeMixLfoAmp = 0.0;
    float fb1HueDitherMixLfoAmp = 0.0;
    float fb1HueDitherAmountLfoAmp = 0;
    float fb1SaturationDitherMixLfoAmp = 0.0;
    float fb1SaturationDitherAmountLfoAmp = 0;
    float fb1BrightDitherMixLfoAmp = 0.0;
    float fb1BrightDitherAmountLfoAmp = 0;
    float fb1HuePowMapLfoAmp = 0;
    float fb1SaturationPowMapLfoAmp = .0;
    float fb1BrightPowMapLfoAmp = .0;
    
    //next up
    //GEOMETRY
    
    //fb1ColorTexmods
    float fb1HueOffsetTexmod = 0.0;
    float fb1SaturationOffsetTexmod = 0.0;
    float fb1BrightOffsetTexmod = 0.0;
    float fb1HueAttenuateTexmod = 0.0;
    float fb1SaturationAttenuateTexmod = 0.0;
    float fb1BrightAttenuateTexmod = 0.0;
    float fb1HueShaperTexmod = 0.0;
    float fb1HuePowMapTexmod = .0;
    float fb1SaturationPowMapTexmod = .0;
    float fb1BrightPowMapTexmod = .0;
    
    
    //delete these
    float fb1HueQuantizeTexmod = 0;
    float fb1SaturationQuantizeTexmod = 0;
    float fb1BrightQuantizeTexmod = 0;
    float fb1HueQuantizeMixTexmod = 0.0;
    float fb1SaturationQuantizeMixTexmod = 0.0;
    float fb1BrightQuantizeMixTexmod = 0.0;
    float fb1HueDitherMixTexmod = 0.0;
    float fb1HueDitherAmountTexmod = 0;
    float fb1SaturationDitherMixTexmod = 0.0;
    float fb1SaturationDitherAmountTexmod = 0;
    float fb1BrightDitherMixTexmod = 0.0;
    float fb1BrightDitherAmountTexmod = 0;
    
    
    //fb1 geo1
    float fb1XDisplace=0.0;
    float fb1YDisplace=0.0;
    float fb1ZDisplace=100.0;
    float fb1Rotate=0;
    ofVec4f fb1ShearMatrix;
    
    float fb1FisheyeAmount = 0;
    float fb1FisheyeX = 0;
    float fb1FisheyeY = 0;
    float fb1SpiralAmount = 0;
    float fb1SpiralAngle = 0;
    float fb1SpiralX = 0;
    float fb1SpiralY = 0;
    int fb1KaleidoscopeSegments = 0;
    float fb1KaleidoscopeSlice = 0;
    bool fb1RotateMode = 0;
    bool fb1HorizontalMirror = 0;
    bool fb1VerticalMirror = 0;
    int fb1_toroid_switch = 0;
    
    //fb1 geo rangemods
    float fb1XDisplaceRange=40;
    float fb1YDisplaceRange=40;
    float fb1ZDisplaceRange=10;
    float fb1ZRotateRange= PI;
    ofVec4f fb1ShearMatrixRange;
    
    float fb1FisheyeAmountRange = .15;
    float fb1FisheyeXRange = .25;
    float fb1FisheyeYRange = .25;
    float fb1SpiralAmountRange = .15;
    float fb1SpiralAngleRange = PI;
    float fb1SpiralXRange = .25;
    float fb1SpiralYRange = .25;
    int fb1KaleidoscopeSegmentsRange = 21;
    float fb1KaleidoscopeSliceRange = PI;
    
    //fb1 geo1 Lfo
    float fb1XDisplaceLfoTheta = 0.0;
    float fb1YDisplaceLfoTheta = 0.0;
    float fb1ZDisplaceLfoTheta = 0.0;
    float fb1RotateLfoTheta = 0;
    ofVec4f fb1ShearMatrixLfoTheta;
    
    float fb1XDisplaceLfoAmp = 0.0;
    float fb1YDisplaceLfoAmp = 0.0;
    float fb1ZDisplaceLfoAmp = 0.0;
    float fb1RotateLfoAmp = 0;
    ofVec4f fb1ShearMatrixLfoAmp;
    
    //fb1 geo2 Lfo
    float fb1FisheyeAmountLfoTheta = 0;
    float fb1FisheyeXLfoTheta = 0;
    float fb1FisheyeYLfoTheta = 0;
    float fb1SpiralAmountLfoTheta = 0;
    float fb1SpiralAngleLfoTheta = 0;
    float fb1SpiralXLfoTheta = 0;
    float fb1SpiralYLfoTheta = 0;
    float fb1KaleidoscopeSegmentsLfoTheta = 0;
    float fb1KaleidoscopeSliceLfoTheta = 0;
    
    float fb1FisheyeAmountLfoAmp = 0;
    float fb1FisheyeXLfoAmp = 0;
    float fb1FisheyeYLfoAmp = 0;
    float fb1SpiralAmountLfoAmp = 0;
    float fb1SpiralAngleLfoAmp = 0;
    float fb1SpiralXLfoAmp = 0;
    float fb1SpiralYLfoAmp = 0;
    float fb1KaleidoscopeSegmentsLfoAmp = 0;
    float fb1KaleidoscopeSliceLfoAmp = 0;
    
    //fbo geo 1 texmods
    float fb1XDisplaceTexmod=0.0;
    float fb1YDisplaceTexmod=0.0;
    float fb1ZDisplaceTexmod=0;
    float fb1RotateTexmod=0;
    ofVec4f fb1ShearMatrixTexmod;
    
    float fb1FisheyeAmountTexmod = 0;
    float fb1FisheyeXTexmod = 0;
    float fb1FisheyeYTexmod = 0;
    float fb1SpiralAmountTexmod = 0;
    float fb1SpiralAngleTexmod = 0;
    float fb1SpiralXTexmod = 0;
    float fb1SpiralYTexmod = 0;
    float fb1KaleidoscopeSegmentsTexmod = 0;
    float fb1KaleidoscopeSliceTexmod = 0;
    
    
    //fb1 pixels
    bool fb1PixelXYLock = 1;
    bool fb1PixelSwitch=0;
    int fb1XPixelScale=64;
    int fb1YPixelScale=64;
    float fb1PixelMix=1;
    float fb1PixelBrightscale=0;
    
    //fb1 pixel lfo
    float fb1XPixelScaleLfoTheta=0;
    float fb1XPixelScaleLfoAmp=0;
    float fb1YPixelScaleLfoTheta=0;
    float fb1YPixelScaleLfoAmp=0;
    float fb1PixelMixLfoTheta=0;
    float fb1PixelMixLfoAmp=0;
    float fb1PixelBrightscaleLfoTheta=0;
    float fb1PixelBrightscaleLfoAmp=0;
    
    //fb1 pixel texmods
    int  fb1XPixelScaleTexmod=0;
    int fb1YPixelScaleTexmod=0;
    float fb1PixelMixTexmod=0;
    float fb1PixelBrightscaleTexmod=0;
    
    
    //fb1 texmods
    int fb1TexmodSelect=2;
    bool fb1TexmodSwitch=false;
    

    //fb2
    int fb2DelayAmount = 0;
    
    //fb2MixnKey
    void fb2ResetAll();
    void fb2ResetAllParameters();
    void fb2ResetAllLfo();
    int fb2KeyOrder = 0;
    int fb2KeyMode = 0;
    int fb2MixType = 0;
    int fb2MixOverflow = 0;
    int fb2MaskSelect = 0;
    int fb2MaskTileMode = 0;
    
    float fb2LumakeyLevel = 0;
    float fb2ChromakeyRed = 0;
    float fb2ChromakeyGreen = 0;
    float fb2ChromakeyBlue = 0;
    float fb2KeyThreshold = 0;
    float fb2KeySoft = 0;
    float fb2Mix = 0;
    float fb2MaskX = 0;
    float fb2MaskY = 0;
    float fb2MaskZ = 1.0;
    float fb2MaskRotate = 0;
    float fb2MaskTileAmount = 1.0;
    float fb2MaskTexmodOffset = 0;
    int fb2MaskTexmodQuantizeAmount = 1.0;
    float fb2MaskTexmodQuantizeMix = 1.0;
    
    //fb2 mixNKey texmod
    float fb2LumakeyLevelTexmod = 0.0;
    float fb2ChromakeyRedTexmod = 0;
    float fb2ChromakeyGreenTexmod = 0;
    float fb2ChromakeyBlueTexmod = 0;
    float fb2KeyThresholdTexmod = 0.0;
    float fb2KeySoftTexmod = 0;
    float fb2MixTexmod = .0;
    float fb2MaskXTexmod = 0;
    float fb2MaskYTexmod = 0;
    float fb2MaskZTexmod = 0.0;
    float fb2MaskRotateTexmod = 0;
    float fb2MaskTileAmountTexmod = 0.0;
    
    //fb2MixnKeyLfo
    float fb2_delay_lfo_theta = 0;
    float fb2DelayLfoAmp = 0;
    float fb2MixLfoTheta = 0;
    float fb2MixLfoAmp = 0;
    
    float fb2LumakeyLevelLfoTheta = 0;
    float fb2LumakeyLevelLfoAmp = 0;
    
    float fb2ChromakeyRedLfoTheta = 0;
    float fb2ChromakeyRedLfoAmp = 0;
    float fb2ChromakeyGreenLfoTheta = 0;
    float fb2ChromakeyGreenLfoAmp = 0;
    float fb2ChromakeyBlueLfoTheta = 0;
    float fb2ChromakeyBlueLfoAmp = 0;
    
    float fb2KeyThresholdLfoTheta = 0;
    float fb2KeyThresholdLfoAmp = 0;
    float fb2KeySoftLfoTheta = 0;
    float fb2KeySoftLfoAmp = 0;
    
    float fb2MaskXLfoTheta = 0;
    float fb2MaskXLfoAmp = 0;
    float fb2MaskYLfoTheta = 0;
    float fb2MaskYLfoAmp = 0;
    float fb2MaskZLfoTheta = 0.0;
    float fb2MaskZLfoAmp = 0.0;
    float fb2MaskRotateLfoTheta = 0;
    float fb2MaskRotateLfoAmp = 0;
    float fb2MaskTileAmountLfoTheta = 0.0;
    float fb2MaskTileAmountLfoAmp = 0.0;
    
    float fb2MaskTexmodOffsetLfoTheta = 0;
    float fb2MaskTexmodOffsetLfoAmp = 0;
    float fb2MaskTexmodQuantizeAmountLfoTheta = 0.0;
    float fb2MaskTexmodQuantizeAmountLfoAmp = 0.0;
    float fb2MaskTexmodQuantizeMixLfoTheta = 0.0;
    float fb2MaskTexmodQuantizeMixLfoAmp = 0.0;
    
    
    //fb2Color
    bool fb2HueInvert = 0;
    bool fb2SaturationInvert = 0;
    bool fb2BrightInvert = 0;
    int fb2SaturationOverflow = 0;
    int fb2BrightOverflow = 0;
    
    float fb2HueOffset = 0.0;
    float fb2SaturationOffset = 0.0;
    float fb2BrightOffset = 0.0;
    float fb2HueAttenuate=10.0;
    float fb2SaturationAttenuate=10.0;
    float fb2BrightAttenuate=10.0;
    float fb2HueShaper = 0.0;
    float fb2HuePowMap = 1.0;
    float fb2SaturationPowMap = 1.0;
    float fb2BrightPowMap = 1.0;
    
    int fb2HueQuantize = 128;
    int fb2SaturationQuantize = 128;
    int fb2BrightQuantize = 128;
    float fb2HueQuantizeMix = 0.0;
    float fb2SaturationQuantizeMix = 0.0;
    float fb2BrightQuantizeMix = 0.0;
    float fb2HueDitherMix = 0.0;
    int fb2HueDitherAmount = 64;
    float fb2SaturationDitherMix = 0.0;
    int fb2SaturationDitherAmount =64;
    float fb2BrightDitherMix = 0.0;
    int fb2BrightDitherAmount = 64;
    
    
    
    //fb2ColorRanges
    int fb2HueDitherRange = 128;
    int fb2SaturationDitherRange = 128;
    int fb2BrightDitherRange = 128;
    int fb2HueQuantizeRange = 128;
    int fb2SaturationQuantizeRange = 128;
    int fb2BrightQuantizeRange = 128;
    float fb2HueShaperRange = 0.25;
    float fb2HueOffsetRange = .25;
    float fb2SaturationOffsetRange = 0.25;
    float fb2BrightOffsetRange = 0.25;
    float fb2HueAttenuateRange = 2.0;
    float fb2SaturationAttenuateRange = 2.0;
    float fb2BrightAttenuateRange = 2.0;
    float fb2HuePowMapRange = .25;
    float fb2SaturationPowMapRange = .25;
    float fb2BrightPowMapRange = .25;
    
    
    //fb2 color texmod
    
    
    //fb2ColorLfo
    
    float fb2HueOffsetLfoTheta = 0.0;
    float fb2SaturationOffsetLfoTheta = 0.0;
    float fb2BrightOffsetLfoTheta = 0.0;
    float fb2HueAttenuateLfoTheta = 0.0;
    float fb2SaturationAttenuateLfoTheta = 0.0;
    float fb2BrightAttenuateLfoTheta = 0.0;
    float fb2HueShaperLfoTheta = 0.0;
    float fb2HuePowMapLfoTheta = 0;
    float fb2SaturationPowMapLfoTheta = .0;
    float fb2BrightPowMapLfoTheta = .0;
    
    float fb2HueQuantizeLfoTheta = 0;
    float fb2SaturationQuantizeLfoTheta = 0;
    float fb2BrightQuantizeLfoTheta = 0;
    float fb2HueQuantizeMixLfoTheta = 0.0;
    float fb2SaturationQuantizeMixLfoTheta = 0.0;
    float fb2BrightQuantizeMixLfoTheta = 0.0;
    float fb2HueDitherMixLfoTheta = 0.0;
    float fb2HueDitherAmountLfoTheta = 0;
    float fb2SaturationDitherMixLfoTheta = 0.0;
    float fb2SaturationDitherAmountLfoTheta = 0;
    float fb2BrightDitherMixLfoTheta = 0.0;
    float fb2BrightDitherAmountLfoTheta = 0;
    
    
    
    float fb2HueOffsetLfoAmp = 0.0;
    float fb2SaturationOffsetLfoAmp = 0.0;
    float fb2BrightOffsetLfoAmp = 0.0;
    float fb2HueAttenuateLfoAmp = 0.0;
    float fb2SaturationAttenuateLfoAmp = 0.0;
    float fb2BrightAttenuateLfoAmp = 0.0;
    float fb2HueShaperLfoAmp = 0.0;
    float fb2HueQuantizeLfoAmp = 0;
    float fb2SaturationQuantizeLfoAmp = 0;
    float fb2BrightQuantizeLfoAmp = 0;
    float fb2HueQuantizeMixLfoAmp = 0.0;
    float fb2SaturationQuantizeMixLfoAmp = 0.0;
    float fb2BrightQuantizeMixLfoAmp = 0.0;
    float fb2HueDitherMixLfoAmp = 0.0;
    float fb2HueDitherAmountLfoAmp = 0;
    float fb2SaturationDitherMixLfoAmp = 0.0;
    float fb2SaturationDitherAmountLfoAmp = 0;
    float fb2BrightDitherMixLfoAmp = 0.0;
    float fb2BrightDitherAmountLfoAmp = 0;
    float fb2HuePowMapLfoAmp = 0;
    float fb2SaturationPowMapLfoAmp = .0;
    float fb2BrightPowMapLfoAmp = .0;
    
    //next up
    //GEOMETRY
    
    //fb2ColorTexmods
    float fb2HueOffsetTexmod = 0.0;
    float fb2SaturationOffsetTexmod = 0.0;
    float fb2BrightOffsetTexmod = 0.0;
    float fb2HueAttenuateTexmod = 0.0;
    float fb2SaturationAttenuateTexmod = 0.0;
    float fb2BrightAttenuateTexmod = 0.0;
    float fb2HueShaperTexmod = 0.0;
    float fb2HuePowMapTexmod = .0;
    float fb2SaturationPowMapTexmod = .0;
    float fb2BrightPowMapTexmod = .0;
    
    
    //delete these
    float fb2HueQuantizeTexmod = 0;
    float fb2SaturationQuantizeTexmod = 0;
    float fb2BrightQuantizeTexmod = 0;
    float fb2HueQuantizeMixTexmod = 0.0;
    float fb2SaturationQuantizeMixTexmod = 0.0;
    float fb2BrightQuantizeMixTexmod = 0.0;
    float fb2HueDitherMixTexmod = 0.0;
    float fb2HueDitherAmountTexmod = 0;
    float fb2SaturationDitherMixTexmod = 0.0;
    float fb2SaturationDitherAmountTexmod = 0;
    float fb2BrightDitherMixTexmod = 0.0;
    float fb2BrightDitherAmountTexmod = 0;
    
    
    //fb2 geo1
    float fb2XDisplace=0.0;
    float fb2YDisplace=0.0;
    float fb2ZDisplace=100.0;
    float fb2Rotate=0;
    ofVec4f fb2ShearMatrix;
    
    float fb2FisheyeAmount = 0;
    float fb2FisheyeX = 0;
    float fb2FisheyeY = 0;
    float fb2SpiralAmount = 0;
    float fb2SpiralAngle = 0;
    float fb2SpiralX = 0;
    float fb2SpiralY = 0;
    int fb2KaleidoscopeSegments = 0;
    float fb2KaleidoscopeSlice = 0;
    bool fb2RotateMode = 0;
    bool fb2HorizontalMirror = 0;
    bool fb2VerticalMirror = 0;
    int fb2_toroid_switch = 0;
    
    //fb2 geo rangemods
    float fb2XDisplaceRange=40;
    float fb2YDisplaceRange=40;
    float fb2ZDisplaceRange=10;
    float fb2ZRotateRange= PI;
    ofVec4f fb2ShearMatrixRange;
    
    float fb2FisheyeAmountRange = .15;
    float fb2FisheyeXRange = .25;
    float fb2FisheyeYRange = .25;
    float fb2SpiralAmountRange = .15;
    float fb2SpiralAngleRange = PI;
    float fb2SpiralXRange = .25;
    float fb2SpiralYRange = .25;
    int fb2KaleidoscopeSegmentsRange = 21;
    float fb2KaleidoscopeSliceRange = PI;
    
    //fb2 geo1 Lfo
    float fb2XDisplaceLfoTheta = 0.0;
    float fb2YDisplaceLfoTheta = 0.0;
    float fb2ZDisplaceLfoTheta = 0.0;
    float fb2RotateLfoTheta = 0;
    ofVec4f fb2ShearMatrixLfoTheta;
    
    float fb2XDisplaceLfoAmp = 0.0;
    float fb2YDisplaceLfoAmp = 0.0;
    float fb2ZDisplaceLfoAmp = 0.0;
    float fb2RotateLfoAmp = 0;
    ofVec4f fb2ShearMatrixLfoAmp;
    
    //fb2 geo2 Lfo
    float fb2FisheyeAmountLfoTheta = 0;
    float fb2FisheyeXLfoTheta = 0;
    float fb2FisheyeYLfoTheta = 0;
    float fb2SpiralAmountLfoTheta = 0;
    float fb2SpiralAngleLfoTheta = 0;
    float fb2SpiralXLfoTheta = 0;
    float fb2SpiralYLfoTheta = 0;
    float fb2KaleidoscopeSegmentsLfoTheta = 0;
    float fb2KaleidoscopeSliceLfoTheta = 0;
    
    float fb2FisheyeAmountLfoAmp = 0;
    float fb2FisheyeXLfoAmp = 0;
    float fb2FisheyeYLfoAmp = 0;
    float fb2SpiralAmountLfoAmp = 0;
    float fb2SpiralAngleLfoAmp = 0;
    float fb2SpiralXLfoAmp = 0;
    float fb2SpiralYLfoAmp = 0;
    float fb2KaleidoscopeSegmentsLfoAmp = 0;
    float fb2KaleidoscopeSliceLfoAmp = 0;
    
    //fbo geo 1 texmods
    float fb2XDisplaceTexmod=0.0;
    float fb2YDisplaceTexmod=0.0;
    float fb2ZDisplaceTexmod=0;
    float fb2RotateTexmod=0;
    ofVec4f fb2ShearMatrixTexmod;
    
    float fb2FisheyeAmountTexmod = 0;
    float fb2FisheyeXTexmod = 0;
    float fb2FisheyeYTexmod = 0;
    float fb2SpiralAmountTexmod = 0;
    float fb2SpiralAngleTexmod = 0;
    float fb2SpiralXTexmod = 0;
    float fb2SpiralYTexmod = 0;
    float fb2KaleidoscopeSegmentsTexmod = 0;
    float fb2KaleidoscopeSliceTexmod = 0;
    
    
    //fb2 pixels
    bool fb2PixelXYLock = 1;
    bool fb2PixelSwitch=0;
    int fb2XPixelScale=64;
    int fb2YPixelScale=64;
    float fb2PixelMix=1;
    float fb2PixelBrightscale=0;
    
    //fb2 pixel lfo
    float fb2XPixelScaleLfoTheta=0;
    float fb2XPixelScaleLfoAmp=0;
    float fb2YPixelScaleLfoTheta=0;
    float fb2YPixelScaleLfoAmp=0;
    float fb2PixelMixLfoTheta=0;
    float fb2PixelMixLfoAmp=0;
    float fb2PixelBrightscaleLfoTheta=0;
    float fb2PixelBrightscaleLfoAmp=0;
    
    //fb2 pixel texmods
    int  fb2XPixelScaleTexmod=0;
    int fb2YPixelScaleTexmod=0;
    float fb2PixelMixTexmod=0;
    float fb2PixelBrightscaleTexmod=0;
    
    
    //fb2 texmods
    int fb2TexmodSelect=2;
    bool fb2TexmodSwitch=false;
    
    
    
    
    //fb3
    int fb3DelayAmount = 0;
    
    //fb3MixnKey
    void fb3ResetAll();
    void fb3ResetAllParameters();
    void fb3ResetAllLfo();
    int fb3KeyOrder = 0;
    int fb3KeyMode = 0;
    int fb3MixType = 0;
    int fb3MixOverflow = 0;
    int fb3MaskSelect = 0;
    int fb3MaskTileMode = 0;
    
    float fb3LumakeyLevel = 0;
    float fb3ChromakeyRed = 0;
    float fb3ChromakeyGreen = 0;
    float fb3ChromakeyBlue = 0;
    float fb3KeyThreshold = 0;
    float fb3KeySoft = 0;
    float fb3Mix = 0;
    float fb3MaskX = 0;
    float fb3MaskY = 0;
    float fb3MaskZ = 1.0;
    float fb3MaskRotate = 0;
    float fb3MaskTileAmount = 1.0;
    float fb3MaskTexmodOffset = 0;
    int fb3MaskTexmodQuantizeAmount = 1.0;
    float fb3MaskTexmodQuantizeMix = 1.0;
    
    //fb3 mixNKey texmod
    float fb3LumakeyLevelTexmod = 0.0;
    float fb3ChromakeyRedTexmod = 0;
    float fb3ChromakeyGreenTexmod = 0;
    float fb3ChromakeyBlueTexmod = 0;
    float fb3KeyThresholdTexmod = 0.0;
    float fb3KeySoftTexmod = 0;
    float fb3MixTexmod = .0;
    float fb3MaskXTexmod = 0;
    float fb3MaskYTexmod = 0;
    float fb3MaskZTexmod = 0.0;
    float fb3MaskRotateTexmod = 0;
    float fb3MaskTileAmountTexmod = 0.0;
    
    //fb3MixnKeyLfo
    float fb3_delay_lfo_theta = 0;
    float fb3DelayLfoAmp = 0;
    float fb3MixLfoTheta = 0;
    float fb3MixLfoAmp = 0;
    
    float fb3LumakeyLevelLfoTheta = 0;
    float fb3LumakeyLevelLfoAmp = 0;
    
    float fb3ChromakeyRedLfoTheta = 0;
    float fb3ChromakeyRedLfoAmp = 0;
    float fb3ChromakeyGreenLfoTheta = 0;
    float fb3ChromakeyGreenLfoAmp = 0;
    float fb3ChromakeyBlueLfoTheta = 0;
    float fb3ChromakeyBlueLfoAmp = 0;
    
    float fb3KeyThresholdLfoTheta = 0;
    float fb3KeyThresholdLfoAmp = 0;
    float fb3KeySoftLfoTheta = 0;
    float fb3KeySoftLfoAmp = 0;
    
    float fb3MaskXLfoTheta = 0;
    float fb3MaskXLfoAmp = 0;
    float fb3MaskYLfoTheta = 0;
    float fb3MaskYLfoAmp = 0;
    float fb3MaskZLfoTheta = 0.0;
    float fb3MaskZLfoAmp = 0.0;
    float fb3MaskRotateLfoTheta = 0;
    float fb3MaskRotateLfoAmp = 0;
    float fb3MaskTileAmountLfoTheta = 0.0;
    float fb3MaskTileAmountLfoAmp = 0.0;
    
    float fb3MaskTexmodOffsetLfoTheta = 0;
    float fb3MaskTexmodOffsetLfoAmp = 0;
    float fb3MaskTexmodQuantizeAmountLfoTheta = 0.0;
    float fb3MaskTexmodQuantizeAmountLfoAmp = 0.0;
    float fb3MaskTexmodQuantizeMixLfoTheta = 0.0;
    float fb3MaskTexmodQuantizeMixLfoAmp = 0.0;
    
    
    //fb3Color
    bool fb3HueInvert = 0;
    bool fb3SaturationInvert = 0;
    bool fb3BrightInvert = 0;
    int fb3SaturationOverflow = 0;
    int fb3BrightOverflow = 0;
    
    float fb3HueOffset = 0.0;
    float fb3SaturationOffset = 0.0;
    float fb3BrightOffset = 0.0;
    float fb3HueAttenuate=10.0;
    float fb3SaturationAttenuate=10.0;
    float fb3BrightAttenuate=10.0;
    float fb3HueShaper = 0.0;
    float fb3HuePowMap = 1.0;
    float fb3SaturationPowMap = 1.0;
    float fb3BrightPowMap = 1.0;
    
    int fb3HueQuantize = 128;
    int fb3SaturationQuantize = 128;
    int fb3BrightQuantize = 128;
    float fb3HueQuantizeMix = 0.0;
    float fb3SaturationQuantizeMix = 0.0;
    float fb3BrightQuantizeMix = 0.0;
    float fb3HueDitherMix = 0.0;
    int fb3HueDitherAmount = 64;
    float fb3SaturationDitherMix = 0.0;
    int fb3SaturationDitherAmount =64;
    float fb3BrightDitherMix = 0.0;
    int fb3BrightDitherAmount = 64;
    
    
    
    //fb3ColorRanges
    int fb3HueDitherRange = 128;
    int fb3SaturationDitherRange = 128;
    int fb3BrightDitherRange = 128;
    int fb3HueQuantizeRange = 128;
    int fb3SaturationQuantizeRange = 128;
    int fb3BrightQuantizeRange = 128;
    float fb3HueShaperRange = 0.25;
    float fb3HueOffsetRange = .25;
    float fb3SaturationOffsetRange = 0.25;
    float fb3BrightOffsetRange = 0.25;
    float fb3HueAttenuateRange = 2.0;
    float fb3SaturationAttenuateRange = 2.0;
    float fb3BrightAttenuateRange = 2.0;
    float fb3HuePowMapRange = .25;
    float fb3SaturationPowMapRange = .25;
    float fb3BrightPowMapRange = .25;
    
    
    //fb3 color texmod
    
    
    //fb3ColorLfo
    
    float fb3HueOffsetLfoTheta = 0.0;
    float fb3SaturationOffsetLfoTheta = 0.0;
    float fb3BrightOffsetLfoTheta = 0.0;
    float fb3HueAttenuateLfoTheta = 0.0;
    float fb3SaturationAttenuateLfoTheta = 0.0;
    float fb3BrightAttenuateLfoTheta = 0.0;
    float fb3HueShaperLfoTheta = 0.0;
    float fb3HuePowMapLfoTheta = 0;
    float fb3SaturationPowMapLfoTheta = .0;
    float fb3BrightPowMapLfoTheta = .0;
    
    float fb3HueQuantizeLfoTheta = 0;
    float fb3SaturationQuantizeLfoTheta = 0;
    float fb3BrightQuantizeLfoTheta = 0;
    float fb3HueQuantizeMixLfoTheta = 0.0;
    float fb3SaturationQuantizeMixLfoTheta = 0.0;
    float fb3BrightQuantizeMixLfoTheta = 0.0;
    float fb3HueDitherMixLfoTheta = 0.0;
    float fb3HueDitherAmountLfoTheta = 0;
    float fb3SaturationDitherMixLfoTheta = 0.0;
    float fb3SaturationDitherAmountLfoTheta = 0;
    float fb3BrightDitherMixLfoTheta = 0.0;
    float fb3BrightDitherAmountLfoTheta = 0;
    
    
    
    float fb3HueOffsetLfoAmp = 0.0;
    float fb3SaturationOffsetLfoAmp = 0.0;
    float fb3BrightOffsetLfoAmp = 0.0;
    float fb3HueAttenuateLfoAmp = 0.0;
    float fb3SaturationAttenuateLfoAmp = 0.0;
    float fb3BrightAttenuateLfoAmp = 0.0;
    float fb3HueShaperLfoAmp = 0.0;
    float fb3HueQuantizeLfoAmp = 0;
    float fb3SaturationQuantizeLfoAmp = 0;
    float fb3BrightQuantizeLfoAmp = 0;
    float fb3HueQuantizeMixLfoAmp = 0.0;
    float fb3SaturationQuantizeMixLfoAmp = 0.0;
    float fb3BrightQuantizeMixLfoAmp = 0.0;
    float fb3HueDitherMixLfoAmp = 0.0;
    float fb3HueDitherAmountLfoAmp = 0;
    float fb3SaturationDitherMixLfoAmp = 0.0;
    float fb3SaturationDitherAmountLfoAmp = 0;
    float fb3BrightDitherMixLfoAmp = 0.0;
    float fb3BrightDitherAmountLfoAmp = 0;
    float fb3HuePowMapLfoAmp = 0;
    float fb3SaturationPowMapLfoAmp = .0;
    float fb3BrightPowMapLfoAmp = .0;
    
    //next up
    //GEOMETRY
    
    //fb3ColorTexmods
    float fb3HueOffsetTexmod = 0.0;
    float fb3SaturationOffsetTexmod = 0.0;
    float fb3BrightOffsetTexmod = 0.0;
    float fb3HueAttenuateTexmod = 0.0;
    float fb3SaturationAttenuateTexmod = 0.0;
    float fb3BrightAttenuateTexmod = 0.0;
    float fb3HueShaperTexmod = 0.0;
    float fb3HuePowMapTexmod = .0;
    float fb3SaturationPowMapTexmod = .0;
    float fb3BrightPowMapTexmod = .0;
    
    
    //delete these
    float fb3HueQuantizeTexmod = 0;
    float fb3SaturationQuantizeTexmod = 0;
    float fb3BrightQuantizeTexmod = 0;
    float fb3HueQuantizeMixTexmod = 0.0;
    float fb3SaturationQuantizeMixTexmod = 0.0;
    float fb3BrightQuantizeMixTexmod = 0.0;
    float fb3HueDitherMixTexmod = 0.0;
    float fb3HueDitherAmountTexmod = 0;
    float fb3SaturationDitherMixTexmod = 0.0;
    float fb3SaturationDitherAmountTexmod = 0;
    float fb3BrightDitherMixTexmod = 0.0;
    float fb3BrightDitherAmountTexmod = 0;
    
    
    //fb3 geo1
    float fb3XDisplace=0.0;
    float fb3YDisplace=0.0;
    float fb3ZDisplace=100.0;
    float fb3Rotate=0;
    ofVec4f fb3ShearMatrix;
    
    float fb3FisheyeAmount = 0;
    float fb3FisheyeX = 0;
    float fb3FisheyeY = 0;
    float fb3SpiralAmount = 0;
    float fb3SpiralAngle = 0;
    float fb3SpiralX = 0;
    float fb3SpiralY = 0;
    int fb3KaleidoscopeSegments = 0;
    float fb3KaleidoscopeSlice = 0;
    bool fb3RotateMode = 0;
    bool fb3HorizontalMirror = 0;
    bool fb3VerticalMirror = 0;
    int fb3_toroid_switch = 0;
    
    //fb3 geo rangemods
    float fb3XDisplaceRange=40;
    float fb3YDisplaceRange=40;
    float fb3ZDisplaceRange=10;
    float fb3ZRotateRange= PI;
    ofVec4f fb3ShearMatrixRange;
    
    float fb3FisheyeAmountRange = .15;
    float fb3FisheyeXRange = .25;
    float fb3FisheyeYRange = .25;
    float fb3SpiralAmountRange = .15;
    float fb3SpiralAngleRange = PI;
    float fb3SpiralXRange = .25;
    float fb3SpiralYRange = .25;
    int fb3KaleidoscopeSegmentsRange = 21;
    float fb3KaleidoscopeSliceRange = PI;
    
    //fb3 geo1 Lfo
    float fb3XDisplaceLfoTheta = 0.0;
    float fb3YDisplaceLfoTheta = 0.0;
    float fb3ZDisplaceLfoTheta = 0.0;
    float fb3RotateLfoTheta = 0;
    ofVec4f fb3ShearMatrixLfoTheta;
    
    float fb3XDisplaceLfoAmp = 0.0;
    float fb3YDisplaceLfoAmp = 0.0;
    float fb3ZDisplaceLfoAmp = 0.0;
    float fb3RotateLfoAmp = 0;
    ofVec4f fb3ShearMatrixLfoAmp;
    
    //fb3 geo2 Lfo
    float fb3FisheyeAmountLfoTheta = 0;
    float fb3FisheyeXLfoTheta = 0;
    float fb3FisheyeYLfoTheta = 0;
    float fb3SpiralAmountLfoTheta = 0;
    float fb3SpiralAngleLfoTheta = 0;
    float fb3SpiralXLfoTheta = 0;
    float fb3SpiralYLfoTheta = 0;
    float fb3KaleidoscopeSegmentsLfoTheta = 0;
    float fb3KaleidoscopeSliceLfoTheta = 0;
    
    float fb3FisheyeAmountLfoAmp = 0;
    float fb3FisheyeXLfoAmp = 0;
    float fb3FisheyeYLfoAmp = 0;
    float fb3SpiralAmountLfoAmp = 0;
    float fb3SpiralAngleLfoAmp = 0;
    float fb3SpiralXLfoAmp = 0;
    float fb3SpiralYLfoAmp = 0;
    float fb3KaleidoscopeSegmentsLfoAmp = 0;
    float fb3KaleidoscopeSliceLfoAmp = 0;
    
    //fbo geo 1 texmods
    float fb3XDisplaceTexmod=0.0;
    float fb3YDisplaceTexmod=0.0;
    float fb3ZDisplaceTexmod=0;
    float fb3RotateTexmod=0;
    ofVec4f fb3ShearMatrixTexmod;
    
    float fb3FisheyeAmountTexmod = 0;
    float fb3FisheyeXTexmod = 0;
    float fb3FisheyeYTexmod = 0;
    float fb3SpiralAmountTexmod = 0;
    float fb3SpiralAngleTexmod = 0;
    float fb3SpiralXTexmod = 0;
    float fb3SpiralYTexmod = 0;
    float fb3KaleidoscopeSegmentsTexmod = 0;
    float fb3KaleidoscopeSliceTexmod = 0;
    
    
    //fb3 pixels
    bool fb3PixelXYLock = 1;
    bool fb3PixelSwitch=0;
    int fb3XPixelScale=64;
    int fb3YPixelScale=64;
    float fb3PixelMix=1;
    float fb3PixelBrightscale=0;
    
    //fb3 pixel lfo
    float fb3XPixelScaleLfoTheta=0;
    float fb3XPixelScaleLfoAmp=0;
    float fb3YPixelScaleLfoTheta=0;
    float fb3YPixelScaleLfoAmp=0;
    float fb3PixelMixLfoTheta=0;
    float fb3PixelMixLfoAmp=0;
    float fb3PixelBrightscaleLfoTheta=0;
    float fb3PixelBrightscaleLfoAmp=0;
    
    //fb3 pixel texmods
    int  fb3XPixelScaleTexmod=0;
    int fb3YPixelScaleTexmod=0;
    float fb3PixelMixTexmod=0;
    float fb3PixelBrightscaleTexmod=0;
    
    
    //fb3 texmods
    int fb3TexmodSelect=2;
    bool fb3TexmodSwitch=false;
    
    
    
    
    

    
    

    
    //global

	void globalResetAll();
	void globalResetAllParameters();
	void globalResetAllLfo();
    int global_texmod_select=0;
    bool global_texmod=false;
    bool control_reset=false;
    bool framebuffer_clear=false;
    float blur_amount=0.0;
    float blur_radius=1.0;
    float sharpen_amount=0.0;
    float sharpen_radius=1.0;
    float sharpen_boost=0.0;
    float ndi_scale=0;
    float x_skew=0;
    float y_skew=0;
    bool tetrahedron_switch=0;
    bool hypercube_switch=0;
    float hypercube_theta_rate=0.01;
    float hypercube_phi_rate=0.01;
    
    //this doesnt work yet
    bool ndiOutput=0;
    
    //global texmods
    float texmod_blur_amount=0.0;
    float texmod_blur_radius=1.0;
    float texmod_sharpen_amount=0.0;
    float texmod_sharpen_radius=1.0;
    float texmod_sharpen_boost=0.0;
    
    //global lfos
    float blur_amount_lfo_amp=0.0;
    float blur_amount_lfo_theta=0.0;
    float blur_radius_lfo_amp=0.0;
    float blur_radius_lfo_theta=0.0;
    float sharpen_amount_lfo_amp=0.0;
    float sharpen_amount_lfo_theta=0.0;
    float sharpen_radius_lfo_amp=1.0;
    float sharpen_radius_lfo_theta=1.0;
    float sharpen_boost_lfo_amp=0.0;
    float sharpen_boost_lfo_theta=0.0;
    
	void resetAll();
    
    

    //pixels:

       
    
    


   
   };
