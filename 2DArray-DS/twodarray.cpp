#include <iostream>
#include <vector>

using namespace std;

int hourglassSum(vector<vector<int> > arr){
    int rows = arr.size();
    int columns = arr[0].size();
    int maxSum = INT_MIN;
    int hgSum = 0;
    for(int i = 0; i < rows - 2; i++){
        for(int j = 0; j < columns - 2; j++){
            hgSum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            maxSum = hgSum > maxSum ? hgSum : maxSum;
        }
    }
    return maxSum;
}

int main(){
    //a space is required between consecutive right angle brackets ??
    vector<vector<int> > arr(6);

    for(int i = 0; i < 6; i++){
        arr[i].resize(6);
        for(int j = 0; j < 6; j++){
            cin >> arr[i][j];
        }
    }

    int result = hourglassSum(arr);
    cout << result <<endl;
    
    return 0;
}