#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

static string expr;

bool areParanthesisBalanced() 
{ 
    stack<char> s; 
    char x; 

    for (int i = 0; i < expr.length(); i++) { 
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') { 
      
            s.push(expr[i]); 
            continue; 
        } 
  
       
        if (s.empty()) 
            return false; 
  
        switch (expr[i]) { 
        case ')': 
            x = s.top(); 
            s.pop(); 
            if (x == '{' || x == '[') {
            	cout<<"Mismatch at Position : "<<i<<endl;
                if (x=='{')
                {
                	expr[i]='}';
                }
                else
                {
                	expr[i]=']';
                }
            }
            break; 
  
        case '}': 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '[') {
            	cout<<"Mismatch at Position : "<<i<<endl;
            	if (x=='(')
                {
                	expr[i]=')';
                }
                else
                {
                	expr[i]=']';
                }
                 
            }
            break; 
  
        case ']': 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{') {
            	cout<<"Mismatch at Position : "<<i<<endl;
            	if (x=='{')
                {
                	expr[i]='}';
                }
                else
                {
                	expr[i]=')';
                }
                
            }
            break; 
        } 
    } 
  
    return (s.empty()); 
} 
  

int main() 
{ 
    cout<<endl<<"Enter Sample Input:"<<endl;
    cin>>expr;
  
    if (areParanthesisBalanced()){ 
        cout << "Balanced"<<endl; 
    }
    else{
        cout << "Not Balanced"<<endl; 
    }
    cout<<"Balanced equation : "<<endl;

    cout<<expr<<endl;

    return 0; 
}