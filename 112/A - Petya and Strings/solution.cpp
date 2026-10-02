#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s1, s2;
    cin >> s1 >> s2;
 
    // Convert both strings to uppercase for case-insensitive comparison
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
 
    // Lexicographical comparison
    if (s1 < s2) {
        cout << "-1
";
    } else if (s1 > s2) {
        cout << "1
";
    } else {
        cout << "0
";
    }
 
    return 0;
}
 