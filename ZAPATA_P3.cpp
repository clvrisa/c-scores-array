// Project 3

#include <iostream>
#include <fstream>
using namespace std;

// function prototypes
void getInput(/*out*/int [], int);
void getFileInput(/*out*/int[], /*in*/int);
void showOutput(/*out*/int[],/*in*/int);
void showEntry (/*out*/int[],int[],/*in*/int);
int getTotal(/*out*/int[], /*in*/int);
int getLeast(/*out*/int[], /*in*/int);
int getMost(/*out*/int[], /*in*/int);
double getAverage(/*out*/int[], int);

int main()
{
    const int size = 10;
    int numbers[size]; // 1D array declaration
    int number[size];
    int choice, entry, count;

    do
    {
    cout << "\n---------------------------------------------------" << endl;
    cout << "1-D ARRAY PROCESSING MENU OPTIONS" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "1. Read in 10 scores from user." << endl;
    cout << "2. Read in 10 scores from the file, scores.txt." << endl;
    cout << "3. Print all scores." << endl;
    cout << "4. Print the highest score." << endl;
    cout << "5. Print the lowest score." << endl;
    cout << "6. Print the average score." << endl;
    cout << "7. Print one score (give its entry number)" << endl;
    cout << "8. Quit program" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // array related processing done by the the following function calls

    switch(choice)
    {
        case 1: getInput(numbers, size);
            break;
        case 2: getFileInput(numbers, size); // call function to input elements from a file
            break;
        case 3: showOutput(numbers, size); // call function to output elements
            break;
        case 4: cout << "\nThe highest score is " << getMost(numbers, size) << endl; // call function to determine highest number of all elements
            break;
        case 5: cout << "\nThe lowest number is " << getLeast(numbers, size) << endl; // call function to determine least number of all elements
            break;
        case 6: cout << "\nThe average score is " << getAverage(numbers, size) << endl; // call function to determine average of all elements
            break;
        case 7: showEntry(numbers, number, size);
            break;
        case 8: cout << "\nArray processing test now concluded. Exiting program ....." << endl;
            break;
        default: cout << "\nINVALID CHOICE ...please retype" << endl;
    }

    }while(choice != 8);

    return 0;
}

void getInput(/*out*/int numbers[], int size)
{
    // input elements
    cout << endl;
    for (int count = 0; count < size; count++)
    {
        cout << "Enter Score #" << (count+1) << ": ";
        cin >> numbers[count]; // input to array a single value using the subscript or index
    }
}
void getFileInput(/*out*/int numbers[], /*in*/int size)
{
   ifstream inData;
   string fileName;

   cout << "\nPlease enter filename: ";
   cin >> fileName;

   inData.open(fileName.c_str()); // argument for runtime input of file name

   cout << "File has successfully opened and 10 scores have been read and stored." << endl;
   cout << "Please select the print all scores menu option to view the scores." << endl;

   //inData >> numbers[count]; // priming read
   for(int count = 0; count < size; count++)
   {
       inData >> numbers[count];
   }
   inData.close();
}
void showOutput(/*out*/int numbers[], int size)
{
    // show elements
    for (int count = 0; count < size; count++)
    {
        cout << "Score #" << (count+1) << ": " << numbers[count] << endl; // output a single value using the subscript or index
    }
}
void showEntry (/*out*/int numbers[],int number[],/*in*/int size)
{
    int count;

    cout << "\nPlease enter entry or row # of score you want: " << endl;
    cin >> count;
    cout << "Entry #" << count << " score: " << numbers[count] << endl;
}

int getTotal(/*out*/int numbers[], int size)
{
    int total = 0;
 // sum all the elements
    for (int count = 0; count < size; count++)
    {
        total = total + numbers[count];
    }

    return total;
}
int getLeast(/*out*/int numbers[], int size)
{
    int least = 2000;
    // find least number
    least = numbers[0]; // assign first element value to least temporary state
    for (int count = 1; count < size; count++)
    {
        if (numbers[count] < least)
        least = numbers[count]; // swap values to store a smaller element
    }

    return least;
}
int getMost(/*out*/int numbers[], int size)
{
    int most = 0;
    // find highest number
    most = numbers[0]; // assign first element value to highest temporary state
    for (int count = 1; count < size; count++)
    {
        if (numbers[count] > most)
        most = numbers[count]; // swap values to store a higher element
    }

    return most;
}
double getAverage(/*out*/int numbers[], int size)
{
    int total = 0;
    double average = 0;

    getTotal(numbers,size);

    average = total / size;

    return average;
}
