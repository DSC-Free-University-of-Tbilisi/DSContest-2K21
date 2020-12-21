import random

def shift(ls):
    return ls[1:] + [ls[0]]

def solve(n, p):
    p = sorted(p)

    allocation = p[::2] + list(reversed(p[1::2]))
    diffs = [abs(a - b) for a, b in zip(allocation, shift(allocation))]
    return max(diffs)


def gen_tests(n_start, n_end, p_start, p_end, t_start, t_end):
    for i in range(t_start, t_end):
        with open(f"./input/input{0 if i < 10 else ''}{i}.txt", "w+") as infile:
            n = random.randint(n_start, n_end)
            a = random.choices(range(p_start, p_end), k=n)
            infile.write(str(n) + "\n")
            infile.write(" ".join([str(x) for x in a]))
        with open(f"./output/output{0 if i < 10 else ''}{i}.txt", "w+") as outfile:
            outfile.write(str(solve(n, a)))

def gen_small_tests(t_start, t_end):
    gen_tests(5, 10, 1, 100, t_start, t_end)

def gen_medium_tests(t_start, t_end):
    gen_tests(10, 100, 1000, 100_000, t_start, t_end)

def gen_medium_duplicate_tests(t_start, t_end):
    gen_tests(10, 100, 20, 30, t_start, t_end)

def gen_large_tests(t_start, t_end):
    gen_tests(10_000, 50_000, 1_000_000, 100_000_000, t_start, t_end)

def gen_large_duplicate_tests(t_start, t_end):
    gen_tests(50_000, 100_000, 99_999_900, 100_000_000, t_start, t_end)

def gen_xlarge_tests(t_start, t_end):
    gen_tests(99_000, 100_000, 999_000_000, 1_000_000_000, t_start, t_end)

gen_small_tests(0, 10)
gen_medium_tests(10, 15)
gen_medium_duplicate_tests(15, 20)
gen_large_tests(20, 25)
gen_large_duplicate_tests(25,30)
gen_xlarge_tests(30, 36)
