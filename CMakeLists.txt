cmake_minimum_required(VERSION 3.10)

# Set the project name
project(OpenGL101)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add GLFW library
set(GLFW_PATH "C:/Other/Tools/glfw-3.4.bin.WIN64")
include_directories(${GLFW_PATH}/include)
link_directories(${GLFW_PATH}/lib-mingw-w64)

# Add GLAD library and source
set(GLAD_PATH "${CMAKE_SOURCE_DIR}/glad")
include_directories(${GLAD_PATH}/include)

# Add GLAD source files
add_library(glad "${GLAD_PATH}/src/glad.c")

# Specify the directory containing your custom header files
include_directories(${CMAKE_SOURCE_DIR}/src)

# Gather all source files in the src/ directory
file(GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

# Add your custom source files
set(SOURCES
    main.c
    ${SRC_FILES}
)

# Add the executable
add_executable(main ${SOURCES})

# Link against GLAD, GLFW, and platform-specific libraries
target_link_libraries(main PRIVATE
    glad
    glfw3
    opengl32
)