#ifndef BOARD_H
#define BOARD_H

#include "Leadboard.h"
#include "calculate.h"
#include <stdlib.h>
#include <stdio.h>


#define RESET_TEXT "\x1b[0m"
#define BLACK_TEXT "\x1b[30m"
#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define BLUE_TEXT "\x1b[34m"
#define MAGENTA_TEXT "\x1b[35m"
#define CYAN_TEXT "\x1b[36m"
#define WHITE_TEXT "\x1b[37m"

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

extern int board() {

    int mainType;
    int convertType;
    int valueToConvert;

    while(1) {
        leadBoard();
        listCon();
        printf(BLUE_TEXT "Input your main type value: " YELLOW_TEXT RESET_TEXT);
        if(scanf("%d", &mainType) == 1 && mainType <= 3) {
            system("clear");
            break;
        } else {
            system("clear");
            printf(YELLOW_TEXT "Error insert a valid main value!\n\n" RESET_TEXT);
            while(getchar() != '\n');
        }
    }
    while(1) {
        leadBoard();
        listCon();
        printf(BLUE_TEXT "Input the TYPE for convert: " YELLOW_TEXT);
        if(scanf("%d", &convertType) == 1 && convertType <=3 && convertType != mainType) {
            system("clear");
            break;
        } else {
            system("clear");
            printf(YELLOW_TEXT "Error insert a valid value to convert!\nOr insert a diferent value of your main value...\n" RESET_TEXT);
            while(getchar() != '\n');
        }
    }

    while(1) {
       leadBoard();
       printf(BLUE_TEXT "Insert the value for convert: " YELLOW_TEXT);
       if(scanf("%d", &valueToConvert) == 1) {
            system("clear");
            break;
       } else {
            system("clear");
            printf(YELLOW_TEXT "Insert only NUMBERS!\n\n" RESET_TEXT);
            while(getchar() != '\n');
       }
    }

    calculate(valueToConvert, mainType, convertType);


/*

    system("clear");
    leadBoard();
    listCon();

    do{
        printf("Now, select the type for convert: ");
    } while (scanf("%d", &convertType) != 1 && convertType <= 3);

    system("clear");
    leadBoard();
    listCon();

    do{
        printf("Enter the value for convert: ");
    } while (scanf("%d", &valueToConvert) != 1);


    system("clear");
    leadBoard();
    listCon();

    calculate(valueToConvert, mainType, convertType);
*/
    return 0;

}
#endif // BOARD_H