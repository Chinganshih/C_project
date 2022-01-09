#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <string.h>
#include <ctype.h>

int check_vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;

    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return 1;

    return 0;
}

char* reverseVowels(char* s) {
    int count=0, start=0, end = strlen(s)-1;

    while (start < end)
    {
        while(start < end && !check_vowel(s[start])) start++;   
        while(start < end && !check_vowel(s[end])) end--;

        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }

    return s;
}

int main() {
    char* output;
    char input[100];
    printf("Input a string: ");
    scanf("%[^\n]", &input);

    output = reverseVowels(input);
    printf("%s", output);

    return 0;
}
