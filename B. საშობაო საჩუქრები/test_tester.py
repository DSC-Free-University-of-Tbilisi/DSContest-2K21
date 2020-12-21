def shift(ls):
    return ls[1:] + [ls[0]]

for i in range(36):
    with open(f"./input/input{0 if i < 10 else ''}{i}.txt") as infile:
        num_children = int(infile.readline())
        p = sorted([int(x) for x in infile.readline().split()])

        allocation = p[::2] + list(reversed(p[1::2]))
        diffs = [abs(a - b) for a, b in zip(allocation, shift(allocation))]
        guess = max(diffs)
        with open(f"./output/output{0 if i < 10 else ''}{i}.txt") as outfile:
            answer = int(outfile.readline())
            if (guess != answer):
                print(f"expected {answer}, got {guess}")
                break

