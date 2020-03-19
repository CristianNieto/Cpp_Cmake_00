### Using Ccmake
## 
## $ cd /media/cris/Panzer/Cris/Documents/Workspace_Linux/Cpp_Cmake_VSCode/build
## $ ccmake ..
## 
## Push [enter] to change val
## Push [c] to config
## Push [g] to make the changes happen and exit
## Push [q] to exit, and not make changes
## 
## Setup
## 	Cppcheck ON
## 	Clang-tidy OFF
## 	Cppcheck ON
## 	Enable_Sanitizer_Address ON (On sanitizer, just can be enabled one kind)
## 
###

## Main CMAKE file
## CMAKE version minimun required 3.8.
cmake_minimum_required(VERSION 3.13.4)

## Name System proyect ##
project(01_start_Cmake VERSION 1.0.0 LANGUAGES C CXX)
include(cmake/Standard_Project_Settings.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/Compiler_Warnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# allow for static analysis options
include(cmake/Static_Analyzers.cmake)

# Enable Boost
include(cmake/Boost.cmake)

# Enable Graphics
include(cmake/Graphics.cmake)

# Very basic PCH example 
option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if (ENABLE_PCH)
  # This sets a global PCH parameter, each project will build its own PCH, which
  # is a good idea if any #define's change
  # 
  # CMAKE 3.16
  #
  message ( STATUS " -- Espera la version 3.16 de Cmake")
#   target_precompile_headers(project_options INTERFACE <vector> <string> <map> <utility>)
endif()


# Set up some extra Conan dependencies based on our needs
# before loading Conan
set(CONAN_EXTRA_REQUIRES "")
set(CONAN_EXTRA_OPTIONS "")

# if(CPP_STARTER_USE_IMGUI)
  set(CONAN_EXTRA_REQUIRES ${CONAN_EXTRA_REQUIRES}
                           imgui-sfml/2.1@bincrafters/stable)

  # set(CONAN_EXTRA_OPTIONS ${CONAN_EXTRA_OPTIONS} sfml:shared=False
  # sfml:graphics=True sfml:audio=False sfml:window=True
  # libalsa:disable_python=True)
# endif()

if(CPP_STARTER_USE_SDL)
  set(CONAN_EXTRA_REQUIRES ${CONAN_EXTRA_REQUIRES}
                           sdl2/2.0.10@bincrafters/stable)
  # set(CONAN_EXTRA_OPTIONS ${CONAN_EXTRA_OPTIONS} sdl2:wayland=True)
endif()

include(cmake/Conan.cmake)
run_conan()

### List Programs ###
## 0000 program ##
add_subdirectory(0000)
# add_subdirectory(0000_game)
# add_subdirectory(0000_tutorial_00)
# add_subdirectory(0000_tutorial_01)
# add_subdirectory(0000_tutorial_02)
# add_subdirectory(0000_tutorial_03) ## Textures
# add_subdirectory(0000_tutorial_04) ## Textures
# add_subdirectory(0001)
# add_subdirectory(0002)		# SFML
# add_subdirectory(0002_SDL2)	# SDL2
# add_subdirectory(0002_SFML)	# SFML
# add_subdirectory(0003)			# GLFW3
# add_subdirectory(0003_Cherno)			# GLFW3

### List Programs ###

## Which C++ version.
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#add_definitions(-std=c++11)
# add_definitions(-std=c++17 )
add_definitions(-std=c++17 -DANALYSIS=ON)

## Debug flags.
set(CMAKE_BUILD_TYPE Debug)

## String values on Debug.
## Adding Sanitize
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -fno-omit-frame-pointer -fsanitize=address")
# set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -fno-omit-frame-pointer -fsanitize=address")
# set(CMAKE_BUILD_TYPE RelWithDebInfo)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

## Output in the same directory
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wdeprecated-declarations")
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++17 ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++2x ${CMAKE_CXX_FLAGS}")

message ( STATUS " -- MY -- CMake C++ FLAGS ${CMAKE_CXX_FLAGS} \n")

################################################################

## Set the current directory the run time folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

target_link_libraries (${PROJECT_NAME} PUBLIC 
						${OPENGL_VIDEO_LIBRARIES} 
						${Boost_LIBRARIES}
						)

####################################################

message ( STATUS " -- MY -- CMake C++ FLAGS ${CMAKE_CXX_FLAGS} \n")

####################################################
## Features
### Lambdas
target_compile_features(${PROJECT_NAME} PRIVATE
		# LAMBDA FEATURES
		cxx_lambda_init_captures
		# C++17 ENABLED
        cxx_std_17
        )

####################################################
# Enable Testing
if(ENABLE_TESTING)
  enable_testing()
  message(
    "Building Tests. Be sure to check out test/constexpr_tests for constexpr testing"
  )
  add_subdirectory(test)
endif()

if(ENABLE_FUZZING)
  message(
    "Building Fuzz Tests, using fuzzing sanitizer https://www.llvm.org/docs/LibFuzzer.html"
  )
  add_subdirectory(fuzz_test)
endif()

####################################################
## Install
# install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin) # $(CMAKE_INSTALL_PREFIX) / bin
# install(FILES "src/main.cpp" DESTINATION src) # $(CMAKE_INSTALL_PREFIX) / bin
# target_link_libraries(${PROJECT_NAME} PRIVATE son_library)

####################################################
####################################################
## OK
# target_link_libraries (${PROJECT_NAME} PUBLIC  OpenGL::GL GLEW::GLEW ${OPENGL_LIBRARIES} ${GLFW3_LIBRARY}
#         ${GLEW_LIBRARY} Xi GLEW GLU m GL m pthread dl drm Xdamage X11-xcb xcb-glx xcb-dri2 glfw3 rt m dl Xrandr Xinerama Xxf86vm Xext Xcursor Xrender Xfixes X11 pthread xcb Xau Xdmcp )
## OK

# # glfw-3.3
# # Needs to download from the official web site
# # set it in the ROOT_PROJECT folder 
# # Ej: 0000,0001,build,glfw-3.3,CMakeLists.txt(main),glad.c
# # add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3)
# # add_library(GLFW ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3)
# # add_subdirectory(glfw-3.3)

	
# # set(GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/glad_gl.h"
# # 		"${GLFW_SOURCE_DIR}/deps/glad_gl.c")
# # set(GETOPT "${GLFW_SOURCE_DIR}/deps/getopt.h"
# # 		"${GLFW_SOURCE_DIR}/deps/getopt.c")
# # set(LINMATH "${GLFW_SOURCE_DIR}/deps/linmath.h")
# # set(TINYCTHREAD "${GLFW_SOURCE_DIR}/deps/tinycthread.h"
# # 		"${GLFW_SOURCE_DIR}/deps/tinycthread.c")
		
# ## Glad
# # local_glad_4_6
# ## Download glad https://glad.dav1d.de/
# # API:		gl: Version 4.6
# # Profile:	Core
# # All default
# # Options: 
# #		#	Generate a loader	True
# #		#	Omit KHR			False
# #		#	Local Files			True
# # Move the folder into the root cmake folder.
# set(LOCAL_GLAD_DIR "local_glad_4_6")
# set(GLAD "${LOCAL_GLAD_DIR}/glad.h"
# 		"${LOCAL_GLAD_DIR}/glad.c"
# 		"${LOCAL_GLAD_DIR}/khrplatform.h")
# add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/local_glad_4_6/glad.c)
# add_library(GLAD ${CMAKE_CURRENT_SOURCE_DIR}/local_glad_4_6/glad.c)

# ## GLEW
# add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/glew-2.1.0/build/cmake )
# add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3 )
# # include_directories(glfw-3.3)
# # include_directories(glfw-3.3/deps)
# include_directories(glfw-3.3/include)
		
# #message ( STATUS " --------- GLAD_GL ${GLAD_GL} \n")
# #message ( STATUS " --------- GETOPT ${GETOPT} \n")
# #message ( STATUS " --------- LINMATH ${LINMATH} \n")
# #message ( STATUS " --------- TINYCTHREAD ${TINYCTHREAD} \n")
# #message ( STATUS " --------- LOCAL_GLAD_DIR ${LOCAL_GLAD_DIR} \n")
# message ( STATUS " --------- GLAD ${GLAD} \n")


# message ( STATUS " --------- GLAD ${PROJECT_SOURCE_DIR}/local_glad_4_6 \n")
# message ( STATUS " --------- CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} \n")
# message ( STATUS " --------- --------- --------- --------- --------- \n")
# message ( STATUS " --------- GLAD_GL ${GLAD_GL} \n")
# message ( STATUS " --------- GETOPT ${GETOPT} \n")
# message ( STATUS " --------- LINMATH ${LINMATH} \n")
# message ( STATUS " --------- TINYCTHREAD ${TINYCTHREAD} \n")
# message ( STATUS " --------- LOCAL_GLAD_DIR ${LOCAL_GLAD_DIR} \n")
# message ( STATUS " --------- GLAD ${GLAD} \n")
# message ( STATUS " --------- GLAD_SINGLE ${GLAD_SINGLE} \n")
# message ( STATUS " --------- --------- --------- --------- --------- \n")
# message ( STATUS " --------- OPENGL_FOUND ${OPENGL_FOUND} \n")
# message ( STATUS " --------- OPENGL_XMESA_FOUND ${OPENGL_XMESA_FOUND} \n")
# message ( STATUS " --------- OPENGL_GLU_FOUND ${OPENGL_GLU_FOUND} \n")
# message ( STATUS " --------- OPENGL_INCLUDE_DIR ${OPENGL_INCLUDE_DIR} \n")
# message ( STATUS " --------- OPENGL_LIBRARIES ${OPENGL_LIBRARIES} \n")
# message ( STATUS " --------- OPENGL_gl_LIBRARY ${OPENGL_gl_LIBRARY} \n")
# message ( STATUS " --------- OPENGL_glu_LIBRARY ${OPENGL_glu_LIBRARY} \n")
# message ( STATUS " --------- --------- --------- --------- --------- \n")
# message ( STATUS " --------- GLEW_VERSION ${GLEW_VERSION} \n")
# message ( STATUS " --------- GLEW_FOUND ${GLEW_FOUND} \n")
# message ( STATUS " --------- GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIRS} \n")
# message ( STATUS " --------- GLEW_LIBRARIES ${GLEW_LIBRARIES} \n")
# message ( STATUS " --------- --------- --------- --------- --------- \n")
# message ( STATUS " --------- GLFW_SOURCE_DIR ${GLFW_SOURCE_DIR} \n")
# message ( STATUS " --------- GLFW3_LIBRARY ${GLFW3_LIBRARY} \n")
# message ( STATUS " --------- GLFW_INCLUDE_VULKAN ${GLFW_INCLUDE_VULKAN} \n")
# message ( STATUS " --------- GLFW_INCLUDE_GLEXT ${GLFW_INCLUDE_GLEXT} \n")
# message ( STATUS " --------- GLFW_INCLUDE_GLU ${GLFW_INCLUDE_GLU} \n")