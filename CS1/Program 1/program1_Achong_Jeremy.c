//Name: Jeremy Achong
//Dr. Steinberg
//COP3502C Spring 2022
//Programming Assignment 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 20

char ** doubleIt(char **arr, int *maxsize);
char ** populate(char ** words, FILE *fptr, int *currentsize, int *maxsize); 
char* generateSentence(char ** noun, char ** verb, char ** adjective, char ** preposition, char ** article, int nounsize, int verbsize, int adjsize, int prepositionsize, int articlesize); //write sentence to console window
void generateStory(char ** noun, char ** verb, char ** adjective, char ** preposition, char ** article, int nounsize, int verbsize, int adjsize, int prepositionsize, int articlesize, FILE *fptr); //write story to txt file
void displaySentence(char * sentence); 
void cleanUp(char ** nouns, char ** verbs, char ** adjectives, char ** prepositions, char ** articles, int nounsize, int verbsize, int adjsize, int prepositionsize, int articlesize);

int main()
{
	//setup randomness
	int x;
	printf("Enter seed: ");
	scanf("%d", &x);
	srand(x); //set seed
	
	//declare necessary variables
	int nounsize = 0;
	int verbsize = 0;
	int adjsize = 0;
	int prepositionsize = 0;
	
	int nounmaxsize = 5;
	int verbmaxsize = 5;
	int adjmaxsize = 5;
	int prepositionmaxsize = 5;
	const int articlemaxsize = 3; //there are only 3 articles in the english language a, an, and the. that is why const is applied
	
	printf("Welcome to the random sentence generator.\n");
	
	//double pointers
	char ** nouns = NULL;
	char ** verbs = NULL;
	char ** adjectives = NULL;
	char ** preposition = NULL;
	char ** articles = NULL;
	
	nouns = malloc(sizeof(char *) * nounmaxsize); 
	verbs = malloc(sizeof(char *) * verbmaxsize);
	adjectives = malloc(sizeof(char *) * adjmaxsize); 
	preposition = malloc(sizeof(char *) * prepositionmaxsize); 
	articles = malloc(sizeof(char *) * articlemaxsize); 
	
	//make sure malloc was able to allocate memory
	if(nouns == NULL || verbs == NULL || adjectives == NULL || preposition == NULL || articles == NULL) 
	{
		printf("malloc was not successful\n");
		printf("Program will now terminate.\n");
		exit(1);
	}
	
	//populate articles using strcpy. numbers represent how many characters are needed. this includes \0 character
	articles[0] = malloc(sizeof(char) * 2);
	strcpy(articles[0], "A");
	articles[1] = malloc(sizeof(char) * 3);
	strcpy(articles[1], "An");
	articles[2] = malloc(sizeof(char) * 4);
	strcpy(articles[2], "The");
	
	//open the file of words
	FILE *fptr = fopen("nouns.txt", "r");
	FILE *fptr2 = fopen("verbs.txt", "r");
	FILE *fptr3 = fopen("adjectives.txt", "r");
	FILE *fptr4 = fopen("preposition.txt", "r");
	
	//make sure the files were opened properly
	if(fptr == NULL || fptr2 == NULL || fptr3 == NULL || fptr4 == NULL)
	{
		printf("file was not successful in opening.");
		printf("Program will now terminate.\n");
		exit(1);
	}
	
	//populate the dynamic array
	nouns = populate(nouns, fptr, &nounsize, &nounmaxsize); //populate nouns
	verbs = populate(verbs, fptr2, &verbsize, &verbmaxsize); //populate verbs
	adjectives = populate(adjectives, fptr3, &adjsize, &adjmaxsize); //populate adjectives
	preposition = populate(preposition, fptr4, &prepositionsize, &prepositionmaxsize); //populate prepositions
	
	//close the files
	fclose(fptr);
	fclose(fptr2);
	fclose(fptr3);
	fclose(fptr4);
	
	//now lets generate 5 sentences and write them to the console window
	
	printf("Let's generate some random sentences that don't make sense.\n");
	
	for(int x = 0; x < 5; ++x)
	{
		char * sentence = generateSentence(nouns, verbs, adjectives, preposition, articles, nounsize, verbsize, adjsize, prepositionsize, articlemaxsize);
		displaySentence(sentence);
		free(sentence);
	}
	
	printf("Now let's create three stories that just don't make sense.\n");
	fptr = fopen("story1.txt", "w");
	generateStory(nouns, verbs, adjectives, preposition, articles, nounsize, verbsize, adjsize, prepositionsize, articlemaxsize, fptr); //story 1
	fclose(fptr);
	
	fptr = fopen("story2.txt", "w");
	generateStory(nouns, verbs, adjectives, preposition, articles, nounsize, verbsize, adjsize, prepositionsize, articlemaxsize, fptr); //story 2
	fclose(fptr);

	fptr = fopen("story3.txt", "w");
	generateStory(nouns, verbs, adjectives, preposition, articles, nounsize, verbsize, adjsize, prepositionsize, articlemaxsize, fptr); //story 3
	fclose(fptr);

	cleanUp(nouns,verbs, adjectives, preposition, articles, nounmaxsize, verbmaxsize, adjmaxsize, prepositionmaxsize, 3);

	
	printf("The stories were generated successfully and stored in their respective text files.\n");
	printf("Check them out!\n");
	
	return 0;
}

/* 
Pre- takes one char pointer (dynamic string) 
Post- display it on a single line
*/  
void displaySentence(char *sentence)
{
	printf("%s",sentence); //print out given sentence which is one string array concatenated
}

/*
Pre- load values from text files
Post- assign values to the dynamic array. reutrn the populated 2D dynamic string array. call doubleit if needed
*/
char **populate(char **words, FILE *fptr, int *currentsize, int *maxsize)
{
	//allocate heap memory for the ArrayOfWords that will be returned to 
	//wordType array
	while(!feof(fptr))
	{
		//call doubleIt in case the 
		if((*currentsize) == (*maxsize))
		{
			words = doubleIt(words, maxsize); 
		}

		//allocate space for each string within the array by LIMIT
		words[*currentsize] = (char*)malloc(sizeof(char)*LIMIT);
		fscanf(fptr, "%s", words[(*currentsize)]); //scan in text file and 
		(*currentsize)++; //increase the current size of the word array
	}
	

	return words; //fill respective category of words. 
}

/* 
Pre- takes in 2d array from respective category (noun verb adj prep)
Post- doubles the maxsize space for respective category and copies the original values over 
*/
char **doubleIt(char **arr, int *maxsize)
{
	*maxsize = *maxsize * 2; //double the maxsize of the original array. 

	//allocation loop
	char **arrDouble = (char **) malloc(sizeof(char*) * (*maxsize)); //new dynamic array that is double the size of arr
	for(int i = 0; i < 	(*maxsize)/2; i++)
	{
		
		arrDouble[i] = (char*)malloc(sizeof(char)*(strlen(arr[i])+1)); 
		
		if(arrDouble[i] == NULL)
		{
			printf("Oh no... malloc wasn't successful\n");
			exit(1);
		}
	}

	//copy loop
	//copy original values to new doubled array.
	for(int i = 0; i < *maxsize/2; i++)
	{
		strcpy(arrDouble[i], arr[i]); //copy string from arr to arrdouble
	}

	//free original array since it is no longer in use.
	for(int i = 0; i < (*maxsize)/2; i++)
	{
		free(arr[i]); 
	}
	free(arr);
	
	return arrDouble; //return the original array with double amount of allocated space.
}

/*
Pre- Retrieve words from word type arrays 
Post- Create a string by combining respective word categories. No more than 100 char
*/
char* generateSentence(char ** noun, char ** verb, char ** adjective,
 char ** preposition, char ** article, int nounsize, int verbsize, int adjsize, 
 int prepositionsize, int articlesize) //write sentence to console window
{
 
	int sentSize = 100; //set max num of characters in sentence. 

	//allocate memory
	//8 word sentence
	char *sentence = (char*) malloc(sizeof(char) * sentSize); 

	//defensive programming
	if(sentence == NULL)
	{
		printf("Oh no... malloc wasn't successful\n");
		exit(1); 
	}

	//choose random word from respective category array
	//article adjective noun verb preposition article adjective noun
	strcat(sentence, article[rand() % articlesize]);
	strcat(sentence, " "); 
	strcat(sentence, adjective[rand() % adjsize]);
	strcat(sentence, " ");
	strcat(sentence, noun[rand() % nounsize]);
	strcat(sentence, " ");
	strcat(sentence, verb[rand() % verbsize]);
	strcat(sentence, " ");
	strcat(sentence, preposition[rand() % prepositionsize]);
	strcat(sentence, " ");
	strcat(sentence, article[rand() % articlesize]);
	strcat(sentence, " "); 
	strcat(sentence, adjective[rand() % adjsize]);
	strcat(sentence, " ");
	strcat(sentence, noun[rand() % nounsize]);
	strcat(sentence, ".\n"); 

	//generate sentence success, return string array called sentence
	return sentence; 
}

/*
Pre- utilize given word category arrays and generateSentence
Post- write story to text file
*/
void generateStory(char ** noun, char ** verb, char ** adjective, 
char ** preposition, char ** article, int nounsize, int verbsize, int adjsize, int prepositionsize, 
int articlesize, FILE *fptr) 
{
	//amount of sentences between 100-500
	int ranNum = (rand() % 401 + 100); //set random number for # of sentences to generate on every call
	char *sentence = NULL; 
	for(int i = 0; i < ranNum; i++)
	{	
		sentence = generateSentence(noun, verb, adjective, preposition, article, nounsize, verbsize, adjsize, prepositionsize, articlesize);
		fprintf(fptr,"%s", sentence); //print sentence to respective story file. 
		free(sentence); //free sentence memory after it was written down
	}
	
}

/*
Pre- take in the 2D array string components
Post- free EVERYTHING within the 2D arrays
*/
void cleanUp(char ** nouns, char ** verbs, char ** adjectives, char ** prepositions, char ** articles, int nounsize, int verbsize, 
int adjsize, int prepositionsize, int articlesize)
{
	//iterate through 2D array and free each element then free whole array
	for(int i = 0; i < nounsize; i++)
	{
		free(nouns[i]); 
	}
	free(nouns);

	for(int i = 0; i < verbsize; i++)
	{
		free(verbs[i]); 
	}
	free(verbs);

	for(int i = 0; i < adjsize; i++)
	{
		free(adjectives[i]); 
	}
	free(adjectives);

	for(int i = 0; i < prepositionsize; i++)
	{
		free(prepositions[i]); 
	}
	free(prepositions);

	for(int i = 0; i < articlesize; i++)
	{
		free(articles[i]); 
	}
	free(articles);

	//set unused pointers to NULL
	nouns = NULL; 
	verbs = NULL;
	adjectives = NULL;
	prepositions = NULL;
	articles = NULL;
}