#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>


using namespace std;

int main()
{
    ifstream fin("quack.in");
    ofstream fout("quack.out");
    string laveles, command;
    int a , b , n1, n2;
    int count_command = 0;
    char chr1, chr2;
    queue<int> queue_value;
    vector<pair <int,string>> labels;
    vector<string> commands;
    int Register[26];
    while (fin >> command){
        commands.push_back(command);
        if (command[0] == ':'){
            laveles = command.substr(1);
            labels.push_back(make_pair(count_command, laveles));
        }
        count_command++;
    }
    count_command = 0;
    while (count_command < commands.size()){
        command = commands[count_command];
        if (atoi(command.c_str()) == 0 && command != "0"){
            switch (command[0]){
                case '+':{
                    a = queue_value.front();
                    queue_value.pop();
                    b = queue_value.front();
                    queue_value.pop();
                    queue_value.push((uint16_t)(a + b));
                }
                    break;
                case 'E':{
                    chr1 = command[1];
                    chr2 = command[2];
                    n1 = chr1 - 'a';
                    n2 = chr2 - 'a';
                    if (Register[n1] == Register[n2]){
                        laveles = command.substr(3);
                        for (int j = 0; j < labels.size(); j++)
                            if (labels[j].second == laveles){
                                count_command = labels[j].first;
                                break;
                            }
                    }
                }
                    break;

                case '*':{
                    a = queue_value.front();
                    queue_value.pop();
                    b = queue_value.front();
                    queue_value.pop();
                    queue_value.push((uint16_t)(a * b));
                }
                    break;
                case '-':{
                    a = queue_value.front();
                    queue_value.pop();
                    b = queue_value.front();
                    queue_value.pop();
                    queue_value.push((uint16_t)(a - b));
                }
                    break;

                case '%':{
                    a = queue_value.front();
                    queue_value.pop();
                    b = queue_value.front();
                    queue_value.pop();
                    if (b == 0)
                        queue_value.push(0);
                    else
                        queue_value.push((uint16_t)(a % b));
                }
                    break;
                case '>':{
                    chr1 = command[1];
                    int number = chr1 - 'a';
                    a = queue_value.front();
                    queue_value.pop();
                    Register[number] = a;
                }
                    break;
                case '/':{
                    a = queue_value.front();
                    queue_value.pop();
                    b = queue_value.front();
                    queue_value.pop();
                    if (b == 0)
                        queue_value.push(0);
                    else
                        queue_value.push((uint16_t)(a / b));
                }
                    break;
                case '<':{
                    chr1 = command[1];
                    n1 = chr1 - 'a';
                    a = Register[n1];
                    queue_value.push(a);
                }
                    break;
                case 'P':{
                    if (command.length() > 1){
                        chr1 = command[1];
                        n1 = chr1 - 'a';
                        fout << Register[n1] << "\n";
                    }
                    else{
                        a = queue_value.front();
                        queue_value.pop();
                        fout << a << "\n";
                    }
                }
                    break;

                case 'J':
                {
                    laveles = command.substr(1);
                    for (int j = 0; j < labels.size(); j++)
                        if (labels[j].second == laveles){
                            count_command = labels[j].first;
                            break;
                        }
                }
                    break;
                case 'C':{
                    if (command.length() > 1){
                        chr1 = command[1];
                        n1 = chr1 - 'a';
                        chr1 = abs(Register[n1] % 256);
                        fout << chr1;
                    }
                    else{
                        a = queue_value.front();
                        queue_value.pop();
                        chr1 = abs(a % 256);
                        fout << chr1;
                    }
                }
                    break;
                case 'Z':{
                    chr1 = command[1];
                    n1 = chr1 - 'a';
                    if (Register[n1] == 0){
                        laveles = command.substr(2);
                        for (int j = 0; j < labels.size(); j++)
                            if (labels[j].second == laveles) {
                                count_command = labels[j].first;
                                break;
                            }
                    }
                }
                    break;

                case 'G': {
                    chr1 = command[1];
                    chr2 = command[2];
                    n1 = chr1 - 'a';
                    n2 = chr2 - 'a';
                    if (Register[n1] > Register[n2])  {
                        laveles = command.substr(3);
                        for (int j = 0; j < labels.size(); j++)
                            if (labels[j].second == laveles){
                                count_command = labels[j].first;
                                break;
                            }
                    }
                }
                    break;
                case 'Q':{
                    return 0;
                }
                default: break;
            }
        }
        else{
            queue_value.push(abs(atoi(command.c_str())) % 65536);
        }
        count_command++;
    }
    return 0;
}
