// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

vector<int> leftView(Node *r)
{
   // Your code here
   
   if(!r) return {};
   
   vector<int> res;
   queue<Node *> q;
   q.push(r);
   
   while(q.size())
   {
       int s=q.size();
       bool flag=1;
       
       while(s--)
       {
           Node * curr=q.front();
           q.pop();
           
           if(flag)
           {
               flag=0;
               res.push_back(curr->data);
           }
           
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
         
       }
   }
   
   return res;
}
