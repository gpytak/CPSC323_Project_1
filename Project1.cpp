// ============================================================================
// Programmer: 
// Date: 03/11/2022
// Class: CPSC 232
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
    REJECT = 0, // REJECT is the starting state and 
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

// Prototypes
int getCol(char character);
void lexer(string line);

class FSM;
class StateTable 
{
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
    //lexer(string) 
    {
        // NOTE: Keep track of previous state
        // Was the previous line a comment?
        {
        }
        // Begin the string walk.
        {
            // What is the input?
            // get current column/input of current character 
            //getCol(char)
            // get current state of expression
            // State switching mechanism
            // Is current state starting state? (Did you just arrive on a new lexeme?)
            {
                // Only add tokens and lexemes that are not SPACE or COMMENT to container.
                {
                    
                }
            // If previous state is COMMENT. We move the expression index forward.
            // Reset lexeme string.
            }
            // Will skip comments entirely without catching.
            // Catch and concat character for current lexeme
            {

            }
            // Reassign previous state
        }
        // Handle end brackets, parethesis, semicolon, etc.
        if(true)
        {

        }
        // Handling block comments that extend onto other lines.
        else if(true)
        {

        }
        return tokens;
    }
}

int main()
{

    return 0;
}

int getCol(char character)
{
    return 0;
}