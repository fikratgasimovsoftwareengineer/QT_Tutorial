# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/web_engine_pro_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/web_engine_pro_autogen.dir/ParseCache.txt"
  "web_engine_pro_autogen"
  )
endif()
