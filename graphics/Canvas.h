/*
   Canvas.h
   Steven G. Leal		November 23, 2014
   Ryan Meyers
   Sahil Dhanju
*/

//
// Implementation of Canvas class and circuit vector.
//

#ifndef CANVAS
#define CANVAS

#include "GUI.h"

using namespace std;

class Canvas : public Fl_Widget{
	GUI* gui;
	vector<Gate*> gates;
	Fl_Scroll* parent;
	Truth_Table* table;
	bool accepted;
public:
    Canvas(int X, int Y, int W, int H, Fl_Scroll* sc, const char*L=0);
	void add_gate(int gate, Gate* input1, Gate* input2);
	void add_gate(int gate, Gate* input);
	void add_gate(int gate);
	Fl_Scroll* Parent() {return parent;}
	GUI* get_gui() {return gui;}
	void set_gui(GUI* g) {gui = g;}
	void set_parent(Fl_Scroll* p) {parent = p;}
    void draw();
	int num_gates() {return gates.size();}
	vector<Gate*> *Gates () {return &gates;}
	Gate* get_gate (int i) {return gates[i];}
	Truth_Table* get_table() {return table;}
	void set_table(Truth_Table* t) {table = t;}
	void generate_circuit();
	bool Accepted() {return accepted;}
	void set_accepted(bool a) {accepted = a;}
	void Resize();
};

#endif