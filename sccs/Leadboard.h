#ifndef LEADBOARD_H
#define LEADBOARD_H

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

//Print the program's main screen.
extern int leadBoard() {

    FILE* ptr;
    char ch;

    ptr = fopen("sccs/leadBoard.txt", "r");
    if (ptr == NULL) {
        perror("Erro ao abrir o arquivo");
    }
    printf(RED_TEXT "##########################################################################\n" YELLOW_TEXT);
    do{
        ch = fgetc(ptr);
        printf("%c", ch);
    } while (ch != EOF);

    printf(RESET_TEXT "Temperature Conversor - Made by:" BLUE_TEXT " fleipekkj13 (github)\n" RESET_TEXT);
    
    printf(RED_TEXT "##########################################################################\n" RESET_TEXT);

    fclose(ptr);

    return 0;
}

#endif // LEADBOARD