#include<iostream>
using namespace std;
struct node{
	node *left;
	int val;
	node *right;
};
node *root=NULL;
node *insert(node *n,int k){
	n->val=k;	
	n->left=NULL;
	n->right=NULL;		
	node *ptr=root;
	node *save=root;	
	if(root==NULL){
		root=n;	
	}else{
		while(ptr!=NULL){
		     if(n->val<ptr->val){
		     	save=ptr;
			ptr=ptr->left;	
                     }else{
		     	save=ptr;
			ptr=ptr->right;
                     }		
		}
	        
		if(n->val<save->val){
			save->left=n;		
		}else{
			save->right=n;		
		}		
	}
}
int find(int k){
	node *ptr=root;	
	if(root==NULL){
		cout<<"\n The Binary Search Tree is Empty";
		return 0;	
	}else{
	    while(ptr!=NULL){		
		if(ptr->val==k){
			cout<<"\n Number found..";
			return 0;		
		}else if(k<ptr->val){
			ptr=ptr->left;		
		}else{
			ptr=ptr->right;		
		}
            }
	    return 0;	
	}
	
}
node *print(node *ptr){
	if(ptr==NULL){
		return root;	
	}else{
		print(ptr->left);
		cout<<ptr->val<<" ";
		print(ptr->right);	
	}
}
int main(){
        int k,num,x;
        char c='y';
	while(k!=-1){
           cout<<"\n Enter a number to insert: ";
	   cin>>k;
	   if(k!=-1){
            node *newp;
	    newp=new node;
	    insert(newp,k);
           }
	}

		
		
	while(c=='Y'||c=='y'){	
                cout<<"\n1. Search a number: ";
                cout<<"\n2. Print the BST: ";	
		cin>>num;
		switch(num){
			case 1:
				cout<<"\n Enter a number to search: ";
				cin>>x;
				find(x);
				break;
                	case 2: 
				print(root);	
				break;
		}
		cout<<"\n Do you want to continue: ";
		cin>>c;
	}
	

}
