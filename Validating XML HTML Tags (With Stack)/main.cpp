//main.cpp

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;


// Validates that Each HTML tag is written properly
// and has a closing tag

// Does not works for self closing tags
bool validateHTML(string document)
{
    Stack<string> tagStack;

    for (int i = 0; i < document.length(); i++)
    {
        if (document[i] == '<')
        {
            int j;
            for (j = i + 1; j < document.length(); j++)
            {
                if (document[j] == '>')
                    break;
            }
            if (j < document.length())
            {
                string tag = document.substr(i + 1, j - i - 1);
                if (tag[0] != '/')
                {
                    tagStack.push(tag);
                }
                else{
                    if (!tagStack.empty() && tagStack.top() == tag.substr(1)){
                        tagStack.pop();
                    }
                    else
                        return false;
                }
            }
            else
                return false;
        }
    }
    return tagStack.empty();
}


int main()
{
    //Correct document
    string document1 = "<html> <body> <h1>My First Heading</h1> <p>My first paragraph.</p> </body> </html>";
    //Incorrect document
    string document2 = "<html> <body> </h1>My First Heading<h1> <p>My first paragraph.</p> </body> </html>";

    //For Document 1
    if (validateHTML(document1))
        cout << "This Document is Correct ! " << endl;
    else
        cout << "This Document has errors in Format ! " << endl;

    //For Document 2
    if (validateHTML(document2))
        cout << "This Document is Correct ! " << endl;
    else
        cout << "This Document has errors in Format ! " << endl;
    return 0;
}
