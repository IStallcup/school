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
	delete [] name;
	name=new char[strlen(n)+1];
	strcpy(name, n);
}

void state::display_name() {
	cout << "State is: " << name << endl;
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

state::state(const state &orig) //added copy constructor b/c dynamic memory
{
	pop = orig.pop;
	name = new char[strlen(orig.name) + 1];
	strcpy(name, orig.name);
}

state::~state() {

}
