//Stack using array
#include<stdio.h>
#include<stdlib.h>
# define N 5
int stack[N];
int top=-1;

int isEmpty(){//checking if the stack is empty or not
    if(top==-1)
    return 1;
    else 
    return 0;
}

int isFull(){//checking if the stack is full or not
    if(top==N-1)
    return 1;
    else
    return 0;
}

void push(int num){//pushing element in stack at top
    if(isFull()==1){
        printf("Stack Overflow !\n");
    }else{
        top+=1;
        stack[top]=num;
        printf("%d is pushed in stack\n",num);
    }
}

void pop(){//poping element from the top of the stack
    int temp;
    if(isEmpty()==1){
        printf("Stack Underflow !\n");
    }else{
        temp=stack[top];
        top-=1;
        printf("The poped value is %d\n",temp);
    }
}

void peek(){//peeking and showing the element in stack at top
    if(isEmpty()==1){
        printf("Stack is empty.\n");
    }else{
        printf("The peeked element is %d\n",stack[top]);
    }
}

void display(){//displaying all the elements in the stack, last in first out (LIFO) order
    if(isEmpty()==1){
        printf("Stack is empty.\n");
    }else{
        int i;
        printf("Elements of the stack are (in LIFO order) :\n");
        for(i=top;i>=0;i--){
        printf("%d ",stack[i]);
        }
    }
}

int main(){//driver function
    int choice;
    while(1){
        printf("Enter your choice : 1. for push, 2. for pop, 3. for peek, 4. for display, 5. for exit.\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 : {
            int num;
            printf("Enter number to push :\n");
            scanf("%d",&num);
            push(num);
        }
        break;
        case 2 : pop();
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

