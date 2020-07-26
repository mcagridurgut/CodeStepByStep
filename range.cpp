void sizehelper(BinaryTreeNode* node, int& count){
    if(node!=NULL){
        sizehelper(node->left,count);
        count++;
        sizehelper(node->right,count);
    }
}
int size(BinaryTreeNode* node) {
	int count = 0;
    sizehelper(node,count);
    return count;
}
BinaryTreeNode* helper(BinaryTreeNode*& node, int min, int max, int& count){
    if(node==NULL)
        return NULL;
    if(node->data < min)
    {
        BinaryTreeNode* temp = node->right;
        node->right = NULL;
        count += size(node);
        delete node;
        node = temp;
        temp = NULL;
        return helper(node,min,max,count);
    }
    else if(node->data > max)
    {
        BinaryTreeNode* temp = node->left;
        node->left = NULL;
        count += size(node);
        delete node;
        node = temp;
        temp = NULL;
        return helper(node,min,max,count);
    }
    if(node!=NULL){
    helper(node->left,min,max,count);
    helper(node->right,min,max,count);
    }
    return node;
}
int range(BinaryTreeNode*& node, int min, int max) {
	if(min>max)
        throw 0;
    int count = 0;
    node = helper(node,min,max,count);
    return count;
}