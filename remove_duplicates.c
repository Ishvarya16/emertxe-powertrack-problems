#include <stdio.h>
#include<string.h>

void remove_duplicates(char *str) 
{
    int i = 0, j = 0;
    
    while (str[i] != '\0') 
    {
        int k;
        
        for (k = 0; k < i; k++) 
        {
            if (str[i] == str[k]) 
           {
                break;
            }
        }

     
        if (k == i) 
        {
            str[j++] = str[i];
        }

        i++;
    }
    
    
    str[j] = '\0';
}

int main() 
{
    char str[100];

    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);
    remove_duplicates(str);
    printf("String after removing duplicates: %s\n", str);

    return 0;
}

