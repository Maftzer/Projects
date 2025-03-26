#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


// Да довърша:
// Когато сложа две едни и съши букви, слага на тази на правилното място G, а на другата слага Y, а трябва да не е Y, а "_"
// Да проверя когато думата има две едни и съши бувки като в Apple, как се държи програмата.
// В момента когато спечеля, не печеля поради някаква причинаs

void checker();

int main(){
    srand(time(NULL));

    char *arr[] = {"Plane", "Train", "Pilot", "Brick", "Flame", "Grasp","Happy",
        "Plant","Light","Cloud","Sharp","Dream","Stone","Quick","Table", 
    };
    int random_index = rand() % 14;
    char *random_word = arr[random_index];
    char guess_word[6];
    char random_word_lower[5];
    char guess_word_lower[5];

    printf("Guess a 5-letter word: \n");
    
    
    printf("%s\n", random_word_lower); //! за debugване

    for(int i = 0; i <=5; i++){
        char result_word[5] = {'_', '_', '_', '_', '_'};
        
        printf("%s\n", random_word); //! за debugване

        scanf("%s", guess_word);
        
        for(int i = 0; i<=4; i++){
            random_word_lower[i] = tolower(random_word[i]);
            guess_word_lower[i] = tolower(guess_word[i]);
        }
        int len_guess_word = strlen(guess_word);
        while(strlen(guess_word) != 5){
            printf("Incorrect lenght, enter a 5-letter word, your current length is %ld!\n", strlen(guess_word));
            scanf("%s", guess_word);
        }

        printf("Your guess: %s\n", guess_word);

        for(int i = 0; i < 5; i++){
            if(guess_word_lower[i] == random_word_lower[i]){
                result_word[i]= 'G';
            }
            else if(result_word[i] == '_'){
                for(char j = 0; j <= 5; j++ ){
                    if(guess_word_lower[i] == random_word_lower[j]){
                        result_word[i] = 'Y';
                    }
                }

            }
            checker(guess_word_lower, random_word_lower, result_word);
        }
        
    
    }
    printf("You did not guess, the word was: %s", random_word);
    return 0;

}


void checker(char guess_word[5], char random_word[5], char result_word[5]){
    if(strcmp(guess_word, random_word) == 0){
        printf("You guessed the word! It is %s\n", random_word);
        return;
    }
    else{
        printf("%s\n", result_word);
    }
}