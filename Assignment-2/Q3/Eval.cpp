/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Duc Manh To  
 * Date: October 2022
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using namespace std;

Token calculate(const Token &lhs, const Token &rhs, const Token &operation)
{
    // Create the answer token
    Token answer;
    answer.text = "";
    answer.tt = integer;
    answer.val = 0;

    //Calculate the expression
    if (operation.tt == pltok)
        answer.val = lhs.val + rhs.val;
    else if (operation.tt == mitok)
        answer.val = lhs.val - rhs.val;
    else if (operation.tt == asttok)
        answer.val = lhs.val * rhs.val;
    else if (operation.tt == slashtok)
        answer.val = lhs.val / rhs.val;
    
    return answer;
}

int main () {
    Scanner S(cin);
    Token t;
    
    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();

    while (t.tt != eof || opstack.isEmpty() == false){
        if (t.tt == integer) 
        {
            numstack.push(t);
            t = S.getnext();
        } 
        else if (t.tt == lptok) 
        {
            opstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == rptok)
        {
            if (opstack.peek().tt == lptok)
            {
                opstack.pop();
                t = S.getnext();
            }
            else
            {
                Token rhs = numstack.pop();
                Token lhs = numstack.pop();
                Token operation = opstack.pop();

                Token answer = calculate(lhs, rhs, operation);

                numstack.push(answer);
            }
        }
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            if ((opstack.isEmpty() == false) && (opstack.peek().tt == pltok || opstack.peek().tt == mitok 
                                            || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                Token rhs = numstack.pop();
                Token lhs = numstack.pop();
                Token operation = opstack.pop();

                Token answer = calculate(lhs, rhs, operation);

                numstack.push(answer);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if (t.tt == asttok || t.tt == slashtok)
        {
            if (opstack.isEmpty() == false && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                Token rhs = numstack.pop();
                Token lhs = numstack.pop();
                Token operation = opstack.pop();

                Token answer = calculate(lhs, rhs, operation);

                numstack.push(answer);
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
    }

    cout << numstack.peek().val << endl;
    return 0;
}

