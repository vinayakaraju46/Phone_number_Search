#include<bits/stdc++.h>

using namespace std;

class Node
{


    public:
        char data;
        Node *left;
        Node *right;
        Node *middle;
        int keyvalue;
        Node(char &val)
        {
            data = val;
            left = NULL;
            right = NULL;
            middle = NULL;
            keyvalue = 0;
        }
};

class TernaryTree
{
    public:
        Node *root;

        TernaryTree()
        {
            root = NULL;
        }

        TernaryTree &insert(string key,const int &val)
        {
            root = insertNode(key,val,root,0);
        }

        Node *insertNode(string key,const int &val,Node *node,int index)
        {
            char c = key[index];
            if(node == NULL)
            {
                node = new Node(c);
            }
            if(c < node->data)
            {
                node->left = insertNode(key,val,node->left,index);
            }
            else if(c > node->data)
            {
                node->right = insertNode(key,val, node->right,index);
            }
            else if(index < key.length()-1)
            {
                node->middle = insertNode(key,val, node->middle, index+1);
            }
            else
            {
                node->keyvalue = val;
            }
            return node;
        }

        int getval(string key)
        {
            Node *node = getvalueNode(key,root,0);
            if(node == NULL)
            {
                return -1;
            }
            else
            {
                return node->keyvalue;
            }
        }

        Node *getvalueNode(string key,Node *node,int index)
        {
            char c = key[index];
            if(node == NULL)
            {
                return NULL;
            }
            if(c < node->data)
            {
                return getvalueNode(key,node->left,index);
            }
            else if(c > node->data)
            {
                return getvalueNode(key,node->right,index);
            }
            else if(index < key.length()-1)
            {
                return getvalueNode(key,node->middle,index+1);
            }
            else
            {
                return node;
            }
        }
};




int main()
{
TernaryTree trie;
string input_string,get_string;
int value,n;
cout << "Enter the number of contacts that need to saved.." << endl;
cin >> n;
for(int i=0; i<n; i++)
{
    cout << "Enter the name:" << endl;
    cin >> input_string;
    cout << "Phone Number.." << endl;
    cin >> value;
    trie.insert(input_string,value);
}

int m;
cout << "Enter the number of contacts that you need to search.." << endl;
cin >> m;
for(int i=0; i<n; i++)
{
    cout << "Enter the name to get his number.." << endl;
    cin >> get_string;
    cout << trie.getval(get_string);
    cout << endl;
}



    return 0;
}
