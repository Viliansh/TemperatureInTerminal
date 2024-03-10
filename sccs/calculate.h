#ifndef CALCULATE_H
#define CALCULATE_H

#include "Leadboard.h"

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



extern int calculate(int value, int mType, int cType) {
    
    int sum;

    switch(mType) {
        case 1:
            switch(cType) {
                case 2:
                    sum = (value * 9/5) + 32;
                    leadBoard();
                    printf(GREEN_TEXT "\n\nResult is: " YELLOW_TEXT"%d F°\n" RESET_TEXT, sum);
                    break;
                case 3:
                    sum = value + 273;
                    leadBoard();
                    printf(GREEN_TEXT "\nResult is: " YELLOW_TEXT"%d K°\n" RESET_TEXT, sum);
                    break;
            }
            break;
        case 2:
            switch(cType) {
                case 1:
                    sum = (value - 32) * 5/9;
                    leadBoard();
                    printf(GREEN_TEXT "\nResult is:" YELLOW_TEXT"%d C°\n" RESET_TEXT,sum);
                    break;
                case 3:
                    leadBoard();
                    sum = (value - 32) * 5/9 + 273;
                    printf(GREEN_TEXT "\nResult is:" YELLOW_TEXT"%d K°\n" RESET_TEXT,sum);
                    break;
            }
            break;
        case 3:
            switch(cType) {
                case 1:
                    sum = value - 273;
                    leadBoard();
                    printf(GREEN_TEXT "\nResult is::" YELLOW_TEXT"%d C°\n" RESET_TEXT,sum);
                    break;
                case 2:
                    sum = (value - 273) * 9/5 + 32;
                    leadBoard();
                    printf(GREEN_TEXT "\nResult is:" YELLOW_TEXT"%d F°\n" RESET_TEXT,sum);
                    break;

            }
            break;
        default:
            printf("Select a valid value!\n");
            break;
    }

    return 0;
}

/*
extern int calculate(int value, int mType, int cType) {
    if (mType == cType) {
        system("clear");
        printf("The convert and main types cant't be the same! Try Again...");
    }

    else if (mType == 1 && cType == 2){
        int sum = (value * 9/5) + 32;
        printf(RED_TEXT "\nResult is:" YELLOW_TEXT"%d F°" RESET_TEXT,sum);
    }
    else if(mType == 1 && cType == 3) {
        int sum = value + 273;
        printf(RED_TEXT "\nResult is:" YELLOW_TEXT"%d K°" RESET_TEXT,sum);
    }
    else if(mType == 2 && cType == 1) {
        int sum = (value - 32) * 5/9;
        printf(RED_TEXT "\nResult is:" YELLOW_TEXT"%d C°" RESET_TEXT,sum);
    }
    else if(mType == 2 && cType == 3) {
        int sum = (value - 32) * 5/9 + 273;
        printf(RED_TEXT "\nResult is:" YELLOW_TEXT"%d K°" RESET_TEXT,sum);
    }
    else if(mType == 3 && cType == 1){
        int sum = value - 273;
        printf(RED_TEXT "\nResult is:" YELLOW_TEXT"%d C°" RESET_TEXT,sum);
    }
    else if(mType == 3 && cType == 2) {
        int sum = (value - 273) * 9/5 + 32;
        printf(RED_TEXT "\nResult is:" YELLOW_TEXT"%d F°" RESET_TEXT,sum);
    }

    return 0;
}
*/

#endif // CALCULATE_H