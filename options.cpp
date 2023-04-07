//
// Created by Dima Taras on 06.04.2023.
//

#include <regex>
#include "options.h"

options::options(int argc, char **argv) {
    parse(argc, argv);
}

options::options() : argv{}, argc{0} {
    _byte = false;
    _char = false;
    _help = false;
    _lines = false;
    _longline = false;
    _version = false;
    _words = false;
}

bool options::lines() const {
    return _lines;
}

bool options::words() const {
    return _words;
}

bool options::characters() const {
    return _char;
}

bool options::bytes() const {
    return _byte;
}

bool options::longest_line() const {
    return _longline;
}

bool options::help() const {
    return _help;
}

bool options::version() const {
    return _version;
}

const std::vector<std::string> options::file_names() const {
    return std::vector<std::string>();
}

bool options::verbose() const {
    return _verbose;
}

void options::print(std::ostream &out) const {
    out << "Char: "<< _char << "\n"<<"Line: " << _lines << "\n" << "Words: "<<  _words << "\n" <<"Bytes: "<< _byte << "\n" <<"Version: "<<  _version << "\n" << "Help: " << _help << "\n" << "Long line: " << _longline << "\n" << "Verbose: "<< _verbose << "\n" << std::endl;
    for (int i = 0; i <_file_names.size(); i++) {
        out << _file_names[i];
    }
}
void options::parse(int argc, char * argv[]) {
    // Loop over arguments and parse options
    parse_options(argv[0]);
    for (int i = 1; i < argc; ++i) {
        const std::string arg(argv[i]);
        if (arg == "-l" || arg == "--lines") {
            _lines = true;
        } else if (arg == "-w" || arg == "--words") {
            _words = true;
        } else if (arg == "-c" || arg == "--characters") {
            _char = true;
        } else if (arg == "--bytes") {
            _byte = true;
        } else if (arg == "--longest-line") {
            _longline = true;
        } else if (arg == "--help") {
            _help = true;
        } else if (arg == "--version") {
            _version = true;
        } else if (arg == "--verbose") {
            _verbose = true;
        } else {
            // Found a file name
            _file_names.push_back(arg);
        }
    }


//    // Regular expressions for matching options and long options
//    std::regex opt_regex("-([lwc])|-(-lines|-words|-characters)");
//    std::regex long_opt_regex("-(-?)(lines|words|characters|bytes|help|version|longest-line|verbose)");
//
//    // Loop over arguments and parse options
//    for (int i = 1; i < argc; ++i) {
//        const std::string arg(argv[i]);
//        std::smatch match;
//        if (std::regex_match(arg, match, opt_regex)) {
//            // Found a short option (-l, -w, or -c)
//            if (match[1].matched) {
//                parse_options(match[1].str());
//            }
//        } else if (std::regex_match(arg, match, long_opt_regex)) {
//            // Found a long option (--lines, --words, --characters, --bytes, --help, --version, or --longest-line)
//            const std::string option = match[2].str();
//            const bool is_negative = match[1].length() > 0;
//            if (option == "lines") {
//                _lines = !is_negative;
//            } else if (option == "words") {
//                _words = !is_negative;
//            } else if (option == "characters") {
//                _char = !is_negative;
//            } else if (option == "bytes") {
//                _byte = !is_negative;
//            } else if (option == "help") {
//                _help = true;
//            } else if (option == "version") {
//                _version = true;
//            } else if (option == "longest-line") {
//                _longline = true;
//            } else if (option == "verbose"){
//                _verbose = true;
//            }
//        } else {
//            // Found a file name
//            _file_names.push_back(arg);
//        }
//    }
}
void options::parse_options(const std::string& option) {
    if (option == "l") {
        _lines = true;
    } else if (option == "w") {
        _words = true;
    } else if (option == "c") {
        _char = true;
    }
}
