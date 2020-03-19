###### Libraries ######
#
### Son Librarie 
add_library(
	son_library 
	src/0001/Son.h
	src/0001/Son.cpp
)
# set_target_properties(son_library PROPERTIES LINKER_LANGUAGE CXX)

### Unique Header file
## Examples Librarie
# add_library(
#         examples_video
#         examples/examples_video.h
# )
# ## Set examples_video.h C++ file
# ## This is only for unique headers.
# set_target_properties(examples_video PROPERTIES LINKER_LANGUAGE CXX)
### Unique Header file

# target_compile_definitions(son_library PUBLIC SON_LIBRARY_VERSION-1) 
# PUBLIC:		MAIN + SON_LIBRARY
# PRIVATE:		SON_LIBRARY
# INTERFACE:	MAIN

# Type of libraries
# SHARED:		dll, so, dylib
# STATIC:		lib, a
# INTERFACE:	Only headers, Doesnt show up in IDE's

target_include_directories(
	son_library PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
	)

###### Libraries ######



# ON BOOST USE
# find_package(Boost REQUIRED
#				COMPONENTS thread system)
# target_link_libraries(mylib
#						Boost::thread)

# AVOID TO USE
# include_directories
# add_definitions
# add_dependences
# add_compile_options