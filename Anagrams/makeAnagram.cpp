#include <iostream>
#include <string>
#include <vector>

using namespace std;

int makeAnagram(string a, string b){
    vector<int> freq(26);
    int count = 0;
    //range-based for loop is a C++11 extension
    for(char c : a) {++freq[c - 'a'];}
    for(char c : b) {--freq[c - 'a'];}
    for(int val : freq) {count += abs(val);}
    return count;
}

int main(){
    string a;
    getline(cin, a);
    string b;
    getline(cin, b);

    int count = makeAnagram(a, b);
    cout<<count<<endl;
    return 0;
}