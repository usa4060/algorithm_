//#include <iostream>
//using namespace std;
//int num = 15;
//
//typedef struct node *treePointer;
//typedef struct node {
//    int data;
//    treePointer leftChild, rightChild;
//};
//
//void preorder(treePointer ptr){
//    if(ptr){
//        cout<<ptr->data;
//        preorder(ptr->leftChild);
//        preorder(ptr->rightChild);
//    }
//}
//
//
//void inorder(treePointer ptr){
//    if(ptr){
//        inorder(ptr->leftChild);
//        cout<<ptr->data;
//        inorder(ptr->rightChild);
//    }
//}
//
//void postorder(treePointer ptr){
//    if(ptr){
//        postorder(ptr->leftChild);
//        postorder(ptr->rightChild);
//        cout<<ptr->data;
//    }
//}
//
//
//
//int main(){
//    node nodes[num+1];
//    for(int i = 1; i <= num; i++){
//        nodes[i].data = i;
//        nodes[i].leftChild = NULL;
//        nodes[i].rightChild = NULL;
//    }
//
//    for(int i = 1; i <= num; i++){
//        if(i % 2 == 0){
//            nodes[i/2].leftChild = &nodes[i];
//        }
//        else{
//            nodes[i/2].rightChild = &nodes[i];
//        }
//    }
//
//    preorder(&nodes[1]);
//}

#include <iostream>
using namespace std;



class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(){
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
};


void preorder(Node* ptr){
    if(ptr != NULL){
    cout<<ptr->data<<' ';
    preorder(ptr->left);
    preorder(ptr->right);
    }
}




int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Node node[15];
    
    for(int i = 1; i < 15; i++){
        node[i].data = i;
        if(i % 2 == 0){
            node[i/2].left = &node[i];
        }
        else{
            node[i/2].right = &node[i];
        }
    }
    
    preorder(&node[1]);
}



















