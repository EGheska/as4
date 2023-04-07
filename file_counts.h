//
// Created by Dima Taras on 06.04.2023.
//

#ifndef UNTITLED33_FILE_COUNTS_H
#define UNTITLED33_FILE_COUNTS_H
#include <string>
#include <cstdlib>
#include "options.h"

struct file_counts {
    std::size_t lines{};
    std::size_t words{};
    std::size_t characters{};
    std::size_t bytes{};
    std::size_t maximum_line_length{};
    std::string file_name{};

    void print(std::ostream& out, options const& opt) const;
};


#endif //UNTITLED33_FILE_COUNTS_H
