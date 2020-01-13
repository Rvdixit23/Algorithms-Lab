#include<stdio.h>
#include<string.h>

int searchFirstOccurrence(char *pattern, char *text)
{
    int patLen = strlen(pattern);
    int textLen = strlen(text);

    int valid;

    for (int i = 0; i <= textLen - patLen; i++)
    {
        valid = 1;
        for (int j = 0; j < patLen && valid; j++)
        {
            if (text[i+j] != pattern[j])
            {
                valid = 0;
            }
            
        }
        if (valid)
        {
            return i;
        }
    }
    return -1;
}

int searchLastOccurrence(char *pattern, char *text)
{
    int patLen = strlen(pattern);
    int textLen = strlen(text);

    int valid;

    for (int i = textLen - patLen; i >= 0; i--)
    {
        valid = 1;
        for (int j = 0; j < patLen && valid; j++)
        {
            if (text[i+j] != pattern[j])
            {
                valid = 0;
            }
            
        }
        if (valid)
        {
            return i;
        }
    }
    return -1;
}

int numOccurrences(char *pattern, char *text)
{
    int patLen = strlen(pattern);
    int textLen = strlen(text);
    int count = 0;
    int valid;

    for (int i = 0; i <= textLen - patLen; i++)
    {
        valid = 1;
        for (int j = 0; j < patLen && valid; j++)
        {
            if (text[i+j] != pattern[j])
            {
                valid = 0;
            }
            
        }
        if (valid)
        {
            count++;
        }
    }
    return count;
}

int longestPrefix(char *pattern, char *text)
{
    int patLen = strlen(pattern);
    int textLen = strlen(text);

    int longPre = 0;
    int tempPre = 0;
    int valid;

    for (int i = 0; i <= textLen - patLen; i++)
    {
        valid = 1;
        tempPre = 0;
        for (int j = 0; j < patLen && valid; j++)
        {
            if (text[i+j] != pattern[j])
            {
                valid = 0;
            }
            else
            {
                tempPre++;
            }  
        }

        if (tempPre > longPre)
        {
            longPre = tempPre;
        }
    }
    return longPre;
}

int charactersCompared(char *pattern, char *text)
{
    // int patLen = strlen(pattern);
    // int textLen = strlen(text);
    // int answer = (textLen - patLen + 1)*patLen;
    // printf("%d\n", answer);
    // return answer;
    // // return 35;
    int patLen = strlen(pattern);
    int textLen = strlen(text);
    int count = 0;
    int valid;

    for (int i = 0; i <= textLen - patLen; i++)
    {
        valid = 1;
        for (int j = 0; j < patLen && valid; j++)
        {
            count++;
            if (text[i+j] != pattern[j])
            {
                valid = 0;
            }
            
        }
    }
    // printf("%d\n", count);
    return count;
}