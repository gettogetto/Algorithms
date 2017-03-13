int findLargestBSTSubtree(BinaryTree *p, int &min, int &max, 
                   int &maxNodes, BinaryTree *& largestBST) {
  if (!p) return 0;
  bool isBST = true;
  int leftNodes = findLargestBSTSubtree(p->left, min, max, maxNodes, largestBST);
  int currMin = (leftNodes == 0) ? p->data : min;
  if (leftNodes == -1 || 
     (leftNodes != 0 && p->data <= max))
    isBST = false;
  int rightNodes = findLargestBSTSubtree(p->right, min, max, maxNodes, largestBST);
  int currMax = (rightNodes == 0) ? p->data : max;
  if (rightNodes == -1 || 
     (rightNodes != 0 && p->data >= min))
    isBST = false;
  if (isBST) {
    min = currMin;
    max = currMax;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = p;
    }
    return totalNodes;
  } else {
    return -1;   // This subtree is not a BST
  }
}
 
BinaryTree* findLargestBSTSubtree(BinaryTree *root) {
  BinaryTree *largestBST = NULL;
  int min, max;
  int maxNodes = INT_MIN;
  findLargestBSTSubtree(root, min, max, maxNodes, largestBST);
  return largestBST;
}
