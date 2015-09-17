/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 17 Сентябрь 2015 г., 19:10
 */

#include <iostream>
#include <fstream>
using namespace std;

short strToNum(string str) {
    if (str[0] == '9') {
        return (str[1]-48)*10 + str[2]-48 - 90;
    }
    else {
        return (str[1]-48)*10 + str[2]-48 + 10;
    }
}

int monNum(string str) {
    if (str[0] == 'F') {
        return 1;
    }
    if (str[0] == 'S') {
        return 8;
    }
    if (str[0] == 'O') {
        return 9;
    }
    if (str[0] == 'N') {
        return 10;
    }
    if (str[0] == 'D') {
        return 11;
    }
    if (str[0] == 'J') {
        if (str[1] == 'a') {
            return 0;
        }
        else {
            if (str[2] == 'l') {
                return 6;
            }
            else {
                return 5;
            }
        }
    }
    else {
        if (str[0] == 'M') {
            if (str[2] == 'r') {
                return 2;
            }
            else {
                return 4;
            }
        }
        else {
            if (str[1] == 'p') {
                return 3;
            }
            else {
                return 7;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    bool mon[372];
    short i, s, e, j;
    while (getline(stream, line)) {
        
        for (i = 0; i < 372; i++) {
            mon[i] = false;
        }
        i = 0;
L1:
        s = monNum(line.substr(i, 3)) + strToNum(line.substr(i+5, 3))*12;
        i += 9;
        e = monNum(line.substr(i, 3)) + strToNum(line.substr(i+5, 3))*12;
        i += 8;
        for (j = s; j <= e; j++) {
            mon[j] = true;
        }
        if (line[i] == ';') {
            i += 2;
            goto L1;
        }
        
        s = 0;
        for (i = 0; i < 372; i++) {
            if (mon[i]) s++;
        }
        e = s/12;
        cout << e << endl;
    }
    return 0;
}