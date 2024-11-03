n = int(input())
l = list()
for _ in range(n):
    l.append(input())
tp = input()

if tp == "rot180":
    l = l[::-1]
    for i in range(n):
        l[i] = l[i][::-1]
else:


print("\n".join(l))
