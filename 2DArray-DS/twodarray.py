#!/bin/python3

'''
Input Format
Each of the 6 lines of inputs arr[i] contains 6 space-separated integers arr[i][j].
Constraints
-9<=arr[i][j]<=9
0<=i,j<=5
Output Format
Print the larget hourglass sum found in arr.
Print the largest (maximum) hourglass sum found in 
Give a 6x6 2D Array, arr:
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
Sample output:
19
'''

import sys
import os

def hourglassSum(arr):
    max_sum = -sys.maxsize-1
    # 6x6 array, all the valid index for i and j is in range of [0, 3]
    for i in range(4):
        for j in range(4):
            hg_sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]
            max_sum = hg_sum if hg_sum>max_sum else max_sum
    return max_sum

if __name__ == '__main__':
    print('please input')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))
    
    result = hourglassSum(arr)

    print(result)
