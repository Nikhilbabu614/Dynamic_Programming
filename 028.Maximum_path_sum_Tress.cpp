// From any node to any node
int solve(Node *root, int &res)
{
    if (root == NULL)
        return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    int temp = max(root->data + max(l, r), root->data);
    int ans = max(temp, l + r + root->data);
    res = max(res, ans);
    return temp;
}
int findMaxSum(Node *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}


// From any leaf  to any leaf
int height(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;
    int l = max(0, height(root->left, ans));
    int r = max(0, height(root->right, ans));
    ans = max(ans, root->val + l + r);
    return root->val + max(l, r);
}
int maxPathSum(TreeNode *root)
{
    int ans = root->val;
    height(root, ans);
    return ans;
}