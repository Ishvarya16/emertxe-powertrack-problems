#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() 
{
    
    int src_fd = open("src.txt", O_RDONLY);

    if (src_fd == -1) 
    {
        perror("Error opening the file");
        return 1;
    }
    int dest_fd = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) 
    {
        perror("Error opening dest.txt");
        close(src_fd);  
        return 1;
    }
    char buf[20];
    int ret;
    while((ret= read(src_fd,buf,20)))
    {
       write(dest_fd,buf,ret);
       
    }
    if (ret == -1) 
    {
        perror("Error reading from src.txt");
    }
    close(src_fd);
    close(dest_fd);

    printf("File copied successfully!\n");
    return 0;


    
   }
