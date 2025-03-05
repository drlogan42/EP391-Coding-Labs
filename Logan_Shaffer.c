//Include Statements
#include <stdio.h>

//Function Prototypes
void Function1(int Arr[]);
void Function2(int Arr[]);
void Function3(int Arr[]);
void Function4(int TxtArr[],int *size);
void Function5(int TxtArr[],int size);
void Function6(int TxtArr[],int size);
void Function7(int TxtArr[],int size);
void Function8(int TxtArr[],int size);

//File Pointer
FILE *fptr ;

int main() {

//Declaration of Variables
int Arr[5];
int TxtArr[10];
int size = 0;


//Calling Each Function
 Function1(Arr);
 Function2(Arr);
 Function3(Arr);
 Function4(TxtArr, &size);
 Function5(TxtArr, size);
 Function6(TxtArr, size);
 Function7(TxtArr, size);
 Function8(TxtArr, size);
return 0;
}

void Function1(int Arr[]) {
  int num;
  //Get five 2-digit inputs and store into Arr[]
  for(int i = 0; i < 5; i++){
  printf("Please input a 2-digit (10-99) integer value, then hit ENTER: ");
  //Read input where leading zeros do not count as a 2 digit number
  if(scanf("%d", &num) == 1){
    if(num >= 10 && num <= 99){
      Arr[i] = num;
    } else {
      //Reject numbers input not 10-99
      printf("Invalid input: Number is not a 2-digit number.\n");
    }
  }
  }
  //Print the input array of integers
  printf("\nFROM USER-ENTERED VALUES\n\nEntered Array:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", Arr[i]);
  }
}
void Function2(int Arr[]){
  //Sorting Algorithm from Largest to Smallest
  for (int i = 0; i < 5; i++){
    //Highest number assigned to index it resides in
    int highnum = i;
    //Iterate through elements to set highnum to highest number
    for (int j = i + 1; j < 5; j++){
      //Check if current element is highest num and assign if higher
      if(Arr[j] > Arr[highnum]){
        highnum = j;
      }
    }
    //If a number was higher than highnum, swap the places of highnum and higher element in array
    if(highnum != i){
    int Temp = Arr[i];
    Arr[i] = Arr[highnum];
    Arr[highnum] = Temp;
  }
  }
  //Print the sorted array
  printf("\n\nSorted Array (large to small):\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", Arr[i]);
  }
}
void Function3(int Arr[]){
  //Calculate Mean and display without using float or double
  //Store integer and decimal portions of mean
  int Meanint = 0;
  int Meandec = 0;
  int sum = 0;
  //Get sum of array
  for (int i = 0; i < 5; i++){
    sum += Arr[i];
  }
  //Mult sum by 10 to get decimal place then divide by num of elements and
  //Finally combine integer and decimal to get mean value
  sum = sum * 10;
  sum = sum / 5 ;
  Meanint = sum / 10 ;
  Meandec =  sum % 10;
  printf("\n\nMean Value: %d.%d\n",Meanint,Meandec);
}

void Function4(int TxtArr[], int *size){

//Open file test.txt in read mode
fptr = fopen("test.txt", "r");

//If file does not exist inform user
if (fptr == NULL) {
  printf("File path incorrect. Name needs to be \"test.txt\"\n");
  
  // Exit the function early
  return; 
}

//Set a counter to 0 and Print the number of lines in the txt file
int count = 0;
printf("\nFROM VALUES READ FROM \"test.txt\":\n\n");

//Read file content line by line
while (count < 10 && fscanf(fptr, "%d", &TxtArr[count]) == 1) {
  
  //Store numbers into array
  count++; 
}

//Close file after reading
fclose(fptr); 

//Store size of array
*size = count;

//Print the original array from file
printf("Original Array:\n");
for (int i = 0; i < count; i++) {
  printf("%d ", TxtArr[i]);
}
}

void Function5(int TxtArr[], int size){

//Declare DoubArr for the double of orginal array and OutContent for the contents of the file in a lengthy array
int DoubArr[10];
char OutContent[100];

//Create and Write to file out.txt in write mode
fptr = fopen("out.txt", "w");

int CopyArr[10];
for(int i = 0; i < size; i++){
  
  //Copy TxtArr to CopyArr
  CopyArr[i]= TxtArr[i];

  //Double all values from CopyArr and store in DoubArr
  DoubArr[i] = 2*CopyArr[i];

  //Write to the file the contents of DoubArr
  fprintf(fptr, "%d ", DoubArr[i]);
}

//Close the file
fclose(fptr);

//Open out.txt in read mode to printout the content from the file
fptr = fopen("out.txt", "r");
printf("\n\nDoubled Array (written to 'out.txt'):\n");
  while(fgets(OutContent, sizeof(OutContent), fptr)) {
    printf("%s ", OutContent);
  }
fclose(fptr);
}

void Function6(int TxtArr[],int size){
//Declare Variables and Arrays for Transposing, using a CopyArr as well as splitting ones and tens place again
int CopyArr[5];
int OnesPlace = 0;
int TensPlace = 0;
int TransposeArr[5];

for (int i = 0; i < size; i++){

  //Copy TxtArr into CopyArr
  CopyArr[i] = TxtArr[i];

  //Take ones place and tens place of each element and store into variables
  OnesPlace = CopyArr[i] % 10;
  TensPlace = CopyArr[i] / 10;

  //Switch ones and tens place and store into TransposeArr
  TransposeArr[i] = OnesPlace * 10 + TensPlace;
}

//Printout the Transposed Array
printf("\n\nTransposed Array:\n");
for (int i = 0; i < size; i++){
printf("%d ",TransposeArr[i]);
}


}
void Function7(int TxtArr[],int size){

//Printout the TxtArr in Hexadecimal using %X iterating through each element
printf("\n\nHexademical Array:\n");
for (int i = 0; i < size; i++){
  printf("%X ",TxtArr[i]);
}
}

void Function8(int TxtArr[],int size){

//Histogram from TxtArr

//Define variables used for splitting ones and tens place, a CopyArr
// A counter array for counting number of times number shows up and
// A Target array for iterating through the target number used for counter
int OnesPlace = 0;
int TensPlace = 0;
int TargetArr[10] = {0,1,2,3,4,5,6,7,8,9};
int CopyArr[10];
int CountArr[10] = {0};

//Count the number of times each number shows up in each element
for (int i = 0; i < size; i++){
  
  //Copy TxtArr into CopyArr
  CopyArr[i] = TxtArr[i];

  //Split element into tens and ones place
  OnesPlace = CopyArr[i] % 10;
  TensPlace = CopyArr[i] / 10;

  //Increment count for each digit found in ones and tens place
  CountArr[OnesPlace]++;

  //Only count the digit in tens if not a leading zero
  if (TensPlace > 0){
    CountArr[TensPlace]++;
  }
}

//Creating the Histogram
//Identify the number that appeared the most and store into MaxFreq
int MaxFreq = 0;
for (int j = 0; j < 10; j++){
  if (CountArr[j] > MaxFreq){
    MaxFreq = CountArr[j];
  }
}

//Printing out the Histogram
printf("\n\nHistrogram:\n\n");

//Vertical of Histogram, there is a blank filled into every spot unless there is an instance a number shows up
//Y axis has MaxFreq at top and goes down by 1 until reaches 1
for(int row = MaxFreq; row > 0; row--){
  printf("%d", row);
  for (int col = 0; col < 10; col++) {
    if (CountArr[col] >= row) {
        printf(" *");
    } else {
        printf("  ");
    }
}
printf("\n");
}

//Printing the horizonal axis of the Histogram
printf("  ");
for (int i = 0; i < 10; i++) {

  //Prints numbers 1-9 on x-axis
  printf("%d ", i);
}
printf("\n");
}
