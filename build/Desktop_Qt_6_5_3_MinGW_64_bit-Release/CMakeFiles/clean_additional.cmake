# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\txt2ply_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\txt2ply_autogen.dir\\ParseCache.txt"
  "txt2ply_autogen"
  )
endif()
