#include <iostream>
#include "file_counts.h"
#include "counter.h"
#include <stdexcept>
#include <fstream>
#include "options.h"

int main(int argc, char * argv[]){
        options opst{argc, argv};
        opst.print(std::cout);
        file_counts fule;
        counter count("anna_karenina.txt", fule);;
        count.process(opst, fule);
        fule.print(std::cout, opst);


//    try{
//        options opts{argc, argv};
//
//        if (opts.verbose()){
//            // print parsed options
//            opts.print(std::cout);
//        }
//
//        if (opts.help()){
//            // print help
//            return EXIT_SUCCESS;
//        }
//
//        if (opts.version()){
//            // print version
//            return EXIT_SUCCESS;
//        }
//
//        // TODO: do the file processing and counting next
//        return EXIT_SUCCESS;
//    }
//    catch(const std::invalid_argument& exc){
//        std::cout << exc.what() << '\n';
//        std::cout << "Try `wc --help` for more information.\n";
//        return EXIT_FAILURE;
//    }
    return 0;
}