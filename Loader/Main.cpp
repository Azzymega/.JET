#include <iostream>
#include "Loader.h"
#include "ClassFile.h"

int main() {
    //std::string Path;
    //std::cout << "Class-file location: " << std::endl;
    //std::cin >> Path;
    Loader CurrentClassLoader = Loader("Main.class");
    CurrentClassLoader.OpenStream();
    ClassFile File = CurrentClassLoader.InitClassFile();
    ConstantPool Pool = CurrentClassLoader.ParseConstantPool(File.ConstantPoolAmount);
    File.Pool = Pool;
    return 0;
}
