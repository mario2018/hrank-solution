#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    vector<int> freq(26);
    // range-based for loop is a C++11 extension(g++ -std=c++11 twoStrings.cpp)
    for(char c : s1) {++freq[c - 'a'];}
    for(char c : s2) {
        int i = c - 'a';
        // value of index i is a positive number, means a matched character is found
        if(freq[i] > 0){
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

    return 0;
}
