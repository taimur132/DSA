#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create(int data) {
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

int count(node* head) {
    if (head == NULL) {
        return 0;
    }

    int c = 0;
    node* temp = head->next;
    c++;

    while (temp != head) {
        c++;
        temp = temp->next;
    }

    return c;
}

void insertBegin(node** head, int data) {
    node* newnode = create(data);

    if (*head == NULL) {
        newnode->next = newnode;  // Circular link for the first node
    } else {
        node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode;  // Link the last node to the new node
        newnode->next = *head; // Make the new node the new head
    }

    *head = newnode; // Update the head pointer
    printf("%d is inserted at begin.\n", data);
}

void insertEnd(node** head, int data) {
    node* newnode = create(data);

    if (*head == NULL) {
        newnode->next = newnode; // Circular link for the first node
        *head = newnode;         // Update the head pointer
    } else {
        node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode;  // Link the last node to the new node
        newnode->next = *head; // Make the new node part of the circular list
    }

    printf("%d is inserted at end.\n", data);
}

void insert_before_position(node** head, int pos, int data) {
    int c = count(*head);
    if (pos > c) {
        printf("Invalid position!\n");
    } else {
        int i = 1;
        node* temp, * newnode;
        temp = *head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode = create(data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("%d is inserted before position %d.\n", data, pos);
}

void insert_after_position(node** head, int pos, int data) {
    int c = count(*head);
    if (pos > c) {
        printf("Invalid position!\n");
    } else {
        int i = 1;
        node* temp, * newnode;
        temp = *head;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        newnode = create(data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("%d is inserted after position %d.\n", data, pos);
}

void deleteBegin(node** head) {
    if (*head == NULL) {
        printf("Empty list.\n");
    } else {
        node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next; // Update the link of the last node
        printf("%d is deleted from beginning.\n", (*head)->data);
        free(*head);
        *head = temp->next; // Update the head pointer
    }
}

void deleteEnd(node** head) {
    if (*head == NULL) {
        printf("Empty list.\n");
    } else {
        node* temp = *head;
        while (temp->next->next != *head) {
            temp = temp->next;
        }
        printf("%d is deleted from end.\n", temp->next->data);
        free(temp->next);
        temp->next = *head; // Update the link of the last node
    }
}

void delete_at_position(node** head, int pos) {
    int c = count(*head);
    if (*head == NULL) {
        printf("Empty list.\n");
    } else if (pos > c) {
        printf("Invalid position!\n");
    } else {
        node* temp, * prenode;
        temp = *head;
        int i = 1;
        while (i < pos) {
            prenode = temp;
            temp = temp->next;
            i++;
        }
        printf("%d is deleted from position %d.\n", temp->data, pos);
        prenode->next = temp->next;
        free(temp);
    }
}

void update_at_position(node** head, int pos, int data) {
    int c = count(*head);
    if (*head == NULL) {
        printf("Empty list.\n");
    } else if (pos > c) {
        printf("Invalid position!\n");
    } else {
        int i = 1;
        node* temp;
        temp = *head;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        temp->data = data;
        printf("Position %d is updated with value %d.\n", i, data);
    }
}

void display(node* head) {
    node* temp;
    temp = head;
    if (head == NULL) {
        printf("Empty list.\n");
    } else {
        printf("The elements are: \n");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    int choice;
    node* head = NULL;
    while (1) {
        printf("Enter your choice : 1. for insertBegin, 2. for insertEnd, 3. for insert_before_position,\n");
        printf("4. for insert_after_position 5. for deleteBegin, 6. for deleteEnd,\n");
        printf("7. for delete_at_position, 8. for update_at_position, 9. for display, 10. for exit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int data;
                printf("Enter the element you want to insert at begin:\n");
                scanf("%d", &data);
                insertBegin(&head, data);
            } break;
            case 2: {
                int data;
                printf("Enter the element you want to insert at end:\n");
                scanf("%d", &data);
                insertEnd(&head, data);
            } break;
            case 3: {
                int pos, data;
                printf("Enter the position and data:\n");
                scanf("%d %d", &pos, &data);
                insert_before_position(&head, pos, data);
            } break;
            case 4: {
                int pos, data;
                printf("Enter the position and data:\n");
                scanf("%d %d", &pos, &data);
                insert_after_position(&head, pos, data);
            } break;
            case 5: deleteBegin(&head); break;
            case 6: deleteEnd(&head); break;
            case 7: {
                int pos;
                printf("Enter the position to delete element:\n");
                scanf("%d", &pos);
                delete_at_position(&head, pos);
            } break;
            case 8: {
                int data, pos;
                printf("Enter position and data for updation.\n");
                scanf("%d %d", &pos, &data);
                update_at_position(&head, pos, data);
            } break;
            case 9: display(head); break;
            case 10: exit(0); break;
            default: printf("Wrong Input!\n");
        }
    }
    return 0;
}
