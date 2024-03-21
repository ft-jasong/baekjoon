#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define UCPC "UCPC"

using namespace std;

vector<string> split_words(string& str) {
    stringstream ss(str);
    string buffer;
    vector<string> words;

    while (getline(ss, buffer, ' ')) {
        words.push_back(buffer);
    }
    return (words);
}

int main(void) {
    string str;
    vector<string> words;
    int UCPC_idx;

    getline(cin, str);
    words = split_words(str);
    UCPC_idx = 0;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].find(UCPC[UCPC_idx]) != string::npos)
            UCPC_idx++;
        if (UCPC_idx >= 4)
            break ;
    }
    if (UCPC_idx >= 4)
        cout << "I love UCPC\n";
    else
        cout << "I hate UCPC\n";
    return (0);
}
