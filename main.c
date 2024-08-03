#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define FILENAME "random_numbers.txt"

void rand_r() ;
void rand_s();
void rand_g();
int generate_unique_random();
int is_duplicate(int );
void store_number(int );
int main(void) {
    //rand_r();
    //rand_s();
    //rand_g();
    for(int i=0;i<5;i++) {
        printf("%d",generate_unique_random());
    }


}
void rand_r() {
    int num;
    for(int i=0;i<5;i++) {
        //num=rand();
        num=rand()%100;// Define constraints to limit the range to 0-99
        printf("\tRandom number is %d\n ",num);
    }
    for(int i=0;i<5;i++) {
        num=rand();
        //num=rand()%100;
        printf("\tRandom number is %d\n ",num);
    }
}
void rand_s() {
    int num;
    srand(time(NULL));
    for(int i=0;i<5;i++) {
        num=rand();
        //num=rand()%100;
        printf("\tRandom number is %d\n ",num);
    }
}
void rand_g() {
    int num;
    srand(getpid());
    for(int i=0;i<5;i++) {
        num=rand();
        //num=rand()%100;
        printf("\tRandom number is %d\n ",num);}}

int generate_unique_random() {
    srand(time(NULL) ^ getpid());
    int random_number;
    do {
        random_number = rand();
    } while (is_duplicate(random_number));
    store_number(random_number);
    return random_number;}

int is_duplicate(int num) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) return 0; // File doesn't exist yet, no duplicates

    int stored_num;
    while (fscanf(file, "%d", &stored_num) != EOF) {
        if (stored_num == num) {
            fclose(file);
            return 1; }}
    fclose(file);
    return 0; }
void store_number(int num){
    FILE *file = fopen(FILENAME, "a");
    if (file != NULL) {
        fprintf(file, "%d\n", num);
        fclose(file);
    }
}

