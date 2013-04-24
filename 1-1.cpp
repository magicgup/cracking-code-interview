// 11 Implement an algorithm to determine if a string has all unique characters What if you can not use additional data structures?
#include <iostream>
#include <string>
using namespace std;

// first, assume the string has all ascii characters, and the representation value of the characters is in [0, 255]
// store the sign of the character into a 256-len array
int is_unique_chars(const char *str) {
    if (NULL == str) {
        cout << "input str is NULL." << endl;
        exit(1);
    }
    int indicators[256];
    memset(indicators, 0, sizeof(int) * 256);

    bool all_unique = true;
    size_t str_len = strlen(str);
    for (size_t i = 0; i < str_len; ++i) {
        if (indicators[str[i]] != 0) {
            cout << "find non-unique character. " << "pos : " << i;
            cout << " content : " << str[i] << endl;
            all_unique = false;
            break;
        } else {
            indicators[str[i]] = 1;
        }
    }

    if (all_unique)
        return 0;
    else
        return 1;
}

int main() {
    string str;
    cin >> str;
    int r = is_unique_chars(str.c_str());
    if (r == 0)
        cout << "unique" << endl;
    else
        cout << "non-unique" << endl;
    return 0;
}
