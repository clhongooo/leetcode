#include<iostream>
#include<string>

using namespace std;

int lengthOfLastWord(string s) 
{
    if(s.size() == 0)
    {
        return 0;
    }
    
    bool ensure_last = false;
    int last = -1;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] == ' ' && ensure_last)
        {
            if(ensure_last)
                return last - i; 
        }
        else if(s[i] != ' ' && ensure_last == false)
        {
                ensure_last = true;
                last = i;
        }
    }
    return last + 1;
}

int main()
{
    cout << lengthOfLastWord("hello world");
    return 0;
}