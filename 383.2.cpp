#include<iostream>
using namespace std;

char queue[3];
int front=-1;
int rear=-1;

void enqueue(char ch)
{

  if (rear == 3 - 1)
  {
    printf("\nQueue is Full");
    return;
  }
    if (front == -1)
      front = 0;
    rear++;
    queue[rear]=ch;
    cout<<" Entered signal "<<ch<<endl;
    
}
void dequeue() 
{
  if (front == -1)
    printf("\nQueue is Empty!!");
  else 
  {
    cout<<queue[front]<<endl;
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

int main()
{
    char inp[10];
    int len=0;
    cout<<"Enter the signals"<<endl;
    cin>>inp;
    for(int i=0;inp[i]!='\0';i++)
        len++;
    int flag=0;
    for(int i=0;i<len/3+1;i++)
    {
        if((len-flag)/3>=1)
        {
            for(int j=0;j<3;j++)
            {
                enqueue(inp[flag]);
                flag++;
            }
            for(int k=0;k<3;k++)
                dequeue();
        }
        else
        {
            for(int j=0;j<len%3;j++)
            {
                enqueue(inp[flag]);
                flag++;
            }
            for(int k=0;k<len%3;k++)
                dequeue();
        }
    }
    return 0;
    
}