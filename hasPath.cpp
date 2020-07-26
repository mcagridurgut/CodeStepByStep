bool help(BinaryTreeNode* node, int start, int end, bool first, bool second){
    if(node!=NULL){
        if(first){
            if(node->data == end)
                return true;
            return help(node->left,start,end,first,second)||help(node->right,start,end,first,second);
        }
        if(node->data == start){
            if(start == end)
                return true;
            first = true;
        }
        return help(node->left,start,end,first,second)||help(node->right,start,end,first,second);
    }
    return false;
}
bool hasPath(BinaryTreeNode* node, int start, int end) {
    
    return help(node,start,end,false,false);
	
}