#include<iostream>
#include<vector>
#include<utility>
#include<string>

using namespace std;

vector<pair<string, int>> roman_vec = {
    {"M",1000},
    {"CM", 900},
    {"D",500},
    {"CD",400},
    {"C",100},
    {"XC",90},
    {"L",50},
    {"XL",40},
    {"X",10},
    {"IX",9},
    {"V",5},
    {"IV",4},
    {"I",1}
};

string intToRoman(int num) 
{
    string str_result;
    for(auto item : roman_vec)
    {
        while(num >= item.second)
        {
            str_result += item.first;
            num -= item.second;
        }
    }
    return str_result;
}

int main()
{
    cout << intToRoman(58);
    return 0;
}