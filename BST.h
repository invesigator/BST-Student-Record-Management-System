// In BST.h, add this line in the private section with other helper functions:

#ifndef BT_type
#define BT_type

#include	"BTNode.h"
#include	"Queue.h"

struct BST {
    int		count;
    BTNode* root;

    // print operation for BST (same as BT)					
    void preOrderPrint2(BTNode*);	// recursive function for preOrderPrint()
    void inOrderPrint2(BTNode*);	// recursive function for inOrderPrint()
    void postOrderPrint2(BTNode*);	// recursive function for postOrderPrint()

    // sample operation (extra functions) - same as BT
    void countNode2(BTNode*, int&);		// recursive function for countNode()
    bool fGS2(type, BTNode*);					// recursive function for findGrandsons(): to find the grandfather
    void fGS3(BTNode*, int);				// recursive function for findGrandsons(): to find the grandsons after the grandfather has been found

    // basic functions for BST
    void insert2(BTNode*, BTNode*);		// recursive function for insert() of BST
    void case3(BTNode*);					// recursive function for remove()
    void case2(BTNode*, BTNode*);		// recursive function for remove()
    bool remove2(BTNode*, BTNode*, type);	// recursive function for remove()

    // ADD THIS LINE - helper function for CloneSubtree
    BTNode* findNode(BTNode*, type);        // helper function to find a node with specific item

    // basic functions for BST
    BST();
    bool empty();
    int size();
    bool insert(type);		// insert an item into a BST
    bool remove(type);			// remove an item from a BST

    // print operation for BST (same as BT)
    void preOrderPrint();			// print BST node in pre-order manner
    void inOrderPrint();			// print BST node in in-order manner
    void postOrderPrint();			// print BST node in post-order manner
    void topDownLevelTraversal();	// print BST level-by-level

    // sample operation (extra functions) - same as BT
    int countNode();		// count number of tree nodes
    bool findGrandsons(type);	// find the grandsons of an input father item

    bool deepestNodes();	// find the deepest nodes of a BST
    void printDeepestNodes(BTNode*, int);  // print the deepest nodes of a BST
    int height(BTNode*);  // find the height of a BST

    bool display(int, int);	// display the tree 
    void displayAsc(BTNode*, int, ofstream&);  // display the tree in ascending order
    void displayDsc(BTNode*, int, ofstream&);	// display the tree in descending order

    bool CloneSubtree(BST, type);	// clone a subtree of a BST
    bool findAndClone(BTNode*, type, BTNode*&);	// find the root of the subtree to be cloned
    BTNode* cloneNode(BTNode*);  // clone a node of a BST

    bool printLevelNodes();  // print the nodes of a BST level-by-level

    bool printPath();  // print the path from the root to a node
    void printPathHelper(BTNode*, string);  // helper function for printPath()
};

#endif