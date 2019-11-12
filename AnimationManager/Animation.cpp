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
#include <iostream>
#include <stdlib.h>
#include <forward_list>
#include <vector>
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"
using namespace std;

/***********************************************************************************
Function: EditFrame
Purpose: edits the frame by prompting user for new data for the frame
Parameters: N/A
Return: void
Verion: 1
Author: Mayank Khera
************************************************************************************/
void Animation::EditFrame() {
	forward_list<Frame>::iterator pf;
	forward_list<Frame> pFrame;
	int nodes;
	int index;
	char newName[256];
	int newDuration;

	pf = this->frames.begin();
	pFrame = this->frames;

	nodes = (int)distance(pFrame.begin(), pFrame.end());
	cout << "Edit a Frame in the Animation" << endl;
	
	if (pFrame.empty()) {
		cout << "There are no Frames in the list." << endl;
		return;
	}

	while (1) {
		cout << "There are " << nodes << " Frame(s) in the list. Please enter an index (<=" << nodes - 1 << "): ";
		if ((cin >> index) && getchar() == '\n') {

			if (index > -1 && index < nodes)
				break;
			else
				cout << "Invalid index" << endl;

		}
		else {
			cin.clear();

			while (getchar() != '\n');
			cout << "Invalid index" << endl;
		}
	}

	for (int i = 0; i < index; i++, pf++);

	bool done = false;

	while (!done) {
		cout << "The name of this Frame is \n" << *pf << "\nWhat do you wish to replace it with? ";
		cin >> newName;

		if (getchar() == '\n') {

			if (newName != nullptr) {

				cout << " and wha duration for this frame? " << endl;
				cin >> newDuration;

				*pf = Frame(newName, newDuration);
				done = true;
				cout << "Frame #" << index << "Edit complete" << endl;

			}
			else {
				cout << "Invalid frame name" << endl;
				while (getchar() != '\n');
			}
		}
	}

}

/***********************************************************************************
Function: DeleteFrame
Purpose: Deletes frame at the beginning of the frames
Parameters: N/A
Return: void
Verion: 1
Author: Mayank Khera
************************************************************************************/
void Animation::DeleteFrame() {
	this->frames.pop_front();

	cout << "First Frame deleted" << endl;
}

/***********************************************************************************
Function: operator>>
Purpose: overloads the >> operator to read data into frame
Parameters: istream&, Animation&
Return: istream&
Verion: 1
Author: Mayank Khera
************************************************************************************/
istream& operator>>(istream& os, Animation& am) {
	int duration = 0;
	char fName[256] = { 0 };
	cout << "Please enter frame name: ";
	os >> fName;
	cout << "Please enter the frame duration: ";
	os >> duration;
	am.frames.push_front(Frame(fName, duration));
	cout << "Frame " << fName << " added at the front of frames" << endl;
	return os;
}

/***********************************************************************************
Function: Frame
Purpose: Initial Constructors
Parameters: char* name, double duration
Return: N/A
Verion: 1
Author: Mayank Khera
************************************************************************************/
ostream& operator<<(ostream& os, Animation& am) {

	int counter = 0;

	os << am.animationName << "\n\tReport the Animation" << endl;
	if (am.frames.empty())
		os << "\tthere are no frames in the animation" << endl;
	else {
		forward_list<Frame>::iterator i;
		for (i = am.frames.begin(); i != am.frames.end(); i++) {
			os << "Frame" << counter++ << ": " << *i << endl;
		}
	}

	return os;
}