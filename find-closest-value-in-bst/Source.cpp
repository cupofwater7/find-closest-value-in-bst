#include <iostream>
#include <cmath>
#include <float.h>
using namespace std;

class BST {
public:
	int value;
	BST* left;
	BST* right;

	BST(int val);
	BST& insert(int val);
};
int findClosestValueInBst(BST* tree, int target);
int findClosestValueInBstHelper(BST* tree, int target, int closest);

BST::BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
}

int main() 
{
    BST* root = new BST(10);
    root->left = new BST(5);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    root->left->right = new BST(5);
    root->right = new BST(15);
    root->right->left = new BST(13);
    root->right->left->right = new BST(14);
    root->right->right = new BST(22);
    int expected = 13;
    int actual = findClosestValueInBst(root, 12);
    cout << actual;
    return 0;
}

int findClosestValueInBst(BST* tree, int target) {
	// Write your code here.
	return findClosestValueInBstHelper(tree, target, tree->value);
}



int findClosestValueInBstHelper(BST* tree, int target, int closest)
{
    BST* currentNode = tree;

    while (currentNode != nullptr)
    {
        if (abs(target - closest) > abs(target - currentNode->value))
        {
            closest = currentNode->value;
        }
        if (currentNode->value > target) currentNode = currentNode->left;
        else if (currentNode->value < target) currentNode = currentNode->right;
        else break;

    }
    return (int)closest;
}