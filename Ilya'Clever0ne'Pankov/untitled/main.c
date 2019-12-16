#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b)              \
        {                       \
             *a = *a + *b;      \
             *b = *a - *b;      \
             *a = *a - *b;      \
        }                       \

void setSeparator(char *separator)
{
    printf("Words separates by: \n");
    scanf("%s", separator);
}

int findSeparator(char *string, char *separator, int index)
{
    while(index < strlen(string))
    {
        if(memcmp(string + index, separator, strlen(separator)) == 0)
        {
            return index;
        }
        index++;
    }
    return index;
}

void reverseWord(char *string, int left_border, int right_border)
{
    unsigned int size = right_border - left_border;
    for(int index = 0; index < size >> 1; index++)
    {
        swap(&string[left_border + index], &string[right_border - 1 - index]);
    }
}

void reverse(char *string, char *separator)
{
    int index = 0;
    int border = 0;
    while(index < strlen(string))
    {
        border = findSeparator(string, separator, index);
        reverseWord(string, index, border);
        index = border + strlen(separator);
    }
}

int main()
{
    char separator[10] = ", ";
    //setSeparator(separator);
    char string[100] = "Hello, world!";
    //printf("Enter the string: \n");
    //scanf("%s", string);
    reverse(string, separator);
    //reverseWord(string, 0, strlen(string));
    printf("\n%s", string);
    scanf("%s", separator);
    return 0;
}