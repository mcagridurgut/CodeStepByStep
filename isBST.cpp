bool help(BinaryTreeNode* node, int min, int max){
    if(node!=NULL){
        if(node->data<max && node->data > min){
            return help(node->left,min,node->data) && help(node->right,node->data,max);
        }
        else return false;
    }
    return true;
}
bool isBST(BinaryTreeNode* node) {
    return help(node,-100000,100000);
	
}