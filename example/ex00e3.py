print("YES" if [i for i in range(1, int(input()) + 1)] == sorted([int(x) for x in input().split()]) else "NO")
