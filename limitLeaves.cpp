BinaryTreeNode* limit(BinaryTreeNode*& node, int n) {
    if(node == NULL)
        return NULL;
    node->left = limit(node->left,n);
    node->right = limit(node->right,n);
    
    if(node->data<=n && (node->left == NULL && node->right == NULL) )
    {
        delete node;
        node = NULL;
    }
    return node;
    
}
void limitLeaves(BinaryTreeNode*& node, int n) {
	node = limit(node,n);
}