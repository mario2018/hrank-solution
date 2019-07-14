
'''
Complete the function minimumBribes. It must print an integer representing the minimum number of bribes necessary, or "Too chaotic" if the line configuration is not possible.
minimumBribes has the following parameter(s):
q: an array of integers
Input Format
The first line contains an integer t, the number of test cases.

Each of the next t pairs of lines are as follows: 
- The first line contains an integer t, the number of people in the queue 
- The second line has n space-separated integers describing the final state of the queue.
Print an integer denoting the minimum number of bribes needed to get the queue into its final state. Print "Too chaotic" if the state is invalid, i.e. it requires a person to have bribed more than 2 people.
Sample Input:
2
5
2 1 5 3 4
5
2 5 1 3 4
Sample Output:
3
Too chaotic
'''
def minimumBribes(queue):
    lastIndex = len(queue) - 1
    swaps = 0
    swapped = False

    for i, v in enumerate(queue):
        if v-1-i > 2:
            return "Too chaotic" #gap is over 2 means have bribed more than 2 people

    #find out minimum bribes by bubble sorting
    for i in range(lastIndex):
        for j in range(lastIndex-i):
            if queue[j]>queue[j+1]:
                queue[j],queue[j+1] = queue[j+1],queue[j]
                swaps += 1
                swapped = True

        if swapped:
            swapped = False
        else:
            break 
    return swaps

if __name__ == "__main__":
    q_arr = []

    for _ in range(int(input())):
        q_length = int(input())
        q = list(map(int, input().strip().split()))[:q_length]
        q_arr.append(q)

    for item in q_arr:
        print(minimumBribes(item))