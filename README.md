# Language Detector
### About
This program uses given text files with different languages and uses their character frequency as a signature. It then counts the character frequency for each given language, sorts, and stores it in an array. Finally, it uses the character frequency of the user's input with that of the stored frequency picked up from the text files and matches the most frequent characters to determine which language is being read.


In the directory, you will find 8 files each consisting of a translation of Macbeth by William Shakespeare.
Given these files, the following languages may be identified by the program:
- English
- Finnish
- French
- German
- Hungarian
- Italian
- Portuguese
- Spanish 

### How it works
Once the program is ran, the user is prompted as such: 
```console
Language Detector.

Select from the following stages of output to display:
1. Letter frequency counts
2. Letter frequency order
3. Get user input and display frequency counts
4. Get user input, display frequency counts, and display language
0. Exit the program
Enter choice >
```
If 1 or 2 are entered, the program then simply uses the Macbeth text files in the project directory to count character frequency counts or order and display the results.

If 3 or 4 are entered, the program will prompt user to enter a paragraph and displays frequency counts and displays which language is being read.

### How to run(from command line)
Compile the program with:
```console
$ g++ main.cpp
```
This will create an executable ``a.out`` file

Run the executable using:
```console
$ ./a.out
```

