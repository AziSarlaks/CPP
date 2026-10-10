add_library(hypotenuse_library
    hypotenuse.cpp
    modified_hypotenuse.cpp
)

target_include_directories(hypotenuse_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
