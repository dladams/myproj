# myproj/Python/CMakeLists.txt

# Install python scripts.
install(
  DIRECTORY .
  DESTINATION python
  FILES_MATCHING PATTERN "*.py"
)
