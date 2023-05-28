//Necati Koçak
//150120053
//Main Goal: Multiply two large numbers
#include <stdio.h>
#include <stdlib.h>

// Create LinkedList
struct node{
    int number;
    struct node *next;
};
char multiplicandNumberDigits;
char multiplierNumberDigits;
int base;

//Heads and Tails

struct node *headMultiplicand =NULL;
struct node *tailMultiplicand = NULL;

struct node *newLinkedListHead = NULL;
struct node *newLinkedListTail = NULL;

struct node *headMultiplier =NULL;
struct node *tailMultiplier = NULL;

//adding new node to newlinkedlist
void addNewNode(struct node** head, int new_data) {

    if(newLinkedListHead ==NULL){
        struct node *new = (struct node *) malloc(sizeof(struct node));
        new->number =new_data;
        new->next = NULL;
        newLinkedListHead = newLinkedListTail = new;
    }
    else{
        struct node *new = (struct node *) malloc(sizeof(struct node));
        new->number=new_data;
        new->next=NULL;

        newLinkedListTail->next=new;
        newLinkedListTail=new;


    }

}

//Printing Numbers

int PrintLinkedList(struct node *indexHead){
    struct node *printing = indexHead;
    while (printing !=NULL){
        printf("%d",printing->number);
        printing = printing->next;
    }
};

//multiply function
void MultiplyNumber(struct node* MultiplicandHead,struct node* MultiplierHead,struct node** newLinkedListHead){
    int digitOne = 0;
    int digitTwo =0;
    while(MultiplicandHead || MultiplierHead){

        if(MultiplicandHead){


            digitOne = digitOne * base + MultiplicandHead->number;
            MultiplicandHead = MultiplicandHead->next;


        }
        if(MultiplierHead){
            digitTwo = digitTwo * base + MultiplierHead->number;

            MultiplierHead = MultiplierHead->next;

        }
    }

    int result = digitOne * digitTwo;
    while (result) {

        int res=result%base;
        addNewNode(newLinkedListHead,res);
        result=result / base;

    }


}

// reverse function
struct node* reverse(struct node *head) {
    struct node *prvs = NULL;
    struct node *next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prvs;
        prvs = head;
        head = next;
    } head = prvs;
    return head;
}

int main(int argc,char* argv[]) {

    if (argc == 1)
        printf("Error message!");
    if (argc >= 2) {
        FILE *number_text = fopen(argv[1], "r");
        while (1) {
            multiplicandNumberDigits = getc(number_text);

            if (multiplicandNumberDigits == '\n') {
                break;
            } else {

                if (headMultiplicand == NULL) {
                    struct node *new1 = (struct node *) malloc(sizeof(struct node));
                    new1->number = (((int) (multiplicandNumberDigits)) - 48);
                    new1->next = NULL;
                    headMultiplicand = tailMultiplicand = new1;

                } else {
                    struct node *new1 = (struct node *) malloc(sizeof(struct node));
                    new1->number = (((int) (multiplicandNumberDigits)) - 48);
                    new1->next = NULL;
                    tailMultiplicand->next = new1;
                    tailMultiplicand = new1;
                }
            }
        }
        //---------------------------Multiplier----------------------------------
        while (1) {
            multiplierNumberDigits = getc(number_text);
            if (multiplierNumberDigits == '\n') {
                break;
            }
            if (headMultiplier == NULL) {
                struct node *new = (struct node *) malloc(sizeof(struct node));

                new->number = (((int) (multiplierNumberDigits)) - 48);
                new->next = NULL;

                headMultiplier = tailMultiplier = new;
            } else {
                struct node *new = (struct node *) malloc(sizeof(struct node));
                new->number = (((int) (multiplierNumberDigits)) - 48);
                new->next = NULL;


                tailMultiplier->next = new;
                tailMultiplier = new;
            }
        }
        //     ------------------------------BASE------------------------------------
        fscanf(number_text, "%d", &base);


        PrintLinkedList(headMultiplicand);

        printf("\n");

        PrintLinkedList(headMultiplier);
        printf("\n");


        MultiplyNumber(headMultiplicand, headMultiplier, &newLinkedListHead);

        // PrintLinkedList(newLinkedListHead);
        printf("\n");

        newLinkedListHead = reverse(newLinkedListHead);

        PrintLinkedList(newLinkedListHead);

        printf("\n");

        scanf("%d", &base);
        return 0;
    }
}