# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "O:/QZskillbox_study/Module_30_3/cmake-build-debug/_deps/curl-src"
  "O:/QZskillbox_study/Module_30_3/cmake-build-debug/_deps/curl-build"
  "O:/QZskillbox_study/Module_30_3/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix"
  "O:/QZskillbox_study/Module_30_3/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/tmp"
  "O:/QZskillbox_study/Module_30_3/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
  "O:/QZskillbox_study/Module_30_3/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src"
  "O:/QZskillbox_study/Module_30_3/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "O:/QZskillbox_study/Module_30_3/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "O:/QZskillbox_study/Module_30_3/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
