#include "arViewer.h"

// Svetlo pro 3D
GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightThreePosition[] = {0, -40, 100.0, 0.0};
GLfloat lightThreeColor[] = {0.99, 0.99, 0.99, 1.0};

ofImage tutorialImage, headerImage, cvutImage, cvutLogo;	///

ofImage sprites[24];
int spritesSize = 24;
int spriteCurrent;
int spriteSize = 250;

// Pouzite markery ve verzi 1.0
int used_markers_size = 4;						//#
int used_markers[] = { 280, 281, 343, 344 };	//test, logo_cvut, random_obr, budova

//--------------------------------------------------------------

arViewer::arViewer(int screenWidth, int screenHeight){
	width = screenWidth;
	height = screenHeight;
}

void arViewer::setup(){
		
#ifdef __APPLE__
#include "CoreFoundation/CoreFoundation.h"
#endif
	
	// ----------------------------------------------------------------------------
	// This makes relative paths work in C++ in Xcode by changing directory to the Resources folder inside the .app bundle
#ifdef __APPLE__    
	CFBundleRef mainBundle = CFBundleGetMainBundle();
	CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
	char path[PATH_MAX];
	if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
	{
		// error!
	}
	CFRelease(resourcesURL);
	
	chdir(path);
//	std::cout << "Current Path: " << path << std::endl;
	stringstream data_path;
	data_path << "../Resources/data/"; //"." << path << "/";
	ofSetDataPathRoot(data_path.str());
#endif
	// ----------------------------------------------------------------------------
	
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(width, height);
	
	
	// ART
	colorImage.allocate(width, height);
	grayImage.allocate(width, height);
	grayThres.allocate(width, height);
	
	// This uses the default camera calibration and marker file
	artk.setup(width, height);
	threshold = 85;
	artk.setThreshold(threshold);
	artk.activateAutoThreshold(true);

///dat do pola
	fs = new arMedia(344, "budova_cvut/cvut.3ds", "ČVUT, Fakulta strojní");
	fs->set_size(0.001, 0.001, 0.001);
	fs->set_position(20, 70, 40);
	fs->set_rotation(90, 0, 0);
	fs->set_rotation(0, 0, 0);
/**
	test = new arMedia(280, "dae/astroBoy_walk.dae", "test"); ///
	test->set_size(10, 10, 10);
	test->set_position(20, 70, 40);
	test->set_rotation(90, 0, 0);
	test->set_rotation(0, 0, 0);
/**/
	
/***
	//load the model 
	std::string filenameBall = ofToDataPath("ball1.dae");
    modelBall.loadModel(filenameBall, 20);
	
    //you can create as many rotations as you want
    //choose which axis you want it to effect
    //you can update these rotations later on
    //model.setRotation(0, 90, 1, 0, 0);
    //model.setRotation(1, 270, 0, 0, 1);
    modelBall.setScale(10, 10, 10);
    modelBall.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
	
/***/
	
	ofBackground(255,255,255);
	
	// 3D stuff
	
	ofSetVerticalSync(true);
	ofBackground(255,255,255);
	
	
	/* Obrazky pro rub skladacky */
	stringstream nameBuilder;
	for (unsigned i = 0; i < spritesSize-1; i++){
		nameBuilder << "skladacka/sprite-" << i << ".png";
		sprites[i].loadImage(nameBuilder.str());
		nameBuilder.str("");
	}
	
	spriteCurrent = ofRandom(0, spritesSize);
	
	tutorialImage.loadImage("tutorial.jpeg");
	headerImage.loadImage("header.png");
	cvutImage.loadImage("cvut_header.png");
	cvutLogo.loadImage("cvut-lev.png");			//Obr LOGO CVUT ///
}

//--------------------------------------------------------------
void arViewer::update(){
	
	
#ifdef CAMERA_CONNECTED
	vidGrabber.grabFrame();
	bool bNewFrame = vidGrabber.isFrameNew();
#else
	vidPlayer.idleMovie();
	bool bNewFrame = vidPlayer.isFrameNew();
#endif
	
	
	if(bNewFrame) {
		
#ifdef CAMERA_CONNECTED
		colorImage.setFromPixels(vidGrabber.getPixels(), width, height);
		//colorImage.mirror(false, true);
#else
		colorImage.setFromPixels(vidPlayer.getPixels(), width, height);
#endif
		
		// convert our camera image to grayscale
		grayImage = colorImage;
		// apply a threshold so we can see what is going on
		grayThres = grayImage;
		grayThres.threshold(threshold);
		// Pass in the new image pixels to artk
		artk.update(grayImage.getPixels());
	}
	
}

//--------------------------------------------------------------
void arViewer::draw(){
	
	//uvodni obrazovka
	if( ofGetElapsedTimef() < 7.0 ){
		ofBackground(234,234,234);
		ofSetColor(0xffffff);	
		cvutImage.draw(0,0);
		headerImage.draw(100,80);
		tutorialImage.draw(100, 250, 799, 267);
		ofSetColor(0x000000);	
		ofDrawBitmapString("v 1.0", 5, 760);
		ofDrawBitmapString("/* Sinfin.cz */", 900, 760);
	//video&model
	}else{
		//Main image
		//grayThres.draw(0, 0);
		colorImage.draw(0, 0);
	
		ofSetColor(0x888888);	
		ofDrawBitmapString("v 1.0", 5, 760);
		ofDrawBitmapString("/* Sinfin.cz */", 900, 760);
		//ofSetColor(0xffffff);
			
		// ARTK draw
		// An easy was to see what is going on
		// Draws the marker location and id number
		//artk.draw(0, 0);

		int machineIndex = -1;	///

		//cyklus->vlakna
		
		/* Marker 280 - TEST DAE */
		artk.applyProjectionMatrix();
		int buildingIndex = artk.getMarkerIndex(280);
		if(buildingIndex >= 0) {

			glOn();///
			
			artk.applyModelMatrix(buildingIndex);
			glPushMatrix();
			ofSetColor(255, 255, 255);
			
//			test->objectModel.draw();		//////////objectmodel - len 3ds //////opravit
//			modelBall.draw();
			glPopMatrix();
			glTranslatef(-360,-240,0);
			
			glOff();///
		}
		
		/* Marker 281 - LOGO */	///
		artk.applyProjectionMatrix();
		machineIndex = artk.getMarkerIndex(281);
		if(machineIndex >= 0) {
			
			
			ofSoundStopAll();					//vyp. zvuky	///
			my_sound.loadSound("b-b-1.mp3");	///
			my_sound.play();					///
			//my_sound.setLoop(true); 
			
			glOn();///

			artk.applyModelMatrix(machineIndex);
			glPushMatrix();
			ofSetColor(255, 255, 255);
			
			ofTranslate(0,0,40);
			ofRotate(180);										//upsidedown
			glRotated(180, 0, 1, 0);							//mirror
			cvutLogo.draw(-125, -125, spriteSize, spriteSize);	//posun obr. x,y
			
			glPopMatrix();
			
			glOff();///
		}
		
		/* Marker 343 - Skladacka stroj */
		artk.applyProjectionMatrix();
		machineIndex = artk.getMarkerIndex(343);
		if(machineIndex >= 0) {
		
			ofSoundStopAll();	//vyp zvuky	///
			my_sound.loadSound("chain-saw-2.mp3");	///
			my_sound.play();	///
			//my_sound.setLoop(true); 

			glOn();///

			artk.applyModelMatrix(machineIndex);
			glPushMatrix();
			ofSetColor(255, 255, 255);
			
			ofTranslate(0,-0,40);
			ofRotate(180);
			if( int(ofGetElapsedTimef())%5 == 0 ){
				spriteCurrent = ofRandom(0, spritesSize);
				spriteSize = ofRandom(250, 450);
			}
			sprites[spriteCurrent].draw(-75, -280, spriteSize, spriteSize);
			
			glPopMatrix();
			
		
			glOff();///
		}
		
		/* Marker 344 - Skladacka budova */
		artk.applyProjectionMatrix();
		buildingIndex = artk.getMarkerIndex(344);	///
		if(buildingIndex >= 0) {
			
			glOn();///
			
			artk.applyModelMatrix(buildingIndex);
			glPushMatrix();
			ofSetColor(255, 255, 255);

			fs->objectModel.draw();
			glPopMatrix();
			glTranslatef(-360,-240,0);
			
			
			glOff();///
		}
		
		// Ostatni
		artk.applyProjectionMatrix();
		int numDetected = artk.getNumDetectedMarkers();
		for(int i=0; i<numDetected; i++) {
			artk.applyModelMatrix(i);	
			ofSetColor(255, 255, 0, 50);
			if(!existsInArray(used_markers, used_markers_size, artk.getMarkerId(i))){
				ofFill();
				ofSetColor(255, 255, 0, 50);	
				ofRect(-25, -25, 50, 50);
				
				ofSetColor(255,0,0);
				ofDrawBitmapString("Stahnete aktualni verzi: http://www.podpora-techniky.cz/ar", 0,0);
				printf("ID: %d\n", artk.getMarkerId(i));	///
			}
		}
		
		ofSetColor(255, 255, 255, 255);	
	}
}

//--------------------------------------------------------------
void arViewer::keyPressed(int key){
	if(key == OF_KEY_UP) {
		artk.setThreshold(++threshold);
		
	} else if(key == OF_KEY_DOWN) {
		artk.setThreshold(--threshold);		
	}
#ifdef CAMERA_CONNECTED
	if(key == 's') {
		vidGrabber.videoSettings();
	}
#endif
}

//--------------------------------------------------------------
void arViewer::keyReleased(int key){
	
}

//--------------------------------------------------------------
void arViewer::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void arViewer::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void arViewer::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void arViewer::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void arViewer::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void arViewer::glOff(){
	glDisable(GL_LIGHT0);
//	glDisable (GL_LIGHT1);
//	glDisable (GL_LIGHT2);
	glDisable (GL_LIGHTING);
	glDisable (GL_COLOR_MATERIAL);
	
	glDisable(GL_DEPTH_TEST);
	
	ofBackground(255,255,255);	
}

//--------------------------------------------------------------
void arViewer::glOn(){
	glEnable (GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
	
	/* initialize lighting */
	
	//glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
	glLightfv (GL_LIGHT0, GL_AMBIENT, lightOneColor);
	glEnable (GL_LIGHT0);
	
	//glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
	//glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
	//glEnable (GL_LIGHT1);
	//		
	//glLightfv (GL_LIGHT2, GL_POSITION, lightThreePosition);
	//glLightfv (GL_LIGHT2, GL_DIFFUSE, lightThreeColor);
	//glEnable (GL_LIGHT2);
	
	glEnable (GL_LIGHTING);
	glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT);
	glEnable (GL_COLOR_MATERIAL);
}

//--------------------------------------------------------------