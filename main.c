#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>

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


// print the linked list value
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
char pointer(struct Node *p, int n) {
    int k = 0;

    while (p != NULL) {
        if(k == n) {
        return p->data;
            }
        p = p->next;
    }
}
void display( const struct Node *node ) {
    while (node != NULL) {
        printf(" %s ", node->data);
        node = node->next;
    }
}
void displaye( const struct Node *node ) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}
void deleteNode(struct Node** head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

void one(struct Node *head);
Node * createLinkedlistS();
void printList(struct Node* n);
Node * heartLinkedlistS(char n);

Node *kindlistS(int n);
void push(struct Node** head_ref, char new_data);


int main() {

    /** Initializing nodes and allocating memory */
    Node * head = NULL;
    head = createLinkedlistS();

    /** Collumns */
    struct Node* C1 = NULL;
    struct Node* C2 = NULL;
    struct Node* C3 = NULL;
    struct Node* C4 = NULL;
    struct Node* C5 = NULL;
    struct Node* C6 = NULL;
    struct Node* C7 = NULL;
    /** Decks */
    struct Node* F1 = NULL;
    struct Node* F2 = NULL;
    struct Node* F3 = NULL;
    struct Node* F4 = NULL;

    Node * SPADES = NULL;
    SPADES = kindlistS(1);
    display(SPADES);
    printf("\n");

    Node * HEARTS = NULL;
    HEARTS = kindlistS(2);
    display(HEARTS);
    printf("\n");

    Node * DIAMONDS = NULL;
    DIAMONDS = kindlistS(3);
    display(DIAMONDS);
    printf("\n");

    Node * CLUBS = NULL;
    CLUBS = kindlistS(4);
    display(CLUBS);
    printf("\n");
    //qlist(p.head2);
    //plist(head,5);

    push(&C1, "hi");
    push(&C1, "hi");
    push(&C1, "hi");
    push(&C1, "hi");
    display(C1);
    deleteNode(&C1,3);

    display(C1);
    printf("\n");
    //delete(pointer(CLUBS,6));


    printf("\n");
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n");
    printf("\n");
    printf("%c%c%c%c%c%c[]\tF1",plist(head,1),plist(head,2),plist(head,3),plist(head,4),plist(head,5),plist(head,6),plist(head,7));
    printf("\n");
    printf("%c%c%c%c%c%c[]\tF2",plist(head,8),plist(head,9),plist(head,10),plist(head,11),plist(head,12),plist(head,13),plist(head,14));
    printf("\n");
    printf("%c%c%c%c%c%c[]\tF3",plist(head,15),plist(head,16),plist(head,17),plist(head,18),plist(head,19),plist(head,20),plist(head,21));
    printf("\n");
    printf("%c%c%c%c%c%c[]\tF4",plist(head,22),plist(head,23),plist(head,24),plist(head,25),plist(head,26),plist(head,27),plist(head,28));
    printf("\n");
    printf("%c%c%c%c%c%c",plist(head,29),plist(head,30),plist(head,31),plist(head,32),plist(head,33),plist(head,34),plist(head,35));
    printf("\n");
    printf("%c%c%c%c%c%c",plist(head,36),plist(head,37),plist(head,38),plist(head,39),plist(head,40),plist(head,41),plist(head,42));
    printf("\n");
    printf("%c%c%c%c%c%c",plist(head,43),plist(head,44),plist(head,45),plist(head,46),plist(head,47),plist(head,48),plist(head,49));
    printf("\n");
    printf("%c%c%c%c%c%c",plist(head,50),plist(head,51),plist(head,52),plist(head,53),plist(head,54),plist(head,55),plist(head,56));
    printf("\n");
    printf("%c%c%c%c%c%c",plist(head,57),plist(head,58),plist(head,59),plist(head,60),plist(head,61),plist(head,62),plist(head,63));
    printf("\n");
    printf("%c%c%c%c%c%c",plist(head,64),plist(head,65),plist(head,66),plist(head,67),plist(head,68),plist(head,69),plist(head,70));
    printf("\n");
    printf("\n");

    char COMMAND;
    printf("LAST COMMAND %c.\n", COMMAND);
    char Message;
    printf("Message: %c.\n", Message);
    char INPUT;
    printf("INPUT > ");scanf("%c", &INPUT);
    return 0;
}

Node * createLinkedlistS(){
    struct Node* head;
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

    head = ACES;
}
void one(struct Node *head)
{
    if (head == NULL)
        return;
    srand(time(NULL));

    int result = head->data;
    struct Node *current = head;
    int n;
    for (n = 2; current != NULL; n++)
    {
        if (rand() % n == 0)
            result = current->data;
        current = current->next;
    }
    printf(result);
}


Node * kindlistS(int n){


    struct Node* head;
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
    KINGS->data = "KS"; KINGS->next = NULL;
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
    KINGH->data = "KH"; KINGH->next = NULL;
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
    KINGD->data = "KD"; KINGD->next = NULL;
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

    if (n==1) {
        head = ACES;
    }
    if (n==2) {
        head = ACEH;
    }
    if (n==3) {
        head = ACED;
    }
    if (n==4) {
        head = ACEC;
    }
}


void push(struct Node** head_ref, char new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}