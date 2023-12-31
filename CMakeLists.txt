cmake_minimum_required(VERSION 3.25)
project(JET)
set(CMAKE_CXX_FLAGS -static-libstdc++)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(JET SHARED cjvm/core/Def.h
        cjvm/jvm_types/primitive_types/IntegerTypes/Byte.c cjvm/jvm_types/primitive_types/IntegerTypes/Byte.h
        cjvm/jvm_types/primitive_types/IntegerTypes/Short.c cjvm/jvm_types/primitive_types/IntegerTypes/Short.h
        cjvm/jvm_types/primitive_types/IntegerTypes/Int.c cjvm/jvm_types/primitive_types/IntegerTypes/Int.h
        cjvm/jvm_types/primitive_types/IntegerTypes/Long.c
        cjvm/jvm_types/primitive_types/IntegerTypes/Long.h cjvm/jvm_types/primitive_types/IntegerTypes/Char.c
        cjvm/jvm_types/primitive_types/IntegerTypes/Char.h cjvm/jvm_types/primitive_types/FloatingTypes/Float.c
        cjvm/jvm_types/primitive_types/FloatingTypes/Float.h cjvm/jvm_types/primitive_types/FloatingTypes/Double.c
        cjvm/jvm_types/primitive_types/FloatingTypes/Double.h cjvm/jvm_types/primitive_types/IntegerTypes/Boolean.c
        cjvm/jvm_types/primitive_types/IntegerTypes/Boolean.h cjvm/jvm_types/primitive_types/IntegerTypes/ReturnAddress.c
        cjvm/jvm_types/primitive_types/IntegerTypes/ReturnAddress.h cjvm/jvm_types/reference_types/ClassType.c
        cjvm/jvm_types/reference_types/ClassType.h
        cjvm/jvm_types/reference_types/ArrayType.c cjvm/jvm_types/reference_types/ArrayType.h
        cjvm/jvm_types/reference_types/InterfaceType.c
        cjvm/jvm_types/reference_types/InterfaceType.h
        cjvm/jvm_global/cgc_jvm/Heap.c cjvm/jvm_global/cgc_jvm/Heap.h cjvm/jvm_global/cgc_jvm/HeapChunk.c
        cjvm/jvm_global/cgc_jvm/HeapChunk.h
        cjvm/jvm_global/PermanentGeneration.c cjvm/jvm_global/PermanentGeneration.h cjvm/jvm_global/ConstantPool.c
        cjvm/jvm_global/ConstantPool.h
        cjvm/jvm_global/CPoolMember.c cjvm/jvm_global/CPoolMember.h cjvm/jvm_global/Field.c cjvm/jvm_global/Field.h
        cjvm/jvm_global/Attribute.c
        cjvm/jvm_global/Attribute.h cjvm/jvm_global/AttributeList.c cjvm/jvm_global/AttributeList.h
        cjvm/jvm_global/Class.c cjvm/jvm_global/Class.h
        cjvm/jvm_global/FieldArray.c cjvm/jvm_global/FieldArray.h
        cjvm/jvm_types/var_info/double_variable_info.h
        cjvm/class_analyzer/class_parser.cpp cjvm/class_analyzer/class_parser.h
        cjvm/class_analyzer/object_parser/parser_service.cpp cjvm/class_analyzer/object_parser/parser_service.h
        cjvm/io/Loader.cpp cjvm/io/Loader.h  cjvm/jvm_types/ClassFile.cpp
        cjvm/jvm_types/ClassFile.h cjvm/jvm_types/ConstantPool.cpp cjvm/jvm_types/ConstantPool.h cjvm/jvm_types/CPInfo.cpp cjvm/jvm_types/CPInfo.h
        cjvm/Loader/Main.cpp cjvm/jvm_types/field_info.c cjvm/jvm_types/field_info.h
        cjvm/jvm_types/method_info.c cjvm/jvm_types/method_info.h
        cjvm/jvm_types/exceptions/exception_table.c cjvm/jvm_types/exceptions/exception_table.h
        cjvm/jvm_types/attributes/stack_map_table_attribute.c cjvm/jvm_types/attributes/stack_map_table_attribute.h cjvm/jvm_types/stack_map_frame.c
        cjvm/jvm_types/stack_map_frame.h cjvm/jvm_types/frames/same_frame.h cjvm/jvm_types/frames/same_locals_1_stack_item_frame.h
        cjvm/jvm_types/var_info/top_variable_info.h cjvm/jvm_types/var_info/integer_variable_info.h
        cjvm/jvm_types/var_info/double_variable_info.h cjvm/jvm_types/var_info/double_variable_info.h
        cjvm/jvm_types/var_info/long_variable_info.h cjvm/jvm_types/var_info/null_variable_info.h
        cjvm/jvm_types/var_info/uninitializedthis_variable_info.h cjvm/jvm_types/var_info/object_variable_info.h
        cjvm/jvm_types/var_info/uninitialized_variable_info.h cjvm/jvm_types/var_info/double_variable_info.h
        cjvm/jvm_types/var_info/float_variable_info.h cjvm/jvm_types/var_info/double_variable_info.h
        cjvm/jvm_types/var_info/double_variable_info.h cjvm/jvm_types/var_info/verification_type_info.h
        cjvm/jvm_types/frames/same_locals_1_stack_item_frame_extended.h cjvm/jvm_types/frames/chop_frame.h
        cjvm/jvm_types/frames/same_frame_extended.h cjvm/jvm_types/frames/append_frame.h
        cjvm/jvm_types/attributes/exceptions_attribute.c
        cjvm/jvm_types/attributes/exceptions_attribute.h cjvm/jvm_types/class.c cjvm/jvm_types/class.h
        cjvm/jvm_types/attributes/inner_classes_attribute.c cjvm/jvm_types/attributes/inner_classes_attribute.h
        cjvm/jvm_types/attributes/enclosing_method_attribute.c cjvm/jvm_types/attributes/enclosing_method_attribute.h
        cjvm/jvm_types/attributes/synthetic_attribute.c cjvm/jvm_types/attributes/synthetic_attribute.h
        cjvm/jvm_types/attributes/signature_attribute.c cjvm/jvm_types/attributes/signature_attribute.h
        cjvm/jvm_types/attributes/source_file_attribute.c cjvm/jvm_types/attributes/source_file_attribute.h
        cjvm/jvm_types/attributes/source_debug_extension_attribute.c
        cjvm/jvm_types/attributes/source_debug_extension_attribute.h cjvm/jvm_types/line_number_table.c
        cjvm/jvm_types/line_number_table.h cjvm/jvm_types/attributes/line_number_table_attribute.c
        cjvm/jvm_types/attributes/line_number_table_attribute.h
        cjvm/jvm_types/attributes/local_variable_table_attribute.c
        cjvm/jvm_types/attributes/local_variable_table_attribute.h cjvm/jvm_types/local_variable_table.c
        cjvm/jvm_types/local_variable_table.h cjvm/jvm_types/local_variable_type_table.c
        cjvm/jvm_types/local_variable_type_table.h cjvm/jvm_types/attributes/local_variable_type_table_attribute.c
        cjvm/jvm_types/attributes/local_variable_type_table_attribute.h
        cjvm/jvm_types/constant_pool_types/constant_class_info.h
        cjvm/jvm_types/constant_pool_types/constant_field_ref_info.h
        cjvm/jvm_types/constant_pool_types/constant_string_info.h
        cjvm/jvm_types/constant_pool_types/constant_integer_info.h
        cjvm/jvm_types/constant_pool_types/constant_float_info.h
        cjvm/jvm_types/constant_pool_types/constant_long_info.h
        cjvm/jvm_types/constant_pool_types/constant_double_info.h
        cjvm/jvm_types/constant_pool_types/constant_name_and_type_info.h
        cjvm/jvm_types/constant_pool_types/constant_utf8_info.h
        cjvm/jvm_types/constant_pool_types/constant_method_handle_info.h
        cjvm/jvm_types/constant_pool_types/constant_method_type_info.h
        cjvm/jvm_types/constant_pool_types/constant_invoke_dynamic_info.h
        cjvm/jvm_types/constant_pool_types/constant_method_ref_info.h
        cjvm/jvm_types/constant_pool_types/constant_interface_method_ref_info.h cjvm/jvm_frames/operand_stack.cpp cjvm/jvm_frames/operand_stack.h cjvm/jvm_frames/frame.cpp cjvm/jvm_frames/frame.h cjvm/jvm_frames/operand_locals.cpp cjvm/jvm_frames/operand_locals.h cjvm/core/frame_stack.cpp cjvm/core/frame_stack.h cjvm/core/native_stack.cpp cjvm/core/native_stack.h cjvm/core/thread.cpp cjvm/core/thread.h cjvm/core/thread_stack.cpp cjvm/core/thread_stack.h cjvm/core/jet.cpp cjvm/core/jet.h cjvm/jvm_types/attributes/code_attribute.cpp cjvm/jvm_types/attributes/code_attribute.h cjvm/jvm_types/attributes/attribute_info.cpp cjvm/jvm_types/attributes/attribute_info.h)
add_executable(ClassLoader cjvm/Loader/Main.cpp cjvm/jvm_frames/local_mut.cpp cjvm/jvm_frames/local_mut.h cjvm/jvm_types/frames/full_frame.cpp cjvm/jvm_types/frames/full_frame.h)
target_link_libraries(ClassLoader PRIVATE JET)

