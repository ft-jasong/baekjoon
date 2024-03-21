#include <iostream>
#include <string>

#define UCPC "UCPC"

using namespace std;

int main(void) {
    string str;
    int ucpc_idx;

    getline(cin, str); 
    ucpc_idx = 0;
    for (string::iterator it = str.begin(); it < str.end(); it++) {
        if (*it == UCPC[ucpc_idx])
            ucpc_idx++;
        if (ucpc_idx == 4)
            break ;
    }
    if (ucpc_idx == 4)
        cout << "I love UCPC\n";
    else
        cout << "I hate UCPC\n";
    return (0);
}
