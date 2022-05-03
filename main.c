#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


//TODO; Make a double linked list, which can read the bottom row
//      OR
//      make maybe 7 linked lists which somehow can be willed with these 52 cards, they have to be able to be moved from linkedlist to linkedlist
//      ^^IT SHOULD PROBABLY BE THIS^^ -- also makes it easier to hide with []

//TODO; If the Bottom row consist of an ACE HEARTS move automatically to F1, if then the TWO HEARTS shows move it automatically ontop

//TODO 25/04; figure out a way to move around the linked lists like in the game
//      it probably has to go like; linked lists which than have to reatach from one spot to another spot
//      fx command could be; 3D TO 8H
// ------------------------------------------------------------------------------------------------------------------------
//TODO; 26/04 - eh.
//              >Create 7 columns, each their own linked list.
//              >Fill these columns with cards (these have to be randomly added)
//              >Figure out a method to add these cards randomly, - maybe a way to iniate them first and then add them randomly through iterating them,
//                                                                  or removing randomly from another linked list which is created.
//              > C1 = face up 1 card
//              > C2 = face down 1 card, face up 5 cards
//              > C3 = face down 2 card, face up 5 cards
//              > C4 = face down 3 card, face up 5 cards
//              > C5 = face down 4 card, face up 5 cards
//              > C6 = face down 5 card, face up 5 cards
//              > C7 = face down 6 card, face up 5 cards
//              maybe with a if statement these cards can move to their F1/F2/F3/F4 positions
//              if last node = what has to be on F1 automatically put it there.
//              moving cards can only be on the opisite color, and if its 1 lower
//              moving cards can be a whole row.
//  play the game more because i dont understand it
//  ------------------------------------------------------------------------------------------------------------------------
// TODO; 28/04 created somewhat OK termnial
//              need to add methods for COMMAND/MESSAGE/INPUT, would be nice if it is in one method.
//              use a switch for the input commands

#define STRMAX 100


/** Creates the node structure */
typedef struct Node {
    char *data;
    struct Node* next;
}Node;

/** there is also a 2D LINKED  LIST, not sure if it is necessary to use this..
typedef struct Deck{
    struct Node* Nodes;
    struct Deck* next;
}Deck; */

struct Node*first = NULL;

/** Collumns */
struct Node *C1 = NULL;
struct Node *C2 = NULL;
struct Node *C3 = NULL;
struct Node *C4 = NULL;
struct Node *C5 = NULL;
struct Node *C6 = NULL;
struct Node *C7 = NULL;
/** Decks */
struct Node *F1 = NULL;
struct Node *F11 = NULL;
struct Node *F2 = NULL;
struct Node *F22 = NULL;
struct Node *F3 = NULL;
struct Node *F33 = NULL;
struct Node *F4 = NULL;
struct Node *F44 = NULL;

/** all cards get withdrawn in collumns through this method.*/
void ArraytoLinkedlist (int arr[], int k, int l) {
    struct Node *temp;
    struct Node *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[k];
    first->next = NULL;
    last = first;

    for (int f; f < l; f++) {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = arr[f];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
} //end ArraytoLinkedlist
/** shuffle the array with cards */
void ArrayShuffle(int *arr, size_t n) {
    if (n > 1){
        size_t i;
        for (i = 0; i < n - 1; i++){
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
} //end ArrayShuffle
/** displays linkedlist with string/char */
void displaystring( const struct Node *node ) {
    while (node != NULL) {
        printf(" %s ", node->data);
        node = node->next;
    }
}//end displaystring
/** displays linkedlist with integers*/
void displayint( const struct Node *node ) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}//end displayint
/** pushes a node at the beginning of the linkedlist CHARACTER*/
void pushstart(struct Node** head_ref, char new_data[2])
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}//endpushstart

char plist(struct Node *p, int n) {
    int k = 0;
    int z = 0;
    while (p != NULL) {
        //printf("%s ", p->data);
        k++;
        if(k == n) {
            z++;
            if(k > 24) {
                printf("%s \t", p->data);
            } else {
                printf("[] \t");
            }
        }
        p = p->next;
    }
}
int Endgame(struct Node **F1, struct Node **F2, struct Node **F3, struct Node **F4){

    struct Node *temp1 = *F1;
    struct Node *temp2 = *F2;
    struct Node *temp3 = *F3;
    struct Node *temp4 = *F4;

    if (temp1 == NULL ) {
        return 0;
    }
    if (temp2 == NULL ) {
        return 0;
    }
    if (temp3 == NULL ) {
        return 0;
    }
    if (temp4 == NULL ) {
        return 0;
    }

        if (strcmp(temp1->data, "KS") == 0) {

                if (strcmp(temp2->data, "KH") == 0) {
                        if (strcmp(temp3->data, "KD") == 0) {
                                if (strcmp(temp4->data, "KC") == 0) {
                                    printf("\nWell played!\n");
                                    return 1;
                                } else { return 0; }
                        } else { return 0; }
                } else { return 0; }
        }else { return 0; }
}
char Terminalprint(struct Node *C1,struct Node *C2,struct Node *C3,struct Node *C4,struct Node *C5,struct Node *C6,struct Node *C7,struct Node *F1,struct Node *F2,struct Node *F3,struct Node *F4) {
    printf("\n");
    printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n");
    printf("\n");
    int k = 0; //keeps track if there is collumns left
    int cry = 0;
    int f = 0;
    C1 = C1->next;
    C2 = C2->next;
    C3 = C3->next;
    C4 = C4->next;
    C5 = C5->next;
    C6 = C6->next;
    C7 = C7->next;

    while(k != 7 || f != 4)  {
        k = 0;
        printf("\t");
        /** printing the C1/C2/C3/C4/C5/C6/C7/C8*/
        if (C1 != NULL) {
            printf("%s \t", C1->data);
            C1 = C1->next;
        } else {
            k++;
            printf("\t");
        }
        if (C2 != NULL) {
            printf("%s \t", C2->data);
            C2 = C2->next;
        } else {
            k++;
            printf("\t");
        }
        if (C3 != NULL) {
            printf("%s \t", C3->data);
            C3 = C3->next;
        } else {
            k++;
            printf("\t");
        }
        if (C4 != NULL) {
            printf("%s \t", C4->data);
            C4 = C4->next;
        } else {
            k++;
            printf("\t");
        }
        if (C5 != NULL) {
            printf("%s \t", C5->data);
            C5 = C5->next;
        } else {
            k++;
            printf("\t");
        }
        if (C6 != NULL) {
            printf("%s \t", C6->data);
            C6 = C6->next;
        } else {
            k++;
            printf("\t");
        }
        if (C7 != NULL) {
            printf("%s \t", C7->data);
            C7 = C7->next;
        } else {
            k++;
            printf("\t");
        }
        /** printing the F1/F2/F3/F4*/
        if ( cry == 1 ) {
            if (F1 == NULL){
                printf("[] \t");
            } else { printf("%s \t", F1->data);
                F1 = F1->next;}
            printf("F1");
            f++;
        }
        if ( cry == 3 ) {
            if (F2 == NULL){
                printf("[] \t");
            } else { printf("%s \t", F2->data);
                F2 = F2->next;}
            printf("F2");
            f++;
        }
        if ( cry == 5 ) {
            if (F3 == NULL){
                printf("[] \t");
            } else { printf("%s \t", F3->data);
            F3 = F3->next;}
            printf("F3");
            f++;

        }
        if ( cry == 7 ) {
            if (F4 == NULL){
                printf("[] \t");
            } else { printf("%s \t", F4->data);
                F4 = F4->next;}
            printf("F4");
            f++;
        }
        printf("\n");
        cry++;


    }

}
int getCount(struct Node* head)
{
    int count = 0;  // Initialize count
    struct Node* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void movenode(struct Node **cards,struct Node **column) {
    struct Node *temp = *cards;
    struct Node *removed;

    // Do sanity checks
    if (temp == NULL || temp ->next == NULL) {
        return;
    }

    // Find the entry before the last entry in the `*cards` list
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    // Remove the last entry in the `*cards` list

    removed = temp->next;
    temp->next = NULL;

    // Find the last entry in the `*column` list

    temp = *column;
    if(temp != NULL) {
        while(temp->next != NULL) {
            temp = temp->next;
        }
    }

    // Add the (removed) entry to the end of the `*columns` list

    if(temp == NULL) {
        *column = removed;
    } else {
        temp->next = removed;
    }
}
bool search(struct Node** head, char *card)
{
    struct Node* current = *head;  // Initialize current
    while (current != NULL)
    {
        if (strcmp(current->data, card) == 0)
            return true;
        current = current->next;
    }
    return false;
}

void movenodewithnumber(struct Node **cards,struct Node **column,int number) {
    struct Node *temp = *cards;
    struct Node *removed;

    if (temp == NULL || temp ->next == NULL) {
        return;
    }

    // Find the entry before the last entry in the `*cards` list
    int counter = 0;
    if(temp != NULL) {
        while (temp->next->next != NULL) {
            if (counter+1 == number) {
                break;
            }
            counter++;
            temp = temp->next;
        }
    }


    // Remove the last entry in the `*cards` list

    removed = temp->next;
    temp->next = NULL;

    // Find the last entry in the `*column` list

    temp = *column;
    if(temp != NULL) {
        while(temp->next != NULL) {
            temp = temp->next;
        }
    }

    // Add the (removed) entry to the end of the `*columns` list

    if(temp == NULL) {
        *column = removed;
    } else {
        temp->next = removed;
    }

}

int movecard(struct Node** head, char *card){

    int number = 0;
    struct Node* current = *head;  // Initialize current
    while (current != NULL)
    {
        if (strcmp(current->data, card) == 0)
            return number;
        current = current->next;
        number++;
    }
    return 5;
}



void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Find the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL) return;

    // Remove the node
    prev->next = temp->next;

    free(temp);
}




Node * createLinkedlistS();

int main() {

    pushstart(&C1,"HEAD");
    pushstart(&C2,"HEAD");
    pushstart(&C3,"HEAD");
    pushstart(&C4,"HEAD");
    pushstart(&C5,"HEAD");
    pushstart(&C6,"HEAD");
    pushstart(&C7,"HEAD");

    struct Node *cards;
    cards = createLinkedlistS();

    char Msg[STRMAX];
    size_t Message;

    char hello[STRMAX];
    size_t HELLO;

    char inp[STRMAX];
    size_t INPUT;

    Message = strncpy(Msg,"",STRMAX);
    INPUT = strncpy(inp,"",STRMAX);


    while(Endgame(&F1,&F2,&F3,&F4) != 1) {
        fseek(stdin, 0, SEEK_END);
        printf("\n");
        Terminalprint(C1, C2, C3, C4, C5, C6, C7, F1, F2, F3, F4);


        printf("LAST COMMAND: %s \n", INPUT);
        INPUT = strncpy(inp, "", STRMAX);
        printf("Message: %s\n", Message);
        printf("INPUT > ");
        scanf(" %s", INPUT);


        if (strcmp(INPUT, "SW") == 0) {
            Message = strncpy(Msg, "this works", STRMAX);

            while (cards->next != NULL) {
                movenode(&cards, &C1);
                movenode(&cards, &C2);
                movenode(&cards, &C3);
                movenode(&cards, &C4);
                movenode(&cards, &C5);
                movenode(&cards, &C6);
                movenode(&cards, &C7);
            }
            Message = strncpy(Msg, "It should return an error message if no deck of cards is loaded and OK otherwise.",
                              STRMAX);
        }
/** -------------------HERE YOU ARE IN P -------------------*/
            if (strcmp(INPUT, "P") == 0) {
                Message = strncpy(Msg, "Your now playing the game!", STRMAX);
                while (Endgame(&F1, &F2, &F3, &F4) != 1) {
                    fseek(stdin, 0, SEEK_END);
                    printf("\n");
                    Terminalprint(C1, C2, C3, C4, C5, C6, C7, F1, F2, F3, F4);


                    printf("LAST COMMAND: %s \n", INPUT);
                    INPUT = strncpy(inp, "", STRMAX);
                    printf("Message: %s\n", Message);
                    printf("INPUT > ");
                    scanf(" %s", INPUT);

                /** -------------------MOVING CARDS -------------------*/

                /** Collumn:card->Collumn */
                if (strlen(INPUT) == 9) {
                    if (strstr(INPUT, ":") != NULL) {
                        if (strstr(INPUT, "->") != NULL) {
                            char *FROMCOLUMN = strtok(INPUT, ":");
                            char *FROMCARD = strtok(NULL, "->");
                            char *TOCOLUMN = strtok(NULL, "-> ");

                            printf("%s\n",FROMCOLUMN);
                            printf("%s\n",FROMCARD);
                            printf("%s\n",TOCOLUMN);

                            //checking which column to go into
                            if(strcmp(FROMCOLUMN, "C1") == 0){

                                //checking if the card exists in that column
                                if(search(&C1,FROMCARD) == true){

                                    //checking which other column to go into
                                    if(strcmp(TOCOLUMN, "C1") == 0){
                                        //checking how many cards you have to go down, and then move from that card
                                        printf("%d\n",movecard(&C1,FROMCARD));
                                        movenodewithnumber(&C1,&C1, movecard(&C1,FROMCARD));
                                        //shouldnt happen.
                                    }
                                    if(strcmp(TOCOLUMN, "C2") == 0){

                                        movenodewithnumber(&C1,&C2, movecard(&C1,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C3") == 0){
                                        movenodewithnumber(&C1,&C3, movecard(&C1,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C4") == 0){
                                        movenodewithnumber(&C1,&C4, movecard(&C1,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C5") == 0){
                                        movenodewithnumber(&C1,&C5, movecard(&C1,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C6") == 0){
                                        movenodewithnumber(&C1,&C6, movecard(&C1,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C7") == 0){
                                        movenodewithnumber(&C1,&C7, movecard(&C1,FROMCARD));
                                    }
                                }
                            }
                            if(strcmp(FROMCOLUMN, "C2") == 0){
                                if(search(&C2,FROMCARD) == true){
                                    if(strcmp(TOCOLUMN, "C1") == 0){
                                        movenodewithnumber(&C2,&C1, movecard(&C2,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C2") == 0){
                                        movenodewithnumber(&C2,&C2, movecard(&C2,FROMCARD));
                                        //shouldnt happen.
                                    }
                                    if(strcmp(TOCOLUMN, "C3") == 0){
                                        movenodewithnumber(&C2,&C3, movecard(&C2,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C4") == 0){
                                        movenodewithnumber(&C2,&C4, movecard(&C2,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C5") == 0){
                                        movenodewithnumber(&C2,&C5, movecard(&C2,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C6") == 0){
                                        movenodewithnumber(&C2,&C6, movecard(&C2,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C7") == 0){
                                        movenodewithnumber(&C2,&C7, movecard(&C2,FROMCARD));
                                    }
                                }
                            }
                            if(strcmp(FROMCOLUMN, "C3") == 0){
                                if(search(&C3,FROMCARD) == true){
                                    if(strcmp(TOCOLUMN, "C1") == 0){
                                        movenodewithnumber(&C3,&C1, movecard(&C3,FROMCARD));
                                        //shouldnt happen.
                                    }
                                    if(strcmp(TOCOLUMN, "C2") == 0){
                                        movenodewithnumber(&C3,&C2, movecard(&C3,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C3") == 0){
                                        movenodewithnumber(&C3,&C3, movecard(&C3,FROMCARD));
                                        //shouldnt happen.
                                    }
                                    if(strcmp(TOCOLUMN, "C4") == 0){
                                        movenodewithnumber(&C3,&C4, movecard(&C3,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C5") == 0){
                                        movenodewithnumber(&C3,&C5, movecard(&C3,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C6") == 0){
                                        movenodewithnumber(&C3,&C6, movecard(&C3,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C7") == 0){
                                        movenodewithnumber(&C3,&C7, movecard(&C3,FROMCARD));
                                    }
                                }
                            }
                            if(strcmp(FROMCOLUMN, "C4") == 0){
                                if(search(&C4,FROMCARD) == true){
                                    if(strcmp(TOCOLUMN, "C1") == 0){
                                        movenodewithnumber(&C4,&C1, movecard(&C4,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C2") == 0){
                                        movenodewithnumber(&C4,&C2, movecard(&C4,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C3") == 0){
                                        movenodewithnumber(&C4,&C3, movecard(&C4,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C4") == 0){
                                        movenodewithnumber(&C4,&C4, movecard(&C4,FROMCARD));
                                        //shouldnt happen.
                                    }
                                    if(strcmp(TOCOLUMN, "C5") == 0){
                                        movenodewithnumber(&C4,&C5, movecard(&C4,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C6") == 0){
                                        movenodewithnumber(&C4,&C6, movecard(&C4,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C7") == 0){
                                        movenodewithnumber(&C4,&C7, movecard(&C4,FROMCARD));
                                    }
                                }
                            }
                            if(strcmp(FROMCOLUMN, "C5") == 0){
                                if(search(&C5,FROMCARD) == true){
                                    if(strcmp(TOCOLUMN, "C1") == 0){
                                        movenodewithnumber(&C5,&C1, movecard(&C5,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C2") == 0){
                                        movenodewithnumber(&C5,&C2, movecard(&C5,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C3") == 0){
                                        movenodewithnumber(&C5,&C3, movecard(&C5,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C4") == 0){
                                        movenodewithnumber(&C5,&C4, movecard(&C5,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C5") == 0){
                                        movenodewithnumber(&C5,&C5, movecard(&C5,FROMCARD));
                                        //shouldnt happen.
                                    }
                                    if(strcmp(TOCOLUMN, "C6") == 0){
                                        movenodewithnumber(&C5,&C6, movecard(&C5,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C7") == 0){
                                        movenodewithnumber(&C5,&C7, movecard(&C5,FROMCARD));
                                    }
                                }
                            }
                            if(strcmp(FROMCOLUMN, "C6") == 0){
                                if(search(&C6,FROMCARD) == true){
                                    if(strcmp(TOCOLUMN, "C1") == 0){
                                        movenodewithnumber(&C6,&C1, movecard(&C6,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C2") == 0){
                                        movenodewithnumber(&C6,&C2, movecard(&C6,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C3") == 0){
                                        movenodewithnumber(&C6,&C3, movecard(&C6,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C4") == 0){
                                        movenodewithnumber(&C6,&C4, movecard(&C6,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C5") == 0){
                                        movenodewithnumber(&C6,&C5, movecard(&C6,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C6") == 0){
                                        movenodewithnumber(&C6,&C6, movecard(&C6,FROMCARD));
                                        //shouldnt happen
                                    }
                                    if(strcmp(TOCOLUMN, "C7") == 0){
                                        movenodewithnumber(&C6,&C7, movecard(&C6,FROMCARD));
                                    }
                                }
                            }
                            if(strcmp(FROMCOLUMN, "C7") == 0){
                                if(search(&C7,FROMCARD) == true){
                                    if(strcmp(TOCOLUMN, "C1") == 0){
                                        movenodewithnumber(&C7,&C1, movecard(&C7,FROMCARD));
                                        //shouldnt happen.
                                    }
                                    if(strcmp(TOCOLUMN, "C2") == 0){
                                        movenodewithnumber(&C7,&C2, movecard(&C7,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C3") == 0){
                                        movenodewithnumber(&C7,&C3, movecard(&C7,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C4") == 0){
                                        movenodewithnumber(&C7,&C4, movecard(&C7,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C5") == 0){
                                        movenodewithnumber(&C7,&C5, movecard(&C7,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C6") == 0){
                                        movenodewithnumber(&C7,&C6, movecard(&C7,FROMCARD));
                                    }
                                    if(strcmp(TOCOLUMN, "C7") == 0){
                                        movenodewithnumber(&C7,&C7, movecard(&C7,FROMCARD));
                                        //shouldnt happen
                                    }
                                }
                            }




                            //1st: we traverse the columns looking for 'FROM' and we return the column

                            //2nd: we traverse the columns looking for 'TO' and we return the column

                            //(3rd): we look if one of these is a hidden card, if so, this is not possible

                            //4th: check if the move is possible

                            //5th: make the move :).
                            Message = strncpy(Msg, "THIS WORKED THIS WORKED", STRMAX);
                        }
                    }
                }

                /** Collumn:card->Collumn */
                if (strlen(INPUT) == 6) {
                    if (strstr(INPUT, "->") != NULL) {
                        char *FROMCARD = strtok(INPUT, "->");
                        char *TOCOLUMN = strtok(NULL, "-> ");
                    }
                }



                /** -------------- MOVING CARDS END ---------------*/

                    if (strcmp(INPUT, "Q") == 0) {
                        Message = strncpy(Msg, "You are not playing the game anymore!", STRMAX);
                        break;
                    }

                    if (strcmp(INPUT, "Q") != 0 || strcmp(INPUT, "P") != 0) {
                        Message = strncpy(Msg, "invalid command", STRMAX);
                        }

                    if (strlen(INPUT) == 6) {
                        if (strstr(INPUT, "->") != NULL) {
                            } else {
                                Message = strncpy(Msg, "The move is not valid.", STRMAX);
                        }
                    }

                }
            } //OUT OF PLAY GAME (P)
/** -------------------HERE YOU ARE OUT OF P -------------------*/

            if (strcmp(INPUT, "QQ") == 0) {
                exit(0);
            }

    // some commands for when you fill in the wrong data, have to be in this order
            if (strcmp(INPUT, "QQ") != 0 || strcmp(INPUT, "SR") != 0 || strcmp(INPUT, "SW") != 0) {
                Message = strncpy(Msg, "invalid command", STRMAX);
            }
            if (strcmp(INPUT, "Q") == 0) {
                Message = strncpy(Msg, "You are not playing the game anymore!", STRMAX);
            }
    }// END OF THE BIG WHILE LOOP
    printf("the game is done!");
    return 0;
}

Node * createLinkedlistS(){
    struct Node* HEAD;
    struct Node* head = NULL; head = (struct Node*)malloc(sizeof(struct Node));
    /**SPADES*/
    struct Node* ACES = NULL; ACES = (struct Node*)malloc(sizeof(struct Node));
    struct Node* TWOS = NULL; TWOS = (struct Node*)malloc(sizeof(struct Node));
    struct Node* THREES = NULL; THREES = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FOURS = NULL; FOURS = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FIVES = NULL; FIVES = (struct Node*)malloc(sizeof(struct Node));
    struct Node* SIXS = NULL; SIXS = (struct Node*)malloc(sizeof(struct Node));
    struct Node* SEVENS = NULL; SEVENS = (struct Node*)malloc(sizeof(struct Node));
    struct Node* EIGHTS = NULL; EIGHTS = (struct Node*)malloc(sizeof(struct Node));
    struct Node* NINES = NULL; NINES = (struct Node*)malloc(sizeof(struct Node));
    struct Node* TENS = NULL; TENS = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FARMERS = NULL; FARMERS = (struct Node*)malloc(sizeof(struct Node));
    struct Node* QUEENS = NULL; QUEENS = (struct Node*)malloc(sizeof(struct Node));
    struct Node* KINGS = NULL; KINGS = (struct Node*)malloc(sizeof(struct Node));
    /**HEARTS*/
    struct Node* ACEH = NULL; ACEH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* TWOH = NULL; TWOH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* THREEH = NULL; THREEH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FOURH = NULL; FOURH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FIVEH = NULL; FIVEH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* SIXH = NULL; SIXH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* SEVENH = NULL; SEVENH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* EIGHTH = NULL; EIGHTH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* NINEH = NULL; NINEH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* TENH = NULL; TENH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FARMERH = NULL; FARMERH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* QUEENH = NULL; QUEENH = (struct Node*)malloc(sizeof(struct Node));
    struct Node* KINGH = NULL; KINGH = (struct Node*)malloc(sizeof(struct Node));
    /**DIAMONDS*/
    struct Node* ACED = NULL; ACED = (struct Node*)malloc(sizeof(struct Node));
    struct Node* TWOD = NULL; TWOD = (struct Node*)malloc(sizeof(struct Node));
    struct Node* THREED = NULL; THREED = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FOURD = NULL; FOURD = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FIVED = NULL; FIVED = (struct Node*)malloc(sizeof(struct Node));
    struct Node* SIXD = NULL; SIXD = (struct Node*)malloc(sizeof(struct Node));
    struct Node* SEVEND = NULL; SEVEND = (struct Node*)malloc(sizeof(struct Node));
    struct Node* EIGHTD = NULL; EIGHTD = (struct Node*)malloc(sizeof(struct Node));
    struct Node* NINED = NULL; NINED = (struct Node*)malloc(sizeof(struct Node));
    struct Node* TEND = NULL; TEND = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FARMERD = NULL; FARMERD = (struct Node*)malloc(sizeof(struct Node));
    struct Node* QUEEND = NULL; QUEEND = (struct Node*)malloc(sizeof(struct Node));
    struct Node* KINGD = NULL; KINGD = (struct Node*)malloc(sizeof(struct Node));
    /**CLUBS*/
    struct Node* ACEC = NULL; ACEC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* TWOC = NULL; TWOC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* THREEC = NULL; THREEC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FOURC = NULL; FOURC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FIVEC = NULL; FIVEC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* SIXC = NULL; SIXC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* SEVENC = NULL; SEVENC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* EIGHTC = NULL; EIGHTC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* NINEC = NULL; NINEC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* TENC = NULL; TENC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* FARMERC = NULL; FARMERC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* QUEENC = NULL; QUEENC = (struct Node*)malloc(sizeof(struct Node));
    struct Node* KINGC = NULL; KINGC = (struct Node*)malloc(sizeof(struct Node));

    /** Initializing nodes and allocating memory */
    head->data = ""; head->next = ACES;
    /**SPADES*/
    ACES->data = "AS"; ACES->next = TWOS;
    TWOS->data = "2S"; TWOS->next = THREES;
    THREES->data = "3S"; THREES->next = FOURS;
    FOURS->data = "4S"; FOURS->next = FIVES;
    FIVES->data = "5S"; FIVES->next = SIXS;
    SIXS->data = "6S"; SIXS->next = SEVENS;
    SEVENS->data = "7S"; SEVENS->next = EIGHTS;
    EIGHTS->data = "8S"; EIGHTS->next = NINES;
    NINES->data = "9S"; NINES->next = TENS;
    TENS->data = "10S"; TENS->next = FARMERS;
    FARMERS->data = "JS"; FARMERS->next = QUEENS;
    QUEENS->data = "QS"; QUEENS->next = KINGS;
    KINGS->data = "KS"; KINGS->next = ACEH;
    /**HEARTS*/
    ACEH->data = "AH"; ACEH->next = TWOH;
    TWOH->data = "2H"; TWOH->next = THREEH;
    THREEH->data = "3H"; THREEH->next = FOURH;
    FOURH->data = "4H"; FOURH->next = FIVEH;
    FIVEH->data = "5H"; FIVEH->next = SIXH;
    SIXH->data = "6H"; SIXH->next = SEVENH;
    SEVENH->data = "7H"; SEVENH->next = EIGHTH;
    EIGHTH->data = "8H"; EIGHTH->next = NINEH;
    NINEH->data = "9H"; NINEH->next = TENH;
    TENH->data = "10H"; TENH->next = FARMERH;
    FARMERH->data = "JH"; FARMERH->next = QUEENH;
    QUEENH->data = "QH"; QUEENH->next = KINGH;
    KINGH->data = "KH"; KINGH->next = ACED;
    /**DIAMONDS*/
    ACED->data  = "AD"; ACED->next = TWOD;
    TWOD->data = "2D"; TWOD->next = THREED;
    THREED->data = "3D"; THREED->next = FOURD;
    FOURD->data = "4D"; FOURD->next = FIVED;
    FIVED->data = "5D"; FIVED->next = SIXD;
    SIXD->data = "6D"; SIXD->next = SEVEND;
    SEVEND->data = "7D"; SEVEND->next = EIGHTD;
    EIGHTD->data = "8D"; EIGHTD->next = NINED;
    NINED->data = "9D"; NINED->next = TEND;
    TEND->data = "10D"; TEND->next = FARMERD;
    FARMERD->data = "JD"; FARMERD->next = QUEEND;
    QUEEND->data = "QD"; QUEEND->next = KINGD;
    KINGD->data = "KD"; KINGD->next = ACEC;
    /**CLUBS*/
    ACEC->data = "AC"; ACEC->next = TWOC;
    TWOC->data = "2C"; TWOC->next = THREEC;
    THREEC->data = "3C"; THREEC->next = FOURC;
    FOURC->data = "4C"; FOURC->next = FIVEC;
    FIVEC->data = "5C"; FIVEC->next = SIXC;
    SIXC->data = "6C"; SIXC->next = SEVENC;
    SEVENC->data = "7C"; SEVENC->next = EIGHTC;
    EIGHTC->data = "8C"; EIGHTC->next = NINEC;
    NINEC->data = "9C"; NINEC->next = TENC;
    TENC->data = "10C"; TENC->next = FARMERC;
    FARMERC->data = "JC"; FARMERC->next = QUEENC;
    QUEENC->data = "QC"; QUEENC->next = KINGC;
    KINGC->data = "KC"; KINGC->next = NULL;

    HEAD = head;
}






