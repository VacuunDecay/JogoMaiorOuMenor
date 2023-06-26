#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MyUtil.h"
#include "Myfilelib.h"

#define FILENAME "random_numbers.bin"
#define NUM_COUNT 100

#define SAVEFILE "save.bin"
#define USERSFILE "users.bin" 
#define IDMIN 1000
#define IDMAX 9999


void playGame(int jogId) {
    int score = 0;
    int currentNumber, nextNumber;
    char userChoice;
    char aux[5];
    scanf("%s", &aux);

    Log* log = (Log*)malloc(sizeof(Log));





    // Generate the first random number
    currentNumber = randRange(1, 20);

    do {
        cls(0);
        printf("Numero atual: %d\n", currentNumber);
        printf("Escolha (z - menor / x - maior): ");
        scanf(" %c", &userChoice);


        // Generate the next random number
        nextNumber = randRange(1, 20);

        // Compare the user's choice with the next number
        if ((userChoice == 'z' && nextNumber < currentNumber) ||
            (userChoice == 'x' && nextNumber > currentNumber)) {
            printf("Parabens! Voce acertou.\n");
            score++;
        } else {
            printf("Resposta incorreta. Fim do jogo!\n");
            break;
        } 

        currentNumber = nextNumber;

        sleep(1);
        ln(); // Break two lines
    } while (userChoice != '0');

    printf("Pontuacao: %d\n", score);

    viewLeaderboard();

    printf("Fim do jogo!\n");
}


void viewLog() {
    // Code for viewing the log
}

void viewLeaderboard() {
    // Code for viewing the leaderboard
}

void starGame() {
    int id;
    char* nome = (char*)malloc(sizeof(char)*5);

    FILE* fp = fopen(USERSFILE, "rb");
    

    printf("Nome:");
    scanf("%d",&nome);
    
    capStr(&nome);
    id = nomeToId(fp, nome);

    if(id == -1){ //Nome nao encontrado no banco de dados
        while(!isIdUnique(fp, id)){
            id = randRange(IDMIN, IDMAX);
        }
        fclose(fp);
        
        fp = fopen(USERSFILE, "ab");
        loadJog(fp, id, nome);
        fclose(fp);
    }
    



    playGame(id);
}

int main() {
    FILE* fp = fopen(SAVEFILE, "wb");
    if (!fp) {
        printf("Error opening the save file.\n");
        return 1;
    }

    // Perform any necessary file operations

    fclose(fp);

    int choice;
    do {
        printf("Menu:\n");
        printf("1 - Jogar\n");
        printf("2 - Ver log\n");
        printf("3 - Leaderboard\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);
        ln(); // Break two lines

        switch (choice) {
            case 1:
                starGame();
                break;
            case 2:
                viewLog();
                break;
            case 3:
                viewLeaderboard();
                break;
            case 4:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }

        ln(); // Break two lines
    } while (choice != 4);

    return 0;
}
