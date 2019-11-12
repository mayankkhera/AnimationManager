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
#include <stdlib.h>
#include <forward_list>
#include <vector>
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"
using namespace std;

/***********************************************************************************
Function: EditAnimation
Purpose: opens up a follow up menu to add, delete, and edit frames
Parameters: N/A
Return: void
Verion: 1
Author: Mayank Khera
************************************************************************************/
void AnimationManager::EditAnimation() {
	while (getchar() != '\n');
	int aniIndex;
	cout << "Which animation would you like to edit? Please give an index from 0 to " << this->animations.size() - 1 << endl;
	cin >> aniIndex;
	cout << "Editing Animation #" << aniIndex << endl;
	char choice;
	bool quit = false;
	while (!quit) {
		cout << "MENU\n\t1. Insert a frame\n\t2. Delete a framen\n\t3. Edit a frame\n\t4. QUIT" << endl;
		cin >> choice;

		switch (choice) {
		case '1':
			cin >> this->animations.at(aniIndex);
			break;
		case '2':
			this->animations.at(aniIndex).DeleteFrame();
			break;
		case '3':
			this->animations.at(aniIndex).EditFrame();
			break;
		case '4':
			quit = true;
			cout << "Animation #" << aniIndex << " edit complete" << endl;
			break;
		default:
			cout << "Please enter a valid option" << endl;
		}
	}
}

/***********************************************************************************
Function: DeleteAnimation
Purpose: Deletes animation from the animations vector at a given index
Parameters: N/A
Return: void
Verion: 1
Author: Mayank Khera
************************************************************************************/
void AnimationManager::DeleteAnimation() {
	int index = 0;
	
	while (1) {
		cout << "Delete an animation manager\nWhich animation do you wish to delete? Please enter an index from 0 to " << animations.size() - 1 << endl;

		if ((cin >> index) && getchar() == '\n') {

			if (index > -1 && index < (this->animations.size()))
				break;
			else
				cout << "Invalid index value" << endl;
		}
		else {
			cin.clear();

			while (getchar() != '\n');
			cout << "Invalid index" << endl;
		}
	}
	this->animations.erase(this->animations.begin() + index);
	cout << "Animation #" << index << " has been deleted" << endl;
}

/***********************************************************************************
Function: operator>>
Purpose: overloading >> to input Animation fields
Parameters: istream& , AnimationManager&
Return: istream&
Verion: 1
Author: Mayank Khera
************************************************************************************/
istream& operator>>(istream& os, AnimationManager& am) {

	char animationName[256];
	cout << "Add an animation to the animation manager\nPlease enter an Animation name: " << endl;
	os >> animationName;

	Animation* ani = new Animation(animationName);
	am.animations.push_back(*ani);

	cout << "Animation " << animationName << " added at the front of animations" << endl;
	return os;

}

/***********************************************************************************
Function: operator<<
Purpose: overloading the operator << to send out data from the animation
Parameters: ostream&, AnimationManager&
Return: ostream&
Verion: 1
Author: Mayank Khera
************************************************************************************/
ostream& operator<<(ostream& os, AnimationManager& am) {
	int i = 0;
	os << "AnimationManager: " << am.managerName << endl;
	if (!am.animations.empty()) {
		vector<Animation>::iterator iterator;
		for (iterator = am.animations.begin(); iterator != am.animations.end(); iterator++, i++) {
			os << "Animation: " << i << endl;
			os << "\tAnimation name is " << *iterator << endl;
		}
	}
	else
		os << " there is no animations on the animation manager" << endl;
	return os;
}