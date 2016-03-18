#pragma once
#include <string>
#define TREENODEPTR unsigned int
#define TREENULLPTR	-1

//Make a TreeNode to be implemented in OrgTree
class TreeNode
{
public:

	//default constructor
	TreeNode()
	{
		TNname = "";
		TNtitle = "";
		TNpar = TREENULLPTR;
		TNlc = TREENULLPTR;
		TNrs = TREENULLPTR;
	}

	//makes a TreeNode with all the params.
	TreeNode(std::string name, std::string title, TREENODEPTR parent, TREENODEPTR lc, TREENODEPTR rs)
	{
		TNname = name;
		TNtitle = title;
		TNpar = parent;
		TNlc = lc;
		TNrs = rs;
	}

	//TreeNode destructor
	~TreeNode()
	{
	}

	//set them pointers.
	void setPtrs(TREENODEPTR par, TREENODEPTR lc, TREENODEPTR rs) {
		TNpar = par;
		TNlc = lc;
		TNrs = rs;
	};

	//made public so more easily accessible by OrgTree
	std::string TNname;
	std::string TNtitle;
	TREENODEPTR TNpar;
	TREENODEPTR TNlc;
	TREENODEPTR TNrs;

};