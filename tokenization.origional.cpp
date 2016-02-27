#include "stdafx.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define _STDC_WANT_LIB_EXT1_ 1
#define BUF_SIZE 100
#define TEXT_LEN 10000
#define WORD_LEN 12
#define WORDS_MAX 500

int main()
{
	char text[TEXT_LEN]="";
	char delimiters[] = " \n\".,;:!)(><-_?";
	char buf[BUF_SIZE];
	char words[WORDS_MAX][WORD_LEN];
	int nWords[WORDS_MAX] = { 0 };
	int word_count = 0;

	printf("input paragraph, press dounle [ENTER] to end input");

	//read in paragraph
	
	while (true)
	{
		fgets(buf, BUF_SIZE, stdin);
		if (buf[0] == '\n')
			break;
		if (strcat_s(text, TEXT_LEN, buf)) {
			printf("Error while Concatenation: exiting");
			return 1;
		}
	}
	
	//get first character
	size_t len = WORD_LEN;
	char* ptr = NULL;
	char* pWord = strtok_s(text, delimiters, &ptr);
	if (!pWord) {
		printf("Error: No Words Found, exiting");
		return 2;
	}
	
		strcpy_s(words[word_count],len,pWord);
		++nWords[word_count++];
	

	//the rest of the words

	bool new_word = true;
	while (true) {
		pWord = strtok_s(NULL, delimiters, &ptr);
		if (!pWord)
			break;
		for (int i = 0;i < word_count;i++) 
		{
			if (strcmp(words[i], pWord) == 0)
			{
				++nWords[i];
				new_word = false;
			}
		}
		if (new_word)
		{
			strcpy_s(words[word_count], len, pWord);
			++nWords[word_count++];

		}
		else
			new_word = true;
		if (word_count > WORDS_MAX - 1)
		{
			printf("Memory limit exceeded. Exiting...");
			return 3;
		}
	}

	//print the results in fives

	for (int i = 0; i < word_count; i++)
	{
		printf("%-13s %-4d", words[i], nWords[i]);
		if ((i + 1) % 5 == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}

