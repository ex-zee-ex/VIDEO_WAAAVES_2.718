/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"
#include <iostream>


int fbob=30;

int guiscale=275;

void GuiApp::setup(){
    
    ofBackground(0);
   
    gui.setup();

    fb0ShearMatrixRange.set(.25, .25, .25, .25);
    fb1ShearMatrixRange.set(.25, .25, .25, .25);
    fb2ShearMatrixRange.set(.25, .25, .25, .25);
    fb3ShearMatrixRange.set(.25, .25, .25, .25);
    
  }


//----------------------------------
    void GuiApp::update() {
       
    }


//------------------------------
    void GuiApp::draw() {
        
		float rootThree = 1.73205080757;
        
        auto mainSettings = ofxImGui::Settings();
        
        //list variables for ranges...not this time but probably at some point in the future
        //should normalize everything in the gui to -1 1 and then add coeffecients in ofApp.cpp
        float x_y_d=40;
        float lfom=10;
        
        
        int gui_hscaler=190;
        int gui_vscaler=110;
        //ImGui::SetNextWindowPos(ImVec2(0*gui_hscaler, 0*gui_vscaler), ImGuiCond_FirstUseEver);
        //ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
        
        
        gui.begin();
        
		ImGui::SetNextWindowSize(ImVec2(gui_hscaler*2.0f, gui_vscaler), ImGuiCond_Once);
        
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 0*gui_vscaler));
        //channel 1 select folder
        if (ofxImGui::BeginWindow("channel1", mainSettings, false))
        {
			static int item_current = 0;
			if (ImGui::Button("reset all")) {
				ch1ResetAll();
			}
			//so for dropdown menues set up a char array of items like so
			const char* items[] = { "cam1","cam2", "ndi" };
			ImGui::Combo("ch1 input", &item_current, items, IM_ARRAYSIZE(items));
			channel1_select = item_current;
			if (ImGui::CollapsingHeader("parameters"))
			{
				if (ImGui::Button("reset all parameters")) {
					ch1ResetAllParameters();
				}
				if (ImGui::CollapsingHeader("ch1 adjust"))
				{
					if (ImGui::Button("reset all adjust")) {
						ch1Scale = 1.0;
						ch1HsbAttenuate.set(0, 0, 0);
						ch1Quantize = 32;
						ch1QuantizeSwitch = false;
						ch1HueInvert = false;
						ch1BrightInvert = false;
						ch1SaturationInvert = false;
						ch1HMirror = false;
						ch1VMirror = false;
					}

					ImGui::SliderFloat("ch1 scale", &ch1Scale, 0, 5.0);

					ImGui::SliderFloat("ch1 hue", &ch1HsbAttenuate.x, -1.0, 2.0);
					ImGui::SliderFloat("ch1 saturation", &ch1HsbAttenuate.y, -1.0, 2.0);
					ImGui::SliderFloat("ch1 bright", &ch1HsbAttenuate.z, -1.0, 2.0);

					ImGui::Checkbox("ch1 quantize switch", &ch1QuantizeSwitch);
					ImGui::SliderInt("ch1 quantize", &ch1Quantize, 1.0, 32.0);

					ImGui::Checkbox("ch1 hue invert", &ch1HueInvert);
					ImGui::Checkbox("ch1 saturation invert", &ch1SaturationInvert);
					ImGui::Checkbox("ch1 bright invert", &ch1BrightInvert);

					ImGui::Checkbox("ch1 horizontal mirror", &ch1HMirror);
					ImGui::Checkbox("ch1 vertical mirror", &ch1VMirror);
				}
				if (ImGui::CollapsingHeader("ch1 pixelate"))
				{
					if (ImGui::Button("reset all pixel")) {
						ch1PixelSwitch = 0;
						ch1PixelXYLock = 1;
						ch1XPixelScale = 64;
						ch1YPixelScale = 64;
						ch1PixelMix = 1;
						ch1PixelBrightscale = 0;
					}

					ImGui::Checkbox("ch1 pixelate on/off", &ch1PixelSwitch);
					ImGui::Checkbox("ch1 pixelXY lock", &ch1PixelXYLock);
					ImGui::SliderInt("ch1 pixel scale_x", &ch1XPixelScale, .0f, 256.0f);
					if (ch1PixelXYLock == 1) {
						ImGui::SliderInt("ch1 pixel scale_y", &ch1XPixelScale, .0f, 256.0f);
					}
					if (ch1PixelXYLock == 0) {
						ImGui::SliderInt("ch1 pixel scale_y", &ch1YPixelScale, .0f, 256.0f);
					}
					ImGui::SliderFloat("ch1 pixel mix", &ch1PixelMix, -2.0f, 2.0f);
					ImGui::SliderFloat("ch1 bright_scale", &ch1PixelBrightscale, -2.0f, 2.0f);
				}

			}
			if (ImGui::CollapsingHeader("L F O s"))
			{
				ImGui::Text("Little False Ovals");

				if (ImGui::Button("reset all lfo")) {
					ch1ResetAllLfo();
				}
				if (ImGui::CollapsingHeader("ch1 adjust lfo")) {
					if (ImGui::Button("reset adjust lfo")) {
						ch1ScaleLfoTheta = .0;
						ch1ScaleLfoAmp = .0;
						ch1HsbAttenuateLfoTheta.set(0, 0, 0);
						ch1HsbAttenuateLfoAmp.set(0, 0, 0);
						ch1QuantizeLfoTheta = 0;
						ch1QuantizeLfoAmp = 0;
					}
					ImGui::SliderFloat("ch1 scale lfo rate", &ch1ScaleLfoTheta, 0.0f, lfom);
					ImGui::SliderFloat("ch1 scale lfo amp", &ch1ScaleLfoAmp, 0, 5.0);

					ImGui::SliderFloat("ch1 hue lfo rate", &ch1HsbAttenuateLfoTheta.x, .0f, lfom);
					ImGui::SliderFloat("ch1 hue lfo amp", &ch1HsbAttenuateLfoAmp.x, -1.0, 2.0);
					ImGui::SliderFloat("ch1 saturation rate", &ch1HsbAttenuateLfoTheta.y, .0f, lfom);
					ImGui::SliderFloat("ch1 saturation lfo amp", &ch1HsbAttenuateLfoAmp.y, -1.0, 2.0);
					ImGui::SliderFloat("ch1 bright lfo rate", &ch1HsbAttenuateLfoTheta.z, .0f, lfom);
					ImGui::SliderFloat("ch1 bright lfo amp", &ch1HsbAttenuateLfoAmp.z, -1.0, 2.0);

					//ImGui::SliderFloat("ch1 quantize lfo rate", &ch1QuantizeLfoTheta, 0.0f, lfom);
					//ImGui::SliderFloat("ch1 quantize lfo amp", &ch1QuantizeLfoAmp, -32.0, 32.0);
				}
				ImGui::Separator();
				if (ImGui::CollapsingHeader("ch1 pixel L F O s"))
				{
					if (ImGui::Button("reset pixel lfo")) {
						ch1XPixelScaleLfoTheta = 0;
						ch1XPixelScaleLfoAmp = 0;
						ch1YPixelScaleLfoTheta = 0;
						ch1YPixelScaleLfoAmp = 0;
						ch1PixelMixLfoTheta = 0;
						ch1PixelMixLfoAmp = 0;
						ch1PixelBrightscaleLfoTheta = 0;
						ch1PixelBrightscaleLfoAmp = 0;
					}
					//ImGui::Text("Lfos For Oscillation s");
					ImGui::SliderFloat("ch1 pixel scale_x_rate", &ch1XPixelScaleLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("ch1 pixel scale_x_amp", &ch1XPixelScaleLfoAmp, -256.0f, 256.0f);
					ImGui::SliderFloat("ch1 pixel scale_y_rate", &ch1YPixelScaleLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("ch1 pixel scale_y_amp", &ch1YPixelScaleLfoAmp, -256.0f, 256.0f);
					ImGui::SliderFloat("ch1 pixel mix_rate", &ch1PixelMixLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("ch1 pixel mix_amp", &ch1PixelMixLfoAmp, -20.0f, 20.0f);
					ImGui::SliderFloat("ch1 pixel bright scale rate", &ch1PixelBrightscaleLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("ch1 pixel bright scale amp", &ch1PixelBrightscaleLfoAmp, -2.0f, 2.0f);
				}
				ImGui::Separator();
            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        //ImGui::End();
        
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 1*gui_vscaler));
        //channel 2 select folder
        if (ofxImGui::BeginWindow("channel2", mainSettings, false))
        {
			if (ImGui::Button("reset all")) {
				ch2ResetAll();
			}

			const char* items[] = { "cam1","cam2", "ndi" };

			static int item_current = 1;

			ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
			if (item_current == 0) { channel2_select = 0; }
			if (item_current == 1) { channel2_select = 1; }
			if (item_current == 2) { channel2_select = 2; }
			if (ImGui::CollapsingHeader("ch 2 parameters")) {
				if (ImGui::Button("reset all parameters")) {
					ch2ResetAllParameters();
				}
				if (ImGui::CollapsingHeader("ch 2 mix and key"))
				{
					static int item_current0 = 0;
					static int item_current1 = 0;
					static int item_current2 = 0;
					static int item_current3 = 0;

					if (ImGui::Button("reset mix n key")) {
						item_current0 = 0;
						item_current1 = 0;
						item_current2 = 0;
						item_current3 = 0;

						ch2LumakeyLevel = 0;
						ch2ChromakeyRed = 0;
						ch2ChromakeyGreen = 0;
						ch2ChromakeyBlue = 0;
						ch2KeyThreshold = 0;
						ch2KeySoft = 0;
						ch2Mix = 0;
					}

					const char* items0[] = { "ch1->ch2","ch2->ch1" };
					ImGui::Combo("ch2 mix and key order", &item_current0, items0, IM_ARRAYSIZE(items0));
					ch2KeyOrder = item_current0;

					const char* items1[] = { "lerp", "add","difference","mult","dodge" };
					ImGui::Combo("ch2 mix Type", &item_current1, items1, IM_ARRAYSIZE(items1));
					ch2MixType = item_current1;

					ImGui::SliderFloat("ch2 mix", &ch2Mix, -2.0f, 2.0f);

					const char* items2[] = { "clamp", "wrap","foldover" };
					ImGui::Combo("ch2 Mix overflow", &item_current2, items2, IM_ARRAYSIZE(items2));
					ch2MixOverflow = item_current2;

					const char* items3[] = { "Lumakey","Chromakey" };
					ImGui::Combo("ch2 key mode", &item_current3, items3, IM_ARRAYSIZE(items3));
					ch2KeyMode = item_current3;

					if (ch2KeyMode == 0) {
						ImGui::SliderFloat("ch2 lumakey level", &ch2LumakeyLevel, 0.0f, 1.0f);
					}
					if (ch2KeyMode == 1) {

						ImGui::SliderFloat("ch2 Chromakey Red", &ch2ChromakeyRed, 0.0f, 1.0f);
						ImGui::SliderFloat("ch2 Chromakey Green", &ch2ChromakeyGreen, 0.0f, 1.0f);
						ImGui::SliderFloat("ch2 Chromakey Blue", &ch2ChromakeyBlue, 0.0f, 1.0f);
						ImGui::ColorButton("testingColorButton", ImVec4(ch2ChromakeyRed, ch2ChromakeyGreen, ch2ChromakeyBlue, 1.0), 0, ImVec2(20, 20));
					}
					ImGui::SliderFloat("ch2 key threshold", &ch2KeyThreshold, 0.0f, rootThree);
					ImGui::SliderFloat("ch2 key soft", &ch2KeySoft, 0.0f, 1.0f);

				}
				if (ImGui::CollapsingHeader("channel 2 adjust"))
				{
					
					if (ImGui::Button("reset adjust")) {
						ch2Scale = 1.0;
						ch2HsbAttenuate.set(0,0,0);
						ch2Quantize = 32;
						ch2QuantizeSwitch = false;
						ch2HueInvert = false;
						ch2BrightInvert = false;
						ch2SaturationInvert = false;
					}					

					ImGui::SliderFloat("ch2 scale", &ch2Scale, 0, 5.0);

					ImGui::SliderFloat("ch2 hue", &ch2HsbAttenuate.x, -1.0, 2.0);
					ImGui::SliderFloat("ch2 saturation", &ch2HsbAttenuate.y, -1.0, 2.0);
					ImGui::SliderFloat("ch2 bright", &ch2HsbAttenuate.z, -1.0, 2.0);

					ImGui::Checkbox("ch2 quantize switch", &ch2QuantizeSwitch);
					ImGui::SliderInt("ch2 quantize", &ch2Quantize, 1.0, 32.0);

					ImGui::Checkbox("ch2 hue invert", &ch2HueInvert);
					ImGui::Checkbox("ch2 saturation invert", &ch2SaturationInvert);
					ImGui::Checkbox("ch2 bright invert", &ch2BrightInvert);


				}//end collapsing folder
				if (ImGui::CollapsingHeader("ch2 pixelate"))
				{
					if (ImGui::Button("reset all pixel")) {
						ch2PixelSwitch = 0;
						ch2PixelXYLock = 1;
						ch2XPixelScale = 64;
						ch2YPixelScale = 64;
						ch2PixelMix = 1;
						ch2PixelBrightscale = 0;
					}
					ImGui::Checkbox("ch2 pixelate on/off", &ch2PixelSwitch);
					ImGui::Checkbox("ch2 pixelXY lock", &ch2PixelXYLock);
					ImGui::SliderInt("ch2 pixel scale_x", &ch2XPixelScale, .0f, 256.0f);
					if (ch2PixelXYLock == 1) {
						ImGui::SliderInt("ch2 pixel scale_y", &ch2XPixelScale, .0f, 256.0f);
					}
					if (ch2PixelXYLock == 0) {
						ImGui::SliderInt("ch2 pixel scale_y", &ch2YPixelScale, .0f, 256.0f);
					}
					ImGui::SliderFloat("ch2 pixel mix", &ch2PixelMix, -2.0f, 2.0f);
					ImGui::SliderFloat("ch2 bright_scale", &ch2PixelBrightscale, -2.0f, 2.0f);
				}
			}
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Lets Find Orangutangs");
                
				if (ImGui::Button("reset all lfo")) {
					ch2ResetAllLfo();
				}
				if (ImGui::CollapsingHeader("ch2 adjust lfo")) {
					if (ImGui::Button("reset adjust lfo")) {
						ch2ScaleLfoTheta = .0;
						ch2ScaleLfoAmp = .0;
						ch2HsbAttenuateLfoTheta.set(0, 0, 0);
						ch2HsbAttenuateLfoAmp.set(0, 0, 0);
						ch2QuantizeLfoTheta = 0;
						ch2QuantizeLfoAmp = 0;
					}
					ImGui::SliderFloat("ch2 scale lfo rate", &ch2ScaleLfoTheta, 0.0f, lfom);
					ImGui::SliderFloat("ch2 scale lfo amp", &ch2ScaleLfoAmp, 0, 5.0);

					ImGui::SliderFloat("ch2 hue lfo rate", &ch2HsbAttenuateLfoTheta.x, .0f, lfom);
					ImGui::SliderFloat("ch2 hue lfo amp", &ch2HsbAttenuateLfoAmp.x, -1.0, 2.0);
					ImGui::SliderFloat("ch2 saturation rate", &ch2HsbAttenuateLfoTheta.y, .0f, lfom);
					ImGui::SliderFloat("ch2 saturation lfo amp", &ch2HsbAttenuateLfoAmp.y, -1.0, 2.0);
					ImGui::SliderFloat("ch2 bright lfo rate", &ch2HsbAttenuateLfoTheta.z, .0f, lfom);
					ImGui::SliderFloat("ch2 bright lfo amp", &ch2HsbAttenuateLfoAmp.z, -1.0, 2.0);

					//ImGui::SliderFloat("ch2 quantize lfo rate", &ch2QuantizeLfoTheta, 0.0f, lfom);
					//ImGui::SliderFloat("ch2 quantize lfo amp", &ch2QuantizeLfoAmp, -32.0, 32.0);
				}
				ImGui::Separator();
				if (ImGui::CollapsingHeader("ch2 pixel L F O s"))
				{
					if (ImGui::Button("reset pixel lfo")) {
						ch2XPixelScaleLfoTheta = 0;
						ch2XPixelScaleLfoAmp = 0;
						ch2YPixelScaleLfoTheta = 0;
						ch2YPixelScaleLfoAmp = 0;
						ch2PixelMixLfoTheta = 0;
						ch2PixelMixLfoAmp = 0;
						ch2PixelBrightscaleLfoTheta = 0;
						ch2PixelBrightscaleLfoAmp = 0;
					}
					//ImGui::Text("Lfos For Oscillation s");
					ImGui::SliderFloat("ch2 pixel scale_x_rate", &ch2XPixelScaleLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("ch2 pixel scale_x_amp", &ch2XPixelScaleLfoAmp, -256.0f, 256.0f);
					ImGui::SliderFloat("ch2 pixel scale_y_rate", &ch2YPixelScaleLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("ch2 pixel scale_y_amp", &ch2YPixelScaleLfoAmp, -256.0f, 256.0f);
					ImGui::SliderFloat("ch2 pixel mix_rate", &ch2PixelMixLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("ch2 pixel mix_amp", &ch2PixelMixLfoAmp, -20.0f, 20.0f);
					ImGui::SliderFloat("ch2 pixel bright scale rate", &ch2PixelBrightscaleLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("ch2 pixel bright scale amp", &ch2PixelBrightscaleLfoAmp, -2.0f, 2.0f);
				}

            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        //ImGui::End();
        
      
        
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 2*gui_vscaler));
        
        //fb0
        if (ofxImGui::BeginWindow("fb0", mainSettings, false)){
			if (ImGui::Button("reset all")) {
				fb0ResetAll();
			}
            if (ImGui::CollapsingHeader("parameters")){
				if (ImGui::Button("reset parameters")) {
					fb0ResetAllParameters();
				}
				ImGui::SliderInt("fb0DelayAmount", &fb0DelayAmount, 0, fbob - 1);
                ImGui::Checkbox("tex_mod", &fb0TexmodSwitch);
                const char* items[] = { "channel 1","channel 2" };
                static int item_current = 0;
                ImGui::Combo("texmod select", &item_current, items, IM_ARRAYSIZE(items));
                fb0TexmodSelect=item_current;
                
                if (ImGui::CollapsingHeader("mix and key")){
					static int item_current0 = 0;
					static int item_current1 = 0;
					static int item_current2 = 0;
					static int item_current3 = 0;
					static int item_current4 = 0;
					static int item_current5 = 0;
					if ( (ImGui::Button("reset mix and key")) ) {
						fb0LumakeyLevel = 0;
						fb0KeyThreshold = 0;
						fb0ChromakeyRed = 0;
						fb0ChromakeyGreen = 0;
						fb0ChromakeyBlue = 0;
						fb0KeySoft = 0;
						fb0MaskX = 0;
						fb0MaskY = 0;
						fb0MaskZ = 1.0;
						fb0MaskRotate = 0;
						fb0MaskTileAmount = 1.0;
						fb0MaskTexmodOffset = 0;
						fb0MaskTexmodQuantizeAmount = 1.0;
						fb0MaskTexmodQuantizeMix = 1.0;
						item_current0 = 0;
						item_current1 = 0;
						item_current2 = 0;
						item_current3 = 0;
						item_current4 = 0;
						item_current5 = 0;
						fb0Mix = 0;

						fb0LumakeyLevelTexmod = 0.0;
						fb0ChromakeyRedTexmod = 0;
						fb0ChromakeyGreenTexmod = 0;
						fb0ChromakeyBlueTexmod = 0;
						fb0KeyThresholdTexmod = 0.0;
						fb0KeySoftTexmod = 0;
						fb0MixTexmod = .0;
						fb0MaskXTexmod = 0;
						fb0MaskYTexmod = 0;
						fb0MaskZTexmod = 0.0;
						fb0MaskRotateTexmod = 0;
						fb0MaskTileAmountTexmod = 0.0;
					}
                    
					const char* items0[] = { "Input1->fb0","fb0->Input1" };
					ImGui::Combo("fb0 mix and key order", &item_current0, items0, IM_ARRAYSIZE(items0));
					fb0KeyOrder = item_current0;

					const char* items1[] = { "lerp", "add","difference","mult","dodge" };
					ImGui::Combo("fb0 mix Type", &item_current1, items1, IM_ARRAYSIZE(items1));
					fb0MixType = item_current1;

					if (fb0TexmodSwitch == false) {
						ImGui::SliderFloat("fb0 mix", &fb0Mix, -2.0f, 2.0f);
					}
					if (fb0TexmodSwitch == true) {
						ImGui::SliderFloat("texmod fb0 mix", &fb0MixTexmod, -2.0f, 2.0f);
					}
					const char* items2[] = { "clamp", "wrap","foldover" };
					ImGui::Combo("fb0 Mix overflow", &item_current2, items2, IM_ARRAYSIZE(items2));
					fb0MixOverflow = item_current2;

					const char* items3[] = { "Lumakey","Chromakey","wipePattern" };
					ImGui::Combo("fb0 key mode", &item_current3, items3, IM_ARRAYSIZE(items3));
					fb0KeyMode = item_current3;

					if (fb0KeyMode == 0) {
						if (fb0TexmodSwitch == false) {
							ImGui::SliderFloat("fb0 lumakey level", &fb0LumakeyLevel, 0.0f, 1.0f);
						}
						if (fb0TexmodSwitch == true) {
							ImGui::SliderFloat("texmod fb0 lumakey level", &fb0LumakeyLevelTexmod, .0f, 1.0f);
						}
					}
					if (fb0KeyMode == 1) {
						if (fb0TexmodSwitch == false) {
							ImGui::SliderFloat("fb0 Chromakey Red", &fb0ChromakeyRed, 0.0f, 1.0f);
							ImGui::SliderFloat("fb0 Chromakey Green", &fb0ChromakeyGreen, 0.0f, 1.0f);
							ImGui::SliderFloat("fb0 Chromakey Blue", &fb0ChromakeyBlue, 0.0f, 1.0f);
						}
						if (fb0TexmodSwitch == true) {
							ImGui::SliderFloat("texmod fb0 Chromakey Red", &fb0ChromakeyRedTexmod, 0.0f, 1.0f);
							ImGui::SliderFloat("texmod fb0 Chromakey Green", &fb0ChromakeyGreenTexmod, 0.0f, 1.0f);
							ImGui::SliderFloat("texmod fb0 Chromakey Blue", &fb0ChromakeyBlueTexmod, 0.0f, 1.0f);
						}
						ImGui::ColorButton("testingColorButton", ImVec4(fb0ChromakeyRed, fb0ChromakeyGreen, fb0ChromakeyBlue, 1.0), 0, ImVec2(20, 20));
					}
					if (fb0KeyMode !=2) {
						if (fb0TexmodSwitch == false) {
							ImGui::SliderFloat("fb0 key threshold", &fb0KeyThreshold, 0.0f, rootThree);
							ImGui::SliderFloat("fb0 key soft", &fb0KeySoft, 0.0f, 1.0f);
						}
						if (fb0TexmodSwitch == true) {
							ImGui::SliderFloat("texmod fb0 key threshold", &fb0KeyThresholdTexmod, .0f, rootThree);
							ImGui::SliderFloat("texmod fb0 key soft", &fb0KeySoftTexmod, 0.0f, 1.0f);
						}
					}
					if (fb0KeyMode == 2) {
						//when wipe pattern is selected we need to change chroma/lumakey values to 0
						fb0LumakeyLevel = 0;
						fb0KeyThreshold = 0;
						fb0ChromakeyRed = 0;
						fb0ChromakeyGreen = 0;
						fb0ChromakeyBlue = 0;
						fb0KeySoft = 0;

						//drop down menu for mask selection
						const char* items4[] = { "mask1","mask2","mask3","mask4","texMod" };
						ImGui::Combo("fb0 mask select", &item_current4, items4, IM_ARRAYSIZE(items4));
						fb0MaskSelect = item_current4;

						//want to figure out way to get variables in here as to global width
						if (fb0MaskSelect != 4) {
							if (fb0TexmodSwitch == false) {
								ImGui::SliderFloat("fb0 mask x", &fb0MaskX, -outWidth * .5f, outWidth*.5f);
								ImGui::SliderFloat("fb0 mask y", &fb0MaskY, -outHeight * .5f, outHeight*.5f);
								ImGui::SliderFloat("fb0 mask z", &fb0MaskZ, 0.0f, 3.0f);
								ImGui::SliderFloat("fb0 mask rotate", &fb0MaskRotate, -TWO_PI, TWO_PI);
								ImGui::SliderFloat("fb0 mask tile amount", &fb0MaskTileAmount, 0.0f, 2.0f);
							}
							if(fb0TexmodSwitch == true) {
								ImGui::SliderFloat("texmod fb0 mask x", &fb0MaskXTexmod, -outWidth * .5f, outWidth*.5f);
								ImGui::SliderFloat("texmod fb0 mask y", &fb0MaskYTexmod, -outHeight * .5f, outHeight*.5f);
								ImGui::SliderFloat("texmod fb0 mask z", &fb0MaskZTexmod, -3.0f, 3.0f);
								ImGui::SliderFloat("texmod fb0 mask rotate", &fb0MaskRotateTexmod, -TWO_PI, TWO_PI);
								ImGui::SliderFloat("texmod fb0 mask tile amount", &fb0MaskTileAmountTexmod, -2.0f, 2.0f);
							}
							const char* items5[] = { "Off","Basic","basic alt rotate","spiral" };
							ImGui::Combo("fb0 mask tile Mode", &item_current5, items5, IM_ARRAYSIZE(items5));
							fb0MaskTileMode = item_current5;
						}
						if (fb0MaskSelect == 4) {
							ImGui::SliderFloat("fb0 mask texmod offset", &fb0MaskTexmodOffset, -1.0f, 1.0f);
							ImGui::SliderFloat("fb0 mask texmod quantize mix", &fb0MaskTexmodQuantizeMix, .0f, 1.0f);
							ImGui::SliderInt("fb0 mask texmod quantize amount", &fb0MaskTexmodQuantizeAmount, 1, 32);
						}
                    }
                }
                if (ImGui::CollapsingHeader("color space 1")){
					static int item_current0 = 0;
					static int item_current1 = 0;
					if (ImGui::TreeNode(" color 1 ranges")) {
						ImGui::SliderFloat("fb0 hue offset range", &fb0HueOffsetRange, .0001f, 2.0f);
						ImGui::SliderFloat("fb0 saturation offset range", &fb0SaturationOffsetRange, .0001f, 2.0f);
						ImGui::SliderFloat("fb0 bright offset range", &fb0BrightOffsetRange, .0001f, 2.0f);
						ImGui::SliderFloat("fb0 hue attenuate range", &fb0HueAttenuateRange, .0001f, 20.0f);
						ImGui::SliderFloat("fb0 saturation attenuate range", &fb0SaturationAttenuateRange, .0001f, 20.0f);
						ImGui::SliderFloat("fb0 bright attenuate range", &fb0BrightAttenuateRange, .0001f, 20.0f);
						ImGui::SliderFloat("fb0 hue Shaper range", &fb0HueShaperRange, .0001f, 5.0f);
						ImGui::SliderFloat("fb0 hue powmap range", &fb0HuePowMapRange, .0001f, 5.0f);
						ImGui::SliderFloat("fb0 saturation powmap range", &fb0SaturationPowMapRange, .0001f, 20.0f);
						ImGui::SliderFloat("fb0 bright powmap range", &fb0BrightPowMapRange, .0001f, 20.0f);
						ImGui::TreePop();
					}
					if ( (ImGui::Button("reset color 1"))  ) {
						fb0HueOffset = 0.0;
						fb0SaturationOffset = 0.0;
						fb0BrightOffset = 0.0;
						fb0HueAttenuate = 10.0;
						fb0SaturationAttenuate = 10.0;
						fb0BrightAttenuate = 10.0;
						fb0HueShaper = 0.0;
                        fb0HuePowMap= 1.0;
                        fb0SaturationPowMap = 1.0;
                        fb0BrightPowMap = 1.0;
						fb0HueInvert = 0;
						fb0SaturationInvert = 0;
						fb0BrightInvert = 0;

						fb0HueShaperRange = 0.25;
						fb0HueOffsetRange = .25;
						fb0SaturationOffsetRange = 0.25;
						fb0BrightOffsetRange = 0.25;
						fb0HueAttenuateRange = 2.0;
						fb0SaturationAttenuateRange = 2.0;
						fb0BrightAttenuateRange = 2.0;

						fb0HueInvert = 0;
						fb0SaturationInvert = 0;
						fb0BrightInvert = 0;

						fb0SaturationOverflow = 0;
						fb0BrightOverflow = 0;
						fb0HuePowMapRange = .25;
						fb0SaturationPowMapRange = .25;
						fb0BrightPowMapRange = .25;

						fb0HueOffsetTexmod = 0.0;
						fb0SaturationOffsetTexmod = 0.0;
						fb0BrightOffsetTexmod = 0.0;
						fb0HueAttenuateTexmod = 0.0;
						fb0SaturationAttenuateTexmod = 0.0;
						fb0BrightAttenuateTexmod = 0.0;
						fb0HueShaperTexmod = 0.0;
						fb0HuePowMapTexmod = .0;
						fb0SaturationPowMapTexmod = .0;
						fb0BrightPowMapTexmod = .0;

					}

					//EASTER EGG
					//some combination of keypresses adds 1. crt overlay, 2. pixels in SD aspect ratio, 3. enuf dither to look like scanlines
					//4. interlacing
                      if(fb0TexmodSwitch==false){
						  ImGui::SliderFloat("fb0 hue offset",&fb0HueOffset,-fb0HueOffsetRange,fb0HueOffsetRange);
						  ImGui::SliderFloat("fb0 saturation offset", &fb0SaturationOffset, -fb0SaturationOffsetRange, fb0SaturationOffsetRange);
						  ImGui::SliderFloat("fb0 bright offset", &fb0BrightOffset, -fb0BrightOffsetRange, fb0BrightOffsetRange);
                          ImGui::SliderFloat("fb0 hue attenuate", &fb0HueAttenuate, 10.0f-fb0HueAttenuateRange, 10.0f+fb0HueAttenuateRange);
                          ImGui::SliderFloat("fb0 saturation attenuate", &fb0SaturationAttenuate, 10.0f - fb0SaturationAttenuateRange, 10.0f + fb0SaturationAttenuateRange);
                          ImGui::SliderFloat("fb0 bright attenuate", &fb0BrightAttenuate, 10.0f - fb0BrightAttenuateRange, 10.0f + fb0BrightAttenuateRange);
						  ImGui::SliderFloat("fb0 hue Shaper", &fb0HueShaper, -fb0HueShaperRange, fb0HueShaperRange);
						  ImGui::SliderFloat("fb0 hue powmap", &fb0HuePowMap, 1.0f - fb0HuePowMapRange, 1.0f + fb0HuePowMapRange);
						  ImGui::SliderFloat("fb0 saturation powmap", &fb0SaturationPowMap, 1.0f - fb0SaturationPowMapRange, 1.0f + fb0SaturationPowMapRange);
						  ImGui::SliderFloat("fb0 bright powmap", &fb0BrightPowMap, 1.0f-fb0BrightPowMapRange, 1.0f+fb0BrightPowMapRange);
                      }
					  if (fb0TexmodSwitch == true) {
						  ImGui::SliderFloat("texmod fb0 hue offset", &fb0HueOffsetTexmod, -fb0HueOffsetRange * .1f, fb0HueOffsetRange*.1f);
						  ImGui::SliderFloat("texmod fb0 saturation offset", &fb0SaturationOffsetTexmod, -fb0SaturationOffsetRange * .1f, fb0SaturationOffsetRange*.1f);
						  ImGui::SliderFloat("texmod fb0 bright offset", &fb0BrightOffsetTexmod, -fb0BrightOffsetRange * .1f, fb0BrightOffsetRange*.1f);
						  ImGui::SliderFloat("texmod fb0HueAttenuate", &fb0HueAttenuateTexmod, -fb0HueAttenuateRange * .1f, fb0HueAttenuateRange*.1f);
						  ImGui::SliderFloat("texmod fb0SaturationAttenuate", &fb0SaturationAttenuateTexmod, -fb0SaturationAttenuateRange * .1f, fb0SaturationAttenuateRange*.1f);
						  ImGui::SliderFloat("texmod fb0BrightAttenuate", &fb0BrightAttenuateTexmod, -fb0BrightAttenuateRange * .1f, fb0BrightAttenuateRange*.1f);
						  ImGui::SliderFloat("texmod fb0 hue Shaper", &fb0HueShaperTexmod, -fb0HueShaperRange * .1f, fb0HueShaperRange*.1f);
						  ImGui::SliderFloat("texmod fb0 hue powmap", &fb0HuePowMapTexmod, -fb0HuePowMapRange, fb0HuePowMapRange);
						  ImGui::SliderFloat("texmod fb0 saturation powmap", &fb0SaturationPowMapTexmod, -fb0SaturationPowMapRange, fb0SaturationPowMapRange);
						  ImGui::SliderFloat("texmod fb0 bright powmap", &fb0BrightPowMapTexmod, -fb0BrightPowMapRange, fb0BrightPowMapRange);
					  }
					  ImGui::Checkbox("fb0HueInvert", &fb0HueInvert);
					  ImGui::Checkbox("fb0SaturationInvert", &fb0SaturationInvert);
					  ImGui::Checkbox("fb0BrightInvert", &fb0BrightInvert);

					  const char* items0[] = { "clamp","wrap","fold" };
					  ImGui::Combo("saturation overflow", &item_current0, items0, IM_ARRAYSIZE(items0));
					  fb0SaturationOverflow = item_current0;
					  const char* items1[] = { "clamp","wrap","fold" };
					  ImGui::Combo("bright overflow", &item_current1, items1, IM_ARRAYSIZE(items1));
					  fb0BrightOverflow = item_current1;
					  //add wrap, fold, clamp for colors
                 }
				if (ImGui::CollapsingHeader("color space 2")) {
					if (ImGui::TreeNode(" color 2 ranges")) {
						ImGui::SliderInt("fb0 hue dither range", &fb0HueDitherRange, 1, 512);
						ImGui::SliderInt("fb0 saturation dither range", &fb0SaturationDitherRange, 1, 512);
						ImGui::SliderInt("fb0 bright dither range", &fb0BrightDitherRange, 1, 512);
						ImGui::SliderInt("fb0 hue quantize range", &fb0HueQuantizeRange, 1, 512);
						ImGui::SliderInt("fb0 saturation quantize range", &fb0SaturationQuantizeRange, 1, 512);
						ImGui::SliderInt("fb0 bright quantize range", &fb0BrightQuantizeRange, 1, 512);
						ImGui::TreePop();
					}
					if ( (ImGui::Button("reset color 2"))  ) {
						fb0HueQuantize = 128;
						fb0SaturationQuantize = 128;
						fb0BrightQuantize = 128;
						fb0HueQuantizeMix = 0.0;
						fb0SaturationQuantizeMix = 0.0;
						fb0BrightQuantizeMix = 0.0;
						fb0HueDitherMix = 0.0;
						fb0HueDitherAmount = 64;
						fb0SaturationDitherMix = 0.0;
						fb0SaturationDitherAmount = 64;
						fb0BrightDitherMix = 0.0;
						fb0BrightDitherAmount = 64;

						fb0HueQuantizeTexmod = 0;
						fb0SaturationQuantizeTexmod = 0;
						fb0BrightQuantizeTexmod = 0;
						fb0HueQuantizeMixTexmod = 0.0;
						fb0SaturationQuantizeMixTexmod = 0.0;
						fb0BrightQuantizeMixTexmod = 0.0;
						fb0HueDitherMixTexmod = 0.0;
						fb0HueDitherAmountTexmod = 0;
						fb0SaturationDitherMixTexmod = 0.0;
						fb0SaturationDitherAmountTexmod = 0;
						fb0BrightDitherMixTexmod = 0.0;
						fb0BrightDitherAmountTexmod = 0;
					}
					if (fb0TexmodSwitch == false) {
						ImGui::SliderFloat("fb0 hue quantize mix", &fb0HueQuantizeMix, .0f, 1.0f);
						ImGui::SliderInt("fb0 hue quantize amount", &fb0HueQuantize, 1, fb0HueQuantizeRange);
						ImGui::SliderFloat("fb0 saturation quantize mix", &fb0SaturationQuantizeMix, .0f, 1.0f);
						ImGui::SliderInt("fb0 saturation quantize amount", &fb0SaturationQuantize, 1, fb0SaturationQuantizeRange);
						ImGui::SliderFloat("fb0 bright quantize mix", &fb0BrightQuantizeMix, .0f, 1.0f);
						ImGui::SliderInt("fb0 bright quantize amount", &fb0BrightQuantize, 1, fb0BrightQuantizeRange);
						ImGui::SliderFloat("fb0 hue dither mix", &fb0HueDitherMix, .0f, 1.0f);
						ImGui::SliderInt("fb0 hue dither amount", &fb0HueDitherAmount, 1, fb0HueDitherRange);
						ImGui::SliderFloat("fb0 saturation dither mix", &fb0SaturationDitherMix, .0f, 1.0f);
						ImGui::SliderInt("fb0 saturation dither amount", &fb0SaturationDitherAmount, 1, fb0SaturationDitherRange);
						ImGui::SliderFloat("fb0 bright dither mix", &fb0BrightDitherMix, .0f, 1.0f);
						ImGui::SliderInt("fb0 bright dither amount", &fb0BrightDitherAmount, 1, fb0BrightDitherRange);
					}
					if (fb0TexmodSwitch == true) {
						/*
						ImGui::SliderFloat("texmod fb0 hue quantize mix", &fb0HueQuantizeMixTexmod, .0f, 1.0f);
						ImGui::SliderFloat("texmod fb0 hue quantize amount", &fb0HueQuantizeTexmod, 1, fb0HueQuantizeRange);
						ImGui::SliderFloat("texmod fb0 saturation quantize mix", &fb0SaturationQuantizeMixTexmod, .0f, 1.0f);
						ImGui::SliderFloat("texmod fb0 saturation quantize amount", &fb0SaturationQuantizeTexmod, 1, fb0SaturationQuantizeRange);
						ImGui::SliderFloat("texmod fb0 bright quantize mix", &fb0BrightQuantizeMixTexmod, .0f, 1.0f);
						ImGui::SliderFloat("texmod fb0 bright quantize amount", &fb0BrightQuantizeTexmod, 1, fb0BrightQuantizeRange);
						ImGui::SliderFloat("texmod fb0 hue dither mix", &fb0HueDitherMixTexmod, .0f, 1.0f);
						ImGui::SliderFloat("texmod fb0 hue dither amount", &fb0HueDitherAmountTexmod, 1, fb0HueDitherRange);
						ImGui::SliderFloat("texmod fb0 saturation dither mix", &fb0SaturationDitherMixTexmod, .0f, 1.0f);
						ImGui::SliderFloat("texmod fb0 saturation dither amount", &fb0SaturationDitherAmountTexmod, 1, fb0SaturationDitherRange);
						ImGui::SliderFloat("texmod fb0 bright dither mix", &fb0BrightDitherMixTexmod, .0f, 1.0f);
						ImGui::SliderFloat("texmod fb0 bright dither amount", &fb0BrightDitherAmountTexmod, 1, fb0BrightDitherRange);
						*/
					}
				
				}
                if (ImGui::CollapsingHeader("geometry1")){
					static int item_current2 = 0;
					if (ImGui::TreeNode(" geo 1 ranges")) {
						ImGui::SliderFloat("fb0 x displace range", &fb0XDisplaceRange, .0001f, 200.0f);
						ImGui::SliderFloat("fb0 y displace range", &fb0YDisplaceRange, .0001f, 200.0f);
						ImGui::SliderFloat("fb0 z displace range", &fb0ZDisplaceRange, .0001f, 100.0f);
						ImGui::SliderFloat("fb0 rotate range", &fb0ZRotateRange, .0001f, TWO_PI);
						ImGui::SliderFloat("fb0 shear matrix 1 Range", &fb0ShearMatrixRange.x, .0001f, 5.0f);
						ImGui::SliderFloat("fb0 shear matrix 2 Range", &fb0ShearMatrixRange.y, .0001f, 5.0f);
						ImGui::SliderFloat("fb0 shear matrix 3 Range", &fb0ShearMatrixRange.z, .0001f, 5.0f);
						ImGui::SliderFloat("fb0 shear matrix 4 Range", &fb0ShearMatrixRange.w, .0001f, 5.0f);
						
						ImGui::TreePop();
					}
					if ( ImGui::Button("reset geo1") ) {
						item_current2 = 0;
						fb0XDisplace = 0.0;
						fb0YDisplace = 0.0;
						fb0ZDisplace = 100.0;
						fb0Rotate = 0;
						fb0ShearMatrix.set(0,0,0,0);
						fb0ShearMatrixRange.set(0.25, 0.25, 0.25, 0.25);
						fb0RotateMode = 0;
						fb0HorizontalMirror = 0;
						fb0VerticalMirror = 0;
						fb0XDisplaceRange = 40;
						fb0YDisplaceRange = 40;
						fb0ZDisplaceRange = 10;
						fb0ZRotateRange = PI;
                        
                        fb0XDisplaceTexmod=0.0;
                        fb0YDisplaceTexmod=0.0;
                        fb0ZDisplaceTexmod=0;
                        fb0RotateTexmod=0;
                        fb0ShearMatrixTexmod.set(0,0,0,0);
					}
                    if(fb0TexmodSwitch==false){
                        ImGui::SliderFloat("fb0_x", &fb0XDisplace, -fb0XDisplaceRange, fb0XDisplaceRange);
                        ImGui::SliderFloat("fb0_y", &fb0YDisplace, -fb0YDisplaceRange, fb0YDisplaceRange);
                        ImGui::SliderFloat("fb0_z", &fb0ZDisplace,  100.0f-fb0ZDisplaceRange, 100.0f+fb0ZDisplaceRange);
                        ImGui::SliderFloat("fb0Rotate", &fb0Rotate, -fb0ZRotateRange, fb0ZRotateRange);
						
						ImGui::SliderFloat("fb0 Shear matrix 1", &fb0ShearMatrix.x, -fb0ShearMatrixRange.x, fb0ShearMatrixRange.x);
						ImGui::SliderFloat("fb0 Shear matrix 2", &fb0ShearMatrix.y, -fb0ShearMatrixRange.y, fb0ShearMatrixRange.y);
						ImGui::SliderFloat("fb0 Shear matrix 3", &fb0ShearMatrix.z, -fb0ShearMatrixRange.z, fb0ShearMatrixRange.z);
                        ImGui::SliderFloat("fb0 Shear matrix 4", &fb0ShearMatrix.w, -fb0ShearMatrixRange.w, fb0ShearMatrixRange.w);
					}
                    if(fb0TexmodSwitch==true){
                        ImGui::SliderFloat("texmod fb0_x", &fb0XDisplaceTexmod, -fb0XDisplaceRange, fb0XDisplaceRange);
                        ImGui::SliderFloat("texmod fb0_y", &fb0YDisplaceTexmod,  -fb0YDisplaceRange, fb0YDisplaceRange);
                        ImGui::SliderFloat("texmod fb0_z", &fb0ZDisplaceTexmod,  -fb0ZDisplaceRange*.01, fb0ZDisplaceRange*.01);
                        ImGui::SliderFloat("texmod fb0Rotate", &fb0RotateTexmod, -fb0ZRotateRange, fb0ZRotateRange);
                        
                        ImGui::SliderFloat("texmod fb0 Shear matrix 1", &fb0ShearMatrixTexmod.x, -fb0ShearMatrixRange.x, fb0ShearMatrixRange.x);
                        ImGui::SliderFloat("texmod fb0 Shear matrix 2", &fb0ShearMatrixTexmod.y, -fb0ShearMatrixRange.y, fb0ShearMatrixRange.y);
                        ImGui::SliderFloat("texmod fb0 Shear matrix 3", &fb0ShearMatrixTexmod.z, -fb0ShearMatrixRange.z, fb0ShearMatrixRange.z);
                        ImGui::SliderFloat("texmod fb0 Shear matrix 4", &fb0ShearMatrixTexmod.w, -fb0ShearMatrixRange.w, fb0ShearMatrixRange.w);
                    }
                    const char* items2[] = { "clamp","toroid","mirror" };
                    ImGui::Combo("Geometry overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                    fb0_toroid_switch = item_current2;
                    
                    ImGui::Checkbox("fb0_h_mirror", &fb0HorizontalMirror);
                    ImGui::Checkbox("fb0_v_mirror", &fb0VerticalMirror);
                    ImGui::Checkbox("fb0RotateMode", &fb0RotateMode);
                }
				if (ImGui::CollapsingHeader("geometry2")) {
					if (ImGui::TreeNode("geo 2 ranges")) {
						ImGui::SliderFloat("fb0 fisheye amount range", &fb0FisheyeAmountRange, .0001f, 2.0f);
						ImGui::SliderFloat("fb0 fisheye X range", &fb0FisheyeXRange, .0001f, 10.0f);
						ImGui::SliderFloat("fb0 fisheye Y range", &fb0FisheyeYRange, .0001f, 10.0f);
						ImGui::SliderFloat("fb0 spiral amount range", &fb0SpiralAmountRange, .0001f, 10.0f);
						ImGui::SliderFloat("fb0 spiral angle range", &fb0SpiralAngleRange, .0001f, TWO_PI);
						ImGui::SliderFloat("fb0 spiral X range", &fb0SpiralXRange, .0001f, 10.0f);
						ImGui::SliderFloat("fb0 spiral Y range", &fb0SpiralYRange, .0001f, 10.0f);
						ImGui::SliderInt("fb0 kaleidoscope segments range", &fb0KaleidoscopeSegmentsRange, 1, 100);
						ImGui::SliderFloat("fb0 kaleidoscope slice range", &fb0KaleidoscopeSliceRange,.01,TWO_PI);

						ImGui::TreePop();
					}
					if (ImGui::Button("reset geo2")) {
						fb0FisheyeAmount = 0;
						fb0FisheyeX = 0;
						fb0FisheyeY = 0;
						fb0SpiralAmount = 0;
						fb0SpiralAngle = 0;
						fb0SpiralX = 0;
						fb0SpiralY = 0;
						fb0KaleidoscopeSegments = 0;
						fb0KaleidoscopeSlice = 0;
						
                        fb0FisheyeAmountRange = .15;
                        fb0FisheyeXRange = .25;
                        fb0FisheyeYRange = .25;
                        fb0SpiralAmountRange = .15;
                        fb0SpiralAngleRange = PI;
                        fb0SpiralXRange = .25;
                        fb0SpiralYRange = .25;
                        fb0KaleidoscopeSegmentsRange = 21;
                        fb0KaleidoscopeSliceRange = PI;
                        
                        fb0FisheyeAmountTexmod = 0;
                        fb0FisheyeXTexmod = 0;
                        fb0FisheyeYTexmod = 0;
                        fb0SpiralAmountTexmod = 0;
                        fb0SpiralAngleTexmod = 0;
                        fb0SpiralXTexmod = 0;
                        fb0SpiralYTexmod = 0;
                        fb0KaleidoscopeSegmentsTexmod = 0;
                        fb0KaleidoscopeSliceTexmod = 0;
                        
					}

                    if(fb0TexmodSwitch==false){
                        ImGui::SliderFloat("fb0 fisheye amount", &fb0FisheyeAmount, -fb0FisheyeAmountRange, fb0FisheyeAmountRange);
                        ImGui::SliderFloat("fb0 fisheye x", &fb0FisheyeX, -fb0FisheyeXRange, fb0FisheyeXRange);
                        ImGui::SliderFloat("fb0 fisheye y", &fb0FisheyeY, -fb0FisheyeYRange, fb0FisheyeYRange);

                        ImGui::SliderFloat("fb0 spiral amount", &fb0SpiralAmount, -fb0SpiralAmountRange, fb0SpiralAmountRange);
                        ImGui::SliderFloat("fb0 spiral angle", &fb0SpiralAngle, -fb0SpiralAngleRange, fb0SpiralAngleRange);
                        ImGui::SliderFloat("fb0 spiral x", &fb0SpiralX, -fb0SpiralXRange, fb0SpiralXRange);
                        ImGui::SliderFloat("fb0 spiral y", &fb0SpiralY, -fb0SpiralYRange, fb0SpiralYRange);

                        ImGui::SliderInt("fb0 kaleidoscope segments", &fb0KaleidoscopeSegments, 0, fb0KaleidoscopeSegmentsRange);
                        ImGui::SliderFloat("fb0 kaleidoscope slice", &fb0KaleidoscopeSlice, -fb0KaleidoscopeSliceRange, fb0KaleidoscopeSliceRange);
                    }
                    
                    if(fb0TexmodSwitch==true){
                        ImGui::SliderFloat("texmod fb0 fisheye amount", &fb0FisheyeAmountTexmod, -fb0FisheyeAmountRange, fb0FisheyeAmountRange);
                        ImGui::SliderFloat("texmod fb0 fisheye x", &fb0FisheyeXTexmod, -fb0FisheyeXRange, fb0FisheyeXRange);
                        ImGui::SliderFloat("texmod fb0 fisheye y", &fb0FisheyeYTexmod, -fb0FisheyeYRange, fb0FisheyeYRange);
                        
                        ImGui::SliderFloat("texmod fb0 spiral amount", &fb0SpiralAmountTexmod, -fb0SpiralAmountRange, fb0SpiralAmountRange);
                        ImGui::SliderFloat("texmod fb0 spiral angle", &fb0SpiralAngleTexmod, -fb0SpiralAngleRange, fb0SpiralAngleRange);
                        ImGui::SliderFloat("texmod fb0 spiral x", &fb0SpiralXTexmod, -fb0SpiralXRange, fb0SpiralXRange);
                        ImGui::SliderFloat("texmod fb0 spiral y", &fb0SpiralYTexmod, -fb0SpiralYRange, fb0SpiralYRange);
                        
                        ImGui::SliderFloat("texmod fb0 kaleidoscope segments", &fb0KaleidoscopeSegmentsTexmod, 0, fb0KaleidoscopeSegmentsRange);
                        ImGui::SliderFloat("texmod fb0 kaleidoscope slice", &fb0KaleidoscopeSliceTexmod, -fb0KaleidoscopeSliceRange, fb0KaleidoscopeSliceRange);
                    }
                    
                }

				//ADD THE PIXELS HERE
				if (ImGui::CollapsingHeader("pixelate"))
				{
					if (ImGui::Button("reset pixelate")) {
						fb0PixelXYLock = 1;
						fb0XPixelScale = 64;
						fb0YPixelScale = 64;
						fb0PixelMix = 1;
						fb0PixelBrightscale = 0;
                        
                        fb0XPixelScaleTexmod=0;
                        fb0YPixelScaleTexmod=0;
                        fb0PixelMixTexmod=0;
                        fb0PixelBrightscaleTexmod=0;
					}
					ImGui::Checkbox("fb0 pixelate", &fb0PixelSwitch);
					ImGui::Checkbox("fb0 pixelXY lock", &fb0PixelXYLock);
					
					if (fb0TexmodSwitch == false) {
						ImGui::SliderInt("fb0 pixel scale x", &fb0XPixelScale, .0f, 256.0f);
						if (fb0PixelXYLock == 1) {
							ImGui::SliderInt("fb0 pixel scale y", &fb0XPixelScale, .0f, 256.0f);
						}
						if (fb0PixelXYLock == 0) {
							ImGui::SliderInt("fb0 pixel scale y", &fb0YPixelScale, .0f, 256.0f);
						}
						ImGui::SliderFloat("fb0 pixel mix", &fb0PixelMix, -2.0f, 2.0f);
						ImGui::SliderFloat("fb0 bright scale", &fb0PixelBrightscale, -2.0f, 2.0f);
					}
					if (fb0TexmodSwitch == true) {
						ImGui::SliderInt("fb0 texmod pixel scale x", &fb0XPixelScaleTexmod, -256.0f, 256.0f);
                        if (fb0PixelXYLock == 1) {
                            ImGui::SliderInt("fb0 texmod pixel scale y", &fb0XPixelScaleTexmod, -256.0f, 256.0f);
                        }
                        if (fb0PixelXYLock == 0) {
                            ImGui::SliderInt("fb0 texmod pixel scale y", &fb0YPixelScaleTexmod, -256.0f, 256.0f);
                        }
                        ImGui::SliderFloat("fb0 texmod pixel mix", &fb0PixelMixTexmod, -2.0f, 2.0f);
						ImGui::SliderFloat("fb0 texmod bright scale", &fb0PixelBrightscaleTexmod, -2.0f, 2.0f);
					}
				}
            }//end collapsing folder
            ImGui::Separator();
            if (ImGui::CollapsingHeader("L F O s")){
               ImGui::Text("Loose Floating Object s");
			   if (ImGui::Button("reset lfo")) {
				   fb0ResetAllLfo();
			   }
                if (ImGui::CollapsingHeader("mix and delay amount lfo")){
					if (ImGui::Button("reset mix and delay lfo")) {
						fb0_delay_lfo_theta = 0;
						fb0DelayLfoAmp = 0;
						fb0MixLfoTheta = 0;
						fb0MixLfoAmp = 0;
						fb0LumakeyLevelLfoTheta = 0;
						fb0LumakeyLevelLfoAmp = 0;
						fb0ChromakeyRedLfoTheta = 0;
						fb0ChromakeyRedLfoAmp = 0;
						fb0ChromakeyGreenLfoTheta = 0;
						fb0ChromakeyGreenLfoAmp = 0;
						fb0ChromakeyBlueLfoTheta = 0;
						fb0ChromakeyBlueLfoAmp = 0;
						fb0KeyThresholdLfoTheta = 0;
						fb0KeyThresholdLfoAmp = 0;
						fb0KeySoftLfoTheta = 0;
						fb0KeySoftLfoAmp = 0;
						fb0MaskXLfoTheta = 0;
						fb0MaskXLfoAmp = 0;
						fb0MaskYLfoTheta = 0;
						fb0MaskYLfoAmp = 0;
						fb0MaskZLfoTheta = 0.0;
						fb0MaskZLfoAmp = 0.0;
						fb0MaskRotateLfoTheta = 0;
						fb0MaskRotateLfoAmp = 0;
						fb0MaskTileAmountLfoTheta = 0.0;
						fb0MaskTileAmountLfoAmp = 0.0;
						fb0MaskTexmodOffsetLfoTheta = 0;
						fb0MaskTexmodOffsetLfoAmp = 0;
						fb0MaskTexmodQuantizeAmountLfoTheta = 0.0;
						fb0MaskTexmodQuantizeAmountLfoAmp = 0.0;
						fb0MaskTexmodQuantizeMixLfoTheta = 0.0;
						fb0MaskTexmodQuantizeMixLfoAmp = 0.0;
					}
					ImGui::SliderFloat("fb0DelayLfoRate", &fb0_delay_lfo_theta, .0f, 10.0f);
					ImGui::SliderFloat("fb0DelayLfoAmp", &fb0DelayLfoAmp, -1.0f, 1.0f);
					ImGui::SliderFloat("fb0MixLfoRate", &fb0MixLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0MixLfoAmp", &fb0MixLfoAmp, -2.0f, 2.0f);
					//Not Wipes
					if (fb0KeyMode != 2) {
						//luma
						if (fb0KeyMode == 0) {
							ImGui::SliderFloat("fb0LumakeyLevelLfoRate", &fb0LumakeyLevelLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0LumakeyLevelLfoAmp", &fb0LumakeyLevelLfoAmp, -1.0f, 1.0f);
						}
						if (fb0KeyMode == 1) {
							ImGui::SliderFloat("fb0ChromakeyRedLfoRate", &fb0ChromakeyRedLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0ChromakeyRedLfoAmp", &fb0ChromakeyRedLfoAmp, -1.0f, 1.0f);
							ImGui::SliderFloat("fb0ChromakeyGreenLfoRate", &fb0ChromakeyGreenLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0ChromakeyGreenLfoAmp", &fb0ChromakeyGreenLfoAmp, -1.0f, 1.0f);
							ImGui::SliderFloat("fb0ChromakeyBlueLfoRate", &fb0ChromakeyBlueLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0ChromakeyBlueLfoAmp", &fb0ChromakeyBlueLfoAmp, -1.0f, 1.0f);
						}
						ImGui::SliderFloat("fb0Keythreshold_lfo_rate", &fb0KeyThresholdLfoTheta, .0f, lfom);
						ImGui::SliderFloat("fb0KeyThresholdLfoAmp", &fb0KeyThresholdLfoAmp, -rootThree, rootThree);
						ImGui::SliderFloat("fb0KeySoftLfoRate", &fb0KeySoftLfoTheta, .0f, lfom);
						ImGui::SliderFloat("fb0KeySoftLfoAmp", &fb0KeySoftLfoAmp, -1.0, 1.0);
					}
					if (fb0KeyMode == 2) {
						fb0ChromakeyRedLfoAmp = 0;
						fb0ChromakeyGreenLfoAmp = 0;
						fb0ChromakeyBlueLfoAmp = 0;
						fb0LumakeyLevelLfoAmp = 0;
						fb0KeyThresholdLfoAmp = 0;
						//regular wipes
						if (fb0MaskSelect != 4) {
							ImGui::SliderFloat("fb0MaskXLfoRate", &fb0MaskXLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0MaskXLfoAmp", &fb0MaskXLfoAmp, -outWidth * .5f, outWidth*.5f);
							ImGui::SliderFloat("fb0MaskYLfoRate", &fb0MaskYLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0MaskYLfoAmp", &fb0MaskYLfoAmp, -outHeight * .5f, outHeight*.5f);
							ImGui::SliderFloat("fb0MaskZLfoRate", &fb0MaskZLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0MaskZLfoAmp", &fb0MaskZLfoAmp, -3.0f, 3.0f);
							ImGui::SliderFloat("fb0MaskRotateLfoRate", &fb0MaskRotateLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0MaskRotateLfoAmp", &fb0MaskRotateLfoAmp, -TWO_PI, TWO_PI);
							ImGui::SliderFloat("fb0MaskTileAmountLfoRate", &fb0MaskTileAmountLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0MaskTileAmountLfoAmp", &fb0MaskTileAmountLfoAmp, -3.0f, 3.0f);
						}
						//texmodWipes
						if (fb0MaskSelect == 4) {
							ImGui::SliderFloat("fb0MaskTexmodOffsetLfoRate", &fb0MaskTexmodOffsetLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0MaskTexmodOffsetLfoAmp", &fb0MaskTexmodOffsetLfoAmp, -1.0, 1.0);
							ImGui::SliderFloat("fb0MaskTexmodQuantizeAmountLfoRate", &fb0MaskTexmodQuantizeAmountLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0MaskTexmodQuantizeAmountLfoAmp", &fb0MaskTexmodQuantizeAmountLfoAmp, 0.0, 32.0);
							ImGui::SliderFloat("fb0MaskTexmodQuantizeMixLfoRate", &fb0MaskTexmodQuantizeMixLfoTheta, .0f, lfom);
							ImGui::SliderFloat("fb0MaskTexmodQuantizeMixLfoAmp", &fb0MaskTexmodQuantizeMixLfoAmp, 0.0, 1.0);
						}
					}
                }
                if (ImGui::CollapsingHeader("color1  lfo")){
					if (ImGui::Button("reset color1 lfo")) {
						fb0HueOffsetLfoTheta = 0.0;
						fb0SaturationOffsetLfoTheta = 0.0;
						fb0BrightOffsetLfoTheta = 0.0;
						fb0HueAttenuateLfoTheta = 0.0;
						fb0SaturationAttenuateLfoTheta = 0.0;
						fb0BrightAttenuateLfoTheta = 0.0;
						fb0HueShaperLfoTheta = 0.0;
						fb0HuePowMapLfoTheta = 0;
						fb0SaturationPowMapLfoTheta = .0;
						fb0BrightPowMapLfoTheta = .0;

						fb0HueOffsetLfoAmp = 0.0;
						fb0SaturationOffsetLfoAmp = 0.0;
						fb0BrightOffsetLfoAmp = 0.0;
						fb0HueAttenuateLfoAmp = 0.0;
						fb0SaturationAttenuateLfoAmp = 0.0;
						fb0BrightAttenuateLfoAmp = 0.0;
						fb0HueShaperLfoAmp = 0.0;
						fb0HuePowMapLfoAmp = 0;
						fb0SaturationPowMapLfoAmp = .0;
						fb0BrightPowMapLfoAmp = .0;
					}

					ImGui::SliderFloat("fb0HueOffsetLfo_rate", &fb0HueOffsetLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0HueOffsetLfoAmp", &fb0HueOffsetLfoAmp, -fb0HueOffsetRange, fb0HueOffsetRange);
					ImGui::SliderFloat("fb0SaturationOffset_lfo_rate", &fb0SaturationOffsetLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0SaturationOffsetLfoAmp", &fb0SaturationOffsetLfoAmp, -fb0SaturationOffsetRange, fb0SaturationOffsetRange);
					ImGui::SliderFloat("fb0BrightOffset_lfo_rate", &fb0BrightOffsetLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0BrightOffsetLfoAmp", &fb0BrightOffsetLfoAmp, -fb0BrightOffsetRange, fb0BrightOffsetRange);
                    ImGui::Separator();
                    ImGui::SliderFloat("fb0HueAttenuateLfo_rate", &fb0HueAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb0HueAttenuateLfoAmp", &fb0HueAttenuateLfoAmp, -fb0HueAttenuateRange, fb0HueAttenuateRange);
                    ImGui::SliderFloat("fb0SaturationAttenuate_lfo_rate", &fb0SaturationAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb0SaturationAttenuateLfoAmp", &fb0SaturationAttenuateLfoAmp, -fb0SaturationAttenuateRange, fb0SaturationAttenuateRange);
                    ImGui::SliderFloat("fb0BrightAttenuate_lfo_rate", &fb0BrightAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb0BrightAttenuateLfoAmp", &fb0BrightAttenuateLfoAmp, -fb0BrightAttenuateRange, fb0BrightAttenuateRange);
                    ImGui::Separator();
					ImGui::SliderFloat("fb0HueShaperLfo_rate", &fb0HueShaperLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0HueShaperLfoAmp", &fb0HueShaperLfoAmp, -fb0HueShaperRange, fb0HueShaperRange);

					ImGui::SliderFloat("fb0HuePowMapLfo_rate", &fb0HuePowMapLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0HuePowMapLfoAmp", &fb0HuePowMapLfoAmp, -fb0HuePowMapRange, fb0HuePowMapRange);
					ImGui::SliderFloat("fb0SaturationPowMap_lfo_rate", &fb0SaturationPowMapLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0SaturationPowMapLfoAmp", &fb0SaturationPowMapLfoAmp, -fb0SaturationPowMapRange, fb0SaturationPowMapRange);
					ImGui::SliderFloat("fb0BrightPowMap_lfo_rate", &fb0BrightPowMapLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0BrightPowMapLfoAmp", &fb0BrightPowMapLfoAmp, -fb0BrightPowMapRange, fb0BrightPowMapRange);
     
				}
				if (ImGui::CollapsingHeader("color2  lfo")) {
					if (ImGui::Button("reset color2 lfo")) {
						fb0HueQuantizeLfoTheta = 0;
						fb0SaturationQuantizeLfoTheta = 0;
						fb0BrightQuantizeLfoTheta = 0;
						fb0HueQuantizeMixLfoTheta = 0.0;
						fb0SaturationQuantizeMixLfoTheta = 0.0;
						fb0BrightQuantizeMixLfoTheta = 0.0;
						fb0HueDitherMixLfoTheta = 0.0;
						fb0HueDitherAmountLfoTheta = 0;
						fb0SaturationDitherMixLfoTheta = 0.0;
						fb0SaturationDitherAmountLfoTheta = 0;
						fb0BrightDitherMixLfoTheta = 0.0;
						fb0BrightDitherAmountLfoTheta = 0;

						fb0HueQuantizeLfoAmp = 0;
						fb0SaturationQuantizeLfoAmp = 0;
						fb0BrightQuantizeLfoAmp = 0;
						fb0HueQuantizeMixLfoAmp = 0.0;
						fb0SaturationQuantizeMixLfoAmp = 0.0;
						fb0BrightQuantizeMixLfoAmp = 0.0;
						fb0HueDitherMixLfoAmp = 0.0;
						fb0HueDitherAmountLfoAmp = 0;
						fb0SaturationDitherMixLfoAmp = 0.0;
						fb0SaturationDitherAmountLfoAmp = 0;
						fb0BrightDitherMixLfoAmp = 0.0;
						fb0BrightDitherAmountLfoAmp = 0;
					}
                    if (ImGui::CollapsingHeader("quantize lfos")) {
                        ImGui::SliderFloat("fb0HueQuantizeMixLfo_rate", &fb0HueQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0HueQuantizeMixLfoAmp", &fb0HueQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb0HueQuantizeLfo_rate", &fb0HueQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0HueQuantizeLfoAmp", &fb0HueQuantizeLfoAmp, -fb0HueQuantizeRange, fb0HueQuantizeRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb0SaturationQuantizeMix_lfo_rate", &fb0SaturationQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0SaturationQuantizeMixLfoAmp", &fb0SaturationQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb0SaturationQuantize_lfo_rate", &fb0SaturationQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0SaturationQuantizeLfoAmp", &fb0SaturationQuantizeLfoAmp, -fb0SaturationQuantizeRange, fb0SaturationQuantizeRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb0BrightQuantizeMix_lfo_rate", &fb0BrightQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0BrightQuantizeMixLfoAmp", &fb0BrightQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb0BrightQuantize_lfo_rate", &fb0BrightQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0BrightQuantizeLfoAmp", &fb0BrightQuantizeLfoAmp, -fb0BrightQuantizeRange, fb0BrightQuantizeRange);
                    }
                    ImGui::Separator();
                    if (ImGui::CollapsingHeader("dither lfos")) {
                        ImGui::SliderFloat("fb0HueDitherMixLfo_rate", &fb0HueDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0HueDitherMixLfoAmp", &fb0HueDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb0HueDitherLfo_rate", &fb0HueDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0HueDitherLfoAmp", &fb0HueDitherAmountLfoAmp, -fb0HueDitherRange, fb0HueDitherRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb0SaturationDitherMix_lfo_rate", &fb0SaturationDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0SaturationDitherMixLfoAmp", &fb0SaturationDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb0SaturationDither_lfo_rate", &fb0SaturationDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0SaturationDitherLfoAmp", &fb0SaturationDitherAmountLfoAmp, -fb0SaturationDitherRange, fb0SaturationDitherRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb0BrightDitherMix_lfo_rate", &fb0BrightDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0BrightDitherMixLfoAmp", &fb0BrightDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb0BrightDither_lfo_rate", &fb0BrightDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb0BrightDitherLfoAmp", &fb0BrightDitherAmountLfoAmp, -fb0BrightDitherRange, fb0BrightDitherRange);
                    }
				}
                if (ImGui::CollapsingHeader("geo1 lfo")){
					if (ImGui::Button("reset geo1 lfo")) {
						 fb0XDisplaceLfoTheta = 0.0;
						 fb0YDisplaceLfoTheta = 0.0;
						 fb0ZDisplaceLfoTheta = 0.0;
						 fb0RotateLfoTheta = 0;
						 fb0ShearMatrixLfoTheta.set(0,0,0,0);

						 fb0XDisplaceLfoAmp = 0.0;
						 fb0YDisplaceLfoAmp = 0.0;
						 fb0ZDisplaceLfoAmp = 0.0;
						 fb0RotateLfoAmp = 0;
						 fb0ShearMatrixLfoAmp.set(0, 0, 0, 0);
					}
                    ImGui::SliderFloat("fb0XDisplace_lfo_rate", &fb0XDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb0XDisplace_lfo_amp", &fb0XDisplaceLfoAmp, -fb0XDisplaceRange, fb0XDisplaceRange);
                    ImGui::SliderFloat("fb0YDisplace_lfo_rate", &fb0YDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb0YDisplace_lfo_amp", &fb0YDisplaceLfoAmp, -fb0YDisplaceRange, fb0YDisplaceRange);
                    ImGui::SliderFloat("fb0ZDisplace_lfo_rate", &fb0ZDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb0ZDisplace_lfo_amp", &fb0ZDisplaceLfoAmp, -fb0ZDisplaceRange, fb0ZDisplaceRange);
                    ImGui::SliderFloat("fb0Rotate_lfo_rate", &fb0RotateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb0RotateLfoAmp", &fb0RotateLfoAmp, -fb0ZRotateRange, fb0ZRotateRange);

					ImGui::SliderFloat("fb0 Shear matrix 1 lfo rate", &fb0ShearMatrixLfoTheta.x, .0f, lfom);
					ImGui::SliderFloat("fb0 Shear matrix 1 lfo amp", &fb0ShearMatrixLfoAmp.x, -fb0ShearMatrixRange.x, fb0ShearMatrixRange.x);
					ImGui::SliderFloat("fb0 Shear matrix 2 lfo rate", &fb0ShearMatrixLfoTheta.y, .0f, lfom);
					ImGui::SliderFloat("fb0 Shear matrix 2 lfo amp", &fb0ShearMatrixLfoAmp.y, -fb0ShearMatrixRange.y, fb0ShearMatrixRange.y);
					ImGui::SliderFloat("fb0 Shear matrix 3 lfo rate", &fb0ShearMatrixLfoTheta.z, .0f, lfom);
					ImGui::SliderFloat("fb0 Shear matrix 3 lfo amp", &fb0ShearMatrixLfoAmp.z, -fb0ShearMatrixRange.z, fb0ShearMatrixRange.z);
					ImGui::SliderFloat("fb0 Shear matrix 4 lfo rate", &fb0ShearMatrixLfoTheta.w, .0f, lfom);
					ImGui::SliderFloat("fb0 Shear matrix 4 lfo amp", &fb0ShearMatrixLfoAmp.w, -fb0ShearMatrixRange.w, fb0ShearMatrixRange.w);
                }
				if (ImGui::CollapsingHeader("geo2 lfo")) {
					if (ImGui::Button("reset geo2 lfo")) {
						fb0FisheyeAmountLfoTheta = 0;
						fb0FisheyeXLfoTheta = 0;
						fb0FisheyeYLfoTheta = 0;
						fb0SpiralAmountLfoTheta = 0;
						fb0SpiralAngleLfoTheta = 0;
						fb0SpiralXLfoTheta = 0;
						fb0SpiralYLfoTheta = 0;
						fb0KaleidoscopeSegmentsLfoTheta = 0;
						fb0KaleidoscopeSliceLfoTheta = 0;

						fb0FisheyeAmountLfoAmp = 0;
						fb0FisheyeXLfoAmp = 0;
						fb0FisheyeYLfoAmp = 0;
						fb0SpiralAmountLfoAmp = 0;
						fb0SpiralAngleLfoAmp = 0;
						fb0SpiralXLfoAmp = 0;
						fb0SpiralYLfoAmp = 0;
						fb0KaleidoscopeSegmentsLfoAmp = 0;
						fb0KaleidoscopeSliceLfoAmp = 0;
					}
					//geo 2 lfos
					ImGui::SliderFloat("fb0 fisheye amount lfo rate", &fb0FisheyeAmountLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0 fisheye amount lfo amp", &fb0FisheyeAmountLfoAmp, -fb0FisheyeAmountRange, fb0FisheyeAmountRange);
					ImGui::SliderFloat("fb0 fisheye x lfo rate", &fb0FisheyeXLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0 fisheye x lfo amp", &fb0FisheyeXLfoAmp, -fb0FisheyeXRange, fb0FisheyeXRange);
					ImGui::SliderFloat("fb0 fisheye y lfo rate", &fb0FisheyeYLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0 fisheye y lfo amp", &fb0FisheyeYLfoAmp, -fb0FisheyeYRange, fb0FisheyeYRange);

					ImGui::SliderFloat("fb0 spiral amount lfo rate", &fb0SpiralAmountLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0 spiral amount lfo amp", &fb0SpiralAmountLfoAmp, -fb0SpiralAmountRange, fb0SpiralAmountRange);
					ImGui::SliderFloat("fb0 spiral angle lfo rate", &fb0SpiralAngleLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0 spiral angle lfo amp", &fb0SpiralAngleLfoAmp, -fb0SpiralAngleRange, fb0SpiralAngleRange);
					ImGui::SliderFloat("fb0 spiral x lfo rate", &fb0SpiralXLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0 spiral x lfo amp", &fb0SpiralXLfoAmp, -fb0SpiralXRange, fb0SpiralXRange);
					ImGui::SliderFloat("fb0 spiral y lfo rate", &fb0SpiralYLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0 spiral y lfo amp", &fb0SpiralYLfoAmp, -fb0SpiralYRange, fb0SpiralYRange);

					ImGui::SliderFloat("fb0 kaleidoscope segments lfo rate", &fb0KaleidoscopeSegmentsLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0 kaleidoscope segments lfo amp", &fb0KaleidoscopeSegmentsLfoAmp, 0, fb0KaleidoscopeSegmentsRange);
					ImGui::SliderFloat("fb0 kaleidoscope slice lfo rate", &fb0KaleidoscopeSliceLfoTheta, .0f, lfom);
					ImGui::SliderFloat("fb0 kaleidoscope slice lfo amp", &fb0KaleidoscopeSliceLfoAmp, -fb0KaleidoscopeSliceRange, fb0KaleidoscopeSliceRange);	
				}

				if (ImGui::CollapsingHeader("pixelation"))
				{
					if (ImGui::Button("reset pixelation lfo")) {
						fb0XPixelScaleLfoTheta = 0;
						fb0XPixelScaleLfoAmp = 0;
						fb0YPixelScaleLfoTheta = 0;
						fb0YPixelScaleLfoAmp = 0;
						fb0PixelMixLfoTheta = 0;
						fb0PixelMixLfoAmp = 0;
						fb0PixelBrightscaleLfoTheta = 0;
						fb0PixelBrightscaleLfoAmp = 0;
					}
					//ImGui::Text("Love Flange Orgasms s");
					ImGui::SliderFloat("fb0 pixel scale_x_rate", &fb0XPixelScaleLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("fb0 pixel scale_x_amp", &fb0XPixelScaleLfoAmp, -256.0f, 256.0f);
					ImGui::SliderFloat("fb0 pixel scale_y_rate", &fb0YPixelScaleLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("fb0 pixel scale_y_amp", &fb0YPixelScaleLfoAmp, -256.0f, 256.0f);
					ImGui::SliderFloat("fb0 pixel mix_rate", &fb0PixelMixLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("fb0 pixel mix_amp", &fb0PixelMixLfoAmp, -2.0f, 2.0f);
					ImGui::SliderFloat("fb0 pixel bright scale rate", &fb0PixelBrightscaleLfoTheta, .0f, 20.0f);
					ImGui::SliderFloat("fb0 pixel bright scale amp", &fb0PixelBrightscaleLfoAmp, -2.0f, 2.0f);
				}
            }//endlfo folder  
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        //FB1
        
         mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 3*gui_vscaler-10));
        //fb1
        if (ofxImGui::BeginWindow("fb1", mainSettings, false)){
            if (ImGui::Button("reset all")) {
                fb1ResetAll();
            }
            if (ImGui::CollapsingHeader("parameters")){
                if (ImGui::Button("reset parameters")) {
                    fb1ResetAllParameters();
                }
                ImGui::SliderInt("fb1DelayAmount", &fb1DelayAmount, 0, fbob - 1);
                ImGui::Checkbox("tex_mod", &fb1TexmodSwitch);
                const char* items[] = { "channel 1","channel 2" };
                static int item_current = 0;
                ImGui::Combo("texmod select", &item_current, items, IM_ARRAYSIZE(items));
                fb1TexmodSelect=item_current;
                
                if (ImGui::CollapsingHeader("mix and key")){
                    static int item_current0 = 0;
                    static int item_current1 = 0;
                    static int item_current2 = 0;
                    static int item_current3 = 0;
                    static int item_current4 = 0;
                    static int item_current5 = 0;
                    if ( (ImGui::Button("reset mix and key")) ) {
                        fb1LumakeyLevel = 0;
                        fb1KeyThreshold = 0;
                        fb1ChromakeyRed = 0;
                        fb1ChromakeyGreen = 0;
                        fb1ChromakeyBlue = 0;
                        fb1KeySoft = 0;
                        fb1MaskX = 0;
                        fb1MaskY = 0;
                        fb1MaskZ = 1.0;
                        fb1MaskRotate = 0;
                        fb1MaskTileAmount = 1.0;
                        fb1MaskTexmodOffset = 0;
                        fb1MaskTexmodQuantizeAmount = 1.0;
                        fb1MaskTexmodQuantizeMix = 1.0;
                        item_current0 = 0;
                        item_current1 = 0;
                        item_current2 = 0;
                        item_current3 = 0;
                        item_current4 = 0;
                        item_current5 = 0;
                        fb1Mix = 0;
                        
                        fb1LumakeyLevelTexmod = 0.0;
                        fb1ChromakeyRedTexmod = 0;
                        fb1ChromakeyGreenTexmod = 0;
                        fb1ChromakeyBlueTexmod = 0;
                        fb1KeyThresholdTexmod = 0.0;
                        fb1KeySoftTexmod = 0;
                        fb1MixTexmod = .0;
                        fb1MaskXTexmod = 0;
                        fb1MaskYTexmod = 0;
                        fb1MaskZTexmod = 0.0;
                        fb1MaskRotateTexmod = 0;
                        fb1MaskTileAmountTexmod = 0.0;
                    }
                    
                    const char* items0[] = { "Input1->fb1","fb1->Input1" };
                    ImGui::Combo("fb1 mix and key order", &item_current0, items0, IM_ARRAYSIZE(items0));
                    fb1KeyOrder = item_current0;
                    
                    const char* items1[] = { "lerp", "add","difference","mult","dodge" };
                    ImGui::Combo("fb1 mix Type", &item_current1, items1, IM_ARRAYSIZE(items1));
                    fb1MixType = item_current1;
                    
                    if (fb1TexmodSwitch == false) {
                        ImGui::SliderFloat("fb1 mix", &fb1Mix, -2.0f, 2.0f);
                    }
                    if (fb1TexmodSwitch == true) {
                        ImGui::SliderFloat("texmod fb1 mix", &fb1MixTexmod, -2.0f, 2.0f);
                    }
                    const char* items2[] = { "clamp", "wrap","foldover" };
                    ImGui::Combo("fb1 Mix overflow", &item_current2, items2, IM_ARRAYSIZE(items2));
                    fb1MixOverflow = item_current2;
                    
                    const char* items3[] = { "Lumakey","Chromakey","wipePattern" };
                    ImGui::Combo("fb1 key mode", &item_current3, items3, IM_ARRAYSIZE(items3));
                    fb1KeyMode = item_current3;
                    
                    if (fb1KeyMode == 0) {
                        if (fb1TexmodSwitch == false) {
                            ImGui::SliderFloat("fb1 lumakey level", &fb1LumakeyLevel, 0.0f, 1.0f);
                        }
                        if (fb1TexmodSwitch == true) {
                            ImGui::SliderFloat("texmod fb1 lumakey level", &fb1LumakeyLevelTexmod, .0f, 1.0f);
                        }
                    }
                    if (fb1KeyMode == 1) {
                        if (fb1TexmodSwitch == false) {
                            ImGui::SliderFloat("fb1 Chromakey Red", &fb1ChromakeyRed, 0.0f, 1.0f);
                            ImGui::SliderFloat("fb1 Chromakey Green", &fb1ChromakeyGreen, 0.0f, 1.0f);
                            ImGui::SliderFloat("fb1 Chromakey Blue", &fb1ChromakeyBlue, 0.0f, 1.0f);
                        }
                        if (fb1TexmodSwitch == true) {
                            ImGui::SliderFloat("texmod fb1 Chromakey Red", &fb1ChromakeyRedTexmod, 0.0f, 1.0f);
                            ImGui::SliderFloat("texmod fb1 Chromakey Green", &fb1ChromakeyGreenTexmod, 0.0f, 1.0f);
                            ImGui::SliderFloat("texmod fb1 Chromakey Blue", &fb1ChromakeyBlueTexmod, 0.0f, 1.0f);
                        }
                        ImGui::ColorButton("testingColorButton", ImVec4(fb1ChromakeyRed, fb1ChromakeyGreen, fb1ChromakeyBlue, 1.0), 0, ImVec2(20, 20));
                    }
                    if (fb1KeyMode !=2) {
                        if (fb1TexmodSwitch == false) {
                            ImGui::SliderFloat("fb1 key threshold", &fb1KeyThreshold, 0.0f, rootThree);
                            ImGui::SliderFloat("fb1 key soft", &fb1KeySoft, 0.0f, 1.0f);
                        }
                        if (fb1TexmodSwitch == true) {
                            ImGui::SliderFloat("texmod fb1 key threshold", &fb1KeyThresholdTexmod, .0f, rootThree);
                            ImGui::SliderFloat("texmod fb1 key soft", &fb1KeySoftTexmod, 0.0f, 1.0f);
                        }
                    }
                    if (fb1KeyMode == 2) {
                        //when wipe pattern is selected we need to change chroma/lumakey values to 0
                        fb1LumakeyLevel = 0;
                        fb1KeyThreshold = 0;
                        fb1ChromakeyRed = 0;
                        fb1ChromakeyGreen = 0;
                        fb1ChromakeyBlue = 0;
                        fb1KeySoft = 0;
                        
                        //drop down menu for mask selection
                        const char* items4[] = { "mask1","mask2","mask3","mask4","texMod" };
                        ImGui::Combo("fb1 mask select", &item_current4, items4, IM_ARRAYSIZE(items4));
                        fb1MaskSelect = item_current4;
                        
                        //want to figure out way to get variables in here as to global width
                        if (fb1MaskSelect != 4) {
                            if (fb1TexmodSwitch == false) {
                                ImGui::SliderFloat("fb1 mask x", &fb1MaskX, -outWidth * .5f, outWidth*.5f);
                                ImGui::SliderFloat("fb1 mask y", &fb1MaskY, -outHeight * .5f, outHeight*.5f);
                                ImGui::SliderFloat("fb1 mask z", &fb1MaskZ, 0.0f, 3.0f);
                                ImGui::SliderFloat("fb1 mask rotate", &fb1MaskRotate, -TWO_PI, TWO_PI);
                                ImGui::SliderFloat("fb1 mask tile amount", &fb1MaskTileAmount, 0.0f, 2.0f);
                            }
                            if(fb1TexmodSwitch == true) {
                                ImGui::SliderFloat("texmod fb1 mask x", &fb1MaskXTexmod, -outWidth * .5f, outWidth*.5f);
                                ImGui::SliderFloat("texmod fb1 mask y", &fb1MaskYTexmod, -outHeight * .5f, outHeight*.5f);
                                ImGui::SliderFloat("texmod fb1 mask z", &fb1MaskZTexmod, -3.0f, 3.0f);
                                ImGui::SliderFloat("texmod fb1 mask rotate", &fb1MaskRotateTexmod, -TWO_PI, TWO_PI);
                                ImGui::SliderFloat("texmod fb1 mask tile amount", &fb1MaskTileAmountTexmod, -2.0f, 2.0f);
                            }
                            const char* items5[] = { "Off","Basic","basic alt rotate","spiral" };
                            ImGui::Combo("fb1 mask tile Mode", &item_current5, items5, IM_ARRAYSIZE(items5));
                            fb1MaskTileMode = item_current5;
                        }
                        if (fb1MaskSelect == 4) {
                            ImGui::SliderFloat("fb1 mask texmod offset", &fb1MaskTexmodOffset, -1.0f, 1.0f);
                            ImGui::SliderFloat("fb1 mask texmod quantize mix", &fb1MaskTexmodQuantizeMix, .0f, 1.0f);
                            ImGui::SliderInt("fb1 mask texmod quantize amount", &fb1MaskTexmodQuantizeAmount, 1, 32);
                        }
                    }
                }
                if (ImGui::CollapsingHeader("color space 1")){
                    static int item_current0 = 0;
                    static int item_current1 = 0;
                    if (ImGui::TreeNode(" color 1 ranges")) {
                        ImGui::SliderFloat("fb1 hue offset range", &fb1HueOffsetRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb1 saturation offset range", &fb1SaturationOffsetRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb1 bright offset range", &fb1BrightOffsetRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb1 hue attenuate range", &fb1HueAttenuateRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb1 saturation attenuate range", &fb1SaturationAttenuateRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb1 bright attenuate range", &fb1BrightAttenuateRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb1 hue Shaper range", &fb1HueShaperRange, .0001f, 5.0f);
                        ImGui::SliderFloat("fb1 hue powmap range", &fb1HuePowMapRange, .0001f, 5.0f);
                        ImGui::SliderFloat("fb1 saturation powmap range", &fb1SaturationPowMapRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb1 bright powmap range", &fb1BrightPowMapRange, .0001f, 20.0f);
                        ImGui::TreePop();
                    }
                    if ( (ImGui::Button("reset color 1"))  ) {
                        fb1HueOffset = 0.0;
                        fb1SaturationOffset = 0.0;
                        fb1BrightOffset = 0.0;
                        fb1HueAttenuate = 10.0;
                        fb1SaturationAttenuate = 10.0;
                        fb1BrightAttenuate = 10.0;
                        fb1HueShaper = 0.0;
                        fb1HuePowMap=1.0;
                        fb1SaturationPowMap=1.0;
                        fb1BrightPowMap=1.0;
                        fb1HueInvert = 0;
                        fb1SaturationInvert = 0;
                        fb1BrightInvert = 0;
                        
                        fb1HueShaperRange = 0.25;
                        fb1HueOffsetRange = .25;
                        fb1SaturationOffsetRange = 0.25;
                        fb1BrightOffsetRange = 0.25;
                        fb1HueAttenuateRange = 2.0;
                        fb1SaturationAttenuateRange = 2.0;
                        fb1BrightAttenuateRange = 2.0;
                        
                        fb1HueInvert = 0;
                        fb1SaturationInvert = 0;
                        fb1BrightInvert = 0;
                        
                        fb1SaturationOverflow = 0;
                        fb1BrightOverflow = 0;
                        fb1HuePowMapRange = .25;
                        fb1SaturationPowMapRange = .25;
                        fb1BrightPowMapRange = .25;
                        
                        fb1HueOffsetTexmod = 0.0;
                        fb1SaturationOffsetTexmod = 0.0;
                        fb1BrightOffsetTexmod = 0.0;
                        fb1HueAttenuateTexmod = 0.0;
                        fb1SaturationAttenuateTexmod = 0.0;
                        fb1BrightAttenuateTexmod = 0.0;
                        fb1HueShaperTexmod = 0.0;
                        fb1HuePowMapTexmod = .0;
                        fb1SaturationPowMapTexmod = .0;
                        fb1BrightPowMapTexmod = .0;
                        
                    }
                    
                    //EASTER EGG
                    //some combination of keypresses adds 1. crt overlay, 2. pixels in SD aspect ratio, 3. enuf dither to look like scanlines
                    //4. interlacing
                    if(fb1TexmodSwitch==false){
                        ImGui::SliderFloat("fb1 hue offset",&fb1HueOffset,-fb1HueOffsetRange,fb1HueOffsetRange);
                        ImGui::SliderFloat("fb1 saturation offset", &fb1SaturationOffset, -fb1SaturationOffsetRange, fb1SaturationOffsetRange);
                        ImGui::SliderFloat("fb1 bright offset", &fb1BrightOffset, -fb1BrightOffsetRange, fb1BrightOffsetRange);
                        ImGui::SliderFloat("fb1 hue attenuate", &fb1HueAttenuate, 10.0f-fb1HueAttenuateRange, 10.0f+fb1HueAttenuateRange);
                        ImGui::SliderFloat("fb1 saturation attenuate", &fb1SaturationAttenuate, 10.0f - fb1SaturationAttenuateRange, 10.0f + fb1SaturationAttenuateRange);
                        ImGui::SliderFloat("fb1 bright attenuate", &fb1BrightAttenuate, 10.0f - fb1BrightAttenuateRange, 10.0f + fb1BrightAttenuateRange);
                        ImGui::SliderFloat("fb1 hue Shaper", &fb1HueShaper, -fb1HueShaperRange, fb1HueShaperRange);
                        ImGui::SliderFloat("fb1 hue powmap", &fb1HuePowMap, 1.0f - fb1HuePowMapRange, 1.0f + fb1HuePowMapRange);
                        ImGui::SliderFloat("fb1 saturation powmap", &fb1SaturationPowMap, 1.0f - fb1SaturationPowMapRange, 1.0f + fb1SaturationPowMapRange);
                        ImGui::SliderFloat("fb1 bright powmap", &fb1BrightPowMap, 1.0f-fb1BrightPowMapRange, 1.0f+fb1BrightPowMapRange);
                    }
                    if (fb1TexmodSwitch == true) {
                        ImGui::SliderFloat("texmod fb1 hue offset", &fb1HueOffsetTexmod, -fb1HueOffsetRange * .1f, fb1HueOffsetRange*.1f);
                        ImGui::SliderFloat("texmod fb1 saturation offset", &fb1SaturationOffsetTexmod, -fb1SaturationOffsetRange * .1f, fb1SaturationOffsetRange*.1f);
                        ImGui::SliderFloat("texmod fb1 bright offset", &fb1BrightOffsetTexmod, -fb1BrightOffsetRange * .1f, fb1BrightOffsetRange*.1f);
                        ImGui::SliderFloat("texmod fb1HueAttenuate", &fb1HueAttenuateTexmod, -fb1HueAttenuateRange * .1f, fb1HueAttenuateRange*.1f);
                        ImGui::SliderFloat("texmod fb1SaturationAttenuate", &fb1SaturationAttenuateTexmod, -fb1SaturationAttenuateRange * .1f, fb1SaturationAttenuateRange*.1f);
                        ImGui::SliderFloat("texmod fb1BrightAttenuate", &fb1BrightAttenuateTexmod, -fb1BrightAttenuateRange * .1f, fb1BrightAttenuateRange*.1f);
                        ImGui::SliderFloat("texmod fb1 hue Shaper", &fb1HueShaperTexmod, -fb1HueShaperRange * .1f, fb1HueShaperRange*.1f);
                        ImGui::SliderFloat("texmod fb1 hue powmap", &fb1HuePowMapTexmod, -fb1HuePowMapRange, fb1HuePowMapRange);
                        ImGui::SliderFloat("texmod fb1 saturation powmap", &fb1SaturationPowMapTexmod, -fb1SaturationPowMapRange, fb1SaturationPowMapRange);
                        ImGui::SliderFloat("texmod fb1 bright powmap", &fb1BrightPowMapTexmod, -fb1BrightPowMapRange, fb1BrightPowMapRange);
                    }
                    ImGui::Checkbox("fb1HueInvert", &fb1HueInvert);
                    ImGui::Checkbox("fb1SaturationInvert", &fb1SaturationInvert);
                    ImGui::Checkbox("fb1BrightInvert", &fb1BrightInvert);
                    
                    const char* items0[] = { "clamp","wrap","fold" };
                    ImGui::Combo("saturation overflow", &item_current0, items0, IM_ARRAYSIZE(items0));
                    fb1SaturationOverflow = item_current0;
                    const char* items1[] = { "clamp","wrap","fold" };
                    ImGui::Combo("bright overflow", &item_current1, items1, IM_ARRAYSIZE(items1));
                    fb1BrightOverflow = item_current1;
                    //add wrap, fold, clamp for colors
                }
                if (ImGui::CollapsingHeader("color space 2")) {
                    if (ImGui::TreeNode(" color 2 ranges")) {
                        ImGui::SliderInt("fb1 hue dither range", &fb1HueDitherRange, 1, 512);
                        ImGui::SliderInt("fb1 saturation dither range", &fb1SaturationDitherRange, 1, 512);
                        ImGui::SliderInt("fb1 bright dither range", &fb1BrightDitherRange, 1, 512);
                        ImGui::SliderInt("fb1 hue quantize range", &fb1HueQuantizeRange, 1, 512);
                        ImGui::SliderInt("fb1 saturation quantize range", &fb1SaturationQuantizeRange, 1, 512);
                        ImGui::SliderInt("fb1 bright quantize range", &fb1BrightQuantizeRange, 1, 512);
                        ImGui::TreePop();
                    }
                    if ( (ImGui::Button("reset color 2"))  ) {
                        fb1HueQuantize = 128;
                        fb1SaturationQuantize = 128;
                        fb1BrightQuantize = 128;
                        fb1HueQuantizeMix = 0.0;
                        fb1SaturationQuantizeMix = 0.0;
                        fb1BrightQuantizeMix = 0.0;
                        fb1HueDitherMix = 0.0;
                        fb1HueDitherAmount = 64;
                        fb1SaturationDitherMix = 0.0;
                        fb1SaturationDitherAmount = 64;
                        fb1BrightDitherMix = 0.0;
                        fb1BrightDitherAmount = 64;
                        
                        fb1HueQuantizeTexmod = 0;
                        fb1SaturationQuantizeTexmod = 0;
                        fb1BrightQuantizeTexmod = 0;
                        fb1HueQuantizeMixTexmod = 0.0;
                        fb1SaturationQuantizeMixTexmod = 0.0;
                        fb1BrightQuantizeMixTexmod = 0.0;
                        fb1HueDitherMixTexmod = 0.0;
                        fb1HueDitherAmountTexmod = 0;
                        fb1SaturationDitherMixTexmod = 0.0;
                        fb1SaturationDitherAmountTexmod = 0;
                        fb1BrightDitherMixTexmod = 0.0;
                        fb1BrightDitherAmountTexmod = 0;
                    }
                    if (fb1TexmodSwitch == false) {
                        ImGui::SliderFloat("fb1 hue quantize mix", &fb1HueQuantizeMix, .0f, 1.0f);
                        ImGui::SliderInt("fb1 hue quantize amount", &fb1HueQuantize, 1, fb1HueQuantizeRange);
                        ImGui::SliderFloat("fb1 saturation quantize mix", &fb1SaturationQuantizeMix, .0f, 1.0f);
                        ImGui::SliderInt("fb1 saturation quantize amount", &fb1SaturationQuantize, 1, fb1SaturationQuantizeRange);
                        ImGui::SliderFloat("fb1 bright quantize mix", &fb1BrightQuantizeMix, .0f, 1.0f);
                        ImGui::SliderInt("fb1 bright quantize amount", &fb1BrightQuantize, 1, fb1BrightQuantizeRange);
                        ImGui::SliderFloat("fb1 hue dither mix", &fb1HueDitherMix, .0f, 1.0f);
                        ImGui::SliderInt("fb1 hue dither amount", &fb1HueDitherAmount, 1, fb1HueDitherRange);
                        ImGui::SliderFloat("fb1 saturation dither mix", &fb1SaturationDitherMix, .0f, 1.0f);
                        ImGui::SliderInt("fb1 saturation dither amount", &fb1SaturationDitherAmount, 1, fb1SaturationDitherRange);
                        ImGui::SliderFloat("fb1 bright dither mix", &fb1BrightDitherMix, .0f, 1.0f);
                        ImGui::SliderInt("fb1 bright dither amount", &fb1BrightDitherAmount, 1, fb1BrightDitherRange);
                    }
                    if (fb1TexmodSwitch == true) {
                        /*
                         ImGui::SliderFloat("texmod fb1 hue quantize mix", &fb1HueQuantizeMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb1 hue quantize amount", &fb1HueQuantizeTexmod, 1, fb1HueQuantizeRange);
                         ImGui::SliderFloat("texmod fb1 saturation quantize mix", &fb1SaturationQuantizeMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb1 saturation quantize amount", &fb1SaturationQuantizeTexmod, 1, fb1SaturationQuantizeRange);
                         ImGui::SliderFloat("texmod fb1 bright quantize mix", &fb1BrightQuantizeMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb1 bright quantize amount", &fb1BrightQuantizeTexmod, 1, fb1BrightQuantizeRange);
                         ImGui::SliderFloat("texmod fb1 hue dither mix", &fb1HueDitherMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb1 hue dither amount", &fb1HueDitherAmountTexmod, 1, fb1HueDitherRange);
                         ImGui::SliderFloat("texmod fb1 saturation dither mix", &fb1SaturationDitherMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb1 saturation dither amount", &fb1SaturationDitherAmountTexmod, 1, fb1SaturationDitherRange);
                         ImGui::SliderFloat("texmod fb1 bright dither mix", &fb1BrightDitherMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb1 bright dither amount", &fb1BrightDitherAmountTexmod, 1, fb1BrightDitherRange);
                         */
                    }
                    
                }
                if (ImGui::CollapsingHeader("geometry1")){
                    static int item_current2 = 0;
                    if (ImGui::TreeNode(" geo 1 ranges")) {
                        ImGui::SliderFloat("fb1 x displace range", &fb1XDisplaceRange, .0001f, 200.0f);
                        ImGui::SliderFloat("fb1 y displace range", &fb1YDisplaceRange, .0001f, 200.0f);
                        ImGui::SliderFloat("fb1 z displace range", &fb1ZDisplaceRange, .0001f, 100.0f);
                        ImGui::SliderFloat("fb1 rotate range", &fb1ZRotateRange, .0001f, TWO_PI);
                        ImGui::SliderFloat("fb1 shear matrix 1 Range", &fb1ShearMatrixRange.x, .0001f, 5.0f);
                        ImGui::SliderFloat("fb1 shear matrix 2 Range", &fb1ShearMatrixRange.y, .0001f, 5.0f);
                        ImGui::SliderFloat("fb1 shear matrix 3 Range", &fb1ShearMatrixRange.z, .0001f, 5.0f);
                        ImGui::SliderFloat("fb1 shear matrix 4 Range", &fb1ShearMatrixRange.w, .0001f, 5.0f);
                        
                        ImGui::TreePop();
                    }
                    if ( ImGui::Button("reset geo1") ) {
                        item_current2 = 0;
                        fb1XDisplace = 0.0;
                        fb1YDisplace = 0.0;
                        fb1ZDisplace = 100.0;
                        fb1Rotate = 0;
                        fb1ShearMatrix.set(0,0,0,0);
                        fb1ShearMatrixRange.set(0.25, 0.25, 0.25, 0.25);
                        fb1RotateMode = 0;
                        fb1HorizontalMirror = 0;
                        fb1VerticalMirror = 0;
                        fb1XDisplaceRange = 40;
                        fb1YDisplaceRange = 40;
                        fb1ZDisplaceRange = 10;
                        fb1ZRotateRange = PI;
                        
                        fb1XDisplaceTexmod=0.0;
                        fb1YDisplaceTexmod=0.0;
                        fb1ZDisplaceTexmod=0;
                        fb1RotateTexmod=0;
                        fb1ShearMatrixTexmod.set(0,0,0,0);
                    }
                    if(fb1TexmodSwitch==false){
                        ImGui::SliderFloat("fb1_x", &fb1XDisplace, -fb1XDisplaceRange, fb1XDisplaceRange);
                        ImGui::SliderFloat("fb1_y", &fb1YDisplace, -fb1YDisplaceRange, fb1YDisplaceRange);
                        ImGui::SliderFloat("fb1_z", &fb1ZDisplace,  100.0f-fb1ZDisplaceRange, 100.0f+fb1ZDisplaceRange);
                        ImGui::SliderFloat("fb1Rotate", &fb1Rotate, -fb1ZRotateRange, fb1ZRotateRange);
                        
                        ImGui::SliderFloat("fb1 Shear matrix 1", &fb1ShearMatrix.x, -fb1ShearMatrixRange.x, fb1ShearMatrixRange.x);
                        ImGui::SliderFloat("fb1 Shear matrix 2", &fb1ShearMatrix.y, -fb1ShearMatrixRange.y, fb1ShearMatrixRange.y);
                        ImGui::SliderFloat("fb1 Shear matrix 3", &fb1ShearMatrix.z, -fb1ShearMatrixRange.z, fb1ShearMatrixRange.z);
                        ImGui::SliderFloat("fb1 Shear matrix 4", &fb1ShearMatrix.w, -fb1ShearMatrixRange.w, fb1ShearMatrixRange.w);
                    }
                    if(fb1TexmodSwitch==true){
                        ImGui::SliderFloat("texmod fb1_x", &fb1XDisplaceTexmod, -fb1XDisplaceRange, fb1XDisplaceRange);
                        ImGui::SliderFloat("texmod fb1_y", &fb1YDisplaceTexmod,  -fb1YDisplaceRange, fb1YDisplaceRange);
                        ImGui::SliderFloat("texmod fb1_z", &fb1ZDisplaceTexmod,  -fb1ZDisplaceRange*.01, fb1ZDisplaceRange*.01);
                        ImGui::SliderFloat("texmod fb1Rotate", &fb1RotateTexmod, -fb1ZRotateRange, fb1ZRotateRange);
                        
                        ImGui::SliderFloat("texmod fb1 Shear matrix 1", &fb1ShearMatrixTexmod.x, -fb1ShearMatrixRange.x, fb1ShearMatrixRange.x);
                        ImGui::SliderFloat("texmod fb1 Shear matrix 2", &fb1ShearMatrixTexmod.y, -fb1ShearMatrixRange.y, fb1ShearMatrixRange.y);
                        ImGui::SliderFloat("texmod fb1 Shear matrix 3", &fb1ShearMatrixTexmod.z, -fb1ShearMatrixRange.z, fb1ShearMatrixRange.z);
                        ImGui::SliderFloat("texmod fb1 Shear matrix 4", &fb1ShearMatrixTexmod.w, -fb1ShearMatrixRange.w, fb1ShearMatrixRange.w);
                    }
                    const char* items2[] = { "clamp","toroid","mirror" };
                    ImGui::Combo("Geometry overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                    fb1_toroid_switch = item_current2;
                    
                    ImGui::Checkbox("fb1_h_mirror", &fb1HorizontalMirror);
                    ImGui::Checkbox("fb1_v_mirror", &fb1VerticalMirror);
                    ImGui::Checkbox("fb1RotateMode", &fb1RotateMode);
                }
                if (ImGui::CollapsingHeader("geometry2")) {
                    if (ImGui::TreeNode("geo 2 ranges")) {
                        ImGui::SliderFloat("fb1 fisheye amount range", &fb1FisheyeAmountRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb1 fisheye X range", &fb1FisheyeXRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb1 fisheye Y range", &fb1FisheyeYRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb1 spiral amount range", &fb1SpiralAmountRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb1 spiral angle range", &fb1SpiralAngleRange, .0001f, TWO_PI);
                        ImGui::SliderFloat("fb1 spiral X range", &fb1SpiralXRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb1 spiral Y range", &fb1SpiralYRange, .0001f, 10.0f);
                        ImGui::SliderInt("fb1 kaleidoscope segments range", &fb1KaleidoscopeSegmentsRange, 1, 100);
                        ImGui::SliderFloat("fb1 kaleidoscope slice range", &fb1KaleidoscopeSliceRange,.01,TWO_PI);
                        
                        ImGui::TreePop();
                    }
                    if (ImGui::Button("reset geo2")) {
                        fb1FisheyeAmount = 0;
                        fb1FisheyeX = 0;
                        fb1FisheyeY = 0;
                        fb1SpiralAmount = 0;
                        fb1SpiralAngle = 0;
                        fb1SpiralX = 0;
                        fb1SpiralY = 0;
                        fb1KaleidoscopeSegments = 0;
                        fb1KaleidoscopeSlice = 0;
                        
                        fb1FisheyeAmountRange = .15;
                        fb1FisheyeXRange = .25;
                        fb1FisheyeYRange = .25;
                        fb1SpiralAmountRange = .15;
                        fb1SpiralAngleRange = PI;
                        fb1SpiralXRange = .25;
                        fb1SpiralYRange = .25;
                        fb1KaleidoscopeSegmentsRange = 21;
                        fb1KaleidoscopeSliceRange = PI;
                        
                        fb1FisheyeAmountTexmod = 0;
                        fb1FisheyeXTexmod = 0;
                        fb1FisheyeYTexmod = 0;
                        fb1SpiralAmountTexmod = 0;
                        fb1SpiralAngleTexmod = 0;
                        fb1SpiralXTexmod = 0;
                        fb1SpiralYTexmod = 0;
                        fb1KaleidoscopeSegmentsTexmod = 0;
                        fb1KaleidoscopeSliceTexmod = 0;
                        
                    }
                    
                    if(fb1TexmodSwitch==false){
                        ImGui::SliderFloat("fb1 fisheye amount", &fb1FisheyeAmount, -fb1FisheyeAmountRange, fb1FisheyeAmountRange);
                        ImGui::SliderFloat("fb1 fisheye x", &fb1FisheyeX, -fb1FisheyeXRange, fb1FisheyeXRange);
                        ImGui::SliderFloat("fb1 fisheye y", &fb1FisheyeY, -fb1FisheyeYRange, fb1FisheyeYRange);
                        
                        ImGui::SliderFloat("fb1 spiral amount", &fb1SpiralAmount, -fb1SpiralAmountRange, fb1SpiralAmountRange);
                        ImGui::SliderFloat("fb1 spiral angle", &fb1SpiralAngle, -fb1SpiralAngleRange, fb1SpiralAngleRange);
                        ImGui::SliderFloat("fb1 spiral x", &fb1SpiralX, -fb1SpiralXRange, fb1SpiralXRange);
                        ImGui::SliderFloat("fb1 spiral y", &fb1SpiralY, -fb1SpiralYRange, fb1SpiralYRange);
                        
                        ImGui::SliderInt("fb1 kaleidoscope segments", &fb1KaleidoscopeSegments, 0, fb1KaleidoscopeSegmentsRange);
                        ImGui::SliderFloat("fb1 kaleidoscope slice", &fb1KaleidoscopeSlice, -fb1KaleidoscopeSliceRange, fb1KaleidoscopeSliceRange);
                    }
                    
                    if(fb1TexmodSwitch==true){
                        ImGui::SliderFloat("texmod fb1 fisheye amount", &fb1FisheyeAmountTexmod, -fb1FisheyeAmountRange, fb1FisheyeAmountRange);
                        ImGui::SliderFloat("texmod fb1 fisheye x", &fb1FisheyeXTexmod, -fb1FisheyeXRange, fb1FisheyeXRange);
                        ImGui::SliderFloat("texmod fb1 fisheye y", &fb1FisheyeYTexmod, -fb1FisheyeYRange, fb1FisheyeYRange);
                        
                        ImGui::SliderFloat("texmod fb1 spiral amount", &fb1SpiralAmountTexmod, -fb1SpiralAmountRange, fb1SpiralAmountRange);
                        ImGui::SliderFloat("texmod fb1 spiral angle", &fb1SpiralAngleTexmod, -fb1SpiralAngleRange, fb1SpiralAngleRange);
                        ImGui::SliderFloat("texmod fb1 spiral x", &fb1SpiralXTexmod, -fb1SpiralXRange, fb1SpiralXRange);
                        ImGui::SliderFloat("texmod fb1 spiral y", &fb1SpiralYTexmod, -fb1SpiralYRange, fb1SpiralYRange);
                        
                        ImGui::SliderFloat("texmod fb1 kaleidoscope segments", &fb1KaleidoscopeSegmentsTexmod, 0, fb1KaleidoscopeSegmentsRange);
                        ImGui::SliderFloat("texmod fb1 kaleidoscope slice", &fb1KaleidoscopeSliceTexmod, -fb1KaleidoscopeSliceRange, fb1KaleidoscopeSliceRange);
                    }
                    
                }
                
                //ADD THE PIXELS HERE
                if (ImGui::CollapsingHeader("pixelate"))
                {
                    if (ImGui::Button("reset pixelate")) {
                        fb1PixelXYLock = 1;
                        fb1XPixelScale = 64;
                        fb1YPixelScale = 64;
                        fb1PixelMix = 1;
                        fb1PixelBrightscale = 0;
                        
                        fb1XPixelScaleTexmod=0;
                        fb1YPixelScaleTexmod=0;
                        fb1PixelMixTexmod=0;
                        fb1PixelBrightscaleTexmod=0;
                    }
                    ImGui::Checkbox("fb1 pixelate", &fb1PixelSwitch);
                    ImGui::Checkbox("fb1 pixelXY lock", &fb1PixelXYLock);
                    
                    if (fb1TexmodSwitch == false) {
                        ImGui::SliderInt("fb1 pixel scale x", &fb1XPixelScale, .0f, 256.0f);
                        if (fb1PixelXYLock == 1) {
                            ImGui::SliderInt("fb1 pixel scale y", &fb1XPixelScale, .0f, 256.0f);
                        }
                        if (fb1PixelXYLock == 0) {
                            ImGui::SliderInt("fb1 pixel scale y", &fb1YPixelScale, .0f, 256.0f);
                        }
                        ImGui::SliderFloat("fb1 pixel mix", &fb1PixelMix, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb1 bright scale", &fb1PixelBrightscale, -2.0f, 2.0f);
                    }
                    if (fb1TexmodSwitch == true) {
                        ImGui::SliderInt("fb1 texmod pixel scale x", &fb1XPixelScaleTexmod, -256.0f, 256.0f);
                        if (fb1PixelXYLock == 1) {
                            ImGui::SliderInt("fb1 texmod pixel scale y", &fb1XPixelScaleTexmod, -256.0f, 256.0f);
                        }
                        if (fb1PixelXYLock == 0) {
                            ImGui::SliderInt("fb1 texmod pixel scale y", &fb1YPixelScaleTexmod, -256.0f, 256.0f);
                        }
                        ImGui::SliderFloat("fb1 texmod pixel mix", &fb1PixelMixTexmod, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb1 texmod bright scale", &fb1PixelBrightscaleTexmod, -2.0f, 2.0f);
                    }
                }
            }//end collapsing folder
            ImGui::Separator();
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Loose Floating Object s");
                if (ImGui::Button("reset lfo")) {
                    fb1ResetAllLfo();
                }
                if (ImGui::CollapsingHeader("mix and delay amount lfo")){
                    if (ImGui::Button("reset mix and delay lfo")) {
                        fb1_delay_lfo_theta = 0;
                        fb1DelayLfoAmp = 0;
                        fb1MixLfoTheta = 0;
                        fb1MixLfoAmp = 0;
                        fb1LumakeyLevelLfoTheta = 0;
                        fb1LumakeyLevelLfoAmp = 0;
                        fb1ChromakeyRedLfoTheta = 0;
                        fb1ChromakeyRedLfoAmp = 0;
                        fb1ChromakeyGreenLfoTheta = 0;
                        fb1ChromakeyGreenLfoAmp = 0;
                        fb1ChromakeyBlueLfoTheta = 0;
                        fb1ChromakeyBlueLfoAmp = 0;
                        fb1KeyThresholdLfoTheta = 0;
                        fb1KeyThresholdLfoAmp = 0;
                        fb1KeySoftLfoTheta = 0;
                        fb1KeySoftLfoAmp = 0;
                        fb1MaskXLfoTheta = 0;
                        fb1MaskXLfoAmp = 0;
                        fb1MaskYLfoTheta = 0;
                        fb1MaskYLfoAmp = 0;
                        fb1MaskZLfoTheta = 0.0;
                        fb1MaskZLfoAmp = 0.0;
                        fb1MaskRotateLfoTheta = 0;
                        fb1MaskRotateLfoAmp = 0;
                        fb1MaskTileAmountLfoTheta = 0.0;
                        fb1MaskTileAmountLfoAmp = 0.0;
                        fb1MaskTexmodOffsetLfoTheta = 0;
                        fb1MaskTexmodOffsetLfoAmp = 0;
                        fb1MaskTexmodQuantizeAmountLfoTheta = 0.0;
                        fb1MaskTexmodQuantizeAmountLfoAmp = 0.0;
                        fb1MaskTexmodQuantizeMixLfoTheta = 0.0;
                        fb1MaskTexmodQuantizeMixLfoAmp = 0.0;
                    }
                    ImGui::SliderFloat("fb1DelayLfoRate", &fb1_delay_lfo_theta, .0f, 10.0f);
                    ImGui::SliderFloat("fb1DelayLfoAmp", &fb1DelayLfoAmp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb1MixLfoRate", &fb1MixLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1MixLfoAmp", &fb1MixLfoAmp, -2.0f, 2.0f);
                    //Not Wipes
                    if (fb1KeyMode != 2) {
                        //luma
                        if (fb1KeyMode == 0) {
                            ImGui::SliderFloat("fb1LumakeyLevelLfoRate", &fb1LumakeyLevelLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1LumakeyLevelLfoAmp", &fb1LumakeyLevelLfoAmp, -1.0f, 1.0f);
                        }
                        if (fb1KeyMode == 1) {
                            ImGui::SliderFloat("fb1ChromakeyRedLfoRate", &fb1ChromakeyRedLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1ChromakeyRedLfoAmp", &fb1ChromakeyRedLfoAmp, -1.0f, 1.0f);
                            ImGui::SliderFloat("fb1ChromakeyGreenLfoRate", &fb1ChromakeyGreenLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1ChromakeyGreenLfoAmp", &fb1ChromakeyGreenLfoAmp, -1.0f, 1.0f);
                            ImGui::SliderFloat("fb1ChromakeyBlueLfoRate", &fb1ChromakeyBlueLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1ChromakeyBlueLfoAmp", &fb1ChromakeyBlueLfoAmp, -1.0f, 1.0f);
                        }
                        ImGui::SliderFloat("fb1Keythreshold_lfo_rate", &fb1KeyThresholdLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1KeyThresholdLfoAmp", &fb1KeyThresholdLfoAmp, -rootThree, rootThree);
                        ImGui::SliderFloat("fb1KeySoftLfoRate", &fb1KeySoftLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1KeySoftLfoAmp", &fb1KeySoftLfoAmp, -1.0, 1.0);
                    }
                    if (fb1KeyMode == 2) {
                        fb1ChromakeyRedLfoAmp = 0;
                        fb1ChromakeyGreenLfoAmp = 0;
                        fb1ChromakeyBlueLfoAmp = 0;
                        fb1LumakeyLevelLfoAmp = 0;
                        fb1KeyThresholdLfoAmp = 0;
                        //regular wipes
                        if (fb1MaskSelect != 4) {
                            ImGui::SliderFloat("fb1MaskXLfoRate", &fb1MaskXLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1MaskXLfoAmp", &fb1MaskXLfoAmp, -outWidth * .5f, outWidth*.5f);
                            ImGui::SliderFloat("fb1MaskYLfoRate", &fb1MaskYLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1MaskYLfoAmp", &fb1MaskYLfoAmp, -outHeight * .5f, outHeight*.5f);
                            ImGui::SliderFloat("fb1MaskZLfoRate", &fb1MaskZLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1MaskZLfoAmp", &fb1MaskZLfoAmp, -3.0f, 3.0f);
                            ImGui::SliderFloat("fb1MaskRotateLfoRate", &fb1MaskRotateLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1MaskRotateLfoAmp", &fb1MaskRotateLfoAmp, -TWO_PI, TWO_PI);
                            ImGui::SliderFloat("fb1MaskTileAmountLfoRate", &fb1MaskTileAmountLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1MaskTileAmountLfoAmp", &fb1MaskTileAmountLfoAmp, -3.0f, 3.0f);
                        }
                        //texmodWipes
                        if (fb1MaskSelect == 4) {
                            ImGui::SliderFloat("fb1MaskTexmodOffsetLfoRate", &fb1MaskTexmodOffsetLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1MaskTexmodOffsetLfoAmp", &fb1MaskTexmodOffsetLfoAmp, -1.0, 1.0);
                            ImGui::SliderFloat("fb1MaskTexmodQuantizeAmountLfoRate", &fb1MaskTexmodQuantizeAmountLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1MaskTexmodQuantizeAmountLfoAmp", &fb1MaskTexmodQuantizeAmountLfoAmp, 0.0, 32.0);
                            ImGui::SliderFloat("fb1MaskTexmodQuantizeMixLfoRate", &fb1MaskTexmodQuantizeMixLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb1MaskTexmodQuantizeMixLfoAmp", &fb1MaskTexmodQuantizeMixLfoAmp, 0.0, 1.0);
                        }
                    }
                }
                if (ImGui::CollapsingHeader("color1  lfo")){
                    if (ImGui::Button("reset color1 lfo")) {
                        fb1HueOffsetLfoTheta = 0.0;
                        fb1SaturationOffsetLfoTheta = 0.0;
                        fb1BrightOffsetLfoTheta = 0.0;
                        fb1HueAttenuateLfoTheta = 0.0;
                        fb1SaturationAttenuateLfoTheta = 0.0;
                        fb1BrightAttenuateLfoTheta = 0.0;
                        fb1HueShaperLfoTheta = 0.0;
                        fb1HuePowMapLfoTheta = 0;
                        fb1SaturationPowMapLfoTheta = .0;
                        fb1BrightPowMapLfoTheta = .0;
                        
                        fb1HueOffsetLfoAmp = 0.0;
                        fb1SaturationOffsetLfoAmp = 0.0;
                        fb1BrightOffsetLfoAmp = 0.0;
                        fb1HueAttenuateLfoAmp = 0.0;
                        fb1SaturationAttenuateLfoAmp = 0.0;
                        fb1BrightAttenuateLfoAmp = 0.0;
                        fb1HueShaperLfoAmp = 0.0;
                        fb1HuePowMapLfoAmp = 0;
                        fb1SaturationPowMapLfoAmp = .0;
                        fb1BrightPowMapLfoAmp = .0;
                    }
                    
                    ImGui::SliderFloat("fb1HueOffsetLfo_rate", &fb1HueOffsetLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1HueOffsetLfoAmp", &fb1HueOffsetLfoAmp, -fb1HueOffsetRange, fb1HueOffsetRange);
                    ImGui::SliderFloat("fb1SaturationOffset_lfo_rate", &fb1SaturationOffsetLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1SaturationOffsetLfoAmp", &fb1SaturationOffsetLfoAmp, -fb1SaturationOffsetRange, fb1SaturationOffsetRange);
                    ImGui::SliderFloat("fb1BrightOffset_lfo_rate", &fb1BrightOffsetLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1BrightOffsetLfoAmp", &fb1BrightOffsetLfoAmp, -fb1BrightOffsetRange, fb1BrightOffsetRange);
                    ImGui::Separator();
                    ImGui::SliderFloat("fb1HueAttenuateLfo_rate", &fb1HueAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1HueAttenuateLfoAmp", &fb1HueAttenuateLfoAmp, -fb1HueAttenuateRange, fb1HueAttenuateRange);
                    ImGui::SliderFloat("fb1SaturationAttenuate_lfo_rate", &fb1SaturationAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1SaturationAttenuateLfoAmp", &fb1SaturationAttenuateLfoAmp, -fb1SaturationAttenuateRange, fb1SaturationAttenuateRange);
                    ImGui::SliderFloat("fb1BrightAttenuate_lfo_rate", &fb1BrightAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1BrightAttenuateLfoAmp", &fb1BrightAttenuateLfoAmp, -fb1BrightAttenuateRange, fb1BrightAttenuateRange);
                    ImGui::Separator();
                    ImGui::SliderFloat("fb1HueShaperLfo_rate", &fb1HueShaperLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1HueShaperLfoAmp", &fb1HueShaperLfoAmp, -fb1HueShaperRange, fb1HueShaperRange);
                    
                    ImGui::SliderFloat("fb1HuePowMapLfo_rate", &fb1HuePowMapLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1HuePowMapLfoAmp", &fb1HuePowMapLfoAmp, -fb1HuePowMapRange, fb1HuePowMapRange);
                    ImGui::SliderFloat("fb1SaturationPowMap_lfo_rate", &fb1SaturationPowMapLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1SaturationPowMapLfoAmp", &fb1SaturationPowMapLfoAmp, -fb1SaturationPowMapRange, fb1SaturationPowMapRange);
                    ImGui::SliderFloat("fb1BrightPowMap_lfo_rate", &fb1BrightPowMapLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1BrightPowMapLfoAmp", &fb1BrightPowMapLfoAmp, -fb1BrightPowMapRange, fb1BrightPowMapRange);
                    
                }
                if (ImGui::CollapsingHeader("color2  lfo")) {
                    if (ImGui::Button("reset color2 lfo")) {
                        fb1HueQuantizeLfoTheta = 0;
                        fb1SaturationQuantizeLfoTheta = 0;
                        fb1BrightQuantizeLfoTheta = 0;
                        fb1HueQuantizeMixLfoTheta = 0.0;
                        fb1SaturationQuantizeMixLfoTheta = 0.0;
                        fb1BrightQuantizeMixLfoTheta = 0.0;
                        fb1HueDitherMixLfoTheta = 0.0;
                        fb1HueDitherAmountLfoTheta = 0;
                        fb1SaturationDitherMixLfoTheta = 0.0;
                        fb1SaturationDitherAmountLfoTheta = 0;
                        fb1BrightDitherMixLfoTheta = 0.0;
                        fb1BrightDitherAmountLfoTheta = 0;
                        
                        fb1HueQuantizeLfoAmp = 0;
                        fb1SaturationQuantizeLfoAmp = 0;
                        fb1BrightQuantizeLfoAmp = 0;
                        fb1HueQuantizeMixLfoAmp = 0.0;
                        fb1SaturationQuantizeMixLfoAmp = 0.0;
                        fb1BrightQuantizeMixLfoAmp = 0.0;
                        fb1HueDitherMixLfoAmp = 0.0;
                        fb1HueDitherAmountLfoAmp = 0;
                        fb1SaturationDitherMixLfoAmp = 0.0;
                        fb1SaturationDitherAmountLfoAmp = 0;
                        fb1BrightDitherMixLfoAmp = 0.0;
                        fb1BrightDitherAmountLfoAmp = 0;
                    }
                    if (ImGui::CollapsingHeader("quantize lfos")) {
                        ImGui::SliderFloat("fb1HueQuantizeMixLfo_rate", &fb1HueQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1HueQuantizeMixLfoAmp", &fb1HueQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb1HueQuantizeLfo_rate", &fb1HueQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1HueQuantizeLfoAmp", &fb1HueQuantizeLfoAmp, -fb1HueQuantizeRange, fb1HueQuantizeRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb1SaturationQuantizeMix_lfo_rate", &fb1SaturationQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1SaturationQuantizeMixLfoAmp", &fb1SaturationQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb1SaturationQuantize_lfo_rate", &fb1SaturationQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1SaturationQuantizeLfoAmp", &fb1SaturationQuantizeLfoAmp, -fb1SaturationQuantizeRange, fb1SaturationQuantizeRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb1BrightQuantizeMix_lfo_rate", &fb1BrightQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1BrightQuantizeMixLfoAmp", &fb1BrightQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb1BrightQuantize_lfo_rate", &fb1BrightQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1BrightQuantizeLfoAmp", &fb1BrightQuantizeLfoAmp, -fb1BrightQuantizeRange, fb1BrightQuantizeRange);
                    }
                    ImGui::Separator();
                    if (ImGui::CollapsingHeader("dither lfos")) {
                        ImGui::SliderFloat("fb1HueDitherMixLfo_rate", &fb1HueDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1HueDitherMixLfoAmp", &fb1HueDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb1HueDitherLfo_rate", &fb1HueDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1HueDitherLfoAmp", &fb1HueDitherAmountLfoAmp, -fb1HueDitherRange, fb1HueDitherRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb1SaturationDitherMix_lfo_rate", &fb1SaturationDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1SaturationDitherMixLfoAmp", &fb1SaturationDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb1SaturationDither_lfo_rate", &fb1SaturationDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1SaturationDitherLfoAmp", &fb1SaturationDitherAmountLfoAmp, -fb1SaturationDitherRange, fb1SaturationDitherRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb1BrightDitherMix_lfo_rate", &fb1BrightDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1BrightDitherMixLfoAmp", &fb1BrightDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb1BrightDither_lfo_rate", &fb1BrightDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb1BrightDitherLfoAmp", &fb1BrightDitherAmountLfoAmp, -fb1BrightDitherRange, fb1BrightDitherRange);
                    }
                }
                if (ImGui::CollapsingHeader("geo1 lfo")){
                    if (ImGui::Button("reset geo1 lfo")) {
                        fb1XDisplaceLfoTheta = 0.0;
                        fb1YDisplaceLfoTheta = 0.0;
                        fb1ZDisplaceLfoTheta = 0.0;
                        fb1RotateLfoTheta = 0;
                        fb1ShearMatrixLfoTheta.set(0,0,0,0);
                        
                        fb1XDisplaceLfoAmp = 0.0;
                        fb1YDisplaceLfoAmp = 0.0;
                        fb1ZDisplaceLfoAmp = 0.0;
                        fb1RotateLfoAmp = 0;
                        fb1ShearMatrixLfoAmp.set(0, 0, 0, 0);
                    }
                    ImGui::SliderFloat("fb1XDisplace_lfo_rate", &fb1XDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1XDisplace_lfo_amp", &fb1XDisplaceLfoAmp, -fb1XDisplaceRange, fb1XDisplaceRange);
                    ImGui::SliderFloat("fb1YDisplace_lfo_rate", &fb1YDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1YDisplace_lfo_amp", &fb1YDisplaceLfoAmp, -fb1YDisplaceRange, fb1YDisplaceRange);
                    ImGui::SliderFloat("fb1ZDisplace_lfo_rate", &fb1ZDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1ZDisplace_lfo_amp", &fb1ZDisplaceLfoAmp, -fb1ZDisplaceRange, fb1ZDisplaceRange);
                    ImGui::SliderFloat("fb1Rotate_lfo_rate", &fb1RotateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1RotateLfoAmp", &fb1RotateLfoAmp, -fb1ZRotateRange, fb1ZRotateRange);
                    
                    ImGui::SliderFloat("fb1 Shear matrix 1 lfo rate", &fb1ShearMatrixLfoTheta.x, .0f, lfom);
                    ImGui::SliderFloat("fb1 Shear matrix 1 lfo amp", &fb1ShearMatrixLfoAmp.x, -fb1ShearMatrixRange.x, fb1ShearMatrixRange.x);
                    ImGui::SliderFloat("fb1 Shear matrix 2 lfo rate", &fb1ShearMatrixLfoTheta.y, .0f, lfom);
                    ImGui::SliderFloat("fb1 Shear matrix 2 lfo amp", &fb1ShearMatrixLfoAmp.y, -fb1ShearMatrixRange.y, fb1ShearMatrixRange.y);
                    ImGui::SliderFloat("fb1 Shear matrix 3 lfo rate", &fb1ShearMatrixLfoTheta.z, .0f, lfom);
                    ImGui::SliderFloat("fb1 Shear matrix 3 lfo amp", &fb1ShearMatrixLfoAmp.z, -fb1ShearMatrixRange.z, fb1ShearMatrixRange.z);
                    ImGui::SliderFloat("fb1 Shear matrix 4 lfo rate", &fb1ShearMatrixLfoTheta.w, .0f, lfom);
                    ImGui::SliderFloat("fb1 Shear matrix 4 lfo amp", &fb1ShearMatrixLfoAmp.w, -fb1ShearMatrixRange.w, fb1ShearMatrixRange.w);
                }
                if (ImGui::CollapsingHeader("geo2 lfo")) {
                    if (ImGui::Button("reset geo2 lfo")) {
                        fb1FisheyeAmountLfoTheta = 0;
                        fb1FisheyeXLfoTheta = 0;
                        fb1FisheyeYLfoTheta = 0;
                        fb1SpiralAmountLfoTheta = 0;
                        fb1SpiralAngleLfoTheta = 0;
                        fb1SpiralXLfoTheta = 0;
                        fb1SpiralYLfoTheta = 0;
                        fb1KaleidoscopeSegmentsLfoTheta = 0;
                        fb1KaleidoscopeSliceLfoTheta = 0;
                        
                        fb1FisheyeAmountLfoAmp = 0;
                        fb1FisheyeXLfoAmp = 0;
                        fb1FisheyeYLfoAmp = 0;
                        fb1SpiralAmountLfoAmp = 0;
                        fb1SpiralAngleLfoAmp = 0;
                        fb1SpiralXLfoAmp = 0;
                        fb1SpiralYLfoAmp = 0;
                        fb1KaleidoscopeSegmentsLfoAmp = 0;
                        fb1KaleidoscopeSliceLfoAmp = 0;
                    }
                    //geo 2 lfos
                    ImGui::SliderFloat("fb1 fisheye amount lfo rate", &fb1FisheyeAmountLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1 fisheye amount lfo amp", &fb1FisheyeAmountLfoAmp, -fb1FisheyeAmountRange, fb1FisheyeAmountRange);
                    ImGui::SliderFloat("fb1 fisheye x lfo rate", &fb1FisheyeXLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1 fisheye x lfo amp", &fb1FisheyeXLfoAmp, -fb1FisheyeXRange, fb1FisheyeXRange);
                    ImGui::SliderFloat("fb1 fisheye y lfo rate", &fb1FisheyeYLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1 fisheye y lfo amp", &fb1FisheyeYLfoAmp, -fb1FisheyeYRange, fb1FisheyeYRange);
                    
                    ImGui::SliderFloat("fb1 spiral amount lfo rate", &fb1SpiralAmountLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1 spiral amount lfo amp", &fb1SpiralAmountLfoAmp, -fb1SpiralAmountRange, fb1SpiralAmountRange);
                    ImGui::SliderFloat("fb1 spiral angle lfo rate", &fb1SpiralAngleLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1 spiral angle lfo amp", &fb1SpiralAngleLfoAmp, -fb1SpiralAngleRange, fb1SpiralAngleRange);
                    ImGui::SliderFloat("fb1 spiral x lfo rate", &fb1SpiralXLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1 spiral x lfo amp", &fb1SpiralXLfoAmp, -fb1SpiralXRange, fb1SpiralXRange);
                    ImGui::SliderFloat("fb1 spiral y lfo rate", &fb1SpiralYLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1 spiral y lfo amp", &fb1SpiralYLfoAmp, -fb1SpiralYRange, fb1SpiralYRange);
                    
                    ImGui::SliderFloat("fb1 kaleidoscope segments lfo rate", &fb1KaleidoscopeSegmentsLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1 kaleidoscope segments lfo amp", &fb1KaleidoscopeSegmentsLfoAmp, 0, fb1KaleidoscopeSegmentsRange);
                    ImGui::SliderFloat("fb1 kaleidoscope slice lfo rate", &fb1KaleidoscopeSliceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb1 kaleidoscope slice lfo amp", &fb1KaleidoscopeSliceLfoAmp, -fb1KaleidoscopeSliceRange, fb1KaleidoscopeSliceRange);
                }
                
                if (ImGui::CollapsingHeader("pixelation"))
                {
                    if (ImGui::Button("reset pixelation lfo")) {
                        fb1XPixelScaleLfoTheta = 0;
                        fb1XPixelScaleLfoAmp = 0;
                        fb1YPixelScaleLfoTheta = 0;
                        fb1YPixelScaleLfoAmp = 0;
                        fb1PixelMixLfoTheta = 0;
                        fb1PixelMixLfoAmp = 0;
                        fb1PixelBrightscaleLfoTheta = 0;
                        fb1PixelBrightscaleLfoAmp = 0;
                    }
                    //ImGui::Text("Love Flange Orgasms s");
                    ImGui::SliderFloat("fb1 pixel scale_x_rate", &fb1XPixelScaleLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb1 pixel scale_x_amp", &fb1XPixelScaleLfoAmp, -256.0f, 256.0f);
                    ImGui::SliderFloat("fb1 pixel scale_y_rate", &fb1YPixelScaleLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb1 pixel scale_y_amp", &fb1YPixelScaleLfoAmp, -256.0f, 256.0f);
                    ImGui::SliderFloat("fb1 pixel mix_rate", &fb1PixelMixLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb1 pixel mix_amp", &fb1PixelMixLfoAmp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb1 pixel bright scale rate", &fb1PixelBrightscaleLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb1 pixel bright scale amp", &fb1PixelBrightscaleLfoAmp, -2.0f, 2.0f);
                }
            }//endlfo folder
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        //fb2
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 4*gui_vscaler-20));
        //fb2
        if (ofxImGui::BeginWindow("fb2", mainSettings, false)){
            if (ImGui::Button("reset all")) {
                fb2ResetAll();
            }
            if (ImGui::CollapsingHeader("parameters")){
                if (ImGui::Button("reset parameters")) {
                    fb2ResetAllParameters();
                }
                ImGui::SliderInt("fb2DelayAmount", &fb2DelayAmount, 0, fbob - 1);
                ImGui::Checkbox("tex_mod", &fb2TexmodSwitch);
                const char* items[] = { "channel 1","channel 2" };
                static int item_current = 0;
                ImGui::Combo("texmod select", &item_current, items, IM_ARRAYSIZE(items));
                fb2TexmodSelect=item_current;
                
                if (ImGui::CollapsingHeader("mix and key")){
                    static int item_current0 = 0;
                    static int item_current1 = 0;
                    static int item_current2 = 0;
                    static int item_current3 = 0;
                    static int item_current4 = 0;
                    static int item_current5 = 0;
                    if ( (ImGui::Button("reset mix and key")) ) {
                        fb2LumakeyLevel = 0;
                        fb2KeyThreshold = 0;
                        fb2ChromakeyRed = 0;
                        fb2ChromakeyGreen = 0;
                        fb2ChromakeyBlue = 0;
                        fb2KeySoft = 0;
                        fb2MaskX = 0;
                        fb2MaskY = 0;
                        fb2MaskZ = 1.0;
                        fb2MaskRotate = 0;
                        fb2MaskTileAmount = 1.0;
                        fb2MaskTexmodOffset = 0;
                        fb2MaskTexmodQuantizeAmount = 1.0;
                        fb2MaskTexmodQuantizeMix = 1.0;
                        item_current0 = 0;
                        item_current1 = 0;
                        item_current2 = 0;
                        item_current3 = 0;
                        item_current4 = 0;
                        item_current5 = 0;
                        fb2Mix = 0;
                        
                        fb2LumakeyLevelTexmod = 0.0;
                        fb2ChromakeyRedTexmod = 0;
                        fb2ChromakeyGreenTexmod = 0;
                        fb2ChromakeyBlueTexmod = 0;
                        fb2KeyThresholdTexmod = 0.0;
                        fb2KeySoftTexmod = 0;
                        fb2MixTexmod = .0;
                        fb2MaskXTexmod = 0;
                        fb2MaskYTexmod = 0;
                        fb2MaskZTexmod = 0.0;
                        fb2MaskRotateTexmod = 0;
                        fb2MaskTileAmountTexmod = 0.0;
                    }
                    
                    const char* items0[] = { "Input1->fb2","fb2->Input1" };
                    ImGui::Combo("fb2 mix and key order", &item_current0, items0, IM_ARRAYSIZE(items0));
                    fb2KeyOrder = item_current0;
                    
                    const char* items1[] = { "lerp", "add","difference","mult","dodge" };
                    ImGui::Combo("fb2 mix Type", &item_current1, items1, IM_ARRAYSIZE(items1));
                    fb2MixType = item_current1;
                    
                    if (fb2TexmodSwitch == false) {
                        ImGui::SliderFloat("fb2 mix", &fb2Mix, -2.0f, 2.0f);
                    }
                    if (fb2TexmodSwitch == true) {
                        ImGui::SliderFloat("texmod fb2 mix", &fb2MixTexmod, -2.0f, 2.0f);
                    }
                    const char* items2[] = { "clamp", "wrap","foldover" };
                    ImGui::Combo("fb2 Mix overflow", &item_current2, items2, IM_ARRAYSIZE(items2));
                    fb2MixOverflow = item_current2;
                    
                    const char* items3[] = { "Lumakey","Chromakey","wipePattern" };
                    ImGui::Combo("fb2 key mode", &item_current3, items3, IM_ARRAYSIZE(items3));
                    fb2KeyMode = item_current3;
                    
                    if (fb2KeyMode == 0) {
                        if (fb2TexmodSwitch == false) {
                            ImGui::SliderFloat("fb2 lumakey level", &fb2LumakeyLevel, 0.0f, 1.0f);
                        }
                        if (fb2TexmodSwitch == true) {
                            ImGui::SliderFloat("texmod fb2 lumakey level", &fb2LumakeyLevelTexmod, .0f, 1.0f);
                        }
                    }
                    if (fb2KeyMode == 1) {
                        if (fb2TexmodSwitch == false) {
                            ImGui::SliderFloat("fb2 Chromakey Red", &fb2ChromakeyRed, 0.0f, 1.0f);
                            ImGui::SliderFloat("fb2 Chromakey Green", &fb2ChromakeyGreen, 0.0f, 1.0f);
                            ImGui::SliderFloat("fb2 Chromakey Blue", &fb2ChromakeyBlue, 0.0f, 1.0f);
                        }
                        if (fb2TexmodSwitch == true) {
                            ImGui::SliderFloat("texmod fb2 Chromakey Red", &fb2ChromakeyRedTexmod, 0.0f, 1.0f);
                            ImGui::SliderFloat("texmod fb2 Chromakey Green", &fb2ChromakeyGreenTexmod, 0.0f, 1.0f);
                            ImGui::SliderFloat("texmod fb2 Chromakey Blue", &fb2ChromakeyBlueTexmod, 0.0f, 1.0f);
                        }
                        ImGui::ColorButton("testingColorButton", ImVec4(fb2ChromakeyRed, fb2ChromakeyGreen, fb2ChromakeyBlue, 1.0), 0, ImVec2(20, 20));
                    }
                    if (fb2KeyMode !=2) {
                        if (fb2TexmodSwitch == false) {
                            ImGui::SliderFloat("fb2 key threshold", &fb2KeyThreshold, 0.0f, rootThree);
                            ImGui::SliderFloat("fb2 key soft", &fb2KeySoft, 0.0f, 1.0f);
                        }
                        if (fb2TexmodSwitch == true) {
                            ImGui::SliderFloat("texmod fb2 key threshold", &fb2KeyThresholdTexmod, .0f, rootThree);
                            ImGui::SliderFloat("texmod fb2 key soft", &fb2KeySoftTexmod, 0.0f, 1.0f);
                        }
                    }
                    if (fb2KeyMode == 2) {
                        //when wipe pattern is selected we need to change chroma/lumakey values to 0
                        fb2LumakeyLevel = 0;
                        fb2KeyThreshold = 0;
                        fb2ChromakeyRed = 0;
                        fb2ChromakeyGreen = 0;
                        fb2ChromakeyBlue = 0;
                        fb2KeySoft = 0;
                        
                        //drop down menu for mask selection
                        const char* items4[] = { "mask1","mask2","mask3","mask4","texMod" };
                        ImGui::Combo("fb2 mask select", &item_current4, items4, IM_ARRAYSIZE(items4));
                        fb2MaskSelect = item_current4;
                        
                        //want to figure out way to get variables in here as to global width
                        if (fb2MaskSelect != 4) {
                            if (fb2TexmodSwitch == false) {
                                ImGui::SliderFloat("fb2 mask x", &fb2MaskX, -outWidth * .5f, outWidth*.5f);
                                ImGui::SliderFloat("fb2 mask y", &fb2MaskY, -outHeight * .5f, outHeight*.5f);
                                ImGui::SliderFloat("fb2 mask z", &fb2MaskZ, 0.0f, 3.0f);
                                ImGui::SliderFloat("fb2 mask rotate", &fb2MaskRotate, -TWO_PI, TWO_PI);
                                ImGui::SliderFloat("fb2 mask tile amount", &fb2MaskTileAmount, 0.0f, 2.0f);
                            }
                            if(fb2TexmodSwitch == true) {
                                ImGui::SliderFloat("texmod fb2 mask x", &fb2MaskXTexmod, -outWidth * .5f, outWidth*.5f);
                                ImGui::SliderFloat("texmod fb2 mask y", &fb2MaskYTexmod, -outHeight * .5f, outHeight*.5f);
                                ImGui::SliderFloat("texmod fb2 mask z", &fb2MaskZTexmod, -3.0f, 3.0f);
                                ImGui::SliderFloat("texmod fb2 mask rotate", &fb2MaskRotateTexmod, -TWO_PI, TWO_PI);
                                ImGui::SliderFloat("texmod fb2 mask tile amount", &fb2MaskTileAmountTexmod, -2.0f, 2.0f);
                            }
                            const char* items5[] = { "Off","Basic","basic alt rotate","spiral" };
                            ImGui::Combo("fb2 mask tile Mode", &item_current5, items5, IM_ARRAYSIZE(items5));
                            fb2MaskTileMode = item_current5;
                        }
                        if (fb2MaskSelect == 4) {
                            ImGui::SliderFloat("fb2 mask texmod offset", &fb2MaskTexmodOffset, -1.0f, 1.0f);
                            ImGui::SliderFloat("fb2 mask texmod quantize mix", &fb2MaskTexmodQuantizeMix, .0f, 1.0f);
                            ImGui::SliderInt("fb2 mask texmod quantize amount", &fb2MaskTexmodQuantizeAmount, 1, 32);
                        }
                    }
                }
                if (ImGui::CollapsingHeader("color space 1")){
                    static int item_current0 = 0;
                    static int item_current1 = 0;
                    if (ImGui::TreeNode(" color 1 ranges")) {
                        ImGui::SliderFloat("fb2 hue offset range", &fb2HueOffsetRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb2 saturation offset range", &fb2SaturationOffsetRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb2 bright offset range", &fb2BrightOffsetRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb2 hue attenuate range", &fb2HueAttenuateRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb2 saturation attenuate range", &fb2SaturationAttenuateRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb2 bright attenuate range", &fb2BrightAttenuateRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb2 hue Shaper range", &fb2HueShaperRange, .0001f, 5.0f);
                        ImGui::SliderFloat("fb2 hue powmap range", &fb2HuePowMapRange, .0001f, 5.0f);
                        ImGui::SliderFloat("fb2 saturation powmap range", &fb2SaturationPowMapRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb2 bright powmap range", &fb2BrightPowMapRange, .0001f, 20.0f);
                        ImGui::TreePop();
                    }
                    if ( (ImGui::Button("reset color 1"))  ) {
                        fb2HueOffset = 0.0;
                        fb2SaturationOffset = 0.0;
                        fb2BrightOffset = 0.0;
                        fb2HueAttenuate = 10.0;
                        fb2SaturationAttenuate = 10.0;
                        fb2BrightAttenuate = 10.0;
                        fb2HueShaper = 0.0;
                        fb2HuePowMap=1.0;
                        fb2SaturationPowMap=1.0;
                        fb2BrightPowMap=1.0;
                        fb2HueInvert = 0;
                        fb2SaturationInvert = 0;
                        fb2BrightInvert = 0;
                        
                        fb2HueShaperRange = 0.25;
                        fb2HueOffsetRange = .25;
                        fb2SaturationOffsetRange = 0.25;
                        fb2BrightOffsetRange = 0.25;
                        fb2HueAttenuateRange = 2.0;
                        fb2SaturationAttenuateRange = 2.0;
                        fb2BrightAttenuateRange = 2.0;
                        
                        fb2HueInvert = 0;
                        fb2SaturationInvert = 0;
                        fb2BrightInvert = 0;
                        
                        fb2SaturationOverflow = 0;
                        fb2BrightOverflow = 0;
                        fb2HuePowMapRange = .25;
                        fb2SaturationPowMapRange = .25;
                        fb2BrightPowMapRange = .25;
                        
                        fb2HueOffsetTexmod = 0.0;
                        fb2SaturationOffsetTexmod = 0.0;
                        fb2BrightOffsetTexmod = 0.0;
                        fb2HueAttenuateTexmod = 0.0;
                        fb2SaturationAttenuateTexmod = 0.0;
                        fb2BrightAttenuateTexmod = 0.0;
                        fb2HueShaperTexmod = 0.0;
                        fb2HuePowMapTexmod = .0;
                        fb2SaturationPowMapTexmod = .0;
                        fb2BrightPowMapTexmod = .0;
                        
                    }
                    
                    //EASTER EGG
                    //some combination of keypresses adds 1. crt overlay, 2. pixels in SD aspect ratio, 3. enuf dither to look like scanlines
                    //4. interlacing
                    if(fb2TexmodSwitch==false){
                        ImGui::SliderFloat("fb2 hue offset",&fb2HueOffset,-fb2HueOffsetRange,fb2HueOffsetRange);
                        ImGui::SliderFloat("fb2 saturation offset", &fb2SaturationOffset, -fb2SaturationOffsetRange, fb2SaturationOffsetRange);
                        ImGui::SliderFloat("fb2 bright offset", &fb2BrightOffset, -fb2BrightOffsetRange, fb2BrightOffsetRange);
                        ImGui::SliderFloat("fb2 hue attenuate", &fb2HueAttenuate, 10.0f-fb2HueAttenuateRange, 10.0f+fb2HueAttenuateRange);
                        ImGui::SliderFloat("fb2 saturation attenuate", &fb2SaturationAttenuate, 10.0f - fb2SaturationAttenuateRange, 10.0f + fb2SaturationAttenuateRange);
                        ImGui::SliderFloat("fb2 bright attenuate", &fb2BrightAttenuate, 10.0f - fb2BrightAttenuateRange, 10.0f + fb2BrightAttenuateRange);
                        ImGui::SliderFloat("fb2 hue Shaper", &fb2HueShaper, -fb2HueShaperRange, fb2HueShaperRange);
                        ImGui::SliderFloat("fb2 hue powmap", &fb2HuePowMap, 1.0f - fb2HuePowMapRange, 1.0f + fb2HuePowMapRange);
                        ImGui::SliderFloat("fb2 saturation powmap", &fb2SaturationPowMap, 1.0f - fb2SaturationPowMapRange, 1.0f + fb2SaturationPowMapRange);
                        ImGui::SliderFloat("fb2 bright powmap", &fb2BrightPowMap, 1.0f-fb2BrightPowMapRange, 1.0f+fb2BrightPowMapRange);
                    }
                    if (fb2TexmodSwitch == true) {
                        ImGui::SliderFloat("texmod fb2 hue offset", &fb2HueOffsetTexmod, -fb2HueOffsetRange * .1f, fb2HueOffsetRange*.1f);
                        ImGui::SliderFloat("texmod fb2 saturation offset", &fb2SaturationOffsetTexmod, -fb2SaturationOffsetRange * .1f, fb2SaturationOffsetRange*.1f);
                        ImGui::SliderFloat("texmod fb2 bright offset", &fb2BrightOffsetTexmod, -fb2BrightOffsetRange * .1f, fb2BrightOffsetRange*.1f);
                        ImGui::SliderFloat("texmod fb2HueAttenuate", &fb2HueAttenuateTexmod, -fb2HueAttenuateRange * .1f, fb2HueAttenuateRange*.1f);
                        ImGui::SliderFloat("texmod fb2SaturationAttenuate", &fb2SaturationAttenuateTexmod, -fb2SaturationAttenuateRange * .1f, fb2SaturationAttenuateRange*.1f);
                        ImGui::SliderFloat("texmod fb2BrightAttenuate", &fb2BrightAttenuateTexmod, -fb2BrightAttenuateRange * .1f, fb2BrightAttenuateRange*.1f);
                        ImGui::SliderFloat("texmod fb2 hue Shaper", &fb2HueShaperTexmod, -fb2HueShaperRange * .1f, fb2HueShaperRange*.1f);
                        ImGui::SliderFloat("texmod fb2 hue powmap", &fb2HuePowMapTexmod, -fb2HuePowMapRange, fb2HuePowMapRange);
                        ImGui::SliderFloat("texmod fb2 saturation powmap", &fb2SaturationPowMapTexmod, -fb2SaturationPowMapRange, fb2SaturationPowMapRange);
                        ImGui::SliderFloat("texmod fb2 bright powmap", &fb2BrightPowMapTexmod, -fb2BrightPowMapRange, fb2BrightPowMapRange);
                    }
                    ImGui::Checkbox("fb2HueInvert", &fb2HueInvert);
                    ImGui::Checkbox("fb2SaturationInvert", &fb2SaturationInvert);
                    ImGui::Checkbox("fb2BrightInvert", &fb2BrightInvert);
                    
                    const char* items0[] = { "clamp","wrap","fold" };
                    ImGui::Combo("saturation overflow", &item_current0, items0, IM_ARRAYSIZE(items0));
                    fb2SaturationOverflow = item_current0;
                    const char* items1[] = { "clamp","wrap","fold" };
                    ImGui::Combo("bright overflow", &item_current1, items1, IM_ARRAYSIZE(items1));
                    fb2BrightOverflow = item_current1;
                    //add wrap, fold, clamp for colors
                }
                if (ImGui::CollapsingHeader("color space 2")) {
                    if (ImGui::TreeNode(" color 2 ranges")) {
                        ImGui::SliderInt("fb2 hue dither range", &fb2HueDitherRange, 1, 512);
                        ImGui::SliderInt("fb2 saturation dither range", &fb2SaturationDitherRange, 1, 512);
                        ImGui::SliderInt("fb2 bright dither range", &fb2BrightDitherRange, 1, 512);
                        ImGui::SliderInt("fb2 hue quantize range", &fb2HueQuantizeRange, 1, 512);
                        ImGui::SliderInt("fb2 saturation quantize range", &fb2SaturationQuantizeRange, 1, 512);
                        ImGui::SliderInt("fb2 bright quantize range", &fb2BrightQuantizeRange, 1, 512);
                        ImGui::TreePop();
                    }
                    if ( (ImGui::Button("reset color 2"))  ) {
                        fb2HueQuantize = 128;
                        fb2SaturationQuantize = 128;
                        fb2BrightQuantize = 128;
                        fb2HueQuantizeMix = 0.0;
                        fb2SaturationQuantizeMix = 0.0;
                        fb2BrightQuantizeMix = 0.0;
                        fb2HueDitherMix = 0.0;
                        fb2HueDitherAmount = 64;
                        fb2SaturationDitherMix = 0.0;
                        fb2SaturationDitherAmount = 64;
                        fb2BrightDitherMix = 0.0;
                        fb2BrightDitherAmount = 64;
                        
                        fb2HueQuantizeTexmod = 0;
                        fb2SaturationQuantizeTexmod = 0;
                        fb2BrightQuantizeTexmod = 0;
                        fb2HueQuantizeMixTexmod = 0.0;
                        fb2SaturationQuantizeMixTexmod = 0.0;
                        fb2BrightQuantizeMixTexmod = 0.0;
                        fb2HueDitherMixTexmod = 0.0;
                        fb2HueDitherAmountTexmod = 0;
                        fb2SaturationDitherMixTexmod = 0.0;
                        fb2SaturationDitherAmountTexmod = 0;
                        fb2BrightDitherMixTexmod = 0.0;
                        fb2BrightDitherAmountTexmod = 0;
                    }
                    if (fb2TexmodSwitch == false) {
                        ImGui::SliderFloat("fb2 hue quantize mix", &fb2HueQuantizeMix, .0f, 1.0f);
                        ImGui::SliderInt("fb2 hue quantize amount", &fb2HueQuantize, 1, fb2HueQuantizeRange);
                        ImGui::SliderFloat("fb2 saturation quantize mix", &fb2SaturationQuantizeMix, .0f, 1.0f);
                        ImGui::SliderInt("fb2 saturation quantize amount", &fb2SaturationQuantize, 1, fb2SaturationQuantizeRange);
                        ImGui::SliderFloat("fb2 bright quantize mix", &fb2BrightQuantizeMix, .0f, 1.0f);
                        ImGui::SliderInt("fb2 bright quantize amount", &fb2BrightQuantize, 1, fb2BrightQuantizeRange);
                        ImGui::SliderFloat("fb2 hue dither mix", &fb2HueDitherMix, .0f, 1.0f);
                        ImGui::SliderInt("fb2 hue dither amount", &fb2HueDitherAmount, 1, fb2HueDitherRange);
                        ImGui::SliderFloat("fb2 saturation dither mix", &fb2SaturationDitherMix, .0f, 1.0f);
                        ImGui::SliderInt("fb2 saturation dither amount", &fb2SaturationDitherAmount, 1, fb2SaturationDitherRange);
                        ImGui::SliderFloat("fb2 bright dither mix", &fb2BrightDitherMix, .0f, 1.0f);
                        ImGui::SliderInt("fb2 bright dither amount", &fb2BrightDitherAmount, 1, fb2BrightDitherRange);
                    }
                    if (fb2TexmodSwitch == true) {
                        /*
                         ImGui::SliderFloat("texmod fb2 hue quantize mix", &fb2HueQuantizeMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb2 hue quantize amount", &fb2HueQuantizeTexmod, 1, fb2HueQuantizeRange);
                         ImGui::SliderFloat("texmod fb2 saturation quantize mix", &fb2SaturationQuantizeMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb2 saturation quantize amount", &fb2SaturationQuantizeTexmod, 1, fb2SaturationQuantizeRange);
                         ImGui::SliderFloat("texmod fb2 bright quantize mix", &fb2BrightQuantizeMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb2 bright quantize amount", &fb2BrightQuantizeTexmod, 1, fb2BrightQuantizeRange);
                         ImGui::SliderFloat("texmod fb2 hue dither mix", &fb2HueDitherMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb2 hue dither amount", &fb2HueDitherAmountTexmod, 1, fb2HueDitherRange);
                         ImGui::SliderFloat("texmod fb2 saturation dither mix", &fb2SaturationDitherMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb2 saturation dither amount", &fb2SaturationDitherAmountTexmod, 1, fb2SaturationDitherRange);
                         ImGui::SliderFloat("texmod fb2 bright dither mix", &fb2BrightDitherMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb2 bright dither amount", &fb2BrightDitherAmountTexmod, 1, fb2BrightDitherRange);
                         */
                    }
                    
                }
                if (ImGui::CollapsingHeader("geometry1")){
                    static int item_current2 = 0;
                    if (ImGui::TreeNode(" geo 1 ranges")) {
                        ImGui::SliderFloat("fb2 x displace range", &fb2XDisplaceRange, .0001f, 200.0f);
                        ImGui::SliderFloat("fb2 y displace range", &fb2YDisplaceRange, .0001f, 200.0f);
                        ImGui::SliderFloat("fb2 z displace range", &fb2ZDisplaceRange, .0001f, 100.0f);
                        ImGui::SliderFloat("fb2 rotate range", &fb2ZRotateRange, .0001f, TWO_PI);
                        ImGui::SliderFloat("fb2 shear matrix 1 Range", &fb2ShearMatrixRange.x, .0001f, 5.0f);
                        ImGui::SliderFloat("fb2 shear matrix 2 Range", &fb2ShearMatrixRange.y, .0001f, 5.0f);
                        ImGui::SliderFloat("fb2 shear matrix 3 Range", &fb2ShearMatrixRange.z, .0001f, 5.0f);
                        ImGui::SliderFloat("fb2 shear matrix 4 Range", &fb2ShearMatrixRange.w, .0001f, 5.0f);
                        
                        ImGui::TreePop();
                    }
                    if ( ImGui::Button("reset geo1") ) {
                        item_current2 = 0;
                        fb2XDisplace = 0.0;
                        fb2YDisplace = 0.0;
                        fb2ZDisplace = 100.0;
                        fb2Rotate = 0;
                        fb2ShearMatrix.set(0,0,0,0);
                        fb2ShearMatrixRange.set(0.25, 0.25, 0.25, 0.25);
                        fb2RotateMode = 0;
                        fb2HorizontalMirror = 0;
                        fb2VerticalMirror = 0;
                        fb2XDisplaceRange = 40;
                        fb2YDisplaceRange = 40;
                        fb2ZDisplaceRange = 10;
                        fb2ZRotateRange = PI;
                        
                        fb2XDisplaceTexmod=0.0;
                        fb2YDisplaceTexmod=0.0;
                        fb2ZDisplaceTexmod=0;
                        fb2RotateTexmod=0;
                        fb2ShearMatrixTexmod.set(0,0,0,0);
                    }
                    if(fb2TexmodSwitch==false){
                        ImGui::SliderFloat("fb2_x", &fb2XDisplace, -fb2XDisplaceRange, fb2XDisplaceRange);
                        ImGui::SliderFloat("fb2_y", &fb2YDisplace, -fb2YDisplaceRange, fb2YDisplaceRange);
                        ImGui::SliderFloat("fb2_z", &fb2ZDisplace,  100.0f-fb2ZDisplaceRange, 100.0f+fb2ZDisplaceRange);
                        ImGui::SliderFloat("fb2Rotate", &fb2Rotate, -fb2ZRotateRange, fb2ZRotateRange);
                        
                        ImGui::SliderFloat("fb2 Shear matrix 1", &fb2ShearMatrix.x, -fb2ShearMatrixRange.x, fb2ShearMatrixRange.x);
                        ImGui::SliderFloat("fb2 Shear matrix 2", &fb2ShearMatrix.y, -fb2ShearMatrixRange.y, fb2ShearMatrixRange.y);
                        ImGui::SliderFloat("fb2 Shear matrix 3", &fb2ShearMatrix.z, -fb2ShearMatrixRange.z, fb2ShearMatrixRange.z);
                        ImGui::SliderFloat("fb2 Shear matrix 4", &fb2ShearMatrix.w, -fb2ShearMatrixRange.w, fb2ShearMatrixRange.w);
                    }
                    if(fb2TexmodSwitch==true){
                        ImGui::SliderFloat("texmod fb2_x", &fb2XDisplaceTexmod, -fb2XDisplaceRange, fb2XDisplaceRange);
                        ImGui::SliderFloat("texmod fb2_y", &fb2YDisplaceTexmod,  -fb2YDisplaceRange, fb2YDisplaceRange);
                        ImGui::SliderFloat("texmod fb2_z", &fb2ZDisplaceTexmod,  -fb2ZDisplaceRange*.01, fb2ZDisplaceRange*.01);
                        ImGui::SliderFloat("texmod fb2Rotate", &fb2RotateTexmod, -fb2ZRotateRange, fb2ZRotateRange);
                        
                        ImGui::SliderFloat("texmod fb2 Shear matrix 1", &fb2ShearMatrixTexmod.x, -fb2ShearMatrixRange.x, fb2ShearMatrixRange.x);
                        ImGui::SliderFloat("texmod fb2 Shear matrix 2", &fb2ShearMatrixTexmod.y, -fb2ShearMatrixRange.y, fb2ShearMatrixRange.y);
                        ImGui::SliderFloat("texmod fb2 Shear matrix 3", &fb2ShearMatrixTexmod.z, -fb2ShearMatrixRange.z, fb2ShearMatrixRange.z);
                        ImGui::SliderFloat("texmod fb2 Shear matrix 4", &fb2ShearMatrixTexmod.w, -fb2ShearMatrixRange.w, fb2ShearMatrixRange.w);
                    }
                    const char* items2[] = { "clamp","toroid","mirror" };
                    ImGui::Combo("Geometry overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                    fb2_toroid_switch = item_current2;
                    
                    ImGui::Checkbox("fb2_h_mirror", &fb2HorizontalMirror);
                    ImGui::Checkbox("fb2_v_mirror", &fb2VerticalMirror);
                    ImGui::Checkbox("fb2RotateMode", &fb2RotateMode);
                }
                if (ImGui::CollapsingHeader("geometry2")) {
                    if (ImGui::TreeNode("geo 2 ranges")) {
                        ImGui::SliderFloat("fb2 fisheye amount range", &fb2FisheyeAmountRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb2 fisheye X range", &fb2FisheyeXRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb2 fisheye Y range", &fb2FisheyeYRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb2 spiral amount range", &fb2SpiralAmountRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb2 spiral angle range", &fb2SpiralAngleRange, .0001f, TWO_PI);
                        ImGui::SliderFloat("fb2 spiral X range", &fb2SpiralXRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb2 spiral Y range", &fb2SpiralYRange, .0001f, 10.0f);
                        ImGui::SliderInt("fb2 kaleidoscope segments range", &fb2KaleidoscopeSegmentsRange, 1, 100);
                        ImGui::SliderFloat("fb2 kaleidoscope slice range", &fb2KaleidoscopeSliceRange,.01,TWO_PI);
                        
                        ImGui::TreePop();
                    }
                    if (ImGui::Button("reset geo2")) {
                        fb2FisheyeAmount = 0;
                        fb2FisheyeX = 0;
                        fb2FisheyeY = 0;
                        fb2SpiralAmount = 0;
                        fb2SpiralAngle = 0;
                        fb2SpiralX = 0;
                        fb2SpiralY = 0;
                        fb2KaleidoscopeSegments = 0;
                        fb2KaleidoscopeSlice = 0;
                        
                        fb2FisheyeAmountRange = .15;
                        fb2FisheyeXRange = .25;
                        fb2FisheyeYRange = .25;
                        fb2SpiralAmountRange = .15;
                        fb2SpiralAngleRange = PI;
                        fb2SpiralXRange = .25;
                        fb2SpiralYRange = .25;
                        fb2KaleidoscopeSegmentsRange = 21;
                        fb2KaleidoscopeSliceRange = PI;
                        
                        fb2FisheyeAmountTexmod = 0;
                        fb2FisheyeXTexmod = 0;
                        fb2FisheyeYTexmod = 0;
                        fb2SpiralAmountTexmod = 0;
                        fb2SpiralAngleTexmod = 0;
                        fb2SpiralXTexmod = 0;
                        fb2SpiralYTexmod = 0;
                        fb2KaleidoscopeSegmentsTexmod = 0;
                        fb2KaleidoscopeSliceTexmod = 0;
                        
                    }
                    
                    if(fb2TexmodSwitch==false){
                        ImGui::SliderFloat("fb2 fisheye amount", &fb2FisheyeAmount, -fb2FisheyeAmountRange, fb2FisheyeAmountRange);
                        ImGui::SliderFloat("fb2 fisheye x", &fb2FisheyeX, -fb2FisheyeXRange, fb2FisheyeXRange);
                        ImGui::SliderFloat("fb2 fisheye y", &fb2FisheyeY, -fb2FisheyeYRange, fb2FisheyeYRange);
                        
                        ImGui::SliderFloat("fb2 spiral amount", &fb2SpiralAmount, -fb2SpiralAmountRange, fb2SpiralAmountRange);
                        ImGui::SliderFloat("fb2 spiral angle", &fb2SpiralAngle, -fb2SpiralAngleRange, fb2SpiralAngleRange);
                        ImGui::SliderFloat("fb2 spiral x", &fb2SpiralX, -fb2SpiralXRange, fb2SpiralXRange);
                        ImGui::SliderFloat("fb2 spiral y", &fb2SpiralY, -fb2SpiralYRange, fb2SpiralYRange);
                        
                        ImGui::SliderInt("fb2 kaleidoscope segments", &fb2KaleidoscopeSegments, 0, fb2KaleidoscopeSegmentsRange);
                        ImGui::SliderFloat("fb2 kaleidoscope slice", &fb2KaleidoscopeSlice, -fb2KaleidoscopeSliceRange, fb2KaleidoscopeSliceRange);
                    }
                    
                    if(fb2TexmodSwitch==true){
                        ImGui::SliderFloat("texmod fb2 fisheye amount", &fb2FisheyeAmountTexmod, -fb2FisheyeAmountRange, fb2FisheyeAmountRange);
                        ImGui::SliderFloat("texmod fb2 fisheye x", &fb2FisheyeXTexmod, -fb2FisheyeXRange, fb2FisheyeXRange);
                        ImGui::SliderFloat("texmod fb2 fisheye y", &fb2FisheyeYTexmod, -fb2FisheyeYRange, fb2FisheyeYRange);
                        
                        ImGui::SliderFloat("texmod fb2 spiral amount", &fb2SpiralAmountTexmod, -fb2SpiralAmountRange, fb2SpiralAmountRange);
                        ImGui::SliderFloat("texmod fb2 spiral angle", &fb2SpiralAngleTexmod, -fb2SpiralAngleRange, fb2SpiralAngleRange);
                        ImGui::SliderFloat("texmod fb2 spiral x", &fb2SpiralXTexmod, -fb2SpiralXRange, fb2SpiralXRange);
                        ImGui::SliderFloat("texmod fb2 spiral y", &fb2SpiralYTexmod, -fb2SpiralYRange, fb2SpiralYRange);
                        
                        ImGui::SliderFloat("texmod fb2 kaleidoscope segments", &fb2KaleidoscopeSegmentsTexmod, 0, fb2KaleidoscopeSegmentsRange);
                        ImGui::SliderFloat("texmod fb2 kaleidoscope slice", &fb2KaleidoscopeSliceTexmod, -fb2KaleidoscopeSliceRange, fb2KaleidoscopeSliceRange);
                    }
                    
                }
                
                //ADD THE PIXELS HERE
                if (ImGui::CollapsingHeader("pixelate"))
                {
                    if (ImGui::Button("reset pixelate")) {
                        fb2PixelXYLock = 1;
                        fb2XPixelScale = 64;
                        fb2YPixelScale = 64;
                        fb2PixelMix = 1;
                        fb2PixelBrightscale = 0;
                        
                        fb2XPixelScaleTexmod=0;
                        fb2YPixelScaleTexmod=0;
                        fb2PixelMixTexmod=0;
                        fb2PixelBrightscaleTexmod=0;
                    }
                    ImGui::Checkbox("fb2 pixelate", &fb2PixelSwitch);
                    ImGui::Checkbox("fb2 pixelXY lock", &fb2PixelXYLock);
                    
                    if (fb2TexmodSwitch == false) {
                        ImGui::SliderInt("fb2 pixel scale x", &fb2XPixelScale, .0f, 256.0f);
                        if (fb2PixelXYLock == 1) {
                            ImGui::SliderInt("fb2 pixel scale y", &fb2XPixelScale, .0f, 256.0f);
                        }
                        if (fb2PixelXYLock == 0) {
                            ImGui::SliderInt("fb2 pixel scale y", &fb2YPixelScale, .0f, 256.0f);
                        }
                        ImGui::SliderFloat("fb2 pixel mix", &fb2PixelMix, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb2 bright scale", &fb2PixelBrightscale, -2.0f, 2.0f);
                    }
                    if (fb2TexmodSwitch == true) {
                        ImGui::SliderInt("fb2 texmod pixel scale x", &fb2XPixelScaleTexmod, -256.0f, 256.0f);
                        if (fb2PixelXYLock == 1) {
                            ImGui::SliderInt("fb2 texmod pixel scale y", &fb2XPixelScaleTexmod, -256.0f, 256.0f);
                        }
                        if (fb2PixelXYLock == 0) {
                            ImGui::SliderInt("fb2 texmod pixel scale y", &fb2YPixelScaleTexmod, -256.0f, 256.0f);
                        }
                        ImGui::SliderFloat("fb2 texmod pixel mix", &fb2PixelMixTexmod, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb2 texmod bright scale", &fb2PixelBrightscaleTexmod, -2.0f, 2.0f);
                    }
                }
            }//end collapsing folder
            ImGui::Separator();
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Loose Floating Object s");
                if (ImGui::Button("reset lfo")) {
                    fb2ResetAllLfo();
                }
                if (ImGui::CollapsingHeader("mix and delay amount lfo")){
                    if (ImGui::Button("reset mix and delay lfo")) {
                        fb2_delay_lfo_theta = 0;
                        fb2DelayLfoAmp = 0;
                        fb2MixLfoTheta = 0;
                        fb2MixLfoAmp = 0;
                        fb2LumakeyLevelLfoTheta = 0;
                        fb2LumakeyLevelLfoAmp = 0;
                        fb2ChromakeyRedLfoTheta = 0;
                        fb2ChromakeyRedLfoAmp = 0;
                        fb2ChromakeyGreenLfoTheta = 0;
                        fb2ChromakeyGreenLfoAmp = 0;
                        fb2ChromakeyBlueLfoTheta = 0;
                        fb2ChromakeyBlueLfoAmp = 0;
                        fb2KeyThresholdLfoTheta = 0;
                        fb2KeyThresholdLfoAmp = 0;
                        fb2KeySoftLfoTheta = 0;
                        fb2KeySoftLfoAmp = 0;
                        fb2MaskXLfoTheta = 0;
                        fb2MaskXLfoAmp = 0;
                        fb2MaskYLfoTheta = 0;
                        fb2MaskYLfoAmp = 0;
                        fb2MaskZLfoTheta = 0.0;
                        fb2MaskZLfoAmp = 0.0;
                        fb2MaskRotateLfoTheta = 0;
                        fb2MaskRotateLfoAmp = 0;
                        fb2MaskTileAmountLfoTheta = 0.0;
                        fb2MaskTileAmountLfoAmp = 0.0;
                        fb2MaskTexmodOffsetLfoTheta = 0;
                        fb2MaskTexmodOffsetLfoAmp = 0;
                        fb2MaskTexmodQuantizeAmountLfoTheta = 0.0;
                        fb2MaskTexmodQuantizeAmountLfoAmp = 0.0;
                        fb2MaskTexmodQuantizeMixLfoTheta = 0.0;
                        fb2MaskTexmodQuantizeMixLfoAmp = 0.0;
                    }
                    ImGui::SliderFloat("fb2DelayLfoRate", &fb2_delay_lfo_theta, .0f, 10.0f);
                    ImGui::SliderFloat("fb2DelayLfoAmp", &fb2DelayLfoAmp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb2MixLfoRate", &fb2MixLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2MixLfoAmp", &fb2MixLfoAmp, -2.0f, 2.0f);
                    //Not Wipes
                    if (fb2KeyMode != 2) {
                        //luma
                        if (fb2KeyMode == 0) {
                            ImGui::SliderFloat("fb2LumakeyLevelLfoRate", &fb2LumakeyLevelLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2LumakeyLevelLfoAmp", &fb2LumakeyLevelLfoAmp, -1.0f, 1.0f);
                        }
                        if (fb2KeyMode == 1) {
                            ImGui::SliderFloat("fb2ChromakeyRedLfoRate", &fb2ChromakeyRedLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2ChromakeyRedLfoAmp", &fb2ChromakeyRedLfoAmp, -1.0f, 1.0f);
                            ImGui::SliderFloat("fb2ChromakeyGreenLfoRate", &fb2ChromakeyGreenLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2ChromakeyGreenLfoAmp", &fb2ChromakeyGreenLfoAmp, -1.0f, 1.0f);
                            ImGui::SliderFloat("fb2ChromakeyBlueLfoRate", &fb2ChromakeyBlueLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2ChromakeyBlueLfoAmp", &fb2ChromakeyBlueLfoAmp, -1.0f, 1.0f);
                        }
                        ImGui::SliderFloat("fb2Keythreshold_lfo_rate", &fb2KeyThresholdLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2KeyThresholdLfoAmp", &fb2KeyThresholdLfoAmp, -rootThree, rootThree);
                        ImGui::SliderFloat("fb2KeySoftLfoRate", &fb2KeySoftLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2KeySoftLfoAmp", &fb2KeySoftLfoAmp, -1.0, 1.0);
                    }
                    if (fb2KeyMode == 2) {
                        fb2ChromakeyRedLfoAmp = 0;
                        fb2ChromakeyGreenLfoAmp = 0;
                        fb2ChromakeyBlueLfoAmp = 0;
                        fb2LumakeyLevelLfoAmp = 0;
                        fb2KeyThresholdLfoAmp = 0;
                        //regular wipes
                        if (fb2MaskSelect != 4) {
                            ImGui::SliderFloat("fb2MaskXLfoRate", &fb2MaskXLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2MaskXLfoAmp", &fb2MaskXLfoAmp, -outWidth * .5f, outWidth*.5f);
                            ImGui::SliderFloat("fb2MaskYLfoRate", &fb2MaskYLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2MaskYLfoAmp", &fb2MaskYLfoAmp, -outHeight * .5f, outHeight*.5f);
                            ImGui::SliderFloat("fb2MaskZLfoRate", &fb2MaskZLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2MaskZLfoAmp", &fb2MaskZLfoAmp, -3.0f, 3.0f);
                            ImGui::SliderFloat("fb2MaskRotateLfoRate", &fb2MaskRotateLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2MaskRotateLfoAmp", &fb2MaskRotateLfoAmp, -TWO_PI, TWO_PI);
                            ImGui::SliderFloat("fb2MaskTileAmountLfoRate", &fb2MaskTileAmountLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2MaskTileAmountLfoAmp", &fb2MaskTileAmountLfoAmp, -3.0f, 3.0f);
                        }
                        //texmodWipes
                        if (fb2MaskSelect == 4) {
                            ImGui::SliderFloat("fb2MaskTexmodOffsetLfoRate", &fb2MaskTexmodOffsetLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2MaskTexmodOffsetLfoAmp", &fb2MaskTexmodOffsetLfoAmp, -1.0, 1.0);
                            ImGui::SliderFloat("fb2MaskTexmodQuantizeAmountLfoRate", &fb2MaskTexmodQuantizeAmountLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2MaskTexmodQuantizeAmountLfoAmp", &fb2MaskTexmodQuantizeAmountLfoAmp, 0.0, 32.0);
                            ImGui::SliderFloat("fb2MaskTexmodQuantizeMixLfoRate", &fb2MaskTexmodQuantizeMixLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb2MaskTexmodQuantizeMixLfoAmp", &fb2MaskTexmodQuantizeMixLfoAmp, 0.0, 1.0);
                        }
                    }
                }
                if (ImGui::CollapsingHeader("color1  lfo")){
                    if (ImGui::Button("reset color1 lfo")) {
                        fb2HueOffsetLfoTheta = 0.0;
                        fb2SaturationOffsetLfoTheta = 0.0;
                        fb2BrightOffsetLfoTheta = 0.0;
                        fb2HueAttenuateLfoTheta = 0.0;
                        fb2SaturationAttenuateLfoTheta = 0.0;
                        fb2BrightAttenuateLfoTheta = 0.0;
                        fb2HueShaperLfoTheta = 0.0;
                        fb2HuePowMapLfoTheta = 0;
                        fb2SaturationPowMapLfoTheta = .0;
                        fb2BrightPowMapLfoTheta = .0;
                        
                        fb2HueOffsetLfoAmp = 0.0;
                        fb2SaturationOffsetLfoAmp = 0.0;
                        fb2BrightOffsetLfoAmp = 0.0;
                        fb2HueAttenuateLfoAmp = 0.0;
                        fb2SaturationAttenuateLfoAmp = 0.0;
                        fb2BrightAttenuateLfoAmp = 0.0;
                        fb2HueShaperLfoAmp = 0.0;
                        fb2HuePowMapLfoAmp = 0;
                        fb2SaturationPowMapLfoAmp = .0;
                        fb2BrightPowMapLfoAmp = .0;
                    }
                    
                    ImGui::SliderFloat("fb2HueOffsetLfo_rate", &fb2HueOffsetLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2HueOffsetLfoAmp", &fb2HueOffsetLfoAmp, -fb2HueOffsetRange, fb2HueOffsetRange);
                    ImGui::SliderFloat("fb2SaturationOffset_lfo_rate", &fb2SaturationOffsetLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2SaturationOffsetLfoAmp", &fb2SaturationOffsetLfoAmp, -fb2SaturationOffsetRange, fb2SaturationOffsetRange);
                    ImGui::SliderFloat("fb2BrightOffset_lfo_rate", &fb2BrightOffsetLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2BrightOffsetLfoAmp", &fb2BrightOffsetLfoAmp, -fb2BrightOffsetRange, fb2BrightOffsetRange);
                    ImGui::Separator();
                    ImGui::SliderFloat("fb2HueAttenuateLfo_rate", &fb2HueAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2HueAttenuateLfoAmp", &fb2HueAttenuateLfoAmp, -fb2HueAttenuateRange, fb2HueAttenuateRange);
                    ImGui::SliderFloat("fb2SaturationAttenuate_lfo_rate", &fb2SaturationAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2SaturationAttenuateLfoAmp", &fb2SaturationAttenuateLfoAmp, -fb2SaturationAttenuateRange, fb2SaturationAttenuateRange);
                    ImGui::SliderFloat("fb2BrightAttenuate_lfo_rate", &fb2BrightAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2BrightAttenuateLfoAmp", &fb2BrightAttenuateLfoAmp, -fb2BrightAttenuateRange, fb2BrightAttenuateRange);
                    ImGui::Separator();
                    ImGui::SliderFloat("fb2HueShaperLfo_rate", &fb2HueShaperLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2HueShaperLfoAmp", &fb2HueShaperLfoAmp, -fb2HueShaperRange, fb2HueShaperRange);
                    
                    ImGui::SliderFloat("fb2HuePowMapLfo_rate", &fb2HuePowMapLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2HuePowMapLfoAmp", &fb2HuePowMapLfoAmp, -fb2HuePowMapRange, fb2HuePowMapRange);
                    ImGui::SliderFloat("fb2SaturationPowMap_lfo_rate", &fb2SaturationPowMapLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2SaturationPowMapLfoAmp", &fb2SaturationPowMapLfoAmp, -fb2SaturationPowMapRange, fb2SaturationPowMapRange);
                    ImGui::SliderFloat("fb2BrightPowMap_lfo_rate", &fb2BrightPowMapLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2BrightPowMapLfoAmp", &fb2BrightPowMapLfoAmp, -fb2BrightPowMapRange, fb2BrightPowMapRange);
                    
                }
                if (ImGui::CollapsingHeader("color2  lfo")) {
                    if (ImGui::Button("reset color2 lfo")) {
                        fb2HueQuantizeLfoTheta = 0;
                        fb2SaturationQuantizeLfoTheta = 0;
                        fb2BrightQuantizeLfoTheta = 0;
                        fb2HueQuantizeMixLfoTheta = 0.0;
                        fb2SaturationQuantizeMixLfoTheta = 0.0;
                        fb2BrightQuantizeMixLfoTheta = 0.0;
                        fb2HueDitherMixLfoTheta = 0.0;
                        fb2HueDitherAmountLfoTheta = 0;
                        fb2SaturationDitherMixLfoTheta = 0.0;
                        fb2SaturationDitherAmountLfoTheta = 0;
                        fb2BrightDitherMixLfoTheta = 0.0;
                        fb2BrightDitherAmountLfoTheta = 0;
                        
                        fb2HueQuantizeLfoAmp = 0;
                        fb2SaturationQuantizeLfoAmp = 0;
                        fb2BrightQuantizeLfoAmp = 0;
                        fb2HueQuantizeMixLfoAmp = 0.0;
                        fb2SaturationQuantizeMixLfoAmp = 0.0;
                        fb2BrightQuantizeMixLfoAmp = 0.0;
                        fb2HueDitherMixLfoAmp = 0.0;
                        fb2HueDitherAmountLfoAmp = 0;
                        fb2SaturationDitherMixLfoAmp = 0.0;
                        fb2SaturationDitherAmountLfoAmp = 0;
                        fb2BrightDitherMixLfoAmp = 0.0;
                        fb2BrightDitherAmountLfoAmp = 0;
                    }
                    if (ImGui::CollapsingHeader("quantize lfos")) {
                        ImGui::SliderFloat("fb2HueQuantizeMixLfo_rate", &fb2HueQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2HueQuantizeMixLfoAmp", &fb2HueQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb2HueQuantizeLfo_rate", &fb2HueQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2HueQuantizeLfoAmp", &fb2HueQuantizeLfoAmp, -fb2HueQuantizeRange, fb2HueQuantizeRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb2SaturationQuantizeMix_lfo_rate", &fb2SaturationQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2SaturationQuantizeMixLfoAmp", &fb2SaturationQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb2SaturationQuantize_lfo_rate", &fb2SaturationQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2SaturationQuantizeLfoAmp", &fb2SaturationQuantizeLfoAmp, -fb2SaturationQuantizeRange, fb2SaturationQuantizeRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb2BrightQuantizeMix_lfo_rate", &fb2BrightQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2BrightQuantizeMixLfoAmp", &fb2BrightQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb2BrightQuantize_lfo_rate", &fb2BrightQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2BrightQuantizeLfoAmp", &fb2BrightQuantizeLfoAmp, -fb2BrightQuantizeRange, fb2BrightQuantizeRange);
                    }
                    ImGui::Separator();
                    if (ImGui::CollapsingHeader("dither lfos")) {
                        ImGui::SliderFloat("fb2HueDitherMixLfo_rate", &fb2HueDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2HueDitherMixLfoAmp", &fb2HueDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb2HueDitherLfo_rate", &fb2HueDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2HueDitherLfoAmp", &fb2HueDitherAmountLfoAmp, -fb2HueDitherRange, fb2HueDitherRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb2SaturationDitherMix_lfo_rate", &fb2SaturationDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2SaturationDitherMixLfoAmp", &fb2SaturationDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb2SaturationDither_lfo_rate", &fb2SaturationDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2SaturationDitherLfoAmp", &fb2SaturationDitherAmountLfoAmp, -fb2SaturationDitherRange, fb2SaturationDitherRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb2BrightDitherMix_lfo_rate", &fb2BrightDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2BrightDitherMixLfoAmp", &fb2BrightDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb2BrightDither_lfo_rate", &fb2BrightDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb2BrightDitherLfoAmp", &fb2BrightDitherAmountLfoAmp, -fb2BrightDitherRange, fb2BrightDitherRange);
                    }
                }
                if (ImGui::CollapsingHeader("geo1 lfo")){
                    if (ImGui::Button("reset geo1 lfo")) {
                        fb2XDisplaceLfoTheta = 0.0;
                        fb2YDisplaceLfoTheta = 0.0;
                        fb2ZDisplaceLfoTheta = 0.0;
                        fb2RotateLfoTheta = 0;
                        fb2ShearMatrixLfoTheta.set(0,0,0,0);
                        
                        fb2XDisplaceLfoAmp = 0.0;
                        fb2YDisplaceLfoAmp = 0.0;
                        fb2ZDisplaceLfoAmp = 0.0;
                        fb2RotateLfoAmp = 0;
                        fb2ShearMatrixLfoAmp.set(0, 0, 0, 0);
                    }
                    ImGui::SliderFloat("fb2XDisplace_lfo_rate", &fb2XDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2XDisplace_lfo_amp", &fb2XDisplaceLfoAmp, -fb2XDisplaceRange, fb2XDisplaceRange);
                    ImGui::SliderFloat("fb2YDisplace_lfo_rate", &fb2YDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2YDisplace_lfo_amp", &fb2YDisplaceLfoAmp, -fb2YDisplaceRange, fb2YDisplaceRange);
                    ImGui::SliderFloat("fb2ZDisplace_lfo_rate", &fb2ZDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2ZDisplace_lfo_amp", &fb2ZDisplaceLfoAmp, -fb2ZDisplaceRange, fb2ZDisplaceRange);
                    ImGui::SliderFloat("fb2Rotate_lfo_rate", &fb2RotateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2RotateLfoAmp", &fb2RotateLfoAmp, -fb2ZRotateRange, fb2ZRotateRange);
                    
                    ImGui::SliderFloat("fb2 Shear matrix 1 lfo rate", &fb2ShearMatrixLfoTheta.x, .0f, lfom);
                    ImGui::SliderFloat("fb2 Shear matrix 1 lfo amp", &fb2ShearMatrixLfoAmp.x, -fb2ShearMatrixRange.x, fb2ShearMatrixRange.x);
                    ImGui::SliderFloat("fb2 Shear matrix 2 lfo rate", &fb2ShearMatrixLfoTheta.y, .0f, lfom);
                    ImGui::SliderFloat("fb2 Shear matrix 2 lfo amp", &fb2ShearMatrixLfoAmp.y, -fb2ShearMatrixRange.y, fb2ShearMatrixRange.y);
                    ImGui::SliderFloat("fb2 Shear matrix 3 lfo rate", &fb2ShearMatrixLfoTheta.z, .0f, lfom);
                    ImGui::SliderFloat("fb2 Shear matrix 3 lfo amp", &fb2ShearMatrixLfoAmp.z, -fb2ShearMatrixRange.z, fb2ShearMatrixRange.z);
                    ImGui::SliderFloat("fb2 Shear matrix 4 lfo rate", &fb2ShearMatrixLfoTheta.w, .0f, lfom);
                    ImGui::SliderFloat("fb2 Shear matrix 4 lfo amp", &fb2ShearMatrixLfoAmp.w, -fb2ShearMatrixRange.w, fb2ShearMatrixRange.w);
                }
                if (ImGui::CollapsingHeader("geo2 lfo")) {
                    if (ImGui::Button("reset geo2 lfo")) {
                        fb2FisheyeAmountLfoTheta = 0;
                        fb2FisheyeXLfoTheta = 0;
                        fb2FisheyeYLfoTheta = 0;
                        fb2SpiralAmountLfoTheta = 0;
                        fb2SpiralAngleLfoTheta = 0;
                        fb2SpiralXLfoTheta = 0;
                        fb2SpiralYLfoTheta = 0;
                        fb2KaleidoscopeSegmentsLfoTheta = 0;
                        fb2KaleidoscopeSliceLfoTheta = 0;
                        
                        fb2FisheyeAmountLfoAmp = 0;
                        fb2FisheyeXLfoAmp = 0;
                        fb2FisheyeYLfoAmp = 0;
                        fb2SpiralAmountLfoAmp = 0;
                        fb2SpiralAngleLfoAmp = 0;
                        fb2SpiralXLfoAmp = 0;
                        fb2SpiralYLfoAmp = 0;
                        fb2KaleidoscopeSegmentsLfoAmp = 0;
                        fb2KaleidoscopeSliceLfoAmp = 0;
                    }
                    //geo 2 lfos
                    ImGui::SliderFloat("fb2 fisheye amount lfo rate", &fb2FisheyeAmountLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2 fisheye amount lfo amp", &fb2FisheyeAmountLfoAmp, -fb2FisheyeAmountRange, fb2FisheyeAmountRange);
                    ImGui::SliderFloat("fb2 fisheye x lfo rate", &fb2FisheyeXLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2 fisheye x lfo amp", &fb2FisheyeXLfoAmp, -fb2FisheyeXRange, fb2FisheyeXRange);
                    ImGui::SliderFloat("fb2 fisheye y lfo rate", &fb2FisheyeYLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2 fisheye y lfo amp", &fb2FisheyeYLfoAmp, -fb2FisheyeYRange, fb2FisheyeYRange);
                    
                    ImGui::SliderFloat("fb2 spiral amount lfo rate", &fb2SpiralAmountLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2 spiral amount lfo amp", &fb2SpiralAmountLfoAmp, -fb2SpiralAmountRange, fb2SpiralAmountRange);
                    ImGui::SliderFloat("fb2 spiral angle lfo rate", &fb2SpiralAngleLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2 spiral angle lfo amp", &fb2SpiralAngleLfoAmp, -fb2SpiralAngleRange, fb2SpiralAngleRange);
                    ImGui::SliderFloat("fb2 spiral x lfo rate", &fb2SpiralXLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2 spiral x lfo amp", &fb2SpiralXLfoAmp, -fb2SpiralXRange, fb2SpiralXRange);
                    ImGui::SliderFloat("fb2 spiral y lfo rate", &fb2SpiralYLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2 spiral y lfo amp", &fb2SpiralYLfoAmp, -fb2SpiralYRange, fb2SpiralYRange);
                    
                    ImGui::SliderFloat("fb2 kaleidoscope segments lfo rate", &fb2KaleidoscopeSegmentsLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2 kaleidoscope segments lfo amp", &fb2KaleidoscopeSegmentsLfoAmp, 0, fb2KaleidoscopeSegmentsRange);
                    ImGui::SliderFloat("fb2 kaleidoscope slice lfo rate", &fb2KaleidoscopeSliceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb2 kaleidoscope slice lfo amp", &fb2KaleidoscopeSliceLfoAmp, -fb2KaleidoscopeSliceRange, fb2KaleidoscopeSliceRange);
                }
                
                if (ImGui::CollapsingHeader("pixelation"))
                {
                    if (ImGui::Button("reset pixelation lfo")) {
                        fb2XPixelScaleLfoTheta = 0;
                        fb2XPixelScaleLfoAmp = 0;
                        fb2YPixelScaleLfoTheta = 0;
                        fb2YPixelScaleLfoAmp = 0;
                        fb2PixelMixLfoTheta = 0;
                        fb2PixelMixLfoAmp = 0;
                        fb2PixelBrightscaleLfoTheta = 0;
                        fb2PixelBrightscaleLfoAmp = 0;
                    }
                    //ImGui::Text("Love Flange Orgasms s");
                    ImGui::SliderFloat("fb2 pixel scale_x_rate", &fb2XPixelScaleLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb2 pixel scale_x_amp", &fb2XPixelScaleLfoAmp, -256.0f, 256.0f);
                    ImGui::SliderFloat("fb2 pixel scale_y_rate", &fb2YPixelScaleLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb2 pixel scale_y_amp", &fb2YPixelScaleLfoAmp, -256.0f, 256.0f);
                    ImGui::SliderFloat("fb2 pixel mix_rate", &fb2PixelMixLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb2 pixel mix_amp", &fb2PixelMixLfoAmp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb2 pixel bright scale rate", &fb2PixelBrightscaleLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb2 pixel bright scale amp", &fb2PixelBrightscaleLfoAmp, -2.0f, 2.0f);
                }
            }//endlfo folder
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
        
        
        
        
        
        
        //fb3
        
        mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 5*gui_vscaler-30));
        //fb3
        if (ofxImGui::BeginWindow("fb3", mainSettings, false)){
            if (ImGui::Button("reset all")) {
                fb3ResetAll();
            }
            if (ImGui::CollapsingHeader("parameters")){
                if (ImGui::Button("reset parameters")) {
                    fb3ResetAllParameters();
                }
                ImGui::SliderInt("fb3DelayAmount", &fb3DelayAmount, 0, fbob - 1);
                ImGui::Checkbox("tex_mod", &fb3TexmodSwitch);
                const char* items[] = { "channel 1","channel 2" };
                static int item_current = 0;
                ImGui::Combo("texmod select", &item_current, items, IM_ARRAYSIZE(items));
                fb3TexmodSelect=item_current;
                
                if (ImGui::CollapsingHeader("mix and key")){
                    static int item_current0 = 0;
                    static int item_current1 = 0;
                    static int item_current2 = 0;
                    static int item_current3 = 0;
                    static int item_current4 = 0;
                    static int item_current5 = 0;
                    if ( (ImGui::Button("reset mix and key")) ) {
                        fb3LumakeyLevel = 0;
                        fb3KeyThreshold = 0;
                        fb3ChromakeyRed = 0;
                        fb3ChromakeyGreen = 0;
                        fb3ChromakeyBlue = 0;
                        fb3KeySoft = 0;
                        fb3MaskX = 0;
                        fb3MaskY = 0;
                        fb3MaskZ = 1.0;
                        fb3MaskRotate = 0;
                        fb3MaskTileAmount = 1.0;
                        fb3MaskTexmodOffset = 0;
                        fb3MaskTexmodQuantizeAmount = 1.0;
                        fb3MaskTexmodQuantizeMix = 1.0;
                        item_current0 = 0;
                        item_current1 = 0;
                        item_current2 = 0;
                        item_current3 = 0;
                        item_current4 = 0;
                        item_current5 = 0;
                        fb3Mix = 0;
                        
                        fb3LumakeyLevelTexmod = 0.0;
                        fb3ChromakeyRedTexmod = 0;
                        fb3ChromakeyGreenTexmod = 0;
                        fb3ChromakeyBlueTexmod = 0;
                        fb3KeyThresholdTexmod = 0.0;
                        fb3KeySoftTexmod = 0;
                        fb3MixTexmod = .0;
                        fb3MaskXTexmod = 0;
                        fb3MaskYTexmod = 0;
                        fb3MaskZTexmod = 0.0;
                        fb3MaskRotateTexmod = 0;
                        fb3MaskTileAmountTexmod = 0.0;
                    }
                    
                    const char* items0[] = { "Input1->fb3","fb3->Input1" };
                    ImGui::Combo("fb3 mix and key order", &item_current0, items0, IM_ARRAYSIZE(items0));
                    fb3KeyOrder = item_current0;
                    
                    const char* items1[] = { "lerp", "add","difference","mult","dodge" };
                    ImGui::Combo("fb3 mix Type", &item_current1, items1, IM_ARRAYSIZE(items1));
                    fb3MixType = item_current1;
                    
                    if (fb3TexmodSwitch == false) {
                        ImGui::SliderFloat("fb3 mix", &fb3Mix, -2.0f, 2.0f);
                    }
                    if (fb3TexmodSwitch == true) {
                        ImGui::SliderFloat("texmod fb3 mix", &fb3MixTexmod, -2.0f, 2.0f);
                    }
                    const char* items2[] = { "clamp", "wrap","foldover" };
                    ImGui::Combo("fb3 Mix overflow", &item_current2, items2, IM_ARRAYSIZE(items2));
                    fb3MixOverflow = item_current2;
                    
                    const char* items3[] = { "Lumakey","Chromakey","wipePattern" };
                    ImGui::Combo("fb3 key mode", &item_current3, items3, IM_ARRAYSIZE(items3));
                    fb3KeyMode = item_current3;
                    
                    if (fb3KeyMode == 0) {
                        if (fb3TexmodSwitch == false) {
                            ImGui::SliderFloat("fb3 lumakey level", &fb3LumakeyLevel, 0.0f, 1.0f);
                        }
                        if (fb3TexmodSwitch == true) {
                            ImGui::SliderFloat("texmod fb3 lumakey level", &fb3LumakeyLevelTexmod, .0f, 1.0f);
                        }
                    }
                    if (fb3KeyMode == 1) {
                        if (fb3TexmodSwitch == false) {
                            ImGui::SliderFloat("fb3 Chromakey Red", &fb3ChromakeyRed, 0.0f, 1.0f);
                            ImGui::SliderFloat("fb3 Chromakey Green", &fb3ChromakeyGreen, 0.0f, 1.0f);
                            ImGui::SliderFloat("fb3 Chromakey Blue", &fb3ChromakeyBlue, 0.0f, 1.0f);
                        }
                        if (fb3TexmodSwitch == true) {
                            ImGui::SliderFloat("texmod fb3 Chromakey Red", &fb3ChromakeyRedTexmod, 0.0f, 1.0f);
                            ImGui::SliderFloat("texmod fb3 Chromakey Green", &fb3ChromakeyGreenTexmod, 0.0f, 1.0f);
                            ImGui::SliderFloat("texmod fb3 Chromakey Blue", &fb3ChromakeyBlueTexmod, 0.0f, 1.0f);
                        }
                        ImGui::ColorButton("testingColorButton", ImVec4(fb3ChromakeyRed, fb3ChromakeyGreen, fb3ChromakeyBlue, 1.0), 0, ImVec2(20, 20));
                    }
                    if (fb3KeyMode !=2) {
                        if (fb3TexmodSwitch == false) {
                            ImGui::SliderFloat("fb3 key threshold", &fb3KeyThreshold, 0.0f, rootThree);
                            ImGui::SliderFloat("fb3 key soft", &fb3KeySoft, 0.0f, 1.0f);
                        }
                        if (fb3TexmodSwitch == true) {
                            ImGui::SliderFloat("texmod fb3 key threshold", &fb3KeyThresholdTexmod, .0f, rootThree);
                            ImGui::SliderFloat("texmod fb3 key soft", &fb3KeySoftTexmod, 0.0f, 1.0f);
                        }
                    }
                    if (fb3KeyMode == 2) {
                        //when wipe pattern is selected we need to change chroma/lumakey values to 0
                        fb3LumakeyLevel = 0;
                        fb3KeyThreshold = 0;
                        fb3ChromakeyRed = 0;
                        fb3ChromakeyGreen = 0;
                        fb3ChromakeyBlue = 0;
                        fb3KeySoft = 0;
                        
                        //drop down menu for mask selection
                        const char* items4[] = { "mask1","mask2","mask3","mask4","texMod" };
                        ImGui::Combo("fb3 mask select", &item_current4, items4, IM_ARRAYSIZE(items4));
                        fb3MaskSelect = item_current4;
                        
                        //want to figure out way to get variables in here as to global width
                        if (fb3MaskSelect != 4) {
                            if (fb3TexmodSwitch == false) {
                                ImGui::SliderFloat("fb3 mask x", &fb3MaskX, -outWidth * .5f, outWidth*.5f);
                                ImGui::SliderFloat("fb3 mask y", &fb3MaskY, -outHeight * .5f, outHeight*.5f);
                                ImGui::SliderFloat("fb3 mask z", &fb3MaskZ, 0.0f, 3.0f);
                                ImGui::SliderFloat("fb3 mask rotate", &fb3MaskRotate, -TWO_PI, TWO_PI);
                                ImGui::SliderFloat("fb3 mask tile amount", &fb3MaskTileAmount, 0.0f, 2.0f);
                            }
                            if(fb3TexmodSwitch == true) {
                                ImGui::SliderFloat("texmod fb3 mask x", &fb3MaskXTexmod, -outWidth * .5f, outWidth*.5f);
                                ImGui::SliderFloat("texmod fb3 mask y", &fb3MaskYTexmod, -outHeight * .5f, outHeight*.5f);
                                ImGui::SliderFloat("texmod fb3 mask z", &fb3MaskZTexmod, -3.0f, 3.0f);
                                ImGui::SliderFloat("texmod fb3 mask rotate", &fb3MaskRotateTexmod, -TWO_PI, TWO_PI);
                                ImGui::SliderFloat("texmod fb3 mask tile amount", &fb3MaskTileAmountTexmod, -2.0f, 2.0f);
                            }
                            const char* items5[] = { "Off","Basic","basic alt rotate","spiral" };
                            ImGui::Combo("fb3 mask tile Mode", &item_current5, items5, IM_ARRAYSIZE(items5));
                            fb3MaskTileMode = item_current5;
                        }
                        if (fb3MaskSelect == 4) {
                            ImGui::SliderFloat("fb3 mask texmod offset", &fb3MaskTexmodOffset, -1.0f, 1.0f);
                            ImGui::SliderFloat("fb3 mask texmod quantize mix", &fb3MaskTexmodQuantizeMix, .0f, 1.0f);
                            ImGui::SliderInt("fb3 mask texmod quantize amount", &fb3MaskTexmodQuantizeAmount, 1, 32);
                        }
                    }
                }
                if (ImGui::CollapsingHeader("color space 1")){
                    static int item_current0 = 0;
                    static int item_current1 = 0;
                    if (ImGui::TreeNode(" color 1 ranges")) {
                        ImGui::SliderFloat("fb3 hue offset range", &fb3HueOffsetRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb3 saturation offset range", &fb3SaturationOffsetRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb3 bright offset range", &fb3BrightOffsetRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb3 hue attenuate range", &fb3HueAttenuateRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb3 saturation attenuate range", &fb3SaturationAttenuateRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb3 bright attenuate range", &fb3BrightAttenuateRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb3 hue Shaper range", &fb3HueShaperRange, .0001f, 5.0f);
                        ImGui::SliderFloat("fb3 hue powmap range", &fb3HuePowMapRange, .0001f, 5.0f);
                        ImGui::SliderFloat("fb3 saturation powmap range", &fb3SaturationPowMapRange, .0001f, 20.0f);
                        ImGui::SliderFloat("fb3 bright powmap range", &fb3BrightPowMapRange, .0001f, 20.0f);
                        ImGui::TreePop();
                    }
                    if ( (ImGui::Button("reset color 1"))  ) {
                        fb3HueOffset = 0.0;
                        fb3SaturationOffset = 0.0;
                        fb3BrightOffset = 0.0;
                        fb3HueAttenuate = 10.0;
                        fb3SaturationAttenuate = 10.0;
                        fb3BrightAttenuate = 10.0;
                        fb3HueShaper = 0.0;
                        fb3HuePowMap=1.0;
                        fb3SaturationPowMap=1.0;
                        fb3BrightPowMap=1.0;
                        fb3HueInvert = 0;
                        fb3SaturationInvert = 0;
                        fb3BrightInvert = 0;
                        
                        fb3HueShaperRange = 0.25;
                        fb3HueOffsetRange = .25;
                        fb3SaturationOffsetRange = 0.25;
                        fb3BrightOffsetRange = 0.25;
                        fb3HueAttenuateRange = 2.0;
                        fb3SaturationAttenuateRange = 2.0;
                        fb3BrightAttenuateRange = 2.0;
                        
                        fb3HueInvert = 0;
                        fb3SaturationInvert = 0;
                        fb3BrightInvert = 0;
                        
                        fb3SaturationOverflow = 0;
                        fb3BrightOverflow = 0;
                        fb3HuePowMapRange = .25;
                        fb3SaturationPowMapRange = .25;
                        fb3BrightPowMapRange = .25;
                        
                        fb3HueOffsetTexmod = 0.0;
                        fb3SaturationOffsetTexmod = 0.0;
                        fb3BrightOffsetTexmod = 0.0;
                        fb3HueAttenuateTexmod = 0.0;
                        fb3SaturationAttenuateTexmod = 0.0;
                        fb3BrightAttenuateTexmod = 0.0;
                        fb3HueShaperTexmod = 0.0;
                        fb3HuePowMapTexmod = .0;
                        fb3SaturationPowMapTexmod = .0;
                        fb3BrightPowMapTexmod = .0;
                        
                    }
                    
                    //EASTER EGG
                    //some combination of keypresses adds 1. crt overlay, 2. pixels in SD aspect ratio, 3. enuf dither to look like scanlines
                    //4. interlacing
                    if(fb3TexmodSwitch==false){
                        ImGui::SliderFloat("fb3 hue offset",&fb3HueOffset,-fb3HueOffsetRange,fb3HueOffsetRange);
                        ImGui::SliderFloat("fb3 saturation offset", &fb3SaturationOffset, -fb3SaturationOffsetRange, fb3SaturationOffsetRange);
                        ImGui::SliderFloat("fb3 bright offset", &fb3BrightOffset, -fb3BrightOffsetRange, fb3BrightOffsetRange);
                        ImGui::SliderFloat("fb3 hue attenuate", &fb3HueAttenuate, 10.0f-fb3HueAttenuateRange, 10.0f+fb3HueAttenuateRange);
                        ImGui::SliderFloat("fb3 saturation attenuate", &fb3SaturationAttenuate, 10.0f - fb3SaturationAttenuateRange, 10.0f + fb3SaturationAttenuateRange);
                        ImGui::SliderFloat("fb3 bright attenuate", &fb3BrightAttenuate, 10.0f - fb3BrightAttenuateRange, 10.0f + fb3BrightAttenuateRange);
                        ImGui::SliderFloat("fb3 hue Shaper", &fb3HueShaper, -fb3HueShaperRange, fb3HueShaperRange);
                        ImGui::SliderFloat("fb3 hue powmap", &fb3HuePowMap, 1.0f - fb3HuePowMapRange, 1.0f + fb3HuePowMapRange);
                        ImGui::SliderFloat("fb3 saturation powmap", &fb3SaturationPowMap, 1.0f - fb3SaturationPowMapRange, 1.0f + fb3SaturationPowMapRange);
                        ImGui::SliderFloat("fb3 bright powmap", &fb3BrightPowMap, 1.0f-fb3BrightPowMapRange, 1.0f+fb3BrightPowMapRange);
                    }
                    if (fb3TexmodSwitch == true) {
                        ImGui::SliderFloat("texmod fb3 hue offset", &fb3HueOffsetTexmod, -fb3HueOffsetRange * .1f, fb3HueOffsetRange*.1f);
                        ImGui::SliderFloat("texmod fb3 saturation offset", &fb3SaturationOffsetTexmod, -fb3SaturationOffsetRange * .1f, fb3SaturationOffsetRange*.1f);
                        ImGui::SliderFloat("texmod fb3 bright offset", &fb3BrightOffsetTexmod, -fb3BrightOffsetRange * .1f, fb3BrightOffsetRange*.1f);
                        ImGui::SliderFloat("texmod fb3HueAttenuate", &fb3HueAttenuateTexmod, -fb3HueAttenuateRange * .1f, fb3HueAttenuateRange*.1f);
                        ImGui::SliderFloat("texmod fb3SaturationAttenuate", &fb3SaturationAttenuateTexmod, -fb3SaturationAttenuateRange * .1f, fb3SaturationAttenuateRange*.1f);
                        ImGui::SliderFloat("texmod fb3BrightAttenuate", &fb3BrightAttenuateTexmod, -fb3BrightAttenuateRange * .1f, fb3BrightAttenuateRange*.1f);
                        ImGui::SliderFloat("texmod fb3 hue Shaper", &fb3HueShaperTexmod, -fb3HueShaperRange * .1f, fb3HueShaperRange*.1f);
                        ImGui::SliderFloat("texmod fb3 hue powmap", &fb3HuePowMapTexmod, -fb3HuePowMapRange, fb3HuePowMapRange);
                        ImGui::SliderFloat("texmod fb3 saturation powmap", &fb3SaturationPowMapTexmod, -fb3SaturationPowMapRange, fb3SaturationPowMapRange);
                        ImGui::SliderFloat("texmod fb3 bright powmap", &fb3BrightPowMapTexmod, -fb3BrightPowMapRange, fb3BrightPowMapRange);
                    }
                    ImGui::Checkbox("fb3HueInvert", &fb3HueInvert);
                    ImGui::Checkbox("fb3SaturationInvert", &fb3SaturationInvert);
                    ImGui::Checkbox("fb3BrightInvert", &fb3BrightInvert);
                    
                    const char* items0[] = { "clamp","wrap","fold" };
                    ImGui::Combo("saturation overflow", &item_current0, items0, IM_ARRAYSIZE(items0));
                    fb3SaturationOverflow = item_current0;
                    const char* items1[] = { "clamp","wrap","fold" };
                    ImGui::Combo("bright overflow", &item_current1, items1, IM_ARRAYSIZE(items1));
                    fb3BrightOverflow = item_current1;
                    //add wrap, fold, clamp for colors
                }
                if (ImGui::CollapsingHeader("color space 2")) {
                    if (ImGui::TreeNode(" color 2 ranges")) {
                        ImGui::SliderInt("fb3 hue dither range", &fb3HueDitherRange, 1, 512);
                        ImGui::SliderInt("fb3 saturation dither range", &fb3SaturationDitherRange, 1, 512);
                        ImGui::SliderInt("fb3 bright dither range", &fb3BrightDitherRange, 1, 512);
                        ImGui::SliderInt("fb3 hue quantize range", &fb3HueQuantizeRange, 1, 512);
                        ImGui::SliderInt("fb3 saturation quantize range", &fb3SaturationQuantizeRange, 1, 512);
                        ImGui::SliderInt("fb3 bright quantize range", &fb3BrightQuantizeRange, 1, 512);
                        ImGui::TreePop();
                    }
                    if ( (ImGui::Button("reset color 2"))  ) {
                        fb3HueQuantize = 128;
                        fb3SaturationQuantize = 128;
                        fb3BrightQuantize = 128;
                        fb3HueQuantizeMix = 0.0;
                        fb3SaturationQuantizeMix = 0.0;
                        fb3BrightQuantizeMix = 0.0;
                        fb3HueDitherMix = 0.0;
                        fb3HueDitherAmount = 64;
                        fb3SaturationDitherMix = 0.0;
                        fb3SaturationDitherAmount = 64;
                        fb3BrightDitherMix = 0.0;
                        fb3BrightDitherAmount = 64;
                        
                        fb3HueQuantizeTexmod = 0;
                        fb3SaturationQuantizeTexmod = 0;
                        fb3BrightQuantizeTexmod = 0;
                        fb3HueQuantizeMixTexmod = 0.0;
                        fb3SaturationQuantizeMixTexmod = 0.0;
                        fb3BrightQuantizeMixTexmod = 0.0;
                        fb3HueDitherMixTexmod = 0.0;
                        fb3HueDitherAmountTexmod = 0;
                        fb3SaturationDitherMixTexmod = 0.0;
                        fb3SaturationDitherAmountTexmod = 0;
                        fb3BrightDitherMixTexmod = 0.0;
                        fb3BrightDitherAmountTexmod = 0;
                    }
                    if (fb3TexmodSwitch == false) {
                        ImGui::SliderFloat("fb3 hue quantize mix", &fb3HueQuantizeMix, .0f, 1.0f);
                        ImGui::SliderInt("fb3 hue quantize amount", &fb3HueQuantize, 1, fb3HueQuantizeRange);
                        ImGui::SliderFloat("fb3 saturation quantize mix", &fb3SaturationQuantizeMix, .0f, 1.0f);
                        ImGui::SliderInt("fb3 saturation quantize amount", &fb3SaturationQuantize, 1, fb3SaturationQuantizeRange);
                        ImGui::SliderFloat("fb3 bright quantize mix", &fb3BrightQuantizeMix, .0f, 1.0f);
                        ImGui::SliderInt("fb3 bright quantize amount", &fb3BrightQuantize, 1, fb3BrightQuantizeRange);
                        ImGui::SliderFloat("fb3 hue dither mix", &fb3HueDitherMix, .0f, 1.0f);
                        ImGui::SliderInt("fb3 hue dither amount", &fb3HueDitherAmount, 1, fb3HueDitherRange);
                        ImGui::SliderFloat("fb3 saturation dither mix", &fb3SaturationDitherMix, .0f, 1.0f);
                        ImGui::SliderInt("fb3 saturation dither amount", &fb3SaturationDitherAmount, 1, fb3SaturationDitherRange);
                        ImGui::SliderFloat("fb3 bright dither mix", &fb3BrightDitherMix, .0f, 1.0f);
                        ImGui::SliderInt("fb3 bright dither amount", &fb3BrightDitherAmount, 1, fb3BrightDitherRange);
                    }
                    if (fb3TexmodSwitch == true) {
                        /*
                         ImGui::SliderFloat("texmod fb3 hue quantize mix", &fb3HueQuantizeMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb3 hue quantize amount", &fb3HueQuantizeTexmod, 1, fb3HueQuantizeRange);
                         ImGui::SliderFloat("texmod fb3 saturation quantize mix", &fb3SaturationQuantizeMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb3 saturation quantize amount", &fb3SaturationQuantizeTexmod, 1, fb3SaturationQuantizeRange);
                         ImGui::SliderFloat("texmod fb3 bright quantize mix", &fb3BrightQuantizeMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb3 bright quantize amount", &fb3BrightQuantizeTexmod, 1, fb3BrightQuantizeRange);
                         ImGui::SliderFloat("texmod fb3 hue dither mix", &fb3HueDitherMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb3 hue dither amount", &fb3HueDitherAmountTexmod, 1, fb3HueDitherRange);
                         ImGui::SliderFloat("texmod fb3 saturation dither mix", &fb3SaturationDitherMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb3 saturation dither amount", &fb3SaturationDitherAmountTexmod, 1, fb3SaturationDitherRange);
                         ImGui::SliderFloat("texmod fb3 bright dither mix", &fb3BrightDitherMixTexmod, .0f, 1.0f);
                         ImGui::SliderFloat("texmod fb3 bright dither amount", &fb3BrightDitherAmountTexmod, 1, fb3BrightDitherRange);
                         */
                    }
                    
                }
                if (ImGui::CollapsingHeader("geometry1")){
                    static int item_current2 = 0;
                    if (ImGui::TreeNode(" geo 1 ranges")) {
                        ImGui::SliderFloat("fb3 x displace range", &fb3XDisplaceRange, .0001f, 200.0f);
                        ImGui::SliderFloat("fb3 y displace range", &fb3YDisplaceRange, .0001f, 200.0f);
                        ImGui::SliderFloat("fb3 z displace range", &fb3ZDisplaceRange, .0001f, 100.0f);
                        ImGui::SliderFloat("fb3 rotate range", &fb3ZRotateRange, .0001f, TWO_PI);
                        ImGui::SliderFloat("fb3 shear matrix 1 Range", &fb3ShearMatrixRange.x, .0001f, 5.0f);
                        ImGui::SliderFloat("fb3 shear matrix 2 Range", &fb3ShearMatrixRange.y, .0001f, 5.0f);
                        ImGui::SliderFloat("fb3 shear matrix 3 Range", &fb3ShearMatrixRange.z, .0001f, 5.0f);
                        ImGui::SliderFloat("fb3 shear matrix 4 Range", &fb3ShearMatrixRange.w, .0001f, 5.0f);
                        
                        ImGui::TreePop();
                    }
                    if ( ImGui::Button("reset geo1") ) {
                        item_current2 = 0;
                        fb3XDisplace = 0.0;
                        fb3YDisplace = 0.0;
                        fb3ZDisplace = 100.0;
                        fb3Rotate = 0;
                        fb3ShearMatrix.set(0,0,0,0);
                        fb3ShearMatrixRange.set(0.25, 0.25, 0.25, 0.25);
                        fb3RotateMode = 0;
                        fb3HorizontalMirror = 0;
                        fb3VerticalMirror = 0;
                        fb3XDisplaceRange = 40;
                        fb3YDisplaceRange = 40;
                        fb3ZDisplaceRange = 10;
                        fb3ZRotateRange = PI;
                        
                        fb3XDisplaceTexmod=0.0;
                        fb3YDisplaceTexmod=0.0;
                        fb3ZDisplaceTexmod=0;
                        fb3RotateTexmod=0;
                        fb3ShearMatrixTexmod.set(0,0,0,0);
                    }
                    if(fb3TexmodSwitch==false){
                        ImGui::SliderFloat("fb3_x", &fb3XDisplace, -fb3XDisplaceRange, fb3XDisplaceRange);
                        ImGui::SliderFloat("fb3_y", &fb3YDisplace, -fb3YDisplaceRange, fb3YDisplaceRange);
                        ImGui::SliderFloat("fb3_z", &fb3ZDisplace,  100.0f-fb3ZDisplaceRange, 100.0f+fb3ZDisplaceRange);
                        ImGui::SliderFloat("fb3Rotate", &fb3Rotate, -fb3ZRotateRange, fb3ZRotateRange);
                        
                        ImGui::SliderFloat("fb3 Shear matrix 1", &fb3ShearMatrix.x, -fb3ShearMatrixRange.x, fb3ShearMatrixRange.x);
                        ImGui::SliderFloat("fb3 Shear matrix 2", &fb3ShearMatrix.y, -fb3ShearMatrixRange.y, fb3ShearMatrixRange.y);
                        ImGui::SliderFloat("fb3 Shear matrix 3", &fb3ShearMatrix.z, -fb3ShearMatrixRange.z, fb3ShearMatrixRange.z);
                        ImGui::SliderFloat("fb3 Shear matrix 4", &fb3ShearMatrix.w, -fb3ShearMatrixRange.w, fb3ShearMatrixRange.w);
                    }
                    if(fb3TexmodSwitch==true){
                        ImGui::SliderFloat("texmod fb3_x", &fb3XDisplaceTexmod, -fb3XDisplaceRange, fb3XDisplaceRange);
                        ImGui::SliderFloat("texmod fb3_y", &fb3YDisplaceTexmod,  -fb3YDisplaceRange, fb3YDisplaceRange);
                        ImGui::SliderFloat("texmod fb3_z", &fb3ZDisplaceTexmod,  -fb3ZDisplaceRange*.01, fb3ZDisplaceRange*.01);
                        ImGui::SliderFloat("texmod fb3Rotate", &fb3RotateTexmod, -fb3ZRotateRange, fb3ZRotateRange);
                        
                        ImGui::SliderFloat("texmod fb3 Shear matrix 1", &fb3ShearMatrixTexmod.x, -fb3ShearMatrixRange.x, fb3ShearMatrixRange.x);
                        ImGui::SliderFloat("texmod fb3 Shear matrix 2", &fb3ShearMatrixTexmod.y, -fb3ShearMatrixRange.y, fb3ShearMatrixRange.y);
                        ImGui::SliderFloat("texmod fb3 Shear matrix 3", &fb3ShearMatrixTexmod.z, -fb3ShearMatrixRange.z, fb3ShearMatrixRange.z);
                        ImGui::SliderFloat("texmod fb3 Shear matrix 4", &fb3ShearMatrixTexmod.w, -fb3ShearMatrixRange.w, fb3ShearMatrixRange.w);
                    }
                    const char* items2[] = { "clamp","toroid","mirror" };
                    ImGui::Combo("Geometry overflow select", &item_current2, items2, IM_ARRAYSIZE(items2));
                    fb3_toroid_switch = item_current2;
                    
                    ImGui::Checkbox("fb3_h_mirror", &fb3HorizontalMirror);
                    ImGui::Checkbox("fb3_v_mirror", &fb3VerticalMirror);
                    ImGui::Checkbox("fb3RotateMode", &fb3RotateMode);
                }
                if (ImGui::CollapsingHeader("geometry2")) {
                    if (ImGui::TreeNode("geo 2 ranges")) {
                        ImGui::SliderFloat("fb3 fisheye amount range", &fb3FisheyeAmountRange, .0001f, 2.0f);
                        ImGui::SliderFloat("fb3 fisheye X range", &fb3FisheyeXRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb3 fisheye Y range", &fb3FisheyeYRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb3 spiral amount range", &fb3SpiralAmountRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb3 spiral angle range", &fb3SpiralAngleRange, .0001f, TWO_PI);
                        ImGui::SliderFloat("fb3 spiral X range", &fb3SpiralXRange, .0001f, 10.0f);
                        ImGui::SliderFloat("fb3 spiral Y range", &fb3SpiralYRange, .0001f, 10.0f);
                        ImGui::SliderInt("fb3 kaleidoscope segments range", &fb3KaleidoscopeSegmentsRange, 1, 100);
                        ImGui::SliderFloat("fb3 kaleidoscope slice range", &fb3KaleidoscopeSliceRange,.01,TWO_PI);
                        
                        ImGui::TreePop();
                    }
                    if (ImGui::Button("reset geo2")) {
                        fb3FisheyeAmount = 0;
                        fb3FisheyeX = 0;
                        fb3FisheyeY = 0;
                        fb3SpiralAmount = 0;
                        fb3SpiralAngle = 0;
                        fb3SpiralX = 0;
                        fb3SpiralY = 0;
                        fb3KaleidoscopeSegments = 0;
                        fb3KaleidoscopeSlice = 0;
                        
                        fb3FisheyeAmountRange = .15;
                        fb3FisheyeXRange = .25;
                        fb3FisheyeYRange = .25;
                        fb3SpiralAmountRange = .15;
                        fb3SpiralAngleRange = PI;
                        fb3SpiralXRange = .25;
                        fb3SpiralYRange = .25;
                        fb3KaleidoscopeSegmentsRange = 21;
                        fb3KaleidoscopeSliceRange = PI;
                        
                        fb3FisheyeAmountTexmod = 0;
                        fb3FisheyeXTexmod = 0;
                        fb3FisheyeYTexmod = 0;
                        fb3SpiralAmountTexmod = 0;
                        fb3SpiralAngleTexmod = 0;
                        fb3SpiralXTexmod = 0;
                        fb3SpiralYTexmod = 0;
                        fb3KaleidoscopeSegmentsTexmod = 0;
                        fb3KaleidoscopeSliceTexmod = 0;
                        
                    }
                    
                    if(fb3TexmodSwitch==false){
                        ImGui::SliderFloat("fb3 fisheye amount", &fb3FisheyeAmount, -fb3FisheyeAmountRange, fb3FisheyeAmountRange);
                        ImGui::SliderFloat("fb3 fisheye x", &fb3FisheyeX, -fb3FisheyeXRange, fb3FisheyeXRange);
                        ImGui::SliderFloat("fb3 fisheye y", &fb3FisheyeY, -fb3FisheyeYRange, fb3FisheyeYRange);
                        
                        ImGui::SliderFloat("fb3 spiral amount", &fb3SpiralAmount, -fb3SpiralAmountRange, fb3SpiralAmountRange);
                        ImGui::SliderFloat("fb3 spiral angle", &fb3SpiralAngle, -fb3SpiralAngleRange, fb3SpiralAngleRange);
                        ImGui::SliderFloat("fb3 spiral x", &fb3SpiralX, -fb3SpiralXRange, fb3SpiralXRange);
                        ImGui::SliderFloat("fb3 spiral y", &fb3SpiralY, -fb3SpiralYRange, fb3SpiralYRange);
                        
                        ImGui::SliderInt("fb3 kaleidoscope segments", &fb3KaleidoscopeSegments, 0, fb3KaleidoscopeSegmentsRange);
                        ImGui::SliderFloat("fb3 kaleidoscope slice", &fb3KaleidoscopeSlice, -fb3KaleidoscopeSliceRange, fb3KaleidoscopeSliceRange);
                    }
                    
                    if(fb3TexmodSwitch==true){
                        ImGui::SliderFloat("texmod fb3 fisheye amount", &fb3FisheyeAmountTexmod, -fb3FisheyeAmountRange, fb3FisheyeAmountRange);
                        ImGui::SliderFloat("texmod fb3 fisheye x", &fb3FisheyeXTexmod, -fb3FisheyeXRange, fb3FisheyeXRange);
                        ImGui::SliderFloat("texmod fb3 fisheye y", &fb3FisheyeYTexmod, -fb3FisheyeYRange, fb3FisheyeYRange);
                        
                        ImGui::SliderFloat("texmod fb3 spiral amount", &fb3SpiralAmountTexmod, -fb3SpiralAmountRange, fb3SpiralAmountRange);
                        ImGui::SliderFloat("texmod fb3 spiral angle", &fb3SpiralAngleTexmod, -fb3SpiralAngleRange, fb3SpiralAngleRange);
                        ImGui::SliderFloat("texmod fb3 spiral x", &fb3SpiralXTexmod, -fb3SpiralXRange, fb3SpiralXRange);
                        ImGui::SliderFloat("texmod fb3 spiral y", &fb3SpiralYTexmod, -fb3SpiralYRange, fb3SpiralYRange);
                        
                        ImGui::SliderFloat("texmod fb3 kaleidoscope segments", &fb3KaleidoscopeSegmentsTexmod, 0, fb3KaleidoscopeSegmentsRange);
                        ImGui::SliderFloat("texmod fb3 kaleidoscope slice", &fb3KaleidoscopeSliceTexmod, -fb3KaleidoscopeSliceRange, fb3KaleidoscopeSliceRange);
                    }
                    
                }
                
                //ADD THE PIXELS HERE
                if (ImGui::CollapsingHeader("pixelate"))
                {
                    if (ImGui::Button("reset pixelate")) {
                        fb3PixelXYLock = 1;
                        fb3XPixelScale = 64;
                        fb3YPixelScale = 64;
                        fb3PixelMix = 1;
                        fb3PixelBrightscale = 0;
                        
                        fb3XPixelScaleTexmod=0;
                        fb3YPixelScaleTexmod=0;
                        fb3PixelMixTexmod=0;
                        fb3PixelBrightscaleTexmod=0;
                    }
                    ImGui::Checkbox("fb3 pixelate", &fb3PixelSwitch);
                    ImGui::Checkbox("fb3 pixelXY lock", &fb3PixelXYLock);
                    
                    if (fb3TexmodSwitch == false) {
                        ImGui::SliderInt("fb3 pixel scale x", &fb3XPixelScale, .0f, 256.0f);
                        if (fb3PixelXYLock == 1) {
                            ImGui::SliderInt("fb3 pixel scale y", &fb3XPixelScale, .0f, 256.0f);
                        }
                        if (fb3PixelXYLock == 0) {
                            ImGui::SliderInt("fb3 pixel scale y", &fb3YPixelScale, .0f, 256.0f);
                        }
                        ImGui::SliderFloat("fb3 pixel mix", &fb3PixelMix, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb3 bright scale", &fb3PixelBrightscale, -2.0f, 2.0f);
                    }
                    if (fb3TexmodSwitch == true) {
                        ImGui::SliderInt("fb3 texmod pixel scale x", &fb3XPixelScaleTexmod, -256.0f, 256.0f);
                        if (fb3PixelXYLock == 1) {
                            ImGui::SliderInt("fb3 texmod pixel scale y", &fb3XPixelScaleTexmod, -256.0f, 256.0f);
                        }
                        if (fb3PixelXYLock == 0) {
                            ImGui::SliderInt("fb3 texmod pixel scale y", &fb3YPixelScaleTexmod, -256.0f, 256.0f);
                        }
                        ImGui::SliderFloat("fb3 texmod pixel mix", &fb3PixelMixTexmod, -2.0f, 2.0f);
                        ImGui::SliderFloat("fb3 texmod bright scale", &fb3PixelBrightscaleTexmod, -2.0f, 2.0f);
                    }
                }
            }//end collapsing folder
            ImGui::Separator();
            if (ImGui::CollapsingHeader("L F O s")){
                ImGui::Text("Loose Floating Object s");
                if (ImGui::Button("reset lfo")) {
                    fb3ResetAllLfo();
                }
                if (ImGui::CollapsingHeader("mix and delay amount lfo")){
                    if (ImGui::Button("reset mix and delay lfo")) {
                        fb3_delay_lfo_theta = 0;
                        fb3DelayLfoAmp = 0;
                        fb3MixLfoTheta = 0;
                        fb3MixLfoAmp = 0;
                        fb3LumakeyLevelLfoTheta = 0;
                        fb3LumakeyLevelLfoAmp = 0;
                        fb3ChromakeyRedLfoTheta = 0;
                        fb3ChromakeyRedLfoAmp = 0;
                        fb3ChromakeyGreenLfoTheta = 0;
                        fb3ChromakeyGreenLfoAmp = 0;
                        fb3ChromakeyBlueLfoTheta = 0;
                        fb3ChromakeyBlueLfoAmp = 0;
                        fb3KeyThresholdLfoTheta = 0;
                        fb3KeyThresholdLfoAmp = 0;
                        fb3KeySoftLfoTheta = 0;
                        fb3KeySoftLfoAmp = 0;
                        fb3MaskXLfoTheta = 0;
                        fb3MaskXLfoAmp = 0;
                        fb3MaskYLfoTheta = 0;
                        fb3MaskYLfoAmp = 0;
                        fb3MaskZLfoTheta = 0.0;
                        fb3MaskZLfoAmp = 0.0;
                        fb3MaskRotateLfoTheta = 0;
                        fb3MaskRotateLfoAmp = 0;
                        fb3MaskTileAmountLfoTheta = 0.0;
                        fb3MaskTileAmountLfoAmp = 0.0;
                        fb3MaskTexmodOffsetLfoTheta = 0;
                        fb3MaskTexmodOffsetLfoAmp = 0;
                        fb3MaskTexmodQuantizeAmountLfoTheta = 0.0;
                        fb3MaskTexmodQuantizeAmountLfoAmp = 0.0;
                        fb3MaskTexmodQuantizeMixLfoTheta = 0.0;
                        fb3MaskTexmodQuantizeMixLfoAmp = 0.0;
                    }
                    ImGui::SliderFloat("fb3DelayLfoRate", &fb3_delay_lfo_theta, .0f, 10.0f);
                    ImGui::SliderFloat("fb3DelayLfoAmp", &fb3DelayLfoAmp, -1.0f, 1.0f);
                    ImGui::SliderFloat("fb3MixLfoRate", &fb3MixLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3MixLfoAmp", &fb3MixLfoAmp, -2.0f, 2.0f);
                    //Not Wipes
                    if (fb3KeyMode != 2) {
                        //luma
                        if (fb3KeyMode == 0) {
                            ImGui::SliderFloat("fb3LumakeyLevelLfoRate", &fb3LumakeyLevelLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3LumakeyLevelLfoAmp", &fb3LumakeyLevelLfoAmp, -1.0f, 1.0f);
                        }
                        if (fb3KeyMode == 1) {
                            ImGui::SliderFloat("fb3ChromakeyRedLfoRate", &fb3ChromakeyRedLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3ChromakeyRedLfoAmp", &fb3ChromakeyRedLfoAmp, -1.0f, 1.0f);
                            ImGui::SliderFloat("fb3ChromakeyGreenLfoRate", &fb3ChromakeyGreenLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3ChromakeyGreenLfoAmp", &fb3ChromakeyGreenLfoAmp, -1.0f, 1.0f);
                            ImGui::SliderFloat("fb3ChromakeyBlueLfoRate", &fb3ChromakeyBlueLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3ChromakeyBlueLfoAmp", &fb3ChromakeyBlueLfoAmp, -1.0f, 1.0f);
                        }
                        ImGui::SliderFloat("fb3Keythreshold_lfo_rate", &fb3KeyThresholdLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3KeyThresholdLfoAmp", &fb3KeyThresholdLfoAmp, -rootThree, rootThree);
                        ImGui::SliderFloat("fb3KeySoftLfoRate", &fb3KeySoftLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3KeySoftLfoAmp", &fb3KeySoftLfoAmp, -1.0, 1.0);
                    }
                    if (fb3KeyMode == 2) {
                        fb3ChromakeyRedLfoAmp = 0;
                        fb3ChromakeyGreenLfoAmp = 0;
                        fb3ChromakeyBlueLfoAmp = 0;
                        fb3LumakeyLevelLfoAmp = 0;
                        fb3KeyThresholdLfoAmp = 0;
                        //regular wipes
                        if (fb3MaskSelect != 4) {
                            ImGui::SliderFloat("fb3MaskXLfoRate", &fb3MaskXLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3MaskXLfoAmp", &fb3MaskXLfoAmp, -outWidth * .5f, outWidth*.5f);
                            ImGui::SliderFloat("fb3MaskYLfoRate", &fb3MaskYLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3MaskYLfoAmp", &fb3MaskYLfoAmp, -outHeight * .5f, outHeight*.5f);
                            ImGui::SliderFloat("fb3MaskZLfoRate", &fb3MaskZLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3MaskZLfoAmp", &fb3MaskZLfoAmp, -3.0f, 3.0f);
                            ImGui::SliderFloat("fb3MaskRotateLfoRate", &fb3MaskRotateLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3MaskRotateLfoAmp", &fb3MaskRotateLfoAmp, -TWO_PI, TWO_PI);
                            ImGui::SliderFloat("fb3MaskTileAmountLfoRate", &fb3MaskTileAmountLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3MaskTileAmountLfoAmp", &fb3MaskTileAmountLfoAmp, -3.0f, 3.0f);
                        }
                        //texmodWipes
                        if (fb3MaskSelect == 4) {
                            ImGui::SliderFloat("fb3MaskTexmodOffsetLfoRate", &fb3MaskTexmodOffsetLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3MaskTexmodOffsetLfoAmp", &fb3MaskTexmodOffsetLfoAmp, -1.0, 1.0);
                            ImGui::SliderFloat("fb3MaskTexmodQuantizeAmountLfoRate", &fb3MaskTexmodQuantizeAmountLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3MaskTexmodQuantizeAmountLfoAmp", &fb3MaskTexmodQuantizeAmountLfoAmp, 0.0, 32.0);
                            ImGui::SliderFloat("fb3MaskTexmodQuantizeMixLfoRate", &fb3MaskTexmodQuantizeMixLfoTheta, .0f, lfom);
                            ImGui::SliderFloat("fb3MaskTexmodQuantizeMixLfoAmp", &fb3MaskTexmodQuantizeMixLfoAmp, 0.0, 1.0);
                        }
                    }
                }
                if (ImGui::CollapsingHeader("color1  lfo")){
                    if (ImGui::Button("reset color1 lfo")) {
                        fb3HueOffsetLfoTheta = 0.0;
                        fb3SaturationOffsetLfoTheta = 0.0;
                        fb3BrightOffsetLfoTheta = 0.0;
                        fb3HueAttenuateLfoTheta = 0.0;
                        fb3SaturationAttenuateLfoTheta = 0.0;
                        fb3BrightAttenuateLfoTheta = 0.0;
                        fb3HueShaperLfoTheta = 0.0;
                        fb3HuePowMapLfoTheta = 0;
                        fb3SaturationPowMapLfoTheta = .0;
                        fb3BrightPowMapLfoTheta = .0;
                        
                        fb3HueOffsetLfoAmp = 0.0;
                        fb3SaturationOffsetLfoAmp = 0.0;
                        fb3BrightOffsetLfoAmp = 0.0;
                        fb3HueAttenuateLfoAmp = 0.0;
                        fb3SaturationAttenuateLfoAmp = 0.0;
                        fb3BrightAttenuateLfoAmp = 0.0;
                        fb3HueShaperLfoAmp = 0.0;
                        fb3HuePowMapLfoAmp = 0;
                        fb3SaturationPowMapLfoAmp = .0;
                        fb3BrightPowMapLfoAmp = .0;
                    }
                    
                    ImGui::SliderFloat("fb3HueOffsetLfo_rate", &fb3HueOffsetLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3HueOffsetLfoAmp", &fb3HueOffsetLfoAmp, -fb3HueOffsetRange, fb3HueOffsetRange);
                    ImGui::SliderFloat("fb3SaturationOffset_lfo_rate", &fb3SaturationOffsetLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3SaturationOffsetLfoAmp", &fb3SaturationOffsetLfoAmp, -fb3SaturationOffsetRange, fb3SaturationOffsetRange);
                    ImGui::SliderFloat("fb3BrightOffset_lfo_rate", &fb3BrightOffsetLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3BrightOffsetLfoAmp", &fb3BrightOffsetLfoAmp, -fb3BrightOffsetRange, fb3BrightOffsetRange);
                    ImGui::Separator();
                    ImGui::SliderFloat("fb3HueAttenuateLfo_rate", &fb3HueAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3HueAttenuateLfoAmp", &fb3HueAttenuateLfoAmp, -fb3HueAttenuateRange, fb3HueAttenuateRange);
                    ImGui::SliderFloat("fb3SaturationAttenuate_lfo_rate", &fb3SaturationAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3SaturationAttenuateLfoAmp", &fb3SaturationAttenuateLfoAmp, -fb3SaturationAttenuateRange, fb3SaturationAttenuateRange);
                    ImGui::SliderFloat("fb3BrightAttenuate_lfo_rate", &fb3BrightAttenuateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3BrightAttenuateLfoAmp", &fb3BrightAttenuateLfoAmp, -fb3BrightAttenuateRange, fb3BrightAttenuateRange);
                    ImGui::Separator();
                    ImGui::SliderFloat("fb3HueShaperLfo_rate", &fb3HueShaperLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3HueShaperLfoAmp", &fb3HueShaperLfoAmp, -fb3HueShaperRange, fb3HueShaperRange);
                    
                    ImGui::SliderFloat("fb3HuePowMapLfo_rate", &fb3HuePowMapLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3HuePowMapLfoAmp", &fb3HuePowMapLfoAmp, -fb3HuePowMapRange, fb3HuePowMapRange);
                    ImGui::SliderFloat("fb3SaturationPowMap_lfo_rate", &fb3SaturationPowMapLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3SaturationPowMapLfoAmp", &fb3SaturationPowMapLfoAmp, -fb3SaturationPowMapRange, fb3SaturationPowMapRange);
                    ImGui::SliderFloat("fb3BrightPowMap_lfo_rate", &fb3BrightPowMapLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3BrightPowMapLfoAmp", &fb3BrightPowMapLfoAmp, -fb3BrightPowMapRange, fb3BrightPowMapRange);
                    
                }
                if (ImGui::CollapsingHeader("color2  lfo")) {
                    if (ImGui::Button("reset color2 lfo")) {
                        fb3HueQuantizeLfoTheta = 0;
                        fb3SaturationQuantizeLfoTheta = 0;
                        fb3BrightQuantizeLfoTheta = 0;
                        fb3HueQuantizeMixLfoTheta = 0.0;
                        fb3SaturationQuantizeMixLfoTheta = 0.0;
                        fb3BrightQuantizeMixLfoTheta = 0.0;
                        fb3HueDitherMixLfoTheta = 0.0;
                        fb3HueDitherAmountLfoTheta = 0;
                        fb3SaturationDitherMixLfoTheta = 0.0;
                        fb3SaturationDitherAmountLfoTheta = 0;
                        fb3BrightDitherMixLfoTheta = 0.0;
                        fb3BrightDitherAmountLfoTheta = 0;
                        
                        fb3HueQuantizeLfoAmp = 0;
                        fb3SaturationQuantizeLfoAmp = 0;
                        fb3BrightQuantizeLfoAmp = 0;
                        fb3HueQuantizeMixLfoAmp = 0.0;
                        fb3SaturationQuantizeMixLfoAmp = 0.0;
                        fb3BrightQuantizeMixLfoAmp = 0.0;
                        fb3HueDitherMixLfoAmp = 0.0;
                        fb3HueDitherAmountLfoAmp = 0;
                        fb3SaturationDitherMixLfoAmp = 0.0;
                        fb3SaturationDitherAmountLfoAmp = 0;
                        fb3BrightDitherMixLfoAmp = 0.0;
                        fb3BrightDitherAmountLfoAmp = 0;
                    }
                    if (ImGui::CollapsingHeader("quantize lfos")) {
                        ImGui::SliderFloat("fb3HueQuantizeMixLfo_rate", &fb3HueQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3HueQuantizeMixLfoAmp", &fb3HueQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb3HueQuantizeLfo_rate", &fb3HueQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3HueQuantizeLfoAmp", &fb3HueQuantizeLfoAmp, -fb3HueQuantizeRange, fb3HueQuantizeRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb3SaturationQuantizeMix_lfo_rate", &fb3SaturationQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3SaturationQuantizeMixLfoAmp", &fb3SaturationQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb3SaturationQuantize_lfo_rate", &fb3SaturationQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3SaturationQuantizeLfoAmp", &fb3SaturationQuantizeLfoAmp, -fb3SaturationQuantizeRange, fb3SaturationQuantizeRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb3BrightQuantizeMix_lfo_rate", &fb3BrightQuantizeMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3BrightQuantizeMixLfoAmp", &fb3BrightQuantizeMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb3BrightQuantize_lfo_rate", &fb3BrightQuantizeLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3BrightQuantizeLfoAmp", &fb3BrightQuantizeLfoAmp, -fb3BrightQuantizeRange, fb3BrightQuantizeRange);
                    }
                    ImGui::Separator();
                    if (ImGui::CollapsingHeader("dither lfos")) {
                        ImGui::SliderFloat("fb3HueDitherMixLfo_rate", &fb3HueDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3HueDitherMixLfoAmp", &fb3HueDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb3HueDitherLfo_rate", &fb3HueDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3HueDitherLfoAmp", &fb3HueDitherAmountLfoAmp, -fb3HueDitherRange, fb3HueDitherRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb3SaturationDitherMix_lfo_rate", &fb3SaturationDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3SaturationDitherMixLfoAmp", &fb3SaturationDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb3SaturationDither_lfo_rate", &fb3SaturationDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3SaturationDitherLfoAmp", &fb3SaturationDitherAmountLfoAmp, -fb3SaturationDitherRange, fb3SaturationDitherRange);
                        ImGui::Separator();
                        ImGui::SliderFloat("fb3BrightDitherMix_lfo_rate", &fb3BrightDitherMixLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3BrightDitherMixLfoAmp", &fb3BrightDitherMixLfoAmp, -1.0f, 1.0f);
                        ImGui::SliderFloat("fb3BrightDither_lfo_rate", &fb3BrightDitherAmountLfoTheta, .0f, lfom);
                        ImGui::SliderFloat("fb3BrightDitherLfoAmp", &fb3BrightDitherAmountLfoAmp, -fb3BrightDitherRange, fb3BrightDitherRange);
                    }
                }
                if (ImGui::CollapsingHeader("geo1 lfo")){
                    if (ImGui::Button("reset geo1 lfo")) {
                        fb3XDisplaceLfoTheta = 0.0;
                        fb3YDisplaceLfoTheta = 0.0;
                        fb3ZDisplaceLfoTheta = 0.0;
                        fb3RotateLfoTheta = 0;
                        fb3ShearMatrixLfoTheta.set(0,0,0,0);
                        
                        fb3XDisplaceLfoAmp = 0.0;
                        fb3YDisplaceLfoAmp = 0.0;
                        fb3ZDisplaceLfoAmp = 0.0;
                        fb3RotateLfoAmp = 0;
                        fb3ShearMatrixLfoAmp.set(0, 0, 0, 0);
                    }
                    ImGui::SliderFloat("fb3XDisplace_lfo_rate", &fb3XDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3XDisplace_lfo_amp", &fb3XDisplaceLfoAmp, -fb3XDisplaceRange, fb3XDisplaceRange);
                    ImGui::SliderFloat("fb3YDisplace_lfo_rate", &fb3YDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3YDisplace_lfo_amp", &fb3YDisplaceLfoAmp, -fb3YDisplaceRange, fb3YDisplaceRange);
                    ImGui::SliderFloat("fb3ZDisplace_lfo_rate", &fb3ZDisplaceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3ZDisplace_lfo_amp", &fb3ZDisplaceLfoAmp, -fb3ZDisplaceRange, fb3ZDisplaceRange);
                    ImGui::SliderFloat("fb3Rotate_lfo_rate", &fb3RotateLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3RotateLfoAmp", &fb3RotateLfoAmp, -fb3ZRotateRange, fb3ZRotateRange);
                    
                    ImGui::SliderFloat("fb3 Shear matrix 1 lfo rate", &fb3ShearMatrixLfoTheta.x, .0f, lfom);
                    ImGui::SliderFloat("fb3 Shear matrix 1 lfo amp", &fb3ShearMatrixLfoAmp.x, -fb3ShearMatrixRange.x, fb3ShearMatrixRange.x);
                    ImGui::SliderFloat("fb3 Shear matrix 2 lfo rate", &fb3ShearMatrixLfoTheta.y, .0f, lfom);
                    ImGui::SliderFloat("fb3 Shear matrix 2 lfo amp", &fb3ShearMatrixLfoAmp.y, -fb3ShearMatrixRange.y, fb3ShearMatrixRange.y);
                    ImGui::SliderFloat("fb3 Shear matrix 3 lfo rate", &fb3ShearMatrixLfoTheta.z, .0f, lfom);
                    ImGui::SliderFloat("fb3 Shear matrix 3 lfo amp", &fb3ShearMatrixLfoAmp.z, -fb3ShearMatrixRange.z, fb3ShearMatrixRange.z);
                    ImGui::SliderFloat("fb3 Shear matrix 4 lfo rate", &fb3ShearMatrixLfoTheta.w, .0f, lfom);
                    ImGui::SliderFloat("fb3 Shear matrix 4 lfo amp", &fb3ShearMatrixLfoAmp.w, -fb3ShearMatrixRange.w, fb3ShearMatrixRange.w);
                }
                if (ImGui::CollapsingHeader("geo2 lfo")) {
                    if (ImGui::Button("reset geo2 lfo")) {
                        fb3FisheyeAmountLfoTheta = 0;
                        fb3FisheyeXLfoTheta = 0;
                        fb3FisheyeYLfoTheta = 0;
                        fb3SpiralAmountLfoTheta = 0;
                        fb3SpiralAngleLfoTheta = 0;
                        fb3SpiralXLfoTheta = 0;
                        fb3SpiralYLfoTheta = 0;
                        fb3KaleidoscopeSegmentsLfoTheta = 0;
                        fb3KaleidoscopeSliceLfoTheta = 0;
                        
                        fb3FisheyeAmountLfoAmp = 0;
                        fb3FisheyeXLfoAmp = 0;
                        fb3FisheyeYLfoAmp = 0;
                        fb3SpiralAmountLfoAmp = 0;
                        fb3SpiralAngleLfoAmp = 0;
                        fb3SpiralXLfoAmp = 0;
                        fb3SpiralYLfoAmp = 0;
                        fb3KaleidoscopeSegmentsLfoAmp = 0;
                        fb3KaleidoscopeSliceLfoAmp = 0;
                    }
                    //geo 2 lfos
                    ImGui::SliderFloat("fb3 fisheye amount lfo rate", &fb3FisheyeAmountLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3 fisheye amount lfo amp", &fb3FisheyeAmountLfoAmp, -fb3FisheyeAmountRange, fb3FisheyeAmountRange);
                    ImGui::SliderFloat("fb3 fisheye x lfo rate", &fb3FisheyeXLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3 fisheye x lfo amp", &fb3FisheyeXLfoAmp, -fb3FisheyeXRange, fb3FisheyeXRange);
                    ImGui::SliderFloat("fb3 fisheye y lfo rate", &fb3FisheyeYLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3 fisheye y lfo amp", &fb3FisheyeYLfoAmp, -fb3FisheyeYRange, fb3FisheyeYRange);
                    
                    ImGui::SliderFloat("fb3 spiral amount lfo rate", &fb3SpiralAmountLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3 spiral amount lfo amp", &fb3SpiralAmountLfoAmp, -fb3SpiralAmountRange, fb3SpiralAmountRange);
                    ImGui::SliderFloat("fb3 spiral angle lfo rate", &fb3SpiralAngleLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3 spiral angle lfo amp", &fb3SpiralAngleLfoAmp, -fb3SpiralAngleRange, fb3SpiralAngleRange);
                    ImGui::SliderFloat("fb3 spiral x lfo rate", &fb3SpiralXLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3 spiral x lfo amp", &fb3SpiralXLfoAmp, -fb3SpiralXRange, fb3SpiralXRange);
                    ImGui::SliderFloat("fb3 spiral y lfo rate", &fb3SpiralYLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3 spiral y lfo amp", &fb3SpiralYLfoAmp, -fb3SpiralYRange, fb3SpiralYRange);
                    
                    ImGui::SliderFloat("fb3 kaleidoscope segments lfo rate", &fb3KaleidoscopeSegmentsLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3 kaleidoscope segments lfo amp", &fb3KaleidoscopeSegmentsLfoAmp, 0, fb3KaleidoscopeSegmentsRange);
                    ImGui::SliderFloat("fb3 kaleidoscope slice lfo rate", &fb3KaleidoscopeSliceLfoTheta, .0f, lfom);
                    ImGui::SliderFloat("fb3 kaleidoscope slice lfo amp", &fb3KaleidoscopeSliceLfoAmp, -fb3KaleidoscopeSliceRange, fb3KaleidoscopeSliceRange);
                }
                
                if (ImGui::CollapsingHeader("pixelation"))
                {
                    if (ImGui::Button("reset pixelation lfo")) {
                        fb3XPixelScaleLfoTheta = 0;
                        fb3XPixelScaleLfoAmp = 0;
                        fb3YPixelScaleLfoTheta = 0;
                        fb3YPixelScaleLfoAmp = 0;
                        fb3PixelMixLfoTheta = 0;
                        fb3PixelMixLfoAmp = 0;
                        fb3PixelBrightscaleLfoTheta = 0;
                        fb3PixelBrightscaleLfoAmp = 0;
                    }
                    //ImGui::Text("Love Flange Orgasms s");
                    ImGui::SliderFloat("fb3 pixel scale_x_rate", &fb3XPixelScaleLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb3 pixel scale_x_amp", &fb3XPixelScaleLfoAmp, -256.0f, 256.0f);
                    ImGui::SliderFloat("fb3 pixel scale_y_rate", &fb3YPixelScaleLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb3 pixel scale_y_amp", &fb3YPixelScaleLfoAmp, -256.0f, 256.0f);
                    ImGui::SliderFloat("fb3 pixel mix_rate", &fb3PixelMixLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb3 pixel mix_amp", &fb3PixelMixLfoAmp, -2.0f, 2.0f);
                    ImGui::SliderFloat("fb3 pixel bright scale rate", &fb3PixelBrightscaleLfoTheta, .0f, 20.0f);
                    ImGui::SliderFloat("fb3 pixel bright scale amp", &fb3PixelBrightscaleLfoAmp, -2.0f, 2.0f);
                }
            }//endlfo folder
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
        
        
        
        
        
        
        
        
        
       // mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 5*gui_vscaler));
      
        
        
         mainSettings.windowPos=ImVec2(ImVec2(0*gui_hscaler, 6*gui_vscaler-40));
        //ImGui::SetNextWindowPos(ImVec2(600, 600), ImGuiCond_FirstUseEver);
        //ImGui::SetNextWindowSize(ImVec2(gui_hscaler, gui_vscaler), ImGuiCond_FirstUseEver);
        //global folder
        if (ofxImGui::BeginWindow("global", mainSettings, false))
			//add to global
			//mirror combined outputs??
			if (ImGui::Button("reset global all")) {
				globalResetAll();
			}
        {
            if (ImGui::CollapsingHeader("parameters"))
            {
				static int item_current = 0;
				if (ImGui::Button("reset global parameters")) {
					globalResetAllParameters();
					item_current = 0;
				}
                ImGui::Checkbox("tex_mod", &global_texmod);
                
                const char* items[] = { "cam1","cam2","ndi" };
                
                ImGui::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
				global_texmod_select = item_current;
				/*
                if(item_current==0){global_texmod_select=0;}
                if(item_current==1){global_texmod_select=1;}
                if(item_current==2){global_texmod_select=2;}
                */

                //ImGui::Button("framebuffer clear");
                framebuffer_clear=false;
                ImGui::Checkbox("framebuffer clear", &framebuffer_clear);
                
                control_reset=false;
                ImGui::Checkbox("control_reset", &control_reset);
                
                if(global_texmod==false){
                    //blur
                    ImGui::SliderFloat("blur amount", &blur_amount, -2.0f, 2.0f);
                    ImGui::SliderFloat("blur radius", &blur_radius, .0f, 10.0f);
                    //sharpen
                    ImGui::SliderFloat("sharpen", &sharpen_amount, -.6f, .6f);
                    ImGui::SliderFloat("sharpen_radius", &sharpen_radius, .0f, 10.f);
                    
                    ImGui::SliderFloat("sharpen_boost", &sharpen_boost, .0f, 1.0f);
                }
                
                if(global_texmod==true){
                    //blur
                    ImGui::SliderFloat("texmod blur amount", &texmod_blur_amount, -4.0f, 4.0f);
                    ImGui::SliderFloat("texmod blur radius", &texmod_blur_radius, -2.0f, 2.0f);
                    //sharpen
                    ImGui::SliderFloat("texmod sharpen", &texmod_sharpen_amount, -.6f, .6f);
                    ImGui::SliderFloat("texmod sharpen_radius", &texmod_sharpen_radius, .0f, 10.f);
                    
                    ImGui::SliderFloat("texmod sharpen_boost", &texmod_sharpen_boost, -.4f, .4f);
                }
               
                ImGui::SliderFloat("ndi_scale", &ndi_scale, -1000.0f, 500.0f);
                //xskew
                ImGui::SliderFloat("x_skew", &x_skew, -3.14f, 3.14f);
                //yskew
                ImGui::SliderFloat("y_skew", &y_skew, -3.14f, 3.14f);
                //tetrahedron
                ImGui::Checkbox("tetrahedron", &tetrahedron_switch);
                //hypercube
                ImGui::Checkbox("hypercube", &hypercube_switch);
                ImGui::SliderFloat("hypercube_theta_rate", &hypercube_theta_rate, -.1,.1);
                ImGui::SliderFloat("hypercube_phi_rate", &hypercube_phi_rate, -.1,.1);
                
            }//end collapsing folder
            
            if (ImGui::CollapsingHeader("L F O s"))
            {   ImGui::Text("Lusty Fresh Onagers s");
				if (ImGui::Button("reset global lfo")) {
					globalResetAllLfo();
				}

				ImGui::SliderFloat("blur_lfo_rate", &blur_amount_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("blur_lfo_amp", &blur_amount_lfo_amp, -10.0f, 10.0f);
				ImGui::SliderFloat("blur_radius_lfo_rate", &blur_radius_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("blur_radius_lfo_amp", &blur_radius_lfo_amp, -10.0f, 10.0f);
				ImGui::SliderFloat("sharpen_lfo_rate", &sharpen_amount_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("sharpen_lfo_amp", &sharpen_amount_lfo_amp, -.6f, .6f);
				ImGui::SliderFloat("sharpen_radius_lfo_rate", &sharpen_radius_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("sharpen_radius_lfo_amp", &sharpen_radius_lfo_amp, -10.0f, 10.f);
				ImGui::SliderFloat("sharpen_boost_lfo_rate", &sharpen_boost_lfo_theta, .0f, 20.0f);
                ImGui::SliderFloat("sharpen_boost_lfo_amp", &sharpen_boost_lfo_amp, -1.0f, 1.0f);
                

            }
            
        }//endImguiWindow
        ofxImGui::EndWindow(mainSettings);
        
		mainSettings.windowPos = ImVec2(ImVec2(1 * gui_hscaler, 6 * gui_vscaler - 40));
		//reset all
		if (ofxImGui::BeginWindow("reset all", mainSettings, false)) {
			if (ImGui::Button("reset global all")) {
				resetAll();
			}
		}
		ofxImGui::EndWindow(mainSettings);
       
        
        gui.end();
        
    }
	//
	void GuiApp::resetAll() {
		ch1ResetAll();
		ch2ResetAll();
		fb0ResetAll();
		fb1ResetAll();
		fb2ResetAll();
		fb3ResetAll();
		globalResetAll();
	}

	//---------------------------------------
	void GuiApp::ch1ResetAllParameters() {
		ch1Scale = 1.0;
		ch1HsbAttenuate.set(0,0,0);
		ch1Quantize = 32;
		ch1QuantizeSwitch = false;
		ch1HueInvert = false;
		ch1BrightInvert = false;
		ch1SaturationInvert = false;
		ch1HMirror = false;
		ch1VMirror = false;

		ch1PixelSwitch = 0;
		ch1PixelXYLock = 1;
		ch1XPixelScale = 64;
		ch1YPixelScale = 64;
		ch1PixelMix = 1;
		ch1PixelBrightscale = 0;
	}

	void GuiApp::ch1ResetAllLfo() {
		ch1ScaleLfoTheta = .0;
		ch1ScaleLfoAmp = .0;
		ch1HsbAttenuateLfoTheta.set(0,0,0);
		ch1HsbAttenuateLfoAmp.set(0,0,0);
		ch1QuantizeLfoTheta = 0;
		ch1QuantizeLfoAmp = 0;

		ch1XPixelScaleLfoTheta = 0;
		ch1XPixelScaleLfoAmp = 0;
		ch1YPixelScaleLfoTheta = 0;
		ch1YPixelScaleLfoAmp = 0;
		ch1PixelMixLfoTheta = 0;
		ch1PixelMixLfoAmp = 0;
		ch1PixelBrightscaleLfoTheta = 0;
		ch1PixelBrightscaleLfoAmp = 0;
	}

	void GuiApp::ch1ResetAll() {
		ch1ResetAllParameters();
		ch1ResetAllLfo();
	}
	//----------------------------------
	void GuiApp::ch2ResetAllParameters() {

		ch2LumakeyLevel = 0;
		ch2ChromakeyRed = 0;
		ch2ChromakeyGreen = 0;
		ch2ChromakeyBlue = 0;
		ch2KeyThreshold = 0;
		ch2KeySoft = 0;
		ch2Mix = 0;

		ch2Scale = 1.0;
		ch2HsbAttenuate.set(0, 0, 0);
		ch2Quantize = 32;
		ch2QuantizeSwitch = false;
		ch2HueInvert = false;
		ch2BrightInvert = false;
		ch2SaturationInvert = false;

		ch2PixelSwitch = 0;
		ch2PixelXYLock = 1;
		ch2XPixelScale = 64;
		ch2YPixelScale = 64;
		ch2PixelMix = 1;
		ch2PixelBrightscale = 0;
	}

	void GuiApp::ch2ResetAllLfo() {
		ch2ScaleLfoTheta = .0;
		ch2ScaleLfoAmp = .0;
		ch2HsbAttenuateLfoTheta.set(0, 0, 0);
		ch2HsbAttenuateLfoAmp.set(0, 0, 0);
		ch2QuantizeLfoTheta = 0;
		ch2QuantizeLfoAmp = 0;

		ch2XPixelScaleLfoTheta = 0;
		ch2XPixelScaleLfoAmp = 0;
		ch2YPixelScaleLfoTheta = 0;
		ch2YPixelScaleLfoAmp = 0;
		ch2PixelMixLfoTheta = 0;
		ch2PixelMixLfoAmp = 0;
		ch2PixelBrightscaleLfoTheta = 0;
		ch2PixelBrightscaleLfoAmp = 0;
	}

	void GuiApp::ch2ResetAll() {
		ch2ResetAllLfo();
		ch2ResetAllParameters();
	}
	//----------------------------------
	void GuiApp::fb0ResetAllParameters() {
		fb0LumakeyLevel = 0;
		fb0KeyThreshold = 0;
		fb0ChromakeyRed = 0;
		fb0ChromakeyGreen = 0;
		fb0ChromakeyBlue = 0;
		fb0KeySoft = 0;
		fb0MaskX = 0;
		fb0MaskY = 0;
		fb0MaskZ = 1.0;
		fb0MaskRotate = 0;
		fb0MaskTileAmount = 1.0;
		fb0MaskTexmodOffset = 0;
		fb0MaskTexmodQuantizeAmount = 1.0;
		fb0MaskTexmodQuantizeMix = 1.0;
		fb0Mix = 0;
		fb0HueOffset = 0.0;
		fb0SaturationOffset = 0.0;
		fb0BrightOffset = 0.0;
		fb0HueAttenuate = 10.0;
		fb0SaturationAttenuate = 10.0;
		fb0BrightAttenuate = 10.0;
		fb0HueShaper = 0.0;
        fb0HuePowMap= 1.0;
        fb0SaturationPowMap = 1.0;
        fb0BrightPowMap = 1.0;
		fb0HueInvert = 0;
		fb0SaturationInvert = 0;
		fb0BrightInvert = 0;

		fb0HueShaperRange = 0.25;
		fb0HueOffsetRange = .25;
		fb0SaturationOffsetRange = 0.25;
		fb0BrightOffsetRange = 0.25;
		fb0HueAttenuateRange = 2.0;
		fb0SaturationAttenuateRange = 2.0;
		fb0BrightAttenuateRange = 2.0;

		fb0HueInvert = 0;
		fb0SaturationInvert = 0;
		fb0BrightInvert = 0;

		fb0SaturationOverflow = 0;
		fb0BrightOverflow = 0;
		fb0HuePowMapRange = .25;
		fb0SaturationPowMapRange = .25;
		fb0BrightPowMapRange = .25;

		fb0HueQuantize = 128;
		fb0SaturationQuantize = 128;
		fb0BrightQuantize = 128;
		fb0HueQuantizeMix = 0.0;
		fb0SaturationQuantizeMix = 0.0;
		fb0BrightQuantizeMix = 0.0;
		fb0HueDitherMix = 0.0;
		fb0HueDitherAmount = 64;
		fb0SaturationDitherMix = 0.0;
		fb0SaturationDitherAmount = 64;
		fb0BrightDitherMix = 0.0;
		fb0BrightDitherAmount = 64;

		fb0_toroid_switch = 0;
		fb0XDisplace = 0.0;
		fb0YDisplace = 0.0;
		fb0ZDisplace = 100.0;
		fb0Rotate = 0;
		fb0ShearMatrix.set(0, 0, 0, 0);
		fb0ShearMatrixRange.set(0.25, 0.25, 0.25, 0.25);
		fb0RotateMode = 0;
		fb0HorizontalMirror = 0;
		fb0VerticalMirror = 0;
		fb0XDisplaceRange = 40;
		fb0YDisplaceRange = 40;
		fb0ZDisplaceRange = 10;
		fb0ZRotateRange = PI;

		fb0FisheyeAmount = 0;
		fb0FisheyeX = 0;
		fb0FisheyeY = 0;
		fb0SpiralAmount = 0;
		fb0SpiralAngle = 0;
		fb0SpiralX = 0;
		fb0SpiralY = 0;
		fb0KaleidoscopeSegments = 0;
		fb0KaleidoscopeSlice = 0;

        fb0FisheyeAmountRange = .15;
        fb0FisheyeXRange = .25;
        fb0FisheyeYRange = .25;
        fb0SpiralAmountRange = .15;
        fb0SpiralAngleRange = PI;
        fb0SpiralXRange = .25;
        fb0SpiralYRange = .25;
        fb0KaleidoscopeSegmentsRange = 21;
        fb0KaleidoscopeSliceRange = PI;

		fb0PixelXYLock = 1;
		fb0PixelSwitch = 0;
		fb0XPixelScale = 64;
		fb0YPixelScale = 64;
		fb0PixelMix = 1;
		fb0PixelBrightscale = 0;

		//texmods, dunno if we want these seperate or with everything
		//keep it easy to seperate for now
		fb0LumakeyLevelTexmod = 0.0;
		fb0ChromakeyRedTexmod = 0;
		fb0ChromakeyGreenTexmod = 0;
		fb0ChromakeyBlueTexmod = 0;
		fb0KeyThresholdTexmod = 0.0;
		fb0KeySoftTexmod = 0;
		fb0MixTexmod = .0;
		fb0MaskXTexmod = 0;
		fb0MaskYTexmod = 0;
		fb0MaskZTexmod = 0.0;
		fb0MaskRotateTexmod = 0;
		fb0MaskTileAmountTexmod = 0.0;

		fb0HueOffsetTexmod = 0.0;
		fb0SaturationOffsetTexmod = 0.0;
		fb0BrightOffsetTexmod = 0.0;
		fb0HueAttenuateTexmod = 0.0;
		fb0SaturationAttenuateTexmod = 0.0;
		fb0BrightAttenuateTexmod = 0.0;
		fb0HueShaperTexmod = 0.0;
		fb0HuePowMapTexmod = .0;
		fb0SaturationPowMapTexmod = .0;
		fb0BrightPowMapTexmod = .0;

		fb0HueQuantizeTexmod = 0;
		fb0SaturationQuantizeTexmod = 0;
		fb0BrightQuantizeTexmod = 0;
		fb0HueQuantizeMixTexmod = 0.0;
		fb0SaturationQuantizeMixTexmod = 0.0;
		fb0BrightQuantizeMixTexmod = 0.0;
		fb0HueDitherMixTexmod = 0.0;
		fb0HueDitherAmountTexmod = 0;
		fb0SaturationDitherMixTexmod = 0.0;
		fb0SaturationDitherAmountTexmod = 0;
		fb0BrightDitherMixTexmod = 0.0;
		fb0BrightDitherAmountTexmod = 0;
        
        fb0XDisplaceTexmod=0.0;
        fb0YDisplaceTexmod=0.0;
        fb0ZDisplaceTexmod=0;
        fb0RotateTexmod=0;
        fb0ShearMatrixTexmod.set(0,0,0,0);
        
        fb0FisheyeAmountTexmod = 0;
        fb0FisheyeXTexmod = 0;
        fb0FisheyeYTexmod = 0;
        fb0SpiralAmountTexmod = 0;
        fb0SpiralAngleTexmod = 0;
        fb0SpiralXTexmod = 0;
        fb0SpiralYTexmod = 0;
        fb0KaleidoscopeSegmentsTexmod = 0;
        fb0KaleidoscopeSliceTexmod = 0;
        
	}
	void GuiApp::fb0ResetAllLfo() {
	
		fb0_delay_lfo_theta = 0;
		fb0DelayLfoAmp = 0;
		fb0MixLfoTheta = 0;
		fb0MixLfoAmp = 0;
		fb0LumakeyLevelLfoTheta = 0;
		fb0LumakeyLevelLfoAmp = 0;
		fb0ChromakeyRedLfoTheta = 0;
		fb0ChromakeyRedLfoAmp = 0;
		fb0ChromakeyGreenLfoTheta = 0;
		fb0ChromakeyGreenLfoAmp = 0;
		fb0ChromakeyBlueLfoTheta = 0;
		fb0ChromakeyBlueLfoAmp = 0;
		fb0KeyThresholdLfoTheta = 0;
		fb0KeyThresholdLfoAmp = 0;
		fb0KeySoftLfoTheta = 0;
		fb0KeySoftLfoAmp = 0;
		fb0MaskXLfoTheta = 0;
		fb0MaskXLfoAmp = 0;
		fb0MaskYLfoTheta = 0;
		fb0MaskYLfoAmp = 0;
		fb0MaskZLfoTheta = 0.0;
		fb0MaskZLfoAmp = 0.0;
		fb0MaskRotateLfoTheta = 0;
		fb0MaskRotateLfoAmp = 0;
		fb0MaskTileAmountLfoTheta = 0.0;
		fb0MaskTileAmountLfoAmp = 0.0;
		fb0MaskTexmodOffsetLfoTheta = 0;
		fb0MaskTexmodOffsetLfoAmp = 0;
		fb0MaskTexmodQuantizeAmountLfoTheta = 0.0;
		fb0MaskTexmodQuantizeAmountLfoAmp = 0.0;
		fb0MaskTexmodQuantizeMixLfoTheta = 0.0;
		fb0MaskTexmodQuantizeMixLfoAmp = 0.0;

		 fb0HueOffsetLfoTheta = 0.0;
		 fb0SaturationOffsetLfoTheta = 0.0;
		 fb0BrightOffsetLfoTheta = 0.0;
		 fb0HueAttenuateLfoTheta = 0.0;
		 fb0SaturationAttenuateLfoTheta = 0.0;
		 fb0BrightAttenuateLfoTheta = 0.0;
		 fb0HueShaperLfoTheta = 0.0;
		 fb0HueQuantizeLfoTheta = 0;
		 fb0SaturationQuantizeLfoTheta = 0;
		 fb0BrightQuantizeLfoTheta = 0;
		 fb0HueQuantizeMixLfoTheta = 0.0;
		 fb0SaturationQuantizeMixLfoTheta = 0.0;
		 fb0BrightQuantizeMixLfoTheta = 0.0;
		 fb0HueDitherMixLfoTheta = 0.0;
		 fb0HueDitherAmountLfoTheta = 0;
		 fb0SaturationDitherMixLfoTheta = 0.0;
		 fb0SaturationDitherAmountLfoTheta = 0;
		 fb0BrightDitherMixLfoTheta = 0.0;
		 fb0BrightDitherAmountLfoTheta = 0;
		 fb0HuePowMapLfoTheta = 0;
		 fb0SaturationPowMapLfoTheta = .0;
		 fb0BrightPowMapLfoTheta = .0;

		 fb0HueOffsetLfoAmp = 0.0;
		 fb0SaturationOffsetLfoAmp = 0.0;
		 fb0BrightOffsetLfoAmp = 0.0;
		 fb0HueAttenuateLfoAmp = 0.0;
		 fb0SaturationAttenuateLfoAmp = 0.0;
		 fb0BrightAttenuateLfoAmp = 0.0;
		 fb0HueShaperLfoAmp = 0.0;
		 fb0HueQuantizeLfoAmp = 0;
		 fb0SaturationQuantizeLfoAmp = 0;
		 fb0BrightQuantizeLfoAmp = 0;
		 fb0HueQuantizeMixLfoAmp = 0.0;
		 fb0SaturationQuantizeMixLfoAmp = 0.0;
		 fb0BrightQuantizeMixLfoAmp = 0.0;
		 fb0HueDitherMixLfoAmp = 0.0;
		 fb0HueDitherAmountLfoAmp = 0;
		 fb0SaturationDitherMixLfoAmp = 0.0;
		 fb0SaturationDitherAmountLfoAmp = 0;
		 fb0BrightDitherMixLfoAmp = 0.0;
		 fb0BrightDitherAmountLfoAmp = 0;
		 fb0HuePowMapLfoAmp = 0;
		 fb0SaturationPowMapLfoAmp = .0;
		 fb0BrightPowMapLfoAmp = .0;

		 fb0XDisplaceLfoTheta = 0.0;
		 fb0YDisplaceLfoTheta = 0.0;
		 fb0ZDisplaceLfoTheta = 0.0;
		 fb0RotateLfoTheta = 0;
		 fb0ShearMatrixLfoTheta.set(0, 0, 0, 0);

		 fb0XDisplaceLfoAmp = 0.0;
		 fb0YDisplaceLfoAmp = 0.0;
		 fb0ZDisplaceLfoAmp = 0.0;
		 fb0RotateLfoAmp = 0;
		 fb0ShearMatrixLfoAmp.set(0, 0, 0, 0);

		 fb0FisheyeAmountLfoTheta = 0;
		 fb0FisheyeXLfoTheta = 0;
		 fb0FisheyeYLfoTheta = 0;
		 fb0SpiralAmountLfoTheta = 0;
		 fb0SpiralAngleLfoTheta = 0;
		 fb0SpiralXLfoTheta = 0;
		 fb0SpiralYLfoTheta = 0;
		 fb0KaleidoscopeSegmentsLfoTheta = 0;
		 fb0KaleidoscopeSliceLfoTheta = 0;

		 fb0FisheyeAmountLfoAmp = 0;
		 fb0FisheyeXLfoAmp = 0;
		 fb0FisheyeYLfoAmp = 0;
		 fb0SpiralAmountLfoAmp = 0;
		 fb0SpiralAngleLfoAmp = 0;
		 fb0SpiralXLfoAmp = 0;
		 fb0SpiralYLfoAmp = 0;
		 fb0KaleidoscopeSegmentsLfoAmp = 0;
		 fb0KaleidoscopeSliceLfoAmp = 0;

		 fb0XPixelScaleLfoTheta = 0;
		 fb0XPixelScaleLfoAmp = 0;
		 fb0YPixelScaleLfoTheta = 0;
		 fb0YPixelScaleLfoAmp = 0;
		 fb0PixelMixLfoTheta = 0;
		 fb0PixelMixLfoAmp = 0;
		 fb0PixelBrightscaleLfoTheta = 0;
		 fb0PixelBrightscaleLfoAmp = 0;
	}

	void GuiApp::fb0ResetAll() {
		fb0ResetAllParameters();
		fb0ResetAllLfo();

	}



//fb1 resets
void GuiApp::fb1ResetAllParameters() {
    fb1LumakeyLevel = 0;
    fb1KeyThreshold = 0;
    fb1ChromakeyRed = 0;
    fb1ChromakeyGreen = 0;
    fb1ChromakeyBlue = 0;
    fb1KeySoft = 0;
    fb1MaskX = 0;
    fb1MaskY = 0;
    fb1MaskZ = 1.0;
    fb1MaskRotate = 0;
    fb1MaskTileAmount = 1.0;
    fb1MaskTexmodOffset = 0;
    fb1MaskTexmodQuantizeAmount = 1.0;
    fb1MaskTexmodQuantizeMix = 1.0;
    fb1Mix = 0;
    fb1HueOffset = 0.0;
    fb1SaturationOffset = 0.0;
    fb1BrightOffset = 0.0;
    fb1HueAttenuate = 10.0;
    fb1SaturationAttenuate = 10.0;
    fb1BrightAttenuate = 10.0;
    fb1HueShaper = 0.0;
    fb1HuePowMap=1.0;
    fb1SaturationPowMap=1.0;
    fb1BrightPowMap=1.0;
    fb1HueInvert = 0;
    fb1SaturationInvert = 0;
    fb1BrightInvert = 0;
    
    fb1HueShaperRange = 0.25;
    fb1HueOffsetRange = .25;
    fb1SaturationOffsetRange = 0.25;
    fb1BrightOffsetRange = 0.25;
    fb1HueAttenuateRange = 2.0;
    fb1SaturationAttenuateRange = 2.0;
    fb1BrightAttenuateRange = 2.0;
    
    fb1HueInvert = 0;
    fb1SaturationInvert = 0;
    fb1BrightInvert = 0;
    
    fb1SaturationOverflow = 0;
    fb1BrightOverflow = 0;
    fb1HuePowMapRange = .25;
    fb1SaturationPowMapRange = .25;
    fb1BrightPowMapRange = .25;
    
    fb1HueQuantize = 128;
    fb1SaturationQuantize = 128;
    fb1BrightQuantize = 128;
    fb1HueQuantizeMix = 0.0;
    fb1SaturationQuantizeMix = 0.0;
    fb1BrightQuantizeMix = 0.0;
    fb1HueDitherMix = 0.0;
    fb1HueDitherAmount = 64;
    fb1SaturationDitherMix = 0.0;
    fb1SaturationDitherAmount = 64;
    fb1BrightDitherMix = 0.0;
    fb1BrightDitherAmount = 64;
    
    fb1_toroid_switch = 0;
    fb1XDisplace = 0.0;
    fb1YDisplace = 0.0;
    fb1ZDisplace = 100.0;
    fb1Rotate = 0;
    fb1ShearMatrix.set(0, 0, 0, 0);
    fb1ShearMatrixRange.set(0.25, 0.25, 0.25, 0.25);
    fb1RotateMode = 0;
    fb1HorizontalMirror = 0;
    fb1VerticalMirror = 0;
    fb1XDisplaceRange = 40;
    fb1YDisplaceRange = 40;
    fb1ZDisplaceRange = 10;
    fb1ZRotateRange = PI;
    
    fb1FisheyeAmount = 0;
    fb1FisheyeX = 0;
    fb1FisheyeY = 0;
    fb1SpiralAmount = 0;
    fb1SpiralAngle = 0;
    fb1SpiralX = 0;
    fb1SpiralY = 0;
    fb1KaleidoscopeSegments = 0;
    fb1KaleidoscopeSlice = 0;
    
    fb1FisheyeAmountRange = .15;
    fb1FisheyeXRange = .25;
    fb1FisheyeYRange = .25;
    fb1SpiralAmountRange = .15;
    fb1SpiralAngleRange = PI;
    fb1SpiralXRange = .25;
    fb1SpiralYRange = .25;
    fb1KaleidoscopeSegmentsRange = 21;
    fb1KaleidoscopeSliceRange = PI;
    
    fb1PixelXYLock = 1;
    fb1PixelSwitch = 0;
    fb1XPixelScale = 64;
    fb1YPixelScale = 64;
    fb1PixelMix = 1;
    fb1PixelBrightscale = 0;
    
    //texmods, dunno if we want these seperate or with everything
    //keep it easy to seperate for now
    fb1LumakeyLevelTexmod = 0.0;
    fb1ChromakeyRedTexmod = 0;
    fb1ChromakeyGreenTexmod = 0;
    fb1ChromakeyBlueTexmod = 0;
    fb1KeyThresholdTexmod = 0.0;
    fb1KeySoftTexmod = 0;
    fb1MixTexmod = .0;
    fb1MaskXTexmod = 0;
    fb1MaskYTexmod = 0;
    fb1MaskZTexmod = 0.0;
    fb1MaskRotateTexmod = 0;
    fb1MaskTileAmountTexmod = 0.0;
    
    fb1HueOffsetTexmod = 0.0;
    fb1SaturationOffsetTexmod = 0.0;
    fb1BrightOffsetTexmod = 0.0;
    fb1HueAttenuateTexmod = 0.0;
    fb1SaturationAttenuateTexmod = 0.0;
    fb1BrightAttenuateTexmod = 0.0;
    fb1HueShaperTexmod = 0.0;
    fb1HuePowMapTexmod = .0;
    fb1SaturationPowMapTexmod = .0;
    fb1BrightPowMapTexmod = .0;
    
    fb1HueQuantizeTexmod = 0;
    fb1SaturationQuantizeTexmod = 0;
    fb1BrightQuantizeTexmod = 0;
    fb1HueQuantizeMixTexmod = 0.0;
    fb1SaturationQuantizeMixTexmod = 0.0;
    fb1BrightQuantizeMixTexmod = 0.0;
    fb1HueDitherMixTexmod = 0.0;
    fb1HueDitherAmountTexmod = 0;
    fb1SaturationDitherMixTexmod = 0.0;
    fb1SaturationDitherAmountTexmod = 0;
    fb1BrightDitherMixTexmod = 0.0;
    fb1BrightDitherAmountTexmod = 0;
    
    fb1XDisplaceTexmod=0.0;
    fb1YDisplaceTexmod=0.0;
    fb1ZDisplaceTexmod=0;
    fb1RotateTexmod=0;
    fb1ShearMatrixTexmod.set(0,0,0,0);
    
    fb1FisheyeAmountTexmod = 0;
    fb1FisheyeXTexmod = 0;
    fb1FisheyeYTexmod = 0;
    fb1SpiralAmountTexmod = 0;
    fb1SpiralAngleTexmod = 0;
    fb1SpiralXTexmod = 0;
    fb1SpiralYTexmod = 0;
    fb1KaleidoscopeSegmentsTexmod = 0;
    fb1KaleidoscopeSliceTexmod = 0;
    
}
void GuiApp::fb1ResetAllLfo() {
    
    fb1_delay_lfo_theta = 0;
    fb1DelayLfoAmp = 0;
    fb1MixLfoTheta = 0;
    fb1MixLfoAmp = 0;
    fb1LumakeyLevelLfoTheta = 0;
    fb1LumakeyLevelLfoAmp = 0;
    fb1ChromakeyRedLfoTheta = 0;
    fb1ChromakeyRedLfoAmp = 0;
    fb1ChromakeyGreenLfoTheta = 0;
    fb1ChromakeyGreenLfoAmp = 0;
    fb1ChromakeyBlueLfoTheta = 0;
    fb1ChromakeyBlueLfoAmp = 0;
    fb1KeyThresholdLfoTheta = 0;
    fb1KeyThresholdLfoAmp = 0;
    fb1KeySoftLfoTheta = 0;
    fb1KeySoftLfoAmp = 0;
    fb1MaskXLfoTheta = 0;
    fb1MaskXLfoAmp = 0;
    fb1MaskYLfoTheta = 0;
    fb1MaskYLfoAmp = 0;
    fb1MaskZLfoTheta = 0.0;
    fb1MaskZLfoAmp = 0.0;
    fb1MaskRotateLfoTheta = 0;
    fb1MaskRotateLfoAmp = 0;
    fb1MaskTileAmountLfoTheta = 0.0;
    fb1MaskTileAmountLfoAmp = 0.0;
    fb1MaskTexmodOffsetLfoTheta = 0;
    fb1MaskTexmodOffsetLfoAmp = 0;
    fb1MaskTexmodQuantizeAmountLfoTheta = 0.0;
    fb1MaskTexmodQuantizeAmountLfoAmp = 0.0;
    fb1MaskTexmodQuantizeMixLfoTheta = 0.0;
    fb1MaskTexmodQuantizeMixLfoAmp = 0.0;
    
    fb1HueOffsetLfoTheta = 0.0;
    fb1SaturationOffsetLfoTheta = 0.0;
    fb1BrightOffsetLfoTheta = 0.0;
    fb1HueAttenuateLfoTheta = 0.0;
    fb1SaturationAttenuateLfoTheta = 0.0;
    fb1BrightAttenuateLfoTheta = 0.0;
    fb1HueShaperLfoTheta = 0.0;
    fb1HueQuantizeLfoTheta = 0;
    fb1SaturationQuantizeLfoTheta = 0;
    fb1BrightQuantizeLfoTheta = 0;
    fb1HueQuantizeMixLfoTheta = 0.0;
    fb1SaturationQuantizeMixLfoTheta = 0.0;
    fb1BrightQuantizeMixLfoTheta = 0.0;
    fb1HueDitherMixLfoTheta = 0.0;
    fb1HueDitherAmountLfoTheta = 0;
    fb1SaturationDitherMixLfoTheta = 0.0;
    fb1SaturationDitherAmountLfoTheta = 0;
    fb1BrightDitherMixLfoTheta = 0.0;
    fb1BrightDitherAmountLfoTheta = 0;
    fb1HuePowMapLfoTheta = 0;
    fb1SaturationPowMapLfoTheta = .0;
    fb1BrightPowMapLfoTheta = .0;
    
    fb1HueOffsetLfoAmp = 0.0;
    fb1SaturationOffsetLfoAmp = 0.0;
    fb1BrightOffsetLfoAmp = 0.0;
    fb1HueAttenuateLfoAmp = 0.0;
    fb1SaturationAttenuateLfoAmp = 0.0;
    fb1BrightAttenuateLfoAmp = 0.0;
    fb1HueShaperLfoAmp = 0.0;
    fb1HueQuantizeLfoAmp = 0;
    fb1SaturationQuantizeLfoAmp = 0;
    fb1BrightQuantizeLfoAmp = 0;
    fb1HueQuantizeMixLfoAmp = 0.0;
    fb1SaturationQuantizeMixLfoAmp = 0.0;
    fb1BrightQuantizeMixLfoAmp = 0.0;
    fb1HueDitherMixLfoAmp = 0.0;
    fb1HueDitherAmountLfoAmp = 0;
    fb1SaturationDitherMixLfoAmp = 0.0;
    fb1SaturationDitherAmountLfoAmp = 0;
    fb1BrightDitherMixLfoAmp = 0.0;
    fb1BrightDitherAmountLfoAmp = 0;
    fb1HuePowMapLfoAmp = 0;
    fb1SaturationPowMapLfoAmp = .0;
    fb1BrightPowMapLfoAmp = .0;
    
    fb1XDisplaceLfoTheta = 0.0;
    fb1YDisplaceLfoTheta = 0.0;
    fb1ZDisplaceLfoTheta = 0.0;
    fb1RotateLfoTheta = 0;
    fb1ShearMatrixLfoTheta.set(0, 0, 0, 0);
    
    fb1XDisplaceLfoAmp = 0.0;
    fb1YDisplaceLfoAmp = 0.0;
    fb1ZDisplaceLfoAmp = 0.0;
    fb1RotateLfoAmp = 0;
    fb1ShearMatrixLfoAmp.set(0, 0, 0, 0);
    
    fb1FisheyeAmountLfoTheta = 0;
    fb1FisheyeXLfoTheta = 0;
    fb1FisheyeYLfoTheta = 0;
    fb1SpiralAmountLfoTheta = 0;
    fb1SpiralAngleLfoTheta = 0;
    fb1SpiralXLfoTheta = 0;
    fb1SpiralYLfoTheta = 0;
    fb1KaleidoscopeSegmentsLfoTheta = 0;
    fb1KaleidoscopeSliceLfoTheta = 0;
    
    fb1FisheyeAmountLfoAmp = 0;
    fb1FisheyeXLfoAmp = 0;
    fb1FisheyeYLfoAmp = 0;
    fb1SpiralAmountLfoAmp = 0;
    fb1SpiralAngleLfoAmp = 0;
    fb1SpiralXLfoAmp = 0;
    fb1SpiralYLfoAmp = 0;
    fb1KaleidoscopeSegmentsLfoAmp = 0;
    fb1KaleidoscopeSliceLfoAmp = 0;
    
    fb1XPixelScaleLfoTheta = 0;
    fb1XPixelScaleLfoAmp = 0;
    fb1YPixelScaleLfoTheta = 0;
    fb1YPixelScaleLfoAmp = 0;
    fb1PixelMixLfoTheta = 0;
    fb1PixelMixLfoAmp = 0;
    fb1PixelBrightscaleLfoTheta = 0;
    fb1PixelBrightscaleLfoAmp = 0;
}

void GuiApp::fb1ResetAll() {
    fb1ResetAllParameters();
    fb1ResetAllLfo();
    
}





//fb2 resets
void GuiApp::fb2ResetAllParameters() {
    fb2LumakeyLevel = 0;
    fb2KeyThreshold = 0;
    fb2ChromakeyRed = 0;
    fb2ChromakeyGreen = 0;
    fb2ChromakeyBlue = 0;
    fb2KeySoft = 0;
    fb2MaskX = 0;
    fb2MaskY = 0;
    fb2MaskZ = 1.0;
    fb2MaskRotate = 0;
    fb2MaskTileAmount = 1.0;
    fb2MaskTexmodOffset = 0;
    fb2MaskTexmodQuantizeAmount = 1.0;
    fb2MaskTexmodQuantizeMix = 1.0;
    fb2Mix = 0;
    fb2HueOffset = 0.0;
    fb2SaturationOffset = 0.0;
    fb2BrightOffset = 0.0;
    fb2HueAttenuate = 10.0;
    fb2SaturationAttenuate = 10.0;
    fb2BrightAttenuate = 10.0;
    fb2HueShaper = 0.0;
    fb2HuePowMap=1.0;
    fb2SaturationPowMap=1.0;
    fb2BrightPowMap=1.0;
    fb2HueInvert = 0;
    fb2SaturationInvert = 0;
    fb2BrightInvert = 0;
    
    fb2HueShaperRange = 0.25;
    fb2HueOffsetRange = .25;
    fb2SaturationOffsetRange = 0.25;
    fb2BrightOffsetRange = 0.25;
    fb2HueAttenuateRange = 2.0;
    fb2SaturationAttenuateRange = 2.0;
    fb2BrightAttenuateRange = 2.0;
    
    fb2HueInvert = 0;
    fb2SaturationInvert = 0;
    fb2BrightInvert = 0;
    
    fb2SaturationOverflow = 0;
    fb2BrightOverflow = 0;
    fb2HuePowMapRange = .25;
    fb2SaturationPowMapRange = .25;
    fb2BrightPowMapRange = .25;
    
    fb2HueQuantize = 128;
    fb2SaturationQuantize = 128;
    fb2BrightQuantize = 128;
    fb2HueQuantizeMix = 0.0;
    fb2SaturationQuantizeMix = 0.0;
    fb2BrightQuantizeMix = 0.0;
    fb2HueDitherMix = 0.0;
    fb2HueDitherAmount = 64;
    fb2SaturationDitherMix = 0.0;
    fb2SaturationDitherAmount = 64;
    fb2BrightDitherMix = 0.0;
    fb2BrightDitherAmount = 64;
    
    fb2_toroid_switch = 0;
    fb2XDisplace = 0.0;
    fb2YDisplace = 0.0;
    fb2ZDisplace = 100.0;
    fb2Rotate = 0;
    fb2ShearMatrix.set(0, 0, 0, 0);
    fb2ShearMatrixRange.set(0.25, 0.25, 0.25, 0.25);
    fb2RotateMode = 0;
    fb2HorizontalMirror = 0;
    fb2VerticalMirror = 0;
    fb2XDisplaceRange = 40;
    fb2YDisplaceRange = 40;
    fb2ZDisplaceRange = 10;
    fb2ZRotateRange = PI;
    
    fb2FisheyeAmount = 0;
    fb2FisheyeX = 0;
    fb2FisheyeY = 0;
    fb2SpiralAmount = 0;
    fb2SpiralAngle = 0;
    fb2SpiralX = 0;
    fb2SpiralY = 0;
    fb2KaleidoscopeSegments = 0;
    fb2KaleidoscopeSlice = 0;
    
    fb2FisheyeAmountRange = .15;
    fb2FisheyeXRange = .25;
    fb2FisheyeYRange = .25;
    fb2SpiralAmountRange = .15;
    fb2SpiralAngleRange = PI;
    fb2SpiralXRange = .25;
    fb2SpiralYRange = .25;
    fb2KaleidoscopeSegmentsRange = 21;
    fb2KaleidoscopeSliceRange = PI;
    
    fb2PixelXYLock = 1;
    fb2PixelSwitch = 0;
    fb2XPixelScale = 64;
    fb2YPixelScale = 64;
    fb2PixelMix = 1;
    fb2PixelBrightscale = 0;
    
    //texmods, dunno if we want these seperate or with everything
    //keep it easy to seperate for now
    fb2LumakeyLevelTexmod = 0.0;
    fb2ChromakeyRedTexmod = 0;
    fb2ChromakeyGreenTexmod = 0;
    fb2ChromakeyBlueTexmod = 0;
    fb2KeyThresholdTexmod = 0.0;
    fb2KeySoftTexmod = 0;
    fb2MixTexmod = .0;
    fb2MaskXTexmod = 0;
    fb2MaskYTexmod = 0;
    fb2MaskZTexmod = 0.0;
    fb2MaskRotateTexmod = 0;
    fb2MaskTileAmountTexmod = 0.0;
    
    fb2HueOffsetTexmod = 0.0;
    fb2SaturationOffsetTexmod = 0.0;
    fb2BrightOffsetTexmod = 0.0;
    fb2HueAttenuateTexmod = 0.0;
    fb2SaturationAttenuateTexmod = 0.0;
    fb2BrightAttenuateTexmod = 0.0;
    fb2HueShaperTexmod = 0.0;
    fb2HuePowMapTexmod = .0;
    fb2SaturationPowMapTexmod = .0;
    fb2BrightPowMapTexmod = .0;
    
    fb2HueQuantizeTexmod = 0;
    fb2SaturationQuantizeTexmod = 0;
    fb2BrightQuantizeTexmod = 0;
    fb2HueQuantizeMixTexmod = 0.0;
    fb2SaturationQuantizeMixTexmod = 0.0;
    fb2BrightQuantizeMixTexmod = 0.0;
    fb2HueDitherMixTexmod = 0.0;
    fb2HueDitherAmountTexmod = 0;
    fb2SaturationDitherMixTexmod = 0.0;
    fb2SaturationDitherAmountTexmod = 0;
    fb2BrightDitherMixTexmod = 0.0;
    fb2BrightDitherAmountTexmod = 0;
    
    fb2XDisplaceTexmod=0.0;
    fb2YDisplaceTexmod=0.0;
    fb2ZDisplaceTexmod=0;
    fb2RotateTexmod=0;
    fb2ShearMatrixTexmod.set(0,0,0,0);
    
    fb2FisheyeAmountTexmod = 0;
    fb2FisheyeXTexmod = 0;
    fb2FisheyeYTexmod = 0;
    fb2SpiralAmountTexmod = 0;
    fb2SpiralAngleTexmod = 0;
    fb2SpiralXTexmod = 0;
    fb2SpiralYTexmod = 0;
    fb2KaleidoscopeSegmentsTexmod = 0;
    fb2KaleidoscopeSliceTexmod = 0;
    
}
void GuiApp::fb2ResetAllLfo() {
    
    fb2_delay_lfo_theta = 0;
    fb2DelayLfoAmp = 0;
    fb2MixLfoTheta = 0;
    fb2MixLfoAmp = 0;
    fb2LumakeyLevelLfoTheta = 0;
    fb2LumakeyLevelLfoAmp = 0;
    fb2ChromakeyRedLfoTheta = 0;
    fb2ChromakeyRedLfoAmp = 0;
    fb2ChromakeyGreenLfoTheta = 0;
    fb2ChromakeyGreenLfoAmp = 0;
    fb2ChromakeyBlueLfoTheta = 0;
    fb2ChromakeyBlueLfoAmp = 0;
    fb2KeyThresholdLfoTheta = 0;
    fb2KeyThresholdLfoAmp = 0;
    fb2KeySoftLfoTheta = 0;
    fb2KeySoftLfoAmp = 0;
    fb2MaskXLfoTheta = 0;
    fb2MaskXLfoAmp = 0;
    fb2MaskYLfoTheta = 0;
    fb2MaskYLfoAmp = 0;
    fb2MaskZLfoTheta = 0.0;
    fb2MaskZLfoAmp = 0.0;
    fb2MaskRotateLfoTheta = 0;
    fb2MaskRotateLfoAmp = 0;
    fb2MaskTileAmountLfoTheta = 0.0;
    fb2MaskTileAmountLfoAmp = 0.0;
    fb2MaskTexmodOffsetLfoTheta = 0;
    fb2MaskTexmodOffsetLfoAmp = 0;
    fb2MaskTexmodQuantizeAmountLfoTheta = 0.0;
    fb2MaskTexmodQuantizeAmountLfoAmp = 0.0;
    fb2MaskTexmodQuantizeMixLfoTheta = 0.0;
    fb2MaskTexmodQuantizeMixLfoAmp = 0.0;
    
    fb2HueOffsetLfoTheta = 0.0;
    fb2SaturationOffsetLfoTheta = 0.0;
    fb2BrightOffsetLfoTheta = 0.0;
    fb2HueAttenuateLfoTheta = 0.0;
    fb2SaturationAttenuateLfoTheta = 0.0;
    fb2BrightAttenuateLfoTheta = 0.0;
    fb2HueShaperLfoTheta = 0.0;
    fb2HueQuantizeLfoTheta = 0;
    fb2SaturationQuantizeLfoTheta = 0;
    fb2BrightQuantizeLfoTheta = 0;
    fb2HueQuantizeMixLfoTheta = 0.0;
    fb2SaturationQuantizeMixLfoTheta = 0.0;
    fb2BrightQuantizeMixLfoTheta = 0.0;
    fb2HueDitherMixLfoTheta = 0.0;
    fb2HueDitherAmountLfoTheta = 0;
    fb2SaturationDitherMixLfoTheta = 0.0;
    fb2SaturationDitherAmountLfoTheta = 0;
    fb2BrightDitherMixLfoTheta = 0.0;
    fb2BrightDitherAmountLfoTheta = 0;
    fb2HuePowMapLfoTheta = 0;
    fb2SaturationPowMapLfoTheta = .0;
    fb2BrightPowMapLfoTheta = .0;
    
    fb2HueOffsetLfoAmp = 0.0;
    fb2SaturationOffsetLfoAmp = 0.0;
    fb2BrightOffsetLfoAmp = 0.0;
    fb2HueAttenuateLfoAmp = 0.0;
    fb2SaturationAttenuateLfoAmp = 0.0;
    fb2BrightAttenuateLfoAmp = 0.0;
    fb2HueShaperLfoAmp = 0.0;
    fb2HueQuantizeLfoAmp = 0;
    fb2SaturationQuantizeLfoAmp = 0;
    fb2BrightQuantizeLfoAmp = 0;
    fb2HueQuantizeMixLfoAmp = 0.0;
    fb2SaturationQuantizeMixLfoAmp = 0.0;
    fb2BrightQuantizeMixLfoAmp = 0.0;
    fb2HueDitherMixLfoAmp = 0.0;
    fb2HueDitherAmountLfoAmp = 0;
    fb2SaturationDitherMixLfoAmp = 0.0;
    fb2SaturationDitherAmountLfoAmp = 0;
    fb2BrightDitherMixLfoAmp = 0.0;
    fb2BrightDitherAmountLfoAmp = 0;
    fb2HuePowMapLfoAmp = 0;
    fb2SaturationPowMapLfoAmp = .0;
    fb2BrightPowMapLfoAmp = .0;
    
    fb2XDisplaceLfoTheta = 0.0;
    fb2YDisplaceLfoTheta = 0.0;
    fb2ZDisplaceLfoTheta = 0.0;
    fb2RotateLfoTheta = 0;
    fb2ShearMatrixLfoTheta.set(0, 0, 0, 0);
    
    fb2XDisplaceLfoAmp = 0.0;
    fb2YDisplaceLfoAmp = 0.0;
    fb2ZDisplaceLfoAmp = 0.0;
    fb2RotateLfoAmp = 0;
    fb2ShearMatrixLfoAmp.set(0, 0, 0, 0);
    
    fb2FisheyeAmountLfoTheta = 0;
    fb2FisheyeXLfoTheta = 0;
    fb2FisheyeYLfoTheta = 0;
    fb2SpiralAmountLfoTheta = 0;
    fb2SpiralAngleLfoTheta = 0;
    fb2SpiralXLfoTheta = 0;
    fb2SpiralYLfoTheta = 0;
    fb2KaleidoscopeSegmentsLfoTheta = 0;
    fb2KaleidoscopeSliceLfoTheta = 0;
    
    fb2FisheyeAmountLfoAmp = 0;
    fb2FisheyeXLfoAmp = 0;
    fb2FisheyeYLfoAmp = 0;
    fb2SpiralAmountLfoAmp = 0;
    fb2SpiralAngleLfoAmp = 0;
    fb2SpiralXLfoAmp = 0;
    fb2SpiralYLfoAmp = 0;
    fb2KaleidoscopeSegmentsLfoAmp = 0;
    fb2KaleidoscopeSliceLfoAmp = 0;
    
    fb2XPixelScaleLfoTheta = 0;
    fb2XPixelScaleLfoAmp = 0;
    fb2YPixelScaleLfoTheta = 0;
    fb2YPixelScaleLfoAmp = 0;
    fb2PixelMixLfoTheta = 0;
    fb2PixelMixLfoAmp = 0;
    fb2PixelBrightscaleLfoTheta = 0;
    fb2PixelBrightscaleLfoAmp = 0;
}

void GuiApp::fb2ResetAll() {
    fb2ResetAllParameters();
    fb2ResetAllLfo();
    
}








//fb3 resets
void GuiApp::fb3ResetAllParameters() {
    fb3LumakeyLevel = 0;
    fb3KeyThreshold = 0;
    fb3ChromakeyRed = 0;
    fb3ChromakeyGreen = 0;
    fb3ChromakeyBlue = 0;
    fb3KeySoft = 0;
    fb3MaskX = 0;
    fb3MaskY = 0;
    fb3MaskZ = 1.0;
    fb3MaskRotate = 0;
    fb3MaskTileAmount = 1.0;
    fb3MaskTexmodOffset = 0;
    fb3MaskTexmodQuantizeAmount = 1.0;
    fb3MaskTexmodQuantizeMix = 1.0;
    fb3Mix = 0;
    fb3HueOffset = 0.0;
    fb3SaturationOffset = 0.0;
    fb3BrightOffset = 0.0;
    fb3HueAttenuate = 10.0;
    fb3SaturationAttenuate = 10.0;
    fb3BrightAttenuate = 10.0;
    fb3HueShaper = 0.0;
    fb3HuePowMap=1.0;
    fb3SaturationPowMap=1.0;
    fb3BrightPowMap=1.0;
    fb3HueInvert = 0;
    fb3SaturationInvert = 0;
    fb3BrightInvert = 0;
    
    fb3HueShaperRange = 0.25;
    fb3HueOffsetRange = .25;
    fb3SaturationOffsetRange = 0.25;
    fb3BrightOffsetRange = 0.25;
    fb3HueAttenuateRange = 2.0;
    fb3SaturationAttenuateRange = 2.0;
    fb3BrightAttenuateRange = 2.0;
    
    fb3HueInvert = 0;
    fb3SaturationInvert = 0;
    fb3BrightInvert = 0;
    
    fb3SaturationOverflow = 0;
    fb3BrightOverflow = 0;
    fb3HuePowMapRange = .25;
    fb3SaturationPowMapRange = .25;
    fb3BrightPowMapRange = .25;
    
    fb3HueQuantize = 128;
    fb3SaturationQuantize = 128;
    fb3BrightQuantize = 128;
    fb3HueQuantizeMix = 0.0;
    fb3SaturationQuantizeMix = 0.0;
    fb3BrightQuantizeMix = 0.0;
    fb3HueDitherMix = 0.0;
    fb3HueDitherAmount = 64;
    fb3SaturationDitherMix = 0.0;
    fb3SaturationDitherAmount = 64;
    fb3BrightDitherMix = 0.0;
    fb3BrightDitherAmount = 64;
    
    fb3_toroid_switch = 0;
    fb3XDisplace = 0.0;
    fb3YDisplace = 0.0;
    fb3ZDisplace = 100.0;
    fb3Rotate = 0;
    fb3ShearMatrix.set(0, 0, 0, 0);
    fb3ShearMatrixRange.set(0.25, 0.25, 0.25, 0.25);
    fb3RotateMode = 0;
    fb3HorizontalMirror = 0;
    fb3VerticalMirror = 0;
    fb3XDisplaceRange = 40;
    fb3YDisplaceRange = 40;
    fb3ZDisplaceRange = 10;
    fb3ZRotateRange = PI;
    
    fb3FisheyeAmount = 0;
    fb3FisheyeX = 0;
    fb3FisheyeY = 0;
    fb3SpiralAmount = 0;
    fb3SpiralAngle = 0;
    fb3SpiralX = 0;
    fb3SpiralY = 0;
    fb3KaleidoscopeSegments = 0;
    fb3KaleidoscopeSlice = 0;
    
    fb3FisheyeAmountRange = .15;
    fb3FisheyeXRange = .25;
    fb3FisheyeYRange = .25;
    fb3SpiralAmountRange = .15;
    fb3SpiralAngleRange = PI;
    fb3SpiralXRange = .25;
    fb3SpiralYRange = .25;
    fb3KaleidoscopeSegmentsRange = 21;
    fb3KaleidoscopeSliceRange = PI;
    
    fb3PixelXYLock = 1;
    fb3PixelSwitch = 0;
    fb3XPixelScale = 64;
    fb3YPixelScale = 64;
    fb3PixelMix = 1;
    fb3PixelBrightscale = 0;
    
    //texmods, dunno if we want these seperate or with everything
    //keep it easy to seperate for now
    fb3LumakeyLevelTexmod = 0.0;
    fb3ChromakeyRedTexmod = 0;
    fb3ChromakeyGreenTexmod = 0;
    fb3ChromakeyBlueTexmod = 0;
    fb3KeyThresholdTexmod = 0.0;
    fb3KeySoftTexmod = 0;
    fb3MixTexmod = .0;
    fb3MaskXTexmod = 0;
    fb3MaskYTexmod = 0;
    fb3MaskZTexmod = 0.0;
    fb3MaskRotateTexmod = 0;
    fb3MaskTileAmountTexmod = 0.0;
    
    fb3HueOffsetTexmod = 0.0;
    fb3SaturationOffsetTexmod = 0.0;
    fb3BrightOffsetTexmod = 0.0;
    fb3HueAttenuateTexmod = 0.0;
    fb3SaturationAttenuateTexmod = 0.0;
    fb3BrightAttenuateTexmod = 0.0;
    fb3HueShaperTexmod = 0.0;
    fb3HuePowMapTexmod = .0;
    fb3SaturationPowMapTexmod = .0;
    fb3BrightPowMapTexmod = .0;
    
    fb3HueQuantizeTexmod = 0;
    fb3SaturationQuantizeTexmod = 0;
    fb3BrightQuantizeTexmod = 0;
    fb3HueQuantizeMixTexmod = 0.0;
    fb3SaturationQuantizeMixTexmod = 0.0;
    fb3BrightQuantizeMixTexmod = 0.0;
    fb3HueDitherMixTexmod = 0.0;
    fb3HueDitherAmountTexmod = 0;
    fb3SaturationDitherMixTexmod = 0.0;
    fb3SaturationDitherAmountTexmod = 0;
    fb3BrightDitherMixTexmod = 0.0;
    fb3BrightDitherAmountTexmod = 0;
    
    fb3XDisplaceTexmod=0.0;
    fb3YDisplaceTexmod=0.0;
    fb3ZDisplaceTexmod=0;
    fb3RotateTexmod=0;
    fb3ShearMatrixTexmod.set(0,0,0,0);
    
    fb3FisheyeAmountTexmod = 0;
    fb3FisheyeXTexmod = 0;
    fb3FisheyeYTexmod = 0;
    fb3SpiralAmountTexmod = 0;
    fb3SpiralAngleTexmod = 0;
    fb3SpiralXTexmod = 0;
    fb3SpiralYTexmod = 0;
    fb3KaleidoscopeSegmentsTexmod = 0;
    fb3KaleidoscopeSliceTexmod = 0;
    
}
void GuiApp::fb3ResetAllLfo() {
    
    fb3_delay_lfo_theta = 0;
    fb3DelayLfoAmp = 0;
    fb3MixLfoTheta = 0;
    fb3MixLfoAmp = 0;
    fb3LumakeyLevelLfoTheta = 0;
    fb3LumakeyLevelLfoAmp = 0;
    fb3ChromakeyRedLfoTheta = 0;
    fb3ChromakeyRedLfoAmp = 0;
    fb3ChromakeyGreenLfoTheta = 0;
    fb3ChromakeyGreenLfoAmp = 0;
    fb3ChromakeyBlueLfoTheta = 0;
    fb3ChromakeyBlueLfoAmp = 0;
    fb3KeyThresholdLfoTheta = 0;
    fb3KeyThresholdLfoAmp = 0;
    fb3KeySoftLfoTheta = 0;
    fb3KeySoftLfoAmp = 0;
    fb3MaskXLfoTheta = 0;
    fb3MaskXLfoAmp = 0;
    fb3MaskYLfoTheta = 0;
    fb3MaskYLfoAmp = 0;
    fb3MaskZLfoTheta = 0.0;
    fb3MaskZLfoAmp = 0.0;
    fb3MaskRotateLfoTheta = 0;
    fb3MaskRotateLfoAmp = 0;
    fb3MaskTileAmountLfoTheta = 0.0;
    fb3MaskTileAmountLfoAmp = 0.0;
    fb3MaskTexmodOffsetLfoTheta = 0;
    fb3MaskTexmodOffsetLfoAmp = 0;
    fb3MaskTexmodQuantizeAmountLfoTheta = 0.0;
    fb3MaskTexmodQuantizeAmountLfoAmp = 0.0;
    fb3MaskTexmodQuantizeMixLfoTheta = 0.0;
    fb3MaskTexmodQuantizeMixLfoAmp = 0.0;
    
    fb3HueOffsetLfoTheta = 0.0;
    fb3SaturationOffsetLfoTheta = 0.0;
    fb3BrightOffsetLfoTheta = 0.0;
    fb3HueAttenuateLfoTheta = 0.0;
    fb3SaturationAttenuateLfoTheta = 0.0;
    fb3BrightAttenuateLfoTheta = 0.0;
    fb3HueShaperLfoTheta = 0.0;
    fb3HueQuantizeLfoTheta = 0;
    fb3SaturationQuantizeLfoTheta = 0;
    fb3BrightQuantizeLfoTheta = 0;
    fb3HueQuantizeMixLfoTheta = 0.0;
    fb3SaturationQuantizeMixLfoTheta = 0.0;
    fb3BrightQuantizeMixLfoTheta = 0.0;
    fb3HueDitherMixLfoTheta = 0.0;
    fb3HueDitherAmountLfoTheta = 0;
    fb3SaturationDitherMixLfoTheta = 0.0;
    fb3SaturationDitherAmountLfoTheta = 0;
    fb3BrightDitherMixLfoTheta = 0.0;
    fb3BrightDitherAmountLfoTheta = 0;
    fb3HuePowMapLfoTheta = 0;
    fb3SaturationPowMapLfoTheta = .0;
    fb3BrightPowMapLfoTheta = .0;
    
    fb3HueOffsetLfoAmp = 0.0;
    fb3SaturationOffsetLfoAmp = 0.0;
    fb3BrightOffsetLfoAmp = 0.0;
    fb3HueAttenuateLfoAmp = 0.0;
    fb3SaturationAttenuateLfoAmp = 0.0;
    fb3BrightAttenuateLfoAmp = 0.0;
    fb3HueShaperLfoAmp = 0.0;
    fb3HueQuantizeLfoAmp = 0;
    fb3SaturationQuantizeLfoAmp = 0;
    fb3BrightQuantizeLfoAmp = 0;
    fb3HueQuantizeMixLfoAmp = 0.0;
    fb3SaturationQuantizeMixLfoAmp = 0.0;
    fb3BrightQuantizeMixLfoAmp = 0.0;
    fb3HueDitherMixLfoAmp = 0.0;
    fb3HueDitherAmountLfoAmp = 0;
    fb3SaturationDitherMixLfoAmp = 0.0;
    fb3SaturationDitherAmountLfoAmp = 0;
    fb3BrightDitherMixLfoAmp = 0.0;
    fb3BrightDitherAmountLfoAmp = 0;
    fb3HuePowMapLfoAmp = 0;
    fb3SaturationPowMapLfoAmp = .0;
    fb3BrightPowMapLfoAmp = .0;
    
    fb3XDisplaceLfoTheta = 0.0;
    fb3YDisplaceLfoTheta = 0.0;
    fb3ZDisplaceLfoTheta = 0.0;
    fb3RotateLfoTheta = 0;
    fb3ShearMatrixLfoTheta.set(0, 0, 0, 0);
    
    fb3XDisplaceLfoAmp = 0.0;
    fb3YDisplaceLfoAmp = 0.0;
    fb3ZDisplaceLfoAmp = 0.0;
    fb3RotateLfoAmp = 0;
    fb3ShearMatrixLfoAmp.set(0, 0, 0, 0);
    
    fb3FisheyeAmountLfoTheta = 0;
    fb3FisheyeXLfoTheta = 0;
    fb3FisheyeYLfoTheta = 0;
    fb3SpiralAmountLfoTheta = 0;
    fb3SpiralAngleLfoTheta = 0;
    fb3SpiralXLfoTheta = 0;
    fb3SpiralYLfoTheta = 0;
    fb3KaleidoscopeSegmentsLfoTheta = 0;
    fb3KaleidoscopeSliceLfoTheta = 0;
    
    fb3FisheyeAmountLfoAmp = 0;
    fb3FisheyeXLfoAmp = 0;
    fb3FisheyeYLfoAmp = 0;
    fb3SpiralAmountLfoAmp = 0;
    fb3SpiralAngleLfoAmp = 0;
    fb3SpiralXLfoAmp = 0;
    fb3SpiralYLfoAmp = 0;
    fb3KaleidoscopeSegmentsLfoAmp = 0;
    fb3KaleidoscopeSliceLfoAmp = 0;
    
    fb3XPixelScaleLfoTheta = 0;
    fb3XPixelScaleLfoAmp = 0;
    fb3YPixelScaleLfoTheta = 0;
    fb3YPixelScaleLfoAmp = 0;
    fb3PixelMixLfoTheta = 0;
    fb3PixelMixLfoAmp = 0;
    fb3PixelBrightscaleLfoTheta = 0;
    fb3PixelBrightscaleLfoAmp = 0;
}

void GuiApp::fb3ResetAll() {
    fb3ResetAllParameters();
    fb3ResetAllLfo();
    
}
void GuiApp::globalResetAll() {
	globalResetAllParameters();
	globalResetAllLfo();
}
void GuiApp::globalResetAllParameters() {
	global_texmod_select = 0;
	global_texmod = false;
	control_reset = false;
	framebuffer_clear = false;
	blur_amount = 0.0;
	blur_radius = 1.0;
	sharpen_amount = 0.0;
	sharpen_radius = 1.0;
	sharpen_boost = 0.0;
	ndi_scale = 0;
	x_skew = 0;
	y_skew = 0;
	tetrahedron_switch = 0;
	hypercube_switch = 0;
	hypercube_theta_rate = 0.01;
	hypercube_phi_rate = 0.01;

	texmod_blur_amount = 0.0;
	texmod_blur_radius = 1.0;
	texmod_sharpen_amount = 0.0;
	texmod_sharpen_radius = 1.0;
	texmod_sharpen_boost = 0.0;
}
void GuiApp::globalResetAllLfo() {
	blur_amount_lfo_amp = 0.0;
	blur_amount_lfo_theta = 0.0;
	blur_radius_lfo_amp = 0.0;
	blur_radius_lfo_theta = 0.0;
	sharpen_amount_lfo_amp = 0.0;
	sharpen_amount_lfo_theta = 0.0;
	sharpen_radius_lfo_amp = 1.0;
	sharpen_radius_lfo_theta = 1.0;
	sharpen_boost_lfo_amp = 0.0;
	sharpen_boost_lfo_theta = 0.0;
}

//---------------------------




