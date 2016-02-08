/*
 * state.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: eecs162
 */
#include <iostream>
#include <cstring>
#include "state.h"

using namespace std;

void state::set_name(const char *n) {
	//cout << "set name start" << endl;
	//cout << n[0] << ", " << n[1] << endl;
	name = new char[strlen(n) + 1]; //added this line
	strcpy(name, n);
	//cout << "set name end" << endl;
}

void state::set_pop(int n){
    this->pop=n;
}

void state::display_pop() {
	cout << "state, " << name << ", pop: " << pop << endl;
}

state::state() {
	pop=0;
	name=NULL;
}

state::~state() {

}

