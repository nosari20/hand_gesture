cmake_minimum_required(VERSION 2.8)
project( WebCam )

# OpenCV
find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

# Copy image folder
file(COPY ./images DESTINATION .)


# executables
add_executable( cam
    src/cam.cpp
)
target_link_libraries( cam ${OpenCV_LIBS} )

add_executable( img
    src/image.cpp
)
target_link_libraries( img ${OpenCV_LIBS} )

