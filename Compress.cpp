#include "header.h"

vector<int> compress(string input){
    unordered_map <string, int> t;
    for(int i = 0; i < 256; i++){
        string ch = "";
        ch += char(i);
        t[ch] = i;
    }

    string A = "", B = "";
    A += input[0];
    int code = 256;
    vector<int> output;
    for(int i = 0; i < input.length(); i++){
        if(i != input.length() - 1){
            B += input[i+1];
        }
        if(t.find(A + B) != t.end()){
            A += B;
        } else {
            output.push_back(t[A]);
            t[A + B] = code;
            code++;
            A = B;
        }
        B = "";
    }
    output.push_back(t[A]);
    return output;
}
