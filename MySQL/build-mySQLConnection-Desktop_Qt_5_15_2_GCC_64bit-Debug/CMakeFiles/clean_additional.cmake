# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/mySQLConnection_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/mySQLConnection_autogen.dir/ParseCache.txt"
  "mySQLConnection_autogen"
  )
endif()
