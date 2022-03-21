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

		result = playRound(); //play game
		
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
	card_t *p1 = NULL; 
	card_t *p2 = NULL; 
	card_t *reward = NULL; //where the tied cards go
	int roundresult = 0; 

	printf("There are %d cards in the deck.\n", deckSize(deck)); 

	while(!empty(deck)) //random select cards from the deck to go to 
	{
		int ranCard = rand() % deckSize(deck)-1; 
		p1 = insertBackDeck(p1, search(deck,ranCard)); //move card from deck to p1 pile
        deck = removeCard(deck,ranCard);

        int ranCard2 = rand() % deckSize(deck)-1;
        p2 = insertBackDeck(p2, search(deck,ranCard2)); 
        deck = removeCard(deck,ranCard2); 
		
	}

	free(deck); //don't need the deck anymore

	//the player decks are now populated, time to play

	//play game until a list / deck is empty
	while( !empty(p1) || !empty(p2))
	{
		if(deckSize(p1) == 0 || deckSize(p2) == 0)
			break; 

		int rewardLength = deckSize(reward); 
		
		int result = compareCard(p1,p2);  

		if(result == 1) //p1 win
		{	
			printf("Player 1 won that round.\n"); 
			p1 = moveCardBack(p1); 
			p1 = insertBackDeck(p1, search(p2,0)); 
			p2 = removeCard(p2, 0); 

		}
		else if(result == 2) //p2 win 
		{
			printf("Player 2 won that round.\n");  
			p2 = moveCardBack(p2);
			p2 = insertBackDeck(p2, search(p1,0)); 
			p1 = removeCard(p1,0); 
	
		}
		else if(result == 0 ) //WAR! 
		{
			printf("Ugh oh...We have a tie! W-A-R!\n");

			int warFlag = 1; 

			while(warFlag == 1)
			{
				//One card left
				if(deckSize(p1) == 1 && deckSize(p2) > 1)
				{	
					p1 = insertBackDeck(p1,p2); 
					removeCard(p2,0); 
					warFlag--; 
					
				}
				else if(deckSize(p2) == 1 && deckSize(p1) > 1)
				{
					p2 = insertBackDeck(p2,p1);
					removeCard(p1,0); 
					warFlag--; 
					
				}

				//two cards left
				if(deckSize(p1) == 2 || deckSize(p2) == 2)
				{
					int warResult = compareCard(p1->nextptr,p2->nextptr); 
					reward = insertBackDeck(reward, p1);
					reward = insertBackDeck(reward,p1->nextptr);

					reward = insertBackDeck(reward, p2);
					reward = insertBackDeck(reward,p2->nextptr);

					if(warResult == 1)
					{
						for(int i = 0; i < deckSize(reward); i++) {
							p1 = insertBackDeck(p1,reward);
							removeCard(p2,0); 
						}
						warFlag--; 
					
						
					}
					else if(warResult == 2)
					{
						for(int i = 0; i < deckSize(reward); i++) {
							p2 = insertBackDeck(p2,reward); 
							removeCard(p1,0);
						}
						warFlag--;
						
					} 

				}
				
				//WAR with 3 or more cards in each deck
				reward = insertBackDeck(reward, p1);  //p1 card 1 send to the reward pile
				reward = insertBackDeck(reward,p1->nextptr); //face down p1 card 2 to reward
 
				reward = insertBackDeck(reward, p2); //p2 card 1 to reward
				reward = insertBackDeck(reward,p2->nextptr); //face down p2 card 2 to reward

				int warResult = compareCard(p1->nextptr->nextptr,p2->nextptr->nextptr);

				reward = insertBackDeck(reward,p1->nextptr->nextptr); //send faceup card 3s to reward pile
				reward = insertBackDeck(reward,p2->nextptr->nextptr);


				//remove the cards from player piles
				for(int i = 0; i < 3; i++)
				{
					p1 = removeCard(p1,0);
					p2 = removeCard(p2,0);
				}
				
				if(warResult == 1) //p1 wins war
				{
					printf("Player 1 won that W-A-R!\n"); 

					while(!empty(reward))
					{
						p1 = insertBackDeck(p1,reward);
						reward = removeCard(reward,0);
					}
						 
					warFlag--; 
					
				}
				else if(warResult == 2) //p2 wins war
				{	
					printf("Player 2 won that W-A-R!\n"); 

					while(!empty(reward))
					{
						p2 = insertBackDeck(p2,reward);
						reward = removeCard(reward,0);
					}

					warFlag--; 
				}
				else if(warResult == 0) //ANOTHER TIE!!!
				{
					continue; //repeat loop
				}

			}

		}

		printf("Player 1 has %d cards.\n",deckSize(p1)); 
		printf("Player 2 has %d cards.\n",deckSize(p2)); 

	}

	
	//store win result
	if(deckSize(p1) == 0)
		roundresult = 2; 
	else 
		roundresult = 1; 

	//clean piles
	cleanUp(p1); 
	cleanUp(p2); 
	cleanUp(reward); 


	//return win result
	if(roundresult == 2)
		return 2;
	else 
		return 1; 
}

void cleanUp(card_t * head)
{
	/*
    if(deckSize(head) == 1)
    {
        free(head->type); 
		free(head); 
		head = NULL; 
    }
    else if(head->nextptr == NULL)
    {
        free(head->type); 
        free(head); 
    }
    else
    {
	    while(head != NULL)
	    { 
			free(head->type); 
			free(head);
			if(head->nextptr != NULL)
				head = head->nextptr; //iterate to next node 

    	}
    }
	*/
	if(deckSize(head) == 0)
	{
		head = NULL; 
	}

	while(head->nextptr!=NULL)
	{
		free(head->type);
		free(head);
		head = head ->nextptr;
	}

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

card_t * search(card_t * node, int spot)
{
	card_t *temp = node; 
	for(int i = 0; i < spot; i++)
	{
		temp = temp->nextptr; 
	}

	if(node != NULL)
    {
		return temp;
    }
	else 
		return NULL;
	
}

card_t * copyCard(card_t * node) 
{	
	card_t *copy = (card_t *) malloc(sizeof(card_t)); //allocate for card

	copy->rank = node->rank; //set the rank

	copy->type = (char *) malloc(sizeof(char) * 20); //allocate for type
	strcpy(copy->type, node->type); //set type

	return copy; 
}	

card_t * removeCard(card_t * node, int spot) 
{

	if(empty(node)) //check if empty
	{
		printf("\tNothing to remove\n"); 
		return NULL; 
	}


    card_t *head = node;
    card_t *temp = search(node, spot); //find card to remove

	if(head == temp)
	{
        head = head->nextptr; 
        temp->nextptr = NULL;
		free(temp->type); 
        free(temp); 

        return head; 
	}
    else if (spot == deckSize(node)) //removing the last spot of linked list
    {
        card_t *temp2 = search(node, spot-1);
  
		free(temp->type); 
        free(temp);
		temp2->nextptr = NULL; 

    }
	else
	{  

        card_t *temp2 = search(node, spot-1);
		temp2->nextptr = temp2->nextptr->nextptr; //redirect node to target->nextptr
    
        temp->nextptr = NULL;
		free(temp->type); 
		free(temp);   //free the target

		//return head
		return node; 
	}
     

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
		head = copyCard(node); 
        head->nextptr = NULL; 
        return head; 
	}

	card_t *temp = head; //keep a pointer to head since we will need to return this address
    
	while(temp->nextptr != NULL) //traverse to tail
		temp = temp->nextptr;

	temp->nextptr = copyCard(node); 
    temp->nextptr->nextptr = NULL; 

	
	return head; //return head node since we need our starting point of the linked list	
}
int compareCard(card_t * cardp1, card_t * cardp2) //1 2 or 0 returned
{
	printf("Player 1 pulled out %s.\tPlayer 2 pulled out %s.\n",cardp1->type,cardp2->type); 
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
	card_t *temp = head; //traverse to decksize 
	card_t *temp2 = head->nextptr;  
	while(temp->nextptr != NULL) //traverse to tail
		temp = temp->nextptr;

	temp->nextptr = head; //set temp next pointer to the head
	head->nextptr = NULL; //the head points to nothing

	return temp2; 
}


