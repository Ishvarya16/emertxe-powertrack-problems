#include <stdio.h>

int is_prime(int num) 
{
    if (num <= 1) 
    {
        return 0;     
    }
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) 
        {
            return 0;  
        }
    }
    return 1;
}

int find_5th_prime(int start) 
{
    int count = 0;
    int num = start;

       while (count < 5) 
       {
        if (is_prime(num)) 
        {
            count++;
        }
        num++;
    }
    
    return num - 1; 
}

void replace_with_5th_prime(int m, int n, int arr[m][n])
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            arr[i][j] = find_5th_prime(arr[i][j]);
        }
    }
}

void print_array(int m, int n, int arr[m][n]) 
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int m, n;
    
        printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);
    
    int arr[m][n];
    
        printf("Enter elements of the array: \n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
        replace_with_5th_prime(m, n, arr);
    
        printf("Modified array with the 5th prime numbers:\n");
    print_array(m, n, arr);
    
    return 0;
}

