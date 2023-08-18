#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void task4(int argc, char* argv[])
{
    if (argc > 2)
    {
        printf("Wrong arguments...\n");
        return; 
    }

    char c; 
    int newbyte; 
    int startindex = 0; 
    int endindex = 0;
    
    FILE* f1 = fopen(argv[1], "ab");

    if (!f1)
    {
        perror("File problem...\n");
        exit(-1);
    }
  
    do
    {
        printf("C: ");
        scanf("%c", &c);
        int len = ftell(f1);
        char buffer[100];

        if (c == 'd')
        {
            
            fseek(f1, 0, SEEK_SET);
            fread(buffer, len, 1, f1);
            
            for(int i = 0; i < len; i++)
            {       
                printf("%02x ", buffer[i]);
            }

            printf("\n");
        }
        else if (c == 't')
        {
            printf("\n");
        }
        else if (c == 'a')
        {
            printf("newbyte: ");
            scanf("%x", &newbyte);
            fwrite(&newbyte, sizeof(newbyte), 1, f1);
            //putc(newbyte, f1);
        }
        else if (c == 'c')
        {
            scanf("%d %d", &startindex, &endindex);
        }
        else if (c == 'e')
        {
            scanf("%d", &startindex);
            scanf("%x", &newbyte);
        }
        
    } while (c != EOF);
    
    fclose(f1);
}

int main(int argc, char* argv[])
{
    task4(argc, argv);

    return 0;
}
