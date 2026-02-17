#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

int MAX = 100;
char stack[100];
int top = -1;

void insert(char val)
{
    if (top >= MAX)
        return;
    stack[++top] = val;
}

char pop()
{
    if (top == 0)
        return 'a';
    return stack[top--];
}

char peek()
{
    if(top == MAX)
        return 'a';
    return stack[top];
}

void reset()
{
    top = -1;
}

bool isValid(const char *s) {
    reset();
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.

    size_t n = strlen(s);
    if(n%2 != 0)
    {
        return false;
    }
    if(s == NULL)
    {
        return true;
    }

    for(size_t i = 0; i < n; i++)
    {
        char c = s[i];

        if(c == '(' || c == '[' || c == '{')
        {
            insert(c);
            continue;
        }

        char check = peek();
        if((c == ')' && check == '(') || (c == ']' && check == '[') || (c == '}' && check == '{'))
        {
            pop();
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
