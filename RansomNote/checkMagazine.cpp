#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> split_string(string);

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    // Define an unordered_map of strings
    unordered_map<string, int> map_word;

    // Iterate keys and values of unordered_map
    for(auto const& word: magazine) {
        map_word[word]++;
    }

    for (auto const& word: note) {
        const auto it = map_word.find(word);
        if (
          it == map_word.end() 
          || (it->second = --it->second) < 0
        ) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;

    //====== Some cases error: Terminated due to timeout!!! Very inefficient way!
    //====== Need to find another solution
    // vector<string>::iterator it;
    // for(int i = 0; i < note.size(); i++){
    //     it = find(magazine.begin(), magazine.end(), note[i]);
    //     if(it == magazine.end()){
    //         cout<<"No"<<endl;
    //         return;
    //     }else{
    //         magazine.erase(it);
    //     }
    // }
    // cout<<"Yes"<<endl;
}

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
