#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> split_string(string);

void minimumBribes(vector<int> q){
    bool swapped = false;
    int swaps = 0;
    int q_length = q.size();
    for(int i=0; i<q_length; i++){
        if(q[i]-1-i > 2){
            cout<<"Too chaotic"<<endl;
            //We can simply write return statement in a void fun(). 
            //In-fact it is considered a good practice (for readability of code) to write return; statement to indicate end of function.
            return; 
        }
    }
    //bubbling sort
    //very important: q_length-1 rounds but not q_length! q[k+1] returns 0 but not report out of range.
    for(int j=0; j<q_length-1; j++){
        for(int k=0; k<q_length-1-j; k++){
            if(q[k]>q[k+1]){
                int temp = q[k+1];
                q[k+1] = q[k];
                q[k] = temp;
                swaps+=1;
                swapped = true;
            }
        }
        if(swapped){
            swapped = false;
        }else{
            break;
        }
    }
    cout<<swaps<<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    //unique(begin, end) is used to remove the duplicated item, not really remove, just move the duplicated one to the end
    //unique(begin, end, []...) is used to remove the continuous duplicated blank space
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