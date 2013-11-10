struct Tree {
	int val;
	Tree* left;
	Tree* right;
}
vector<int> BreadthFirstSearch(Tree* root)
{
	queue<Tree*> q;
	q.push(root);
	vector<int> ret;
	while(!q.empty())
	{
		Tree* tmp = q.front();
		q.pop();
		ret.push_back(tmp->val);
		if(root->left!=NULL)
		{
			q.push(root->left);
		}
		if(root->right!=NULL)
		{
			q.push(root->right);
		}
	}
	return ret;
}
void InOrder(Tree* root,vector<int> &ans)
{
	if(root!=NULL)
	{
		InOrder(root->left);
		ans.push_back(root->val);
		InOrder(root->right);
	}
}
void PreOrder(Tree* root,vector<int> &ans)
{
	if(root!=NULL)
	{
		ans.push_back(root->val);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void PostOrder(Tree* root,vector<int> &ans)
{
	if(root!=NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		ans.push_back(root->val);
	}
}
