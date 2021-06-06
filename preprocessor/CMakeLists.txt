set(SUBDIR_NAME preprocessor)
# Add all source files in preprocessor directory
file(GLOB preprocessor_src CONFIGURE_DEPENDS ".h" "*.cpp")
# Create preprocessor library
add_library(${SUBDIR_NAME} STATIC ${preprocessor_src})
target_include_directories(${SUBDIR_NAME} PUBLIC include/)