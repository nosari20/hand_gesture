# OpenCV shape recognition

## Requirement
 - CMake
 - OpenCV 

 ## Build

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Install OpenCV on Windows

 1. Download Pre-built Libraries [here](http://sourceforge.net/projects/opencvlibrary/files/opencv-win/)
 2. Extract it to your install directory
 3. Export environment variable
    ```
    $ setx -m OPENCV_DIR C:\path\to\dir\build\x64\vc14
    ```
 4. Add ```FindOpenCV.cmake``` file to CMake in ```C:\CMake_Dir\share\cmake-3.8\Modules```
    ```
    find_path(OpenCV_DIR "OpenCVConfig.cmake" DOC "Root directory of OpenCV")
    
    set(OpenCV_DIR $ENV{OPENCV_DIR})   # ici vous mettez le chemin vers votre build OpenCV
    set(OpenCV_configScript "${OpenCV_DIR}/lib/OpenCVConfig.cmake") # normalement ce script est créé lorsque vous buildez OpenCV
    
    set(OpenCV_INCLUDE_DIR $ENV{OPENCV_DIR}/lib) # le répertoire include
    include_directories(${OpenCV_INCLUDE_DIR})
    
    set(OPENCV_BINARY_DIR ${OPENCV_DIR}/bin) # les binaires OpenCV (.dll sous windows)
    
    include("${OpenCV_configScript}")
    
    set(CVLIB_SUFFIX "${OpenCV_VERSION_MAJOR}${OpenCV_VERSION_MINOR}${OpenCV_VERSION_PATCH}")
    
    find_path(OpenCV_INCLUDE_DIR "cv.h" PATHS "${OpenCV_DIR}" PATH_SUFFIXES "include" "include/opencv" DOC "")
    
    set(OPENCV_LIB_COMPONENTS calib3d contrib core features2d flann gpu highgui imgproc legacy ml objdetect video)
    
    get_filename_component(PARENT_DIR ${OpenCV_INCLUDE_DIR} PATH)
    set(OpenCV_INCLUDE_DIR "${OpenCV_INCLUDE_DIR};${PARENT_DIR}")
        
    ##====================================================
    ## Backward compatibility
    ##----------------------------------------------------
    if(OpenCV_FOUND)
    option(OpenCV_BACKWARD_COMPA "Add some variable to make this script compatible with the other version of FindOpenCV.cmake" false)
    if(OpenCV_BACKWARD_COMPA)
        find_path(OpenCV_INCLUDE_DIRS "cv.h" PATHS "${OpenCV_DIR}" PATH_SUFFIXES "include" "include/opencv" DOC "Include directory")
        find_path(OpenCV_INCLUDE_DIR "cv.h" PATHS "${OpenCV_DIR}" PATH_SUFFIXES "include" "include/opencv" DOC "Include directory")
        set(OpenCV_LIBRARIES "${OpenCV_LIBS}" CACHE STRING "" FORCE)
    endif(OpenCV_BACKWARD_COMPA)
    endif(OpenCV_FOUND)
    ##====================================================

    ```