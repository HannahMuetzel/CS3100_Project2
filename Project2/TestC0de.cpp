#include <iostream>
#include "OrgTree.h"

int main()
{
	//test TreeNode constructors
	TreeNode nub;
	TreeNode nubsFriend("Nubbin 2", "Nubbin 1's Friend", TREENULLPTR, TREENULLPTR, TREENULLPTR);
	
	OrgTree cherryTree;
	cherryTree.addRoot("test title", "test name");
	
	std::cout << "Boo!" << std::endl;
	system("pause");
	return 0;
}

