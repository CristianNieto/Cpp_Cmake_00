## Graphics
#
# PkgConfig
# OpenGl
# Vulkan
# GFLW
# GLEW
# Glad
# SFML
# SDL2
# 
#
#
set(CMAKE_MODULE_PATH /usr/local/lib/cmake /usr/local/lib/x86_64-linux-gnu/cmake)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw3)

# ## SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio  REQUIRED)
# set(OpenGL_GL_PREFERENCE GLVND)
set(OpenGL_GL_PREFERENCE LEGACY)

find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
find_package (Vulkan REQUIRED)
find_package (SDL2 REQUIRED)
# find_package (SDL2_image REQUIRED)
# find_package (SDL2_gfx REQUIRED)
find_package (glfw3 REQUIRED)
# find_package (GLM REQUIRED)
find_package (GLEW REQUIRED STATIC)

# ## GLFW
# ## GLFW additions
set(GLFW_BUILD_DOCS ON CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

## SDL2
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS}
					${SDL2IMAGE_INCLUDE_DIRS}
					${SDL2GFX_INCLUDE_DIRS})


# include_directories(${SDL2_INCLUDE_DIR}
#                     ${SDL2_IMAGE_INCLUDE_DIR}
#                     ${SDL2_TTF_INCLUDE_DIR})

## OPENGL_VIDEO_LIBRARIES
set(OPENGL_VIDEO_LIBRARIES 
## GENERAL System Libraries
${OPENGL_LIBRARY} 
${OPENGL_LIBRARIES} 
${OPENGL_gl_LIBRARY}
${OPENGL_glu_LIBRARY}

# GLFW
${GLFW_LIBRARIES}
${GLFW3_LIBRARY} 
${GLEW_LIBRARY}

# SDL2
${SDL2_LIBRARIES}
${SDL2GFX_LIBRARIES}
${SDL2_IMAGE_LIBRARIES}
${SDL2_TTF_LIBRARIES}

## Define Libraries
Vulkan::Vulkan
OpenGL::GL 
GLEW::GLEW 
glfw
SOIL
OpenGL

# SDL2
SDL2
SDL2_image
SDL2_net 
SDL2_mixer
SDL2_ttf
SDL2_gfx
# SDL2_sound

## System Libraries
Xi
GLEW
GLU
m
GL
m
glut
pthread
dl
drm
Xdamage
X11-xcb
xcb-glx
xcb-dri2
glfw3
rt
m
dl
Xrandr
Xinerama
Xxf86vm
Xext
Xcursor
Xrender
Xfixes
X11
pthread
xcb
Xau
Xdmcp
assimp
##
	# ----- SFML ----- #
	${SFML_LIBRARIES} 
	${SFML_DEPENDENCIES}
	sfml-system 
	sfml-window 
	sfml-graphics 
	sfml-network 
	sfml-audio

## TCP
mysqlclient
)
