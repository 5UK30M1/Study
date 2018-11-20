#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string input();

int main()
{
    string sentence = input();
    cout << sentence;

}

string input()
{
    string sentence="";
    string word="";
    string temp;
    char symb;
    bool ind0;
    int ind = 0;
    int i =0;

        while ((symb = getchar()) != ' ')
        {
              word += symb;
              if (symb == '.')
              {
                  return sentence + word;
              }
              if (symb == ' ')
              {
                  sentence += word;
                  word = "";
                  continue;
              }
        }


}



/*
    for(int i = 0; i < 30; i++)
    {
        while ((symb = getchar()) != ' ')
        {
              word[i] += symb;
              if (symb == '.')
              {
                  return sentence + word[i];
              }
        }
        for (int j = 0; j < i; j++)
        {
            if(word[i] == word[j])
            {
                ind0 = true;
                break;
            }
        }
        if (ind0)
        {
            continue;
        }
        for (int j = 0; j < word[i].size(); j++)
        {
            temp = word[i][j];
            ind = word[i].find(temp);
        }
        if (ind > 1)
        {
            continue;
        }
        sentence += word[i];
    }
    return sentence;
*/
