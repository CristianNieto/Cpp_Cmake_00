################################################################
## BOOST Default System
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost REQUIRED COMPONENTS)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
#   add_executable(foo foo.cc)
  	message(STATUS "Boost Find it!!!")
	# message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}\n")
	# message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}\n")
	# message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}\n")
	# message(STATUS "Boost_VERSION: ${Boost_VERSION}\n")
	# message("boost inc:${Boost_INCLUDE_DIR}\n")
	# message("boost lib: ${Boost_LIBRARY_DIR} \n")
endif()

# find_package(Boost )
# if(NOT Boost_FOUND)
# 	message(FATAL_ERROR "Could not find boost!!!")
# 	else()
# 	message(STATUS "Boost Find it!!!")
# endif()


################################################################
