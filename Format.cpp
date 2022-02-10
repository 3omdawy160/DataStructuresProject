string format(string input) {
    string space = "";
    const string tab = "    ";
    string output;
    string names[1000];
    int index = 0,numofTabs=0;
    bool flag;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '<' && input[i + 1] == '/') {
            flag = false;
            output = output + "\n";
            string name;
            i+=2;
            for (int j = i; input[j] != '>'; j++) {
                name += input[j];
                i = j+1;
            }
            for (int j = 0; j < index; j++) {
                if (names[j] == name) {
                    space = "";
                    for (int k = 0; k < numofTabs - 1; k++) {
                        space += tab;
                    }
                    numofTabs--;
                    output += space + "</" + names[j] + ">";
                    names[j] = "";
                    break;
                }
            }
        }
        else if (input[i] == '<') {
            flag = false;
            output = output + "\n";
            ++i;
            for (int j = i; input[j] != '>'; j++) {
                names[index] = names[index] + input[j];
                i = j;
                
            }
            output += space+'<' + names[index] + ">";
            space = space + tab;
            numofTabs++;
            index++;
            i++;
        }
        else {
            if (!flag) {
                output = output + "\n" + space;
                flag = true;
            }
            output += input[i];
        }
    }
    return output;
}
