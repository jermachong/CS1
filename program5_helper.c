//Name: Jeremy Achong
//Dr. Steinberg
//COP3502C Computer Science 1
//Programming Assignment 5 Helper File

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
void * merge(player_t *arr, int p, int q, int r); 
void * sortRoster(player_t * arr, int p, int r);
double average(player_t *roster); //return average rank of given array
void freePlayers(player_t* roster); 
void displayTest(player_t *roster); 

int main(void)
{
	int seed;
	printf("Enter seed: ");
	scanf("%d", &seed);
	srand(seed);
	
	player_t *roster = (player_t*) malloc(sizeof(player_t) * MAX);
	player_t *team1 = (player_t*) malloc(sizeof(player_t) * MAX / 2); //each team allocates for 1000 players 
	player_t *team2 = (player_t*) malloc(sizeof(player_t) * MAX / 2);
	
	roster = scanRoster(roster); //all players, unsorted go in to roster array
    displayTest(roster); 
    double average1 = average(roster); 
    printf("%f is roster avg \n", average1); 

    sortRoster(roster,0,MAX); 
    printf("\npost sort results\n\n");
    displayTest(roster); 
    printf("wtf is happening %d", roster[1201].rank); 
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

/*
Take player type array and sort the roster of players in decending order. 
*/
void* merge(player_t *arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	
	player_t * leftarr = (player_t *) malloc(sizeof(player_t) * n1);
	player_t * rightarr = (player_t *) malloc(sizeof(player_t) * n2);
	
	for(int x = 0; x < n1; ++x)
		leftarr[x] = arr[p + x];
	
	for(int x = 0; x < n2; ++x)
		rightarr[x] = arr[q + x + 1];
	
	int i = 0;
	int j = 0;
	int k = p;
	
	//merge
	while (i < n1 && j < n2) 
	{
		if (leftarr[i].rank <= rightarr[j].rank) 
		{
		  arr[k] = leftarr[i];
		  i++;
		} 
		else 
		{
		  arr[k] = rightarr[j];
		  j++;
		}
		
		k++;
	}
	
	//copy the remaining elements once out of bounds

	while (i < n1) 
	{
		arr[k] = leftarr[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		arr[k] = rightarr[j];
		j++;
		k++;
	}
	
	free(leftarr);
	free(rightarr);
}


void * sortRoster(player_t * arr, int p, int r) //array, index 0, size of array
{
	if(p < r)
	{
		int q = (r + p) / 2;
		sortRoster(arr, p, q);
		sortRoster(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

/*
Take array of players and give average rank.
*/
double average(player_t * arr)
{
	int size = sizeof(arr)/sizeof(arr[0]); //take size of array
	int total = 0; 

	for(int i = 0; i < 2000; i++ )
	{
		//printf("player %s rank is %d\n", arr[i].name, arr[i].rank); 
		total = arr[i].rank + total; //add rank + total. 
	}

	double average = total / MAX; 
	return average; //return total divided by size of player array.
}

/*
Take in  array and free its elements
*/
void freePlayers(player_t *arr)
{
	if(arr == NULL)
	{
		exit(1); 
	} 
	else
	{
		for(int i = 0; i < MAX; i++)
		{
			free(arr[i].name); 
		}
	}

	free(arr); 
}

void displayTest(player_t *roster)
{
	for(int i = 0; i < 50; i++)
		printf("Player Name: %s Player Rank = %d\n",roster[i].name, roster[i].rank);

}