#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

// function to check if parentheses are balanced
bool isvalid(string expression) {
    stack<char> charstack; // stacks to store opening parentheses

    stringstream str_s(expression); // create a string stream to tokenise the input string
    string Token_;

    while (getline(str_s, Token_, ' ')) { // tokenise the string by space
        for (char currentchar : Token_) {
            if (currentchar == '(' || currentchar == '{' || currentchar == '[') {
                // if it's an opening parenthesisis, push it onto the stack
                charstack.push(currentchar);
            } else if (currentchar == ')' || currentchar == '}' || currentchar == ']') {
                // if it's a closing parenthesisis, check if the stack is not empty
                if (!charstack.empty()) {
                    char toop = charstack.top(); // get the top element from the stack

                    // check if the string closing parenthesisis matches the corresponding opening parenthesisis
                    if ((currentchar == ')' && toop == '(') || (currentchar == '}' && toop == '{') || (currentchar == ']' && toop == '[')) {
                        charstack.pop(); // pop the opening parenthesisis from the stack
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
    }

    return charstack.empty(); // check if there are any unmatched opening parentheses left in the stack
}

int main() {
    string In_String;
    cout << "enter a string: ";
    getline(cin, In_String);

    if (isvalid(In_String)) {
        cout << "Parentheses are balanced. So True" << endl;
    } else {
        cout << "Parentheses are not balanced. So False" << endl;
    }

    return 0;
}
