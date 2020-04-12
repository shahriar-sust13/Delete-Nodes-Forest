/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:

	void dfs(TreeNode *root, TreeNode *parent, bool isParentErased, bool isLeft, vector<TreeNode*> &forest_root, unordered_map<int, bool> &mark){
		if( root == NULL ){ // base case
			return;
		}
		if( mark.find(root->val) == mark.end() ){ // Current node won't be deleted
			if( parent == NULL or isParentErased == true ){ // Current node is the root of the forest
				forest_root.push_back(root);
			}
			if( parent != NULL and isParentErased == true ){ // Need to erase the edge between parent and child
				if( isLeft ){
					parent->left = NULL;
				}
				else{
					parent->right = NULL;
				}
			}
			dfs(root->left, root, false, true, forest_root, mark);
			dfs(root->right, root, false, false, forest_root, mark);
		}
		else{ // Current node will be deleted
			if( parent != NULL ){ // Need to erase the edge between parent and child
				if( isLeft ){
					parent->left = NULL;
				}
				else{
					parent->right = NULL;
				}
			}
			dfs(root->left, root, true, true, forest_root, mark);
			dfs(root->right, root, true, false, forest_root, mark);
		}
	}

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    	unordered_map<int, bool> mark; // Hash table for storing the to_delete values
    	for( int i = 0; i<to_delete.size(); i++ ){
    		mark[to_delete[i]] = true;
    	}
    	vector<TreeNode *> forest_root;
    	dfs(root, NULL, false, false, forest_root, mark);
    	return forest_root;
    }
};