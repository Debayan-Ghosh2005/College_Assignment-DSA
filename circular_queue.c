#include <stdio.h>
#include<stdlib.h>  
# define max 3
int queue[max]; 
int front=-1; 
int rear=-1;  
void enqueue(int element) 
{
  if(front==-1 && rear==-1) 
  {
  	front=0; 
    rear=0; 
    queue[rear]=element; 
  } 
  else if((rear+1)%max==front)
  {
    printf("OVERFLOW..\n"); 
  } 
  else 
  {
  	rear=(rear+1)%max;
    queue[rear]=element; 
  } 
} 
int dequeue() 
{
	if((front==-1) && (rear==-1)) 
	{
		printf("UNDERFLOW..\n"); 
	 } 
    else if(front==rear) 
    { 
        printf("The dequeued element is %d\n", queue[front]); 
        front=-1; 
        rear=-1; 
    } 
	else 
	{ 
 		printf("The dequeued element is %d\n", queue[front]); 
 		front=(front+1)%max; 
 	}	 
} 
void display() 
{
	int i=front; 
	if(front==-1 && rear==-1) 
	{ 
		printf("EMPTY QUEUE...\n"); 
    } 
	else 
	{ 
		printf("Elements in a Queue are: \n"); 
		while(i<=rear) 
		{ 
			printf("%d\n", queue[i]); 
			i=(i+1)%max; 
 		} 
 	} 
} 
int main() 
{ 
	int choice=1,x; 
 	while(1) 
	{ 
		printf("\nMenu\n1. Insert an element \n2. Delete an element \n3. Display the elements\n4. Exit"); 
 		printf("\nEnter your choice: "); 
 		scanf("%d", &choice);  
 		switch(choice) 
 		{  
 			case 1:  
			printf("Enter the element which is to be inserted: "); 
			scanf("%d", &x); 
 			enqueue(x); 
  			break; 
 			case 2:
			dequeue(); 
 			break; 
 			case 3: 
			display();
			break;
			case 4: 
			printf("Exit Point");
			exit(0);
			break; 
 			default: 
			 printf("Invalid choice. Please try again.\n");   
 			}
	} 
 	return 0; 
 }