# myproj/Utility/test/CMakeLists.txt

# Test for utiltity.
add_executable(test_MyXform test_MyXform.cxx)
target_link_libraries(test_MyXform ${PKGLIB})
install(TARGETS test_MyXform DESTINATION test)

# Test for dictionary.
install(FILES test_MyXform.C DESTINATION test)
