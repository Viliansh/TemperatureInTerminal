#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define RESET_TEXT "\x1b[0m"
#define BLACK_TEXT "\x1b[30m"
#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define BLUE_TEXT "\x1b[34m"
#define MAGENTA_TEXT "\x1b[35m"
#define CYAN_TEXT "\x1b[36m"
#define WHITE_TEXT "\x1b[37m"

int calculate(int value, int mType, int cType){
    if (mType == cType){
        system("clear");
        printf("The convert and main types can't be the same! Try again...");
    }
    else if (mType == 1 && cType == 2){
        int sum = (value * 9/5) + 32;
        printf(RED_TEXT "Result is:" YELLOW_TEXT"%d F°" RESET_TEXT,sum);
    }
    else if(mType == 1 && cType == 3) {
        int sum = value + 273;
        printf(RED_TEXT "Result is:" YELLOW_TEXT"%d K°" RESET_TEXT,sum);
    }
    else if(mType == 2 && cType == 1) {
        int sum = (value - 32) * 5/9;
        printf(RED_TEXT "Result is:" YELLOW_TEXT"%d C°" RESET_TEXT,sum);
    }
    else if(mType == 2 && cType == 3) {
        int sum = (value - 32) * 5/9 + 273;
        printf(RED_TEXT "Result is:" YELLOW_TEXT"%d K°" RESET_TEXT,sum);
    }
    else if(mType == 3 && cType == 1){
        int sum = value - 273;
        printf(RED_TEXT "Result is:" YELLOW_TEXT"%d C°" RESET_TEXT,sum);
    }
    else if(mType == 3 && cType == 2) {
        int sum = (value - 273) * 9/5 + 32;
        printf(RED_TEXT "Result is:" YELLOW_TEXT"%d F°" RESET_TEXT,sum);
    }

    return 0;
}

int leadBoard() {
    
    FILE* ptr;
    char ch;

    ptr = fopen("leadBoard.txt", "r");
    printf(RED_TEXT "##########################################################################" YELLOW_TEXT);
    do{
        ch = fgetc(ptr);
        printf("%c", ch);
    } while (ch != EOF);

    printf(RESET_TEXT "Temperature Conversor - Made by:" BLUE_TEXT " fleipekkj13 (github)\n" RESET_TEXT);
    
    printf(RED_TEXT "##########################################################################\n" RESET_TEXT);

    fclose(ptr);
    return 0;
}

int listCon() {
    char listaStrings[3][20] = {
        "1-Celsius",
        "2-Fahrenheit",
        "3-Kelvin"
    };
    for (int i = 0; i < 3; i++) {
        printf(GREEN_TEXT "\n%s\n" RESET_TEXT, listaStrings[i]);
    }

    return 0;
}

int mained() {
    while (1){

        listCon();
        int mainType;
        printf("Select your main type for convert: ");
        if(scanf("%d", &mainType) == 1 ){
            system("clear");
            leadBoard();
            listCon();
            printf("Now, selecty the type for convert: ");
            int convertType;
            if(scanf("%d", &convertType) == 1) {
                system("clear");
                leadBoard();
                int valueToConvert;
                printf("Enter the value to convert: ");
                if(scanf("%d", &valueToConvert) == 1) {
                    printf("Converting...\n");
                    system("clear");
                    leadBoard();
                    printf("\n\n\n");
                    calculate(valueToConvert, mainType, convertType);
                    break;
                } else {
                    system("clear");
                    leadBoard();
                    printf( RED_TEXT"Insert a valid value!" RESET_TEXT);
                    while (getchar() != '\n');                     
                }
            } else {
                system("clear");
                leadBoard();
                printf( RED_TEXT"Insert a valid value!" RESET_TEXT);
                while (getchar() != '\n');                
            }
        } else {
            system("clear");
            leadBoard();
            printf( RED_TEXT"Insert a valid value!" RESET_TEXT);
            while (getchar() != '\n');
        }
    }
    return 0;
}

int main() {
    leadBoard();
    mained();
    return 0;
}