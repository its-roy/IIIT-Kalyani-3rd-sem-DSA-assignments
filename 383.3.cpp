#include <bits/stdc++.h>
#include <cstring>
using namespace std;

char circ_queue[3];
int front = -1,rear = -1;




void dequeue() {
	
	cout << "Dequeing the element: ";
	cout << circ_queue[front];
	cout << "\n";	
	if(front == rear) {
		front = -1;
		rear = -1;
	}
	if(front == 2)
		front = -1;
	front = front + 1;
	return;	
}

void enqueue(char signal) {
	if((rear - front == 2) || (front == rear + 1)){
		dequeue();
	}
	cout << "Enqueuing the element: ";
	cout << signal;
	cout << "\n";
	if(front == -1)
		front = 0;
	if(front > 0 && rear == 2)
		rear = -1;
	rear = rear + 1;
	circ_queue[rear] = signal;
}

void display() {
	if(front<rear){
		for(int i=front;i<=rear;i++){
			cout << circ_queue[i];
			cout << " ";
		}
	}
	else{
		for(int i = 0;i<front;i++){
			cout << circ_queue[i];
			cout << " ";
		}
		for(int i = front;i<n;i++){
			cout << circ_queue[i];
			cout << " ";
		}
	}
}


int main() {
	int choice;
	
	char input[30];
	cin >> input;
	for(int i = 0;i < strlen(input);i++) {
		enqueue(input[i]);
		display();
		cout<<"\n";
	}
	
	return 0;
}



