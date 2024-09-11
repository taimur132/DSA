//double endedd queue , deletion restricted
#include<stdio.h>
#include<stdlib.h>
#define N 5
int deque[N];
int front=-1;
int rear=-1;

int isFull(){//checking if the deque is full or not
    if((front==0&&rear==N-1)&&(front==rear+1))
    return 1;
    else 
    return 0;
}

int isEmpty(){//checking if the deque is empty or not
    if(front==-1&&rear==-1)
    return 1;
    else 
    return 0;
}

void enqueueFront(int n){//inserting element at front
    if(isFull()==1){
        printf("Deque is full.\n");
    }else if(isEmpty()==1){
        front=rear=0;
        deque[front]=n;
        printf("%d is inserted at front.\n",n);
    }else if(front==0){
        front=N-1;
        deque[front]=n;
        printf("%d is inserted at front.\n",n);
    }else{
        front--;
        deque[front]=n;
        printf("%d is inserted at front.\n",n);
    }
}

void enqueueRear(int n){//inserting element at rear
    if(isFull()==1){
        printf("Deque is full.\n");
    }else if(isEmpty()==1){
        front=rear=0;
        deque[front]=n;
        printf("%d is inserted at rear.\n",n);
    }else if(rear==N-1){
        rear=0;
        deque[rear]=n;
        printf("%d is inserted at rear.\n",n);
    }else{
        rear++;
        deque[rear]=n;
        printf("%d is inserted at rear.\n",n);
    }
}

void dequeuefront(){//deletion element from front
    if(isEmpty()==1){
        printf("Deque is empty.\n");
    }else if(front==rear){
        printf("The deleted element is %d .\n",deque[front]);
    }else if(front==N-1){
        printf("The deleted element is %d .\n",deque[front]);
        front=0;
    }else{
        printf("The deleted element is %d .\n",deque[front]);
        front+=1;
    }
}

void peekFront(){//displaying element at front
    if(isEmpty()==1){
        printf("Deque is empty.\n");
    }else{
        printf("The element at front is %d .\n",deque[front]);
    }
}

void peekRear(){//displaying element at rear
    if(isEmpty()==1){
        printf("Deque is empty.\n");
    }else{
        printf("The element at rear is %d .\n",deque[rear]);
    }
}

void display(){//displaying elements in deque
    if(isEmpty()==1){
        printf("Queue is empty.\n");
    }else{
        printf("Elements of the deque are :\n");
        int i=front;
        while(i!=(rear+1)%N){
            printf("%d ",deque[i]);
            i=(i+1)%N;
        }
        /*do{
            printf("%d ",deque[i]);
            i=(i+1)%N;
        }while(i!=(rear+1)%N);*/
        printf("\n");
    }
}

int main(){//driver function
    int choice;
    while(1){
        printf("Enter your choice : 1. for enqueue at front, 2. for enqueue at rear, 3. for dequeue from front,\n 4. for peek from front, 5. for peek from rear, 6. for display, 7. for exit.\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : {
                int num;
                printf("Enter element to insert at front : \n");
                scanf("%d",&num);
                enqueueFront(num);
            }
            break;
            case 2 : {
                int num;
                printf("Enter element to insert at rear : \n");
                scanf("%d",&num);
                enqueueRear(num);
            }
            break;
            case 3 : dequeuefront();
            break;
            case 4 : peekFront();
            break;
            case 5 : peekRear();
            break;
            case 6 : display();
            break;
            case 7 : exit(0);
            break;
            default : printf("Wrong Input !\n");
        }
    }
    return 0;
}
