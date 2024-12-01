

def day1_read(filepath):
    lhs, rhs = [], []

    with open(filepath, "r") as file:
        for line in file.readlines():
            rawStrings = line.split("   ")
            if len(rawStrings) == 2:
                lhs.append(int(rawStrings[0]))
                rhs.append(int(rawStrings[1]))
            else: raise Exception(f"Bad line!, {line}")
    
    return lhs, rhs

def day1a(filepath):
    lhs, rhs = day1_read(filepath)

    lhs.sort()
    rhs.sort()
    if len(lhs) != len(rhs):
        raise Exception("Side lengths differ!")

    total = 0
    for i in range(len(lhs)):
        total += abs(lhs[i] - rhs[i])
    
    print(f"Total distance: {total}")


def day1b(filepath):
    lhs, rhs = day1_read(filepath)

    score = 0
    for lx in lhs:
        count = rhs.count(lx)
        score += lx * count
    
    print(f"Similarity score: {score}")


def main():
    day1a("day1.txt")
    day1b("day1.txt")


if __name__ == "__main__":
    main()