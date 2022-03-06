#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Node*makeNode(int data){
    Node*newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node*head, int data){// This function uses Recursion to Insert
    if(head == NULL){head = makeNode(data);}
    if(data <= head->data){insertNode(head->left,data);}else{
        head->right = insertNode(head->right,data);
    }
    return head;
}

bool SearchNode(Node*head,int data){// This function uses Recursion to Search
    if(head == NULL) return false;
    else if(head->data == data){return true;}
    else if(data <= head->data) return SearchNode(head->left,data);
    else return SearchNode(head->right,data);
}

Node* search(Node*head, int data){
    if(head == NULL){
        return NULL;
    }
    queue<Node*>q;// stack = Depth and queue = breadth
    Node*out;
    q.push(head);
    
    // Pre  order Traversal : Node Left Right
    // In   order Traversal : Left Node Right
    // Post order Traversal : Left Right Node
    
    while(!q.empty()){
        Node*temp = q.front();
        q.pop();
        if(temp->left != NULL){q.push(temp->left);}
        if(temp->data == data){out = temp;cout << " Data Found : "<< endl;}
        if(temp->right != NULL){q.push(temp->right);}
    }
    return out;
}

void insert(Node*head, int data){
    Node*insertNode = makeNode(data);
    if(head == NULL){
        head = insertNode;  
    }
    
    queue<Node*> q;
    q.push(head);

    while(!q.empty()){
        Node*temp = q.front();
        q.pop();
        if(temp->left == NULL){
            temp->left = insertNode;
            return;
        }else{
            q.push(temp->left);

        }
        if(temp->right == NULL){
            temp->right = insertNode;
            return;
        }else{
            q.push(temp->right);

        }
    }
}

Node* minNode(Node*head){// This function id used in DeleteNode
    while(head->left != NULL){
                head = head->left;
            }
            return head;
}

Node* DeleteNode(Node* head, int data) {
    if(head == NULL){return NULL;}
    else if(data < head->data){head->left = DeleteNode(head->left, data);}
    else if(data > head->data){head->right = DeleteNode(head->right, data);}
    else{
        // Case 1: No Child
        if(head->left == NULL && head->right == NULL){ 
            delete head; head == NULL;
        }// Case 2: One Child
        else if(head->left == NULL){
            Node*temp = head;
            head = head->right;
            delete temp;
        }
        else if(head->right == NULL){
            Node*temp = head;
            head = head->left;
            delete temp;
        }// Case 3: Two Children
        else{
            
            Node*temp = minNode(head->right);
            head->data = temp->data;
            head->right = DeleteNode(head->right,temp->data);
        }
    }
    return head;
}

int main(){
    //Trees : recursive data structures. root and subtrees. root,parent, children,siblings, leaf and internal.
    // N nodes has n - 1 edges. depth of node : length of path Height: no. of edges in longest path  
    // Binary tree: a tree in which each node has 2 children using pointers(linked list) frame[left child, data, right child]
    // Applications : hierarchical data, quick search, insertion, deletion, tries, network routing algorithm
    // Enumeration : 2n!/ (n+1)n! 
    //            10
    //        4        20 
    //     2    9   15    25
    //
    
    Node* root = makeNode(10);
    root->left = makeNode(4);
    root->left->left = makeNode(2);
    root->left->right = makeNode(9);
    root->right = makeNode(20);
    root->right->right = makeNode(25);
    root->right->left = makeNode(15);

    system("pause>0");
    return 0;
}
