bool wordExists(BinaryTreeNodeChar* node, string& str,int size) {
    if(node!=NULL){
        if(node->data == str[0]){
            if(str.size() == 1)
                return true;
            str = str.substr(1,str.size()-1);
        }
        else if(str.size()<size)
            return false;
        return wordExists(node->left,str,size) || wordExists(node->right,str,size);
    }
    return false;
}
bool wordExists(BinaryTreeNodeChar* node, const string& str) {
    
	string a = str;
    return wordExists(node,a,str.size());
}