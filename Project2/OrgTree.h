#pragma once
#define TREENODEPTR unsigned int
#define TREENULLPTR	-1
#include <string>

class OrgTree
{
private:
	unsigned int size = 1;
	unsigned int capacity = 0;
	TreeNode* tree;
	TreeNode* root = TREENULLPTR;

public:
	OrgTree();
	~OrgTree();

	void resize(TreeNode*[]);
	void setPointers(TREENODEPTR node);
	void addRoot(string title, string name);
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