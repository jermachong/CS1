//Name: Jeremy Achong
//Dr. Steinberg
//COP3502 Spring 2022
//Programming Assignment 3: Helper Test File for functions. 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct card_s{
	int rank;    //number
	char * type; //type of card
	struct card_s * nextptr;
}card_t;

int empty(card_t * node) 
{
	return (node == NULL); //return condition result
}

card_t * insertBackSetup(card_t *node, char *name, int cardrank)
{
	
    if(empty(node)) //check to see if list is empty
    {
		node = (card_t *) malloc(sizeof(card_t));
		
		if(empty(node)) //check to see if malloc worked
		{
			printf("Did not allocate head successfully...");
			printf("Program Terminating...\n");
			exit(1);
		}
		else //otherwise populate data of new head node
		{
			node->type = (char *) malloc(sizeof(char) * 20);
			
			if(node->type == NULL)
			{
				printf("Error with malloc...\n");
				exit(1);
			}
			
			strcpy(node->type, name);
			node->rank = cardrank;
			node->nextptr = NULL; //must make new tail nextptr NULL!!!
			
			return node;  //terminate
		}
      
    }
	
	//here we know that the list has at least one node
	
	card_t *head = node; //keep pointer to head since we will need to return this address
	
	while(node->nextptr != NULL) //traverse to tail
		node = node->nextptr;
	
	node->nextptr = (card_t *) malloc(sizeof(card_t)); 
	
	if(node->nextptr == NULL) //see if new tail was allocated successfully
	{
		printf("Did not allocate node successfully...");
		return head; //terminate if tail didn't get created
	}
	
	//populate new node
	node->nextptr->type = (char *) malloc(sizeof(char) * 20);
	
	if(node->nextptr->type == NULL)
	{
		printf("Error with malloc...\n");
		exit(1);
	}
	
	strcpy(node->nextptr->type, name);
	node->nextptr->rank = cardrank;
	node->nextptr->nextptr = NULL; //very important
			
	return head; //return head node since we need our starting point of the linked list
}

card_t * openCardDeck()
{
	FILE *fptr = fopen("deck.txt", "r");
	
	char *name = (char *) malloc(sizeof(char) * 20);
	
	if (name == NULL)
	{
		printf("Error in malloc...\n");
		exit(1);
	}
	
	card_t * head = NULL;
	
	int cardrank = 13;
	int tracker = 1;
	while(fscanf(fptr, "%s", name) == 1)
	{			
		strcat(name, " ");
		
		if(tracker % 5 == 1)
		{
			strcat(name, "of Clubs");
			head = insertBackSetup(head, name, cardrank);
		}
		else if(tracker % 5 == 2)
		{
			strcat(name, "of Diamonds");
			head = insertBackSetup(head, name, cardrank);
		}
		else if(tracker % 5 == 3)
		{
			strcat(name, "of Hearts");
			head = insertBackSetup(head, name, cardrank);
		}
		else if(tracker % 5 == 4)
		{
			strcat(name, "of Spades");
			head = insertBackSetup(head, name, cardrank);
			tracker = 0;
			--cardrank;
		}
		
		++tracker;
		
	}
	
	free(name);
	fclose(fptr);
	
	return head;
}

int deckSize(card_t * head) //count number of nodes in the linked list
{
	//lets try a recursion method
		if(head == NULL) 
		{
			return 0; 
		}
		else
			return 1 + deckSize(head->nextptr); 
}

void cleanUp(card_t * head)
{
    printf("entered clean\n");
    if(head == NULL)
    {
        printf("nothing to clean :)\n"); 
        exit(1); 
    }
    else if(head->nextptr == NULL)
    {
        printf("\tcase 1 single free\n"); 
        free(head->type); 
        free(head); 
    }
    else
    {
	    while(head != NULL)
	    { 
        printf("\tcase 2 multiple free"); 
		free(head->type); 
        printf("\t1 succ\n");

		free(head);
        printf("\t2 succ\n"); 

        if(head->nextptr != NULL)
		    head = head->nextptr; //iterate to next node 
        printf("\t3 succ\n"); 

        //printf("\t%d",deckSize(head));  
    	}
    }

    printf("\tCLEANED\n"); 
}

card_t * search(card_t * node, int spot)
{
	card_t *temp = node; 
	for(int i = 0; i < spot; i++)
	{
		temp = temp->nextptr; 
	}

	if(node != NULL)
    {
        printf("found %s\n",node->type); 
		return temp;
    }
	else 
		return NULL;
	
}

card_t * removeCard(card_t * node, int spot) 
{
    printf("Entered Remove\n"); 
    printf("\tremoving spot %d\n",spot); 

	if(empty(node)) //check if empty
	{
		printf("\tNothing to remove\n"); 
		return NULL; 
	}


    card_t *head = node;
    card_t *temp = search(node, spot); //find card to remove

	if(head == temp)
	{
		printf("\t1st case\n"); 
        head = head->nextptr; 
        temp->nextptr = NULL;
        cleanUp(temp); 

        printf("\t1st case success\n"); 
        return head; 
	}
    else if (spot == deckSize(node)) //removing the last spot of linked list
    {
        printf("\t2nd case\n");
        card_t *temp2 = search(node, spot-1);
        //temp->nextptr = NULL; 
        cleanUp(temp);
		temp2->nextptr = NULL; 
        printf("\t2nd case success\n"); 
    }
	else
	{  
        printf("\t3rd case\n"); 
        card_t *temp2 = search(node, spot-1);
		temp2->nextptr = temp2->nextptr->nextptr; //redirect node to target->nextptr
        printf("\t\tset prev node to next next\n"); 
    
        temp->nextptr = NULL;
		cleanUp(temp);   //free the target

		//return head
        printf("\t3rd case success\n"); 
		return node; 
	}
     

}

card_t * copyCard(card_t * node) //Good
{
	card_t *copy = (card_t *) malloc(sizeof(card_t)); //allocate for card

	copy->rank = node->rank; //set the rank

	copy->type = (char *) malloc(sizeof(char) * 20); //allocate for type
	strcpy(copy->type, node->type); //set type

	//copy->nextptr = node->nextptr; 

	return copy; 
}

card_t * insertBackDeck(card_t *head, card_t *node)
{
    if(empty(node)) //check to see if list is empty
    {
		printf("Node is empty...\n");
		return head; 
      
    }
	//here we know that the list has at least one node
    
	if(empty(head)) //if the list has no nodes
	{
		printf("Head is empty...\n"); 
		head = copyCard(node); 
        head->nextptr = NULL; 
        return head; 
	}

	card_t *temp = head; //keep a pointer to head since we will need to return this address
    
	while(temp->nextptr != NULL) //traverse to tail
		temp = temp->nextptr;

	temp->nextptr = copyCard(node); 
    temp->nextptr->nextptr = NULL; 

	//node->nextptr = NULL; 
	
	printf("IBD SUCCESS!\n"); 
	return head; //return head node since we need our starting point of the linked list	
}

void display(card_t *head)
{
	card_t *temp = head; 
	while(temp->nextptr != NULL)
	{
		printf("\ncard display: %s",temp->type);
		temp = temp->nextptr; 
	}
		printf("\ncard display: %s",temp->type);
}


int main()
{
    srand(0); 
	//create deck, player 1 pile, and player 2 pile
	//populate deck, then take from 
	card_t *deck = openCardDeck(); 
	card_t *p1 = NULL; 
    card_t *p2 = NULL; 
	int count = 0; 

	printf("There are %d cards in the deck.\n", deckSize(deck)); 

	while(!(empty(deck))) //random select cards from the deck to go to 
	{
        
		int ranCard = rand() % deckSize(deck)-1; 
		p1 = insertBackDeck(p1, search(deck,ranCard)); //move card from deck to p1 pile
        deck = removeCard(deck,ranCard);

        int ranCard2 = rand() % deckSize(deck)-1; 
        p2 = insertBackDeck(p2, search(deck,ranCard2)); 
        deck = removeCard(deck,ranCard2); 

        printf("New Deck Size: %d\n",deckSize(deck)); 
		printf("There are %d in Player 1's Deck\n", deckSize(p1));
		
   		printf("There are %d in Player 2's Deck\n", deckSize(p2)); 
 

	}

	free(deck); //don't need the deck anymore

    
}
