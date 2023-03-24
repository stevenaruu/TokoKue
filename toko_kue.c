#include <stdio.h>
#include <string.h>
#include <windows.h>

struct kue {
    char cakeCode[6];
    char cakeName[50];
    int available;
    int price;
}kue[4];

void sell() {

    char input[10];
    int flag = 0;
    int available = 0;
    int idx = 0;

    do {

        printf("Input Cake Code [5 chars]: ");
        scanf(" %s", input);

        if(strcmp(input, kue[0].cakeCode) == 0){
            flag = 1;
            available = kue[0].available;
            idx = 0;
        }else if(strcmp(input, kue[1].cakeCode) == 0){
            flag = 1;
            available = kue[1].available;
            idx = 1;
        }else if(strcmp(input, kue[2].cakeCode) == 0){
            flag = 1;
            available = kue[2].available;
            idx = 2;
        }else if(strcmp(input, kue[3].cakeCode) == 0){
            flag = 1;
            available = kue[3].available;
            idx = 3;
        }

        if(flag == 0){
            printf("\n--- The Cake Code doesn't exist ---\n\n");
        }

    }while(flag != 1);

    int beli;
    int total = 0;

    do {

        printf("Input Quantity [0..%d]: ", available);
        scanf(" %d", &beli);

        if(beli > available){
            printf("\n...The quantity of cake is not enough...\n");
        }else{
            total = kue[idx].price * beli;
            kue[idx].available -= beli;
            printf("\n\nTotal price is : Rp %d,- x %d = Rp %d,-\n", kue[idx].price, beli, total);
        }

    }while(beli > available);

    printf("--- Thank You ---\n");
    
}

void addStock() {

    char input[10];
    int flag = 0;
    int idx = 0;

    do {

        printf("Input Cake Code [5 Chars]: ");
        scanf(" %s", input);

        if(strcmp(input, kue[0].cakeCode) == 0){
            flag = 1;
            idx = 0;
        }else if(strcmp(input, kue[1].cakeCode) == 0){
            flag = 1;
            idx = 1;
        }else if(strcmp(input, kue[2].cakeCode) == 0){
            flag = 1;
            idx = 2;
        }else if(strcmp(input, kue[3].cakeCode) == 0){
            flag = 1;
            idx = 3;
        }

        if(flag == 0){
            printf("\n--- The Cake Code doesn't exist ---\n\n");
        }        

    }while(flag != 1);

    int tambah;

    do {

        flag = 0;

        printf("Input Quantity [1..10]: ");
        scanf(" %d", &tambah);

        if(tambah <= 10){
            kue[idx].available += tambah;
            printf("\n\n--- Adding Stock Success---\n");
        }

    }while(tambah > 10);

}

int main(){

    strcpy(kue[0].cakeCode, "CK001");
    strcpy(kue[1].cakeCode, "CK009");
    strcpy(kue[2].cakeCode, "CK017");
    strcpy(kue[3].cakeCode, "CK023");

    strcpy(kue[0].cakeName, "Blueberry Cake");
    strcpy(kue[1].cakeName, "Chocochip Cake");
    strcpy(kue[2].cakeName, "Mayonise Cake");
    strcpy(kue[3].cakeName, "Strawberry ShortCake");

    kue[0].available = 13;
    kue[1].available = 5;
    kue[2].available = 24;
    kue[3].available = 7;

    kue[0].price = 25000;
    kue[1].price = 20000;
    kue[2].price = 30000;
    kue[3].price = 17500;

    int input;

    do{

        system("cls");
        
        puts("BLUE CAKE SHOP CASHIER");
        puts("======================");
        puts("");

        printf("No.  | Cake Code | Cake Name            | Available | Price      \n");
        printf("----------------------------------------------------------------\n");

        for(int i = 0; i < 4; i++){
            printf("0%d.  | %-9s | %-20s | %-9d | Rp. %d,-\n", i+1, kue[i].cakeCode, kue[i].cakeName, kue[i].available, kue[i].price);
        }

        printf("----------------------------------------------------------------\n\n");

        printf("Menu :\n");
        printf("1. Sell\n");
        printf("2. Add Stock\n");
        printf("3. Exit\n");
        printf("Input choice : ");
        scanf("%d", &input);

        switch(input){

            case 1:
                printf("\n");
                sell();
                getchar();
                break;
            case 2:
                printf("\n");
                addStock();
                getchar();
                break;
            case 3:
                printf("\n");
                printf("-- Thank You --");
                break;
            default:
                break;

        }

        getchar();

    }while(input != 3);



}