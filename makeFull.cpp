bool isLeaf(BinaryTreeNode* root){
    return (root->left==NULL) && (root->right == NULL);
}
bool isFull(BinaryTreeNode* root){
    if(root==NULL)
        return true;
    if(isLeaf(root))
        return true;
    if(root->left == NULL)
        return false;
    if(root->right == NULL)
        return false;
    return isFull(root->left) && isFull(root->right);
}
int makeFull(BinaryTreeNode*& root, int& level, int& count) {
    
    if(isFull(root))
        return count;
    
    int c = level+1;
    int a = makeFull(root->left,c,count);
    
    if( (root->right == NULL) || (root->left == NULL) ){
        
        BinaryTreeNode** next;
        if(root->left == NULL) {next = &(root->left);}
        else {next = &(root->right);}
        (*next) = new BinaryTreeNode();
        (*next)->data = root->data;
        root->data = -level;
        count++;
    }
    
    
    c = level+1;
    int b = makeFull(root->right,c,count);
    return a+b;
    
    
}
int makeFull(BinaryTreeNode*& root) {
    if(root==NULL)
        return 0;
    if(isFull(root))
        return 0;
    
    int level = 1;
    int count = 0;
    return makeFull(root,level,count);
}