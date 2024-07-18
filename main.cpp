#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right; //struct
};

struct Node* NewNode(int data){
    struct Node* temp = (struct Node *)malloc(sizeof(Node));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

struct Node* Reconstruct(int Postorder[], int* PostIndex, int Key, int min, int max, int size){
    if(*PostIndex < 0) return NULL;

    struct Node* root = NULL;

    if(Key > min && Key < max){
        root = NewNode(Key);
        *PostIndex = *PostIndex - 1;

        if(*PostIndex >=0){
            root->left = Reconstruct(Postorder, PostIndex, Postorder[*PostIndex], min, Key , size);
            root->right = Reconstruct(Postorder, PostIndex, Postorder[*PostIndex], Key, max , size);
        }
    }
    return root;
}

struct Node *ConstructTree(int Postorder[], int size){
    int PostIndex = size-1;
    return Reconstruct(Postorder, &PostIndex, Postorder[PostIndex], -500, 1000, size);
}

void PrintInorder(struct Node* node){
    if(node == NULL) return;
    PrintInorder(node->left);
    cout << node->data << " "; //outfile
    PrintInorder(node->right);
}

int main(){
    int TreeNum;
    cin >> TreeNum; //infile
    for(int i=1;i<=TreeNum;i++){
        int NodeNum;
        cin >> NodeNum;
        int Postorder[NodeNum];
        int size = sizeof(Postorder) / sizeof(Postorder[0]);

        struct Node *root = ConstructTree(Postorder, size);

        PrintInorder(root);
    }
    return 0;
}
