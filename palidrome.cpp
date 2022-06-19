#include "stack.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    cout << "Please Enter a String:" << endl;
    cout << '<';

    int index = 0,maxSize = 100;
    /*
    char * pali = new char [maxSize];
    while(cin.peek() != '\n'){
        cin.get(pali[index]);
        index++;
        if(index >= maxSize)
            maxSize += 1;
    }
*/
    char temp[maxSize];
    cin.getline(temp,maxSize,'\n');

    char check[maxSize];
    int count = 0;
    for(int i = 0; i < strlen(temp); i++)
    {
        if(isalpha(temp[i])) {
            check[count] = toupper(temp[i]);
            count++;
        }
    }


    Stack< char > paliStack;         //create a stack of chars
    int c = count - 1;
    for(int i  = 0; i < c; i++){
        paliStack.push(check[i]);
        paliStack.push(check[c]);
        if(check[i] == check[c])
        {
            paliStack.pop(check[i]);
            paliStack.pop(check[c]);
        }
        c--;
    }

    if(paliStack.isStackEmpty())
        cout << '"' << temp << '"' << " IS a palidrome" << endl;
    else
        cout << '"' << temp << '"' << " is NOT a palidrome" << endl;
    return 0;

    }
