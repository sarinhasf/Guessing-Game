#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void game(){
    printf("Choose the difficulty level:\n (1)easy (2)medium (3)hard\n");
    int level, attempts;
    scanf("%d", &level);
    switch (level)
    {
    case 1:
        attempts = 20;
        break;
    case 2:
        attempts = 15;
        break;
    case 3:
        attempts = 6;
        break;
    }
    int segundos = time(0);
    srand(segundos); //semente para sortear valores
    int num_big = rand(), kick;
    double points;
    int num_secret = num_big % 100; //resto de 100 pq o num é mt alto
    //printf("%d", num_secret);
    while(attempts>0){ //infinite loop
        printf("\n[%d move]\n", attempts);
        printf("Write a number:\n");
        scanf("%d", &kick);
        points = (double)(kick - num_big) / (double)2;
        if(kick<0){ //case number less that 0
            printf("you dont can to kick negative number\n");
            continue; //volta para o loop daq
        }
        int correct = kick == num_secret;
        int greater = kick > num_secret;
        if(correct){
            printf("You are right!\n[Your points]: %f\n", points);
            printf("thanks to play!!\n");
            printf("               /|  /|  ---------------------------\n");
            printf("               ||__||  |                         |\n");
            printf("              /   O O\\__      you are very       |\n");
            printf("              /          \\      good man         |\n");
            printf("             /      \\     \\                      |\n");
            printf("            /   _    \\     \\ ---------------------\n");
            printf("           /    |\\____\\     \\      |\n");
            printf("          /     | | | |\\____/      ||\n");
            printf("         /       \\| | | |/ |     __||\n");
            printf("        /  /  \\   -------  |_____| ||\n");
            break;
        }
        else if(greater){
            printf("the number is greater than the guessed\n");
        }
        else{
            printf("the number is less than the guessed\n");
            printf("Try again\n");
        }
        attempts--;
        if(attempts == 0){
            printf("wow you lost!\n");
            printf("  _\n");
            printf(" | |\n");
            printf(" | |===( )   //////\n");
            printf(" |_|   |||  | o o|\n");
            printf("       |||  ( c  )                  ____\n");
            printf("        ||| \\= /                   ||   \\_\n");
            printf("          ||||||                   ||     |\n");
            printf("          ||||||                ...||__/|-| \n");
            printf("          ||||||             __|________|__\n");
            printf("            |||             |______________| \n");
            printf("            |||             || ||      || || \n");
            printf("            |||             || ||      || || \n");
            printf("------------|||-------------||-||------||-||-------\n");
            printf("            |__>            || ||      || || \n");
            
        }
} 
}
int main(){
    printf("**********************************\n");
    printf("*  Welcome to the guessing game  *\n");
    printf("**********************************\n");
    game();
    while(1){
    printf("Want to play again?\n[1].yes [2].no\n");
    int k=0;
    scanf("%d", &k);
    if(k==2){
        break;
    }
    game();
    }
    return 0;
}