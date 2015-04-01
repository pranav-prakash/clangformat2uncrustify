clangformat2uncrustify
======================

Convert a clang format specification to an uncrustify config 

Requires a conversion helper file to be present. A sample one is included.

## Usage

Compile using you preferred C++ compiler and run `./clangformat2uncrustify <clangFormatFilePath>` where `<clangFormatFile>` is replaced by the path to your clang format file. The output will be an uncrustify config file in your current directory with the name `converted.cfg`.
