#pragma once
#include <string>
#define TREENODEPTR unsigned int
#define TREENULLPTR	-1

class TreeNode
{
public:

	TreeNode()
	{
		TNname = "";
		TNtitle = "";
		TNpar = TREENULLPTR;
		TNlc = TREENULLPTR;
		TNrs = TREENULLPTR;
	}

	TreeNode(std::string name, std::string title, TREENODEPTR parent, TREENODEPTR lc, TREENODEPTR rs)
	{
		TNname = name;
		TNtitle = title;
		TNpar = parent;
		TNlc = lc;
		TNrs = rs;
	}

	~TreeNode()
	{
	}

	std::string TNname;
	std::string TNtitle;
	TREENODEPTR TNpar;
	TREENODEPTR TNlc;
	TREENODEPTR TNrs;

};