set(SUBDIR_NAME exceptions)
file(GLOB exceptions_src CONFIGURE_DEPENDS "*.h" "*.cpp")
add_library(${SUBDIR_NAME} STATIC ${exceptions_src} include/)