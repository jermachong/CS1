//Dr. Andrew Steinberg
//COP3502 Computer Science 1
//Programming Assignment 5 Solution

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 2000

typedef struct{
	char * name; //dynamic string
	int rank;
}player_t;

//function prototype(s)
player_t* scanRoster(player_t *roster);

int main(void)
{
	int seed;
	printf("Enter seed: ");
	scanf("%d", &seed);
	srand(seed);
	
	player_t *roster = (player_t*) malloc(sizeof(player_t) * MAX);
	player_t *team1 = (player_t*) malloc(sizeof(player_t) * MAX / 2);
	player_t *team2 = (player_t*) malloc(sizeof(player_t) * MAX / 2);
	
	roster = scanRoster(roster);
	
	double average1 = 0;
	double average2 = 0;
	
	printf("Team 1 Rank Average is: %f\n", average1);
	printf("Team 2 Rank Average is: %f\n", average2);
	
	return 0;
}




player_t* scanRoster(player_t *roster)
{
	FILE *fptr = fopen("players.txt", "r");
	
	char name[20];
	int index = 0;
	
	while(fscanf(fptr, "%s", name) == 1)
	{
		roster[index].name = (char *) malloc(sizeof(char) * 20);
		strcpy(roster[index].name, name);
		roster[index].rank = rand() % 5 + 1;
		++index;
	}
	
	fclose(fptr);
	
	return roster;
}