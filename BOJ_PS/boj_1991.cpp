#include <iostream>
using namespace std;
 
struct node{
    char left;
    char right;
};
 
struct node arr[31];
 
void preorder(char root){
    if(root == '.')
        return;
    printf("%c",root);
    preorder(arr[root].left);
    preorder(arr[root].right);
}
 
void inorder(char root){
    if(root == '.')
        return;
    inorder(arr[root].left);
    printf("%c",root);
    inorder(arr[root].right);
}

void postorder(char root){
    if(root == '.')
        return;
    postorder(arr[root].left);
    postorder(arr[root].right);
    printf("%c",root);
}
 
int main() {
	int n;
    cin>>n;
    char a, b, c;
    
    for(int i = 1; i <= n; i++){
		cin>>a>>b>>c;
        arr[a].left = b;
        arr[a].right = c;
    }
    preorder('A');
	cout<<'\n';
    inorder('A');
	cout<<'\n';
    postorder('A');
}