# set(CPPUTEST_PATH "${PROJECT_ROOT_DIR}/lib/CppUTest")

# set_target_properties(
#     CppUTest PROPERTIES
#         IMPORTED_LOCATION "${CPPUTEST_PATH}/cpputest_build/lib/libCppUTest.a"
#         INTERFACE_INCLUDE_DIRECTORIES "${CPPUTEST_PATH}/include"
# )

# set_target_properties(
#     CppUTestExt PROPERTIES
#         IMPORTED_LOCATION "${CPPUTEST_PATH}/cpputest_build/lib/libCppUTestExt.a"
#         INTERFACE_INCLUDE_DIRECTORIES "${CPPUTEST_PATH}/include"
# )

add_subdirectory(TestExample)
add_subdirectory(TestCommandLineParser)
