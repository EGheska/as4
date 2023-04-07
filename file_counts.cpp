//
// Created by Dima Taras on 06.04.2023.
//

#include "file_counts.h"

void file_counts::print(std::ostream &out, const options &opt) const {
    if (opt.lines()){
        out << "Lines: " << lines << "\n";
    }
    if (opt.words()){
        out << "Words: " << words << "\n";
    }
    if (opt.bytes()){
        out << "Bytes: " << bytes << "\n";
    }
    if (opt.characters()) {
        out << "Characters: " << characters << "\n";
    }
    if (opt.help()) {
        out << "HELP ME PLS" << "\n";
    }
    if (opt.longest_line()) {
        out << "Longest line: " << maximum_line_length;
    }
}
