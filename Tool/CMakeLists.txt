# myproj/Tool/CMakeLists.txt

# Build a tool.
add_library(MyTool_tool SHARED MyTool_tool.cc)
target_include_directories(MyTool_tool BEFORE PRIVATE ../Interface)
target_link_libraries(MyTool_tool ${tool_lib_list})
install(TARGETS MyTool_tool DESTINATION lib)

add_subdirectory(test)
