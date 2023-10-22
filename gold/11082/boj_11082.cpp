#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void parseInteger(string& input, string& integer, string& rest) {
    int pointPos;

    pointPos = input.find('.');
    if (pointPos < 0) {
        integer = input;
        return ;
    }
    integer = input.substr(0, pointPos);
    rest = input.substr(pointPos + 1, 10);
}

void parseRepeat(string& rest, string& repeat, string& notRepeat) {
    int repeatStartPos;

    repeatStartPos = rest.find('(');
    notRepeat = rest.substr(0, repeatStartPos);
    if (repeatStartPos != string::npos)
        repeat = rest.substr(repeatStartPos + 1, rest.length() - repeatStartPos - 2);
    else
        repeat = "";
}

long long getGCD(long long a, long long b) {
    long long r;

    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return (a);
}

int main(void) {
    string inStr;
    string integer;
    string rest;
    string notRepeat;
    string repeat;
    long long up;
    long long down;
    long long gcd;

    cin >> inStr;
    parseInteger(inStr, integer, rest);
    parseRepeat(rest, repeat, notRepeat);
    if (repeat.empty())
        down = pow(10, notRepeat.length());
    else
        down = pow(10, notRepeat.length() + repeat.length()) - pow(10, notRepeat.length());
    if (down < 1)
        down = 1;
    if (repeat.empty())
        up = stol(integer + notRepeat);
    else
        up = stol(integer + notRepeat + repeat) - stol(integer + notRepeat);
    gcd = getGCD(up, down);
    cout << up / gcd << '/' << down / gcd << '\n';
    return (0);
}
