#include "MyUtil.h"


void cls(int time) {
    sleep(time);
    #ifdef _WIN32  // For Windows
        system("cls");
    #else  // For UNIX-like systems (Linux, macOS, etc.)
        system("clear");
    #endif
}

void ln() {
    printf("\n");
}


int randRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int ask2op(const char* question) {
    printf("%s (y/n): ", question);

    char response;
    do {
        scanf(" %c", &response);
        if (response == 'y' || response == 'Y') {
            return 1;  // Yes
        } else if (response == 'n' || response == 'N') {
            return 0;  // No
        } else {
            printf("Invalid input. Please enter 'y' for Yes or 'n' for No: ");
        }
    } while (1);  // Keep asking until a valid response is entered
}

/**!Pace o str como referencia ou seja, passe o seu indereço Ex.: &minhaStr*/
void capStr(char** str) {
    if (str == NULL || *str == NULL) {
        return;  // Handle NULL string pointer or empty string
    }

    for (int i = 0; (*str)[i] != '\0'; i++) {
        (*str)[i] = toupper((*str)[i]);
    }
}