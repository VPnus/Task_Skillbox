# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "O:/QZskillbox_study/Module_30_2/cmake-build-debug/_deps/zlib-src"
  "O:/QZskillbox_study/Module_30_2/cmake-build-debug/_deps/zlib-build"
  "O:/QZskillbox_study/Module_30_2/cmake-build-debug/_deps/zlib-subbuild/zlib-populate-prefix"
  "O:/QZskillbox_study/Module_30_2/cmake-build-debug/_deps/zlib-subbuild/zlib-populate-prefix/tmp"
  "O:/QZskillbox_study/Module_30_2/cmake-build-debug/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
  "O:/QZskillbox_study/Module_30_2/cmake-build-debug/_deps/zlib-subbuild/zlib-populate-prefix/src"
  "O:/QZskillbox_study/Module_30_2/cmake-build-debug/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "O:/QZskillbox_study/Module_30_2/cmake-build-debug/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "O:/QZskillbox_study/Module_30_2/cmake-build-debug/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
