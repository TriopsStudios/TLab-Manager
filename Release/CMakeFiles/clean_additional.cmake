# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\TLabManager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TLabManager_autogen.dir\\ParseCache.txt"
  "TLabManager_autogen"
  )
endif()
