#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	int data;
	TreeNode*left;
	TreeNode*right;
   TreeNode(int x)
     {
     	data=x;
     	left=NULL;
     	right=NULL;
     }

};
string serializeTree(TreeNode*root)
{
	if(!root) return "";
       string data;
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
          TreeNode*currNode=q.front();
          q.pop();
          if(currNode==NULL)
          {
          	data.append("null,");
          }
          else
          {
          	data.append(to_string(currNode->data)+",");
          	q.push(currNode->left);
          	q.push(currNode->right);
          }
       }
       return data;
}
TreeNode * constructBinaryTreeORDeserialize(string data)
{
	if(data.size()==0) return NULL;
      stringstream s(data);
       string str;
      getline(s,str,',');
      TreeNode*root=new TreeNode(stoi(str));
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty())
      {
      	TreeNode*currNode=q.front();
      	q.pop();
      	getline(s,str,',');
      	if(str=="null")
      	{
            currNode->left=NULL;
      	}
      	else
      	{
      		TreeNode*leftNode=new TreeNode(stoi(str));
      		currNode->left=leftNode;
      		q.push(leftNode);
      	}
      	getline(s,str,',');
      	if(str=="null")
      	{
      		currNode->right=NULL;

      	}
      	else
      	{
      		TreeNode*rightNode=new TreeNode(stoi(str));
      		currNode->right=rightNode;
      		q.push(rightNode);
      	}
      }
      return root;

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
                cout << "  "<< current->data << " ";
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
  string s;
  cin>>s;
TreeNode*root=constructBinaryTreeORDeserialize(s);
  printBinaryTree(root);
  cout<<"\n"<<serializeTree(root);
}