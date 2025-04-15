# For if you prefer Python

def longest_sub_from_video(input: str) -> str:
    hash_set = set()
    longest_overall = ""
    longest_till_now = ""

    for i in range(len(input)):
        c = input[i]

        # clearing the str and set will erase possibly valid parts of the substring
        if c in hash_set:
            longest_till_now = ""
            hash_set.clear()

        longest_till_now += c
        hash_set.add(c)
        if len(longest_till_now) > len(longest_overall):
            longest_overall = longest_till_now

    return longest_overall

def longest_sub_corrected(input: str) -> str:
    hash_set = set()
    longest_overall = ""
    longest_till_now = ""

    for i in range(len(input)):
        c = input[i]

        # instead, we repeatedly remove first char of str from str and set until set does not contain the char
        while c in hash_set:
            hash_set.remove(longest_till_now[0])
            longest_till_now = longest_till_now[1:]

        longest_till_now += c
        hash_set.add(c)
        if len(longest_till_now) > len(longest_overall):
            longest_overall = longest_till_now

    return longest_overall

def main():
    input = "ABCAD"
    print("-------------------------")
    print(f"input            -> {input}")
    print("expected output  -> BCAD\n")

    output_from_video = longest_sub_from_video(input)
    print(f"output from vid  -> {output_from_video}")

    output_corrected = longest_sub_corrected(input)
    print(f"output corrected -> {output_corrected}")
    print("-------------------------")

if __name__ == "__main__":
    main()
