#include "ofx3DModelLoader.h"
#include <string>

class arMedia{
	std::string title;
	std::string filepath;

	
	float positionX, positionY, positionZ;
	float rotationX, rotationY, rotationZ;
	float scaleX, scaleY, scaleZ;
	
	int markerId;
	
	public:
	ofx3DModelLoader objectModel;

	arMedia(int set_markerId, string set_filepath, string set_title="");
	void set_size(float set_scaleX, float set_scaleY, float set_scaleZ);
	void set_position(float set_positionX, float set_positionY, float set_positionZ);
	void set_rotation(float set_rotationX, float set_rotationY, float set_rotationZ);
};