//Name: Jeremy Achong
//Dr. Steinberg
//COP3502 Spring 2022
//Programming Assignment 2

#include<stdio.h>
#include<stdlib.h>

int blobDetect(int ** picture, int x, int y, int limit);
void display(int **picture, int limit); 

int main()
{
	//setup randomness
    int x;

    printf("Enter seed: ");
    scanf("%d", &x);

    srand(x); //set seed
	
	printf("Enter the size of the picture: ");
	
	int size;
	scanf("%d", &size);
	
	int ** picture = (int **) malloc(size * sizeof(int *));
	
	for(int x = 0; x < size; ++x)
		picture[x] = (int *) malloc(size * sizeof(int));
	
	for(int test = 1; test <= 5; ++test)
	{
		printf("Test %d\n", test);
		
		for(int r = 0; r < size; ++r)
			for(int c = 0; c < size; ++c)
				picture[r][c] = rand() % 2; //generate random number between 0 and 1
		
		
		int numblobs = 0;
		
		//display(picture,size); 

		for(int r = 0; r < size; ++r)
			for(int c = 0; c < size; ++c)
			{	
				//printf("\n%d %d\n",r,c);  DEBUG
				if(blobDetect(picture, r, c, size) > 0)
					++numblobs;
			}
		
		printf("There are %d blob(s) in the picture.\n", numblobs);

	}
	
	//Super important! I don't think I can emphasize how important this is to do!
	for(int x = 0; x < size; ++x)
		free(picture[x]);
	
	free(picture);
	
	return 0;
}

int blobDetect(int **picture, int x, int y, int limit)
{
	/*
		Iterate through the picture until coordinate reaches limit
		if picture[x][y] == 1
			'clean' it to 0 and find adjacent blobs from respective coordinate 

		keep going until the blob ends
	*/
	/* 
		x-1y-1	xy-1	x+1y-1
		x-1y	xy		x+1y
		x-1y+1	xy+1	x+1y+1
	*/

	if(picture[x][y] == 0)
		return 0; 
	else if(x == limit-1 && y == limit-1) //bottom right
	{
		if(picture[x][y] == 1) //end of matrix
		{
			picture[x][y] = 0;
			//printf("\n BLOB 1 - %d %d",x ,y); //DEBUG
			return 1;
		}
	}
	else if(x == 0 && y == 0) //top left
	{
		if(picture[x][y] == 1) //start of matrix
		{	
			picture[x][y] = 0;
			//printf("\n BLOB 2- %d %d",x ,y); //DEBUG
									//one to the right					diagnal down right			one down
			return 1 + blobDetect(picture, x+1,y, limit) + blobDetect(picture, x+1,y+1, limit) + blobDetect(picture, x,y+1, limit); 
		}
	}
	else if(x == limit-1 && y == 0) //top right
	{
		if(picture[x][y] == 1)
		{
			//printf("\n BLOB 3- %d %d",x ,y); //DEBUG
			picture[x][y] = 0; 
						//diagnal down left						//one down							one left
			return 1 + blobDetect(picture, x-1,y+1, limit) + blobDetect(picture, x,y+1, limit) + blobDetect(picture, x-1,y,limit);
		}	
	}
	else if(x == 0 && y == limit-1) //bottom left
	{
		if(picture[x][y] == 1)
		{
			//printf("\n BLOB 4- %d %d",x ,y); //DEBUG
			picture[x][y] = 0;	//one right 						diagnal up right							up one
			return 1 + blobDetect(picture, x+1,y,limit) + blobDetect(picture, x+1,y-1,limit) + blobDetect(picture,x,y-1,limit); 
		}
	}
	else if(x == 0)
	{
		//check to the right
		if(picture[x][y] == 1)
		{
			//printf("\n BLOB 5- %d %d",x ,y); //DEBUG
			picture[x][y] = 0;	//one right							one up								diangal right down 					 down one							diangal right up
			return 1 + blobDetect(picture,x+1,y,limit) + blobDetect(picture,x,y-1,limit) + blobDetect(picture,x+1,y+1,limit) + blobDetect(picture,x,y+1,limit) + blobDetect(picture,x+1,y-1,limit);
		}
	}
	else if(y == 0)
	{
		//check below
		if(picture[x][y] == 1)
		{
			//printf("\n BLOB 6- %d %d",x ,y); //DEBUG
			picture[x][y] = 0; 	//diagnal down right 			one left								diagnal down left					oen right
			return 1 + blobDetect(picture,x+1,y+1,limit) + blobDetect(picture,x-1,y,limit) + blobDetect(picture,x-1,y+1,limit) + blobDetect(picture, x+1,y,limit); 
		}
	}
	else if(y == limit-1) //if c is at the top or bottom
	{
		//check on top
		if(picture[x][y] == 1)
		{
			//printf("\n BLOB 7- %d %d",x ,y); //DEBUG
			picture[x][y] = 0 ; //			left							right							left up									right up 	
			return 1 + blobDetect(picture,x-1,y,limit) + blobDetect(picture, x+1,y,limit) + blobDetect(picture,x-1,y-1,limit) + blobDetect(picture,x+1,y-1,limit); 
		}
	}
	else if(x == limit-1) 
	{
		//check to the left
		if(picture[x][y] == 1)
		{
			//printf("\n BLOB 8- %d %d",x ,y); //DEBUG
			picture[x][y] = 0;// 		down one							left down									left up 							up 
			return 1 + blobDetect(picture, x, y+1,limit) + blobDetect(picture, x-1,y+1,limit) + blobDetect(picture, x-1, y-1,limit) + blobDetect(picture, x,y-1,limit);
		}
	}
	else //if xy is somewhere in the middle of the matrix
	{
		if(picture[x][y] == 1)
		{
			//printf("\n BLOB 9- %d %d",x ,y); //DEBUG
			picture[x][y] = 0;
			
			return 1 + blobDetect(picture, x-1,y-1,limit) + blobDetect(picture, x,y-1,limit) + blobDetect(picture, x+1,y-1,limit) +
				blobDetect(picture, x-1,y,limit) + 										blobDetect(picture, x+1,y,limit) +
				blobDetect(picture, x-1,y+1,limit) + blobDetect(picture, x,y+1,limit) + blobDetect(picture, x+1,y+1,limit);
		}
	}
}
