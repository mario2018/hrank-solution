
def makeAnagram(a, b):
    seq = [0]*26
    count = 0
    for item in a:
        seq[ord(item) - ord('a')] += 1
    for item in b:
        seq[ord(item) - ord('a')] -= 1
    for item in seq:
        count += abs(item)
    return count

if __name__ == '__main__':
    a = input()
    b = input()
    res = makeAnagram(a, b)
    print(res)
    