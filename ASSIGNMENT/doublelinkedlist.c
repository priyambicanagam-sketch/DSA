#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char page[50];
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *current = NULL;
void insertPage()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter page name: ");
    scanf("%49s", newNode->page);
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        current = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        current = newNode;
    }
    printf("Page added successfully\n");
}
void moveForward()
{
    if (current == NULL)
    {
        printf("No pages available\n");
    }
    else if (current->next == NULL)
    {
        printf("Already at the last page\n");
    }
    else
    {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}
void moveBackward()
{
    if (current == NULL)
    {
        printf("No pages available\n");
    }
    else if (current->prev == NULL)
    {
        printf("Already at the first page\n");
    }
    else
    {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}
void deletePage()
{
    char name[50];
    struct Node *temp;
    printf("Enter page name to delete: ");
    scanf("%49s", name);
    temp = head;
    while (temp != NULL && strcmp(temp->page, name) != 0)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Page not found\n");
        return;
    }
    if (temp == head)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
    }
    if (temp == tail)
    {
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
    }
    else if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (current == temp)
    {
        current = head;
    }
    free(temp);
    printf("Page deleted successfully\n");
    if (head == NULL)
    {
        tail = NULL;
        current = NULL;
    }
}
void displayForward()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("No pages available\n");
        return;
    }
    printf("Pages from first to last:\n");
    while (temp != NULL)
    {
        printf("%s ", temp->page);
        temp = temp->next;
    }
    printf("\n");
}
void displayBackward()
{
    struct Node *temp = tail;
    if (tail == NULL)
    {
        printf("No pages available\n");
        return;
    }
    printf("Pages from last to first:\n");
    while (temp != NULL)
    {
        printf("%s ", temp->page);
        temp = temp->prev;
    }
    printf("\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n--- Web Page Navigation ---\n");
        printf("1. Insert New Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insertPage();
                break;
            case 2:
                moveForward();
                break;
            case 3:
                moveBackward();
                break;
            case 4:
                deletePage();
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                printf("Program exited\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);
    return 0;
}
