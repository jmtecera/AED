cmake_minimum_required(VERSION 3.29)
project(aed)

set(CMAKE_CXX_STANDARD 17)

set(source_files
        gtp2/src/prog_a_3.cpp
        gtp2/src/prog_a_4.cpp
        gtp2/src/prog_a_5.cpp
)

# Loop through each source file
foreach(source_file IN LISTS source_files)
    get_filename_component(target_name ${source_file} NAME_WE)
    add_executable("${target_name}" "${source_file}")
endforeach()