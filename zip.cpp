bool isLeaf(BinaryTreeNode* root){
    return ((root->left == NULL) && (root->right == NULL));
}
int isSingle(BinaryTreeNode* root){ //returns 1 if only left child exists, 2 if only right, 0 if it has no single child
    BinaryTreeNode* next;
    if(root->left != NULL)
        if(root->right != NULL){ return 0; }
        else{ return 1; }
    if(root->right != NULL)
            return 2;
    return 0;

}
void makeOne(BinaryTreeNode*& root,BinaryTreeNode*& next){
    root->data += next->data;
    root->left = next->left;
    root->right = next->right;
    delete next;
    next = NULL;
}

void zip(BinaryTreeNode*& root, int k, int& count){
    if( (root != NULL) && (!isLeaf(root)) ){
        
        int a = isSingle(root);
        if(a){
            BinaryTreeNode* next;
            if(a>1)
                next = root->right;
            else
                next = root->left;
            
            if(count < k){
                makeOne(root,next);
                count++;
                zip(root,k,count);
            }
            else{
                count = 1;
                zip(next,k,count);
            }
        }
        else{
            count = 1;
            zip(root->left,k,count);
            count = 1;
            zip(root->right,k,count);
        }
    }
}

void zip(BinaryTreeNode*& root, int k) {
    if(k<1)
        throw k;
    if(!(k == 1 && root == NULL)){
        int count = 1;
        zip(root,k,count);
    }
}