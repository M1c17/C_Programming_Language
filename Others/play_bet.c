#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Simple Betting Game:
Jack, Queen, King  - computer shuffles these cards 
player has to guess the position of the queen
if he wins, he takes 3*bet
if he looses, he looses the bet amount 
player has $100 initially
*/

int cash = 100;

void Play(int );

int main(){
    int bet;
    
    printf("Welcome to the Virtual Casino\n");
    printf("Total cash = $%d\n", cash);

    while (cash > 0){
        printf("What is your bet? $");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash){
            break;
        }
        Play(bet);
        printf("*************************************");
    }
}

void Play(int bet){
    // local variable
    // char Cards[3] = {'J', 'Q', 'K'};
    // create a variable on the heap
    char *Cards = (char *)malloc(1000*sizeof(char));
    Cards[0] = 'J'; Cards[1] = 'Q'; Cards[2] = 'k';
    printf("Shuffling....\n");
    srand(time(NULL));               // seeding random number generator
    int i;
    for (i = 0; i < 5; i++){
        int x = rand() % 3;         // want a number between 0 and 2 
        int y = rand() % 3;
        int temp = Cards[x];
        Cards[x] = Cards[y];
        Cards[y] = temp;                // swap characters at position x and y 
    }
    int playerGuess;
    printf("What is the position of queen -> 1, 2 or 3?\n");
    scanf("%d", &playerGuess);
    if (Cards[playerGuess - 1] == 'Q'){
        cash += 3 * bet;
        printf("You Win! = Result = \"%c %c %c\" Total Cash = %d\n", Cards[0], Cards[1], Cards[2], cash);
    }
    else{
        cash -= bet;
        printf("You looses! = Result = \"%c %c %c\" Total Cash = %d\n", Cards[0], Cards[1], Cards[2], cash);
    }
    free(Cards);

}