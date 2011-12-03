/*
 *  arMarkerFunctions.cpp
 *  SinfinAR
 *
 *  Copyright 2011 Sinfin. All rights reserved.
 *
 */


///void marker(){}
		/* Marker 281 - LOGO */	///
/*
		artk.applyProjectionMatrix();
		machineIndex = artk.getMarkerIndex(281);
		if(machineIndex >= 0) {
			
			glEnable (GL_DEPTH_TEST);
			glShadeModel (GL_SMOOTH);
			
			
			/* initialize lighting */
/*			glLightfv (GL_LIGHT0, GL_AMBIENT, lightOneColor);
			glEnable (GL_LIGHT0);
			
			glEnable (GL_LIGHTING);
			glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT);
			glEnable (GL_COLOR_MATERIAL);
			
			artk.applyModelMatrix(machineIndex);
			glPushMatrix();
			ofSetColor(255, 255, 255);
			
			ofTranslate(0,0,40);
			ofRotate(180);	//upsidedown
			glRotated(180, 0, 1, 0);	//mirror
			cvutLogo.draw(-125, -125, spriteSize, spriteSize);	//posun obr. x,y
			
			glPopMatrix();
			
			
			glDisable(GL_LIGHT0);
			glDisable (GL_LIGHTING);
			glDisable (GL_COLOR_MATERIAL);
			
			glDisable(GL_DEPTH_TEST);
			
			ofBackground(255,255,255);
		}
		
		/* Marker 343 - Skladacka stroj */
/*		artk.applyProjectionMatrix();
		machineIndex = artk.getMarkerIndex(343);
		if(machineIndex >= 0) {
		
			glEnable (GL_DEPTH_TEST);
			glShadeModel (GL_SMOOTH);
			
			
			/* initialize lighting */
			//glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
/*			glLightfv (GL_LIGHT0, GL_AMBIENT, lightOneColor);
			glEnable (GL_LIGHT0);
			
	//		glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
	//		glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
	//		glEnable (GL_LIGHT1);
	//		
	//		glLightfv (GL_LIGHT2, GL_POSITION, lightThreePosition);
	//		glLightfv (GL_LIGHT2, GL_DIFFUSE, lightThreeColor);
	//		glEnable (GL_LIGHT2);
			
			glEnable (GL_LIGHTING);
			glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT);
			glEnable (GL_COLOR_MATERIAL);
			
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
			
		
			glDisable(GL_LIGHT0);
	//		glDisable (GL_LIGHT1);
	//		glDisable (GL_LIGHT2);
			glDisable (GL_LIGHTING);
			glDisable (GL_COLOR_MATERIAL);
			
			glDisable(GL_DEPTH_TEST);
	//		
			
			ofBackground(255,255,255);
		}
		
		/* Marker 344 - Skladacka budova */
/*		artk.applyProjectionMatrix();
		int buildingIndex = artk.getMarkerIndex(344);
		if(buildingIndex >= 0) {
			
			glEnable (GL_DEPTH_TEST);
			glShadeModel (GL_SMOOTH);
			
			
			/* initialize lighting */
			//glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
/*			glLightfv (GL_LIGHT0, GL_AMBIENT, lightOneColor);
			glEnable (GL_LIGHT0);
			
			//		glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
			//		glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
			//		glEnable (GL_LIGHT1);
			//		
			//		glLightfv (GL_LIGHT2, GL_POSITION, lightThreePosition);
			//		glLightfv (GL_LIGHT2, GL_DIFFUSE, lightThreeColor);
			//		glEnable (GL_LIGHT2);
			
			glEnable (GL_LIGHTING);
			glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT);
			glEnable (GL_COLOR_MATERIAL);
			
			artk.applyModelMatrix(buildingIndex);
			glPushMatrix();
			ofSetColor(255, 255, 255);

			fs->objectModel.draw();
			glPopMatrix();
			glTranslatef(-360,-240,0);
			
			
			glDisable(GL_LIGHT0);
			//		glDisable (GL_LIGHT1);
			//		glDisable (GL_LIGHT2);
			glDisable (GL_LIGHTING);
			glDisable (GL_COLOR_MATERIAL);
			
			glDisable(GL_DEPTH_TEST);
			//		
			
			ofBackground(255,255,255);
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
				printf("ID: %d\n", artk.getMarkerId(i));
			}
		}
		
*/