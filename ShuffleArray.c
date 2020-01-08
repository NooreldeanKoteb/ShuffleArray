#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SIZE 10
void InitializeArray(int *numArray, const int arrayLength); //prototype
void ShuffleArray(int *numArray, const int arrayLength); //prototype
void PrintList(int *numArray, const int arrayLength); //prototype
int cmp_func(const void * a, const void * b); //prototype
int main(int argc, char *argv[]){
    if (argc!=3){ //checks that there are 2 inputs
        printf("Error: Incorrect argument input!"); //sends error message if more or less than 2 inputs
        exit(0); //exits program
    }
    printf("Name: Nooreldean Koteb\n lab:209\n");
    printf("Description:\n");
    printf("This Program will create a randomized set of numbers, print the array.\n");
    printf("Then it will sort the randomized array in descending order and print the array.\n");
    int seed; //initializes seed
    int N; //initializes N
    sscanf(argv[1],"%d",&seed); //puts argv values into int
    sscanf(argv[2],"%d",&N); //puts argv values into int
    int *numArray= malloc(sizeof(int)*N); //allocates memory to numArray
    if (numArray == NULL){ //checks malloc
        printf("Error: allocating memory!\n"); //prints error message
        exit(1); //exits if malloc fails
    }
    int i; //initializes i
    srandom(seed); //seeds randomizer
    for (i=0; i<=ARRAY_SIZE; i++){ // for loop that runs the program
        InitializeArray(numArray,N); //calls initializeArray
        printf("First Array:"); //Prints for clarity
        PrintList(numArray,N); //calls printlist
        ShuffleArray(numArray,N); //calls shufflearray
        printf("Mixed Array:"); //prints for clarity
        PrintList(numArray,N); // calls printlist
        qsort(numArray,N,sizeof(int), cmp_func); //qsort sorts the array by calling cmp_func
        printf("Fixed Array:"); //prints for clarity
        PrintList(numArray,N); //calls printlist
    }
    free(numArray); //frees memory
    numArray = NULL; //prevents dangling pointer by setting numArray to NULL
}
void InitializeArray(int *numArray, const int arrayLength){ //void function takes in two values
    int i; //initializes i
    for (i=0; i<arrayLength; i++){ //for loop that goes through the length of the array
        numArray[i]= i+1; //adds 1-N into the array
    }
}
void PrintList(int *numArray, const int arrayLength){ //void function takes in two values
    int i; //initializes i
    for (i=0; i<arrayLength; i++){ //for loop goes through array
        printf("%d ",numArray[i]); //prints array value
    }
    printf("\n"); //new line
}
void ShuffleArray(int *numArray, const int arrayLength){ //void function takes in two values
    int i; //initializes i
    int j; //initializes j
    int TempVal; //initializes TempVal
    for (i= arrayLength-1; i>0; i-- ){ //for loop that goes through arrayLength
        j=random()%(i+1); //sets j to random value
        TempVal = numArray[i];  //sets temp val to current array val
        numArray[i]=numArray[j]; //switches array values
        numArray[j]=TempVal; //switches array values
    }
}
int cmp_func(const void * a, const void * b){ //qsort cmp_func
    return ( *(int*)b - *(int*)a ); //sorts in decreasing order
}