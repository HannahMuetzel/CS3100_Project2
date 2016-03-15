#include <iostream>
#include "TreeNode.h"
#include "OrgTree.h"
#include "OrgTree.cpp"

int main()
{
	//test TreeNode constructors
	TreeNode nub;
	TreeNode nubsFriend("Nubbin 2", "Nubbin 1's Friend", TREENULLPTR, TREENULLPTR, TREENULLPTR);
	
	//TODO: test OrgTree::addRoot() & OrgTree::setPointers()
	OrgTree::addRoot(string "test title", string "test name");
	//TODO: test OrgTree::resize()
	//OrgTree::addRoot(string "new title", string "new name");

	std::cout << "Boo!" << std::endl;
	system("pause");
	return 0;
}

