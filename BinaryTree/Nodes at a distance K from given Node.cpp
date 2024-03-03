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
 void markParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent)
 {
    if(!root) return;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
            TreeNode*currNode=q.front();
            q.pop();
    if(currNode->left)
    {
        q.push(currNode->left);
        parent[currNode->left]=currNode;
    }
    if(currNode->right)
    {
        q.push(currNode->right);
        parent[currNode->right]=currNode;
    }

    }
 }
vector<int> NodesAtaDistanceK(TreeNode*root,TreeNode*target,int k)
{
    unordered_map<TreeNode*,TreeNode*>parent;

    markParent(root,parent);
  queue<TreeNode*>q;
    unordered_map<TreeNode*,bool>visited;
    q.push(target);
    visited[target]=true;
    int dis=0;
    while(!q.empty())
    {
        int n=q.size();
        if(dis++ ==k) break;

        while(n--)
        {
            TreeNode*currNode=q.front();
            q.pop();
            if(currNode->left && !visited[currNode->left])
            {
                q.push(currNode->left);
                visited[currNode->left]=true;
            }
            if(currNode->right && !visited[currNode->right])
            {
                q.push(currNode->right);
                visited[currNode->right]=true;
            }
            if(parent[currNode] && !visited[parent[currNode]])
            {
                q.push(parent[currNode]);
                visited[parent[currNode]]=true;
            }
        }
    }
    vector<int>ans;
    while(!q.empty())
    {
        TreeNode*Node=q.front();
        q.pop();
        ans.push_back(Node->val);
    }
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
TreeNode* findTargetNode(TreeNode* root, int target) {
    if (!root || root->val == target) {
        return root;
    }

    TreeNode* leftResult = findTargetNode(root->left, target);
    TreeNode* rightResult = findTargetNode(root->right, target);

    if (leftResult) {
        return leftResult;  // Target found in the left subtree
    } else {
        return rightResult; // If left subtree doesn't contain target, check the right subtree
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
    int target,k;
    cin>>target>>k;
    TreeNode*targt=findTargetNode(root,2);
  // cout<<maximumPathSum(root);
     vector<int>ans=NodesAtaDistanceK(root,targt,2);
       // cout<<ans.size();
     for(int x:ans)
     {
        cout<<x<<" ";
     }

}