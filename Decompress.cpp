#include "header.h"

string decompress(vector<int> input)
{
    std::string output = "";
    unordered_map<int, string> t;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        t[i] = ch;
    }
    int o = input[0], r;
    string str = t[o];
    string B = "";
    B += str[0];
    output += str;
    int count = 256;
    for (int i = 0; i < input.size() - 1; i++) {
        r = input[i + 1];
        if (t.find(r) == t.end()) {
            str = t[o];
            str = str + B;
        }
        else {
            str = t[r];
        }
        output += str;
        B = "";
        B += str[0];
        t[count] = t[o] + B;
        count++;
        o = r;
    }
    return output;
}
