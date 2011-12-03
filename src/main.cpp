#include "ofMain.h"
#include "arViewer.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
	int screenWidth, screenHeight;
	screenWidth = 1024;
	screenHeight = 768;
	
	
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
	std::cout << "Current Path: " << path << std::endl;
#endif
	// ----------------------------------------------------------------------------
	
	
    ofAppGlutWindow window;
	ofSetupOpenGL(&window, screenWidth,screenHeight, OF_WINDOW);			// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new arViewer(screenWidth, screenHeight));

}