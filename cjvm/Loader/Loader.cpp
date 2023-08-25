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

void Loader::LoadInTo(void* Dest, u4 Length) {
    Stream.read(static_cast<char *>(Dest), Length);
}

ConstantPool Loader::ParseConstantPool(uint16_t* CPUnits) {
    ConstantPool Pool = ConstantPool();
    u2 continue_index = 0;
    for (int i = 0; i < *CPUnits; ++i) {
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
                CurrentCPEl.Size = 2;
                LoadInTo(CurrentCPEl.Data,2);
                break;
            }
            case CONSTANT_STRING:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(2));
                CurrentCPEl.Size = 2;
                LoadInTo(CurrentCPEl.Data,2);
                break;
            }
            case CONSTANT_FIELDREF:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                CurrentCPEl.Size = 4;
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_METHODREF:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                CurrentCPEl.Size = 4;
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_INTERFACEMETHODREF:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                CurrentCPEl.Size = 4;
                LoadInTo(CurrentCPEl.Data,4);
            }
            case CONSTANT_NAMEANDTYPE:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                CurrentCPEl.Size = 4;
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_INTEGER:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                CurrentCPEl.Size = 4;
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_FLOAT:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                CurrentCPEl.Size = 4;
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            case CONSTANT_LONG:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(8));
                CurrentCPEl.Size = 8;
                LoadInTo(CurrentCPEl.Data,8);
                break;
            }
            case CONSTANT_DOUBLE:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(8));
                CurrentCPEl.Size = 8;
                LoadInTo(CurrentCPEl.Data,8);
                break;
            }
            case CONSTANT_METHODHANDLE:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(3));
                CurrentCPEl.Size = 3;
                LoadInTo(CurrentCPEl.Data,3);
                break;
            }
            case CONSTANT_METHODTYPE:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(2));
                CurrentCPEl.Size = 2;
                LoadInTo(CurrentCPEl.Data,2);
                break;
            }
            case CONSTANT_INVOKEDYNAMIC:{
                CurrentCPEl.Data = static_cast<uint8_t *>(malloc(4));
                CurrentCPEl.Size = 4;
                LoadInTo(CurrentCPEl.Data,4);
                break;
            }
            default: {
                continue_index++;
                continue;
            }
        }
        Pool.Pool.push_back(CurrentCPEl);
    }
    *CPUnits-=continue_index;
    return Pool;
}

ClassFile * Loader::InitClassFile() {
    auto* File = static_cast<ClassFile *>(malloc(sizeof(ClassFile)));
    auto* RESERVED = static_cast<uint32_t *>(malloc(sizeof(uint32_t)));
    auto* Minor = static_cast<uint16_t *>(malloc(sizeof(uint16_t)));
    auto* Major = static_cast<uint16_t *>(malloc(sizeof(uint16_t)));
    auto* CPSize = static_cast<uint16_t *>(malloc(sizeof(uint16_t)));
    Stream.read(reinterpret_cast<char *>(RESERVED), sizeof(int32_t));
    Stream.read(reinterpret_cast<char *>(Minor), sizeof(short));
    Stream.read(reinterpret_cast<char *>(Major), sizeof(short));
    Stream.read(reinterpret_cast<char *>(CPSize), sizeof(short));
    File->magic = *RESERVED >> 8;
    File->MinorVersion = *Minor >> 8;
    File->MajorVersion = *Major >> 8;
    File->ConstantPoolAmount = *CPSize >> 8;
    ConstantPool Pool = ParseConstantPool(&File->ConstantPoolAmount);
    for (size_t i = 0; i < Pool.Pool.size(); ++i) {
        File->constant_pool[i] = Pool.Pool.at(i);
    }
    File->AccessFlags16 = parse_flags();
    File->CurrentClass = parse_current_class();
    File->SuperClass = parse_super_class();
    File->InterfaceCount = parse_interface_count();
    for (int i = 0; i < File->InterfaceCount; ++i) {
        File->interfaces[i] = parse_interface();
    }
    File->FieldCount = parse_field_count();
    for (int i = 0; i < File->FieldCount; ++i) {
        File->fields[i] = parse_field();
    }
    File->MethodCount = parse_method_count();
    for (int i = 0; i < File->MethodCount; ++i) {
        File->methods[i] = parse_method();
    }
    File->AttributeCount = parse_attribute_count();
    for (int i = 0; i < File->FieldCount; ++i) {
        File->attributes[i] = parse_attribute();
    }
    return File;
}

u2 Loader::parse_interface() {
    u2 interface_index;
    LoadInTo(&interface_index,sizeof(u2));
    interface_index = interface_index >> 8;
    return interface_index;
}

u2 Loader::parse_flags() {
    u2 flags = 0;
    LoadInTo(&flags,sizeof(u2));
    return flags;
}

u2 Loader::parse_super_class() {
    u2 super_class_index = 0;
    LoadInTo(&super_class_index,sizeof(u2));
    return super_class_index;
}

u2 Loader::parse_interface_count() {
    u2 interfaces_count = 0;
    LoadInTo(&interfaces_count,sizeof(u2));
    return interfaces_count;
}

void Loader::parse_interfaces(ClassFile *file) {
    for (int i = 0; i < file->InterfaceCount; ++i) {
        file->interfaces[i] = parse_interface();
    }
}

u2 Loader::parse_field_count() {
    u2 field_count;
    LoadInTo(&field_count,sizeof(u2));
    field_count = field_count >> 8;
    return field_count;
}

field_info Loader::parse_field() {
    field_info info{};
    u2 flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    LoadInTo(&flags,sizeof(u2));
    flags = flags >> 8;
    LoadInTo(&name_index,sizeof(u2));
    name_index = name_index >> 8;
    LoadInTo(&descriptor_index,sizeof(u2));
    descriptor_index = descriptor_index >> 8;
    LoadInTo(&attributes_count,sizeof(u2));
    attributes_count = attributes_count >> 8;
    for (int i = 0; i < attributes_count; ++i) {
        info.attributes[i] = parse_attribute();
    }
    return info;
}

attribute_info Loader::parse_attribute() {
    attribute_info attribute{};
    u2 name_index = 0;
    u4 length = 0;
    u1 info[max_attribute_length] = {};
    LoadInTo(&name_index,sizeof(u2));
    LoadInTo(&length,sizeof(u4));
    LoadInTo(&info,length);
    length = length >> 16;
    for (int i = 0; i < max_attribute_length; ++i) {
        attribute.info[i] = info[i];
    }
    attribute.attribute_name_index = name_index;
    attribute.attribute_length = length;
    return attribute;
}

method_info Loader::parse_method() {
    method_info info{};
    u2 flags = 0;
    u2 name_index = 0;
    u2 descriptor_index = 0;
    u2 attributes_count = 0;
    LoadInTo(&flags,sizeof(u2));
    LoadInTo(&name_index,sizeof(u2));
    LoadInTo(&descriptor_index,sizeof(u2));
    LoadInTo(&attributes_count,sizeof(u2));
    for (int i = 0; i < attributes_count; ++i) {
        info.attributes[i] = parse_attribute();
    }
    info.access_flags16 = flags;
    info.name_index = name_index;
    info.descriptor_index = descriptor_index;
    info.attributes_count = attributes_count;
    return info;
}

u2 Loader::parse_attribute_count() {
    u2 attribute_count = 0;
    LoadInTo(&attribute_count,sizeof(u2));
    return attribute_count;
}

u2 Loader::parse_current_class() {
    u2 current_class_index = 0;
    LoadInTo(&current_class_index,sizeof(u2));
    return current_class_index;
}

u2 Loader::parse_method_count() {
    u2 method_count = 0;
    LoadInTo(&method_count,sizeof(u2));
    return method_count;
}

