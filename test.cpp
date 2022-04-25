#include <stdio.h>   //insert headeer file standard input/output
#include <stdlib.h> //insert header file for mamory allocation

struct node                  //creating structure for node
{
    int num;                 //variable of that node
    struct node *nextptr;    //pointer of node
} * stnode;                  //header of node

struct node *tail, *p, *q;     //declaring pointer variable for creating linked list & deleting node

void Create_circular_list(int n);       //calling function for creating list
void Delete_last_node();                //calling function for deleting last node
void Display_circular_list(int a);      //calling function for disply linked list

int main()
{
    int n, a;        
    stnode = NULL;   //initial value of head = 0
    printf("\n\n Circular Linked List : Delete node at the end of a circular linked list :\n");
    printf("------------------------------------------------------------------------------\n");

    printf(" Input the number of nodes : ");
    scanf("%d", &n);            //taking the number of nodes from the user
    Create_circular_list(n);    //calling function for creating circular list
    a = 1;   //here a = 1 means the initial number of nodes before delete
    Display_circular_list(a);  //calling function to display all the nodes before delete
    Delete_last_node();        //calling function for delete last node
    a = 2;  //here a = 2 means the number of nodes after deletion
    Display_circular_list(a);  //calling function again to display all the nodes after deletaion
    return 0;
}

void Create_circular_list(int n)  //the creation of list is starting from here
{
    int i, num;  //here variable i for using loop & variable num for taiking input from the use for nodes
    struct node *preptr, *newnode;     //declaring 2 pointer variable fro node

    if (n >= 1)     //if the number of 'n' is more than or equal 1 then this loop will be execute
    {
        stnode = (struct node *)malloc(sizeof(struct node)); //here malloc function is allocating memory for the header of node

        printf(" Input data for node 1 : ");
        scanf("%d", &num);  //taking the value from user for first node
        stnode->num = num;  //puting the value of first node into variable 'num'
        stnode->nextptr = NULL;
        preptr = stnode; //put the value of addre from the header to variable pre-pointer
        for (i = 2; i <= n; i++)  //taiking value for the rest of node from user by using loop
        {
            newnode = (struct node *)malloc(sizeof(struct node)); //allocating memory address for the rest of nodes
            printf(" Input data for node %d : ", i);    //instruction for entering the value of node to the user
            scanf("%d", &num);     //taking the value of nodes from user
            newnode->num = num;     //the number of newnode is assigned into variable 'num'
            newnode->nextptr = NULL;   // next address of new node set as NULL
            preptr->nextptr = newnode; // previous node is linking with new node
            preptr = newnode;          // previous node is advanced
        }
        preptr->nextptr = stnode; // last node is linking with first node
    }
}

void Delete_last_node()        //function for deleting last node
{
    p = stnode;   //put the address of the first node into pointer variavle "P"
    while (p->nextptr != stnode)
    {
        q = p;  //put the value of variable 'p' into variable 'q'
        p = p->nextptr; //put the the address of 'p' into variable 'p'
    }
    q->nextptr = stnode;    //put the address of 'q' into header
    printf("\n The deleted node is : %d", p->num);  //printing the value of deleted node from 'p'
    free(p);    //clearing garbage
}

void Display_circular_list(int m)   //function for displaying the linked list
{
    struct node *tmp;   //declaring the pointer variable 'tmp'
    int n = 1;

    if (stnode == NULL)     //if the header of node is null then execute the program for this condition
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = stnode;
        if (m == 1)
        {
            printf("\n Data entered in the list are :\n");
        }
        else
        {
            printf("\n After deletion the new list are :\n");
        }
        do
        {
            printf(" Data %d = %d\n", n, tmp->num);

            tmp = tmp->nextptr;
            n++;
        } while (tmp != stnode);
    }
}
