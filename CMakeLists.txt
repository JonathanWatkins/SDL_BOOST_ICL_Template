# - Main CMake script for SDL_BOOST_ICL_Template
#
# - Require lastest generatation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# - Use the intel icl compiler
set(CMAKE_CXX_COMPILER "icl")

# - Add the Boost Libraries
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# we also need to find the system's OpenGL version
find_package(OpenGL REQUIRED)

# - Declare the project
project(SBItemplate CXX)


set(SDL_FOLDER c:/SDL-1.2.15
    CACHE STRING "Path to SDL-1.2.15" FORCE)
find_library(SDL_LIBRARY
    NAMES SDL-1.2.15 SDL
    PATHS ${SDL_FOLDER}
    PATH_SUFFIXES lib/x64 
    NO_DEFAULT_PATH
)

find_library(SDLMAIN_LIBRARY
    NAMES SDLmain
    PATHS ${SDL_FOLDER}
    PATH_SUFFIXES lib/x64
    NO_DEFAULT_PATH
)

# - Tell compiler where to find headers
include_directories(
	include
	${SDL_FOLDER}/include
)

# - Add the SBItemplate executable
add_executable(SBItemplate WIN32 SBItemplate.cpp)

# - Link SBItemplate to the SBItemplate library
target_link_libraries(SBItemplate ${OPENGL_LIBRARIES} ${SDL_LIBRARY}  ${SDLMAIN_LIBRARY})

# - Install SBItemplate to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS SBItemplate DESTINATION bin)

# - Package SBItemplate sources and executable
include(CPack)

##if(WIN32)
#    set(VS_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR})
#    add_custom_command(TARGET meshworks POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        ${SDL_FOLDER}/VisualC/SDL/Release/SDL.dll ${VS_OUTPUT_DIR}/SDL.dll)
#endif()
