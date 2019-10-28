#include <stdio.h>
#include <stdlib.h>
void answer3right (int summ1,int summ2, int ans1, int ans2, int ans3){
    char resulted[3];

    printf("%d+%d =\n 1) %d\n 2) %d\n 3) %d\n", summ1,summ2,ans1,ans2,ans3);
    scanf("%s", resulted);

    int answered = 0;
    answered = atoi(resulted);


    switch (answered){
        case 1: printf("NO"); break;
        case 2: printf("NO"); break;
        case 3: printf("YES"); break;
        default: printf("NOT CORRECT");
    };
}
