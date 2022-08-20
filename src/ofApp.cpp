/*
 re the midi biz
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */

/*thanks to ed tannenbaum for help in fixing up the framebuffer code!*/

#include "ofApp.h"
#include <iostream>

//this fixes the total maximum delay time possible in frames
//
const int fbob=30;

float color_theta=0;

//variables for the midi controllers
float c1=0;
float c2=0;
float c3=0;
float c4=0;
float c5=0;
float c6=0;
float c7=0;
float c8=0;
float c9=0;
float c10=0;
float c11=0;
float c12=0;
float c13=0;
float c14=0;
float c15=0;
float c16=0;
float c17=0;
float c18=0;
float c19=0;
float c20=0;
float c21=0;
float c22=0;
float c23=0;
float c24=0;
float c25=0;
float c26=0;
float c27=0;
float c28=0;
float c29=0;
float c30=0;
float c31=0;

//lfo thetas

//ch1 adjust
float ch1ScaleThetaInc;
float ch1HueThetaInc;
float ch1SaturationThetaInc;
float ch1BrightThetaInc;
float ch1QuantizeThetaInc;

//ch1 pixels
float ch1XPixelScaleThetaInc = 0;
float ch1YPixelScaleThetaInc = 0;
float ch1PixelMixThetaInc = 0;
float ch1PixelBrightscaleThetaInc = 0;


//ch2 adjust
float ch2ScaleThetaInc;
float ch2HueThetaInc;
float ch2SaturationThetaInc;
float ch2BrightThetaInc;
float ch2QuantizeThetaInc;

//ch2 pixels
float ch2XPixelScaleThetaInc = 0;
float ch2YPixelScaleThetaInc = 0;
float ch2PixelMixThetaInc = 0;
float ch2PixelBrightscaleThetaInc = 0;




//fb0 theta Inc
float fb0DelayThetaInc;
float fb0MixThetaInc;
float fb0LumakeyLevelThetaInc;
float fb0ChromakeyRedThetaInc;
float fb0ChromakeyGreenThetaInc;
float fb0ChromakeyBlueThetaInc;
float fb0KeyThresholdThetaInc;
float fb0KeySoftThetaInc;

float fb0MaskXThetaInc = 0;
float fb0MaskYThetaInc = 0;
float fb0MaskZThetaInc = 0.0;
float fb0MaskRotateThetaInc = 0.0;
float fb0MaskTileAmountThetaInc = 0.0;

float fb0MaskTexmodOffsetThetaInc = 0;
float fb0MaskTexmodQuantizeAmountThetaInc = 0.0;
float fb0MaskTexmodQuantizeMixThetaInc = 0.0;

float fb0HueOffsetThetaInc = 0.0;
float fb0SaturationOffsetThetaInc = 0.0;
float fb0BrightOffsetThetaInc = 0.0;
float fb0HueAttenuateThetaInc = 0.0;
float fb0SaturationAttenuateThetaInc = 0.0;
float fb0BrightAttenuateThetaInc = 0.0;
float fb0HueShaperThetaInc = 0.0;
float fb0HuePowMapThetaInc = 0;
float fb0SaturationPowMapThetaInc = .0;
float fb0BrightPowMapThetaInc = .0;

float fb0HueQuantizeThetaInc = 0;
float fb0SaturationQuantizeThetaInc = 0;
float fb0BrightQuantizeThetaInc = 0;
float fb0HueQuantizeMixThetaInc = 0.0;
float fb0SaturationQuantizeMixThetaInc = 0.0;
float fb0BrightQuantizeMixThetaInc = 0.0;
float fb0HueDitherMixThetaInc = 0.0;
float fb0HueDitherAmountThetaInc = 0;
float fb0SaturationDitherMixThetaInc = 0.0;
float fb0SaturationDitherAmountThetaInc = 0;
float fb0BrightDitherMixThetaInc = 0.0;
float fb0BrightDitherAmountThetaInc = 0;

//fb0 geo
float fb0XDisplaceThetaInc;
float fb0YDisplaceThetaInc;
float fb0ZDisplaceThetaInc;
float fb0RotateThetaInc;
ofVec4f fb0ShearMatrixThetaInc;

float fb0FisheyeAmountThetaInc = 0;
float fb0FisheyeXThetaInc = 0;
float fb0FisheyeYThetaInc = 0;
float fb0SpiralAmountThetaInc = 0;
float fb0SpiralAngleThetaInc = 0;
float fb0SpiralXThetaInc = 0;
float fb0SpiralYThetaInc = 0;
float fb0KaleidoscopeSegmentsThetaInc = 0;
float fb0KaleidoscopeSliceThetaInc = 0;

//fb0 pixels
float fb0XPixelScaleThetaInc=0;
float fb0YPixelScaleThetaInc=0;
float fb0PixelMixThetaInc=0;
float fb0PixelBrightscaleThetaInc=0;












//fb1
//fb1 theta Inc
float fb1DelayThetaInc;
float fb1MixThetaInc;
float fb1LumakeyLevelThetaInc;
float fb1ChromakeyRedThetaInc;
float fb1ChromakeyGreenThetaInc;
float fb1ChromakeyBlueThetaInc;
float fb1KeyThresholdThetaInc;
float fb1KeySoftThetaInc;

float fb1MaskXThetaInc = 0;
float fb1MaskYThetaInc = 0;
float fb1MaskZThetaInc = 0.0;
float fb1MaskRotateThetaInc = 0.0;
float fb1MaskTileAmountThetaInc = 0.0;

float fb1MaskTexmodOffsetThetaInc = 0;
float fb1MaskTexmodQuantizeAmountThetaInc = 0.0;
float fb1MaskTexmodQuantizeMixThetaInc = 0.0;

float fb1HueOffsetThetaInc = 0.0;
float fb1SaturationOffsetThetaInc = 0.0;
float fb1BrightOffsetThetaInc = 0.0;
float fb1HueAttenuateThetaInc = 0.0;
float fb1SaturationAttenuateThetaInc = 0.0;
float fb1BrightAttenuateThetaInc = 0.0;
float fb1HueShaperThetaInc = 0.0;
float fb1HuePowMapThetaInc = 0;
float fb1SaturationPowMapThetaInc = .0;
float fb1BrightPowMapThetaInc = .0;

float fb1HueQuantizeThetaInc = 0;
float fb1SaturationQuantizeThetaInc = 0;
float fb1BrightQuantizeThetaInc = 0;
float fb1HueQuantizeMixThetaInc = 0.0;
float fb1SaturationQuantizeMixThetaInc = 0.0;
float fb1BrightQuantizeMixThetaInc = 0.0;
float fb1HueDitherMixThetaInc = 0.0;
float fb1HueDitherAmountThetaInc = 0;
float fb1SaturationDitherMixThetaInc = 0.0;
float fb1SaturationDitherAmountThetaInc = 0;
float fb1BrightDitherMixThetaInc = 0.0;
float fb1BrightDitherAmountThetaInc = 0;

//fb1 geo
float fb1XDisplaceThetaInc;
float fb1YDisplaceThetaInc;
float fb1ZDisplaceThetaInc;
float fb1RotateThetaInc;
ofVec4f fb1ShearMatrixThetaInc;

float fb1FisheyeAmountThetaInc = 0;
float fb1FisheyeXThetaInc = 0;
float fb1FisheyeYThetaInc = 0;
float fb1SpiralAmountThetaInc = 0;
float fb1SpiralAngleThetaInc = 0;
float fb1SpiralXThetaInc = 0;
float fb1SpiralYThetaInc = 0;
float fb1KaleidoscopeSegmentsThetaInc = 0;
float fb1KaleidoscopeSliceThetaInc = 0;

//fb1 pixels
float fb1XPixelScaleThetaInc=0;
float fb1YPixelScaleThetaInc=0;
float fb1PixelMixThetaInc=0;
float fb1PixelBrightscaleThetaInc=0;





//fb2
//fb2 theta Inc
float fb2DelayThetaInc;
float fb2MixThetaInc;
float fb2LumakeyLevelThetaInc;
float fb2ChromakeyRedThetaInc;
float fb2ChromakeyGreenThetaInc;
float fb2ChromakeyBlueThetaInc;
float fb2KeyThresholdThetaInc;
float fb2KeySoftThetaInc;

float fb2MaskXThetaInc = 0;
float fb2MaskYThetaInc = 0;
float fb2MaskZThetaInc = 0.0;
float fb2MaskRotateThetaInc = 0.0;
float fb2MaskTileAmountThetaInc = 0.0;

float fb2MaskTexmodOffsetThetaInc = 0;
float fb2MaskTexmodQuantizeAmountThetaInc = 0.0;
float fb2MaskTexmodQuantizeMixThetaInc = 0.0;

float fb2HueOffsetThetaInc = 0.0;
float fb2SaturationOffsetThetaInc = 0.0;
float fb2BrightOffsetThetaInc = 0.0;
float fb2HueAttenuateThetaInc = 0.0;
float fb2SaturationAttenuateThetaInc = 0.0;
float fb2BrightAttenuateThetaInc = 0.0;
float fb2HueShaperThetaInc = 0.0;
float fb2HuePowMapThetaInc = 0;
float fb2SaturationPowMapThetaInc = .0;
float fb2BrightPowMapThetaInc = .0;

float fb2HueQuantizeThetaInc = 0;
float fb2SaturationQuantizeThetaInc = 0;
float fb2BrightQuantizeThetaInc = 0;
float fb2HueQuantizeMixThetaInc = 0.0;
float fb2SaturationQuantizeMixThetaInc = 0.0;
float fb2BrightQuantizeMixThetaInc = 0.0;
float fb2HueDitherMixThetaInc = 0.0;
float fb2HueDitherAmountThetaInc = 0;
float fb2SaturationDitherMixThetaInc = 0.0;
float fb2SaturationDitherAmountThetaInc = 0;
float fb2BrightDitherMixThetaInc = 0.0;
float fb2BrightDitherAmountThetaInc = 0;

//fb2 geo
float fb2XDisplaceThetaInc;
float fb2YDisplaceThetaInc;
float fb2ZDisplaceThetaInc;
float fb2RotateThetaInc;
ofVec4f fb2ShearMatrixThetaInc;

float fb2FisheyeAmountThetaInc = 0;
float fb2FisheyeXThetaInc = 0;
float fb2FisheyeYThetaInc = 0;
float fb2SpiralAmountThetaInc = 0;
float fb2SpiralAngleThetaInc = 0;
float fb2SpiralXThetaInc = 0;
float fb2SpiralYThetaInc = 0;
float fb2KaleidoscopeSegmentsThetaInc = 0;
float fb2KaleidoscopeSliceThetaInc = 0;

//fb2 pixels
float fb2XPixelScaleThetaInc=0;
float fb2YPixelScaleThetaInc=0;
float fb2PixelMixThetaInc=0;
float fb2PixelBrightscaleThetaInc=0;






//fb3
//fb3 theta Inc
float fb3DelayThetaInc;
float fb3MixThetaInc;
float fb3LumakeyLevelThetaInc;
float fb3ChromakeyRedThetaInc;
float fb3ChromakeyGreenThetaInc;
float fb3ChromakeyBlueThetaInc;
float fb3KeyThresholdThetaInc;
float fb3KeySoftThetaInc;

float fb3MaskXThetaInc = 0;
float fb3MaskYThetaInc = 0;
float fb3MaskZThetaInc = 0.0;
float fb3MaskRotateThetaInc = 0.0;
float fb3MaskTileAmountThetaInc = 0.0;

float fb3MaskTexmodOffsetThetaInc = 0;
float fb3MaskTexmodQuantizeAmountThetaInc = 0.0;
float fb3MaskTexmodQuantizeMixThetaInc = 0.0;

float fb3HueOffsetThetaInc = 0.0;
float fb3SaturationOffsetThetaInc = 0.0;
float fb3BrightOffsetThetaInc = 0.0;
float fb3HueAttenuateThetaInc = 0.0;
float fb3SaturationAttenuateThetaInc = 0.0;
float fb3BrightAttenuateThetaInc = 0.0;
float fb3HueShaperThetaInc = 0.0;
float fb3HuePowMapThetaInc = 0;
float fb3SaturationPowMapThetaInc = .0;
float fb3BrightPowMapThetaInc = .0;

float fb3HueQuantizeThetaInc = 0;
float fb3SaturationQuantizeThetaInc = 0;
float fb3BrightQuantizeThetaInc = 0;
float fb3HueQuantizeMixThetaInc = 0.0;
float fb3SaturationQuantizeMixThetaInc = 0.0;
float fb3BrightQuantizeMixThetaInc = 0.0;
float fb3HueDitherMixThetaInc = 0.0;
float fb3HueDitherAmountThetaInc = 0;
float fb3SaturationDitherMixThetaInc = 0.0;
float fb3SaturationDitherAmountThetaInc = 0;
float fb3BrightDitherMixThetaInc = 0.0;
float fb3BrightDitherAmountThetaInc = 0;

//fb3 geo
float fb3XDisplaceThetaInc;
float fb3YDisplaceThetaInc;
float fb3ZDisplaceThetaInc;
float fb3RotateThetaInc;
ofVec4f fb3ShearMatrixThetaInc;

float fb3FisheyeAmountThetaInc = 0;
float fb3FisheyeXThetaInc = 0;
float fb3FisheyeYThetaInc = 0;
float fb3SpiralAmountThetaInc = 0;
float fb3SpiralAngleThetaInc = 0;
float fb3SpiralXThetaInc = 0;
float fb3SpiralYThetaInc = 0;
float fb3KaleidoscopeSegmentsThetaInc = 0;
float fb3KaleidoscopeSliceThetaInc = 0;

//fb3 pixels
float fb3XPixelScaleThetaInc=0;
float fb3YPixelScaleThetaInc=0;
float fb3PixelMixThetaInc=0;
float fb3PixelBrightscaleThetaInc=0;







//globla
float blur_theta_amount;
float blur_theta_radius;
float sharpen_theta_amount;
float sharpen_theta_radius;
float sharpen_theta_boost;

//pixels



ofPolyline tetrahedron;
//ofPolyline pnt_line;

float aa=0.0;
float ss=0.0;
float dd=0.0;
float ff=0.0;
float xw=1.01;
float yw=1.01;
float jj=1;
float kk=1;
float ll=.05;

float qq=0;
float ee=0;

float oo=1.0;
int ii=1;

float gg=0;
float hh=0;

float theta=0;

float frequency=0;

float amp=0;

float cam1_scale=1;
float scale1=1;
float scale2=1;

//vidmixer variables
float scale=.5;

float tt=0;


int framedelayoffset=0;  // this is used as an index to the circular framebuffers eeettt
unsigned int framecount=0; // framecounter used to calc offset eeettt


//i got this up to 240 frames with steady on my computer, is a bit skewed extreme for real time video
//executions tho
 // number of "framedelay" buffers eeettt
//int dd=fbob;
//this buffers the framebuffers from the final screen draws

//this buffers the framebuffers from the final screen draws
ofFbo pastFrames[fbob];
//ofFbo pastFrames2[fbob];

//ofFbo pastFrames_comp[fbob];
//ofFbo is the openframeworks framebuffer object
//this line is declaring an array of framebuffer objects
//many c++ afficionados prefer a c++ vector object instead of arrays every time
//because c++ vectors are like arrays but with some handier ways to access and add and delete contents
//but on the other hand vectors can have dynamic lengths and one can really end up in some
//trouble with dynamically working with framebuffers bc its generally best pratice to allocate
//memory on the gpu for all of yr framebuffers before yr code runs, trying to mess with that on
//the fly could have some interesting appeal to a glitch art style but is not going to please
//others

void incIndex()  // call this every frame to calc the offset eeettt
{
    
    framecount++;
    framedelayoffset=framecount % fbob;
}


//VIDEO FILE BIZ
ofVideoPlayer videoPlayer1;
bool videoSwitch = 0;


ofImage mask1;
ofImage mask2;
ofImage mask3;
ofImage mask4;


//sevenstar1 biz
const int reps = 7;
ofVec2f points[reps];
//i don't think this would be every time? but should double check
//this one increments 3 = floor[7/2] to 8 reps
const int reps1 = reps + 1;
ofVec2f points1[reps1];

ofVec2f position1;
float increment1 = 0;
int index1 = 0;

float acceleration1 = .002;
float threshold = .125;

//this one increments 2, will work for any odd star
ofVec2f points2[reps];
ofVec2f position2;
float increment2 = 0;
int index2 = 0;

float acceleration2 = .00125;

float thetaHue1;
float thetaHue2;
float thetaSaturation1;
float thetaChaos;

float hueInc1 = .021257;
float hueInc2 = .083713;
float saturationInc1 = .00612374;
float chaosInc = .0001;

//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetFrameRate(30);
	//ofSetFrameRate(24);
    
   
 
    
	ofSetVerticalSync(true);
	ofBackground(0);
	//ofSetLogLevel(OF_LOG_VERBOSE);
	
    
    /**MIDIBIX***/
    /*
	// print input ports to console
	midiIn.listInPorts();
	
	// open port by number (you may need to change this)
	midiIn.openPort(1);
	//midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
	
	// add ofApp as a listener
	midiIn.addListener(this);
	
	// print received messages to the console
	midiIn.setVerbose(true);
    */
    /*******/
    
    string reciever_name="Scan Converter";
    //string reciever_name="testing";
    //ndi setup
    NDI_reciever_setup(reciever_name);
    //NDI_sender_setup("video_waaaaves");
    /**shaderobiz***/
    
#ifdef TARGET_OPENGLES

#else
    if(ofIsGLProgrammableRenderer()){
    
    }else{
   
        shader_mixer.load("shadersGL2/shader_mixer");
        shader_blur.load("shadersGL2/shader_blur");
        shader_sharpen.load("shadersGL2/shader_sharpen");
       
    }
#endif
    
    fbo_draw.allocate(ofGetWidth(), ofGetHeight());
    fbo_feedback.allocate(ofGetWidth(), ofGetHeight());
    fbo_blur.allocate(ofGetWidth(), ofGetHeight());
    
    
    ndi_fbo.allocate(ofGetWidth(), ofGetHeight());
    
    fbo_feedback.begin();
    ofClear(0,0,0,255);
    fbo_feedback.end();
    
    fbo_draw.begin();
    ofClear(0,0,0,255);
    fbo_draw.end();
    
    fbo_blur.begin();
    ofClear(0,0,0,255);
    fbo_blur.end();
    
    //allocate and clear the variable delay final draw buffers
 
    for(int i=0;i<fbob;i++){
        
        pastFrames[i].allocate(ofGetWidth(), ofGetHeight());
        pastFrames[i].begin();
        ofClear(0,0,0,255);
        pastFrames[i].end();

		/*
		pastFrames2[i].allocate(ofGetWidth(), ofGetHeight());
		pastFrames2[i].begin();
		ofClear(0, 0, 0, 255);
		pastFrames2[i].end();
        */
    }//endifor
    
    //camerabiz
    //if u are having low framerates u can try lower resolution grabs
    //or if its all going smooth and u want to try higher resolutions here is where to fuck with that
    
    //add some optional UI interactivity with these?
    //like a incrementer that cycles thru integers mod the lenght of the device list for selecting inputs cameras
   
    cam1.setVerbose(true);
    cam1.listDevices();
    cam1.setDeviceID(0);
	//cam1.initGrabber(1920, 1080);
    cam1.initGrabber(1280,720);
	//cam1.initGrabber(640,480);
    //cam1.initGrabber(1024,768);
	//cam1.initGrabber(320,240);
    
    cam2.setDeviceID(2);
	cam2.setup(1280,720);
	//cam2.initGrabber(1920, 1080);
    //cam2.setup(640,480);
    //cam2.initGrabber(320, 240);
 
    tetrahedron_setup();
	sevenStar1Setup();

	//VIDEO FILE BIZ  
	// 8 frames per second what the fuckkk
	/*
	videoPlayer1.load("videos/magickandNarrativeLecture0-1.mp4");
	videoPlayer1.play();
	videoPlayer1.setVolume(0.0);
	*/

	//MASK BIZ
	mask1.load("images/rectangleMask1.png");
	//mask1.load("images/rectangleMaskBeveled.png");
	mask2.load("images/heartMask.png");
	mask3.load("images/septagram2.jpg");
	mask4.load("images/mandelbrotMask1.jpg");
}

//--------------------------------------------------------------
void ofApp::update() {

	/*
	if (videoSwitch == 1) {
		videoPlayer1.update();
	}
    */

    //only update if active set a test for that too?
    cam1.update();
    cam2.update();
    
    //midibiz();
    //midibiz();
    
    NDI_reciever_update();
    //NDI_sender_update();
    
    lfo_update();
    
    if(gui->framebuffer_clear==true){
        for(int i=0;i<fbob;i++){
            pastFrames[i].begin();
            ofClear(0,0,0,255);
            pastFrames[i].end();
/*
			pastFrames2[i].begin();
			ofClear(0, 0, 0, 255);
			pastFrames2[i].end();
  */
		}
        
        fbo_draw.begin();
        ofClear(0,0,0,255);
        fbo_draw.end();
        //cout<<"lalalal"<<endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {






	/***shaderbix**/
   





	fbo_draw.begin();

	shader_mixer.begin();

	//--------------------------send the textures

	//this gets bound to tex0 when u do this way
	//for some reason i can't just erase this and move on
	//so replace this with a useful texture at some point
	//haha but whenever i replace this then the feedback textures dissapear.
	//fuckin a
    
     //LETS GET RID OF THIS BIZ PLEASE
    //main thing that actualy works is just set up ch1 as tex0, so just do it
	fbo_feedback.draw(0, 0);

	//we have removed ndi, cam1, cam2 textures so lets try and renumber things
	//we have lost texture ids 1, 2, 3
    if(gui->channel1_select==0){
        shader_mixer.setUniformTexture("ch1Tex",cam1.getTexture(),1);
        shader_mixer.setUniform2f("ch1Dimensions",ofVec2f(cam1.getWidth(),cam1.getHeight()));
        shader_mixer.setUniform1f("ch1AspectRatio",cam1.getWidth()/cam1.getHeight());
        shader_mixer.setUniform2f("ch1Center",ofVec2f(cam1.getWidth()/2,cam1.getHeight()/2));
    }
    if(gui->channel1_select==1){
        shader_mixer.setUniformTexture("ch1Tex",cam2.getTexture(),1);
        shader_mixer.setUniform2f("ch1Dimensions",ofVec2f(cam2.getWidth(),cam2.getHeight()));
        shader_mixer.setUniform1f("ch1AspectRatio",cam2.getWidth()/cam2.getHeight());
		shader_mixer.setUniform2f("ch1Center", ofVec2f(cam2.getWidth() / 2, cam2.getHeight() / 2));
    }
    if(gui->channel1_select==2){
        shader_mixer.setUniformTexture("ch1Tex",ndi_fbo.getTexture(),1);
        shader_mixer.setUniform2f("ch1Dimensions",ofVec2f(ndi_fbo.getWidth(),ndi_fbo.getHeight()));
        shader_mixer.setUniform1f("ch1AspectRatio",ndi_fbo.getWidth()/ndi_fbo.getHeight());
		shader_mixer.setUniform2f("ch1Center", ofVec2f(ndi_fbo.getWidth() / 2, ndi_fbo.getHeight() / 2));
    }

	//channel 2 select
	if (gui->channel2_select == 0) {
		shader_mixer.setUniformTexture("ch2Tex", cam1.getTexture(), 2);
		shader_mixer.setUniform2f("ch2Dimensions", ofVec2f(cam1.getWidth(), cam1.getHeight()));
		shader_mixer.setUniform1f("ch2AspectRatio", cam1.getWidth() / cam1.getHeight());
		shader_mixer.setUniform2f("ch2Center", ofVec2f(cam1.getWidth() / 2, cam1.getHeight() / 2));
	}
	if (gui->channel2_select == 1) {
		shader_mixer.setUniformTexture("ch2Tex", cam2.getTexture(), 2);
		shader_mixer.setUniform2f("ch2Dimensions", ofVec2f(cam2.getWidth(), cam2.getHeight()));
		shader_mixer.setUniform1f("ch2AspectRatio", cam2.getWidth() / cam2.getHeight());
		shader_mixer.setUniform2f("ch2Center", ofVec2f(cam2.getWidth() / 2, cam2.getHeight() / 2));
	}
	if (gui->channel2_select == 2) {
		shader_mixer.setUniformTexture("ch2Tex", ndi_fbo.getTexture(), 2);
		shader_mixer.setUniform2f("ch2Dimensions", ofVec2f(ndi_fbo.getWidth(), ndi_fbo.getHeight()));
		shader_mixer.setUniform1f("ch2AspectRatio", ndi_fbo.getWidth() / ndi_fbo.getHeight());
		shader_mixer.setUniform2f("ch2Center", ofVec2f(ndi_fbo.getWidth() / 2, ndi_fbo.getHeight() / 2));
	}
    


	shader_mixer.setUniformTexture("fb0", pastFrames[(abs(framedelayoffset - fbob - gui->fb0DelayAmount - (int(fbob*c8)) - abs(int(fbob*lfo(gui->fb0DelayLfoAmp, fb0DelayThetaInc, 0)))) - 1) % fbob].getTexture(), 4);
	shader_mixer.setUniformTexture("fb1", pastFrames[(abs(framedelayoffset - fbob - gui->fb1DelayAmount - (int(fbob*c21)) - abs(int(fbob*lfo(gui->fb1DelayLfoAmp, fb1DelayThetaInc, 0)))) - 1) % fbob].getTexture(), 5);
	shader_mixer.setUniformTexture("fb2", pastFrames[(abs(framedelayoffset - fbob - gui->fb2DelayAmount - abs(int(fbob*lfo(gui->fb2DelayLfoAmp, fb2DelayThetaInc, 0)))) - 1) % fbob].getTexture(), 6);
	shader_mixer.setUniformTexture("fb3", pastFrames[(abs(framedelayoffset - fbob - gui->fb3DelayAmount - abs(int(fbob*lfo(gui->fb3DelayLfoAmp, fb3DelayThetaInc, 0)))) - 1) % fbob].getTexture(), 7);

	//set up logic in here to choose wich mask goes where
	if (gui->fb0MaskSelect == 0) {
		shader_mixer.setUniformTexture("fb0Mask", mask1.getTexture(), 10);
	}
	if (gui->fb0MaskSelect == 1) {
		shader_mixer.setUniformTexture("fb0Mask", mask2.getTexture(), 10);
	}
	if (gui->fb0MaskSelect == 2) {
		shader_mixer.setUniformTexture("fb0Mask", mask3.getTexture(), 10);
	}
	if (gui->fb0MaskSelect == 3) {
		shader_mixer.setUniformTexture("fb0Mask", mask4.getTexture(), 10);
	}
    
    
    //set up logic in here to choose wich mask goes where
    //is this where the extra hit comes in?
    //seems like nah, its probably something to do with all the extra color stuff
    //happeningin the shader.  we can try optimizing some stuff later on
    
    if (gui->fb1MaskSelect == 0) {
        shader_mixer.setUniformTexture("fb1Mask", mask1.getTexture(), 11);
    }
    if (gui->fb1MaskSelect == 1) {
        shader_mixer.setUniformTexture("fb1Mask", mask2.getTexture(), 11);
    }
    if (gui->fb1MaskSelect == 2) {
        shader_mixer.setUniformTexture("fb1Mask", mask3.getTexture(), 11);
    }
    if (gui->fb1MaskSelect == 3) {
        shader_mixer.setUniformTexture("fb1Mask", mask4.getTexture(), 11);
    }
    
    //fb2 mask
    if (gui->fb2MaskSelect == 0) {
        shader_mixer.setUniformTexture("fb2Mask", mask1.getTexture(), 12);
    }
    if (gui->fb2MaskSelect == 1) {
        shader_mixer.setUniformTexture("fb2Mask", mask2.getTexture(), 12);
    }
    if (gui->fb2MaskSelect == 2) {
        shader_mixer.setUniformTexture("fb2Mask", mask3.getTexture(), 12);
    }
    if (gui->fb2MaskSelect == 3) {
        shader_mixer.setUniformTexture("fb2Mask", mask4.getTexture(), 12);
    }
    
    
    //fb3 mask
    if (gui->fb3MaskSelect == 0) {
        shader_mixer.setUniformTexture("fb3Mask", mask1.getTexture(), 13);
    }
    if (gui->fb3MaskSelect == 1) {
        shader_mixer.setUniformTexture("fb3Mask", mask2.getTexture(), 13);
    }
    if (gui->fb3MaskSelect == 2) {
        shader_mixer.setUniformTexture("fb3Mask", mask3.getTexture(), 13);
    }
    if (gui->fb3MaskSelect == 3) {
        shader_mixer.setUniformTexture("fb3Mask", mask4.getTexture(), 13);
    }
    
    
    shader_mixer.setUniform1f("width", ofGetWidth());
    shader_mixer.setUniform1f("height", ofGetHeight());
    
  
    
    
    
    //ch1 variables
	ofVec3f ch1HsbAttenuateLfoOutput;
	ch1HsbAttenuateLfoOutput.set( lfo(gui->ch1HsbAttenuateLfoAmp.x, ch1HueThetaInc, 0),
									lfo(gui->ch1HsbAttenuateLfoAmp.y, ch1SaturationThetaInc, 0),
									lfo(gui->ch1HsbAttenuateLfoAmp.z, ch1BrightThetaInc, 0));
									
	/*ch1HsbAttenuateLfoOutput.set(lfo(gui->ch1HsbAttenuateLfoAmp.x, ch1HueThetaInc, 0),
		lfo(gui->ch1HsbAttenuateLfoAmp.y, ch1SaturationThetaInc, 0),
		lfo(1.0, ch1BrightThetaInc, 0)); */
	//adjust
    shader_mixer.setUniform1f("ch1Scale",gui->ch1Scale + abs(lfo(gui->ch1ScaleLfoAmp, ch1ScaleThetaInc, 0)));
    shader_mixer.setUniform3f("ch1HsbAttenuate",(gui->ch1HsbAttenuate) + ch1HsbAttenuateLfoOutput);
    
    shader_mixer.setUniform1f("ch1QuantizeAmount",gui->ch1Quantize);
    shader_mixer.setUniform1f("ch1QuantizeAmountDenom",1.0f/gui->ch1Quantize );
    shader_mixer.setUniform1i("ch1QuantizeSwitch",gui->ch1QuantizeSwitch);
    
    shader_mixer.setUniform1i("ch1HueInvert",gui->ch1HueInvert);
    shader_mixer.setUniform1i("ch1SaturationInvert",gui->ch1SaturationInvert);
    shader_mixer.setUniform1i("ch1BrightInvert",gui->ch1BrightInvert);

	shader_mixer.setUniform1i("ch1HMirror", gui->ch1HMirror);
	shader_mixer.setUniform1i("ch1VMirror", gui->ch1VMirror);

	//pixels
	shader_mixer.setUniform1i("ch1PixelSwitch", gui->ch1PixelSwitch);
	shader_mixer.setUniform1i("ch1XPixelScale", gui->ch1XPixelScale + lfo(gui->ch1XPixelScaleLfoAmp, ch1XPixelScaleThetaInc, 0));
	shader_mixer.setUniform1i("ch1YPixelScale", gui->ch1YPixelScale + lfo(gui->ch1YPixelScaleLfoAmp, ch1YPixelScaleThetaInc, 0));
	shader_mixer.setUniform1f("ch1PixelMix", gui->ch1PixelMix + lfo(gui->ch1PixelMixLfoAmp, ch1PixelMixThetaInc, 0));
	shader_mixer.setUniform1f("ch1PixelBrightscale", gui->ch1PixelBrightscale + lfo(gui->ch1PixelBrightscaleLfoAmp, ch1PixelBrightscaleThetaInc, 0));

	//ch2 variables
	//mixnkey

	shader_mixer.setUniform1i("ch2KeyOrder",gui->ch2KeyOrder);
	shader_mixer.setUniform1i("ch2KeyMode", gui->ch2KeyMode);
	shader_mixer.setUniform1i("ch2MixType", gui->ch2MixType);
	shader_mixer.setUniform1i("ch2MixOverflow", gui->ch2MixOverflow);

	shader_mixer.setUniform1f("ch2LumakeyLevel",gui->ch2LumakeyLevel);
	shader_mixer.setUniform1f("ch2ChromakeyRed", gui->ch2ChromakeyRed);
	shader_mixer.setUniform1f("ch2ChromakeyGreen", gui->ch2ChromakeyGreen);
	shader_mixer.setUniform1f("ch2ChromakeyBlue", gui->ch2ChromakeyBlue);
	shader_mixer.setUniform1f("ch2KeyThreshold", gui->ch2KeyThreshold);
	shader_mixer.setUniform1f("ch2KeySoft", gui->ch2KeySoft);
	shader_mixer.setUniform1f("ch2Mix", gui->ch2Mix);

	//adjust

	ofVec3f ch2HsbAttenuateLfoOutput;
	ch2HsbAttenuateLfoOutput.set(lfo(gui->ch2HsbAttenuateLfoAmp.x, ch2HueThetaInc, 0),
		lfo(gui->ch2HsbAttenuateLfoAmp.y, ch2SaturationThetaInc, 0),
		lfo(gui->ch2HsbAttenuateLfoAmp.z, ch2BrightThetaInc, 0));

	shader_mixer.setUniform1f("ch2Scale", gui->ch2Scale + abs(lfo(gui->ch2ScaleLfoAmp, ch2ScaleThetaInc, 0)));
	shader_mixer.setUniform3f("ch2HsbAttenuate", gui->ch2HsbAttenuate+ch2HsbAttenuateLfoOutput);

	shader_mixer.setUniform1f("ch2QuantizeAmount", gui->ch2Quantize);
	shader_mixer.setUniform1f("ch2QuantizeAmountDenom", 1.0f / gui->ch2Quantize);
	shader_mixer.setUniform1i("ch2QuantizeSwitch", gui->ch2QuantizeSwitch);

	shader_mixer.setUniform1i("ch2HueInvert", gui->ch2HueInvert);
	shader_mixer.setUniform1i("ch2SaturationInvert", gui->ch2SaturationInvert);
	shader_mixer.setUniform1i("ch2BrightInvert", gui->ch2BrightInvert);


	//pixels
	shader_mixer.setUniform1i("ch2PixelSwitch", gui->ch2PixelSwitch);
	shader_mixer.setUniform1i("ch2XPixelScale", gui->ch2XPixelScale + lfo(gui->ch2XPixelScaleLfoAmp, ch2XPixelScaleThetaInc, 0));
	shader_mixer.setUniform1i("ch2YPixelScale", gui->ch2YPixelScale + lfo(gui->ch2YPixelScaleLfoAmp, ch2YPixelScaleThetaInc, 0));
	shader_mixer.setUniform1f("ch2PixelMix", gui->ch2PixelMix + lfo(gui->ch2PixelMixLfoAmp, ch2PixelMixThetaInc, 0));
	shader_mixer.setUniform1f("ch2PixelBrightscale", gui->ch2PixelBrightscale + lfo(gui->ch2PixelBrightscaleLfoAmp, ch2PixelBrightscaleThetaInc, 0));
    
    ofVec3f hsb_x;
	ofVec3f hsbOffset;
	//delete the next one
    ofVec3f hue_x;
    ofVec3f fb_modswitch;
    ofVec3f fb_rescale;
	ofVec3f powMap;
    
	shader_mixer.setUniform1f("inverseWidth",1.0f/float(ofGetWidth()));
	shader_mixer.setUniform1f("inverseHeight", 1.0f / float(ofGetHeight()));
    //fb0

    float fbShearC = .25;
    
    
    
    
    //fb0 variables
	//fb0Mixing
	shader_mixer.setUniform1i("fb0KeyMode", gui->fb0KeyMode);
	shader_mixer.setUniform1f("fb0LumakeyLevel", gui->fb0LumakeyLevel
		+lfo(gui->fb0LumakeyLevelLfoAmp, fb0LumakeyLevelThetaInc, 0));
	shader_mixer.setUniform1f("fb0ChromakeyRed", gui->fb0ChromakeyRed
		+ lfo(gui->fb0ChromakeyRedLfoAmp, fb0ChromakeyRedThetaInc, 0));
	shader_mixer.setUniform1f("fb0ChromakeyGreen", gui->fb0ChromakeyGreen
		+ lfo(gui->fb0ChromakeyGreenLfoAmp, fb0ChromakeyGreenThetaInc, 0));
	shader_mixer.setUniform1f("fb0ChromakeyBlue", gui->fb0ChromakeyBlue
		+ lfo(gui->fb0ChromakeyBlueLfoAmp, fb0ChromakeyBlueThetaInc, 0));
	
	shader_mixer.setUniform1f("fb0KeyThreshold", gui->fb0KeyThreshold
		+lfo(gui->fb0KeyThresholdLfoAmp, fb0KeyThresholdThetaInc, 0));
	shader_mixer.setUniform1f("fb0KeySoft", gui->fb0KeySoft
		+ lfo(gui->fb0KeySoftLfoAmp, fb0KeySoftThetaInc, 0));
	shader_mixer.setUniform1i("fb0KeyOrder", gui->fb0KeyOrder);
	shader_mixer.setUniform1i("fb0MixType", gui->fb0MixType);
	shader_mixer.setUniform1f("fb0Mix", gui->fb0Mix
		+lfo(gui->fb0MixLfoAmp, fb0MixThetaInc, 0));
	shader_mixer.setUniform1i("fb0MixOverflow", gui->fb0MixOverflow);

	shader_mixer.setUniform1f("fb0MaskX", gui->fb0MaskX
		+ lfo(gui->fb0MaskXLfoAmp, fb0MaskXThetaInc, 0));
	shader_mixer.setUniform1f("fb0MaskY", gui->fb0MaskY
		+ lfo(gui->fb0MaskYLfoAmp, fb0MaskYThetaInc, 0));
	float fb0MaskZMapped = gui->fb0MaskZ + lfo(gui->fb0MaskZLfoAmp, fb0MaskZThetaInc, 0);
	//we want a piece wise function here
	//-1->0 or -1->1 should be fine
	//but from 1-2 we want it to go from like 1 to infinity
	
	if (fb0MaskZMapped > 1) {
		fb0MaskZMapped = pow(2,(fb0MaskZMapped-1.0f)*4.0f);
		if (gui->fb0MaskZ == 3.0) { fb0MaskZMapped = 1000; }
	}

	//switch statement for fb0MaskTilemode to 
	//remap fb0 MaskTileAmount appropriately
	//if spiral mode selected (3) then we want it to be like 
	//-3.14 to 3.14

	shader_mixer.setUniform1f("fb0MaskZ", fb0MaskZMapped);
	shader_mixer.setUniform1f("fb0MaskRotate", gui->fb0MaskRotate
		+ lfo(gui->fb0MaskRotateLfoAmp, fb0MaskRotateThetaInc, 0));
	shader_mixer.setUniform1f("fb0MaskTileAmount", gui->fb0MaskTileAmount
		+ lfo(gui->fb0MaskTileAmountLfoAmp, fb0MaskTileAmountThetaInc, 0));
	shader_mixer.setUniform1i("fb0MaskTileMode", gui->fb0MaskTileMode);
	shader_mixer.setUniform1i("fb0MaskTexmod",gui->fb0MaskSelect);
    
	shader_mixer.setUniform1f("fb0MaskTexmodOffset",gui->fb0MaskTexmodOffset
		+ lfo(gui->fb0MaskTexmodOffsetLfoAmp, fb0MaskTexmodOffsetThetaInc, 0));
	shader_mixer.setUniform1i("fb0MaskTexmodQuantizeAmount",gui->fb0MaskTexmodQuantizeAmount
		+ lfo(gui->fb0MaskTexmodQuantizeAmountLfoAmp, fb0MaskTexmodQuantizeAmountThetaInc, 0));
	shader_mixer.setUniform1f("fb0MaskTexmodQuantizeInvert", 1.0/(gui->fb0MaskTexmodQuantizeAmount
		+ lfo(gui->fb0MaskTexmodQuantizeAmountLfoAmp, fb0MaskTexmodQuantizeAmountThetaInc, 0)));
	shader_mixer.setUniform1f("fb0MaskTexmodQuantizeMix", gui->fb0MaskTexmodQuantizeMix
		+ lfo(gui->fb0MaskTexmodQuantizeMixLfoAmp, fb0MaskTexmodQuantizeMixThetaInc, 0));

	//fb0Color
	hsbOffset.set(gui->fb0HueOffset + lfo(gui->fb0HueOffsetLfoAmp, fb0HueOffsetThetaInc, 0),
		gui->fb0SaturationOffset + lfo(gui->fb0SaturationOffsetLfoAmp, fb0SaturationOffsetThetaInc, 0),
		gui->fb0BrightOffset + lfo(gui->fb0BrightOffsetLfoAmp, fb0BrightOffsetThetaInc, 0));
	shader_mixer.setUniform3f("fb0HsbOffset",hsbOffset);
	
	hsb_x.set((gui->fb0HueAttenuate + lfo(gui->fb0HueAttenuateLfoAmp, fb0HueAttenuateThetaInc, 0))*.1f,
		(gui->fb0SaturationAttenuate + lfo(gui->fb0SaturationAttenuateLfoAmp, fb0SaturationAttenuateThetaInc, 0))*.1f ,
		(gui->fb0BrightAttenuate + lfo(gui->fb0BrightAttenuateLfoAmp, fb0BrightAttenuateThetaInc, 0))*.1f);
	shader_mixer.setUniform3f("fb0HsbAttenuate", hsb_x);
	
	shader_mixer.setUniform1f("fb0HueShaper", gui->fb0HueShaper + lfo(gui->fb0HueShaperLfoAmp, fb0HueShaperThetaInc, 0));
	
	powMap.set(gui->fb0HuePowMap + lfo(gui->fb0HuePowMapLfoAmp, fb0HuePowMapThetaInc, 0),
		gui->fb0SaturationPowMap + lfo(gui->fb0SaturationPowMapLfoAmp, fb0SaturationPowMapThetaInc, 0),
		gui->fb0BrightPowMap + lfo(gui->fb0BrightPowMapLfoAmp, fb0BrightPowMapThetaInc, 0));
	shader_mixer.setUniform3f("fb0PowMap", powMap);
    
	shader_mixer.setUniform3f("fb0ColorQuantize", ofVec3f(gui->fb0HueQuantize + lfo(gui->fb0HueQuantizeLfoAmp, fb0HueQuantizeThetaInc, 0),
		gui->fb0SaturationQuantize + lfo(gui->fb0SaturationQuantizeLfoAmp, fb0SaturationQuantizeThetaInc, 0),
		gui->fb0BrightQuantize + lfo(gui->fb0BrightQuantizeLfoAmp, fb0BrightQuantizeThetaInc, 0)));
	shader_mixer.setUniform3f("fb0ColorQuantizeMix", ofVec3f(gui->fb0HueQuantizeMix + lfo(gui->fb0HueQuantizeMixLfoAmp, fb0HueQuantizeMixThetaInc, 0),
		gui->fb0SaturationQuantizeMix + lfo(gui->fb0SaturationQuantizeMixLfoAmp, fb0SaturationQuantizeMixThetaInc, 0),
		gui->fb0BrightQuantizeMix + lfo(gui->fb0BrightQuantizeMixLfoAmp, fb0BrightQuantizeMixThetaInc, 0)));
	shader_mixer.setUniform3f("fb0ColorQuantizeDenom", ofVec3f(1.0f/(gui->fb0HueQuantize + lfo(gui->fb0HueQuantizeLfoAmp, fb0HueQuantizeThetaInc, 0)),
		1.0f/(gui->fb0SaturationQuantize + lfo(gui->fb0SaturationQuantizeLfoAmp, fb0SaturationQuantizeThetaInc, 0)),
		1.0f/(gui->fb0BrightQuantize + lfo(gui->fb0BrightQuantizeLfoAmp, fb0BrightQuantizeThetaInc, 0))));
    
	shader_mixer.setUniform1f("fb0HueDitherMix",gui->fb0HueDitherMix + lfo(gui->fb0HueDitherMixLfoAmp, fb0HueDitherMixThetaInc, 0));
	shader_mixer.setUniform1f("fb0SaturationDitherMix", gui->fb0SaturationDitherMix + lfo(gui->fb0SaturationDitherMixLfoAmp, fb0SaturationDitherMixThetaInc, 0));
	shader_mixer.setUniform1f("fb0BrightDitherMix", gui->fb0BrightDitherMix + lfo(gui->fb0BrightDitherMixLfoAmp, fb0BrightDitherMixThetaInc, 0));
	shader_mixer.setUniform1f("fb0HueDitherAmount", gui->fb0HueDitherAmount + lfo(gui->fb0HueDitherAmountLfoAmp, fb0HueDitherAmountThetaInc, 0));
	shader_mixer.setUniform1f("fb0SaturationDitherAmount", gui->fb0SaturationDitherAmount + lfo(gui->fb0SaturationDitherAmountLfoAmp, fb0SaturationDitherAmountThetaInc, 0));
	shader_mixer.setUniform1f("fb0BrightDitherAmount", gui->fb0BrightDitherAmount + lfo(gui->fb0BrightDitherAmountLfoAmp, fb0BrightDitherAmountThetaInc, 0));

	//fb0ColorSwitches
    fb_modswitch.set(gui->fb0HueInvert,gui->fb0SaturationInvert,gui->fb0BrightInvert);
    shader_mixer.setUniform3f("fb0HsbInvert",fb_modswitch);

	shader_mixer.setUniform1i("fb0SaturationOverflow", gui->fb0SaturationOverflow);
	shader_mixer.setUniform1i("fb0BrightOverflow", gui->fb0BrightOverflow);

	//fb0 Geometry
	shader_mixer.setUniform1i("fb0_toroid_switch", gui->fb0_toroid_switch);
    shader_mixer.setUniform3f("fb0_rescale",ofVec3f(gui->fb0XDisplace+lfo(gui->fb0XDisplaceLfoAmp, fb0XDisplaceThetaInc,0),
                                                    gui->fb0YDisplace+lfo(gui->fb0YDisplaceLfoAmp, fb0YDisplaceThetaInc,0),
                                                    gui->fb0ZDisplace/100.0f+lfo(gui->fb0ZDisplaceLfoAmp, fb0ZDisplaceThetaInc,0)/100.0f));
    
    shader_mixer.setUniform1f("fb0Rotate",(gui->fb0Rotate)+lfo(gui->fb0RotateLfoAmp,fb0RotateThetaInc,0));
	shader_mixer.setUniform1i("fb0RotateMode",gui->fb0RotateMode);
	
	ofVec4f d_fb0ShearMatrix;
	d_fb0ShearMatrix.set(fbShearC*(1.0f / fbShearC + gui->fb0ShearMatrix.x+ lfo(gui->fb0ShearMatrixLfoAmp.x, fb0ShearMatrixThetaInc.x, 0)),
		fbShearC*(gui->fb0ShearMatrix.y + lfo(gui->fb0ShearMatrixLfoAmp.y, fb0ShearMatrixThetaInc.y, 0)),
		fbShearC*(gui->fb0ShearMatrix.z + lfo(gui->fb0ShearMatrixLfoAmp.z, fb0ShearMatrixThetaInc.z, 0)),
		fbShearC*(1.0f/fbShearC +gui->fb0ShearMatrix.w+lfo(gui->fb0ShearMatrixLfoAmp.w, fb0ShearMatrixThetaInc.w, 0))
	);
	shader_mixer.setUniform4f("fb0ShearMatrix",d_fb0ShearMatrix);

	shader_mixer.setUniform1f("fb0FisheyeAmount", gui->fb0FisheyeAmount + lfo(gui->fb0FisheyeAmountLfoAmp, fb0FisheyeAmountThetaInc, 0));
	shader_mixer.setUniform2f("fb0FisheyeCenter",ofVec2f(gui->fb0FisheyeX + lfo(gui->fb0FisheyeXLfoAmp, fb0FisheyeXThetaInc, 0),
		gui->fb0FisheyeY + lfo(gui->fb0FisheyeYLfoAmp, fb0FisheyeYThetaInc, 0)));

	float fb0SpiralAmountC = .15;
	float d_fb0SpiralAmount = fb0SpiralAmountC * (.00001f + 1.0f / fb0SpiralAmountC - (gui->fb0SpiralAmount + lfo(gui->fb0SpiralAmountLfoAmp, fb0SpiralAmountThetaInc, 0)));
	shader_mixer.setUniform1f("fb0SpiralAmount",d_fb0SpiralAmount);
	shader_mixer.setUniform1f("fb0SpiralAngle", gui->fb0SpiralAngle + lfo(gui->fb0SpiralAngleLfoAmp, fb0SpiralAngleThetaInc, 0));
	shader_mixer.setUniform2f("fb0SpiralCenter", ofVec2f(gui->fb0SpiralX + lfo(gui->fb0SpiralXLfoAmp, fb0SpiralXThetaInc, 0),
		gui->fb0SpiralY + lfo(gui->fb0SpiralYLfoAmp, fb0SpiralYThetaInc, 0)));

	shader_mixer.setUniform1f("fb0KaleidoscopeSegments",gui->fb0KaleidoscopeSegments + lfo(gui->fb0KaleidoscopeSegmentsLfoAmp, fb0KaleidoscopeSegmentsThetaInc, 0));
	shader_mixer.setUniform1f("fb0KaleidoscopeSlice", gui->fb0KaleidoscopeSlice + lfo(gui->fb0KaleidoscopeSliceLfoAmp, fb0KaleidoscopeSliceThetaInc, 0));


	//TEXMOD
    shader_mixer.setUniform1f("fb0LumakeyLevelTexmod", gui->fb0LumakeyLevelTexmod);
	shader_mixer.setUniform1f("fb0ChromakeyRedTexmod", gui->fb0ChromakeyRedTexmod);
	shader_mixer.setUniform1f("fb0ChromakeyGreenTexmod", gui->fb0ChromakeyGreenTexmod);
	shader_mixer.setUniform1f("fb0ChromakeyBlueTexmod", gui->fb0ChromakeyBlueTexmod);
    shader_mixer.setUniform1f("fb0KeyThresholdTexmod", gui->fb0KeyThresholdTexmod);
	shader_mixer.setUniform1f("fb0KeySoftTexmod", gui->fb0KeySoftTexmod);
    shader_mixer.setUniform1f("fb0MixTexmod", gui->fb0MixTexmod);

	shader_mixer.setUniform1f("fb0MaskXTexmod", gui->fb0MaskXTexmod);
	shader_mixer.setUniform1f("fb0MaskYTexmod", gui->fb0MaskYTexmod);
	shader_mixer.setUniform1f("fb0MaskZTexmod", gui->fb0MaskZTexmod);
	shader_mixer.setUniform1f("fb0MaskRotateTexmod", gui->fb0MaskRotateTexmod);
	shader_mixer.setUniform1f("fb0MaskTileAmountTexmod", gui->fb0MaskTileAmountTexmod);

	//fb0Color texmods
	shader_mixer.setUniform3f("fb0HsbOffsetTexmod", ofVec3f(gui->fb0HueOffsetTexmod, gui->fb0SaturationOffsetTexmod, gui->fb0BrightOffsetTexmod));
	shader_mixer.setUniform3f("fb0HsbAttenuateTexmod", ofVec3f(gui->fb0HueAttenuateTexmod, gui->fb0SaturationAttenuateTexmod, gui->fb0BrightAttenuateTexmod));
	shader_mixer.setUniform3f("fb0HsbPowMapTexmod", ofVec3f(gui->fb0HuePowMapTexmod, gui->fb0SaturationPowMapTexmod, gui->fb0BrightPowMapTexmod));
	shader_mixer.setUniform1f("fb0HueShaperTexmod",gui->fb0HueShaperTexmod);
	
	
	/*
	shader_mixer.setUniform3f("fb0ColorQuantizeTexmod", ofVec3f(gui->fb0HueQuantizeTexmod,
		gui->fb0SaturationQuantizeTexmod,
		gui->fb0BrightQuantizeTexmod));
	shader_mixer.setUniform3f("fb0ColorQuantizeMixTexmod", ofVec3f(gui->fb0HueQuantizeMixTexmod,
		gui->fb0SaturationQuantizeMixTexmod,
		gui->fb0BrightQuantizeMixTexmod));
	
	shader_mixer.setUniform3f("fb0ColorQuantizeDenomTexmod", ofVec3f(1.0f / (gui->fb0HueQuantizeTexmod),
		1.0f / (gui->fb0SaturationQuantizeTexmod),
		1.0f / (gui->fb0BrightQuantizeTexmod)));
	
	shader_mixer.setUniform1f("fb0HueDitherMixTexmod", gui->fb0HueDitherMixTexmod);
	shader_mixer.setUniform1f("fb0SaturationDitherMixTexmod", gui->fb0SaturationDitherMixTexmod);
	shader_mixer.setUniform1f("fb0BrightDitherMixTexmod", gui->fb0BrightDitherMixTexmod);
	shader_mixer.setUniform1f("fb0HueDitherAmountTexmod", gui->fb0HueDitherAmountTexmod);
	shader_mixer.setUniform1f("fb0SaturationDitherAmountTexmod", gui->fb0SaturationDitherAmountTexmod);
	shader_mixer.setUniform1f("fb0BrightDitherAmountTexmod", gui->fb0BrightDitherAmountTexmod);
    */
    
    shader_mixer.setUniform3f("fb0RescaleTexmod",ofVec3f(gui->fb0XDisplaceTexmod, gui->fb0YDisplaceTexmod, gui->fb0ZDisplaceTexmod));
    shader_mixer.setUniform1f("fb0RotateTexmod",(gui->fb0RotateTexmod));
    shader_mixer.setUniform4f("fb0ShearMatrixTexmod", fbShearC*(gui->fb0ShearMatrixTexmod) );
    
    
    shader_mixer.setUniform1f("fb0FisheyeAmountTexmod", gui->fb0FisheyeAmountTexmod );
    shader_mixer.setUniform2f("fb0FisheyeCenterTexmod",ofVec2f(gui->fb0FisheyeXTexmod ,
                                                         gui->fb0FisheyeYTexmod));
    
    //float d_fb0SpiralAmountTexmod = fb0SpiralAmountC * (.000001f + 1.0f / fb0SpiralAmountC - (gui->fb0SpiralAmountTexmod));
    
    float d_fb0SpiralAmountTexmod = fb0SpiralAmountC * ((gui->fb0SpiralAmountTexmod));
    shader_mixer.setUniform1f("fb0SpiralAmountTexmod",d_fb0SpiralAmountTexmod);
    shader_mixer.setUniform1f("fb0SpiralAngleTexmod", gui->fb0SpiralAngleTexmod);
    shader_mixer.setUniform2f("fb0SpiralCenterTexmod", ofVec2f(gui->fb0SpiralXTexmod,
                                                         gui->fb0SpiralYTexmod ));
    
    shader_mixer.setUniform1f("fb0KaleidoscopeSegmentsTexmod",gui->fb0KaleidoscopeSegmentsTexmod);
    shader_mixer.setUniform1f("fb0KaleidoscopeSliceTexmod", gui->fb0KaleidoscopeSliceTexmod);
    
    
    ofVec2f fb0TexmodLogic;
    if(gui->fb0TexmodSelect==0){
        fb0TexmodLogic.set(1,0);
    }
    
    if(gui->fb0TexmodSelect==1){
        fb0TexmodLogic.set(0,1);
    }
    
    shader_mixer.setUniform2f("fb0TexmodLogic",fb0TexmodLogic);
    
    //fb0 pixel
    shader_mixer.setUniform1i("fb0PixelSwitch",gui->fb0PixelSwitch);
    shader_mixer.setUniform1i("fb0XPixelScale",gui->fb0XPixelScale+lfo(gui->fb0XPixelScaleLfoAmp,fb0XPixelScaleThetaInc,0));
    shader_mixer.setUniform1i("fb0YPixelScale",gui->fb0YPixelScale+lfo(gui->fb0YPixelScaleLfoAmp,fb0YPixelScaleThetaInc,0));
    if(gui->fb0PixelXYLock==1){
        shader_mixer.setUniform1i("fb0YPixelScale", gui->fb0XPixelScale + lfo(gui->fb0XPixelScaleLfoAmp, fb0XPixelScaleThetaInc, 0));
    }
    shader_mixer.setUniform1f("fb0PixelMix", gui->fb0PixelMix + lfo(gui->fb0PixelMixLfoAmp, fb0PixelMixThetaInc, 0));
    shader_mixer.setUniform1f("fb0PixelBrightscale",gui->fb0PixelBrightscale+lfo(gui->fb0PixelBrightscaleLfoAmp,fb0PixelBrightscaleThetaInc,0));
    //fb0 texmods
    
    shader_mixer.setUniform1i("fb0XPixelScaleTexmod",gui->fb0XPixelScaleTexmod);
    shader_mixer.setUniform1i("fb0YPixelScaleTexmod",gui->fb0YPixelScaleTexmod);
    shader_mixer.setUniform1f("fb0PixelMixTexmod",gui->fb0PixelMixTexmod);
    shader_mixer.setUniform1f("fb0PixelBrightscaleTexmod",gui->fb0PixelBrightscaleTexmod);
    
    
    
    
    
    
    
    
    
    //fb1
    //fb1 variables
    //fb1Mixing
    shader_mixer.setUniform1i("fb1KeyMode", gui->fb1KeyMode);
    shader_mixer.setUniform1f("fb1LumakeyLevel", gui->fb1LumakeyLevel
                              +lfo(gui->fb1LumakeyLevelLfoAmp, fb1LumakeyLevelThetaInc, 0));
    shader_mixer.setUniform1f("fb1ChromakeyRed", gui->fb1ChromakeyRed
                              + lfo(gui->fb1ChromakeyRedLfoAmp, fb1ChromakeyRedThetaInc, 0));
    shader_mixer.setUniform1f("fb1ChromakeyGreen", gui->fb1ChromakeyGreen
                              + lfo(gui->fb1ChromakeyGreenLfoAmp, fb1ChromakeyGreenThetaInc, 0));
    shader_mixer.setUniform1f("fb1ChromakeyBlue", gui->fb1ChromakeyBlue
                              + lfo(gui->fb1ChromakeyBlueLfoAmp, fb1ChromakeyBlueThetaInc, 0));
    
    shader_mixer.setUniform1f("fb1KeyThreshold", gui->fb1KeyThreshold
                              +lfo(gui->fb1KeyThresholdLfoAmp, fb1KeyThresholdThetaInc, 0));
    shader_mixer.setUniform1f("fb1KeySoft", gui->fb1KeySoft
                              + lfo(gui->fb1KeySoftLfoAmp, fb1KeySoftThetaInc, 0));
    shader_mixer.setUniform1i("fb1KeyOrder", gui->fb1KeyOrder);
    shader_mixer.setUniform1i("fb1MixType", gui->fb1MixType);
    shader_mixer.setUniform1f("fb1Mix", gui->fb1Mix
                              +lfo(gui->fb1MixLfoAmp, fb1MixThetaInc, 0));
    shader_mixer.setUniform1i("fb1MixOverflow", gui->fb1MixOverflow);
    
    shader_mixer.setUniform1f("fb1MaskX", gui->fb1MaskX
                              + lfo(gui->fb1MaskXLfoAmp, fb1MaskXThetaInc, 0));
    shader_mixer.setUniform1f("fb1MaskY", gui->fb1MaskY
                              + lfo(gui->fb1MaskYLfoAmp, fb1MaskYThetaInc, 0));
    float fb1MaskZMapped = gui->fb1MaskZ + lfo(gui->fb1MaskZLfoAmp, fb1MaskZThetaInc, 0);
    //we want a piece wise function here
    //-1->0 or -1->1 should be fine
    //but from 1-2 we want it to go from like 1 to infinity
    
    if (fb1MaskZMapped > 1) {
        fb1MaskZMapped = pow(2,(fb1MaskZMapped-1.0f)*4.0f);
        if (gui->fb1MaskZ == 3.0) { fb1MaskZMapped = 1000; }
    }
    
    //switch statement for fb1MaskTilemode to
    //remap fb1 MaskTileAmount appropriately
    //if spiral mode selected (3) then we want it to be like
    //-3.14 to 3.14
    
    shader_mixer.setUniform1f("fb1MaskZ", fb1MaskZMapped);
    shader_mixer.setUniform1f("fb1MaskRotate", gui->fb1MaskRotate
                              + lfo(gui->fb1MaskRotateLfoAmp, fb1MaskRotateThetaInc, 0));
    shader_mixer.setUniform1f("fb1MaskTileAmount", gui->fb1MaskTileAmount
                              + lfo(gui->fb1MaskTileAmountLfoAmp, fb1MaskTileAmountThetaInc, 0));
    shader_mixer.setUniform1i("fb1MaskTileMode", gui->fb1MaskTileMode);
    shader_mixer.setUniform1i("fb1MaskTexmod",gui->fb1MaskSelect);
    
    shader_mixer.setUniform1f("fb1MaskTexmodOffset",gui->fb1MaskTexmodOffset
                              + lfo(gui->fb1MaskTexmodOffsetLfoAmp, fb1MaskTexmodOffsetThetaInc, 0));
    shader_mixer.setUniform1i("fb1MaskTexmodQuantizeAmount",gui->fb1MaskTexmodQuantizeAmount
                              + lfo(gui->fb1MaskTexmodQuantizeAmountLfoAmp, fb1MaskTexmodQuantizeAmountThetaInc, 0));
    shader_mixer.setUniform1f("fb1MaskTexmodQuantizeInvert", 1.0/(gui->fb1MaskTexmodQuantizeAmount
                                                                  + lfo(gui->fb1MaskTexmodQuantizeAmountLfoAmp, fb1MaskTexmodQuantizeAmountThetaInc, 0)));
    shader_mixer.setUniform1f("fb1MaskTexmodQuantizeMix", gui->fb1MaskTexmodQuantizeMix
                              + lfo(gui->fb1MaskTexmodQuantizeMixLfoAmp, fb1MaskTexmodQuantizeMixThetaInc, 0));
    
    //fb1Color
    hsbOffset.set(gui->fb1HueOffset + lfo(gui->fb1HueOffsetLfoAmp, fb1HueOffsetThetaInc, 0),
                  gui->fb1SaturationOffset + lfo(gui->fb1SaturationOffsetLfoAmp, fb1SaturationOffsetThetaInc, 0),
                  gui->fb1BrightOffset + lfo(gui->fb1BrightOffsetLfoAmp, fb1BrightOffsetThetaInc, 0));
    shader_mixer.setUniform3f("fb1HsbOffset",hsbOffset);
    
    hsb_x.set((gui->fb1HueAttenuate + lfo(gui->fb1HueAttenuateLfoAmp, fb1HueAttenuateThetaInc, 0))*.1f,
              (gui->fb1SaturationAttenuate + lfo(gui->fb1SaturationAttenuateLfoAmp, fb1SaturationAttenuateThetaInc, 0))*.1f ,
              (gui->fb1BrightAttenuate + lfo(gui->fb1BrightAttenuateLfoAmp, fb1BrightAttenuateThetaInc, 0))*.1f);
    shader_mixer.setUniform3f("fb1HsbAttenuate", hsb_x);
    
    shader_mixer.setUniform1f("fb1HueShaper", gui->fb1HueShaper + lfo(gui->fb1HueShaperLfoAmp, fb1HueShaperThetaInc, 0));
    
    powMap.set(gui->fb1HuePowMap + lfo(gui->fb1HuePowMapLfoAmp, fb1HuePowMapThetaInc, 0),
               gui->fb1SaturationPowMap + lfo(gui->fb1SaturationPowMapLfoAmp, fb1SaturationPowMapThetaInc, 0),
               gui->fb1BrightPowMap + lfo(gui->fb1BrightPowMapLfoAmp, fb1BrightPowMapThetaInc, 0));
    shader_mixer.setUniform3f("fb1PowMap", powMap);
    
    shader_mixer.setUniform3f("fb1ColorQuantize", ofVec3f(gui->fb1HueQuantize + lfo(gui->fb1HueQuantizeLfoAmp, fb1HueQuantizeThetaInc, 0),
                                                          gui->fb1SaturationQuantize + lfo(gui->fb1SaturationQuantizeLfoAmp, fb1SaturationQuantizeThetaInc, 0),
                                                          gui->fb1BrightQuantize + lfo(gui->fb1BrightQuantizeLfoAmp, fb1BrightQuantizeThetaInc, 0)));
    shader_mixer.setUniform3f("fb1ColorQuantizeMix", ofVec3f(gui->fb1HueQuantizeMix + lfo(gui->fb1HueQuantizeMixLfoAmp, fb1HueQuantizeMixThetaInc, 0),
                                                             gui->fb1SaturationQuantizeMix + lfo(gui->fb1SaturationQuantizeMixLfoAmp, fb1SaturationQuantizeMixThetaInc, 0),
                                                             gui->fb1BrightQuantizeMix + lfo(gui->fb1BrightQuantizeMixLfoAmp, fb1BrightQuantizeMixThetaInc, 0)));
    shader_mixer.setUniform3f("fb1ColorQuantizeDenom", ofVec3f(1.0f/(gui->fb1HueQuantize + lfo(gui->fb1HueQuantizeLfoAmp, fb1HueQuantizeThetaInc, 0)),
                                                               1.0f/(gui->fb1SaturationQuantize + lfo(gui->fb1SaturationQuantizeLfoAmp, fb1SaturationQuantizeThetaInc, 0)),
                                                               1.0f/(gui->fb1BrightQuantize + lfo(gui->fb1BrightQuantizeLfoAmp, fb1BrightQuantizeThetaInc, 0))));
    
    shader_mixer.setUniform1f("fb1HueDitherMix",gui->fb1HueDitherMix + lfo(gui->fb1HueDitherMixLfoAmp, fb1HueDitherMixThetaInc, 0));
    shader_mixer.setUniform1f("fb1SaturationDitherMix", gui->fb1SaturationDitherMix + lfo(gui->fb1SaturationDitherMixLfoAmp, fb1SaturationDitherMixThetaInc, 0));
    shader_mixer.setUniform1f("fb1BrightDitherMix", gui->fb1BrightDitherMix + lfo(gui->fb1BrightDitherMixLfoAmp, fb1BrightDitherMixThetaInc, 0));
    shader_mixer.setUniform1f("fb1HueDitherAmount", gui->fb1HueDitherAmount + lfo(gui->fb1HueDitherAmountLfoAmp, fb1HueDitherAmountThetaInc, 0));
    shader_mixer.setUniform1f("fb1SaturationDitherAmount", gui->fb1SaturationDitherAmount + lfo(gui->fb1SaturationDitherAmountLfoAmp, fb1SaturationDitherAmountThetaInc, 0));
    shader_mixer.setUniform1f("fb1BrightDitherAmount", gui->fb1BrightDitherAmount + lfo(gui->fb1BrightDitherAmountLfoAmp, fb1BrightDitherAmountThetaInc, 0));
    
    //fb1ColorSwitches
    fb_modswitch.set(gui->fb1HueInvert,gui->fb1SaturationInvert,gui->fb1BrightInvert);
    shader_mixer.setUniform3f("fb1HsbInvert",fb_modswitch);
    
    shader_mixer.setUniform1i("fb1SaturationOverflow", gui->fb1SaturationOverflow);
    shader_mixer.setUniform1i("fb1BrightOverflow", gui->fb1BrightOverflow);
    
    //fb1 Geometry
    shader_mixer.setUniform1i("fb1_toroid_switch", gui->fb1_toroid_switch);
    shader_mixer.setUniform3f("fb1_rescale",ofVec3f(gui->fb1XDisplace+lfo(gui->fb1XDisplaceLfoAmp, fb1XDisplaceThetaInc,0),
                                                    gui->fb1YDisplace+lfo(gui->fb1YDisplaceLfoAmp, fb1YDisplaceThetaInc,0),
                                                    gui->fb1ZDisplace/100.0f+lfo(gui->fb1ZDisplaceLfoAmp, fb1ZDisplaceThetaInc,0)/100.0f));
    
    shader_mixer.setUniform1f("fb1Rotate",(gui->fb1Rotate)+lfo(gui->fb1RotateLfoAmp,fb1RotateThetaInc,0));
    shader_mixer.setUniform1i("fb1RotateMode",gui->fb1RotateMode);
    
    ofVec4f d_fb1ShearMatrix;
    d_fb1ShearMatrix.set(fbShearC*(1.0f / fbShearC + gui->fb1ShearMatrix.x+ lfo(gui->fb1ShearMatrixLfoAmp.x, fb1ShearMatrixThetaInc.x, 0)),
                         fbShearC*(gui->fb1ShearMatrix.y + lfo(gui->fb1ShearMatrixLfoAmp.y, fb1ShearMatrixThetaInc.y, 0)),
                         fbShearC*(gui->fb1ShearMatrix.z + lfo(gui->fb1ShearMatrixLfoAmp.z, fb1ShearMatrixThetaInc.z, 0)),
                         fbShearC*(1.0f/fbShearC +gui->fb1ShearMatrix.w+lfo(gui->fb1ShearMatrixLfoAmp.w, fb1ShearMatrixThetaInc.w, 0))
                         );
    shader_mixer.setUniform4f("fb1ShearMatrix",d_fb1ShearMatrix);
    
    shader_mixer.setUniform1f("fb1FisheyeAmount", gui->fb1FisheyeAmount + lfo(gui->fb1FisheyeAmountLfoAmp, fb1FisheyeAmountThetaInc, 0));
    shader_mixer.setUniform2f("fb1FisheyeCenter",ofVec2f(gui->fb1FisheyeX + lfo(gui->fb1FisheyeXLfoAmp, fb1FisheyeXThetaInc, 0),
                                                         gui->fb1FisheyeY + lfo(gui->fb1FisheyeYLfoAmp, fb1FisheyeYThetaInc, 0)));
    
    float fb1SpiralAmountC = .15;
    float d_fb1SpiralAmount = fb1SpiralAmountC * (.00001f + 1.0f / fb1SpiralAmountC - (gui->fb1SpiralAmount + lfo(gui->fb1SpiralAmountLfoAmp, fb1SpiralAmountThetaInc, 0)));
    shader_mixer.setUniform1f("fb1SpiralAmount",d_fb1SpiralAmount);
    shader_mixer.setUniform1f("fb1SpiralAngle", gui->fb1SpiralAngle + lfo(gui->fb1SpiralAngleLfoAmp, fb1SpiralAngleThetaInc, 0));
    shader_mixer.setUniform2f("fb1SpiralCenter", ofVec2f(gui->fb1SpiralX + lfo(gui->fb1SpiralXLfoAmp, fb1SpiralXThetaInc, 0),
                                                         gui->fb1SpiralY + lfo(gui->fb1SpiralYLfoAmp, fb1SpiralYThetaInc, 0)));
    
    shader_mixer.setUniform1f("fb1KaleidoscopeSegments",gui->fb1KaleidoscopeSegments + lfo(gui->fb1KaleidoscopeSegmentsLfoAmp, fb1KaleidoscopeSegmentsThetaInc, 0));
    shader_mixer.setUniform1f("fb1KaleidoscopeSlice", gui->fb1KaleidoscopeSlice + lfo(gui->fb1KaleidoscopeSliceLfoAmp, fb1KaleidoscopeSliceThetaInc, 0));
    
    
    //TEXMOD
    shader_mixer.setUniform1f("fb1LumakeyLevelTexmod", gui->fb1LumakeyLevelTexmod);
    shader_mixer.setUniform1f("fb1ChromakeyRedTexmod", gui->fb1ChromakeyRedTexmod);
    shader_mixer.setUniform1f("fb1ChromakeyGreenTexmod", gui->fb1ChromakeyGreenTexmod);
    shader_mixer.setUniform1f("fb1ChromakeyBlueTexmod", gui->fb1ChromakeyBlueTexmod);
    shader_mixer.setUniform1f("fb1KeyThresholdTexmod", gui->fb1KeyThresholdTexmod);
    shader_mixer.setUniform1f("fb1KeySoftTexmod", gui->fb1KeySoftTexmod);
    shader_mixer.setUniform1f("fb1MixTexmod", gui->fb1MixTexmod);
    
    shader_mixer.setUniform1f("fb1MaskXTexmod", gui->fb1MaskXTexmod);
    shader_mixer.setUniform1f("fb1MaskYTexmod", gui->fb1MaskYTexmod);
    shader_mixer.setUniform1f("fb1MaskZTexmod", gui->fb1MaskZTexmod);
    shader_mixer.setUniform1f("fb1MaskRotateTexmod", gui->fb1MaskRotateTexmod);
    shader_mixer.setUniform1f("fb1MaskTileAmountTexmod", gui->fb1MaskTileAmountTexmod);
    
    //fb1Color texmods
    shader_mixer.setUniform3f("fb1HsbOffsetTexmod", ofVec3f(gui->fb1HueOffsetTexmod, gui->fb1SaturationOffsetTexmod, gui->fb1BrightOffsetTexmod));
    shader_mixer.setUniform3f("fb1HsbAttenuateTexmod", ofVec3f(gui->fb1HueAttenuateTexmod, gui->fb1SaturationAttenuateTexmod, gui->fb1BrightAttenuateTexmod));
    shader_mixer.setUniform3f("fb1HsbPowMapTexmod", ofVec3f(gui->fb1HuePowMapTexmod, gui->fb1SaturationPowMapTexmod, gui->fb1BrightPowMapTexmod));
    shader_mixer.setUniform1f("fb1HueShaperTexmod",gui->fb1HueShaperTexmod);
    
    
    /*
     shader_mixer.setUniform3f("fb1ColorQuantizeTexmod", ofVec3f(gui->fb1HueQuantizeTexmod,
     gui->fb1SaturationQuantizeTexmod,
     gui->fb1BrightQuantizeTexmod));
     shader_mixer.setUniform3f("fb1ColorQuantizeMixTexmod", ofVec3f(gui->fb1HueQuantizeMixTexmod,
     gui->fb1SaturationQuantizeMixTexmod,
     gui->fb1BrightQuantizeMixTexmod));
     
     shader_mixer.setUniform3f("fb1ColorQuantizeDenomTexmod", ofVec3f(1.0f / (gui->fb1HueQuantizeTexmod),
     1.0f / (gui->fb1SaturationQuantizeTexmod),
     1.0f / (gui->fb1BrightQuantizeTexmod)));
     
     shader_mixer.setUniform1f("fb1HueDitherMixTexmod", gui->fb1HueDitherMixTexmod);
     shader_mixer.setUniform1f("fb1SaturationDitherMixTexmod", gui->fb1SaturationDitherMixTexmod);
     shader_mixer.setUniform1f("fb1BrightDitherMixTexmod", gui->fb1BrightDitherMixTexmod);
     shader_mixer.setUniform1f("fb1HueDitherAmountTexmod", gui->fb1HueDitherAmountTexmod);
     shader_mixer.setUniform1f("fb1SaturationDitherAmountTexmod", gui->fb1SaturationDitherAmountTexmod);
     shader_mixer.setUniform1f("fb1BrightDitherAmountTexmod", gui->fb1BrightDitherAmountTexmod);
     */
    
    shader_mixer.setUniform3f("fb1RescaleTexmod",ofVec3f(gui->fb1XDisplaceTexmod, gui->fb1YDisplaceTexmod, gui->fb1ZDisplaceTexmod));
    shader_mixer.setUniform1f("fb1RotateTexmod",(gui->fb1RotateTexmod));
    shader_mixer.setUniform4f("fb1ShearMatrixTexmod", fbShearC*(gui->fb1ShearMatrixTexmod) );
    
    
    shader_mixer.setUniform1f("fb1FisheyeAmountTexmod", gui->fb1FisheyeAmountTexmod );
    shader_mixer.setUniform2f("fb1FisheyeCenterTexmod",ofVec2f(gui->fb1FisheyeXTexmod ,
                                                               gui->fb1FisheyeYTexmod));
    
    float d_fb1SpiralAmountTexmod = fb1SpiralAmountC * ((gui->fb1SpiralAmountTexmod));
    shader_mixer.setUniform1f("fb1SpiralAmountTexmod",d_fb1SpiralAmountTexmod);
    shader_mixer.setUniform1f("fb1SpiralAngleTexmod", gui->fb1SpiralAngleTexmod);
    shader_mixer.setUniform2f("fb1SpiralCenterTexmod", ofVec2f(gui->fb1SpiralXTexmod,
                                                               gui->fb1SpiralYTexmod ));
    
    shader_mixer.setUniform1f("fb1KaleidoscopeSegmentsTexmod",gui->fb1KaleidoscopeSegmentsTexmod);
    shader_mixer.setUniform1f("fb1KaleidoscopeSliceTexmod", gui->fb1KaleidoscopeSliceTexmod);
    
    
    ofVec2f fb1TexmodLogic;
    if(gui->fb1TexmodSelect==0){
        fb1TexmodLogic.set(1,0);
    }
    
    if(gui->fb1TexmodSelect==1){
        fb1TexmodLogic.set(0,1);
    }
    
    shader_mixer.setUniform2f("fb1TexmodLogic",fb1TexmodLogic);
    
    //fb1 pixel
    shader_mixer.setUniform1i("fb1PixelSwitch",gui->fb1PixelSwitch);
    shader_mixer.setUniform1i("fb1XPixelScale",gui->fb1XPixelScale+lfo(gui->fb1XPixelScaleLfoAmp,fb1XPixelScaleThetaInc,0));
    shader_mixer.setUniform1i("fb1YPixelScale",gui->fb1YPixelScale+lfo(gui->fb1YPixelScaleLfoAmp,fb1YPixelScaleThetaInc,0));
    if(gui->fb1PixelXYLock==1){
        shader_mixer.setUniform1i("fb1YPixelScale", gui->fb1XPixelScale + lfo(gui->fb1XPixelScaleLfoAmp, fb1XPixelScaleThetaInc, 0));
    }
    shader_mixer.setUniform1f("fb1PixelMix", gui->fb1PixelMix + lfo(gui->fb1PixelMixLfoAmp, fb1PixelMixThetaInc, 0));
    shader_mixer.setUniform1f("fb1PixelBrightscale",gui->fb1PixelBrightscale+lfo(gui->fb1PixelBrightscaleLfoAmp,fb1PixelBrightscaleThetaInc,0));
    //fb1 texmods
    
    shader_mixer.setUniform1i("fb1XPixelScaleTexmod",gui->fb1XPixelScaleTexmod);
    shader_mixer.setUniform1i("fb1YPixelScaleTexmod",gui->fb1YPixelScaleTexmod);
    shader_mixer.setUniform1f("fb1PixelMixTexmod",gui->fb1PixelMixTexmod);
    shader_mixer.setUniform1f("fb1PixelBrightscaleTexmod",gui->fb1PixelBrightscaleTexmod);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //fb2
    //fb2 variables
    //fb2Mixing
    shader_mixer.setUniform1i("fb2KeyMode", gui->fb2KeyMode);
    shader_mixer.setUniform1f("fb2LumakeyLevel", gui->fb2LumakeyLevel
                              +lfo(gui->fb2LumakeyLevelLfoAmp, fb2LumakeyLevelThetaInc, 0));
    shader_mixer.setUniform1f("fb2ChromakeyRed", gui->fb2ChromakeyRed
                              + lfo(gui->fb2ChromakeyRedLfoAmp, fb2ChromakeyRedThetaInc, 0));
    shader_mixer.setUniform1f("fb2ChromakeyGreen", gui->fb2ChromakeyGreen
                              + lfo(gui->fb2ChromakeyGreenLfoAmp, fb2ChromakeyGreenThetaInc, 0));
    shader_mixer.setUniform1f("fb2ChromakeyBlue", gui->fb2ChromakeyBlue
                              + lfo(gui->fb2ChromakeyBlueLfoAmp, fb2ChromakeyBlueThetaInc, 0));
    
    shader_mixer.setUniform1f("fb2KeyThreshold", gui->fb2KeyThreshold
                              +lfo(gui->fb2KeyThresholdLfoAmp, fb2KeyThresholdThetaInc, 0));
    shader_mixer.setUniform1f("fb2KeySoft", gui->fb2KeySoft
                              + lfo(gui->fb2KeySoftLfoAmp, fb2KeySoftThetaInc, 0));
    shader_mixer.setUniform1i("fb2KeyOrder", gui->fb2KeyOrder);
    shader_mixer.setUniform1i("fb2MixType", gui->fb2MixType);
    shader_mixer.setUniform1f("fb2Mix", gui->fb2Mix
                              +lfo(gui->fb2MixLfoAmp, fb2MixThetaInc, 0));
    shader_mixer.setUniform1i("fb2MixOverflow", gui->fb2MixOverflow);
    
    shader_mixer.setUniform1f("fb2MaskX", gui->fb2MaskX
                              + lfo(gui->fb2MaskXLfoAmp, fb2MaskXThetaInc, 0));
    shader_mixer.setUniform1f("fb2MaskY", gui->fb2MaskY
                              + lfo(gui->fb2MaskYLfoAmp, fb2MaskYThetaInc, 0));
    float fb2MaskZMapped = gui->fb2MaskZ + lfo(gui->fb2MaskZLfoAmp, fb2MaskZThetaInc, 0);
    //we want a piece wise function here
    //-1->0 or -1->1 should be fine
    //but from 1-2 we want it to go from like 1 to infinity
    
    if (fb2MaskZMapped > 1) {
        fb2MaskZMapped = pow(2,(fb2MaskZMapped-1.0f)*4.0f);
        if (gui->fb2MaskZ == 3.0) { fb2MaskZMapped = 1000; }
    }
    
    //switch statement for fb2MaskTilemode to
    //remap fb2 MaskTileAmount appropriately
    //if spiral mode selected (3) then we want it to be like
    //-3.14 to 3.14
    
    shader_mixer.setUniform1f("fb2MaskZ", fb2MaskZMapped);
    shader_mixer.setUniform1f("fb2MaskRotate", gui->fb2MaskRotate
                              + lfo(gui->fb2MaskRotateLfoAmp, fb2MaskRotateThetaInc, 0));
    shader_mixer.setUniform1f("fb2MaskTileAmount", gui->fb2MaskTileAmount
                              + lfo(gui->fb2MaskTileAmountLfoAmp, fb2MaskTileAmountThetaInc, 0));
    shader_mixer.setUniform1i("fb2MaskTileMode", gui->fb2MaskTileMode);
    shader_mixer.setUniform1i("fb2MaskTexmod",gui->fb2MaskSelect);
    
    shader_mixer.setUniform1f("fb2MaskTexmodOffset",gui->fb2MaskTexmodOffset
                              + lfo(gui->fb2MaskTexmodOffsetLfoAmp, fb2MaskTexmodOffsetThetaInc, 0));
    shader_mixer.setUniform1i("fb2MaskTexmodQuantizeAmount",gui->fb2MaskTexmodQuantizeAmount
                              + lfo(gui->fb2MaskTexmodQuantizeAmountLfoAmp, fb2MaskTexmodQuantizeAmountThetaInc, 0));
    shader_mixer.setUniform1f("fb2MaskTexmodQuantizeInvert", 1.0/(gui->fb2MaskTexmodQuantizeAmount
                                                                  + lfo(gui->fb2MaskTexmodQuantizeAmountLfoAmp, fb2MaskTexmodQuantizeAmountThetaInc, 0)));
    shader_mixer.setUniform1f("fb2MaskTexmodQuantizeMix", gui->fb2MaskTexmodQuantizeMix
                              + lfo(gui->fb2MaskTexmodQuantizeMixLfoAmp, fb2MaskTexmodQuantizeMixThetaInc, 0));
    
    //fb2Color
    hsbOffset.set(gui->fb2HueOffset + lfo(gui->fb2HueOffsetLfoAmp, fb2HueOffsetThetaInc, 0),
                  gui->fb2SaturationOffset + lfo(gui->fb2SaturationOffsetLfoAmp, fb2SaturationOffsetThetaInc, 0),
                  gui->fb2BrightOffset + lfo(gui->fb2BrightOffsetLfoAmp, fb2BrightOffsetThetaInc, 0));
    shader_mixer.setUniform3f("fb2HsbOffset",hsbOffset);
    
    hsb_x.set((gui->fb2HueAttenuate + lfo(gui->fb2HueAttenuateLfoAmp, fb2HueAttenuateThetaInc, 0))*.1f,
              (gui->fb2SaturationAttenuate + lfo(gui->fb2SaturationAttenuateLfoAmp, fb2SaturationAttenuateThetaInc, 0))*.1f ,
              (gui->fb2BrightAttenuate + lfo(gui->fb2BrightAttenuateLfoAmp, fb2BrightAttenuateThetaInc, 0))*.1f);
    shader_mixer.setUniform3f("fb2HsbAttenuate", hsb_x);
    
    shader_mixer.setUniform1f("fb2HueShaper", gui->fb2HueShaper + lfo(gui->fb2HueShaperLfoAmp, fb2HueShaperThetaInc, 0));
    
    powMap.set(gui->fb2HuePowMap + lfo(gui->fb2HuePowMapLfoAmp, fb2HuePowMapThetaInc, 0),
               gui->fb2SaturationPowMap + lfo(gui->fb2SaturationPowMapLfoAmp, fb2SaturationPowMapThetaInc, 0),
               gui->fb2BrightPowMap + lfo(gui->fb2BrightPowMapLfoAmp, fb2BrightPowMapThetaInc, 0));
    shader_mixer.setUniform3f("fb2PowMap", powMap);
    
    shader_mixer.setUniform3f("fb2ColorQuantize", ofVec3f(gui->fb2HueQuantize + lfo(gui->fb2HueQuantizeLfoAmp, fb2HueQuantizeThetaInc, 0),
                                                          gui->fb2SaturationQuantize + lfo(gui->fb2SaturationQuantizeLfoAmp, fb2SaturationQuantizeThetaInc, 0),
                                                          gui->fb2BrightQuantize + lfo(gui->fb2BrightQuantizeLfoAmp, fb2BrightQuantizeThetaInc, 0)));
    shader_mixer.setUniform3f("fb2ColorQuantizeMix", ofVec3f(gui->fb2HueQuantizeMix + lfo(gui->fb2HueQuantizeMixLfoAmp, fb2HueQuantizeMixThetaInc, 0),
                                                             gui->fb2SaturationQuantizeMix + lfo(gui->fb2SaturationQuantizeMixLfoAmp, fb2SaturationQuantizeMixThetaInc, 0),
                                                             gui->fb2BrightQuantizeMix + lfo(gui->fb2BrightQuantizeMixLfoAmp, fb2BrightQuantizeMixThetaInc, 0)));
    shader_mixer.setUniform3f("fb2ColorQuantizeDenom", ofVec3f(1.0f/(gui->fb2HueQuantize + lfo(gui->fb2HueQuantizeLfoAmp, fb2HueQuantizeThetaInc, 0)),
                                                               1.0f/(gui->fb2SaturationQuantize + lfo(gui->fb2SaturationQuantizeLfoAmp, fb2SaturationQuantizeThetaInc, 0)),
                                                               1.0f/(gui->fb2BrightQuantize + lfo(gui->fb2BrightQuantizeLfoAmp, fb2BrightQuantizeThetaInc, 0))));
    
    shader_mixer.setUniform1f("fb2HueDitherMix",gui->fb2HueDitherMix + lfo(gui->fb2HueDitherMixLfoAmp, fb2HueDitherMixThetaInc, 0));
    shader_mixer.setUniform1f("fb2SaturationDitherMix", gui->fb2SaturationDitherMix + lfo(gui->fb2SaturationDitherMixLfoAmp, fb2SaturationDitherMixThetaInc, 0));
    shader_mixer.setUniform1f("fb2BrightDitherMix", gui->fb2BrightDitherMix + lfo(gui->fb2BrightDitherMixLfoAmp, fb2BrightDitherMixThetaInc, 0));
    shader_mixer.setUniform1f("fb2HueDitherAmount", gui->fb2HueDitherAmount + lfo(gui->fb2HueDitherAmountLfoAmp, fb2HueDitherAmountThetaInc, 0));
    shader_mixer.setUniform1f("fb2SaturationDitherAmount", gui->fb2SaturationDitherAmount + lfo(gui->fb2SaturationDitherAmountLfoAmp, fb2SaturationDitherAmountThetaInc, 0));
    shader_mixer.setUniform1f("fb2BrightDitherAmount", gui->fb2BrightDitherAmount + lfo(gui->fb2BrightDitherAmountLfoAmp, fb2BrightDitherAmountThetaInc, 0));
    
    //fb2ColorSwitches
    fb_modswitch.set(gui->fb2HueInvert,gui->fb2SaturationInvert,gui->fb2BrightInvert);
    shader_mixer.setUniform3f("fb2HsbInvert",fb_modswitch);
    
    shader_mixer.setUniform1i("fb2SaturationOverflow", gui->fb2SaturationOverflow);
    shader_mixer.setUniform1i("fb2BrightOverflow", gui->fb2BrightOverflow);
    
    //fb2 Geometry
    shader_mixer.setUniform1i("fb2_toroid_switch", gui->fb2_toroid_switch);
    shader_mixer.setUniform3f("fb2_rescale",ofVec3f(gui->fb2XDisplace+lfo(gui->fb2XDisplaceLfoAmp, fb2XDisplaceThetaInc,0),
                                                    gui->fb2YDisplace+lfo(gui->fb2YDisplaceLfoAmp, fb2YDisplaceThetaInc,0),
                                                    gui->fb2ZDisplace/100.0f+lfo(gui->fb2ZDisplaceLfoAmp, fb2ZDisplaceThetaInc,0)/100.0f));
    
    shader_mixer.setUniform1f("fb2Rotate",(gui->fb2Rotate)+lfo(gui->fb2RotateLfoAmp,fb2RotateThetaInc,0));
    shader_mixer.setUniform1i("fb2RotateMode",gui->fb2RotateMode);
    
    ofVec4f d_fb2ShearMatrix;
    d_fb2ShearMatrix.set(fbShearC*(1.0f / fbShearC + gui->fb2ShearMatrix.x+ lfo(gui->fb2ShearMatrixLfoAmp.x, fb2ShearMatrixThetaInc.x, 0)),
                         fbShearC*(gui->fb2ShearMatrix.y + lfo(gui->fb2ShearMatrixLfoAmp.y, fb2ShearMatrixThetaInc.y, 0)),
                         fbShearC*(gui->fb2ShearMatrix.z + lfo(gui->fb2ShearMatrixLfoAmp.z, fb2ShearMatrixThetaInc.z, 0)),
                         fbShearC*(1.0f/fbShearC +gui->fb2ShearMatrix.w+lfo(gui->fb2ShearMatrixLfoAmp.w, fb2ShearMatrixThetaInc.w, 0))
                         );
    shader_mixer.setUniform4f("fb2ShearMatrix",d_fb2ShearMatrix);
    
    shader_mixer.setUniform1f("fb2FisheyeAmount", gui->fb2FisheyeAmount + lfo(gui->fb2FisheyeAmountLfoAmp, fb2FisheyeAmountThetaInc, 0));
    shader_mixer.setUniform2f("fb2FisheyeCenter",ofVec2f(gui->fb2FisheyeX + lfo(gui->fb2FisheyeXLfoAmp, fb2FisheyeXThetaInc, 0),
                                                         gui->fb2FisheyeY + lfo(gui->fb2FisheyeYLfoAmp, fb2FisheyeYThetaInc, 0)));
    
    float fb2SpiralAmountC = .15;
    float d_fb2SpiralAmount = fb2SpiralAmountC * (.00001f + 1.0f / fb2SpiralAmountC - (gui->fb2SpiralAmount + lfo(gui->fb2SpiralAmountLfoAmp, fb2SpiralAmountThetaInc, 0)));
    shader_mixer.setUniform1f("fb2SpiralAmount",d_fb2SpiralAmount);
    shader_mixer.setUniform1f("fb2SpiralAngle", gui->fb2SpiralAngle + lfo(gui->fb2SpiralAngleLfoAmp, fb2SpiralAngleThetaInc, 0));
    shader_mixer.setUniform2f("fb2SpiralCenter", ofVec2f(gui->fb2SpiralX + lfo(gui->fb2SpiralXLfoAmp, fb2SpiralXThetaInc, 0),
                                                         gui->fb2SpiralY + lfo(gui->fb2SpiralYLfoAmp, fb2SpiralYThetaInc, 0)));
    
    shader_mixer.setUniform1f("fb2KaleidoscopeSegments",gui->fb2KaleidoscopeSegments + lfo(gui->fb2KaleidoscopeSegmentsLfoAmp, fb2KaleidoscopeSegmentsThetaInc, 0));
    shader_mixer.setUniform1f("fb2KaleidoscopeSlice", gui->fb2KaleidoscopeSlice + lfo(gui->fb2KaleidoscopeSliceLfoAmp, fb2KaleidoscopeSliceThetaInc, 0));
    
    
    //TEXMOD
    shader_mixer.setUniform1f("fb2LumakeyLevelTexmod", gui->fb2LumakeyLevelTexmod);
    shader_mixer.setUniform1f("fb2ChromakeyRedTexmod", gui->fb2ChromakeyRedTexmod);
    shader_mixer.setUniform1f("fb2ChromakeyGreenTexmod", gui->fb2ChromakeyGreenTexmod);
    shader_mixer.setUniform1f("fb2ChromakeyBlueTexmod", gui->fb2ChromakeyBlueTexmod);
    shader_mixer.setUniform1f("fb2KeyThresholdTexmod", gui->fb2KeyThresholdTexmod);
    shader_mixer.setUniform1f("fb2KeySoftTexmod", gui->fb2KeySoftTexmod);
    shader_mixer.setUniform1f("fb2MixTexmod", gui->fb2MixTexmod);
    
    shader_mixer.setUniform1f("fb2MaskXTexmod", gui->fb2MaskXTexmod);
    shader_mixer.setUniform1f("fb2MaskYTexmod", gui->fb2MaskYTexmod);
    shader_mixer.setUniform1f("fb2MaskZTexmod", gui->fb2MaskZTexmod);
    shader_mixer.setUniform1f("fb2MaskRotateTexmod", gui->fb2MaskRotateTexmod);
    shader_mixer.setUniform1f("fb2MaskTileAmountTexmod", gui->fb2MaskTileAmountTexmod);
    
    //fb2Color texmods
    shader_mixer.setUniform3f("fb2HsbOffsetTexmod", ofVec3f(gui->fb2HueOffsetTexmod, gui->fb2SaturationOffsetTexmod, gui->fb2BrightOffsetTexmod));
    shader_mixer.setUniform3f("fb2HsbAttenuateTexmod", ofVec3f(gui->fb2HueAttenuateTexmod, gui->fb2SaturationAttenuateTexmod, gui->fb2BrightAttenuateTexmod));
    shader_mixer.setUniform3f("fb2HsbPowMapTexmod", ofVec3f(gui->fb2HuePowMapTexmod, gui->fb2SaturationPowMapTexmod, gui->fb2BrightPowMapTexmod));
    shader_mixer.setUniform1f("fb2HueShaperTexmod",gui->fb2HueShaperTexmod);
    
    
    /*
     shader_mixer.setUniform3f("fb2ColorQuantizeTexmod", ofVec3f(gui->fb2HueQuantizeTexmod,
     gui->fb2SaturationQuantizeTexmod,
     gui->fb2BrightQuantizeTexmod));
     shader_mixer.setUniform3f("fb2ColorQuantizeMixTexmod", ofVec3f(gui->fb2HueQuantizeMixTexmod,
     gui->fb2SaturationQuantizeMixTexmod,
     gui->fb2BrightQuantizeMixTexmod));
     
     shader_mixer.setUniform3f("fb2ColorQuantizeDenomTexmod", ofVec3f(1.0f / (gui->fb2HueQuantizeTexmod),
     1.0f / (gui->fb2SaturationQuantizeTexmod),
     1.0f / (gui->fb2BrightQuantizeTexmod)));
     
     shader_mixer.setUniform1f("fb2HueDitherMixTexmod", gui->fb2HueDitherMixTexmod);
     shader_mixer.setUniform1f("fb2SaturationDitherMixTexmod", gui->fb2SaturationDitherMixTexmod);
     shader_mixer.setUniform1f("fb2BrightDitherMixTexmod", gui->fb2BrightDitherMixTexmod);
     shader_mixer.setUniform1f("fb2HueDitherAmountTexmod", gui->fb2HueDitherAmountTexmod);
     shader_mixer.setUniform1f("fb2SaturationDitherAmountTexmod", gui->fb2SaturationDitherAmountTexmod);
     shader_mixer.setUniform1f("fb2BrightDitherAmountTexmod", gui->fb2BrightDitherAmountTexmod);
     */
    
    shader_mixer.setUniform3f("fb2RescaleTexmod",ofVec3f(gui->fb2XDisplaceTexmod, gui->fb2YDisplaceTexmod, gui->fb2ZDisplaceTexmod));
    shader_mixer.setUniform1f("fb2RotateTexmod",(gui->fb2RotateTexmod));
    shader_mixer.setUniform4f("fb2ShearMatrixTexmod", fbShearC*(gui->fb2ShearMatrixTexmod) );
    
    
    shader_mixer.setUniform1f("fb2FisheyeAmountTexmod", gui->fb2FisheyeAmountTexmod );
    shader_mixer.setUniform2f("fb2FisheyeCenterTexmod",ofVec2f(gui->fb2FisheyeXTexmod ,
                                                               gui->fb2FisheyeYTexmod));
    
    float d_fb2SpiralAmountTexmod = fb2SpiralAmountC * ((gui->fb2SpiralAmountTexmod));
    shader_mixer.setUniform1f("fb2SpiralAmountTexmod",d_fb2SpiralAmountTexmod);
    shader_mixer.setUniform1f("fb2SpiralAngleTexmod", gui->fb2SpiralAngleTexmod);
    shader_mixer.setUniform2f("fb2SpiralCenterTexmod", ofVec2f(gui->fb2SpiralXTexmod,
                                                               gui->fb2SpiralYTexmod ));
    
    shader_mixer.setUniform1f("fb2KaleidoscopeSegmentsTexmod",gui->fb2KaleidoscopeSegmentsTexmod);
    shader_mixer.setUniform1f("fb2KaleidoscopeSliceTexmod", gui->fb2KaleidoscopeSliceTexmod);
    
    
    ofVec2f fb2TexmodLogic;
    if(gui->fb2TexmodSelect==0){
        fb2TexmodLogic.set(1,0);
    }
    
    if(gui->fb2TexmodSelect==1){
        fb2TexmodLogic.set(0,1);
    }
    
    shader_mixer.setUniform2f("fb2TexmodLogic",fb2TexmodLogic);
    
    //fb2 pixel
    shader_mixer.setUniform1i("fb2PixelSwitch",gui->fb2PixelSwitch);
    shader_mixer.setUniform1i("fb2XPixelScale",gui->fb2XPixelScale+lfo(gui->fb2XPixelScaleLfoAmp,fb2XPixelScaleThetaInc,0));
    shader_mixer.setUniform1i("fb2YPixelScale",gui->fb2YPixelScale+lfo(gui->fb2YPixelScaleLfoAmp,fb2YPixelScaleThetaInc,0));
    if(gui->fb2PixelXYLock==1){
        shader_mixer.setUniform1i("fb2YPixelScale", gui->fb2XPixelScale + lfo(gui->fb2XPixelScaleLfoAmp, fb2XPixelScaleThetaInc, 0));
    }
    shader_mixer.setUniform1f("fb2PixelMix", gui->fb2PixelMix + lfo(gui->fb2PixelMixLfoAmp, fb2PixelMixThetaInc, 0));
    shader_mixer.setUniform1f("fb2PixelBrightscale",gui->fb2PixelBrightscale+lfo(gui->fb2PixelBrightscaleLfoAmp,fb2PixelBrightscaleThetaInc,0));
    //fb2 texmods
    
    shader_mixer.setUniform1i("fb2XPixelScaleTexmod",gui->fb2XPixelScaleTexmod);
    shader_mixer.setUniform1i("fb2YPixelScaleTexmod",gui->fb2YPixelScaleTexmod);
    shader_mixer.setUniform1f("fb2PixelMixTexmod",gui->fb2PixelMixTexmod);
    shader_mixer.setUniform1f("fb2PixelBrightscaleTexmod",gui->fb2PixelBrightscaleTexmod);
    
    
    
    
   
    
    
    //fb3
    //fb3 variables
    //fb3Mixing
    shader_mixer.setUniform1i("fb3KeyMode", gui->fb3KeyMode);
    shader_mixer.setUniform1f("fb3LumakeyLevel", gui->fb3LumakeyLevel
                              +lfo(gui->fb3LumakeyLevelLfoAmp, fb3LumakeyLevelThetaInc, 0));
    shader_mixer.setUniform1f("fb3ChromakeyRed", gui->fb3ChromakeyRed
                              + lfo(gui->fb3ChromakeyRedLfoAmp, fb3ChromakeyRedThetaInc, 0));
    shader_mixer.setUniform1f("fb3ChromakeyGreen", gui->fb3ChromakeyGreen
                              + lfo(gui->fb3ChromakeyGreenLfoAmp, fb3ChromakeyGreenThetaInc, 0));
    shader_mixer.setUniform1f("fb3ChromakeyBlue", gui->fb3ChromakeyBlue
                              + lfo(gui->fb3ChromakeyBlueLfoAmp, fb3ChromakeyBlueThetaInc, 0));
    
    shader_mixer.setUniform1f("fb3KeyThreshold", gui->fb3KeyThreshold
                              +lfo(gui->fb3KeyThresholdLfoAmp, fb3KeyThresholdThetaInc, 0));
    shader_mixer.setUniform1f("fb3KeySoft", gui->fb3KeySoft
                              + lfo(gui->fb3KeySoftLfoAmp, fb3KeySoftThetaInc, 0));
    shader_mixer.setUniform1i("fb3KeyOrder", gui->fb3KeyOrder);
    shader_mixer.setUniform1i("fb3MixType", gui->fb3MixType);
    shader_mixer.setUniform1f("fb3Mix", gui->fb3Mix
                              +lfo(gui->fb3MixLfoAmp, fb3MixThetaInc, 0));
    shader_mixer.setUniform1i("fb3MixOverflow", gui->fb3MixOverflow);
    
    shader_mixer.setUniform1f("fb3MaskX", gui->fb3MaskX
                              + lfo(gui->fb3MaskXLfoAmp, fb3MaskXThetaInc, 0));
    shader_mixer.setUniform1f("fb3MaskY", gui->fb3MaskY
                              + lfo(gui->fb3MaskYLfoAmp, fb3MaskYThetaInc, 0));
    float fb3MaskZMapped = gui->fb3MaskZ + lfo(gui->fb3MaskZLfoAmp, fb3MaskZThetaInc, 0);
    //we want a piece wise function here
    //-1->0 or -1->1 should be fine
    //but from 1-2 we want it to go from like 1 to infinity
    
    if (fb3MaskZMapped > 1) {
        fb3MaskZMapped = pow(2,(fb3MaskZMapped-1.0f)*4.0f);
        if (gui->fb3MaskZ == 3.0) { fb3MaskZMapped = 1000; }
    }
    
    //switch statement for fb3MaskTilemode to
    //remap fb3 MaskTileAmount appropriately
    //if spiral mode selected (3) then we want it to be like
    //-3.14 to 3.14
    
    shader_mixer.setUniform1f("fb3MaskZ", fb3MaskZMapped);
    shader_mixer.setUniform1f("fb3MaskRotate", gui->fb3MaskRotate
                              + lfo(gui->fb3MaskRotateLfoAmp, fb3MaskRotateThetaInc, 0));
    shader_mixer.setUniform1f("fb3MaskTileAmount", gui->fb3MaskTileAmount
                              + lfo(gui->fb3MaskTileAmountLfoAmp, fb3MaskTileAmountThetaInc, 0));
    shader_mixer.setUniform1i("fb3MaskTileMode", gui->fb3MaskTileMode);
    shader_mixer.setUniform1i("fb3MaskTexmod",gui->fb3MaskSelect);
    
    shader_mixer.setUniform1f("fb3MaskTexmodOffset",gui->fb3MaskTexmodOffset
                              + lfo(gui->fb3MaskTexmodOffsetLfoAmp, fb3MaskTexmodOffsetThetaInc, 0));
    shader_mixer.setUniform1i("fb3MaskTexmodQuantizeAmount",gui->fb3MaskTexmodQuantizeAmount
                              + lfo(gui->fb3MaskTexmodQuantizeAmountLfoAmp, fb3MaskTexmodQuantizeAmountThetaInc, 0));
    shader_mixer.setUniform1f("fb3MaskTexmodQuantizeInvert", 1.0/(gui->fb3MaskTexmodQuantizeAmount
                                                                  + lfo(gui->fb3MaskTexmodQuantizeAmountLfoAmp, fb3MaskTexmodQuantizeAmountThetaInc, 0)));
    shader_mixer.setUniform1f("fb3MaskTexmodQuantizeMix", gui->fb3MaskTexmodQuantizeMix
                              + lfo(gui->fb3MaskTexmodQuantizeMixLfoAmp, fb3MaskTexmodQuantizeMixThetaInc, 0));
    
    //fb3Color
    hsbOffset.set(gui->fb3HueOffset + lfo(gui->fb3HueOffsetLfoAmp, fb3HueOffsetThetaInc, 0),
                  gui->fb3SaturationOffset + lfo(gui->fb3SaturationOffsetLfoAmp, fb3SaturationOffsetThetaInc, 0),
                  gui->fb3BrightOffset + lfo(gui->fb3BrightOffsetLfoAmp, fb3BrightOffsetThetaInc, 0));
    shader_mixer.setUniform3f("fb3HsbOffset",hsbOffset);
    
    hsb_x.set((gui->fb3HueAttenuate + lfo(gui->fb3HueAttenuateLfoAmp, fb3HueAttenuateThetaInc, 0))*.1f,
              (gui->fb3SaturationAttenuate + lfo(gui->fb3SaturationAttenuateLfoAmp, fb3SaturationAttenuateThetaInc, 0))*.1f ,
              (gui->fb3BrightAttenuate + lfo(gui->fb3BrightAttenuateLfoAmp, fb3BrightAttenuateThetaInc, 0))*.1f);
    shader_mixer.setUniform3f("fb3HsbAttenuate", hsb_x);
    
    shader_mixer.setUniform1f("fb3HueShaper", gui->fb3HueShaper + lfo(gui->fb3HueShaperLfoAmp, fb3HueShaperThetaInc, 0));
    
    powMap.set(gui->fb3HuePowMap + lfo(gui->fb3HuePowMapLfoAmp, fb3HuePowMapThetaInc, 0),
               gui->fb3SaturationPowMap + lfo(gui->fb3SaturationPowMapLfoAmp, fb3SaturationPowMapThetaInc, 0),
               gui->fb3BrightPowMap + lfo(gui->fb3BrightPowMapLfoAmp, fb3BrightPowMapThetaInc, 0));
    shader_mixer.setUniform3f("fb3PowMap", powMap);
    
    shader_mixer.setUniform3f("fb3ColorQuantize", ofVec3f(gui->fb3HueQuantize + lfo(gui->fb3HueQuantizeLfoAmp, fb3HueQuantizeThetaInc, 0),
                                                          gui->fb3SaturationQuantize + lfo(gui->fb3SaturationQuantizeLfoAmp, fb3SaturationQuantizeThetaInc, 0),
                                                          gui->fb3BrightQuantize + lfo(gui->fb3BrightQuantizeLfoAmp, fb3BrightQuantizeThetaInc, 0)));
    shader_mixer.setUniform3f("fb3ColorQuantizeMix", ofVec3f(gui->fb3HueQuantizeMix + lfo(gui->fb3HueQuantizeMixLfoAmp, fb3HueQuantizeMixThetaInc, 0),
                                                             gui->fb3SaturationQuantizeMix + lfo(gui->fb3SaturationQuantizeMixLfoAmp, fb3SaturationQuantizeMixThetaInc, 0),
                                                             gui->fb3BrightQuantizeMix + lfo(gui->fb3BrightQuantizeMixLfoAmp, fb3BrightQuantizeMixThetaInc, 0)));
    shader_mixer.setUniform3f("fb3ColorQuantizeDenom", ofVec3f(1.0f/(gui->fb3HueQuantize + lfo(gui->fb3HueQuantizeLfoAmp, fb3HueQuantizeThetaInc, 0)),
                                                               1.0f/(gui->fb3SaturationQuantize + lfo(gui->fb3SaturationQuantizeLfoAmp, fb3SaturationQuantizeThetaInc, 0)),
                                                               1.0f/(gui->fb3BrightQuantize + lfo(gui->fb3BrightQuantizeLfoAmp, fb3BrightQuantizeThetaInc, 0))));
    
    shader_mixer.setUniform1f("fb3HueDitherMix",gui->fb3HueDitherMix + lfo(gui->fb3HueDitherMixLfoAmp, fb3HueDitherMixThetaInc, 0));
    shader_mixer.setUniform1f("fb3SaturationDitherMix", gui->fb3SaturationDitherMix + lfo(gui->fb3SaturationDitherMixLfoAmp, fb3SaturationDitherMixThetaInc, 0));
    shader_mixer.setUniform1f("fb3BrightDitherMix", gui->fb3BrightDitherMix + lfo(gui->fb3BrightDitherMixLfoAmp, fb3BrightDitherMixThetaInc, 0));
    shader_mixer.setUniform1f("fb3HueDitherAmount", gui->fb3HueDitherAmount + lfo(gui->fb3HueDitherAmountLfoAmp, fb3HueDitherAmountThetaInc, 0));
    shader_mixer.setUniform1f("fb3SaturationDitherAmount", gui->fb3SaturationDitherAmount + lfo(gui->fb3SaturationDitherAmountLfoAmp, fb3SaturationDitherAmountThetaInc, 0));
    shader_mixer.setUniform1f("fb3BrightDitherAmount", gui->fb3BrightDitherAmount + lfo(gui->fb3BrightDitherAmountLfoAmp, fb3BrightDitherAmountThetaInc, 0));
    
    //fb3ColorSwitches
    fb_modswitch.set(gui->fb3HueInvert,gui->fb3SaturationInvert,gui->fb3BrightInvert);
    shader_mixer.setUniform3f("fb3HsbInvert",fb_modswitch);
    
    shader_mixer.setUniform1i("fb3SaturationOverflow", gui->fb3SaturationOverflow);
    shader_mixer.setUniform1i("fb3BrightOverflow", gui->fb3BrightOverflow);
    
    //fb3 Geometry
    shader_mixer.setUniform1i("fb3_toroid_switch", gui->fb3_toroid_switch);
    shader_mixer.setUniform3f("fb3_rescale",ofVec3f(gui->fb3XDisplace+lfo(gui->fb3XDisplaceLfoAmp, fb3XDisplaceThetaInc,0),
                                                    gui->fb3YDisplace+lfo(gui->fb3YDisplaceLfoAmp, fb3YDisplaceThetaInc,0),
                                                    gui->fb3ZDisplace/100.0f+lfo(gui->fb3ZDisplaceLfoAmp, fb3ZDisplaceThetaInc,0)/100.0f));
    
    shader_mixer.setUniform1f("fb3Rotate",(gui->fb3Rotate)+lfo(gui->fb3RotateLfoAmp,fb3RotateThetaInc,0));
    shader_mixer.setUniform1i("fb3RotateMode",gui->fb3RotateMode);
    
    ofVec4f d_fb3ShearMatrix;
    d_fb3ShearMatrix.set(fbShearC*(1.0f / fbShearC + gui->fb3ShearMatrix.x+ lfo(gui->fb3ShearMatrixLfoAmp.x, fb3ShearMatrixThetaInc.x, 0)),
                         fbShearC*(gui->fb3ShearMatrix.y + lfo(gui->fb3ShearMatrixLfoAmp.y, fb3ShearMatrixThetaInc.y, 0)),
                         fbShearC*(gui->fb3ShearMatrix.z + lfo(gui->fb3ShearMatrixLfoAmp.z, fb3ShearMatrixThetaInc.z, 0)),
                         fbShearC*(1.0f/fbShearC +gui->fb3ShearMatrix.w+lfo(gui->fb3ShearMatrixLfoAmp.w, fb3ShearMatrixThetaInc.w, 0))
                         );
    shader_mixer.setUniform4f("fb3ShearMatrix",d_fb3ShearMatrix);
    
    shader_mixer.setUniform1f("fb3FisheyeAmount", gui->fb3FisheyeAmount + lfo(gui->fb3FisheyeAmountLfoAmp, fb3FisheyeAmountThetaInc, 0));
    shader_mixer.setUniform2f("fb3FisheyeCenter",ofVec2f(gui->fb3FisheyeX + lfo(gui->fb3FisheyeXLfoAmp, fb3FisheyeXThetaInc, 0),
                                                         gui->fb3FisheyeY + lfo(gui->fb3FisheyeYLfoAmp, fb3FisheyeYThetaInc, 0)));
    
    float fb3SpiralAmountC = .15;
    float d_fb3SpiralAmount = fb3SpiralAmountC * (.00001f + 1.0f / fb3SpiralAmountC - (gui->fb3SpiralAmount + lfo(gui->fb3SpiralAmountLfoAmp, fb3SpiralAmountThetaInc, 0)));
    shader_mixer.setUniform1f("fb3SpiralAmount",d_fb3SpiralAmount);
    shader_mixer.setUniform1f("fb3SpiralAngle", gui->fb3SpiralAngle + lfo(gui->fb3SpiralAngleLfoAmp, fb3SpiralAngleThetaInc, 0));
    shader_mixer.setUniform2f("fb3SpiralCenter", ofVec2f(gui->fb3SpiralX + lfo(gui->fb3SpiralXLfoAmp, fb3SpiralXThetaInc, 0),
                                                         gui->fb3SpiralY + lfo(gui->fb3SpiralYLfoAmp, fb3SpiralYThetaInc, 0)));
    
    shader_mixer.setUniform1f("fb3KaleidoscopeSegments",gui->fb3KaleidoscopeSegments + lfo(gui->fb3KaleidoscopeSegmentsLfoAmp, fb3KaleidoscopeSegmentsThetaInc, 0));
    shader_mixer.setUniform1f("fb3KaleidoscopeSlice", gui->fb3KaleidoscopeSlice + lfo(gui->fb3KaleidoscopeSliceLfoAmp, fb3KaleidoscopeSliceThetaInc, 0));
    
    
    //TEXMOD
    shader_mixer.setUniform1f("fb3LumakeyLevelTexmod", gui->fb3LumakeyLevelTexmod);
    shader_mixer.setUniform1f("fb3ChromakeyRedTexmod", gui->fb3ChromakeyRedTexmod);
    shader_mixer.setUniform1f("fb3ChromakeyGreenTexmod", gui->fb3ChromakeyGreenTexmod);
    shader_mixer.setUniform1f("fb3ChromakeyBlueTexmod", gui->fb3ChromakeyBlueTexmod);
    shader_mixer.setUniform1f("fb3KeyThresholdTexmod", gui->fb3KeyThresholdTexmod);
    shader_mixer.setUniform1f("fb3KeySoftTexmod", gui->fb3KeySoftTexmod);
    shader_mixer.setUniform1f("fb3MixTexmod", gui->fb3MixTexmod);
    
    shader_mixer.setUniform1f("fb3MaskXTexmod", gui->fb3MaskXTexmod);
    shader_mixer.setUniform1f("fb3MaskYTexmod", gui->fb3MaskYTexmod);
    shader_mixer.setUniform1f("fb3MaskZTexmod", gui->fb3MaskZTexmod);
    shader_mixer.setUniform1f("fb3MaskRotateTexmod", gui->fb3MaskRotateTexmod);
    shader_mixer.setUniform1f("fb3MaskTileAmountTexmod", gui->fb3MaskTileAmountTexmod);
    
    //fb3Color texmods
    shader_mixer.setUniform3f("fb3HsbOffsetTexmod", ofVec3f(gui->fb3HueOffsetTexmod, gui->fb3SaturationOffsetTexmod, gui->fb3BrightOffsetTexmod));
    shader_mixer.setUniform3f("fb3HsbAttenuateTexmod", ofVec3f(gui->fb3HueAttenuateTexmod, gui->fb3SaturationAttenuateTexmod, gui->fb3BrightAttenuateTexmod));
    shader_mixer.setUniform3f("fb3HsbPowMapTexmod", ofVec3f(gui->fb3HuePowMapTexmod, gui->fb3SaturationPowMapTexmod, gui->fb3BrightPowMapTexmod));
    shader_mixer.setUniform1f("fb3HueShaperTexmod",gui->fb3HueShaperTexmod);
    
    
    /*
     shader_mixer.setUniform3f("fb3ColorQuantizeTexmod", ofVec3f(gui->fb3HueQuantizeTexmod,
     gui->fb3SaturationQuantizeTexmod,
     gui->fb3BrightQuantizeTexmod));
     shader_mixer.setUniform3f("fb3ColorQuantizeMixTexmod", ofVec3f(gui->fb3HueQuantizeMixTexmod,
     gui->fb3SaturationQuantizeMixTexmod,
     gui->fb3BrightQuantizeMixTexmod));
     
     shader_mixer.setUniform3f("fb3ColorQuantizeDenomTexmod", ofVec3f(1.0f / (gui->fb3HueQuantizeTexmod),
     1.0f / (gui->fb3SaturationQuantizeTexmod),
     1.0f / (gui->fb3BrightQuantizeTexmod)));
     
     shader_mixer.setUniform1f("fb3HueDitherMixTexmod", gui->fb3HueDitherMixTexmod);
     shader_mixer.setUniform1f("fb3SaturationDitherMixTexmod", gui->fb3SaturationDitherMixTexmod);
     shader_mixer.setUniform1f("fb3BrightDitherMixTexmod", gui->fb3BrightDitherMixTexmod);
     shader_mixer.setUniform1f("fb3HueDitherAmountTexmod", gui->fb3HueDitherAmountTexmod);
     shader_mixer.setUniform1f("fb3SaturationDitherAmountTexmod", gui->fb3SaturationDitherAmountTexmod);
     shader_mixer.setUniform1f("fb3BrightDitherAmountTexmod", gui->fb3BrightDitherAmountTexmod);
     */
    
    shader_mixer.setUniform3f("fb3RescaleTexmod",ofVec3f(gui->fb3XDisplaceTexmod, gui->fb3YDisplaceTexmod, gui->fb3ZDisplaceTexmod));
    shader_mixer.setUniform1f("fb3RotateTexmod",(gui->fb3RotateTexmod));
    shader_mixer.setUniform4f("fb3ShearMatrixTexmod", fbShearC*(gui->fb3ShearMatrixTexmod) );
    
    
    shader_mixer.setUniform1f("fb3FisheyeAmountTexmod", gui->fb3FisheyeAmountTexmod );
    shader_mixer.setUniform2f("fb3FisheyeCenterTexmod",ofVec2f(gui->fb3FisheyeXTexmod ,
                                                               gui->fb3FisheyeYTexmod));
    
    float d_fb3SpiralAmountTexmod = fb3SpiralAmountC * ((gui->fb3SpiralAmountTexmod));
    shader_mixer.setUniform1f("fb3SpiralAmountTexmod",d_fb3SpiralAmountTexmod);
    shader_mixer.setUniform1f("fb3SpiralAngleTexmod", gui->fb3SpiralAngleTexmod);
    shader_mixer.setUniform2f("fb3SpiralCenterTexmod", ofVec2f(gui->fb3SpiralXTexmod,
                                                               gui->fb3SpiralYTexmod ));
    
    shader_mixer.setUniform1f("fb3KaleidoscopeSegmentsTexmod",gui->fb3KaleidoscopeSegmentsTexmod);
    shader_mixer.setUniform1f("fb3KaleidoscopeSliceTexmod", gui->fb3KaleidoscopeSliceTexmod);
    
    
    ofVec2f fb3TexmodLogic;
    if(gui->fb3TexmodSelect==0){
        fb3TexmodLogic.set(1,0);
    }
    
    if(gui->fb3TexmodSelect==1){
        fb3TexmodLogic.set(0,1);
    }
    
    shader_mixer.setUniform2f("fb3TexmodLogic",fb3TexmodLogic);
    
    //fb3 pixel
    shader_mixer.setUniform1i("fb3PixelSwitch",gui->fb3PixelSwitch);
    shader_mixer.setUniform1i("fb3XPixelScale",gui->fb3XPixelScale+lfo(gui->fb3XPixelScaleLfoAmp,fb3XPixelScaleThetaInc,0));
    shader_mixer.setUniform1i("fb3YPixelScale",gui->fb3YPixelScale+lfo(gui->fb3YPixelScaleLfoAmp,fb3YPixelScaleThetaInc,0));
    if(gui->fb3PixelXYLock==1){
        shader_mixer.setUniform1i("fb3YPixelScale", gui->fb3XPixelScale + lfo(gui->fb3XPixelScaleLfoAmp, fb3XPixelScaleThetaInc, 0));
    }
    shader_mixer.setUniform1f("fb3PixelMix", gui->fb3PixelMix + lfo(gui->fb3PixelMixLfoAmp, fb3PixelMixThetaInc, 0));
    shader_mixer.setUniform1f("fb3PixelBrightscale",gui->fb3PixelBrightscale+lfo(gui->fb3PixelBrightscaleLfoAmp,fb3PixelBrightscaleThetaInc,0));
    //fb3 texmods
    
    shader_mixer.setUniform1i("fb3XPixelScaleTexmod",gui->fb3XPixelScaleTexmod);
    shader_mixer.setUniform1i("fb3YPixelScaleTexmod",gui->fb3YPixelScaleTexmod);
    shader_mixer.setUniform1f("fb3PixelMixTexmod",gui->fb3PixelMixTexmod);
    shader_mixer.setUniform1f("fb3PixelBrightscaleTexmod",gui->fb3PixelBrightscaleTexmod);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    shader_mixer.setUniform1f("ee",ee);
    
    
    //here is where controls from the gui get shunted
    
    //for now channel 1 and 2 can only b cam1 or cam2 input
    shader_mixer.setUniform1i("channel1", gui->channel1_select);
    shader_mixer.setUniform1i("channel2", gui->channel2_select);
    shader_mixer.setUniform1i("mix1", 2);//gui->mix1);
    //shader_mixer.setUniform1i("mix2", gui->mix2);
    
    
    //h and v flip controls
    //no shader_mixer.setUniform1i("ch1_h_mirror", gui->ch1_h_mirror);
    
    
    //channel1 controls from the gui
    //vector these up
    ///asuming these will all stay
    
    //ch1
    //vectorize all this


    //h and v flips
    

    shader_mixer.setUniform1i("fb0HorizontalMirror", gui->fb0HorizontalMirror);
    shader_mixer.setUniform1i("fb0VerticalMirror", gui->fb0VerticalMirror);
    shader_mixer.setUniform1i("fb1HorizontalMirror", gui->fb1HorizontalMirror);
    shader_mixer.setUniform1i("fb1VerticalMirror", gui->fb1VerticalMirror);
    shader_mixer.setUniform1i("fb2HorizontalMirror", gui->fb2HorizontalMirror);
    shader_mixer.setUniform1i("fb2VerticalMirror", gui->fb2VerticalMirror);
    shader_mixer.setUniform1i("fb3HorizontalMirror", gui->fb3HorizontalMirror);
    shader_mixer.setUniform1i("fb3VerticalMirror", gui->fb3VerticalMirror);

    shader_mixer.end();
    
    if(gui->hypercube_switch==1){
        hypercube_draw();
    }
    
    if(gui->tetrahedron_switch==1){
        
        ofSetColor(127+127*(sin(ofGetElapsedTimef())),127+127*(cos(ofGetElapsedTimef()/7)),127-127*(sin(ofGetElapsedTimef()/19)),255);
        ofNoFill();
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
        ofRotateZRad(ofGetElapsedTimef()/5);
        ofRotateYRad(ofGetElapsedTimef()/13);
        ofRotateXRad(ofGetElapsedTimef()/11);
        tetrahedron.draw();

        ofPopMatrix();
    }
    
    //seven star thing
	//sevenStar1Draw();
    
    
    
    fbo_draw.end();
    
    //--_-__--___-_--_------_---------____
    
    fbo_blur.begin();
    shader_blur.begin();
    fbo_draw.draw(0,0);
    
    if(gui->global_texmod_select==0){
        shader_blur.setUniformTexture("texmod",cam1.getTexture(),8);
    }
    if(gui->global_texmod_select==1){
        shader_blur.setUniformTexture("texmod",cam2.getTexture(),8);
    }
    if(gui->global_texmod_select==2){
        shader_blur.setUniformTexture("texmod",ndi_fbo.getTexture(),8);
    }
    
    shader_blur.setUniform1f("blur_amount",gui->blur_amount + c4*10+lfo(gui->blur_amount_lfo_amp,blur_theta_amount,0));//+5*(midi_controls[25]+1)/2);
    shader_blur.setUniform1f("blur_radius",gui->blur_radius+lfo(gui->blur_radius_lfo_amp,blur_theta_radius,0));
    shader_blur.setUniform1f("texmod_blur_amount",gui->texmod_blur_amount);
    shader_blur.setUniform1f("texmod_blur_radius",gui->texmod_blur_radius);
    shader_blur.end();
    fbo_blur.end();
    
   
    
    //sharpen back in the draw fbo
    fbo_draw.begin();
    
    shader_sharpen.begin();
    fbo_blur.draw(0,0);
    
    
    if(gui->global_texmod_select==0){
        shader_sharpen.setUniformTexture("texmod",cam1.getTexture(),9);
    }
    if(gui->global_texmod_select==1){
        shader_sharpen.setUniformTexture("texmod",cam2.getTexture(),9);
    }
    if(gui->global_texmod_select==2){
        shader_sharpen.setUniformTexture("texmod",ndi_fbo.getTexture(),9);
    }
    
    shader_sharpen.setUniform1f("texmod_sharpen_amount",gui->texmod_sharpen_amount+lfo(gui->sharpen_amount_lfo_amp,sharpen_theta_amount,0));
    shader_sharpen.setUniform1f("texmod_sharpen_radius",gui->texmod_sharpen_radius+lfo(gui->sharpen_radius_lfo_amp,sharpen_theta_radius,0));
    shader_sharpen.setUniform1f("texmod_sharpen_boost",gui->texmod_sharpen_boost+lfo(gui->sharpen_boost_lfo_amp,sharpen_theta_boost,0));
    
    
    //lets change sharpAMNT to be larger?
    shader_sharpen.setUniform1f("sharpen_amount",gui->sharpen_amount+c5*.3);//+.3*(midi_controls[24]+1.0)/2.0);
    shader_sharpen.setUniform1f("sharpen_radius",gui->sharpen_radius);
    shader_sharpen.setUniform1f("sharpen_boost",gui->sharpen_boost+c5);
    shader_sharpen.setUniform1f("qq",qq);
    shader_sharpen.end();
   
    
    //fbo_blur.draw(0,0);
    
    fbo_draw.end();
    
    //___--_------___-_-_______-----___-
    
    /*this part gets drawn to screen*/
    
    fbo_draw.draw(0,0);
    
	//videoPlayer1.draw(0, 0);

    //ndi_fbo.draw(0,0);
    //___--_------___-_-_______-----___-
    
    //pass the frame back into the delay
    pastFrames[abs(fbob-framedelayoffset)-1].begin(); //eeettt

    ofPushMatrix();
    //recenter the coordinates so 0,0 is at the center of the screen
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2,0);
    ofTranslate(ff,gg,hh);
    ofRotateYRad(ss+gui->y_skew);
    ofRotateXRad(aa+gui->x_skew);
    ofRotateZRad(dd);
    ofRotateZRad(oo*TWO_PI/ii);
    fbo_draw.draw(-ofGetWidth()/2,-ofGetHeight()/2);
    ofPopMatrix();
    
    pastFrames[abs(fbob-framedelayoffset)-1].end(); //eeettt


	/*
	pastFrames2[abs(fbob - framedelayoffset) - 1].begin(); //eeettt

	ofPushMatrix();
	//recenter the coordinates so 0,0 is at the center of the screen
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	ofTranslate(ff, gg, hh);
	ofRotateYRad(ss + gui->y_skew);
	ofRotateXRad(aa + gui->x_skew);
	ofRotateZRad(dd);
	ofRotateZRad(oo*TWO_PI / ii);
	fbo_draw.draw(-ofGetWidth() / 2, -ofGetHeight() / 2);
	ofPopMatrix();

	pastFrames2[abs(fbob - framedelayoffset) - 1].end(); //eeettt
    */
    //-----____---____---__-__---____-----_--_-
    

    ofSetHexColor(0xFFFFFF);
  //  ofDrawBitmapString(" delayhead: "+ofToString(delayhead),10, ofGetHeight()-5 );
   
 
    
    
    incIndex(); // increment framecount and framedelayoffset eeettt
}
//---------------------------------------------------------
void ofApp::sevenStar1Setup() {
	//how to auto generate coordinates for n division of circumference of unit circle
	for (int i = 0; i < reps; i++) {
		float theta = float(i)*2.0f*PI / float(reps);
		points[i].set(cos(theta), sin(theta));
	}
	int starIncrementer = 0;
	for (int i = 0; i < reps1; i++) {
		points1[i].set(ofGetHeight() / 4.0f*points[starIncrementer]);
		starIncrementer = (starIncrementer + 3) % reps;
	}
	//second odd star styling
	starIncrementer = 0;
	for (int i = 0; i < reps; i++) {
		points2[i].set(ofGetHeight() / 4.0f*points[starIncrementer]);
		starIncrementer = (starIncrementer + 2) % reps;
	}
	position1 = points1[0];
	position2 = points2[0];
}
//------------------------------------------------------
void ofApp::sevenStar1Draw() {

	thetaHue1 += hueInc1;
	thetaHue2 += hueInc2;
	thetaSaturation1 += saturationInc1;
	thetaChaos += .000125*(thetaHue1*(sin(thetaHue2*.00001)) + thetaHue2 * (sin(thetaHue1*.00001)));

	float squareSize = ofGetWidth() / 64;

	ofPushMatrix();

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	position1.x = ofLerp(position1.x, points1[index1].x, increment1);
	position1.y = ofLerp(position1.y, points1[index1].y, increment1);
	//this is kinda neat in that it seems to create a bit of a sense of depth
	//could be pretty cool to have for odd stars 2 or more different paths like this that are moving in different orders over one another??
	float shapedX = position1.x;
	float shapedY = position1.y;
	//probably cool thing to do here with 'shaping' would be to work with beziers, arcs, splines etc
	//and then lerp between the two different paths with some kind of oscillator

	ofColor hsbC1;
	hsbC1.setHsb(127 + 63 * sin(thetaHue1 + thetaChaos) + 63 * cos(thetaHue2 - thetaChaos), 190 + 63 * cos(thetaSaturation1), 255);
	ofSetColor(hsbC1);
	ofDrawEllipse(shapedX, shapedY, squareSize, squareSize);
	ofSetColor(0);
	ofDrawEllipse(shapedX, shapedY, squareSize - 2, squareSize - 2);

	if (position1 != points1[index1]) {
		increment1 += acceleration1;
	}
	if (position1.distance(points1[index1]) < threshold) {
		index1++;
		index1 = index1 % reps1;
		increment1 = 0;
	}

	position2.x = ofLerp(position2.x, points2[index2].x, increment2);
	position2.y = ofLerp(position2.y, points2[index2].y, increment2);

	hsbC1.setHsb(127 + 63 * sin(thetaHue2 + thetaChaos) - 63 * cos(thetaHue1 - thetaChaos), 190 + 63 * cos(thetaSaturation1 - thetaHue1), 255);
	ofSetColor(hsbC1);
	ofDrawEllipse(position2.x, position2.y, squareSize, squareSize);
	ofSetColor(0);
	ofDrawEllipse(position2.x, position2.y, squareSize - 2, squareSize - 2);

	if (position2 != points2[index2]) {
		increment2 += acceleration2;
	}
	if (position2.distance(points2[index2]) < threshold) {
		index2++;
		index2 = index2 % reps;
		increment2 = 0;
	}

	ofPopMatrix();

}

//-------------------------------------------------------

float ofApp::lfo(float amp, float rate,int shape){
    
    return amp*sin(rate);
}


//_____----_-_-_-______---__---_--_----____--_-__-_-

void ofApp::NDI_reciever_setup(string reciever_name){
    auto findSource = [](const string &name_or_url) {
        auto sources = ofxNDI::listSources();
        if(name_or_url == "") {
            return make_pair(ofxNDI::Source(), false);
        }
        auto found = find_if(begin(sources), end(sources), [name_or_url](const ofxNDI::Source &s) {
            return ofIsStringInString(s.p_ndi_name, name_or_url) || ofIsStringInString(s.p_url_address, name_or_url);
        });
        if(found == end(sources)) {
            ofLogWarning("ofxNDI") << "no NDI source found by string:" << name_or_url;
            return make_pair(ofxNDI::Source(), false);
        }
        return make_pair(*found, true);
    };
    string name_or_url = "";//reciever_name;    // Specify name or address of expected NDI source. In case of blank or not found, receiver will grab default(which is found first) source.
    auto result = findSource(name_or_url);
    if(result.second ? ndi_receiver_.setup(result.first) : ndi_receiver_.setup()) {
        ndi_video_.setup(ndi_receiver_);
    }
    
}
//-------------------------

void ofApp::NDI_reciever_update(){
    if(ndi_receiver_.isConnected()) {
        ndi_video_.update();
        if(ndi_video_.isFrameNew()) {
            ndi_video_.decodeTo(ndi_pixels);
        }
    }
    ndi_fbo.begin();
    if(ndi_pixels.isAllocated()) {
        //ofImage ndi_image;
        ofPushMatrix();
        ofTranslate(ndi_fbo.getWidth()/2,ndi_fbo.getHeight()/2);
        ofTranslate(0,0,gui->ndi_scale);
        ofImage(ndi_pixels).draw(-ofImage(ndi_pixels).getWidth()/2,-ofImage(ndi_pixels).getHeight()/2);
        //ofImage(ndi_pixels).draw(0,0);
        ofPopMatrix();
    }
    ndi_fbo.end();
    
    
    
}

//------------------------------------------------

void ofApp::NDI_sender_setup(string app_name){
    
    if(sender_.setup(app_name)) {
        ndi_send_video_.setup(sender_);
        ndi_send_video_.setAsync(true);
    }
    
}

//----

void ofApp:: NDI_sender_update(){
    ofPixels fbo_pixels;
    fbo_draw.readToPixels(fbo_pixels);
    ndi_send_video_.send(fbo_pixels);//getPixels());
}

//- ---

void ofApp::lfo_update(){
    
    //ch1 adjust
	ch1ScaleThetaInc += .01*(gui->ch1ScaleLfoTheta);
    ch1HueThetaInc+=.01*(gui->ch1HsbAttenuateLfoTheta.x);
    ch1SaturationThetaInc+=.01*(gui->ch1HsbAttenuateLfoTheta.y);
    ch1BrightThetaInc+=.01*(gui->ch1HsbAttenuateLfoTheta.z);
	//ch1QuantizeThetaInc += .01*(gui->ch1QuantizeLfoTheta);

	//ch1 pixel
	ch1XPixelScaleThetaInc += .01*(gui->ch1XPixelScaleLfoTheta);
	ch1YPixelScaleThetaInc += .01*(gui->ch1YPixelScaleLfoTheta);
	ch1PixelMixThetaInc += .01*(gui->ch1PixelMixLfoTheta);
	ch1PixelBrightscaleThetaInc += .01*(gui->ch1PixelBrightscaleLfoTheta);
    
	//ch2 adjust
	ch2ScaleThetaInc += .01*(gui->ch2ScaleLfoTheta);
	ch2HueThetaInc += .01*(gui->ch2HsbAttenuateLfoTheta.x);
	ch2SaturationThetaInc += .01*(gui->ch2HsbAttenuateLfoTheta.y);
	ch2BrightThetaInc += .01*(gui->ch2HsbAttenuateLfoTheta.z);
	//ch2QuantizeThetaInc += .01*(gui->ch2QuantizeLfoTheta);

	//ch2 pixel
	ch2XPixelScaleThetaInc += .01*(gui->ch2XPixelScaleLfoTheta);
	ch2YPixelScaleThetaInc += .01*(gui->ch2YPixelScaleLfoTheta);
	ch2PixelMixThetaInc += .01*(gui->ch2PixelMixLfoTheta);
	ch2PixelBrightscaleThetaInc += .01*(gui->ch2PixelBrightscaleLfoTheta);

    
    
    //fb0 lfos
	fb0DelayThetaInc += .01*(gui->fb0_delay_lfo_theta);

	//fb0mix and key
    fb0MixThetaInc+=.01*(gui->fb0MixLfoTheta);
    fb0LumakeyLevelThetaInc+=.01*(gui->fb0LumakeyLevelLfoTheta);
	fb0ChromakeyRedThetaInc += .01*(gui->fb0ChromakeyRedLfoTheta);
	fb0ChromakeyGreenThetaInc += .01*(gui->fb0ChromakeyGreenLfoTheta);
	fb0ChromakeyBlueThetaInc += .01*(gui->fb0ChromakeyBlueLfoTheta);
    fb0KeyThresholdThetaInc+=.01*(gui->fb0KeyThresholdLfoTheta);
	fb0KeySoftThetaInc += .01*(gui->fb0KeySoftLfoTheta);
	fb0MaskXThetaInc += 0.01*(gui->fb0MaskXLfoTheta);
	fb0MaskYThetaInc += 0.01*(gui->fb0MaskYLfoTheta);
	fb0MaskZThetaInc += 0.01*(gui->fb0MaskZLfoTheta);
	fb0MaskRotateThetaInc += 0.01*(gui->fb0MaskRotateLfoTheta);
	fb0MaskTileAmountThetaInc += 0.01*(gui->fb0MaskTileAmountLfoTheta);
	fb0MaskTexmodOffsetThetaInc += 0.01*(gui->fb0MaskTexmodOffsetLfoTheta);
	fb0MaskTexmodQuantizeAmountThetaInc += 0.01*(gui->fb0MaskTexmodQuantizeAmountLfoTheta);
	fb0MaskTexmodQuantizeMixThetaInc += 0.01*(gui->fb0MaskTexmodQuantizeMixLfoTheta);
    
	//fb0 color
	fb0HueOffsetThetaInc +=0.01*(gui->fb0HueOffsetLfoTheta);
	fb0SaturationOffsetThetaInc +=0.01*(gui->fb0SaturationOffsetLfoTheta);
	fb0BrightOffsetThetaInc +=0.01*(gui->fb0BrightOffsetLfoTheta);
	fb0HueAttenuateThetaInc +=0.01*(gui->fb0HueAttenuateLfoTheta);
	fb0SaturationAttenuateThetaInc +=0.01*(gui->fb0SaturationAttenuateLfoTheta);
	fb0BrightAttenuateThetaInc +=0.01*(gui->fb0BrightAttenuateLfoTheta);
	fb0HueShaperThetaInc +=0.01*(gui->fb0HueShaperLfoTheta);
	fb0HuePowMapThetaInc += .01*(gui->fb0HuePowMapLfoTheta);
	fb0SaturationPowMapThetaInc += .01*(gui->fb0SaturationPowMapLfoTheta);
	fb0BrightPowMapThetaInc += .01*(gui->fb0BrightPowMapLfoTheta);

	fb0HueQuantizeThetaInc += 0.01*(gui->fb0HueQuantizeLfoTheta);
	fb0SaturationQuantizeThetaInc += 0.01*(gui->fb0SaturationQuantizeLfoTheta);
	fb0BrightQuantizeThetaInc += 0.01*(gui->fb0BrightQuantizeLfoTheta);
	fb0HueQuantizeMixThetaInc += 0.01*(gui->fb0HueQuantizeMixLfoTheta);
	fb0SaturationQuantizeMixThetaInc += 0.01*(gui->fb0SaturationQuantizeMixLfoTheta);
	fb0BrightQuantizeMixThetaInc += 0.01*(gui->fb0BrightQuantizeMixLfoTheta);

	fb0HueDitherAmountThetaInc += 0.01*(gui->fb0HueDitherAmountLfoTheta);
	fb0SaturationDitherAmountThetaInc += 0.01*(gui->fb0SaturationDitherAmountLfoTheta);
	fb0BrightDitherAmountThetaInc += 0.01*(gui->fb0BrightDitherAmountLfoTheta);
	fb0HueDitherMixThetaInc += 0.01*(gui->fb0HueDitherMixLfoTheta);
	fb0SaturationDitherMixThetaInc += 0.01*(gui->fb0SaturationDitherMixLfoTheta);
	fb0BrightDitherMixThetaInc += 0.01*(gui->fb0BrightDitherMixLfoTheta);

    //fb0 geo
    fb0XDisplaceThetaInc+=.01*(gui->fb0XDisplaceLfoTheta);
    fb0YDisplaceThetaInc+=.01*(gui->fb0YDisplaceLfoTheta);
    fb0ZDisplaceThetaInc+=.01*(gui->fb0ZDisplaceLfoTheta);
    fb0RotateThetaInc+=.01*(gui->fb0RotateLfoTheta);
	fb0ShearMatrixThetaInc.x+= .01*(gui->fb0ShearMatrixLfoTheta.x);
	fb0ShearMatrixThetaInc.y += .01*(gui->fb0ShearMatrixLfoTheta.y);
	fb0ShearMatrixThetaInc.z += .01*(gui->fb0ShearMatrixLfoTheta.z);
	fb0ShearMatrixThetaInc.w += .01*(gui->fb0ShearMatrixLfoTheta.w);

	fb0FisheyeAmountThetaInc += .01*(gui->fb0FisheyeAmountLfoTheta);
	fb0FisheyeXThetaInc += .01*(gui->fb0FisheyeXLfoTheta);
	fb0FisheyeYThetaInc += .01*(gui->fb0FisheyeYLfoTheta);
	fb0SpiralAmountThetaInc += .01*(gui->fb0SpiralAmountLfoTheta);
	fb0SpiralAngleThetaInc += .01*(gui->fb0SpiralAngleLfoTheta);
	fb0SpiralXThetaInc += .01*(gui->fb0SpiralXLfoTheta);
	fb0SpiralYThetaInc += .01*(gui->fb0SpiralYLfoTheta);
	fb0KaleidoscopeSegmentsThetaInc += .01*(gui->fb0KaleidoscopeSegmentsLfoTheta);
	fb0KaleidoscopeSliceThetaInc += .01*(gui->fb0KaleidoscopeSliceLfoTheta);
    
    //fb0 pixel lfo
    fb0XPixelScaleThetaInc+=.01*(gui->fb0XPixelScaleLfoTheta);
    fb0YPixelScaleThetaInc+=.01*(gui->fb0YPixelScaleLfoTheta);
    fb0PixelMixThetaInc+=.01*(gui->fb0PixelMixLfoTheta);
    fb0PixelBrightscaleThetaInc+=.01*(gui->fb0PixelBrightscaleLfoTheta);
    
    
    
    
    
    
    
    
    
    
    //fb1 lfos
    fb1DelayThetaInc += .01*(gui->fb1_delay_lfo_theta);
    
    //fb1mix and key
    fb1MixThetaInc+=.01*(gui->fb1MixLfoTheta);
    fb1LumakeyLevelThetaInc+=.01*(gui->fb1LumakeyLevelLfoTheta);
    fb1ChromakeyRedThetaInc += .01*(gui->fb1ChromakeyRedLfoTheta);
    fb1ChromakeyGreenThetaInc += .01*(gui->fb1ChromakeyGreenLfoTheta);
    fb1ChromakeyBlueThetaInc += .01*(gui->fb1ChromakeyBlueLfoTheta);
    fb1KeyThresholdThetaInc+=.01*(gui->fb1KeyThresholdLfoTheta);
    fb1KeySoftThetaInc += .01*(gui->fb1KeySoftLfoTheta);
    fb1MaskXThetaInc += 0.01*(gui->fb1MaskXLfoTheta);
    fb1MaskYThetaInc += 0.01*(gui->fb1MaskYLfoTheta);
    fb1MaskZThetaInc += 0.01*(gui->fb1MaskZLfoTheta);
    fb1MaskRotateThetaInc += 0.01*(gui->fb1MaskRotateLfoTheta);
    fb1MaskTileAmountThetaInc += 0.01*(gui->fb1MaskTileAmountLfoTheta);
    fb1MaskTexmodOffsetThetaInc += 0.01*(gui->fb1MaskTexmodOffsetLfoTheta);
    fb1MaskTexmodQuantizeAmountThetaInc += 0.01*(gui->fb1MaskTexmodQuantizeAmountLfoTheta);
    fb1MaskTexmodQuantizeMixThetaInc += 0.01*(gui->fb1MaskTexmodQuantizeMixLfoTheta);
    
    //fb1 color
    fb1HueOffsetThetaInc +=0.01*(gui->fb1HueOffsetLfoTheta);
    fb1SaturationOffsetThetaInc +=0.01*(gui->fb1SaturationOffsetLfoTheta);
    fb1BrightOffsetThetaInc +=0.01*(gui->fb1BrightOffsetLfoTheta);
    fb1HueAttenuateThetaInc +=0.01*(gui->fb1HueAttenuateLfoTheta);
    fb1SaturationAttenuateThetaInc +=0.01*(gui->fb1SaturationAttenuateLfoTheta);
    fb1BrightAttenuateThetaInc +=0.01*(gui->fb1BrightAttenuateLfoTheta);
    fb1HueShaperThetaInc +=0.01*(gui->fb1HueShaperLfoTheta);
    fb1HuePowMapThetaInc += .01*(gui->fb1HuePowMapLfoTheta);
    fb1SaturationPowMapThetaInc += .01*(gui->fb1SaturationPowMapLfoTheta);
    fb1BrightPowMapThetaInc += .01*(gui->fb1BrightPowMapLfoTheta);
    
    fb1HueQuantizeThetaInc += 0.01*(gui->fb1HueQuantizeLfoTheta);
    fb1SaturationQuantizeThetaInc += 0.01*(gui->fb1SaturationQuantizeLfoTheta);
    fb1BrightQuantizeThetaInc += 0.01*(gui->fb1BrightQuantizeLfoTheta);
    fb1HueQuantizeMixThetaInc += 0.01*(gui->fb1HueQuantizeMixLfoTheta);
    fb1SaturationQuantizeMixThetaInc += 0.01*(gui->fb1SaturationQuantizeMixLfoTheta);
    fb1BrightQuantizeMixThetaInc += 0.01*(gui->fb1BrightQuantizeMixLfoTheta);
    
    fb1HueDitherAmountThetaInc += 0.01*(gui->fb1HueDitherAmountLfoTheta);
    fb1SaturationDitherAmountThetaInc += 0.01*(gui->fb1SaturationDitherAmountLfoTheta);
    fb1BrightDitherAmountThetaInc += 0.01*(gui->fb1BrightDitherAmountLfoTheta);
    fb1HueDitherMixThetaInc += 0.01*(gui->fb1HueDitherMixLfoTheta);
    fb1SaturationDitherMixThetaInc += 0.01*(gui->fb1SaturationDitherMixLfoTheta);
    fb1BrightDitherMixThetaInc += 0.01*(gui->fb1BrightDitherMixLfoTheta);
    
    //fb1 geo
    fb1XDisplaceThetaInc+=.01*(gui->fb1XDisplaceLfoTheta);
    fb1YDisplaceThetaInc+=.01*(gui->fb1YDisplaceLfoTheta);
    fb1ZDisplaceThetaInc+=.01*(gui->fb1ZDisplaceLfoTheta);
    fb1RotateThetaInc+=.01*(gui->fb1RotateLfoTheta);
    fb1ShearMatrixThetaInc.x+= .01*(gui->fb1ShearMatrixLfoTheta.x);
    fb1ShearMatrixThetaInc.y += .01*(gui->fb1ShearMatrixLfoTheta.y);
    fb1ShearMatrixThetaInc.z += .01*(gui->fb1ShearMatrixLfoTheta.z);
    fb1ShearMatrixThetaInc.w += .01*(gui->fb1ShearMatrixLfoTheta.w);
    
    fb1FisheyeAmountThetaInc += .01*(gui->fb1FisheyeAmountLfoTheta);
    fb1FisheyeXThetaInc += .01*(gui->fb1FisheyeXLfoTheta);
    fb1FisheyeYThetaInc += .01*(gui->fb1FisheyeYLfoTheta);
    fb1SpiralAmountThetaInc += .01*(gui->fb1SpiralAmountLfoTheta);
    fb1SpiralAngleThetaInc += .01*(gui->fb1SpiralAngleLfoTheta);
    fb1SpiralXThetaInc += .01*(gui->fb1SpiralXLfoTheta);
    fb1SpiralYThetaInc += .01*(gui->fb1SpiralYLfoTheta);
    fb1KaleidoscopeSegmentsThetaInc += .01*(gui->fb1KaleidoscopeSegmentsLfoTheta);
    fb1KaleidoscopeSliceThetaInc += .01*(gui->fb1KaleidoscopeSliceLfoTheta);
    
    //fb1 pixel lfo
    fb1XPixelScaleThetaInc+=.01*(gui->fb1XPixelScaleLfoTheta);
    fb1YPixelScaleThetaInc+=.01*(gui->fb1YPixelScaleLfoTheta);
    fb1PixelMixThetaInc+=.01*(gui->fb1PixelMixLfoTheta);
    fb1PixelBrightscaleThetaInc+=.01*(gui->fb1PixelBrightscaleLfoTheta);
    
    
    
    
    
    
    
    
    
    
    //fb2 lfos
    //fb2 lfos
    fb2DelayThetaInc += .01*(gui->fb2_delay_lfo_theta);
    
    //fb2mix and key
    fb2MixThetaInc+=.01*(gui->fb2MixLfoTheta);
    fb2LumakeyLevelThetaInc+=.01*(gui->fb2LumakeyLevelLfoTheta);
    fb2ChromakeyRedThetaInc += .01*(gui->fb2ChromakeyRedLfoTheta);
    fb2ChromakeyGreenThetaInc += .01*(gui->fb2ChromakeyGreenLfoTheta);
    fb2ChromakeyBlueThetaInc += .01*(gui->fb2ChromakeyBlueLfoTheta);
    fb2KeyThresholdThetaInc+=.01*(gui->fb2KeyThresholdLfoTheta);
    fb2KeySoftThetaInc += .01*(gui->fb2KeySoftLfoTheta);
    fb2MaskXThetaInc += 0.01*(gui->fb2MaskXLfoTheta);
    fb2MaskYThetaInc += 0.01*(gui->fb2MaskYLfoTheta);
    fb2MaskZThetaInc += 0.01*(gui->fb2MaskZLfoTheta);
    fb2MaskRotateThetaInc += 0.01*(gui->fb2MaskRotateLfoTheta);
    fb2MaskTileAmountThetaInc += 0.01*(gui->fb2MaskTileAmountLfoTheta);
    fb2MaskTexmodOffsetThetaInc += 0.01*(gui->fb2MaskTexmodOffsetLfoTheta);
    fb2MaskTexmodQuantizeAmountThetaInc += 0.01*(gui->fb2MaskTexmodQuantizeAmountLfoTheta);
    fb2MaskTexmodQuantizeMixThetaInc += 0.01*(gui->fb2MaskTexmodQuantizeMixLfoTheta);
    
    //fb2 color
    fb2HueOffsetThetaInc +=0.01*(gui->fb2HueOffsetLfoTheta);
    fb2SaturationOffsetThetaInc +=0.01*(gui->fb2SaturationOffsetLfoTheta);
    fb2BrightOffsetThetaInc +=0.01*(gui->fb2BrightOffsetLfoTheta);
    fb2HueAttenuateThetaInc +=0.01*(gui->fb2HueAttenuateLfoTheta);
    fb2SaturationAttenuateThetaInc +=0.01*(gui->fb2SaturationAttenuateLfoTheta);
    fb2BrightAttenuateThetaInc +=0.01*(gui->fb2BrightAttenuateLfoTheta);
    fb2HueShaperThetaInc +=0.01*(gui->fb2HueShaperLfoTheta);
    fb2HuePowMapThetaInc += .01*(gui->fb2HuePowMapLfoTheta);
    fb2SaturationPowMapThetaInc += .01*(gui->fb2SaturationPowMapLfoTheta);
    fb2BrightPowMapThetaInc += .01*(gui->fb2BrightPowMapLfoTheta);
    
    fb2HueQuantizeThetaInc += 0.01*(gui->fb2HueQuantizeLfoTheta);
    fb2SaturationQuantizeThetaInc += 0.01*(gui->fb2SaturationQuantizeLfoTheta);
    fb2BrightQuantizeThetaInc += 0.01*(gui->fb2BrightQuantizeLfoTheta);
    fb2HueQuantizeMixThetaInc += 0.01*(gui->fb2HueQuantizeMixLfoTheta);
    fb2SaturationQuantizeMixThetaInc += 0.01*(gui->fb2SaturationQuantizeMixLfoTheta);
    fb2BrightQuantizeMixThetaInc += 0.01*(gui->fb2BrightQuantizeMixLfoTheta);
    
    fb2HueDitherAmountThetaInc += 0.01*(gui->fb2HueDitherAmountLfoTheta);
    fb2SaturationDitherAmountThetaInc += 0.01*(gui->fb2SaturationDitherAmountLfoTheta);
    fb2BrightDitherAmountThetaInc += 0.01*(gui->fb2BrightDitherAmountLfoTheta);
    fb2HueDitherMixThetaInc += 0.01*(gui->fb2HueDitherMixLfoTheta);
    fb2SaturationDitherMixThetaInc += 0.01*(gui->fb2SaturationDitherMixLfoTheta);
    fb2BrightDitherMixThetaInc += 0.01*(gui->fb2BrightDitherMixLfoTheta);
    
    //fb2 geo
    fb2XDisplaceThetaInc+=.01*(gui->fb2XDisplaceLfoTheta);
    fb2YDisplaceThetaInc+=.01*(gui->fb2YDisplaceLfoTheta);
    fb2ZDisplaceThetaInc+=.01*(gui->fb2ZDisplaceLfoTheta);
    fb2RotateThetaInc+=.01*(gui->fb2RotateLfoTheta);
    fb2ShearMatrixThetaInc.x+= .01*(gui->fb2ShearMatrixLfoTheta.x);
    fb2ShearMatrixThetaInc.y += .01*(gui->fb2ShearMatrixLfoTheta.y);
    fb2ShearMatrixThetaInc.z += .01*(gui->fb2ShearMatrixLfoTheta.z);
    fb2ShearMatrixThetaInc.w += .01*(gui->fb2ShearMatrixLfoTheta.w);
    
    fb2FisheyeAmountThetaInc += .01*(gui->fb2FisheyeAmountLfoTheta);
    fb2FisheyeXThetaInc += .01*(gui->fb2FisheyeXLfoTheta);
    fb2FisheyeYThetaInc += .01*(gui->fb2FisheyeYLfoTheta);
    fb2SpiralAmountThetaInc += .01*(gui->fb2SpiralAmountLfoTheta);
    fb2SpiralAngleThetaInc += .01*(gui->fb2SpiralAngleLfoTheta);
    fb2SpiralXThetaInc += .01*(gui->fb2SpiralXLfoTheta);
    fb2SpiralYThetaInc += .01*(gui->fb2SpiralYLfoTheta);
    fb2KaleidoscopeSegmentsThetaInc += .01*(gui->fb2KaleidoscopeSegmentsLfoTheta);
    fb2KaleidoscopeSliceThetaInc += .01*(gui->fb2KaleidoscopeSliceLfoTheta);
    
    //fb2 pixel lfo
    fb2XPixelScaleThetaInc+=.01*(gui->fb2XPixelScaleLfoTheta);
    fb2YPixelScaleThetaInc+=.01*(gui->fb2YPixelScaleLfoTheta);
    fb2PixelMixThetaInc+=.01*(gui->fb2PixelMixLfoTheta);
    fb2PixelBrightscaleThetaInc+=.01*(gui->fb2PixelBrightscaleLfoTheta);
    
    
    
    
    
    //fb3 lfos
    fb3DelayThetaInc += .01*(gui->fb3_delay_lfo_theta);
    
    //fb3mix and key
    fb3MixThetaInc+=.01*(gui->fb3MixLfoTheta);
    fb3LumakeyLevelThetaInc+=.01*(gui->fb3LumakeyLevelLfoTheta);
    fb3ChromakeyRedThetaInc += .01*(gui->fb3ChromakeyRedLfoTheta);
    fb3ChromakeyGreenThetaInc += .01*(gui->fb3ChromakeyGreenLfoTheta);
    fb3ChromakeyBlueThetaInc += .01*(gui->fb3ChromakeyBlueLfoTheta);
    fb3KeyThresholdThetaInc+=.01*(gui->fb3KeyThresholdLfoTheta);
    fb3KeySoftThetaInc += .01*(gui->fb3KeySoftLfoTheta);
    fb3MaskXThetaInc += 0.01*(gui->fb3MaskXLfoTheta);
    fb3MaskYThetaInc += 0.01*(gui->fb3MaskYLfoTheta);
    fb3MaskZThetaInc += 0.01*(gui->fb3MaskZLfoTheta);
    fb3MaskRotateThetaInc += 0.01*(gui->fb3MaskRotateLfoTheta);
    fb3MaskTileAmountThetaInc += 0.01*(gui->fb3MaskTileAmountLfoTheta);
    fb3MaskTexmodOffsetThetaInc += 0.01*(gui->fb3MaskTexmodOffsetLfoTheta);
    fb3MaskTexmodQuantizeAmountThetaInc += 0.01*(gui->fb3MaskTexmodQuantizeAmountLfoTheta);
    fb3MaskTexmodQuantizeMixThetaInc += 0.01*(gui->fb3MaskTexmodQuantizeMixLfoTheta);
    
    //fb3 color
    fb3HueOffsetThetaInc +=0.01*(gui->fb3HueOffsetLfoTheta);
    fb3SaturationOffsetThetaInc +=0.01*(gui->fb3SaturationOffsetLfoTheta);
    fb3BrightOffsetThetaInc +=0.01*(gui->fb3BrightOffsetLfoTheta);
    fb3HueAttenuateThetaInc +=0.01*(gui->fb3HueAttenuateLfoTheta);
    fb3SaturationAttenuateThetaInc +=0.01*(gui->fb3SaturationAttenuateLfoTheta);
    fb3BrightAttenuateThetaInc +=0.01*(gui->fb3BrightAttenuateLfoTheta);
    fb3HueShaperThetaInc +=0.01*(gui->fb3HueShaperLfoTheta);
    fb3HuePowMapThetaInc += .01*(gui->fb3HuePowMapLfoTheta);
    fb3SaturationPowMapThetaInc += .01*(gui->fb3SaturationPowMapLfoTheta);
    fb3BrightPowMapThetaInc += .01*(gui->fb3BrightPowMapLfoTheta);
    
    fb3HueQuantizeThetaInc += 0.01*(gui->fb3HueQuantizeLfoTheta);
    fb3SaturationQuantizeThetaInc += 0.01*(gui->fb3SaturationQuantizeLfoTheta);
    fb3BrightQuantizeThetaInc += 0.01*(gui->fb3BrightQuantizeLfoTheta);
    fb3HueQuantizeMixThetaInc += 0.01*(gui->fb3HueQuantizeMixLfoTheta);
    fb3SaturationQuantizeMixThetaInc += 0.01*(gui->fb3SaturationQuantizeMixLfoTheta);
    fb3BrightQuantizeMixThetaInc += 0.01*(gui->fb3BrightQuantizeMixLfoTheta);
    
    fb3HueDitherAmountThetaInc += 0.01*(gui->fb3HueDitherAmountLfoTheta);
    fb3SaturationDitherAmountThetaInc += 0.01*(gui->fb3SaturationDitherAmountLfoTheta);
    fb3BrightDitherAmountThetaInc += 0.01*(gui->fb3BrightDitherAmountLfoTheta);
    fb3HueDitherMixThetaInc += 0.01*(gui->fb3HueDitherMixLfoTheta);
    fb3SaturationDitherMixThetaInc += 0.01*(gui->fb3SaturationDitherMixLfoTheta);
    fb3BrightDitherMixThetaInc += 0.01*(gui->fb3BrightDitherMixLfoTheta);
    
    //fb3 geo
    fb3XDisplaceThetaInc+=.01*(gui->fb3XDisplaceLfoTheta);
    fb3YDisplaceThetaInc+=.01*(gui->fb3YDisplaceLfoTheta);
    fb3ZDisplaceThetaInc+=.01*(gui->fb3ZDisplaceLfoTheta);
    fb3RotateThetaInc+=.01*(gui->fb3RotateLfoTheta);
    fb3ShearMatrixThetaInc.x+= .01*(gui->fb3ShearMatrixLfoTheta.x);
    fb3ShearMatrixThetaInc.y += .01*(gui->fb3ShearMatrixLfoTheta.y);
    fb3ShearMatrixThetaInc.z += .01*(gui->fb3ShearMatrixLfoTheta.z);
    fb3ShearMatrixThetaInc.w += .01*(gui->fb3ShearMatrixLfoTheta.w);
    
    fb3FisheyeAmountThetaInc += .01*(gui->fb3FisheyeAmountLfoTheta);
    fb3FisheyeXThetaInc += .01*(gui->fb3FisheyeXLfoTheta);
    fb3FisheyeYThetaInc += .01*(gui->fb3FisheyeYLfoTheta);
    fb3SpiralAmountThetaInc += .01*(gui->fb3SpiralAmountLfoTheta);
    fb3SpiralAngleThetaInc += .01*(gui->fb3SpiralAngleLfoTheta);
    fb3SpiralXThetaInc += .01*(gui->fb3SpiralXLfoTheta);
    fb3SpiralYThetaInc += .01*(gui->fb3SpiralYLfoTheta);
    fb3KaleidoscopeSegmentsThetaInc += .01*(gui->fb3KaleidoscopeSegmentsLfoTheta);
    fb3KaleidoscopeSliceThetaInc += .01*(gui->fb3KaleidoscopeSliceLfoTheta);
    
    //fb3 pixel lfo
    fb3XPixelScaleThetaInc+=.01*(gui->fb3XPixelScaleLfoTheta);
    fb3YPixelScaleThetaInc+=.01*(gui->fb3YPixelScaleLfoTheta);
    fb3PixelMixThetaInc+=.01*(gui->fb3PixelMixLfoTheta);
    fb3PixelBrightscaleThetaInc+=.01*(gui->fb3PixelBrightscaleLfoTheta);
    
    
    //global
    
    blur_theta_amount+=.01*(gui->blur_amount_lfo_theta);
    blur_theta_radius+=.01*(gui->blur_radius_lfo_theta);
    sharpen_theta_amount+=.01*(gui->sharpen_amount_lfo_theta);
    sharpen_theta_radius+=.01*(gui->sharpen_radius_lfo_theta);
    sharpen_theta_boost+=.01*(gui->sharpen_boost_lfo_theta);
    
    //pixelation lfos
    
    
    
    
}

//--------------------------
void ofApp::hypercube_draw(){
    
    int limit=3;
    for(int i=0;i<limit;i++){
        hypercube_theta+=.1*gui->hypercube_theta_rate;
        
        hypercube_phi+=.1*gui->hypercube_phi_rate;
        
        
        
        hypercube_r=ofGetWidth()/16*(1);
        
        float xr=hypercube_r*(1);
        hypercube_x[0]=xr*(cos(hypercube_theta)-sin(hypercube_theta))*(1-.5*(cos(hypercube_phi)));
        hypercube_x[1]=xr*(cos(hypercube_theta)+sin(hypercube_theta))*(1-.5*(cos(PI/4+hypercube_phi)));
        hypercube_x[2]=xr*(-cos(hypercube_theta)+sin(hypercube_theta))*(1-.5*(cos(PI/2+hypercube_phi)));
        hypercube_x[3]=xr*(-cos(hypercube_theta)-sin(hypercube_theta))*(1-.5*(cos(3*PI/4+hypercube_phi)));
        hypercube_x[4]=xr*(cos(hypercube_theta)-sin(hypercube_theta))*(1-.5*(cos(PI+hypercube_phi)));
        hypercube_x[5]=xr*(cos(hypercube_theta)+sin(hypercube_theta))*(1-.5*(cos(5*PI/4+hypercube_phi)));
        hypercube_x[6]=xr*(-cos(hypercube_theta)+sin(hypercube_theta))*(1-.5*(cos(3*PI/2+hypercube_phi)));
        hypercube_x[7]=xr*(-cos(hypercube_theta)-sin(hypercube_theta))*(1-.5*(cos(7*PI/4+hypercube_phi)));
        
        float yr=hypercube_r*(1);
        hypercube_y[0]=yr*(sin(hypercube_theta)+cos(hypercube_theta))*(1-.5*(cos(hypercube_phi)));
        hypercube_y[1]=yr*(sin(hypercube_theta)-cos(hypercube_theta))*(1-.5*(cos(PI/4+hypercube_phi)));
        hypercube_y[2]=yr*(-sin(hypercube_theta)-cos(hypercube_theta))*(1-.5*(cos(PI/2+hypercube_phi)));
        hypercube_y[3]=yr*(-sin(hypercube_theta)+cos(hypercube_theta))*(1-.5*(cos(3*PI/4+hypercube_phi)));
        hypercube_y[4]=yr*(sin(hypercube_theta)+cos(hypercube_theta))*(1-.5*(cos(PI+hypercube_phi)));
        hypercube_y[5]=yr*(sin(hypercube_theta)-cos(hypercube_theta))*(1-.5*(cos(5*PI/4+hypercube_phi)));
        hypercube_y[6]=yr*(-sin(hypercube_theta)-cos(hypercube_theta))*(1-.5*(cos(3*PI/2+hypercube_phi)));
        hypercube_y[7]=yr*(-sin(hypercube_theta)+cos(hypercube_theta))*(1-.5*(cos(7*PI/4+hypercube_phi)));
        
        float zr=hypercube_r*(1);
        hypercube_z[0]=-zr/2*cos(hypercube_phi)+hypercube_r;
        hypercube_z[1]=-zr/2*cos(PI/4+hypercube_phi)+hypercube_r;
        hypercube_z[2]=-zr/2*cos(PI/2+hypercube_phi)+hypercube_r;
        hypercube_z[3]=-zr/2*cos(3*PI/4+hypercube_phi)+hypercube_r;
        hypercube_z[4]=-zr/2*cos(PI+hypercube_phi)+hypercube_r;
        hypercube_z[5]=-zr/2*cos(5*PI/4+hypercube_phi)+hypercube_r;
        hypercube_z[6]=-zr/2*cos(3*PI/2+hypercube_phi)+hypercube_r;
        hypercube_z[7]=-zr/2*cos(7*PI/8+hypercube_phi)+hypercube_r;
        
        
        color_theta+=.01;
        ofSetColor(127+127*sin(color_theta),0+192*abs(cos(color_theta*.2)),127+127*cos(color_theta/3.0f));
        ofNoFill();
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
        ofRotateYRad(-PI/2);
        ofRotateZRad(hypercube_phi);
        ofRotateXRad(hypercube_theta/3);
        ofRotateXRad(hypercube_theta/5);
        
        //list up the vertexes, give them some kind of grouping and
        //set up a set of 3 rotatios for each
        //i think just pick like an inner cube and an outer cube
        //if thats even possible
        
        ofDrawLine(hypercube_x[0],hypercube_y[0],hypercube_z[0],hypercube_x[1],hypercube_y[1],hypercube_z[1]);
        ofDrawLine(hypercube_x[1],hypercube_y[1],hypercube_z[1],hypercube_x[2],hypercube_y[2],hypercube_z[2]);
        ofDrawLine(hypercube_x[2],hypercube_y[2],hypercube_z[2],hypercube_x[3],hypercube_y[3],hypercube_z[3]);
        ofDrawLine(hypercube_x[3],hypercube_y[3],hypercube_z[3],hypercube_x[4],hypercube_y[4],hypercube_z[4]);
        ofDrawLine(hypercube_x[4],hypercube_y[4],hypercube_z[4],hypercube_x[5],hypercube_y[5],hypercube_z[5]);
        ofDrawLine(hypercube_x[5],hypercube_y[5],hypercube_z[5],hypercube_x[6],hypercube_y[6],hypercube_z[6]);
        ofDrawLine(hypercube_x[6],hypercube_y[6],hypercube_z[6],hypercube_x[7],hypercube_y[7],hypercube_z[7]);
        ofDrawLine(hypercube_x[7],hypercube_y[7],hypercube_z[7],hypercube_x[0],hypercube_y[0],hypercube_z[0]);
        
        ofDrawLine(hypercube_x[0],hypercube_y[0],-hypercube_z[0],hypercube_x[1],hypercube_y[1],-hypercube_z[1]);
        ofDrawLine(hypercube_x[1],hypercube_y[1],-hypercube_z[1],hypercube_x[2],hypercube_y[2],-hypercube_z[2]);
        ofDrawLine(hypercube_x[2],hypercube_y[2],-hypercube_z[2],hypercube_x[3],hypercube_y[3],-hypercube_z[3]);
        ofDrawLine(hypercube_x[3],hypercube_y[3],-hypercube_z[3],hypercube_x[4],hypercube_y[4],-hypercube_z[4]);
        ofDrawLine(hypercube_x[4],hypercube_y[4],-hypercube_z[4],hypercube_x[5],hypercube_y[5],-hypercube_z[5]);
        ofDrawLine(hypercube_x[5],hypercube_y[5],-hypercube_z[5],hypercube_x[6],hypercube_y[6],-hypercube_z[6]);
        ofDrawLine(hypercube_x[6],hypercube_y[6],-hypercube_z[6],hypercube_x[7],hypercube_y[7],-hypercube_z[7]);
        ofDrawLine(hypercube_x[7],hypercube_y[7],-hypercube_z[7],hypercube_x[0],hypercube_y[0],-hypercube_z[0]);
        
        ofDrawLine(hypercube_x[0],hypercube_y[0],hypercube_z[0],hypercube_x[0],hypercube_y[0],-hypercube_z[0]);
        ofDrawLine(hypercube_x[1],hypercube_y[1],hypercube_z[1],hypercube_x[1],hypercube_y[1],-hypercube_z[1]);
        ofDrawLine(hypercube_x[2],hypercube_y[2],hypercube_z[2],hypercube_x[2],hypercube_y[2],-hypercube_z[2]);
        ofDrawLine(hypercube_x[3],hypercube_y[3],hypercube_z[3],hypercube_x[3],hypercube_y[3],-hypercube_z[3]);
        ofDrawLine(hypercube_x[4],hypercube_y[4],hypercube_z[4],hypercube_x[4],hypercube_y[4],-hypercube_z[4]);
        ofDrawLine(hypercube_x[5],hypercube_y[5],hypercube_z[5],hypercube_x[5],hypercube_y[5],-hypercube_z[5]);
        ofDrawLine(hypercube_x[6],hypercube_y[6],hypercube_z[6],hypercube_x[6],hypercube_y[6],-hypercube_z[6]);
        ofDrawLine(hypercube_x[7],hypercube_y[7],hypercube_z[7],hypercube_x[7],hypercube_y[7],-hypercube_z[7]);
        
        ofDrawLine(hypercube_x[0],hypercube_y[0],-hypercube_z[0],hypercube_x[4],hypercube_y[4],-hypercube_z[4]);
        ofDrawLine(hypercube_x[1],hypercube_y[1],-hypercube_z[1],hypercube_x[5],hypercube_y[5],-hypercube_z[5]);
        ofDrawLine(hypercube_x[2],hypercube_y[2],-hypercube_z[2],hypercube_x[6],hypercube_y[6],-hypercube_z[6]);
        ofDrawLine(hypercube_x[3],hypercube_y[3],-hypercube_z[3],hypercube_x[7],hypercube_y[7],-hypercube_z[7]);
        
        ofDrawLine(hypercube_x[0],hypercube_y[0],hypercube_z[0],hypercube_x[4],hypercube_y[4],hypercube_z[4]);
        ofDrawLine(hypercube_x[1],hypercube_y[1],hypercube_z[1],hypercube_x[5],hypercube_y[5],hypercube_z[5]);
        ofDrawLine(hypercube_x[2],hypercube_y[2],hypercube_z[2],hypercube_x[6],hypercube_y[6],hypercube_z[6]);
        ofDrawLine(hypercube_x[3],hypercube_y[3],hypercube_z[3],hypercube_x[7],hypercube_y[7],hypercube_z[7]);
        
        
        
        
        
        
        ofPopMatrix();
        
    }//endifor
    
}

 /****************************************************/

void ofApp::tetrahedron_setup(){
    
    
    ofVec3f tri1;
    ofVec3f tri2;
    ofVec3f tri3;
    ofVec3f tri4;
    tri1.set(1,1,1);
    tri2.set(-1,-1,1);
    tri3.set(-1,1,-1);
    tri4.set(1,-1,-1);
    float shapeScale=ofGetWidth()/8;
    
    tri1=tri1*shapeScale;
    tri2=tri2*shapeScale;
    tri3=tri3*shapeScale;
    tri4=tri4*shapeScale;
    
    
    tetrahedron.lineTo(tri1);
    tetrahedron.lineTo(tri2);
    tetrahedron.lineTo(tri4);
    tetrahedron.lineTo(tri1);
    tetrahedron.lineTo(tri3);
    tetrahedron.lineTo(tri2);
    tetrahedron.lineTo(tri3);
    tetrahedron.lineTo(tri4);
    //tetrahedron.lineTo(tri4);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 'q') { qq += .01; cout << "qq" << qq << endl; }
	if (key == 'w') { qq -= .01; cout << "qq" << qq << endl; }
	//if (key == 'q') { videoSwitch = 0; }
	//if (key == 'w') { videoSwitch = 1; }
    
	/*
    if(key=='3'){
        aa=ss=dd=ff=gg=hh=0;
    }
 
  
    if(key=='1'){
        for(int i=0;i<fbob;i++){
            pastFrames[i].begin();       
            ofClear(0,0,0,255);
            pastFrames[i].end();

			//pastFrames2[i].begin();
			//ofClear(0, 0, 0, 255);
			//pastFrames2[i].end();
        }
        
        fbo_draw.begin();
        ofClear(0,0,0,255);
        fbo_draw.end();
    }
    //if(key=='q'){sw1==0;}
    
    if(key=='a'){aa+=0.0001;}
    if(key=='z'){aa-=0.0001;}
    if(key=='s'){ss+=0.0001;}
    if(key=='x'){ss-=0.0001;}
    
    if(key=='d'){dd+=0.0001;}
    if(key=='c'){dd-=0.0001;}
    
    if(key=='f'){ff+=0.0001;}
    if(key=='v'){ff-=0.0001;}
    
    if(key=='g'){gg+=0.0001;}
    if(key=='b'){gg-=0.0001;}
    if(key=='h'){hh+=0.01;}
    if(key=='n'){hh-=0.01;}
    
    
    if(key=='j'){jj+=0.1;}
    if(key=='m'){jj-=0.1;}
    if(key=='k'){kk+=0.1;}
    if(key==','){kk-=0.1;}
    
    if(key=='l'){cam1_scale+=0.01;}
    if(key=='.'){cam1_scale-=0.01;}
    
    if(key==';'){scale1+=0.01;}
    if(key=='/'){scale1-=0.01;}
    
    if(key=='['){scale2+=0.01;}
    if(key==']'){scale2-=0.01;}
    
    if(key=='q'){qq+=.01;cout << "qq"<<qq<< endl;}
    if(key=='w'){qq-=.01;cout << "qq"<<qq<< endl;}
    if(key=='e'){ee+=.1;cout << "ee"<<ee<< endl;}
    if(key=='r'){ee-=.1;cout << "ee"<<ee<< endl;}
    
    
    if(key=='u'){ii+=1;}
    if(key=='i'){ii-=1;}
    if(key=='o'){oo+=.1;}
    if(key=='p'){oo-=.1;}
    
    if(key=='t'){tt+=.01;}
    if(key=='y'){tt-=.01;}
    
    
    if(key=='2'){amp+=.001;}
    if(key=='3'){amp-=.001;}
    
	*/

}

/************************/
//--------------------------------------------------------------
void ofApp::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
}

//_---------------------------
void ofApp::midibiz(){
    /*midimessagesbiz**/
    
    
    //ofTranslate(0,0,-100);
    for(unsigned int i = 0; i < midiMessages.size(); ++i) {
        
        ofxMidiMessage &message = midiMessages[i];
        
        
        ofSetColor(127);
        if(message.status < MIDI_SYSEX) {
            //text << "chan: " << message.channel;
            if(message.status == MIDI_CONTROL_CHANGE) {
                
                //How to Midi Map
                //uncomment the line that says cout<<message control etc
                //run the code and look down in the console
                //when u move a knob on yr controller keep track of the number that shows up
                //that is the cc value of the knob
                //then go down to the part labled 'MIDIMAPZONE'
                //and change the numbers for each if message.control== statement to the values
                //on yr controller
                
                 cout << "message.control"<< message.control<< endl;
                 cout << "message.value"<< message.value<< endl;
                //lets try defaulting to bipolar...
                //nice try but nope that sucks
                //midi_controls[message.control]=(message.value-63.0)/63.0;
                
                
                //ch1 hue
                if(message.control==20){c1=(message.value-63.0f)/63.0f;}
                
                //ch1 sat
                if(message.control==21){c2=(message.value-63.0f)/63.0f;}
                
                //ch1 bright
                if(message.control==22){c3=(message.value-63.0f)/63.0f;}
                
                //global blur
                if(message.control==25){c4=(message.value)/127.0f;}
                
                //global sharpen
                if(message.control==24){c5=(message.value)/127.0f;}
                
                //fb0 key value
                if(message.control==28){c6=(message.value)/127.0f;}
                
                //fb0 mix
                if(message.control==29){c7=(message.value-63.0f)/63.0f;}
                
                //fb0 delay amount
                if(message.control==30){c8=(message.value)/127.0f;}
                
                //fb0 x
                if(message.control==4){c9=(message.value-63.0f)/63.0f;}
                
                //fb0 y
                if(message.control==3){c10=(message.value-63.0f)/63.0f;}

                
                //fb0 z
                if(message.control==12){c11=(message.value-63.0f)/63.0f;}

                
                //fb0 theta
                if(message.control==11){c12=(message.value-63.0f)/63.0f;}
                
                //fb0 hue
                if(message.control==5){c13=(message.value-63.0f)/63.0f;}
                
                //fb0 sat
                if(message.control==2){c14=(message.value-63.0f)/63.0f;}
                
                //fb0 bright
                if(message.control==13){c15=(message.value-63.0f)/63.0f;}

                
                //fb0 huex_mod
                if(message.control==16){c16=(message.value)/127.0f;}
                
                //fb0 huex_offset
                if(message.control==10){c17=(message.value-63.0f)/63.0f;}
                
                //fb0 huex_lfo
                if(message.control==17){c18=(message.value-63.0f)/63.0f;}
                
                
                //fB!1
                //fb1 key value
                if(message.control==31){c19=(message.value)/127.0f;}
                
                //fb1 mix
                if(message.control==27){c20=(message.value-63.0f)/63.0f;}
                
                //fb1 delay amount
                if(message.control==26){c21=(message.value)/127.0f;}
                
                //fb1 x
                if(message.control==6){c22=(message.value-63.0f)/63.0f;}
                
                //fb1 y
                if(message.control==1){c23=(message.value-63.0f)/63.0f;}
                
                
                //fb1 z
                if(message.control==14){c24=(message.value-63.0f)/63.0f;}
                
                
                //fb1 theta
                if(message.control==9){c25=(message.value-63.0f)/63.0f;}
                
                //fb1 hue
                if(message.control==7){c26=(message.value-63.0f)/63.0f;}
                
                //fb1 sat
                if(message.control==0){c27=(message.value-63.0f)/63.0f;}
                
                //fb1 bright
                if(message.control==15){c28=(message.value-63.0f)/63.0f;}
                
                
                //fb1 huex_mod
                if(message.control==18){c29=(message.value)/127.0f;}
                
                //fb1 huex_offset
                if(message.control==8){c30=(message.value-63.0f)/63.0f;}
                
                //fb1 huex_lfo
                if(message.control==19){c31=(message.value-63.0f)/63.0f;}

                
                //MIDIMAPZONE
                //these are all set to output bipolor controls at this moment (ranging from -1.0 to 1.0)
                //if u uncomment the second line on each of these if statements that will switch thems to unipolor
                //controls (ranging from 0.0to 1.0) if  you prefer
                //then find the variable that youd like to control down in CAVARIABLEZONES or MIXERVARIBLEZONES
                //and substitute c1,c2, ..cn whichever control knob u wish the map
          
                
            }
           
            
            
            
        }//
        
        
    }
    
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {

	// add the latest message to the message queue
	midiMessages.push_back(msg);

	// remove any old messages if we have too many
	while(midiMessages.size() > maxMessages) {
		midiMessages.erase(midiMessages.begin());
	}
}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
   
}


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
   
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased() {
}
