#include<iostream>
#include<fstream>
using namespace std;
struct node{
     node *left;
     int info;
     node *right;
};
node *root=NULL;  // Initialy root is NULL

// Function to create full binary tree
//Here "l" and "r" are storing the lower and higher index of subarray respectively
//Here integer variable "index" is used to traverse preorder expression
node *createtree(int preorder[],int postorder[],int size,int *index,int l,int r){
	if(*index>=size||l>r)
		return NULL;
	
	node *root=new node;
	root->info=preorder[*index];
	root->left=NULL;
	root->right=NULL;
	++*index;
	//If there is one element in the tree no need to proceed further
	if(l==r)
		return root;
	//Searching the next value of preorder in postorder 
	int i;
	for(i=l;i<=r;i++)
	  if(preorder[*index]==postorder[i])
			break;		
	// Dividing the postorder expression in two parts ,left subtree and right subtree from index "i"
	  
	  if(i<=r){
	  	root->left=createtree(preorder,postorder,size,index,l,i);
	  	root->right=createtree(preorder,postorder,size,index,i+1,r);
	  }
	
	
	return root;
}

//Function to traverse tree(Inorder)
int inorder1[100];
int t=0;
int insert(int val){
	inorder1[t]=val;
	t++;
}
node *inorder(node *root){

	int i=0; 
	node *ptr=root;
	if(ptr==NULL)
		return root;
	inorder(ptr->left);
	cout<<ptr->info<<" ";
	insert(ptr->info);
	inorder(ptr->right);
}

//Driver Function main
int main(){
	int preorder[100],postorder[100],n,pre=0,post=0,x;  
	ifstream file1,file2;  
	ofstream file3;
	
	int index=0;
	//Taking preorder expression from file "preorder.txt"
	cout<<"\n Reading Preorder Expression from Preorder.txt";
	file1.open("preorder.txt");
	while(!file1.eof()){
		file1>>preorder[pre];
		pre++;
	}
	n=pre;
	
	//Taking postorder expression from file "postorder.txt"
	cout<<"\n Reading Postorder from Postorder.txt";
	file2.open("postorder.txt");
	while(!file2.eof()){
		file2>>postorder[post];
		post++;
	}
	//Function call to create full binary tree
	root=createtree(preorder,postorder,n,&index,0,n-1);
	cout<<"\n Full binary tree is created!!";
	//Inorder Traversal to check whether tree formed is right or wrong
	cout<<"\n Inorder Traversal: ";
	root=inorder(root);
	
	file3.open("inorder.txt"); 
	for(int i=0;i<n;i++){
		
		file3<<inorder1[i];
		file3<<" ";
	}
	cout<<" is saved in file inorder.txt";
}
