#include <stdio.h>

// no test

int reset;
int question_1;
int question_2;
int question_3;
int question_4;
int question_5;
int question_6;
int question_7;
int count = 0;
int mistake = 0;
int main()
{
    printf("Test\n");
    do {
        reset = 0;
        printf("When was the first world war?\n");
        printf("1. 1913 - 1918\n");
        printf("2. 1914 - 1919\n");
        printf("3. 1914 - 1918\n");
        printf("4. 1912 - 1916\n");
        printf("Your choice: ");

        scanf("%d", &question_1);
        switch (question_1)
        {
            case 1:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 2:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 3:
                printf("Correctly\n");
                count++;
                break;
            case 4:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            default:
                reset = 1;
                printf("Re-enter the answer\n");
        }
    } while (reset == 1);
    do {
        reset = 0;
        printf("The most popular element in the world?\n");
        printf("1. H\n");
        printf("2. Ne\n");
        printf("3. Fe\n");
        printf("4. C\n");
        printf("Your choice: ");
        scanf("%d", &question_2);
        switch (question_2) {
            case 1:
                printf("Correctly\n");
                count++;
                break;
            case 2:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 3:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 4:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            default:
                reset = 1;
                printf("Re-enter the answer\n");

        }
    }while (reset == 1);
    do {
        reset = 0;
        printf("In what year founded Moscow?\n");
        printf("1. 1123\n");
        printf("2. 1147\n");
        printf("3. 1136\n");
        printf("4. 1154\n");
        printf("Your choice: ");
        scanf("%d", &question_3);
        switch (question_3) {
            case 1:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 2:
                printf("Correctly\n");
                count++;
                break;
            case 3:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 4:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            default:
                reset = 1;
                printf("Re-enter the answer\n");
        }
    }while (reset == 1);
    do {
        reset = 0;
        printf("The result is 12*6\n");
        printf("1. 70\n");
        printf("2. 68\n");
        printf("3. 74\n");
        printf("4. 72\n");
        printf("Your choice: ");
        scanf("%d", &question_4);
        switch (question_4) {
            case 1:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 2:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 3:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 4:
                printf("Correctly\n");
                count++;
                break;
            default:
                reset = 1;
                printf("Re-enter the answer\n");
        }
    }while (reset == 1);
    do {
        reset = 0;
        printf("The largest planet in the solar system??\n");
        printf("1. Jupiter\n");
        printf("2. Saturn\n");
        printf("3. Mars\n");
        printf("4. Neptune\n");
        printf("Your choice: ");
        scanf("%d", &question_5);
        switch (question_5) {
            case 1:
                printf("Correctly\n");
                count++;
                break;
            case 2:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 3:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 4:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            default:
                reset = 1;
                printf("Re-enter the answer\n");
        }
    }while (reset == 1);
    do {
        reset = 0;
        printf("The record running speed of a human??\n");
        printf("1. 40 km / h\n");
        printf("2. 30 km / h\n");
        printf("3. 25 km / h\n");
        printf("4. 45 km / h\n");
        printf("Your choice: ");
        scanf("%d", &question_6);
        switch (question_6) {
            case 1:
                printf("Correctly\n");
                count++;
                break;
            case 2:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 3:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 4:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            default:
                reset = 1;
                printf("Re-enter the answer\n");
        }
    }while (reset == 1);
    do {
        reset = 0;
        printf("The Height Of Everest ??\n");
        printf("1. 9  635 m\n");
        printf("2. 8  848 m\n");
        printf("3. 7  324 m\n");
        printf("4. 10 245 m\n");
        printf("Your choice: ");
        scanf("%d", &question_7);
        switch (question_7) {
            case 1:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 2:
                printf("Correctly\n");
                count++;
                break;
            case 3:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            case 4:
                mistake++;
                printf("Mistake %d\n", mistake);
                break;
            default:
                reset = 1;
                printf("Re-enter the answer\n");
        }
    }while (reset == 1);
    printf("Mistake : %d\n", mistake);
    printf("count : %d\n", count);
    if (count == 7)
        {
            printf("grade : 5");
        }
    if (count >= 5)
        {
            printf("grade : 4");
        }
    if (count >= 3)
        {
            printf("grade : 3");
        }
    else
    {
        printf("grade : 2");
    }
    return 0;
}
