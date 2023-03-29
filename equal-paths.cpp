#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
/*int heightOfTree(Node * root) // doesn't work w/ 9/12 tests
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root -> left == NULL && root -> right == NULL)
    {
        return 1;
    }
    return (heightOfTree(root -> left) + heightOfTree(root -> right) % 2);
}*/
int shortestHeightOfTree(Node * root) // does not check in the case of if left or right doesn't exist
{
		int rightHeight = 0, leftHeight = 0;
    if (root == NULL)
    {
        return 0;
    }
		else if (root -> left == NULL && root -> right == NULL)
    {
        return 1;
    }

    if (root -> right != NULL)
    {
        rightHeight = shortestHeightOfTree(root -> right);
    }
    if (root -> left != NULL)
    {
        leftHeight = shortestHeightOfTree(root -> left);
    }

    // meant to check if left and right path are the same height or not
		if (rightHeight == 0 && leftHeight != 0)
		{
				return leftHeight + 1;
		}
		else if (rightHeight != 0 && leftHeight == 0)
		{
				return rightHeight + 1;
		}
		else if (leftHeight <= rightHeight && rightHeight != 0 && leftHeight != 0)
		{
				return leftHeight + 1;
		}
		else
		{
				return rightHeight + 1;
		}
}
int longestHeightOfTree(Node * root) // does not check in the case of if left or right doesn't exist
{
		int rightHeight = 0, leftHeight = 0;
    if (root == NULL)
    {
        return 0;
    }
		else if (root -> left == NULL && root -> right == NULL)
    {
        return 1;
    }

    if (root -> right != NULL)
    {
        rightHeight = longestHeightOfTree(root -> right);
    }
    if (root -> left != NULL)
    {
        leftHeight = longestHeightOfTree(root -> left);
    }

    // meant to check if left and right path are the same height or not
		if (rightHeight == 0 && leftHeight != 0)
		{
				return leftHeight + 1;
		}
		else if (rightHeight != 0 && leftHeight == 0)
		{
				return rightHeight + 1;
		}
		else if (leftHeight >= rightHeight)
		{
				return leftHeight + 1;
		}
		else
		{
				return rightHeight + 1;
		}
}

bool equalPaths(Node * root)
{
    // Add your code below

    // no left and right, so  by default all paths have the same height
    if (root == NULL)
    {
        return true;
    }
    //if not null, check the heights of left and right
    else
    {
        if (shortestHeightOfTree(root) != longestHeightOfTree(root))
        {
            return false;
        }
    }
    
    return true;

}

