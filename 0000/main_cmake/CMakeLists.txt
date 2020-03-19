
# Threads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

### Main proyect ###
add_executable(
	${PROJECT_NAME} 
	main.cpp
	)
# add_executable(
# 	${PROJECT_NAME}_fr
# 	main.cpp
# 	)
### Main proyect ###

# target_compile_definitions(file_name PRIVATE #DEFINE)
# target_compile_definitions(main.cpp PRIVATE FRENCH)

### Add LINKS
target_link_libraries(
						${PROJECT_NAME} PRIVATE
						## Options
						project_options
						project_warnings
						## Conan
						CONAN_PKG::docopt.cpp
						CONAN_PKG::fmt
						CONAN_PKG::spdlog
						CONAN_PKG::imgui-sfml
						## FEATURES: Threads
						Threads::Threads
						## MY LIBRARIES
 						son_library
					)

### Add LINKS