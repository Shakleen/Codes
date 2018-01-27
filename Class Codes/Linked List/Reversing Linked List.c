#include <stdio.h>
#include <string.h>

//Defining student structure
struct student{
    int roll;
    char name[80];
    struct student* next;
};

//Creating prototype for function to add elements
struct student* add_student (struct student *HEAD, int ROLL, char *NAME);

//Creating prototype for function to print elements
void PRINT (struct student *Head);

//Creating prototype for function to reverse
struct student* rev_list (struct student *HEAD);

int main(){

    //Setting head to NULL at the beginning
    struct student *head = NULL;

    //Asking for the number of data to add
    printf("How many students data to add?\n");
    int n=0, i=0;
    scanf("%d", &n);

    //Running loop to add the data to the linked list
    for(i=1; i<=n; i++){
        //taking data from user
        int rollno=0;
        printf("Enter the roll number of the student\n");
        scanf("%d", &rollno);
        fflush(stdin);

        char name[80]={};
        printf("Enter the name of the student\n");
        gets(name);

        //sending data to function to be added to the linked list
        head = add_student (head, rollno, name);

    }

    //printing the linked list
    printf("Before Reversing the list:\n");
    PRINT (head);

    head=rev_list(head);

    //printing the reversed linked list
    printf("After Reversing the list:\n");
    PRINT (head);

    return 0;
}

struct student* add_student (struct student *HEAD, int ROLL, char *NAME){

    //Allocating new memory for new student info
    struct student *NEW = (struct student*) malloc ( sizeof(struct student) );

    //Setting the informating part
    NEW -> roll = ROLL;
    strcpy(NEW -> name, NAME);

    //Setting the linking part
    NEW -> next = NULL;

    if ( HEAD == NULL ){
        HEAD = NEW;
    }
    else{
        struct student *current = HEAD;

        //Iterate through the linked list to find the last element
        while ( current -> next != NULL ){
            current = current -> next;
        }

        //link the last element to the new element
        current -> next = NEW;
    }
    //returning the head after alteration
    return HEAD;

}

void PRINT (struct student *Head){

    struct student *current = Head;

    while ( current != NULL ){

        //Printing info
        printf ("Student roll = %d ", current -> roll);
        printf ("Student name = %s\n", current -> name);

        //Moving to the next element
        current = current -> next;

    }

    printf("\n");

    return;

}

struct student* rev_list (struct student *HEAD){

    struct student *current = HEAD, *previous = NULL, *NEXT;

    while ( current != NULL ){

        //Step 1: Save the next element address in NEXT
        NEXT = current -> next;

        //Step 2: Current should point to the previous element
        current -> next = previous;

        //Step 3: Previous should be moved to current
        previous = current;

        //Step 4: Current should be moved to the next element
        current = NEXT;

    }

    //Step 5: At the end when current = NULL head should point to previous
    HEAD = previous;

    return HEAD;

};
