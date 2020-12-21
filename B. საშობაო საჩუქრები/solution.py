def shift(ls):
    return ls[1:] + [ls[0]]

num_children = int(input())
p = sorted([int(x) for x in input().split()])

allocation = p[::2] + list(reversed(p[1::2]))
diffs = [abs(a - b) for a, b in zip(allocation, shift(allocation))]
print(max(diffs))