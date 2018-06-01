#include<iostream>
#include<string>

using namespace std;

int romanToInt(string s) 
{
    string str;
    int size = s.size();
    int result = 0;
    for(int i = 0; i < size; )
    {
        if(s[i] == 'I')
        {
            if(i < size - 1 && s[i + 1] == 'V')
            {
                result += 4;
                i += 2;
                continue;
            }
            else if(i < size - 1 && s[i + 1] == 'X')
            {
                result += 9;
                i += 2;
                continue;
            }
            else
            {
                result += 1;
            }
        }
        else if (s[i] == 'X')
        {
            if(i < size - 1 && s[i + 1] == 'L')
            {
                result += 40;
                i += 2;
                continue;
            }
            else if(i < size - 1 && s[i + 1] == 'C')
            {
                result += 90;
                i += 2;
                continue;
            }
            else
            {
                result += 10;
            }                
        }
        else if(s[i] == 'C')
        {
            if(i < size - 1 && s[i + 1] == 'D')
            {
                result += 400;
                i += 2;
                continue;
            }
            else if(i < size - 1 && s[i + 1] == 'M')
            {
                result += 900;
                i += 2;
                continue;
            }
            else
            {
                result += 100;
            }                
        }
        else if(s[i] == 'V')
        {
            result += 5;
        }
        else if(s[i] == 'L')
        {
            result += 50;
        }
        else if(s[i] == 'D')
        {
            result += 500;
        }
        else if(s[i] == 'M')
        {
            result += 1000;
        }
        i += 1;
    }
    return result;
}

int main()
{
    cout << romanToInt("III");
    return 0;    
}