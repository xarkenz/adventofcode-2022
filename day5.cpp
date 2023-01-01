//
// Created by xarkenz on 12/05/22.
//

#include "adventofcode.h"

void day5p1() {
    std::ifstream input("day5.txt");
    if (!input.is_open()) {
        std::cerr << "Unable to open file\n";
        return;
    }
    std::string line;
    std::vector<std::string> stacks;
    while (input.good()) {
        std::getline(input, line);
        if (line.empty()) {
            break;
        }
        for (int i = 0; i * 4 + 1 < line.length(); ++i) {
            char box = line[i * 4 + 1];
            if ('A' <= box && box <= 'Z') {
                while (i >= stacks.size()) {
                    stacks.emplace_back();
                }
                stacks[i].insert(0, 1, box);
            }
        }
    }
    while (input.good()) {
        std::getline(input, line);
        if (line.empty()) {
            continue;
        }
        size_t endIndex;
        line.erase(0, 5);
        int amount = std::stoi(line, &endIndex);
        line.erase(0, endIndex + 6);
        int from = std::stoi(line, &endIndex) - 1;
        line.erase(0, endIndex + 4);
        int to = std::stoi(line) - 1;
        stacks[to] += stacks[from].substr(stacks[from].length() - amount);
        stacks[from].erase(stacks[from].length() - amount);
    }
    input.close();
    std::string topLetters;
    for (std::string stack : stacks) {
        topLetters += stack.back();
    }
    std::cout << "Top letters (P1): " << topLetters << std::endl;
}

void day5p2() {
    std::ifstream input("day5.txt");
    if (!input.is_open()) {
        std::cerr << "Unable to open file\n";
        return;
    }
    std::string line;
    std::vector<std::string> stacks;
    while (input.good()) {
        std::getline(input, line);
        if (line.empty()) {
            break;
        }
        for (int i = 0; i * 4 + 1 < line.length(); ++i) {
            char box = line[i * 4 + 1];
            if ('A' <= box && box <= 'Z') {
                while (i >= stacks.size()) {
                    stacks.emplace_back();
                }
                stacks[i].insert(0, 1, box);
            }
        }
    }
    while (input.good()) {
        std::getline(input, line);
        if (line.empty()) {
            continue;
        }
        size_t endIndex;
        line.erase(0, 5);
        int amount = std::stoi(line, &endIndex);
        line.erase(0, endIndex + 6);
        int from = std::stoi(line, &endIndex) - 1;
        line.erase(0, endIndex + 4);
        int to = std::stoi(line) - 1;
        for (int i = 0; i < amount; ++i) {
          stacks[to].push_back(stacks[from].back());
          stacks[from].pop_back();
        }
    }
    input.close();
    std::string topLetters;
    for (std::string stack : stacks) {
        topLetters += stack.back();
    }
    std::cout << "Top letters (P2): " << topLetters << std::endl;
}

void day5() {
    day5p1();
    day5p2();
}