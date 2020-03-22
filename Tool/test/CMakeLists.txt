# myproj/Tool/test/CMakeLists.txt

# Test for tool.
add_executable(test_MyTool test_MyTool.cxx)
target_include_directories(test_MyTool BEFORE PRIVATE ../../Interface)
find_library(LIB_dune_ArtSupport "libdune_ArtSupport.so")
target_link_libraries(test_MyTool ${LIB_dune_ArtSupport})
target_link_libraries(test_MyTool ${source_lib_list})
target_link_libraries(test_MyTool ${ROOT_LIBRARIES})
install(TARGETS test_MyTool DESTINATION test)
