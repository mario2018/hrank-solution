from collections import Counter

def checkMagazine(magazine, note):
    # note键值对在magazine中是否都存在，存在的列出相异性，不存在的直接列出
    # 所以note-magazine和magazine-note的结果是完全不一样的
    if (Counter(note) - Counter(magazine) == {}):
        print('Yes')
    else:
        print('No')

    '''以下是本人的老古董做法‘’‘
    for i in range(len(note)):
        if note[i] in magazine:
            magazine.remove(note[i])
        else:
            print('No')
            return
    print('Yes')    
    '''


if __name__ == '__main__':
    mn = input().split()
    m = int(mn[0])
    n = int(mn[1])
    magazine = input().rstrip().split()
    note = input().rstrip().split()
    checkMagazine(magazine, note)
