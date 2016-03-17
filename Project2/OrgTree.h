#pragma once
#include "TreeNode.h"

#define TREENODEPTR unsigned int
#define TREENULLPTR	-1
#include <string>

class OrgTree
{
private:
	unsigned int size;
	unsigned int capacity;
	TreeNode* tree;
	TREENODEPTR root;

public:
	OrgTree();
	~OrgTree();

	void resize(TreeNode* tree);
	void addRoot(std::string title, std::string name);
	unsigned int getSize();
	unsigned int getRoot();
	void OrgTree::setPtrs(TREENODEPTR node, TREENODEPTR par, TREENODEPTR lc, TREENODEPTR rs);
	unsigned int leftmostChild(TREENODEPTR node);
	unsigned int rightSibling(TREENODEPTR node);
	void printSubTree(TREENODEPTR subTreeRoot);
	unsigned int find(std::string title);
	bool read(std::string filename);
	void write(std::string filename);
	void hire(TREENODEPTR parent, std::string name, std::string title);
	bool fire(std::string title);
	TREENODEPTR theRIGHTEST(TREENODEPTR currNode, TREENODEPTR brotherNode); //omg recursion wowZERS!!!
};