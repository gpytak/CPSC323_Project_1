// ============================================================================
// Programmer: Vincent Hsu, Gregory Pytak, Ethan Ton
// Date: 03/11/2022
// Class: CPSC 232
// Project: Project 1 Lexer
// ============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
// These are the inputs for the FSM.
enum TransitionStates {
	// REJECT is the starting state and final state.
	REJECT = 0,
	INTEGER = 1,
	REAL = 2,
	OPERATOR = 3,
	STRING = 4,
	SPACE = 5,
	SEPARATOR = 6,
	COMMENT = 7,
	UNKNOWN = 8,
	PLACEHOLDER = 9
};

// ============================================================================
//  Function Prototypes
// ============================================================================
int getCol(char character);
void lexer(string line);

// ============================================================================
//  Class Prototypes
// ============================================================================
class FSM;
class StateTable;
class Token;

// ============================================================================
//  MAIN
// ============================================================================
int main()
{
	ifstream inFile;
	int input;
	string fileInput = "";

	string file1 = "Input1.txt";
	string file2 = "Input2.txt";
	string file3 = "Input3.txt";

	cout << "Please choose which input file to analyze:" << endl;
	cout << "1: Input File 1" << endl;
	cout << "2: Input File 2" << endl;
	cout << "3: Input File 3" << endl;

	// Receive input from user to select which file to open
	// Loops if input received is not acceptable
	while (true)
	{
		cin >> input;
		if (input == 1 || input == 2 || input == 3)
		{
			break;
		}
		cout << "Please input 1, 2, or 3." << endl;
	}
	
	// Uses user input to select which file to open
	if (input == 1)
	{
		inFile.open("file1.txt");
	}
	else if (input == 2)
	{
		inFile.open("file2.txt");
	}
	else
	{
		inFile.open("file3.txt");
	}
	if (!inFile.is_open())
	{
		cout << "Failed to open file." << endl;
		return 0;
	}


	while (getline(inFile, fileInput))
	{
		lexer(fileInput);
	}

	inFile.close();
	return 0;
}

// ============================================================================
//  CLASS StateTable
// ============================================================================
class StateTable
{
	friend FSM; // INPUTS
	protected:  /* INTEGER, REAL, OPERATOR, STRING, SPACE, SEPARATOR, COMMENT, UNKNOWN  */
	int table[9][9] =
	{ 		      {REJECT,    INTEGER,       REAL,          OPERATOR,      STRING,       SPACE,         SEPARATOR,    COMMENT,  UNKNOWN},
		/* STATE 1 */ {INTEGER,   INTEGER    ,   REAL       ,   REJECT     ,   STRING     ,  REJECT     ,   REJECT     ,  COMMENT,  REJECT  },
		/* STATE 2 */ {REAL,      REAL       ,   UNKNOWN    ,   REJECT     ,   REJECT     ,  REJECT     ,   REJECT     ,  COMMENT,  REJECT  },
		/* STATE 3 */ {OPERATOR,  REJECT     ,   REJECT     ,   COMMENT    ,   REJECT     ,  REJECT     ,   REJECT     ,  COMMENT,  REJECT  },
		/* STATE 4 */ {STRING,    STRING     ,   REJECT     ,   STRING     ,   STRING     ,  REJECT     ,   REJECT     ,  COMMENT,  REJECT  },
		/* STATE 5 */ {SPACE,     REJECT     ,   REJECT     ,   REJECT     ,   REJECT     ,  REJECT     ,   REJECT     ,  COMMENT,  REJECT  },
		/* STATE 6 */ {SEPARATOR, REJECT     ,   REJECT     ,   REJECT     ,   REJECT     ,  REJECT     ,   REJECT     ,  COMMENT,  REJECT  },
		/* STATE 7 */ {COMMENT,   REJECT     ,   REJECT     ,   REJECT     ,   REJECT     ,  REJECT     ,   REJECT     ,  REJECT,   REJECT  },
		/* STATE 8 */ {UNKNOWN,   UNKNOWN    ,   UNKNOWN    ,   UNKNOWN    ,   UNKNOWN    ,  UNKNOWN    ,   UNKNOWN    ,  UNKNOWN,  REJECT  } };
};

// ============================================================================
//  CLASS FSM
// ============================================================================
class FSM
{
	void lexer(string fileInput)
	{
		StateTable StateTable;
		StateTable.table;
		string token = "";
		int lexeme;
		int col = REJECT;
		int currentState = REJECT;
		int previousState = REJECT;
		char currentChar = ' ';
		string lexemeLiteral;

		for (int i = 0; i < fileInput.length(); i++)
		{
			currentChar = fileInput[i];
			col = getCol(currentChar);
			currentState = StateTable.table[currentState][col];

			if (currentState == REJECT)
			{
				if (previousState != SPACE)
				{

				}
				token = "";
			}
			else
			{
				token += currentChar;
			}
			previousState = currentState;
		}
		if (currentState != SPACE && token != "")
		{

		}
	}
	//lexer(string) Function
		// NOTE: Keep track of previous state
		// Was the previous line a comment?
		// Begin the string walk.
			// What is the input?
			// get current column/input of current character 
			//getCol(char)
			// get current state of expression
			// State switching mechanism
			// Is current state starting state? (Did you just arrive on a new lexeme?)
				// Only add tokens and lexemes that are not SPACE or COMMENT to container.
			// If previous state is COMMENT. We move the expression index forward.
			// Reset lexeme string.
			// Will skip comments entirely without catching.
			// Catch and concat character for current lexeme
			// Reassign previous state
		// Handle end brackets, parethesis, semicolon, etc.
		// Handling block comments that extend onto other lines.

};

// ============================================================================
//  CLASS Token
// ============================================================================
class Token
{
	struct Tokens
	{

	};
};

// ============================================================================
//  int getCol
//      INPUT  - char
//      OUTPUT - Column number associated with the current input character
// ============================================================================
int getCol(char character)
{
	if (isspace(character))
	{
		return SPACE;
	}
	else if (isdigit(character))
	{
		return INTEGER;
	}
	else if (character == '.')
	{
		return REAL;
	}
	else if (isalpha(character))
	{
		return STRING;
	}
	else if (ispunct(character))
	{
		if (character == '+' || character == '-' || character == '/' || character == '*')
		{
			return OPERATOR;
		}
		if (character == '(' || character == ')' || character == '{' || character == '}')
		{
			return SEPERATOR;
		}
	}
	return UNKNOWN;
}

// ============================================================================
//  lexer
//      INPUT  - 
//      OUTPUT - 
// ============================================================================
string lexemeName(int lexeme)
{
	switch (lexeme)
	{
	case INTEGER:
		return "INTEGER";
		break;
	case REAL:
		return "REAL  ";
		break;
	case OPERATOR:
		return "OPERATOR";
		break;
	case SEPERATOR:
		return "SEPERATOR";
		break;
	case STRING:
		return "STRING";
		break;
	case COMMENT:
		return "COMMENT";
		break;
	case UNKNOWN:
		return "UNKNOWN";
		break;
	case SPACE:
		return "SPACE";
		break;
	default:
		return "ERROR";
		break;
	}
}
