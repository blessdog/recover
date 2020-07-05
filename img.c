#include <stdio.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>
#define BLOCKSIZE 512

int inputError()
{
    printf("Usage: ./recover image");
    return 1;
    
}
int fileError(char filename[])
{
    printf("Unable to open file %s\n", filename);
    return 1;
}

bool isJpgHeader(uint8_t buffer[])
{
    return buffer[0] == 0xff
    && buffer[1] == 0xd8
    && buffer[2] == 0xff
    && (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        return inputError();
    }
    char *inFile = argv[1];
    if(inFile == NULL)
    {
        return inputError();
    }
    FILE* inPtr = fopen(inFile, "r");
    if(inPtr == NULL)
        {
            return fileError(inFile);
        }
    char filename[8];
    FILE* img = NULL;
    uint8_t buffer[BLOCKSIZE]; 
    int jpgCounter= 0; 
    
   
    while(fread(buffer, sizeof(uint8_t), BLOCKSIZE, inPtr) || feof(inPtr) == 0)
    {
        if(isJpgHeader(buffer))
        {
            if(img != NULL)
            {
                fclose(img);
            } 
            sprintf(filename, "%03i.jpg", jpgCounter);
            img = fopen(filename, "w");
            jpgCounter++;
            
        }
        if(img != NULL)
        {
            fwrite(buffer, sizeof(buffer),1,img);
        }
    }    
    if(inPtr == NULL)
    {
        fclose(inPtr);
    }
    if(img == NULL)
    {
        fclose(img);
    }
    return 0;
}    

