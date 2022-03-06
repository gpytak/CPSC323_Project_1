// ============================================================================
// Programmer: , , Ethan Ton
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
//FOR SCIENCE
enum TransitionStates {
    // REJECT is the starting state and 
    REJECT      = 0, 
    INTEGER     = 1,
    REAL        = 2,
    OPERATOR    = 3,
    STRING      = 4,
    SPACE       = 5,
    SEPARATOR   = 6,
    COMMENT     = 7,
    UNKNOWN     = 8,
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

    string file1 = "Input1.txt";
    string file2 = "Input2.txt";
    string file3 = "Input3.txt";

    cout << "Please choose which input file to analyze:" << endl;
    cout << "1: Input File 1";
    cout << "2: Input File 2";
    cout << "3: Input File 2";

    cin >> input;

    if(input == 1)
    {

    }
    else if(input == 2)
    {
        
    }
    else
    {

    }

    return 0;
}

class StateTable {
friend FSM; // INPUTS
protected:  /* INTEGER, REAL, OPERATOR, STRING, SPACE, SEPARATOR, COMMENT, UNKNOWN  */
int table[9][9] = 
             {{REJECT,    INTEGER,       REAL,          OPERATOR,      STRING,       SPACE,         SEPARATOR,    COMMENT,  UNKNOWN},
/* STATE 1 */ {INTEGER,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,  PLACEHOLDER,   PLACEHOLDER,  COMMENT,  PLACEHOLDER  },
/* STATE 2 */ {REAL,      PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,  PLACEHOLDER,   PLACEHOLDER,  COMMENT,  PLACEHOLDER  },
/* STATE 3 */ {OPERATOR,  PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,  PLACEHOLDER,   PLACEHOLDER,  COMMENT,  PLACEHOLDER  },
/* STATE 4 */ {STRING,    PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,  PLACEHOLDER,   PLACEHOLDER,  COMMENT,  PLACEHOLDER  },
/* STATE 5 */ {SPACE,     PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,  PLACEHOLDER,   PLACEHOLDER,  COMMENT,  PLACEHOLDER  },
/* STATE 6 */ {SEPARATOR, PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,  PLACEHOLDER,   PLACEHOLDER,  COMMENT,  PLACEHOLDER  },
/* STATE 7 */ {COMMENT,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,  PLACEHOLDER,   PLACEHOLDER,  REJECT,   PLACEHOLDER  },
/* STATE 8 */ {UNKNOWN,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,   PLACEHOLDER,  PLACEHOLDER,   PLACEHOLDER,  COMMENT,  PLACEHOLDER }};
};

class Token {
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
//  int getCol
//      INPUT - char
//      OUTPUT - Column number associated with the current input character
// ============================================================================
int getCol(char character)
{
    return 0;
}