void help(BinaryTreeNode*& node, int k, int& level){
    if(node!=NULL && k>=level)
    {
        int lv = level+1;
        help(node->left,k,lv);
            if(k==level){
                BinaryTreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
                temp = NULL;
            }
        lv = level+1;
        help(node->right,k,lv);
    }
}
void swapChildrenAtLevel(BinaryTreeNode*& node, int k) {
    if(k>0){
        int level = 1;
        help(node,k,level);
    }
    else
        throw k;
}