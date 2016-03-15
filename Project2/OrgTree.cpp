#define TREENODEPTR unsigned int
#define TREENULLPTR	-1
#include <string>
#include "OrgTree.h"
#include "TreeNode.h"


OrgTree::OrgTree()
{
	tree = new TreeNode*[size];
}


OrgTree::~OrgTree()
{
	delete[] tree;
}

//TODO: resize tree if full and adding more crap to it
void OrgTree::resize(TreeNode*[] tnptr) {
	//increase the size of the arr
	size = size * 2;		
	TreeNode* temp = new TreeNode*[size];
	for (int i = 0; i < size; i++) {
		temp[i] = tnptr[i];
	}
	delete[] tnptr;
	tnptr = temp;
}

//TODO: OrgTree::setPointers(parent, lc, rs) to NULL
void OrgTree::setPointers(TREENODEPTR node) {
	tree[node].TNpar = TREENULLPTR;
	tree[node].TNrs = TREENULLPTR;
	tree[node].TNlc = TREENULLPTR;
}

//TODO: OrgTree::addRoot(title, name) - resize if tree is full
void OrgTree::addRoot(string title, string name) {
	if (root == TREENULLPTR) {
		//if tree is full, resize (shouldn't get here because first node added)
		if (size == capacity) {
			resize(tree[]);
		}
		//set root's ptrs to null.
		setPointers(root);
		tree[capacity] = root;
		tree[capacity].TNtitle = title;
		tree[capacity].TNname = name;
		root = tree[capacity];
		capacity++;
	}
	//TODO: else: entire tree becomes subtree of new root
	/* //if tree is full, resize
		if (size == capacity) {
			resize(tree[]);
		}*/
}

//TODO: unsigned int OrgTree::getSize() - return # of employees
//TODO: OrgTree::getRoot() - return array index of root of tree
//TODO: OrgTree::leftmostChild(TREENODEPTR node) - return pointer to lc of node passed. if no children, return TREENULLPTR
//TODO: OrgTree::rightSibling(TREENODEPTR node) - return pointer to rs of node passed. if no rs, return TREENULLPTR
//TODO: void OrgTree::printSubTree(TREENODEPTR subTreeRoot) - prints subtree starting at subTreeRoot (use indentation indicated)
//TODO: OrgTree::find(title) - return TREENODEPTR to the node that has title. if no title found, return TREENULLPTR
//TODO: bool OrgTree::read(filename) - reads orgTree from file. return true if file found & read successfully, else return false.
//TODO: void OrgTree::write(filename) write to orgTree file using same format in read()
//TODO: void OrgTree::hire(TREENODEPTR, title, name) hire name with title title. make TREENODEPTR their parent. must also change rs of rightmost child of TREENODEPTR's kids
//TODO: bool OrgTree::fire(title) - fire employee with title title. if title is found and employee fired, return true. if no title match found or title is that of rootNode, return false and don't delete any nodes.