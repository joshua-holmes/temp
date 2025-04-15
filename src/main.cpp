// For if you prefer C++

#include <iostream>
#include <ostream>
#include <string>
#include <unordered_set>

std::string longestSubFromVideo(const std::string* const input) {
    std::unordered_set<char> set;
    std::string longestOverall = "";
    std::string longestTillNow = "";

    for (int i = 0; i < input->length(); i++) {
        char c = (*input)[i];

        // clearing the str and set will erase possibly valid parts of the substring
        if (set.contains(c)) {
            longestTillNow = "";
            set.clear();
        }

        longestTillNow += c;
        set.insert(c);
        if (longestTillNow.length() > longestOverall.length()) {
            longestOverall = longestTillNow;
        }
    }

    return longestOverall;
}

std::string longestSubCorrected(const std::string* const input) {
    std::unordered_set<char> set;
    std::string longestOverall = "";
    std::string longestTillNow = "";

    for (int i = 0; i < input->length(); i++) {
        char c = (*input)[i];

        // instead, we repeatedly remove first char of str from str and set until set does not contain the char
        while (set.contains(c)) {
            set.erase(longestTillNow[0]);
            longestTillNow = longestTillNow.substr(1);
        }

        longestTillNow += c;
        set.insert(c);
        if (longestTillNow.length() > longestOverall.length()) {
            longestOverall = longestTillNow;
        }
    }

    return longestOverall;
}

int main() {
    const std::string input = "ABCAD";
    std::cout << "-------------------------" << std::endl;
    std::cout << "input            -> " << input << std::endl;
    std::cout << "expected output  -> BCAD\n" << std::endl;

    std::string outputFromVideo = longestSubFromVideo(&input);
    std::cout << "output from vid  -> " << outputFromVideo << std::endl;

    std::string outputCorrected = longestSubCorrected(&input);
    std::cout << "output corrected -> " << outputCorrected << std::endl;
    std::cout << "-------------------------" << std::endl;
}
