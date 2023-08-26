#include <iostream>
#include "../io/Loader.h"
#include "../jvm_types/ClassFile.h"
#include "../class_analyzer/class_parser.h"

int main() {
    //std::string Path;
    //std::cout << "Class-file location: " << std::endl;
    //std::cin >> Path;
    Loader CurrentClassLoader = Loader("Main.class");
    CurrentClassLoader.OpenStream();
    class_parser parser;
    ClassFile* file = parser.parse_file(&CurrentClassLoader);
    return 0;
}
