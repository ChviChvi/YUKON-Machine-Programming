#include <stdio.h>
#include <malloc.h>
#include <time.h>
/** Creates the node structure */
typedef struct Node {
    char *data;
    struct Node* next;
}Node;

typedef struct private private;

typedef struct data data;

// print the linked list value
char plist(struct Node *p, int n) {
    int k =0;
    while (p != NULL) {
        //printf("%s ", p->data);
        k++;
        if(k == n)
            printf("%s \t", p->data);
        p = p->next;
    }

}//ok

void one(struct Node *head);
Node * createLinkedlistS();
//void printList(struct Node* n);

int main() {

    /** Initializing nodes and allocating memory */
    Node * head = NULL;

    head = createLinkedlistS();
    //plist(head,5);
    //printLinkedlist(head);


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