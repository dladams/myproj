# myproj/Fcl/CMakeLists.txt

# Install fcl files.
install(
  DIRECTORY .
  DESTINATION fcl
  FILES_MATCHING PATTERN "*.fcl"
)
