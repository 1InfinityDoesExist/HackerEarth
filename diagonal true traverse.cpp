/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
void diagonalPrint(Node *root)
{
   // your code here
   queue<struct Node *> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
       struct Node *node = q.front();
       q.pop();
       if(node == NULL)
       {
           if(q.empty())
           {
               return;
           }
          //  cout << endl;
            q.push(NULL);
       }
       else
       {
           while(node)
           {
               cout << node->data << " ";
               if(node->left)
               {
                   q.push(node->left);
               }
               node = node->right;
           }
       }
   }
}
