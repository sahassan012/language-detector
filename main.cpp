#include <iostream>
#include <cctype>       // For the letter checking functions
#include <fstream>	// For file input
#include <iomanip>      // For setw()
#include <cstdlib>      // For exit()
#include <cmath>
using namespace std;

#define LIMIT 26        // Max array size, which is number of alphabet
#define languageSize 8	// max size of the language list, 8 total

// Store filenames into array of strings
const string languageNameList[] = {"MacbethEnglish.txt","MacbethFinnish.txt","MacbethFrench.txt","MacbethGerman.txt","MacbethHungarian.txt","MacbethItalian.txt","MacbethPortuguese.txt","MacbethSpanish.txt"};
const string languageName[] = {"English", "Finnish", "French", "German", "Hungarian", "Italian", "Portuguese", "Spanish"};

void printSortLetter(int languageLetterArray[languageSize][LIMIT]);

// 
//
// findIndex:
//    find the index value of the target element with the Array
int findIndex(int inputLetterArray[LIMIT], int target){
	for(int i = 0; i < LIMIT; i++){
		if(inputLetterArray[i] == target){
			return i;
		}
	}
	return 10000; 
	// this return should not return, if it does, something is wrong
}

// 
//
// findMin:
//    find the minimum value of the LetterDifference array, which is the langauge that is least different from user input
int findMin(int letterDifference[languageSize], int getSecond = 0){
	int minNum = letterDifference[0];
	int secMin = letterDifference[0];
	for(int i = 0; i < languageSize - 1; i++){
		if(letterDifference[i] < minNum){
			secMin = minNum;
			minNum = letterDifference[i];
		}
	}
	
	if(getSecond){
		return secMin;
	}
	return minNum;
}

//
//
// languageChecker:
//
void languageChecker(int languageLetterArray[languageSize][LIMIT], int inputLetterArray[LIMIT]){
	int letterDifference[languageSize] = {0};
	int startIndex;
	int target;
	int digitDiff;
	char languageIndex;
	
	for(int i = 0; i < languageSize; i++){
		for(int j = 0; j < LIMIT; j++){
			// store the difference between the input Letter compare to each langauge's sample letter Frequency
			startIndex = j;
			target = languageLetterArray[i][j];
			digitDiff = fabs(startIndex - findIndex(inputLetterArray, target));
			if(digitDiff <= 3){ // ignore small differnece to increase accuracy
				digitDiff = 0;
			}
			letterDifference[i] += digitDiff;
		}
	}
	// display language
	languageIndex = findIndex(letterDifference, findMin(letterDifference));
	string language = languageName[languageIndex];
	cout << "\n\nLanguage is " << language << "." << endl;
}

//
//
// swap:
//
void swap(int array[], int x, int y){
	int temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

// 
//
// bubbleSort:
//    sort in decending order
//
void bubbleSort(int list[], int sortList[],  int limit){
	for(int pass = 0; pass < limit - 1; pass++){
		for(int i = limit - 2; i >= 0 + pass; i--){
			if(list[i] < list[i + 1]){ // change the operator for opposite ordering
				swap(list, i, i+1);
				swap(sortList, i, i+1);
			}
		}
	}
}

//
//
//  printLanguageLetterCount:
//
void printLanguageLetterCount(int languageCountArray[languageSize][LIMIT]){
	for (int i=0; i<LIMIT; i++) {
        cout << (char)(i+'A') << ":";
        for(int j = 0; j < languageSize; j++){
            // Check if printable char and if any of the chars exist
            if ( languageCountArray[j][i] != 0 ) {
                // display the character and the number of occurences
                cout << setw(6) << languageCountArray[j][i];
            }
        }
	cout << "\n";
    }
}

//
//
// inputReader:
//	read user input text for option 3 and 4 and count letter frequency
//
void inputReader(int inputCountArray[LIMIT]){
	char c;
	// initalize array
	while(cin >> c){
		if(isalpha(c)){
			c = toupper(c);
			inputCountArray[c-'A']++;
		}
	}
}

//
//
// fileReader:
// 	read the given txt file that contains sample language text and get the letters count
//
void fileReader(int languageCountArray[languageSize][LIMIT]){
	
	// Iterate through all txt files and count letters in them
    	for(int languageIndex = 0; languageIndex < languageSize; languageIndex++){
        	ifstream inputFileStream;  // declare the input file stream
        	char c = ' ';              // input character
        	// set the name of the file to open using the index from languageIndex
        	string fileName = languageNameList[languageIndex];
        
        // open file
        inputFileStream.open( fileName.c_str());   // Convert C++ string to expected C-style string 
        if(!inputFileStream.is_open()){
            cout << "Could not find input file.  Exiting..." << endl;
            exit(-1);
        }
        while(inputFileStream >> c){
             // convert alphabetic input characters to upper case
             if(isalpha(c)){
                 c = toupper(c);
                 languageCountArray[languageIndex][c-'A']++; // update letter count for the current language
            }
        }   
	inputFileStream.close();
    }
}


//
//
// printSortLetter: 
//
void printSortLetter(int languageLetterArray[languageSize][LIMIT]){
	char printable; // tempoary variable
	for (int i=0; i<LIMIT; i++) {
        cout << "   "; // indent in front of each lines of output
        for(int j = 0; j < languageSize; j++){
			      printable = languageLetterArray[j][i] + 'A';// This prints out 0 as A, and 2 as C, which is what we wanted
            cout << setw(6) << printable;
    	}
    	cout << "\n"; // newline for each line output
	}
	
}

//
//
// printInputLetterCount:
//
void printInputLetterCount(int inputCountArray[LIMIT], int inputLetterArray[LIMIT]){
	char printable; 
	for(int i = 0; i < LIMIT; i++){
		printable = inputLetterArray[i] + 'A';
		cout << printable << ":" << inputCountArray[i] << " ";
	}
}


//
//
// initializeArray:
//
void initalizeArray(int languageLetterArray[languageSize][LIMIT], int inputLetterArray[LIMIT], int inputCountArray[LIMIT]){
	// Initalize language letter array
	for(int i = 0; i < languageSize; i++){
		for(int j = 0; j < LIMIT; j++){
			languageLetterArray[i][j] = j;
		}
	}

	//Initialize input letter array
	for(int i = 0; i < LIMIT; i++){
		inputLetterArray[i] = i;
	}
}


// 
//
// printUserSortLetter:
//
void printUserSortLetter(int languageLetterArray[languageSize][LIMIT], int inputLetterArray[LIMIT]){

	char printable; // tempoary variable
	int i = 0;
	for (i = 0; i < LIMIT; i++) {
        	cout << "   "; // indent in front of each lines of output
        	for(int j = 0; j < languageSize; j++){
	    		printable = languageLetterArray[j][i] + 'A';// This prints out 0 as A, and 2 as C, which is what we wanted
            		cout << setw(6) << printable;
    		}
    		printable = inputLetterArray[i] + 'A'; // prints out extra colume of user input's letter sort order
    		cout << setw(6) << printable;
    		cout << "\n";
	}
}

//
//
// main:
//
int main(){
      
      	// 2D use for storing letter count numbers for each language
	int languageCountArray[languageSize][LIMIT] = {0};

        // The "pointer" array, size is exactly same as languageCountArray
        // each element in this array is matched to a unique index in languageCountArray
        // languageCountArray stores A's letter count in index 0, and C's letter count in index 2
        // during bubbleSort, for each value we swap in languageCountArray, the index value of languageLetterArray is also swapped
        // The languageLetterArray after bubbleSort gives the frequency of letters in chars instead of integer values.
	int languageLetterArray[languageSize][LIMIT];
	
	// user input array
	int inputCountArray[LIMIT] = {0};
	
	// letter order array 
	int inputLetterArray[LIMIT];
	
	initalizeArray(languageLetterArray, inputLetterArray, inputCountArray);
	fileReader(languageCountArray); // read txt file of each language 
	
	int userInput;
	
	// display prompt
	cout << "Program 3: Which Language.\n\n";
	cout << "Select from the following stages of output to display:\n"
   		 <<	"1. Letter frequency counts\n"            
   		 <<	"2. Letter frequency order\n"                
   		 <<	"3. Get user input and display frequency counts\n" 
   		 <<	"4. Get user input, display frequency counts, and display language\n"
   		 << "0. Exit the program\n"
		 << "Your choice --> ";
	
	// take input
	cin >> userInput;
	

	if(userInput >= 1){
		cout << "Letter Frequency Counts:\n";
    		cout << "    Engl  Finn  Fren  Germ  Hung  Ital  Port  Span\n";
    		printLanguageLetterCount(languageCountArray);	
	} 
	if(userInput >= 2){
		cout << "\nLetter frequency order:\n";
    		cout << "     Engl  Finn  Fren  Germ  Hung  Ital  Port  Span\n";
    		for(int languageIndex = 0; languageIndex < languageSize; languageIndex++){
    			bubbleSort(languageCountArray[languageIndex], languageLetterArray[languageIndex], LIMIT);
    		}
		printSortLetter(languageLetterArray);
	}
	if(userInput >= 3){
		cout << "\nCopy and paste a paragraph of text to be analyzed, followed by ^z (PC) or ^d (Mac): \n";
	    	inputReader(inputCountArray);
	    	cout << "\n\n";
	    	printInputLetterCount(inputCountArray, inputLetterArray);
	    	cout << "\n\nLetter frequency order:\n";
    		cout << "     Engl  Finn  Fren  Germ  Hung  Ital  Port  Span  User\n";
    		bubbleSort(inputCountArray, inputLetterArray, LIMIT);
		printUserSortLetter(languageLetterArray, inputLetterArray);
	}
	if(userInput >= 4){
		languageChecker(languageLetterArray, inputLetterArray);
		
	}
    return 0;
}
