int height(BinaryTreeNode* node){
    if(node == NULL)
        return 0;
    return 1+ max( height(node->left), height(node->right) );
}
bool check(BinaryTreeNode* node){
    if(node == NULL)
        return true;
    if( abs( height(node->left) - height(node->right) ) > 1)
        return false;
    return check(node->left) && check(node->right);
}
bool BinaryTree::isBalanced() const {
	return check(root);
}