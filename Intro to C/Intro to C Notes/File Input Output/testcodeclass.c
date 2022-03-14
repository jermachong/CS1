/*
    Jeremy Achong
    11.18.21

        in-class written code during 2nd File input & output lecture

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOS 100
#define MAXC 10

int main(void){

    FILE *ifp, *ofp; 

    ifp = fopen("students.txt", "r");
    ofp = fopen("summary.txt", "w"); 

    int ids[MAXNOS]; 
    char names[MAXNOS][MAXC];
    float g[MAXNOS][MAXC], avg[MAXNOS]; 

    int nos, noc;
    fscanf(ifp, "%d %d", &nos, &nos); //store values # of students & # of classes

    for(int i = 0; i<nos; i++)
    {
        float sum = 0.0; 
        fscanf(ifp, "%d %s", &ids[i], names[i]);

        for(int j = 0; j<noc; j++)
        {
            fscanf(ifp, "%f", g[i][j]); 
            sum += g[i][j]; 
        }

    }

    fseek(ifp, 5, SEEK_SET); 

    printf("%c", fgetc(ifp)); 


}