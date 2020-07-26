void printSideways(BinaryTreeNode* node, string indent = "") {
	if(node!= NULL){
        string k = indent+"    ";
        printSideways(node->right,k);
        cout<<indent<<node->data<<endl;
        printSideways(node->left,k);
    }
    cout<<"";
}