// trim.h
#ifndef TRIM_H
#define TRIM_H

void trim(char *word);

#endif

// trim.c
#include<string.h>
#include"trim.h"

void trim(char *word)
{
    int len = strlen(word);
    
    while (len > 0 
           && (!isalnum(word[len - 1]) || word[len - 1] == ' '))
    {
        word[len - 1] = '\0';
        len--;
    }
    
    int start = 0;
    while (word[start] != '\0' && (!isalnum(word[start]) || word[start] == ' '))
    {
        start++;
    }
    
    if (start > 0)
    {
        memmove(word, word + start, strlen(word) - start + 1);
    }
}

// In your main file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trim.h"

extern char **words;
extern int number_of_words;

void append(char *string, char ch)
{
    size_t size = strlen(string);
    if (size < 63) {
        string[size] = ch;
        string[size + 1] = '\0';
    }
}

void read_file(char *file_name, int file_number)
{
    // Your existing code here

    int a = 0;
    int exists = 0;

    while (a < number_of_words)
    {
        if (strcmp(words[a], word) == 0)
        {
            exists = 1;
            printf("%s\n", words[a]);
        }
        a++;
    }

    if (!exists)
    {
        printf("number of words: %i\n", number_of_words);
        number_of_words++;
        char **temp = realloc(words, (sizeof(char *) * number_of_words));
        if (temp == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        words = temp;
        words[number_of_words - 1] = malloc(strlen(word) + 1);
        strcpy(words[number_of_words - 1], word);
    }

    // Your existing code here
}

// initialization code
char **words;
words = malloc(9 * sizeof(char *));
words[0] = malloc(strlen("the") + 1);
strcpy(words[0], "the");
number_of_words = 1;
