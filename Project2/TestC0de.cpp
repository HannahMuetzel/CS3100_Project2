#include <iostream>
#include "OrgTree.h"

int main()
{
	//test TreeNode constructors
	TreeNode nub;
	TreeNode nubsFriend("Nubbin 2", "Nubbin 1's Friend", TREENULLPTR, TREENULLPTR, TREENULLPTR);
	
	OrgTree cherryTree;
	//TODO: test OrgTree::addRoot() & OrgTree::setPointers()
	cherryTree.addRoot("test title", "test name");
	//TODO: test OrgTree::resize()
	//OrgTree::addRoot(string "new title", string "new name");

	std::cout << "Boo!" << std::endl;
	system("pause");
	return 0;
}

