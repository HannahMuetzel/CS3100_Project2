#pragma once
#include "TreeNode.h"

#define TREENODEPTR unsigned int
#define TREENULLPTR	-1
#include <string>

class OrgTree
{
private:
	unsigned int size = 1;
	unsigned int capacity = 0;
	TreeNode* tree;
	root = TREENULLPTR;

public:
	OrgTree();
	~OrgTree();

	void resize(TreeNode* tree);
	void setPointers(TREENODEPTR node);
	void addRoot(std::string title, std::string name);
	unsigned int getSize();
	unsigned int getRoot();
	unsigned int leftmostChild(TREENODEPTR node);
	unsigned int rightSibling(TREENODEPTR node);
	void printSubTree(TREENODEPTR subTreeRoot);
	unsigned int find(std::string title);
	bool read(std::string filename);
	void write(std::string filename);
	void hire(TREENODEPTR parent, std::string title, std::string name);
	bool fire(std::string title);
};