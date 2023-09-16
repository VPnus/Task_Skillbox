# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Module_34_1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Module_34_1_autogen.dir\\ParseCache.txt"
  "Module_34_1_autogen"
  )
endif()
