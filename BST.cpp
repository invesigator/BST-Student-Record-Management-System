#include <iostream>
#include <fstream>
#include <algorithm>
#include "BST.h"
#include <string>



using namespace std;


BST::BST() {
	root = NULL;
	count = 0;
}


bool BST::empty() {
	if (count == 0) return true;
	return false;
}


int BST::size() {
	return count;
}


void BST::preOrderPrint() {
	if (root == NULL) return;// handle special case
	else preOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::preOrderPrint2(BTNode *cur) {

	if (cur == NULL) return;
	cur->item.print(cout);
	preOrderPrint2(cur->left);
	preOrderPrint2(cur->right);
}


void BST::inOrderPrint() {
	if (root == NULL) return;// handle special case
	else inOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::inOrderPrint2(BTNode *cur) {

	if (cur == NULL) return;

	inOrderPrint2(cur->left);
	cur->item.print(cout);
	inOrderPrint2(cur->right);
}


void BST::postOrderPrint() {
	if (root == NULL) return;// handle special case
	else postOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::postOrderPrint2(BTNode *cur) {
	if (cur == NULL) return;
	postOrderPrint2(cur->left);
	postOrderPrint2(cur->right);
	cur->item.print(cout);
}



int BST::countNode() {
	int	counter = 0;
	if (root == NULL) return 0;
	countNode2(root, counter);
	return counter;
}


void BST::countNode2(BTNode *cur, int &count) {
	if (cur == NULL) return;
	countNode2(cur->left, count);
	countNode2(cur->right, count);
	count++;
}


bool BST::findGrandsons(type grandFather) {
	if (root == NULL) return false;
	return (fGS2(grandFather, root));
}


bool BST::fGS2(type grandFather, BTNode *cur) {
	if (cur == NULL) return false;
	//if (cur->item == grandFather) {
	if (cur->item.compare2(grandFather)){

		fGS3(cur, 0);// do another TT to find grandsons
		return true;
	}
	if (fGS2(grandFather, cur->left)) return true;
	return fGS2(grandFather, cur->right);
}


void BST::fGS3(BTNode *cur, int level) {
	if (cur == NULL) return;
	if (level == 2) {
		cur->item.print(cout);
		return;  // No need to search downward
	}
	fGS3(cur->left, level + 1);
	fGS3(cur->right, level + 1);
}



void BST::topDownLevelTraversal() {
	BTNode			*cur;
	Queue		    q;


	if (empty()) return; 	// special case
	q.enqueue(root);	// Step 1: enqueue the first node
	while (!q.empty()) { 	// Step 2: do 2 operations inside
		q.dequeue(cur);
		if (cur != NULL) {
			cur->item.print(cout);

			if (cur->left != NULL)
				q.enqueue(cur->left);

			if (cur->right != NULL)
				q.enqueue(cur->right);
		}
	}
}

//insert for BST
bool BST::insert(type newItem) {
	BTNode	*cur = new BTNode(newItem);
	if (!cur) return false;		// special case 1
	if (root == NULL) {
		root = cur;
		count++;
		return true; 			// special case 2
	}
	insert2(root, cur);			// normal
	count++;
	return true;
}


void BST::insert2(BTNode *cur, BTNode *newNode) {
	//if (cur->item > newNode->item) {
	if (cur->item.compare1(newNode->item)){
		if (cur->left == NULL)
			cur->left = newNode;
		else
			insert2(cur->left, newNode);
	}
	else {
		if (cur->right == NULL)
			cur->right = newNode;
		else
			insert2(cur->right, newNode);
	}
}



bool BST::remove(type item) {
	if (root == NULL) return false; 		// special case 1: tree is empty
	return remove2(root, root, item); 		// normal case
}

bool BST::remove2(BTNode *pre, BTNode *cur, type item) {

	// Turn back when the search reaches the end of an external path
	if (cur == NULL) return false;

	// normal case: manage to find the item to be removed
	//if (cur->item == item) {
	if (cur->item.compare2(item)){
		if (cur->left == NULL || cur->right == NULL)
			case2(pre, cur);	// case 2 and case 1: cur has less than 2 sons
		else
			case3(cur);		// case 3, cur has 2 sons
		count--;				// update the counter
		return true;
	}

	// Current node does NOT store the current item -> ask left sub-tree to check
	//if (cur->item > item)
	if (cur->item.compare1(item))
		return remove2(cur, cur->left, item);

	// Item is not in the left subtree, try the right sub-tree instead
	return remove2(cur, cur->right, item);
}


void BST::case2(BTNode *pre, BTNode *cur) {

	// special case: delete root node
	if (pre == cur) {
		if (cur->left != NULL)	// has left son?
			root = cur->left;
		else
			root = cur->right;

		free(cur);
		return;
	}

	if (pre->right == cur) {		// father is right son of grandfather? 
		if (cur->left == NULL)			// father has no left son?
			pre->right = cur->right;			// connect gfather/gson
		else
			pre->right = cur->left;
	}
	else {						// father is left son of grandfather?
		if (cur->left == NULL)			// father has no left son? 
			pre->left = cur->right;				// connect gfather/gson
		else
			pre->left = cur->left;
	}

	free(cur);					// remove item
}


void BST::case3(BTNode *cur) {
	BTNode		*is, *isFather;

	// get the IS and IS_parent of current node
	is = isFather = cur->right;
	while (is->left != NULL) {
		isFather = is;
		is = is->left;
	}

	// copy IS node into current node
	cur->item = is->item;

	// Point IS_Father (grandfather) to IS_Child (grandson)
	if (is == isFather)
		cur->right = is->right;		// case 1: There is no IS_Father    
	else
		isFather->left = is->right;	// case 2: There is IS_Father

	// remove IS Node
	free(is);
}


bool BST::deepestNodes() {
	if (root == NULL) {  // if the tree is empty
		cout << "Error! The tree is empty.\n\n";
		return false;
	}

	int maxHeight = height(root);  // get the height of the tree
	printDeepestNodes(root, maxHeight);  // print the nodes at the deepest level

	return true;
}


void BST::printDeepestNodes(BTNode* node, int height) {
	if (node == NULL)
		return;

	if (height == 1)  // if the node is at the deepest level
		cout << "The deepest node of the student id is " << node->item.id << ".\n\n";
	
	else if (height > 1) {  // if the node is not at the deepest level
		// recursively check the left and right subtrees
		printDeepestNodes(node->left, height - 1);  
		printDeepestNodes(node->right, height - 1);
	}
}


int BST::height(BTNode* node) {
	if (node == NULL)
		return 0;

	else {
		int leftHeight = height(node->left);  // get the height of the left subtree
		int rightHeight = height(node->right);  // get the height of the right subtree

		if (leftHeight > rightHeight)  // if the left subtree is taller
			return (leftHeight + 1);  // return the height of the left subtree + 1, which is the height of the current node
		
		else
			return (rightHeight + 1);
	}
}


bool BST::display(int order, int source) {
	if (root == NULL) {
		cout << "Error! The tree is empty.\n";	
		return false;
	}

	ofstream outfile;

	if (source == 2) {  // source = 2 means the output is written to a file
		outfile.open("student-info.txt");

		if (!outfile.is_open()) {  // if the file cannot be opened
			cout << "Error! Cannot open the file student-info.txt successfully." << endl;
			return false;
		}
		else
			cout << "The file student-info.txt is opened successfully." << endl;

		if (order == 1)  // order = 1 means the output is in ascending order
			displayAsc(root, source, outfile);
		else if (order == 2)  // order = 2 means the output is in descending order
			displayDsc(root, source, outfile);

		outfile.close();
	}
	else if (source == 1) {  // source = 1 means the output is written to the screen
		if (order == 1)
			displayAsc(root, source, outfile);
		else if (order == 2)
			displayDsc(root, source, outfile);
	}
	else {  // if the source is invalid
		cout << "Error! Invalid source.\n\n";
		return false;
	}

	return true;
}


void BST::displayAsc(BTNode* node, int source, ofstream& outfile) {
	if (node == NULL) 
		return;

	displayAsc(node->left, source, outfile);  // recursively display the left subtree

	if (source == 1)  // print to screen
		node->item.print(cout);
	
	else if(source == 2)  // print to file
		node->item.print(outfile);

	displayAsc(node->right, source, outfile);  // recursively display the right subtree
}


void BST::displayDsc(BTNode* node, int source, ofstream& outfile) {
	if (node == NULL)
		return;

	displayDsc(node->right, source, outfile);  // recursively display the right subtree

	if (source == 1)
		node->item.print(cout);

	else if (source == 2)
		node->item.print(outfile);

	displayDsc(node->left, source, outfile);  // recursively display the left subtree
}


bool BST::findAndClone(BTNode* node, type item, BTNode*& cloneNode) {
	if (node == nullptr)  // if the node is null
		return false;
	
	if (node->item.compare2(item)) {  // compare 2 students struct variable
		cloneNode = new BTNode(node->item);  
		cloneNode->left = node->left;
		cloneNode->right = node->right;
		return true;
	}

	return findAndClone(node->left, item, cloneNode) || findAndClone(node->right, item, cloneNode);  // recursively search the left and right subtrees
}


BTNode* BST::cloneNode(BTNode* node) {
	if (node == nullptr)
		return nullptr;
	
	BTNode* newNode = new BTNode(node->item);  // create a new node

	// recursively clone the left and right subtrees
	newNode->left = cloneNode(node->left);  

	newNode->right = cloneNode(node->right);

	return newNode;  // return the new node
}


// CORRECTED VERSION:
bool BST::CloneSubtree(BST t1, type item) {
	if (t1.root == nullptr)
		return false;

	// Find the node containing the item
	BTNode* targetNode = findNode(t1.root, item);

	if (targetNode == nullptr)
		return false;

	// Deep clone the entire subtree rooted at targetNode
	this->root = cloneNode(targetNode);
	return true;
}

// Add this helper function to find the node:
BTNode* BST::findNode(BTNode* node, type item) {
	if (node == nullptr)
		return nullptr;

	if (node->item.compare2(item))
		return node;

	BTNode* leftResult = findNode(node->left, item);
	if (leftResult != nullptr)
		return leftResult;

	return findNode(node->right, item);
}


bool BST::printLevelNodes() {
	if (root == NULL)
		return false;

	Queue q;
	q.enqueue(root);
	int level = 1;

	cout << "The level of nodes in the tree is: \n\n";

	while (!q.empty()) {
		int levelSize = q.size();  // Get current level size
		cout << "Level " << level << " nodes: ";

		for (int i = 0; i < levelSize; i++) {
			BTNode* node;
			q.dequeue(node);  // Proper dequeue usage
			cout << node->item.id << "  ";

			// Add children to queue for next level
			if (node->left != NULL)
				q.enqueue(node->left);
			if (node->right != NULL)
				q.enqueue(node->right);
		}
		cout << endl;
		level++;
	}
	return true;
}


bool BST::printPath() {
	// if the tree is empty, return false
	if (root == NULL) {
		cout << "Error! The tree is empty.\n\n";
		return false;
	}

	cout << "\nBelow are all the external paths for the tree: \n\n";

	printPathHelper(root, "");  // call the helper function

	cout << endl;

	return true;
}


void BST::printPathHelper(BTNode* node, string path) {
	if (node == NULL)
		return;

	// If the node is a leaf node, print the path
	if (node->left == NULL && node->right == NULL) {
		cout << path << to_string(node->item.id) << endl;  // to_string is used to convert an integer to a string
		return;
	}

	// Check if the current node is an internal node
	if (node->left != NULL)
		printPathHelper(node->left, path + to_string(node->item.id) + " ");

	if (node->right != NULL)
		printPathHelper(node->right, path + to_string(node->item.id) + " ");
}

