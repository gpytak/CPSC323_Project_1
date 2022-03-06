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
final state.
    INTEGER = 1,
    REAL = 2,
    OPERATOR = 3,
    STRING = 4,
    SPACE = 5,
    SEPARATOR = 6,
    COMMENT = 7,
    UNKNOWN = 8,
};

class FSM;
class StateTable {
friend FSM; // INPUTS
protected:  /* INTEGER, REAL, OPERATOR, STRING, SPACE, SEPARATOR, COMMENT, UNKNOWN  */
int table[9][9] = 
{ {REJECT, INTEGER, REAL, OPERATOR, STRING, SPACE, SEPARATOR, COMMENT, UNKNOWN},
/* STATE 1 */ {"INTEGER",   -------,   ----,   --------,   ------,  -----,   ---------,  COMMENT,  -------  },
/* STATE 2 */ {"REAL",      -------,   ----,   --------,   ------,   -----,   ---------,  COMMENT,  -------  },
/* STATE 3 */ {"OPERATOR",  -------,   ----,   --------,   ------,   -----,   ---------,  COMMENT,  -------  },
/* STATE 4 */ {"STRING",    -------,   ----,   --------,   ------,   -----,   ---------,  COMMENT,  -------  },
/* STATE 5 */ {"SPACE",     -------,   ----,   --------,   ------,   -----,   ---------,  COMMENT,  -------  },
/* STATE 6 */ {"SEPARATOR", -------,   ----,   --------,   ------,  -----,   ---------,  COMMENT,  -------  },
/* STATE 7 */ {"COMMENT", -------,   ----,   --------,   ------,  -----,   ---------,  REJECT, -------  },
/* STATE 8 */ {"UNKNOWN",   -------,   ----,   --------,   ------,  -----,   ---------,  COMMENT,  -------  }
};
};

class Token {
lexer(string) 
{
    // NOTE: Keep track of previous state
    // Was the previous line a comment?
    {
    }
    // Begin the string walk.
    {
        // What is the input?
        // get current column/input of current character 
        getCol(char)
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
