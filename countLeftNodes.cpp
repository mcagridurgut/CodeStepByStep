int count(BinaryTreeNode* root){
    if(root == NULL)
        return 0;
    if( root->left != NULL){
        return 1+count(root->left)+count(root->right);
    }
    return count(root->right);
}
int BinaryTree::countLeftNodes() const {
    return count(root);
}