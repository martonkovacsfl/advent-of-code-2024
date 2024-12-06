#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>
#include <vector>
#include <functional>
#include <numeric>
#include <map>

void part1() {
    std::ifstream inputFile("input.txt");
    std::string example = 
        R"(3   4
        4   3
        2   5
        1   3
        3   9
        3   3)";
    std::stringstream exampleInput;
    exampleInput << example;

    bool useExample = false;

    int first, second;
    std::vector<int> firstList, secondList;
    if (useExample) {
        while (exampleInput >> first >> second) {
            firstList.emplace_back(first);
            secondList.emplace_back(second);
        }
    } else {
        while (inputFile >> first >> second) {
            firstList.emplace_back(first);
            secondList.emplace_back(second);
        }
        inputFile.close();
    }

    std::sort(firstList.begin(), firstList.end());
    std::sort(secondList.begin(), secondList.end());

    std::vector<std::pair<int, int>> zipList;
    zipList.reserve(firstList.size());
    std::transform(
        firstList.begin(), firstList.end(),
        secondList.begin(), std::back_inserter(zipList),
        [](int a, int b)
        { return std::make_pair(a, b); });

    std::cout<< std::accumulate(zipList.cbegin(), zipList.cend(), 0,
        [](int a, std::pair<int, int> b) {
            return a + std::abs(b.second - b.first);
        }) << std::endl;
}

void part2() {
    std::ifstream inputFile("input.txt");
    std::string example = 
        R"(3   4
        4   3
        2   5
        1   3
        3   9
        3   3)";
    std::stringstream exampleInput;
    exampleInput << example;

    bool useExample = false;

    int first, second;
    std::vector<int> firstList, secondList;
    if (useExample) {
        while (exampleInput >> first >> second) {
            firstList.emplace_back(first);
            secondList.emplace_back(second);
        }
    } else {
        while (inputFile >> first >> second) {
            firstList.emplace_back(first);
            secondList.emplace_back(second);
        }
        inputFile.close();
    }

    std::map<int, int> secondListAggregated;
    for (auto element : secondList) {
        if (!secondListAggregated.contains(element)) {
            secondListAggregated[element] = element;
        } else {
            secondListAggregated[element] += element;
        }
    }

    int sum{0};
    for (auto element : firstList) {
        if (secondListAggregated.contains(element)) {
            sum += secondListAggregated[element];
        }
    }

    std::cout << sum << std::endl;
}

int main() {
    std::cout << "Day-01" << std::endl;
    std::cout << "Part 1: ";
    part1();
    std::cout << "Part 2: ";
    part2();

    return 0;
}