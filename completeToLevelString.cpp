BinaryTreeNodeString* complete(BinaryTreeNodeString*& node, int n){
    
    if(n < 1)
        throw n;
        
    if(node == NULL){
        node = new BinaryTreeNodeString();
        node->data = "??";
    }
        
    if(n == 1){
        return node;
    }
        
    node->left = complete(node->left, n - 1);
    node->right = complete(node->right, n - 1);
    return node;
    
}
void completeToLevel(BinaryTreeNodeString*& node, int k) {
	node = complete(node,k);
}