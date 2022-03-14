/*
    Jeremy Achong
    10/4/21

            Lab 6 Problem 1 Grading Function

            This program calculates your grade after the input 
            of three exam inputs. 
*/ 

float getScore() //Retrieve average score of three user inputted exams
{
    //Variable declaration
    float exam1, exam2, exam3; 
    float totalAverage = 0.0; 

    //Ask for user input of exams
    printf("Enter scores for exam1, exam2, and exam3: "); 
    scanf("%f %f %f", &exam1, &exam2, &exam3);

    //The final score is calculated by 
    //20% of exam1 + 30% of exam2 + 50% of exam 3.
    totalAverage = (0.2*exam1) + (0.3*exam2) + (0.5*exam3); 

    return totalAverage; 
}

char getLetterGrade(float score)
{
    //Sort the letter equivlant for returned average score.
    //Check for equal to or over 90
    if(score >= 90)
        return 'A'; 
    //Check for score between 90 and 80
    else if (score < 90 && score >= 80)
        return 'B'; 
    //Check for score between 80 and 70
    else if(score < 80 && score >= 70)
        return 'C';
    //Check for score between 70 and 60
    else if(score < 70 && score >= 60)
        return 'D'; 
    //Check for score under 60
    else if(score < 60)
        return 'F';
}

int main(void)
{
    //this statement calls getLetterGrade and autmatically prints the character retrieved from it. 
    printf("You got %c",getLetterGrade(getScore())); 

    return 0; 
}