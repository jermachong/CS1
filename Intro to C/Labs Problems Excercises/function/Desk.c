/*
    Jeremy Achong
    10/4/21

            Lab 6 Problem 2 - Desk

        This code decides whether or not a desk fits a room
        given the dimensions of both.

*/ 

//This function compares the length and width of the room vs the desk
//Returns 1 (True) if the desk's dimensions are less than the room. 
int sizeCheck(int roomLength, int roomWidth, int deskLength, int deskWidth)
{
    int temp; 

    //Correcting room length if it is less than the room width.
    if(roomLength < roomWidth)
    {
        temp = roomLength;
        roomLength = roomWidth;
        roomWidth = temp;    
    }

    //Correcting desk length if it is less than the desk length. 
    if(deskLength < deskWidth)
    {
        temp = deskLength;
        deskLength = deskWidth;
        deskWidth = temp; 
    }

    // Checking if, the room length and width are either larger than
    // or equal to the room dimensions. 
    if(roomLength > deskLength || roomLength == deskLength
        && deskWidth < roomWidth || deskWidth == roomWidth)
        return 1; 
    else    
        return 0; 
        
}

int main(void)
{
    //Prevent garbage numbers
    int roomLength = 0;
    int roomWidth = 0;
    int deskLength = 0;
    int deskWidth = 0;

    //Ask user for length and width of the ROOM
    printf("Enter the length and width of the room: ");
    scanf("%d %d",&roomLength,&roomWidth);

    //Ask user for length and width of the DESK
    printf("Enter the length and width of the desk: "); 
    scanf("%d %d", &deskLength, &deskWidth); 

    //If size check comes back true, it will fit. if size check comes back false it will not fit. 
    if(sizeCheck(roomLength, roomWidth, deskLength, deskWidth))
        printf("The desk will fit in the room.");
    else
        printf("The desk will not fit in the room.");
    
}