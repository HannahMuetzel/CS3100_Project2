#pragma once
#define TREENODEPTR unsigned int
#define TREENULLPTR	-1
#include <string>

class OrgTree
{
public:
	OrgTree();
	~OrgTree();

	//TODO: prototype resize tree if full and adding more crap to it
	void setPointers(parent, lc, rs);
	void addRoot(title, name);
	unsigned int getSize();
	unsigned int getRoot();
	unsigned int leftmostChild(TREENODEPTR node);
	unsigned int rightSibling(TREENODEPTR node);
	void printSubTree(TREENODEPTR subTreeRoot);
	unsigned int find(string title);
	bool read(string filename);
	void write(string filename);
	void hire(TREENODEPTR parent, string title, string name);
	bool fire(string title);
};