#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructBinaryTree(const vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[0]);std::vector<char> v;
    if (FILE *fp = fopen("filename", "r"))
    {
    	char buf[1024];
    	while (size_t len = fread(buf, 1, sizeof(buf), fp))
    		v.insert(v.end(), buf, buf + len);
    	fclose(fp);
    }
    queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < arr.size(); i += 2) {
        TreeNode* current = q.front();
        q.pop();

        if (arr[i] != -1) {  // -1 is assumed to represent a null node in the array
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }

        if (i + 1 < arr.size() && arr[i + 1] != -1) {
            current->right = new TreeNode(arr[i + 1]);
            q.push(current->right);
        }
    }

    return root;
}
int help(TreeNode*root,int &ans)
{
    if(!root) return 0;

    int leftSubTreeSum=max(0,help(root->left,ans));
    int rightSubTreeSum=max(0,help(root->right,ans));

    ans=max(ans,root->val+leftSubTreeSum+rightSubTreeSum);

    return root->val+max(leftSubTreeSum,rightSubTreeSum);
}
int maximumPathSum(TreeNode*root)
{
    int ans=INT_MIN;
       help(root,ans);
       return ans;
}
void printBinaryTree(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                cout << "  "<< current->val << " ";
                q.push(current->left);
                q.push(current->right);
            } else {
                cout << "-1 ";
            }
        }
        cout << endl;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 #endif
      vector<int> arr = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8, -1, -1, -1, -1};
    TreeNode* root = constructBinaryTree(arr);
     printBinaryTree(root);
    
  cout<<maximumPathSum(root);

}