//
// Created by xarkenz on 12/04/22.
//

#include "adventofcode.h"

void day4() {
    std::ifstream input("day4.txt");
    if (!input.is_open()) {
        std::cerr << "Unable to open file\n";
        return;
    }
    std::string num;
    int containedPairs = 0, overlapPairs = 0;
    int elf1Start, elf1End, elf2Start, elf2End;
    while (input.good()) {
        std::getline(input, num, '-');
        elf1Start = std::stoi(num);
        std::getline(input, num, ',');
        elf1End = std::stoi(num);
        std::getline(input, num, '-');
        elf2Start = std::stoi(num);
        std::getline(input, num);
        elf2End = std::stoi(num);
        if ((elf2Start <= elf1Start && elf1End <= elf2End) || (elf1Start <= elf2Start && elf2End <= elf1End)) {
            ++containedPairs;
        }
        if (!(elf1End < elf2Start || elf2End < elf1Start)) {
            ++overlapPairs;
        }
    }
    input.close();
    std::cout << "Contained pairs: " << containedPairs << std::endl;
    std::cout << "Overlapping pairs: " << overlapPairs << std::endl;
}