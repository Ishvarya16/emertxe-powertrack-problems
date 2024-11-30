#include <stdio.h>
#include <string.h>

void reverseWord(char *word) 
{
    int start = 0;
    int end = strlen(word) - 1;
    
        while (start < end) 
        {
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

int main() 
{
    char input[100];  
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    char *word = strtok(input, " ");
    
    while (word != NULL) 
    {
        reverseWord(word);  
        printf("%s ", word);
        word = strtok(NULL, " ");  
    }

    return 0;
}

