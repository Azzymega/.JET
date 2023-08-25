#include <iostream>
#include "Loader.h"
#include "../jvm_types/ClassFile.h"

int main() {
    //std::string Path;
    //std::cout << "Class-file location: " << std::endl;
    //std::cin >> Path;
    Loader CurrentClassLoader = Loader("Main.class");
    CurrentClassLoader.OpenStream();
    ClassFile* File = CurrentClassLoader.InitClassFile();
    return 0;
}
