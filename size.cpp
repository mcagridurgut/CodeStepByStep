void helper(BinaryTreeNode* node, int& count){
    if(node!=NULL){
        helper(node->left,count);
        count++;
        helper(node->right,count);
    }
}
int size(BinaryTreeNode* node) {
	int count = 0;
    helper(node,count);
    return count;
}