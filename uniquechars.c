#include <stdio.h>
#include <string.h>

int hasUniqueChars(char *str) 
{
    
    int char_set[128] = {0}; 

    
    for (int i = 0; str[i] != '\0'; i++) 
    {
        int val = str[i];

          if (char_set[val] == 1) 
          {
            return 0;
        }

        
        char_set[val] = 1;
    }

    
    return 1;
}

int main() 
{
    char input[100]; 

    
    printf("Enter an Input: ");
    fgets(input, sizeof(input), stdin); 

    
    input[strcspn(input, "\n")] = '\0';

    
    if (hasUniqueChars(input)) 
    {
        printf("The Input has all unique characters.\n");
    } else {
        printf("The Input has duplicate characters.\n");
    }

    return 0;
}

