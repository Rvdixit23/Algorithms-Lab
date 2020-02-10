#include<stdio.h>
#include<stdlib.h>


void nextPermutation(int n, char *bitStr)
{
    int index = n - 1;
    while (bitStr[index] == '1')
    {
        index--;
    }
    bitStr[index] = '1';
    index++;
    while (index < n)
    {
        bitStr[index++] = '0';
    }
    printf("%s\n", bitStr);
}

int main()
{
    int stringLength;
    printf("Enter the string length : ");
    scanf("%d", &stringLength);
    int count = 1;
    for (int i = 0; i < stringLength; i++)
    {
        count = count * 2;
    }

    char *bitString = (char *)malloc(sizeof(char) * (stringLength));
    for (int i = 0; i < stringLength; i++)
    {
        bitString[i] = '0';
    }
    bitString[stringLength] = '\0';
    printf("%s\n", bitString);
    
    for (int i = 0; i < count - 1; i++)
    {
        nextPermutation(stringLength, bitString);
    }
    
    
}