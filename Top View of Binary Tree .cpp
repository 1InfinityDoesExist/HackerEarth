/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//Structure of binary tree
/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    // Your code here
    vector<vector<int> > res;
    if(root == NULL)
    {
        return;
    }
  //  map<int, vector<int> > mp;
  set<int> st;
  st.insert(0);
  cout << root->data << " ";
    queue<pair<struct Node *, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        pair<struct Node *, int> p = q.front();
        q.pop();
        int hd = p.second;
        struct Node *tmp = p.first;

      //  mp[hd].push_back(tmp->data);
        if(tmp->left != NULL)
        {
            q.push(make_pair(tmp->left,hd-1));
            if(st.find(hd-1) == st.end())
            {
                cout << tmp->left->data << " ";
                st.insert(hd-1);
            }
        }
        if(tmp->right != NULL)
        {
            q.push(make_pair(tmp->right, hd+1));
            if(st.find(hd+1) == st.end())
            {
                cout << tmp->right->data << " ";
                st.insert(hd+1);
            }
        }
    }
}
