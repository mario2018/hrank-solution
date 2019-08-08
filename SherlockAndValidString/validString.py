# Enter your code here. Read input from STDIN. Print output to STDOUT
def isValid(s):
    if(len(s)<3):
        return 'YES'
    freq = [0]*26
    for item in s:
        freq[ord(item) - ord('a')] += 1
    i=0 #loop counter
    length = len(freq)  #list length 
    while(i<length):
        if(freq[i]==0):
            freq.remove(freq[i])
            # as an element is removed    
            # so decrease the length by 1    
            length = length -1  
            # run loop again to check element                            
            # at same index, when item removed 
            # next item will shift to the left 
            continue
        i = i+1
            
    maxVal = max(freq)
    minVal = min(freq)
    if(maxVal == minVal):
        return 'YES'
    elif(freq.count(maxVal)==1 and (maxVal - minVal)==1):
        return 'YES'
    elif(freq.count(minVal)==1 and minVal==1 and freq.count(minVal)+freq.count(maxVal)==len(freq)):
        return 'YES'
    return 'NO'

if __name__ == '__main__':
    s = input()
    print(isValid(s))   