/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string>A;
    void path(TreeNode *rt,string data)
{
        
	if( rt!=NULL && rt->left==NULL && rt->right==NULL)
	{
      A.push_back(data+ to_string(rt->val));
	}
	else
	{
		if(rt->left)
        {
            string z=data + to_string(rt->val);
            path(rt->left,z);
        }
        if(rt->right)
        {
             string z=data + to_string(rt->val);
            path(rt->right,z);
        }
	}
}
    int sumRootToLeaf(TreeNode* root) {
        string p;
        path(root,p);
        long int sum=0,i=0;
        while(i<A.size())
        {
            sum=sum+stoi(A[i],0,2);
            i++;
        }
        return sum;
    }
};
