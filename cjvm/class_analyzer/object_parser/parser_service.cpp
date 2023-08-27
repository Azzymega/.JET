//
// Created by Danil on 26.08.2023.
//

#include "parser_service.h"

ConstantPool parser_service::parse_pool(uint16_t *length, Loader* loader) {
    ConstantPool Pool = ConstantPool();
    u2 continue_index = 0;
    for (int i = 0; i < *length; ++i) {
        CPInfo CurrentCPEl = CPInfo();
        loader->LoadInTo(&CurrentCPEl.Tag,1);
        switch (CurrentCPEl.Tag) {
            case CONSTANT_UTF8:{
                u2 Size;
                loader->LoadInTo(&Size,2);
                Size >>= 8;
                CurrentCPEl.constant_utf8_info.length = Size;
                CurrentCPEl.constant_utf8_info.string = parse_string(Size,loader);
                break;
            }
            case CONSTANT_CLASS:{
                loader->LoadInTo(&CurrentCPEl.constant_class_info.name_index,2);
                CurrentCPEl.constant_class_info.name_index >>= 8;
                break;
            }
            case CONSTANT_STRING:{
                loader->LoadInTo(&CurrentCPEl.constant_string_info.string_index,2);
                CurrentCPEl.constant_string_info.string_index >>= 8;
                break;
            }
            case CONSTANT_FIELDREF:{
                loader->LoadInTo(&CurrentCPEl.constant_field_ref_info.class_index,2);
                loader->LoadInTo(&CurrentCPEl.constant_field_ref_info.name_and_type_index,2);
                CurrentCPEl.constant_field_ref_info.class_index >>= 8;
                CurrentCPEl.constant_field_ref_info.name_and_type_index >>= 8;
                break;
            }
            case CONSTANT_METHODREF:{
                loader->LoadInTo(&CurrentCPEl.constant_method_ref_info.class_index,2);
                loader->LoadInTo(&CurrentCPEl.constant_method_ref_info.name_and_type_index,2);
                CurrentCPEl.constant_method_ref_info.class_index >>= 8;
                CurrentCPEl.constant_method_ref_info.name_and_type_index >>= 8;
                break;
            }
            case CONSTANT_INTERFACEMETHODREF:{
                loader->LoadInTo(&CurrentCPEl.constant_interface_method_ref_info.class_index,2);
                loader->LoadInTo(&CurrentCPEl.constant_interface_method_ref_info.name_and_type_index,2);
                CurrentCPEl.constant_interface_method_ref_info.class_index >>= 8;
                CurrentCPEl.constant_interface_method_ref_info.name_and_type_index >>= 8;
                break;
            }
            case CONSTANT_NAMEANDTYPE:{
                loader->LoadInTo(&CurrentCPEl.constant_name_and_type_info.name_index,2);
                loader->LoadInTo(&CurrentCPEl.constant_name_and_type_info.descriptor_index,2);
                CurrentCPEl.constant_name_and_type_info.name_index >>= 8;
                CurrentCPEl.constant_name_and_type_info.descriptor_index >>= 8;
                break;
            }
            case CONSTANT_INTEGER:{
                loader->LoadInTo(&CurrentCPEl.constant_integer_info.bytes,4);
                CurrentCPEl.constant_integer_info.bytes >>= 8;
                break;
            }
            case CONSTANT_FLOAT:{
                loader->LoadInTo(&CurrentCPEl.constant_float_info.bytes,4);
                CurrentCPEl.constant_float_info.bytes >>= 8;
                break;
            }
            case CONSTANT_LONG:{
                loader->LoadInTo(&CurrentCPEl.constant_long_info.high_bytes,4);
                loader->LoadInTo(&CurrentCPEl.constant_long_info.low_bytes,4);
                CurrentCPEl.constant_long_info.high_bytes >>= 8;
                CurrentCPEl.constant_long_info.low_bytes >>= 8;
                break;
            }
            case CONSTANT_DOUBLE:{
                loader->LoadInTo(&CurrentCPEl.constant_double_info.high_bytes,4);
                loader->LoadInTo(&CurrentCPEl.constant_double_info.low_bytes,4);
                CurrentCPEl.constant_double_info.high_bytes >>= 8;
                CurrentCPEl.constant_double_info.low_bytes >>= 8;
                break;
            }
            case CONSTANT_METHODHANDLE:{
                loader->LoadInTo(&CurrentCPEl.constant_method_handle_info.reference_kind,1);
                loader->LoadInTo(&CurrentCPEl.constant_method_handle_info.reference_index,2);
                CurrentCPEl.constant_method_handle_info.reference_kind >>= 4;
                CurrentCPEl.constant_method_handle_info.reference_index >>= 8;
                break;
            }
            case CONSTANT_METHODTYPE:{
                loader->LoadInTo(&CurrentCPEl.constant_method_type_info.descriptor_index,2);
                CurrentCPEl.constant_method_type_info.descriptor_index >>= 8;
                break;
            }
            case CONSTANT_INVOKEDYNAMIC:{
                loader->LoadInTo(&CurrentCPEl.constant_invoke_dynamic_info.bootstrap_method_attr_index,2);
                loader->LoadInTo(&CurrentCPEl.constant_invoke_dynamic_info.name_and_type_index,2);
                CurrentCPEl.constant_invoke_dynamic_info.bootstrap_method_attr_index >>= 8;
                CurrentCPEl.constant_invoke_dynamic_info.name_and_type_index >>= 8;

                break;
            }
            default: {
                continue_index++;
                continue;
            }
        }
        Pool.Pool.push_back(CurrentCPEl);
    }
    *length = set_pool_amount(*length-continue_index);
    loader->loaded--; // hackfix
    return Pool;
}
ClassFile * parser_service::InitClassFile(Loader* loader) {
    auto* File = static_cast<ClassFile *>(malloc(sizeof(ClassFile)));
    loader->LoadInTo(&File->magic,sizeof(u4));
    loader->LoadInTo(&File->MinorVersion,sizeof(u2));
    loader->LoadInTo(&File->MajorVersion,sizeof(u2));
    loader->LoadInTo(&File->ConstantPoolAmount,sizeof(u2));
    File->magic =  File->magic >> 8;
    File->MinorVersion =  File->MinorVersion >> 8;
    File->MajorVersion =  File->MajorVersion >> 8;
    File->ConstantPoolAmount = File->ConstantPoolAmount >> 8;
    ConstantPool Pool = parse_pool(&File->ConstantPoolAmount,loader);
    for (size_t i = 0; i < Pool.Pool.size(); ++i) {
        File->constant_pool[i] = Pool.Pool.at(i);
    }
    File->AccessFlags16 = parse_flags(loader);
    File->CurrentClass = parse_current_class(loader);
    File->SuperClass = parse_super_class(loader);
    File->InterfaceCount = parse_interface_count(loader);
    for (int i = 0; i < File->InterfaceCount; ++i) {
        File->interfaces[i] = parse_interface(loader);
    }
    File->FieldCount = parse_field_count(loader);
    File->FieldCount >>= 8;
    for (int i = 0; i < File->FieldCount; ++i) {
        File->fields[i] = parse_field(loader,File->constant_pool);
    }
    File->MethodCount = parse_method_count(loader);
    File->MethodCount >>= 8;
    for (int i = 0; i < File->MethodCount; ++i) {
        File->methods[i] = parse_method(loader,File->constant_pool);
    }
    File->AttributeCount = parse_attribute_count(loader);
    File->AttributeCount >>= 8;
    for (int i = 0; i < File->FieldCount; ++i) {
        File->attributes[i] = *parse_attribute(loader,File->constant_pool);
    }
    return File;
}
u2 parser_service::parse_interface(Loader* loader) {
    u2 interface_index;
    loader->LoadInTo(&interface_index,sizeof(u2));
    interface_index = interface_index >> 8;
    return interface_index;
}
u2 parser_service::parse_flags(Loader* loader) {
    u2 flags = 0;
    loader->LoadInTo(&flags,sizeof(u2));
    return flags;
}
u2 parser_service::parse_super_class(Loader* loader) {
    u2 super_class_index = 0;
    loader->LoadInTo(&super_class_index,sizeof(u2));
    return super_class_index;
}
u2 parser_service::parse_interface_count(Loader* loader) {
    u2 interfaces_count = 0;
    loader->LoadInTo(&interfaces_count,sizeof(u2));
    return interfaces_count;
}
void parser_service::parse_interfaces(ClassFile *file,Loader* loader) {
    for (int i = 0; i < file->InterfaceCount; ++i) {
        file->interfaces[i] = parse_interface(loader);
    }
}
u2 parser_service::parse_field_count(Loader* loader) {
    u2 field_count;
    loader->LoadInTo(&field_count,sizeof(u2));
    field_count = field_count >> 8;
    return field_count;
}
field_info parser_service::parse_field(Loader* loader,CPInfo* pool) {
    field_info info{};
    u2 flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    loader->LoadInTo(&flags,sizeof(u2));
    flags = flags >> 8;
    loader->LoadInTo(&name_index,sizeof(u2));
    name_index = name_index >> 8;
    loader->LoadInTo(&descriptor_index,sizeof(u2));
    descriptor_index = descriptor_index >> 8;
    loader->LoadInTo(&attributes_count,sizeof(u2));
    attributes_count = attributes_count >> 8;
    for (int i = 0; i < attributes_count; ++i) {
        info.attributes[i] = *parse_attribute(loader,pool);
    }
    return info;
}
attribute_info * parser_service::parse_attribute(Loader* loader, CPInfo* pool) {
    attribute_info* attribute = static_cast<attribute_info *>(malloc(sizeof(attribute_info)));
    loader->LoadInTo(&attribute->attribute_name_index,sizeof(u2));
    loader->LoadInTo(&attribute->attribute_length,sizeof(u4));
    attribute->attribute_length >>= 24;
    attribute->attribute_name_index >>= 8;
    switch (return_attribute_tag(*pool[attribute->attribute_name_index-1].constant_utf8_info.string)) {
        case constant_value:
            attribute->tag = constant_value;
            // work
            break;
        case code:
            attribute->tag = code;
            loader->LoadInTo(&attribute->code_attribute.max_stack, 2);
            loader->LoadInTo(&attribute->code_attribute.max_locals, 2);
            loader->LoadInTo(&attribute->code_attribute.code_length, 4);
            attribute->code_attribute.code_length >>= 24;
            attribute->code_attribute.max_stack >>= 8;
            attribute->code_attribute.max_locals >>= 8;
            for (size_t i = 0; i < attribute->code_attribute.code_length; ++i) {
                loader->LoadInTo(&attribute->code_attribute.code[i], 1);
            }
            loader->LoadInTo(&attribute->code_attribute.exception_table_length, 2);
            attribute->code_attribute.exception_table_length >>= 8;
            for (size_t i = 0; i < attribute->code_attribute.exception_table_length >> 8; ++i) {
                attribute->code_attribute.exception_table[i] = parse_table(loader);
            }
            loader->LoadInTo(&attribute->code_attribute.attributes_count,2);
            attribute->code_attribute.attributes_count >>= 8;
            for (size_t i = 0; i < attribute->code_attribute.attributes_count; ++i) {
                attribute->code_attribute.attributes[i] = parse_attribute(loader,pool);
            }
            break;
        case stack_map_table:
            attribute->tag = stack_map_table;
            loader->LoadInTo(&attribute->stack_map_table_attribute.number_of_entries, 2);
            for (size_t i = 0; i < attribute->stack_map_table_attribute.number_of_entries >> 8; ++i) {
                attribute->stack_map_table_attribute.entries[i] = parse_frame(loader);
            }
            break;
        case exceptions:
            attribute->tag = exceptions;
            loader->LoadInTo(&attribute->exceptions_attribute.number_of_exceptions, 2);
            for (int i = 0; i < attribute->exceptions_attribute.number_of_exceptions >> 8; ++i) {
                loader->LoadInTo(&attribute->exceptions_attribute.exception_index_table[i], 2);
            }
            break;
        case inner_classes:
            attribute->tag = inner_classes;
            loader->LoadInTo(&attribute->inner_classes_attribute.number_of_classes, 2);
            for (int i = 0; i < attribute->inner_classes_attribute.number_of_classes >> 8; ++i) {
                loader->LoadInTo(&attribute->inner_classes_attribute.classes[i], sizeof(classT));
            }
            break;
        case enclosing_method:
            attribute->tag = enclosing_method;
            loader->LoadInTo(&attribute->enclosing_method_attribute.class_index, 2);
            loader->LoadInTo(&attribute->enclosing_method_attribute.method_index, 2);
            break;
        case synthetic:
            attribute->tag = synthetic;
            break;
        case signature:
            attribute->tag = signature;
            loader->LoadInTo(&attribute->signature_attribute.signature_index, 2);
            break;
        case source_file:
            attribute->tag = signature;
            loader->LoadInTo(&attribute->source_file_attribute.sourcefile_index, 2);
            break;
        case source_debug_extension:
            attribute->tag = source_debug_extension;
            for (int i = 0; i < attribute->attribute_length >> 8; ++i) {
                loader->LoadInTo(&attribute->source_debug_extension_attribute.debug_extension[i], 1);
            }
            break;
        case line_number_table:
            attribute->tag = line_number_table;
            loader->LoadInTo(&attribute->line_number_table_attribute.line_number_table_length, 2);
            attribute->line_number_table_attribute.line_number_table_length >>= 8;
            for (int i = 0; i < attribute->line_number_table_attribute.line_number_table_length >> 8; ++i) {
                loader->LoadInTo(&attribute->line_number_table_attribute.line_number_table[i], sizeof(line_number_table));
                attribute->line_number_table_attribute.line_number_table[i].start_pc >>= 8;
                attribute->line_number_table_attribute.line_number_table[i].line_number >>= 8;
            }
            break;
        case local_variable_table:
            attribute->tag = local_variable_table;
            loader->LoadInTo(&attribute->local_variable_table_attribute.local_variable_table_length, 2);
            for (int i = 0; i < attribute->local_variable_table_attribute.local_variable_table_length >> 8; ++i) {
                loader->LoadInTo(&attribute->local_variable_table_attribute.local_variable_table[i], sizeof(local_variable_table));
            }
            break;
        case local_variable_type_table:
            attribute->tag = local_variable_type_table;
            loader->LoadInTo(&attribute->local_variable_type_table_attribute.local_variable_type_table_length, 2);
            for (int i = 0; i < attribute->local_variable_type_table_attribute.local_variable_type_table_length >> 8; ++i) {
                loader->LoadInTo(&attribute->local_variable_type_table_attribute.local_variable_type_table[i], sizeof(local_variable_type_table));
            }
            break;
        case deprecated:
            attribute->tag = deprecated;
            break;
        case runtime_visible_annotations:
            attribute->tag = runtime_visible_annotations;
            break;
        case runtime_invisible_annotations:
            attribute->tag = runtime_invisible_annotations;
            break;
        case runtime_visible_parameter_annotations:
            attribute->tag = runtime_visible_parameter_annotations;
            break;
        case runtime_invisible_parameter_annotations:
            attribute->tag = runtime_invisible_parameter_annotations;
            break;
        case annotation_default:
            attribute->tag = annotation_default;
            break;
        case bootstrap_method:
            attribute->tag = bootstrap_method;
            break;
    }
    return attribute;
}
method_info parser_service::parse_method(Loader* loader, CPInfo* pool) {
    method_info info{};
    u2 flags = 0;
    u2 name_index = 0;
    u2 descriptor_index = 0;
    u2 attributes_count = 0;
    loader->LoadInTo(&flags,sizeof(u2));
    loader->LoadInTo(&name_index,sizeof(u2));
    loader->LoadInTo(&descriptor_index,sizeof(u2));
    loader->LoadInTo(&attributes_count,sizeof(u2));
    flags >>= 8;
    name_index >>= 8;
    descriptor_index >>= 8;
    attributes_count >>= 8;
    for (int i = 0; i < attributes_count; ++i) {
        info.attributes[i] = *parse_attribute(loader,pool);
    }
    info.access_flags16 = flags;
    info.name_index = name_index;
    info.descriptor_index = descriptor_index;
    info.attributes_count = attributes_count;
    return info;
}
u2 parser_service::parse_attribute_count(Loader* loader) {
    u2 attribute_count = 0;
    loader->LoadInTo(&attribute_count,sizeof(u2));
    return attribute_count;
}
u2 parser_service::parse_current_class(Loader* loader) {
    u2 current_class_index = 0;
    loader->LoadInTo(&current_class_index,sizeof(u2));
    return current_class_index;
}
u2 parser_service::parse_method_count(Loader* loader) {
    u2 method_count = 0;
    loader->LoadInTo(&method_count,sizeof(u2));
    return method_count;
}
uint16_t parser_service::set_pool_amount(uint16_t wanted_size) {
    return wanted_size;
}

std::string* parser_service::parse_string(u2 size, Loader* loader) {
    auto* data = new std::string();
    for (int j = 0; j < size; ++j) {
        char c;
        loader->LoadInTo(&c,1);
        data->push_back(c);
    }
    return data;
}

attributes parser_service::return_attribute_tag(std::string name) {
    if (name == "Code"){
        return code;
    }
    else if (name == "ConstantValue"){
        return constant_value;
    }
    else if (name == "StackMapTable"){
        return stack_map_table;
    }
    else if (name == "Exceptions"){
        return exceptions;
    }
    else if (name == "InnerClasses"){
        return inner_classes;
    }
    else if (name == "EnclosingMethod"){
        return enclosing_method;
    }
    else if (name == "Synthetic"){
        return synthetic;
    }
    else if (name == "Signature"){
        return signature;
    }
    else if (name == "SourceFile"){
        return source_file;
    }
    else if (name == "SourceDebugExtension"){
        return source_debug_extension;
    }
    else if (name == "LineNumberTable"){
        return line_number_table;
    }
    else if (name == "LocalVariableTable"){
        return local_variable_table;
    }
    else if (name == "LocalVariableTypeTable"){
        return local_variable_type_table;
    }
    else if (name == "Deprecated"){
        return deprecated;
    }
    else if (name == "RuntimeVisibleAnnotations"){
        return runtime_visible_annotations;
    }
    else if (name == "RuntimeInvisibleAnnotations"){
        return runtime_invisible_annotations;
    }
    else if (name == "RuntimeVisibleParameterAnnotations"){
        return runtime_visible_parameter_annotations;
    }
    else if (name == "RuntimeInvisibleParameterAnnotations"){
        return runtime_invisible_parameter_annotations;
    }
    else if (name == "AnnotationDefault"){
        return annotation_default;
    }
    else {
        return bootstrap_method;
    }
}
exception_table parser_service::parse_table(Loader *loader) {
    exception_table table{};
    loader->LoadInTo(&table.start_pc,2);
    loader->LoadInTo(&table.end_pc,2);
    loader->LoadInTo(&table.handler_pc,2);
    loader->LoadInTo(&table.catch_type,2);
    return table;
}

stack_map_frame parser_service::parse_frame(Loader *loader) {
    stack_map_frame result{};
    loader->LoadInTo(&result.frame_type,sizeof(u2));
    if (result.frame_type < 64){

    }
    else if (result.frame_type > 63 && result.frame_type < 128){
        loader->LoadInTo(&result.same_locals_1_stack_item_frame.stack[0],sizeof(verification_type_info));
    }
    else if (result.frame_type == 247){
        loader->LoadInTo(&result.same_locals_1_stack_item_frame_extended.offset_delta,2);
        loader->LoadInTo(&result.same_locals_1_stack_item_frame.stack[0],sizeof(verification_type_info));
    }
    else if (result.frame_type > 247 && result.frame_type < 251){
        loader->LoadInTo(&result.chop_frame.offset_delta,2);
    }
    else if (result.frame_type == 251){
        loader->LoadInTo(&result.same_frame_extended.offset_delta,2);
    }
    else if (result.frame_type > 251 && result.frame_type < 255){
        loader->LoadInTo(&result.append_frame.offset_delta,2);
        for (int i = 0; i < result.frame_type-251; ++i) {
            loader->LoadInTo(&result.append_frame.locals[i],sizeof(verification_type_info));
        }
    }
    else {
        loader->LoadInTo(&result.full_frame.offset_delta,sizeof(u2));
        loader->LoadInTo(&result.full_frame.number_of_locals,sizeof(u2));
        for (int i = 0; i < result.full_frame.number_of_locals; ++i) {
            loader->LoadInTo(&result.full_frame.locals[i],sizeof(verification_type_info));
        }
        loader->LoadInTo(&result.full_frame.number_of_stack_items,sizeof(u2));
        for (int i = 0; i < result.full_frame.number_of_stack_items; ++i) {
            loader->LoadInTo(&result.full_frame.stack[i],sizeof(verification_type_info));
        }
    }
    return result;
}

verification_type_info parser_service::parse_vti(Loader *loader) {
    verification_type_info result{};
    u1 tag;
    loader->LoadInTo(&tag,sizeof(u1));
    switch (tag) {
        case ITEM_Top:
            result.tag = ITEM_Top;
            break;
        case ITEM_Integer:
            result.tag = ITEM_Integer;
            break;
        case ITEM_Float:
            result.tag = ITEM_Float;
            break;
        case ITEM_Long:
            result.tag = ITEM_Long;
            break;
        case ITEM_Double:
            result.tag = ITEM_Double;
            break;
        case ITEM_Null:
            result.tag = ITEM_Null;
            break;
        case ITEM_UninitializedThis:
            result.tag = ITEM_Uninitialized;
            break;
        case ITEM_Object:
            result.tag = ITEM_Object;
            loader->LoadInTo(&result.object_variable_info.cpool_index,2);
            break;
        case ITEM_Uninitialized:
            result.tag = ITEM_Uninitialized;
            loader->LoadInTo(&result.uninitialized_variable_info.offset,2);
            break;
    }
    return result;
}
