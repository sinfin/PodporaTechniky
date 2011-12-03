#include "arMedia.h"

arMedia::arMedia(int set_markerId, string set_filepath, string set_title){
	markerId = set_markerId;
	
	title = set_title;
	filepath = set_filepath;
	objectModel.loadModel(filepath, 1);
	
	scaleX = 1.0; scaleY = 1.0; scaleZ = 1.0;
	positionX = 0.0; positionY = 0.0; positionZ = 0.0;
	rotationX = 0.0; rotationY = 0.0; rotationZ = 0.0;
}

void arMedia::set_size(float set_scaleX, float set_scaleY, float set_scaleZ){
	scaleX = set_scaleX; scaleY = set_scaleY; scaleZ = set_scaleZ;
	objectModel.setScale(scaleX,scaleY,scaleZ);
}

void arMedia::set_position(float set_positionX, float set_positionY, float set_positionZ){
	positionX = set_positionX; positionY = set_positionY; positionZ = set_positionZ;
	objectModel.setPosition(positionX,positionY,positionZ);
}

void arMedia::set_rotation(float set_rotationX, float set_rotationY, float set_rotationZ){
	rotationX = set_rotationX; rotationY = set_rotationY; rotationZ = set_rotationZ;
	if (set_rotationX > 0) objectModel.setRotation(0, rotationX, 1, 0, 0);
	if (set_rotationY > 0) objectModel.setRotation(0, rotationY, 0, 1, 0);
	if (set_rotationZ > 0) objectModel.setRotation(0, rotationZ, 0, 0, 1);
}

