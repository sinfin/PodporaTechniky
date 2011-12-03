// Computer Vision
#include "ofxOpenCv.h"
#include "ofxARToolkitPlus.h"
#include "ofxFBOTexture.h"
#include "ofxShader.h"

#include "arMedia.h"
#include "library.h"

// Main
//#include "ofMain.h"

// Uncomment this to use a camera instead of a video file
#define CAMERA_CONNECTED

class arViewer : public ofBaseApp{
	
public:
	
	arViewer(int screenWidth=640, int screenHeight=480);
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

private:
	void glOff();///
	void glOn();///

//---
	
	/* Size of the image */
	int width, height;
	
	/* Use either camera or a video file */
#ifdef CAMERA_CONNECTED
	ofVideoGrabber vidGrabber;
#else
	ofVideoPlayer vidPlayer;
#endif
	
	/* ARToolKitPlus class */	
	ofxARToolkitPlus artk;	
	int threshold;
	
	/* OpenCV images */
	ofxCvColorImage colorImage;
	ofxCvGrayscaleImage grayImage;
	ofxCvGrayscaleImage	grayThres;
	
	/* modely */
	arMedia * fs;
	//arMedia * test;	///
	
	ofSoundPlayer my_sound; ///
};
