#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

//TODO; ADD SHUFFLE FUNCTION
//      ADD COLLUMN->COLLUMN FUNCTIONS (including F1.etc..)
//      FIX THE 'Message'
//      FIX 'last command'
//      ADD ALL HIDE FUNCTION

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
struct Node *F2 = NULL;
struct Node *F3 = NULL;
struct Node *F4 = NULL;
/** hide cards */
int hideC7 = 6;
int hideC6 = 5;
int hideC5 = 4;
int hideC4 = 3;
int hideC3 = 2;
int hideC2 = 1;

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

/** Reads if all F collumns have a king on top and ends the game.*/
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
}//endEndgame

/** prints the gigantic terminal...*/
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

    int showC7=0;
    int showC6=0;
    int showC5=0;
    int showC4=0;

    int showC3=0;
    int showC2=0;
    int showC1=0;

    int removeC2=0;
    struct Node* current2 = C2;
    while (current2 != NULL)
    {
        removeC2++;
        current2 = current2->next;
    } if (removeC2 == hideC2) { hideC2--;}

    int removeC3=0;
    struct Node* current3 = C3;
    while (current3 != NULL)
    {
        removeC3++;
        current3 = current3->next;
    } if (removeC3 == hideC3) { hideC3--;}

    int removeC4 = 0;
    struct Node* current4 = C4;
    while (current4 != NULL)
    {
        removeC4++;
        current4 = current4->next;
    } if (removeC4 == hideC4) { hideC4--;}

    int removeC5=0;
    struct Node* current5 = C5;
    while (current5 != NULL)
    {
        removeC5++;
        current5 = current5->next;
    } if (removeC5 == hideC5) { hideC5--;}

    int removeC6=0;
    struct Node* current6 = C6;
    while (current6 != NULL)
    {
        removeC6++;
        current6 = current6->next;
    } if (removeC6 == hideC6) { hideC6--;}

    int removeC7=0;
    struct Node* current7 = C7;
    while (current7 != NULL)
    {
        removeC7++;
        current7 = current7->next;
    } if (removeC7 == hideC7) { hideC7--;}

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
            if( hideC2 >= showC2 ){
                printf("[] \t");
            } else {
                printf("%s \t", C2->data);
            }
            ++showC2;
            C2 = C2->next;
        } else {
            k++;
            printf("\t");
        }
        if (C3 != NULL) {
            if( hideC3 >= showC3 ){
                printf("[] \t");
            } else {
                printf("%s \t", C3->data);
            }
            ++showC3;
            C3 = C3->next;
        } else {
            k++;
            printf("\t");
        }
        if (C4 != NULL) {
            if( hideC4 >= showC4 ){
                printf("[] \t");
            } else {
                printf("%s \t", C4->data);
            }
            ++showC4;
            C4 = C4->next;
        } else {
            k++;
            printf("\t");
        }
        if (C5 != NULL) {
            if( hideC5 >= showC5 ){
                printf("[] \t");
            } else {
                printf("%s \t", C5->data);
            }
            ++showC5;
            C5 = C5->next;
        } else {
            k++;
            printf("\t");
        }
        if (C6 != NULL) {
            if( hideC6 >= showC6 ){
                printf("[] \t");
            } else {
                printf("%s \t", C6->data);
            }
            ++showC6;
            C6 = C6->next;
        } else {
            k++;
            printf("\t");
        }
        if (C7 != NULL) {
            if( hideC7 >= showC7 ){
                printf("[] \t");
            } else {
                printf("%s \t", C7->data);
            }
            ++showC7;
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

}//end Terminalprint

/** gives the amount of nodes in a linkedlist*/
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
}//endgetCount

/** moves the last not of a linked list to the last node of another linkedlist*/
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
}//end movenode

/** checks if the card exists in the linkedlist*/
bool search(struct Node** FROMCOLUMN, char *card)
{
    struct Node* current = *FROMCOLUMN;  // Initialize current
    while (current != NULL)
    {
        if (strcmp(current->data, card) == 0)
            return true;
        current = current->next;
    }
    return false;
}//end search

/** moves from a given card to the end of a given linkedlist */
void movenodewithnumber(struct Node **FROMCOLUMN, struct Node **TOCOLUMN, int Card_number) {
    struct Node *temp = *FROMCOLUMN;
    struct Node *removed;

    if (temp == NULL || temp ->next == NULL) {
        return;
    }

    // Find the entry before the last entry in the `*FROMCOLUMN` list
    int counter = 0;
    if(temp != NULL) {
        while (temp->next->next != NULL) {
            if (counter+1 == Card_number) {
                break;
            }
            counter++;
            temp = temp->next;
        }
    }
    removed = temp->next;
    temp->next = NULL;

    temp = *TOCOLUMN;
    if(temp != NULL) {
        while(temp->next != NULL) {
            temp = temp->next;
        }
    }

    if(temp == NULL) {
        *TOCOLUMN = removed;
    } else {
        temp->next = removed;
    }

}//end movenodewithnumber

int movecard(struct Node** head, char *card){

    int number = 0;
    struct Node* current = *head;
    while (current != NULL)
    {
        if (strcmp(current->data, card) == 0)
            return number;
        current = current->next;
        number++;
    }
    return 0;
}

bool checkifpossible(struct Node** FROMCOLUMN,struct Node** TOCOLUMN,int Card_number){

    struct Node* temp1 = *FROMCOLUMN;
    struct Node* temp2 = *TOCOLUMN;
    struct Node *removed;

    if (temp1 == NULL || temp1 ->next == NULL) {
        return false;
    }
    if (temp2 == NULL || temp2 ->next == NULL) {
        return false;
    }

    /** Get the last node of the 'TOCOLUMN' */
    if(temp2 != NULL) {
        while(temp2->next != NULL) {
            temp2 = temp2->next;
        }
    }

    int counter = 0;
    if(temp1 != NULL) {
        while (temp1->next != NULL) {
            if (counter+1 == Card_number) {
                break;
            }
            counter++;
            temp1 = temp1->next;
        }
    }
    removed = temp1->next;
    //temp->next = NULL;

    printf("\nFROM CARD (TOP) = %s\n", removed->data);
    printf("\nTO CARD (TO) = %s\n", temp2->data);

    int fromcardnumber = 0;
    if (strstr(removed->data, "1") != NULL){
        if (strstr(removed->data, "0") != NULL) {
        } else {
            fromcardnumber = 1;
        }
    }
    if (strstr(removed->data, "2") != NULL){
        fromcardnumber = 2;
    }
    if (strstr(removed->data, "3") != NULL){
        fromcardnumber = 3;
    }
    if (strstr(removed->data, "4") != NULL){
        fromcardnumber = 4;
    }
    if (strstr(removed->data, "5") != NULL){
        fromcardnumber = 5;
    }
    if (strstr(removed->data, "6") != NULL){
        fromcardnumber = 6;
    }
    if (strstr(removed->data, "7") != NULL){
        fromcardnumber = 7;
    }
    if (strstr(removed->data, "8") != NULL){
        fromcardnumber = 8;
    }
    if (strstr(removed->data, "9") != NULL){
        fromcardnumber = 9;
    }
    if (strstr(removed->data, "10") != NULL){
        fromcardnumber = 10;
    }
    if (strstr(removed->data, "J") != NULL){
        fromcardnumber = 11;
    }
    if (strstr(removed->data, "D") != NULL){
        fromcardnumber = 12;
    }
    if (strstr(removed->data, "K") != NULL){
        fromcardnumber = 13;
    }

    int tocardnumber = 0;
    if (strstr(temp2->data, "1") != NULL){
        if (strstr(temp2->data, "0") != NULL) {
        } else {
            tocardnumber = 1;
        }
    }
    if (strstr(temp2->data, "2") != NULL){
        tocardnumber = 2;
    }
    if (strstr(temp2->data, "3") != NULL){
        tocardnumber = 3;
    }
    if (strstr(temp2->data, "4") != NULL){
        tocardnumber = 4;
    }
    if (strstr(temp2->data, "5") != NULL){
        tocardnumber = 5;
    }
    if (strstr(temp2->data, "6") != NULL){
        tocardnumber = 6;
    }
    if (strstr(temp2->data, "7") != NULL){
        tocardnumber = 7;
    }
    if (strstr(temp2->data, "8") != NULL){
        tocardnumber = 8;
    }
    if (strstr(temp2->data, "9") != NULL){
        tocardnumber = 9;
    }
    if (strstr(temp2->data, "10") != NULL){
        tocardnumber = 10;
    }
    if (strstr(temp2->data, "J") != NULL){
        tocardnumber = 11;
    }
    if (strstr(temp2->data, "D") != NULL){
        tocardnumber = 12;
    }
    if (strstr(temp2->data, "K") != NULL){
        tocardnumber = 13;
    }



    if (strstr(removed->data, "D") != NULL) {
        if (strstr(temp2->data, "H") != NULL) {
            return false;
        }
        if (strstr(temp2->data, "C") != NULL || strstr(temp2->data, "S") != NULL) {
            if (fromcardnumber == tocardnumber-1) {
                return true;
            }
        }
    }
    if (strstr(removed->data, "H") != NULL) {
        if (strstr(temp2->data, "D") != NULL) {
            return false;
        }
        if (strstr(temp2->data, "C") != NULL || strstr(temp2->data, "S") != NULL) {
            if (fromcardnumber == tocardnumber-1) {
                return true;
            }
        }
    }
    if (strstr(removed->data, "C") != NULL) {
        if (strstr(temp2->data, "S") != NULL) {
            return false;
        }
        if (strstr(temp2->data, "H") != NULL || strstr(temp2->data, "D") != NULL) {
            if (fromcardnumber == tocardnumber-1) {
                return true;
            }
        }
    }
    if (strstr(removed->data, "S") != NULL) {
        if (strstr(temp2->data, "C") != NULL) {
            return false;
        }
        if (strstr(temp2->data, "H") != NULL || strstr(temp2->data, "D") != NULL) {
            if (fromcardnumber == tocardnumber-1) {
                return true;
            }
        }
    }
    return false;
}

int whichcolumn(char *column){

    int from = 0;

    if(strcmp(column, "C1") == 0){
        from =1;
    }
    if(strcmp(column, "C2") == 0){ from = 2; }
    if(strcmp(column, "C3") == 0){ from = 3; }
    if(strcmp(column, "C4") == 0){ from = 4; }
    if(strcmp(column, "C5") == 0){ from = 5; }
    if(strcmp(column, "C6") == 0){ from = 6; }
    if(strcmp(column, "C7") == 0){ from = 7; }
    if(from>0) {
        return from;
    }

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
                if (strlen(INPUT) == 9 || strlen(INPUT) == 10) {
                    if (strstr(INPUT, ":") != NULL) {
                        if (strstr(INPUT, "->") != NULL) {
                            char *FROMCOLUMN = strtok(INPUT, ":");
                            char *FROMCARD = strtok(NULL, "->");
                            char *TOCOLUMN = strtok(NULL, "-> ");

                            int card_number;
                            int from = whichcolumn(FROMCOLUMN);
                            int to = whichcolumn(TOCOLUMN);

                            switch (from){
                                case 1: card_number = movecard(&C1,FROMCARD); break;
                                case 2: card_number = movecard(&C2,FROMCARD); break;
                                case 3: card_number = movecard(&C3,FROMCARD); break;
                                case 4: card_number = movecard(&C4,FROMCARD); break;
                                case 5: card_number = movecard(&C5,FROMCARD); break;
                                case 6: card_number = movecard(&C6,FROMCARD); break;
                                case 7: card_number = movecard(&C7,FROMCARD); break;
                            }
                            /** COLUMN 1 */
                            if (from == 1 && to == 2 && search(&C1,FROMCARD) == true) {
                                if(checkifpossible(&C1,&C2,card_number)== true) {
                                    movenodewithnumber(&C1, &C2, card_number);
                                }
                            }
                            if (from == 1 && to == 3 && search(&C1,FROMCARD) == true) {
                                if(checkifpossible(&C1,&C3,card_number)== true) {
                                    movenodewithnumber(&C1, &C3, card_number);
                                }
                            }
                            if (from == 1 && to == 4 && search(&C1,FROMCARD) == true) {
                                if(checkifpossible(&C1,&C4,card_number)== true) {
                                    movenodewithnumber(&C1, &C4, card_number);
                                }
                            }
                            if (from == 1 && to == 5 && search(&C1,FROMCARD) == true) {
                                if(checkifpossible(&C1,&C5,card_number)== true) {
                                    movenodewithnumber(&C1, &C5, card_number);
                                }
                            }
                            if (from == 1 && to == 6 && search(&C1,FROMCARD) == true) {
                                if(checkifpossible(&C1,&C6,card_number)== true) {
                                    movenodewithnumber(&C1, &C6, card_number);
                                }
                            }
                            if (from == 1 && to == 7 && search(&C1,FROMCARD) == true) {
                                if(checkifpossible(&C1,&C7,card_number)== true) {
                                    movenodewithnumber(&C1, &C7, card_number);
                                }
                            }

                            /** COLUMN 2 */
                            if (from == 2 && to == 1 && search(&C2,FROMCARD) == true) {
                                if(checkifpossible(&C2,&C1,card_number)== true) {
                                    movenodewithnumber(&C2, &C1, card_number);
                                }
                            }
                            if (from == 2 && to == 3 && search(&C2,FROMCARD) == true) {
                                if(checkifpossible(&C2,&C3,card_number)== true) {
                                    movenodewithnumber(&C2, &C3, card_number);
                                }
                            }
                            if (from == 2 && to == 4 && search(&C2,FROMCARD) == true) {
                                if(checkifpossible(&C2,&C4,card_number)== true) {
                                    movenodewithnumber(&C2, &C4, card_number);
                                }
                            }
                            if (from == 2 && to == 5 && search(&C2,FROMCARD) == true) {
                                if(checkifpossible(&C2,&C5,card_number)== true) {
                                    movenodewithnumber(&C2, &C5, card_number);
                                }
                            }
                            if (from == 2 && to == 6 && search(&C2,FROMCARD) == true) {
                                if(checkifpossible(&C2,&C6,card_number)== true) {
                                    movenodewithnumber(&C2, &C6, card_number);
                                }
                            }
                            if (from == 2 && to == 7 && search(&C2,FROMCARD) == true) {
                                if(checkifpossible(&C2,&C7,card_number)== true) {
                                    movenodewithnumber(&C2, &C7, card_number);
                                }
                            }

                            /** COLUMN 3 */
                            if (from == 3 && to == 1 && search(&C3,FROMCARD) == true) {
                                if(checkifpossible(&C3,&C1,card_number)== true) {
                                    movenodewithnumber(&C3, &C1, card_number);
                                }
                            }
                            if (from == 3 && to == 2 && search(&C3,FROMCARD) == true) {
                                if(checkifpossible(&C3,&C2,card_number)== true) {
                                    movenodewithnumber(&C3, &C2, card_number);
                                }
                            }
                            if (from == 3 && to == 4 && search(&C3,FROMCARD) == true) {
                                if(checkifpossible(&C3,&C4,card_number)== true) {
                                    movenodewithnumber(&C3, &C4, card_number);
                                }
                            }
                            if (from == 3 && to == 5 && search(&C3,FROMCARD) == true) {
                                if(checkifpossible(&C3,&C5,card_number)== true) {
                                    movenodewithnumber(&C3, &C5, card_number);
                                }
                            }
                            if (from == 3 && to == 6 && search(&C3,FROMCARD) == true) {
                                if(checkifpossible(&C3,&C6,card_number)== true) {
                                    movenodewithnumber(&C3, &C6, card_number);
                                }
                            }
                            if (from == 3 && to == 7 && search(&C3,FROMCARD) == true) {
                                if(checkifpossible(&C3,&C7,card_number)== true) {
                                    movenodewithnumber(&C3, &C7, card_number);
                                }
                            }

                            /** COLUMN 4 */
                            if (from == 4 && to == 1 && search(&C4,FROMCARD) == true) {
                                if(checkifpossible(&C4,&C1,card_number)== true) {
                                    movenodewithnumber(&C4, &C1, card_number);
                                }
                            }
                            if (from == 4 && to == 2 && search(&C4,FROMCARD) == true) {
                                if(checkifpossible(&C4,&C2,card_number)== true) {
                                    movenodewithnumber(&C4, &C2, card_number);
                                }
                            }
                            if (from == 4 && to == 3 && search(&C4,FROMCARD) == true) {
                                if(checkifpossible(&C4,&C3,card_number)== true) {
                                    movenodewithnumber(&C4, &C3, card_number);
                                }
                            }
                            if (from == 4 && to == 5 && search(&C4,FROMCARD) == true) {
                                if(checkifpossible(&C4,&C5,card_number)== true) {
                                    movenodewithnumber(&C4, &C5, card_number);
                                }
                            }
                            if (from == 4 && to == 6 && search(&C4,FROMCARD) == true) {
                                if(checkifpossible(&C4,&C6,card_number)== true) {
                                    movenodewithnumber(&C4, &C6, card_number);
                                }
                            }
                            if (from == 4 && to == 7 && search(&C4,FROMCARD) == true) {
                                if(checkifpossible(&C4,&C7,card_number)== true) {
                                    movenodewithnumber(&C4, &C7, card_number);
                                }
                            }

                            /** COLUMN 5 */
                            if (from == 5 && to == 1 && search(&C5,FROMCARD) == true) {
                                if(checkifpossible(&C5,&C1,card_number)== true) {
                                    movenodewithnumber(&C5, &C1, card_number);
                                }
                            }
                            if (from == 5 && to == 2 && search(&C5,FROMCARD) == true) {
                                if(checkifpossible(&C5,&C2,card_number)== true) {
                                    movenodewithnumber(&C5, &C2, card_number);
                                }
                            }
                            if (from == 5 && to == 3 && search(&C5,FROMCARD) == true) {
                                if(checkifpossible(&C5,&C3,card_number)== true) {
                                    movenodewithnumber(&C5, &C3, card_number);
                                }
                            }
                            if (from == 5 && to == 4 && search(&C5,FROMCARD) == true) {
                                if(checkifpossible(&C5,&C4,card_number)== true) {
                                    movenodewithnumber(&C5, &C4, card_number);
                                }
                            }
                            if (from == 5 && to == 6 && search(&C5,FROMCARD) == true) {
                                if(checkifpossible(&C5,&C6,card_number)== true) {
                                    movenodewithnumber(&C5, &C6, card_number);
                                }
                            }
                            if (from == 5 && to == 7 && search(&C5,FROMCARD) == true) {
                                if(checkifpossible(&C5,&C7,card_number)== true) {
                                    movenodewithnumber(&C5, &C7, card_number);
                                }
                            }

                            /** COLUMN 6 */
                            if (from == 6 && to == 1 && search(&C6,FROMCARD) == true) {
                                if(checkifpossible(&C6,&C1,card_number)== true) {
                                    movenodewithnumber(&C6, &C1, card_number);
                                }
                            }
                            if (from == 6 && to == 2 && search(&C6,FROMCARD) == true) {
                                if(checkifpossible(&C6,&C2,card_number)== true) {
                                    movenodewithnumber(&C6, &C2, card_number);
                                }
                            }
                            if (from == 6 && to == 3 && search(&C6,FROMCARD) == true) {
                                if(checkifpossible(&C6,&C3,card_number)== true) {
                                    movenodewithnumber(&C6, &C3, card_number);
                                }
                            }
                            if (from == 6 && to == 4 && search(&C6,FROMCARD) == true) {
                                if(checkifpossible(&C6,&C4,card_number)== true) {
                                    movenodewithnumber(&C6, &C4, card_number);
                                }
                            }
                            if (from == 6 && to == 5 && search(&C6,FROMCARD) == true) {
                                if(checkifpossible(&C6,&C5,card_number)== true) {
                                    movenodewithnumber(&C6, &C5, card_number);
                                }
                            }
                            if (from == 6 && to == 7 && search(&C6,FROMCARD) == true) {
                                if(checkifpossible(&C6,&C7,card_number)== true) {
                                    movenodewithnumber(&C6, &C7, card_number);
                                }
                            }

                            /** COLUMN 7 */
                            if (from == 7 && to == 1 && search(&C7,FROMCARD) == true) {
                                if(checkifpossible(&C7,&C1,card_number)== true) {
                                    movenodewithnumber(&C7, &C1, card_number);
                                }
                            }
                            if (from == 7 && to == 2 && search(&C7,FROMCARD) == true) {
                                if(checkifpossible(&C7,&C2,card_number)== true) {
                                    movenodewithnumber(&C7, &C2, card_number);
                                }
                            }
                            if (from == 7 && to == 3 && search(&C7,FROMCARD) == true) {
                                if(checkifpossible(&C7,&C3,card_number)== true) {
                                    movenodewithnumber(&C7, &C3, card_number);
                                }
                            }
                            if (from == 7 && to == 4 && search(&C7,FROMCARD) == true) {
                                if(checkifpossible(&C7,&C4,card_number)== true) {
                                    movenodewithnumber(&C7, &C4, card_number);
                                }
                            }
                            if (from == 7 && to == 5 && search(&C7,FROMCARD) == true) {
                                if(checkifpossible(&C7,&C5,card_number)== true) {
                                    movenodewithnumber(&C7, &C5, card_number);
                                }
                            }
                            if (from == 7 && to == 6 && search(&C7,FROMCARD) == true) {
                                if(checkifpossible(&C7,&C6,card_number)== true) {
                                    movenodewithnumber(&C7, &C6, card_number);
                                }
                            }
                        }
                    }
                }

                /** Collumn->Collumn */
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






