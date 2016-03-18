#define TREENODEPTR unsigned int
#define TREENULLPTR	-1
#include <string>
#include "OrgTree.h"
#include "TreeNode.h"

//Creates OrgTree, which is a general tree. One node holds 5 pointers, so each node needs space for 5 pointers and
//an int (its TREENODEPTR index).
//in this situation, size IS n, so theta(n)
OrgTree::OrgTree()
{
	size = 0;	//how many nodes ARE in the tree
	capacity = 100; //how many nodes CAN be in the tree
	tree = new TreeNode[size];
	root = 0;
}

//theta(n)--destructor
OrgTree::~OrgTree()
{
	delete[] tree;
}

//theta(n)
//resize tree if full and adding more crap to it
void OrgTree::resize(TreeNode* tree) {
	//increase the capacity of the arr
	capacity = capacity * 2;		
	TreeNode* temp = new TreeNode[capacity];
	for (int i = 0; i < capacity; i++) {
		temp[i] = tree[i];
	}
	delete[] tree;
	tree = temp;
}

//theta(1)
//OrgTree::setPointers(parent, lc, rs)
void OrgTree::setPtrs(TREENODEPTR node, TREENODEPTR par, TREENODEPTR lc, TREENODEPTR rs) {
	tree[node].TNpar = par;
	tree[node].TNrs = rs;
	tree[node].TNlc = lc;
}

//theta(n) bc of resize() being theta(n)
//OrgTree::addRoot(title, name) - resize if tree is full
void OrgTree::addRoot(std::string title, std::string name) {
	//just hire a guy. if he's a root, cool.
	hire(TREENULLPTR, title, name);
}

//theta(1)
//unsigned int OrgTree::getSize() - return # of employees
unsigned int OrgTree::getSize() {
	return size;
}

//theta(1)
//TREENODEPTR OrgTree::getRoot() - return array index of root of tree
TREENODEPTR OrgTree::getRoot() {
	//return TREENODEPTR of root which is @ tree[0]
	return root;
}

//theta(1)
//OrgTree::leftmostChild(TREENODEPTR node) - return pointer to lc of node passed. if no children, return TREENULLPTR
TREENODEPTR OrgTree::leftmostChild(TREENODEPTR node) {
	return tree[node].TNlc;
}

//theta(1)
//OrgTree::rightSibling(TREENODEPTR node) - return pointer to rs of node passed. if no rs, return TREENULLPTR
TREENODEPTR OrgTree::rightSibling(TREENODEPTR node) {
	return tree[node].TNrs;
}

//theta(n)
//TREENODEPTR OrgTree::find(title) - return TREENODEPTR to the node that has title. if no title found, return TREENULLPTR
TREENODEPTR OrgTree::find(std::string title) {
	//traverse tree, compare title to tree[currNodePtr].TNtitle.
	//if title == tree[currNodePtr].TNtitle, currNodePtr;
	for (int currNodePtr = 0; currNodePtr < size; currNodePtr++) {
		if (title == tree[currNodePtr].TNtitle) {
			return currNodePtr;
			//leaves find method if person w title is found
		}
	}

	//return TREENULLPTR if person w title isn't found
	return TREENULLPTR;
}

//TODO: void OrgTree::printSubTree(TREENODEPTR subTreeRoot) - prints subtree starting at subTreeRoot (use indentation indicated)
void OrgTree::printSubTree(TREENODEPTR subTreeRoot) {
	//start with root
	//next line, indent & print root.lc (which is now called next)
	//if next.lc == null, print ) and then print (next.lc).rs
	//else, print next.lc, then go back up to doing this again and again.
	//repeat indent again, etc etc, for as deep as it needs to go
	//print (next.lc).rs until ((next.lc).rs).rs == null

	/*next = tree[subTreeRoot].lc;
		if (next == TREENULLPTR) {
			print ")";
		} else {
			//do the above
		}
	*/
}
//TODO: bool OrgTree::read(filename) - reads orgTree from file. return true if file found & read successfully, else return false.
//TODO: void OrgTree::write(filename) write to orgTree file using same format in read()

//theta(n) bc resize() is theta(n)
//void OrgTree::hire(TREENODEPTR, title, name) hire name with title title. 
	//make TREENODEPTR their parent. must also change rs of rightmost child of TREENODEPTR's kids
void OrgTree::hire(TREENODEPTR par, std::string name, std::string title) {
	//omg make da node yo
	TreeNode newNode(name, title, TREENULLPTR, TREENULLPTR, TREENULLPTR); //make a new employee node
	TREENODEPTR ptr = size;
	//set its pointers to the parent pointer & null pointers for lc & rs
	newNode.setPtrs(par, TREENULLPTR, TREENULLPTR);
	//put newNode in tree, inc size
	tree[ptr] = newNode;
	size++;

	//if tree is full, resize
	if (size == capacity) {
		resize(tree);
	}

	//is this node the root?
	if (par == TREENULLPTR) {
		//then its the root woop-de-doo
		//if there already is a root, currRoot ptr is 0--need to fix this poo
		if (ptr = !0) {
			//set old root to be kid of new root
			tree[root].TNpar = ptr;
			//so old root is lc of new root
			newNode.TNlc = root;
		}
		root = ptr;
		//cool now new node is the root
		//give da new parent a kid
	} else if (tree[par].TNlc == TREENULLPTR) {
		//set lc of par to node's ptr
		tree[par].TNlc = ptr;
		//gives par the lc of new node
	} //else the parent already has a lc & we gotta add newNode as a rs to the furthestRightChild
	else {
		TREENODEPTR furthestRChild = tree[par].TNlc; //possible that furthestRChild is the furthestLeftChild
		//if currNode's rs == TREENULLPTR then currNode is the furthestRChild of par.
		//else, then do the same lil search thing (change currNode) and hope for the best. Keep doing this til done.
		//crap that means recursion doesn't it.
		//brb writing recursive method for finding a kid.
		//k back.
		furthestRChild == OrgTree::theRIGHTEST(tree[par].TNlc, TREENULLPTR); //if right sib == null then no right sib. it's rightest kid of tree[par]
		//make furthestRChild's right sib the new node.
		tree[furthestRChild].TNrs = ptr;
	} 
	
	//omg am i done adding a node?
	//omg i think i am
	//time to get rid of it.
	//aka backwards hire--except more complicated :')
	//why did i pick this major tbh
}

//theta(1) (i think?)
//world's crappiest method to find if the right sib is the passed node
TREENODEPTR OrgTree::theRIGHTEST(TREENODEPTR currNode, TREENODEPTR brotherNode) {
	//tfw "tree" isn't defined except that it is. you know. that feel. that feel, man.
	if (tree[currNode].TNrs == brotherNode) {
		return currNode;
	} //currNode's right sibling = brotherNode! stop.
	else {
		//gotta call it again, using currNode's right sib so just...do that?
		OrgTree::theRIGHTEST(tree[currNode].TNrs, brotherNode);
		//do dis til u find good good.
	}
}

//theta(1) (i think?...you can tell i'm so confident in my answers, can't you?)
//bool OrgTree::fire(title) - fire employee with title title. 
	//if title is found and employee fired, return true. 
	//if no title match found or title is that of rootNode, return false and don't delete any nodes.
bool OrgTree::fire(std::string title) {
	//holy crap don't forget to return a boolean because you probably will
	//i'm not even removing these comments anymore #sorrynotsorry

	//find(title)
	//if find(title) returns TREENULLPTR then mr. employee isn't really hired, so return false, delete nothing.
	//is he real??! cool. kill--errrr..."fire" him.
	//fix the pointers for everyone else. aka: hard part of fire.

	TREENODEPTR toFire = find(title);
	if (toFire == TREENULLPTR || tree[root].TNtitle == title) {
		return false;
	}
	//else, he's part of the company and he's got to goooo
	else {
		//go thru the tree
		for (int i = 0; i < size; i++) {

			if (tree[i].TNtitle == title) {
				//we found him. eliminate.

				//get prevKid to be the rightest sib of the lc of the parent of where we are now
				TREENODEPTR prevKid = OrgTree::theRIGHTEST(tree[tree[i].TNpar].TNlc, i);
				tree[prevKid].TNrs = tree[i].TNrs;

				//set the lc of mr. employee's parent to mr. employee's lc
				tree[tree[i].TNpar].TNlc = tree[i].TNlc;

				//set the freakin' children of who mr. employee had to the dude above him.
				//and DON'T delete Billy in accounting.
				while (tree[i].TNlc != TREENULLPTR) {
					//TREENODEPTR toFiresParsRightChild = OrgTree::theRIGHTEST(tree[tree[i].TNpar].TNlc, TREENULLPTR);
					//tree[toFiresParsRightChild].TNrs = tree[i].TNlc;
					OrgTree::dudebroKidSwap(tree[i].TNrs, tree[i].TNpar);
				}

				//reduce size because we fired mr. mcidiot
				size--;
				return true;
			}
		}
	}
}

//recursive method to change fired man (dudebro) kids' parent pionter.
//theta(1)
void OrgTree::dudebroKidSwap(TREENODEPTR dudebro, TREENODEPTR newPar) {

	if (tree[dudebro].TNlc == TREENULLPTR) {
		return;
	}
	else {
		tree[dudebro].TNpar = newPar;		
		dudebroKidSwap(theRIGHTEST(tree[tree[dudebro].TNpar].TNlc, TREENULLPTR), newPar);	
	}	
}