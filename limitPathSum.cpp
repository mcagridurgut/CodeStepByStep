void destroy(BinaryTreeNode*& node){
    if(node!=NULL){
    destroy(node->left);
    destroy(node->right);
    delete node;
    node = NULL;
    }
}
void limitPathSum(BinaryTreeNode*& node, int max, int sum = 0) {
	if(node!=NULL){
        sum += node->data;
        if(sum>max)
            destroy(node);
        else{
            limitPathSum(node->left,max,sum);
            limitPathSum(node->right,max,sum);
        }
    }
}