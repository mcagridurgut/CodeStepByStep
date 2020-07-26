void print(BinaryTreeNode* node) {
	if(node!=NULL){
        print(node->left);
        cout<<node->data<<endl;
        print(node->right);
    }
}