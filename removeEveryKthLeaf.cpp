BinaryTreeNode* removeEveryKthLeafHelper(BinaryTreeNode*& node, int k, int& count) {
        if(node != NULL){
            if(node->left == NULL && node->right == NULL){
                count++;
                if(count%k == 0){
                    delete(node);
                    node = NULL;
                    return node;
                }
            }
            node->left = removeEveryKthLeafHelper(node->left,k,count);
            node->right = removeEveryKthLeafHelper(node->right,k,count);
            return node;
        }
        return NULL;
}
BinaryTreeNode* removeEveryKthLeaf(BinaryTreeNode*& node, int k){
    
    int count = 0;
    if(k<1){
        throw k;
    }
    
    if(node == NULL)
        return NULL;
    
    
    if(node->left == NULL && node->right == NULL){
        delete node;
        node = NULL;
        return node;
    }
    return removeEveryKthLeafHelper(node,k,count);
}