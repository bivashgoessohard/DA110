#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Queue {
    char data[50];
    struct Queue *next;
} Queue;

/* Special Queue */
Queue *specialHead = NULL;
Queue *specialTail = NULL;

/* Level Queues */
Queue *head1 = NULL, *tail1 = NULL;
Queue *head2 = NULL, *tail2 = NULL;
Queue *head3 = NULL, *tail3 = NULL;
Queue *head4 = NULL, *tail4 = NULL;
Queue *head5 = NULL, *tail5 = NULL;

void traverse(Queue *head) {
    Queue *ptr = head;

    while (ptr != NULL) {
        printf("%s -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

void enqueue(Queue **head, Queue **tail, const char *id) {

    Queue *newNode = malloc(sizeof(Queue));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(newNode->data, id);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void dequeue(Queue **head, Queue **tail) {
    if (*head == NULL)
        return;
    
    Queue *ptr = *head;
    *head = (*head)->next;

    if (*head == NULL)
        *tail = NULL;

    free(ptr);
    
}

void addPatient(const char *id, int level, char time[], bool special) {

    if (level < 1 || level > 5) {
        printf("Invalid critical level.\n");
        return;
    }

    if (special) {
        enqueue(&specialHead, &specialTail, id);
        return;
    }

    switch (level) {

        case 1:
            enqueue(&head1, &tail1, id);
            break;

        case 2:
            enqueue(&head2, &tail2, id);
            break;

        case 3:
            enqueue(&head3, &tail3, id);
            break;

        case 4:
            enqueue(&head4, &tail4, id);
            break;

        case 5:
            enqueue(&head5, &tail5, id);
            break;
    }
}

char *treatPatient()
{
    static char patientID[50];

    if (specialHead != NULL)
    {
        strcpy(patientID, specialHead->data);
        dequeue(&specialHead, &specialTail);
        return patientID;
    }
    else if (head5 != NULL)
    {
        strcpy(patientID, head5->data);
        dequeue(&head5, &tail5);
        return patientID;
    }
    else if (head4 != NULL)
    {
        strcpy(patientID, head4->data);
        dequeue(&head4, &tail4);
        return patientID;
    }
    else if (head3 != NULL)
    {
        strcpy(patientID, head3->data);
        dequeue(&head3, &tail3);
        return patientID;
    }
    else if (head2 != NULL)
    {
        strcpy(patientID, head2->data);
        dequeue(&head2, &tail2);
        return patientID;
    }
    else if (head1 != NULL)
    {
        strcpy(patientID, head1->data);
        dequeue(&head1, &tail1);
        return patientID;
    }

    return NULL;
}


char *peekNextPatient()
{
    if (specialHead != NULL)
        return specialHead->data;

    else if (head5 != NULL)
        return head5->data;

    else if (head4 != NULL)
        return head4->data;

    else if (head3 != NULL)
        return head3->data;

    else if (head2 != NULL)
        return head2->data;

    else if (head1 != NULL)
        return head1->data;

    return NULL;
}


void removeFromQueue(Queue **head, Queue **tail, const char *id)
{
    Queue *curr = *head;
    Queue *prev = NULL;

    while (curr != NULL)
    {
        if (strcmp(curr->data, id) == 0)
        {
            /* deleting head */
            if (prev == NULL)
            {
                *head = curr->next;

                if (*head == NULL)
                    *tail = NULL;
            }
            else
            {
                prev->next = curr->next;

                if (curr == *tail)
                    *tail = prev;
            }

            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}


void removePatient(const char *id)
{
    removeFromQueue(&specialHead, &specialTail, id);
    removeFromQueue(&head5, &tail5, id);
    removeFromQueue(&head4, &tail4, id);
    removeFromQueue(&head3, &tail3, id);
    removeFromQueue(&head2, &tail2, id);
    removeFromQueue(&head1, &tail1, id);
}


int main(void)
{
    addPatient("P1", 3, "09:00", false);
    addPatient("P2", 5, "09:05", false);
    addPatient("P3", 2, "09:10", false);
    addPatient("P4", 4, "09:15", true);

    printf("Initial Queues:\n");

    printf("Special Queue: ");
    traverse(specialHead);

    printf("Level 5 Queue: ");
    traverse(head5);

    printf("Level 4 Queue: ");
    traverse(head4);

    printf("Level 3 Queue: ");
    traverse(head3);

    printf("Level 2 Queue: ");
    traverse(head2);

    printf("Level 1 Queue: ");
    traverse(head1);

    printf("\n");

    printf("peekNextPatient() -> %s\n", peekNextPatient());

    printf("treatPatient() -> %s\n", treatPatient());

    printf("peekNextPatient() -> %s\n", peekNextPatient());

    printf("\nRemoving P2...\n");
    removePatient("P2");

    printf("peekNextPatient() -> %s\n", peekNextPatient());

    printf("treatPatient() -> %s\n", treatPatient());

    printf("\nFinal Queues:\n");

    printf("Special Queue: ");
    traverse(specialHead);

    printf("Level 5 Queue: ");
    traverse(head5);

    printf("Level 4 Queue: ");
    traverse(head4);

    printf("Level 3 Queue: ");
    traverse(head3);

    printf("Level 2 Queue: ");
    traverse(head2);

    printf("Level 1 Queue: ");
    traverse(head1);

    return 0;
}