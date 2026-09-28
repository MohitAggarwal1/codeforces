#include <iostream>
 
using namespace std;
 
int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    int solved_count = 0;
 
    while (n--) {
        int petya, vasya, tonya;
        cin >> petya >> vasya >> tonya;
 
        // If at least two friends are sure, the sum will be >= 2
        if (petya + vasya + tonya >= 2) {
            solved_count++;
        }
    }
 
    cout << solved_count << "
";
 
    return 0;
}
 