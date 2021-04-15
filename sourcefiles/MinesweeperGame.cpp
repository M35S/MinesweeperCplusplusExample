#include <iostream>
#include <string>

using namespace std;

// Enum with type name MINES containing 4 values:
enum MINES
{							// This technique uses an array to relate string values with enum values.
	HIDDEN_MINE,			// enum val = 0		str val = "*"
	UNCOVERED_MINE,			// enum val = 1		str val = "X"
	HIDDEN_SAFE,			// enum val = 2		str val = "-"
	UNCOVERED_SAFE			// enum val = 3		str val = "O"
};

const int NUM_OF_CHARS = 4;								// = 4 (0, 1, 2, 3)	//
string names[NUM_OF_CHARS] = { "*", "X", "-", "O" };	// 1D str array = *, X, -, O //

const int ROWS = 7;					// Number of rows = 7 //
const int COLUMNS = 7;				// Number of columns = 7 //
MINES minefield[COLUMNS][ROWS];		// 2D Array of type MINES

/* 2D Array explanation (We essentially build a matrix).
Example:				column elements (top to bottom):
			  [y][x]		 0 & 1
int numberGrid[3][2] =	{							  
							{1, 2}	<--------------	< 0,	
							{3, 4}	<--------------	< 1, row elements (left to right):
							{5, 6}	<--------------	< 2
						}

Accessing these elements examples.
Example: If we want to access element value "2":
cout << numberGrid[0][1];
				  [y][x]

Example 2: If we want to access element value "5":
cout << numberGrid[2][0];
				  [y][x]

We can use nested for loops to iterate through the whole 2D array.
We keep looping while "i" is less than "3" (i < 3). We use 3 as there are 3 elements.
Note the relationship between numberGrid[i][j] and numberGrid[3][2]
// while i less than 3, increment row.
for (int i = 0; i < 3; i++)
{
// while j less than 2, increment col.
	for (int j = 0; j < 2; j++)
		{
			cout << numberGrid[i][j];
		}
	cout << endl;
}
*/

void printSingle(MINES type);					// Print single char

int main()
{	
	// Initialise 2D array minefield / board using nested for loops
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			minefield[i][j] = HIDDEN_SAFE;
		}
	}

	// Place random mines on 2D array minefield 10 times
	for (int i = 0; i < 10; i++)
	{
		int x = rand() % 7;
		int y = rand() % 7;
		minefield[x][y] = HIDDEN_MINE;
	}

	// Print 2D minefield after initialisation
	cout << "Below is the 2D minefield array output." << endl;
	cout << "Each component has it's own value:" << endl;
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			cout << minefield[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	// Print 2D minefield out with chars
	cout << "Below is the 2D minefield array output." << endl;
	cout << "Each component's value corresponds to the string value:" << endl;
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			printSingle(minefield[i][j]);
		}
		cout << endl;
	}

	cout << endl;

	// *********** Insert while loop here *************************
	int xPos = 0;
	int yPos = 0;

	while (minefield[yPos][xPos] != UNCOVERED_MINE)
	{
		// User input for x and y values on 2D minefield array
		cout << "Enter a value between 0 - 6 for y position:";
		cin >> yPos;
		cout << "Enter a value between 0 - 6 for x position:";
		cin >> xPos;
		cout << endl;

		cout << "You entered:" << endl;
		cout << "y = " << yPos << endl << "x = " << xPos << endl;

		cout << "This results in minefield[" << yPos << "][" << xPos << "] = " << minefield[yPos][xPos] << endl;

		cout << endl;

		// Switch statement
		switch (minefield[yPos][xPos])
		{
		case 0:
			cout << "This is the hidden mine '*'" << endl;
			cout << "Oh no, you've hit a mine!" << endl;
			minefield[yPos][xPos] = UNCOVERED_MINE;
			for (int i = 0; i < COLUMNS; i++)
			{
				for (int j = 0; j < ROWS; j++)
				{
					printSingle(minefield[i][j]);
				}
				cout << endl;
			}
			break;

		case 1:
			cout << "This is the uncovered mine 'X'";
			break;

		case 2:
			cout << "This is the hidden safe '-'" << endl;
			cout << "Phew, you dodged a mine!" << endl;
			minefield[yPos][xPos] = UNCOVERED_SAFE;
			for (int i = 0; i < COLUMNS; i++)
			{
				for (int j = 0; j < ROWS; j++)
				{
					printSingle(minefield[i][j]);
				}
				cout << endl;
			}
			break;

		case 3:
			cout << "This is the uncovered safe 'O'";
			break;
		}

		cout << endl;
	}
	// ********************** end while loop here *****************

	cout << "Press ENTER to end the program." << endl;
	cin.ignore();
	cin.get();

	return 0;
}

void printSingle(MINES type)
{
		cout << names[type] << " ";
}