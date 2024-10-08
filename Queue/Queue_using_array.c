//Queue using array
#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1,rear=-1;

int isFull(){//checking if the queue is full or not
    if(rear==N-1)
    return 1;
    else
    return 0;
}

int isEmpty(){//cheching if the queue is empty or not
    if(front==-1&&rear==-1)
    return 1;
    else
    return 0;
}

void enqueue(int n){//inserting elements in the queue
    if(isFull()==1){
        printf("Queue is full.\n");
    }else if(isEmpty()==1){
        front=rear=0;
        queue[rear]=n;
        printf("%d is insertedd in the queue.\n",n);
    }else{
        rear+=1;
        queue[rear]=n;
        printf("%d is insertedd in the queue.\n",n);
    }
}

void dequeue(){//deletion of elements from the queue
    if(isEmpty()==1){
        printf("Queue is empty.\n");
    }else if(front==rear){
        printf("Deleted element is %d .\n",queue[front]);
        front=rear=-1;
    }else{
        printf("Deleted element is %d .\n",queue[front]);
        front+=1;
    }
}

void peek(){//peeking element from the front of the queue
    if(isEmpty()==1){
        printf("Queue is empty.\n");
    }else{
        printf("The peeked element from front is %d .\n",queue[front]);
    }
}

void display(){//displaying all the elements in the queue (front to rear)
    if(isEmpty()==1){
        printf("Queue is empty.\n");
    }else{
        printf("Elements of the queue are :\n");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main(){//driver function
    int choice;
    while(1){
        printf("Enter your choice : 1. for enqueue, 2. for dequeue, 3. for peek, 4. for display, 5. for exit.\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 : {
            int num;
            printf("Enter number to push :\n");
            scanf("%d",&num);
            enqueue(num);
        }
        break;
        case 2 : dequeue();
        break;
        case 3 : peek();
        break;
        case 4 : display();
        break;
        case 5 : exit(0);
        break;
        default : printf("Wrong Input !\n");
    }
    }
    return 0;
}
