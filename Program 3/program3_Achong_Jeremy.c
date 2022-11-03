//Name: Jeremy Achong
//Dr. Steinberg
//COP3502 Spring 2022
//Programming Assignment 3 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct card_s{
	int rank;    //number
	char * type; //type of card
	struct card_s * nextptr;
}card_t;

//function prototypes
void rules(); //display rules
int playRound(); //simulate round
card_t * openCardDeck(); //open the card deck and place into a linkedlist setup
card_t * insertBackSetup(card_t *node, char *name, int cardrank); //take card from orginial deck and place in back of linked list for setup of game
int empty(card_t * node); //check to see if linked list is empty
void cleanUp(card_t * head); //free memory to prevent memory leaks
int deckSize(card_t * head); //count number of nodes in the linked list
card_t * search(card_t * node, int spot); //search list for a specific spot in the card deck indexing is similar to array setup
card_t * copyCard(card_t * node); //make a deep copy of card
card_t * removeCard(card_t * node, int spot); //remove card from linkedlist
card_t * insertBackDeck(card_t *head, card_t *node); //place card at end of pile
int compareCard(card_t * cardp1, card_t * cardp2); //compare cards
card_t * moveCardBack(card_t *head); //place card at top of deck to the bottom of the deck

int main()
{
	int seed;
	printf("Enter Seed: ");
	scanf("%d", &seed);
	
	srand(seed); //seed set
	rules();
	
	int player; //1 or 2
	int result;
	
	printf("Would you like to be player 1 or 2?\n");
	printf("Enter 1 or 2: ");
	scanf("%d", &player); //choose player
	
	for(int game = 1; game <= 5; ++game) //simulate games
	{
		printf("Alright lets play game %d.\n", game);
		printf("Lets split the deck.\n");

		//result = playRound(); //play game
		
		if((result == 1 && player == 1) || (result == 2 && player == 2)) //determine who won
			printf("You won game %d.\n", game);
		else
			printf("I won game %d.\n", game);
	}
	
	return 0;
}

void rules()
{
	printf("Welcome to the card game war!\n");
	printf("Here are the rules.\n");
	printf("You have a pile of cards and I have a pile of cards.\n");
	printf("We will each pull the top card off of our respective deck and compare them.\n");
	printf("The card with the highest number will win the round and take both cards.\n");
	printf("However if there is a tie, then we have to we have to place three cards out and pull one more to compare the final result.\n");
	printf("Winner of the tie, will grab all the cards out. However if it's a tie again, then we repeat the same action.\n");
	printf("Ready? Here we go!\n");
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

int empty(card_t * node) 
{
	return (node == NULL); //return condition result
}

int playRound()
{
	//create deck, player 1 pile, and player 2 pile
	//populate deck, then take from 
	card_t *deck = openCardDeck(); 
	card_t *p1; 
	card_t *p2; 
	card_t *reward; //where the tied cards go

	while((empty(deck))) //random select cards from the deck to go to 
	{
		int ranCard = rand() % 52; 
		int ranCard2 = rand() % 52; 
		p1 = insertBackDeck(search(deck, ranCard));
		p2 = insertBackDeck(search(deck, ranCard2));
		remove(deck,ranCard); 
		remove(deck,ranCard2); 
	}

	cleanUp(deck); //don't need the deck anymore

	//the player decks are now populated, time to play

	//play game until a list / deck is empty
	while( !empty(p1) || !empty(p2))
	{
		rewardLength = deckSize(reward); 

		if(compareCard(p1,p2) == 1) //p1 win
		{
			moveCardBack(p1); 
			card_t p2Loss = copyCard(p2);
			p1 = insertBackDeck(p1, p2Loss); 
			if(rewardLength > 0)
			{
				for(int i = 0; i < rewardLength; i++)
					p1 = insertBackDeck(p1, reward); 
			}
		}
		else if(compareCard(p1,p2) == 2) //p2 win 
		{
			moveCardBack(p2);
			card_t p1Loss = copyCard(p1); 
			p2 = insertBackDeck(p2, p1Loss); 
			if(rewardLength > 0)
			{
				for(int i = 0; i < rewardLength; i++)
					p2 = insertBackDeck(p2, reward); 
			}
			
		}
		else if(compareCard(p1,p2) == 0 ) //WAR! 
		{
			reward = insertBackDeck(reward, p1);  //send to the reward pile
			reward = insertBackDeck(reward, p2); 
			p1 = p1->nextptr; 
			p2 = p2->nextptr;  
		}
	}

	cleanUp(reward); 
	cleanUp(p1); 
	cleanUp(p2); 

	//return 1 or 2 depending on results  
	if(empty(p1))
		return 2;
	else
		return 1; 
}

void cleanUp(card_t * head)
{
	while(!empty(head))
	{
		free(head->type); 
		free(head);
		head = head->nextptr; //iterate to next node 
	}
}

int deckSize(card_t * head); //count number of nodes in the linked list
{
	//lets try a recursion method
		if(head == NULL) 
		{
			return 0; 
		}
		else
			return 1 + deckSize(head->nextptr); 
}

card_t * search(card_t * node, int spot)
{
	for(int i = 0; i < spot; i++)
	{
		node = node->nextptr; 
	}

	return node; 
}

card_t * copyCard(card_t * node)
{
	card_t *copy;
	copy->rank = node->rank; 
	strcpy(copy->type, node->type);
	copy->nextptr = node->nextptr; 

	return copy; 
}

card_t * removeCard(card_t * node, int spot) //this is probably done wrong
{
	if(empty(node)) //check if empty
	{
		printf("Nothing to remove"); 
		return NULL; 
	}

	if(spot == 0)
	{
		card_t *temp = node; 
		printf("Removing %d from deck./n", temp->data); 
		node = node->nextptr; 
		free(temp);
		return node; 
	}
	else
	{
		card_t *temp = search(node, spot-1);  //retrieve node before the target
		temp->nextptr = temp->nextptr->nextptr; //redirect node to target->nextptr
		free(search(node,spot)); //free the target

		//return head
		return node; 
	}

}

card_t * insertBackDeck(card_t *head, card_t *node)
{
    if(empty(node)) //check to see if list is empty
    {
		printf("Deck is empty...\n");
		return head; 
      
    }
	//here we know that the list has at least one node
	
	card_t *temp = head; //keep pointer to head since we will need to return this address
	
	while(temp->nextptr != NULL) //traverse to tail
		temp = temp->nextptr;
	
	temp->nextptr = node; 
	node->nextptr = NULL; 
	
	return head; //return head node since we need our starting point of the linked list	
}

int compareCard(card_t * cardp1, card_t * cardp2) //1 2 or 0 returned
{
	if(cardp1->rank > cardp2->rank)
	{
		return 1; 
	}
	else if(cardp1->rank < cardp2->rank)
	{
		return 2; 
	}
	else
		return 0; 

}

card_t * moveCardBack(card_t *head) 
{
	card_t *temp = search(head, deckSize(head)); //traverse to decksize 
	temp->nextptr = head; //set temp next pointer to the head
	head->nextptr = NULL; //the head points to nothing
}


