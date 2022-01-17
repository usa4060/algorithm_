#include <iostream>
#define MAX 27
using namespace std;
int N;

class Node{
    Node*root = NULL;
public:
    char data;
    Node* left;
    Node* right;
    Node(){
        this->data = '\0';
        this->left = NULL;
        this->right = NULL;
    }
};



void preOrder(Node* n){
    if(n != NULL){
        cout<<n->data;
        preOrder(n->left);
        preOrder(n->right);
    }
}

void inOrder(Node* n){
    if(n != NULL){
        inOrder(n->left);
        cout<<n->data;
        inOrder(n->right);
    }
}

void postOrder(Node* n){
    if(n != NULL){
        postOrder(n->left);
        postOrder(n->right);
        cout<<n->data;
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Node node[MAX];
    cin>>N;
    
    for(int i = 1; i <= N; i++){
        char parent, left, right;
        cin>>parent>>left>>right;
        node[parent-'A'].data = parent;
        
        if(left != '.'){
            node[parent-'A'].left = &node[left-'A'];
            node[parent-'A'].left->data = left;
        }
        if(right != '.'){
            node[parent - 'A'].right = &node[right-'A'];
            node[parent-'A'].right->data = right;
        }
    }
    preOrder(&node[0]);
    cout<<'\n';
    inOrder(&node[0]);
    cout<<'\n';
    postOrder(&node[0]);
    cout<<'\n';
}
