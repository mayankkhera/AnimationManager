/***********************************************************************************
Filename: Frame.cpp
Version: 1
Student Name: Mayank Khera
Student Number: 040912734
Course: CST8219 - C++ Programming
Lab Section: 310
Assignment: Assignment 2
Due Date: November 11, 2019
Submission Date: November 11, 2019
Professor: Mohammad
Purpose: managing animations and frames through an animation manager by putting them
		 on a forward_list
************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
#include <forward_list>
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"

/***********************************************************************************
Function: Frame
Purpose: Initial Constructor
Parameters: char* name, double duration
Return: N/A
Verion: 1
Author: Mayank Khera
************************************************************************************/
Frame::Frame(char* name, double dur) {
	this->frameName = new char[256];
	strcpy(this->frameName, name);
	this->duration = duration;
}

/***********************************************************************************
Function: Frame
Purpose: Copy constructor
Parameters: const Frame&
Return: N/A
Verion: 1
Author: Mayank Khera
************************************************************************************/
Frame::Frame(const Frame& p) {
	this->frameName = new char[256];
	this->duration = p.duration;
	strcpy(this->frameName, p.frameName);
}

/***********************************************************************************
Function: operator=
Purpose: Copies a frame into the class and returns it
Parameters: const Frame&
Return: Frame&
Verion: 1
Author: Mayank Khera
************************************************************************************/
Frame& Frame::operator=(const Frame& frame) {
	this->frameName = new char[256];
	strcpy(this->frameName, frame.frameName);
	this->duration = frame.duration;
	return *this;
}

/***********************************************************************************
Function: operator<<
Purpose: overload the << operator to send out data from the frame
Parameters: ostream&, Frame&
Return: osream&
Verion: 1
Author: Mayank Khera
************************************************************************************/
ostream& operator<<(ostream& out, Frame& frame) {
	out << "\tFrame name = " << frame.frameName << "; duration = " << frame.duration;
	return out;
}

/***********************************************************************************
Function: ~Frame
Purpose: Destructor
Parameters: N/A
Return: N/A
Verion: 1
Author: Mayank Khera
************************************************************************************/
Frame::~Frame() {
	delete(this->frameName);
}