//
// Created by Danil on 23.08.2023.
//

#include "Loader.h"

#include <utility>
#include <iostream>

Loader::Loader(std::string Path) {
    this->Path = std::move(Path);
}

void Loader::OpenStream() {
    this->Stream.open(Path,std::ios::binary);
    if (Stream.is_open()){
        std::cout << "Stream Opened" << std::endl;
    }
}

void Loader::CloseStream() {
    this->Stream.close();
}

void Loader::LoadInTo(void* Dest, int Length) {
    Stream.read(static_cast<char *>(Dest), Length);
}

ConstantPool Loader::ParseConstantPool(uint16_t CPUnits) {
    ConstantPool Pool = ConstantPool();
    for (int i = 0; i < CPUnits; ++i) {
        CPInfo CurrentCPEl = CPInfo();
        LoadInTo(&CurrentCPEl.Tag,1);
        switch (CurrentCPEl.Tag) {
            case CONSTANT_UTF8:{
                uint16_t Size;
                LoadInTo(&Size,2);
                Size = Size >> 8;
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(Size));
                for (int j = 0; j < Size; ++j) {
                    LoadInTo(&CurrentCPEl.Data[j],1);
                }
                CurrentCPEl.Size = Size;
                break;
            }
            case CONSTANT_CLASS:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(2));
                LoadInTo(CurrentCPEl.Data,2);
                break;
            }
            case CONSTANT_STRING:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(2));
                LoadInTo(CurrentCPEl.Data,2);
                break;
            }
            case CONSTANT_FIELDREF:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_METHODREF:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_INTERFACEMETHODREF:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                LoadInTo(CurrentCPEl.Data,4);
            }
            case CONSTANT_NAMEANDTYPE:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_INTEGER:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_FLOAT:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_LONG:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(8));
                LoadInTo(CurrentCPEl.Data,8);
                break;
            }
            case CONSTANT_DOUBLE:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(8));
                LoadInTo(CurrentCPEl.Data,8);
                break;
            }
            case CONSTANT_METHODHANDLE:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(3));
                LoadInTo(CurrentCPEl.Data,3);
                break;
            }
            case CONSTANT_METHODTYPE:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(2));
                LoadInTo(CurrentCPEl.Data,2);
                break;
            }
            case CONSTANT_INVOKEDYNAMIC:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            default: {
                continue;
            }
        }
        Pool.Pool.push_back(CurrentCPEl);
    }
    return Pool;
}

ClassFile Loader::InitClassFile() {
    ClassFile File;
    auto* RESERVED = static_cast<uint32_t *>(malloc(sizeof(uint32_t)));
    auto* Minor = static_cast<uint16_t *>(malloc(sizeof(uint16_t)));
    auto* Major = static_cast<uint16_t *>(malloc(sizeof(uint16_t)));
    auto* CPSize = static_cast<uint16_t *>(malloc(sizeof(uint16_t)));
    Stream.read(reinterpret_cast<char *>(RESERVED), sizeof(int32_t));
    Stream.read(reinterpret_cast<char *>(Minor), sizeof(short));
    Stream.read(reinterpret_cast<char *>(Major), sizeof(short));
    Stream.read(reinterpret_cast<char *>(CPSize), sizeof(short));
    File.RESERVED = *RESERVED >> 8;
    File.MinorVersion = *Minor >> 8;
    File.MajorVersion = *Major >> 8;
    File.ConstantPoolAmount = *CPSize >> 8;
    return File;
}
