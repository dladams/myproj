# myproj/Exec/CMakeLists.txt

# Build an executable.
add_executable(myhello myhello.cxx)
install(TARGETS myhello DESTINATION bin)
