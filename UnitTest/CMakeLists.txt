﻿# CMakeList.txt: CMakeProject 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

#-----------------TODO 自定义编译选项
# SET(CMAKE_CXX_FLAGS “-std=c++11 -O2 -g”)

string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})

string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})

string(REGEX REPLACE "(.*)/${CURRENT_FOLDER}$" "\\1" MODULE_FOLDER_ABSOLUTE ${CURRENT_FOLDER_ABSOLUTE})

string(REGEX REPLACE ".*/(.*)" "\\1" MODULE_FOLDER ${MODULE_FOLDER_ABSOLUTE})

#get_filename_component(MODULE_FOLDER_ABSOLUTE ${CURRENT_FOLDER_ABSOLUTE} DIRECTORY)
#get_filename_component(MODULE_FOLDER ${CURRENT_FOLDER_ABSOLUTE} NAME)

#-----------------TODO 添加模块变量
SET(_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../${CURRENT_FOLDER}/include)
SET(_SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../${CURRENT_FOLDER}/src)

#当前工程的模块
SET(MODULE_PATH ${CMAKE_INSTALL_PREFIX}/${MODULE_FOLDER})

#添加其他工程模块
#SET(OHTER_PATH ${IDE_PATH}/${OTHER_INCLUDE_DIR})

#MESSAGE(STATUS ${MODULE_FOLDER_ABSOLUTE})
#MESSAGE(STATUS ${MODULE_FOLDER})
#MESSAGE(STATUS ${MODULE_PATH})

# 添加执行EXE目录
#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../${CURRENT_FOLDER}/include _INC_EXPATH)
#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../${CURRENT_FOLDER}/src _SRC_EXPATH)

#-----------------TODO EXE编译连接
#add_executable (${CURRENT_FOLDER} ${_INC_EXPATH} ${_SRC_EXPATH})

file(GLOB_RECURSE HEADER_FILES ${_INC_PATH}/*.h)
file(GLOB_RECURSE SOURCE_FILES ${_SRC_PATH}/*.cpp)
add_executable(${CURRENT_FOLDER} ${SOURCE_FILES} ${HEADER_FILES})

#-----------------TODO 创建工程内的库
#-----------------STATIC表示创建静态库，目标文件为 libmylib.a，如果是 SHARED， 则为创建动态库.
#add_library(${CURRENT_FOLDER} SHARED ${_INC_EXPATH} ${_SRC_EXPATH})

#-----------------TODO添加头文件的搜索目录
include_directories(${_INC_PATH}
					${_SRC_PATH}
					${MODULE_PATH}/include)
#-----------------TODO 添加lib文件的搜索目录
link_directories(${MODULE_PATH}/lib)

target_link_libraries(${CURRENT_FOLDER} ${MODULE_FOLDER})

find_package(pthread)
if(pthread_FOUND)
	include_directories(${pthread_DIR}/include)
	link_directories(${pthread_DIR}/lib)
	target_link_libraries(${CURRENT_FOLDER} general ${pthread_LIBRARY})	
endif(pthread_FOUND)

find_package(IxPublic)
if(IxPublic_FOUND)
	include_directories(${IxPublic_DIR}/include)
	link_directories(${IxPublic_DIR}/lib)
	target_link_libraries(${CURRENT_FOLDER} debug ${IxPublic_LIBRARY_DEBUG})
	target_link_libraries(${CURRENT_FOLDER} optimized ${IxPublic_LIBRARY})
endif(IxPublic_FOUND)

find_package(ExtendStructure)
if(ExtendStructure_FOUND)
	include_directories(${ExtendStructure_DIR}/include)
	link_directories(${ExtendStructure_DIR}/lib)
	target_link_libraries(${CURRENT_FOLDER} debug ${ExtendStructure_LIBRARY_DEBUG})
	target_link_libraries(${CURRENT_FOLDER} optimized ${ExtendStructure_LIBRARY})
	
endif(ExtendStructure_FOUND)

find_package(IxSystem)
if(IxSystem_FOUND)
	include_directories(${IxSystem_DIR}/include)
	link_directories(${IxSystem_DIR}/lib)
	target_link_libraries(${CURRENT_FOLDER} debug ${IxSystem_LIBRARY_DEBUG})
	target_link_libraries(${CURRENT_FOLDER} optimized ${IxSystem_LIBRARY})
endif(IxSystem_FOUND)

find_package(IxKernel)
if(IxKernel_FOUND)
	include_directories(${IxKernel_DIR}/include)
	link_directories(${IxKernel_DIR}/lib)
	target_link_libraries(${CURRENT_FOLDER} debug ${IxKernel_LIBRARY_DEBUG})
	target_link_libraries(${CURRENT_FOLDER} optimized ${IxKernel_LIBRARY})
endif(IxKernel_FOUND)

find_package(IxPluginDemo)
if(IxPluginDemo_FOUND)
	include_directories(${IxPluginDemo_DIR}/include)
	link_directories(${IxPluginDemo_DIR}/lib)
	target_link_libraries(${CURRENT_FOLDER} debug ${IxPluginDemo_LIBRARY_DEBUG})
	target_link_libraries(${CURRENT_FOLDER} optimized ${IxPluginDemo_LIBRARY})
endif(IxPluginDemo_FOUND)
#-----------------TODO 执行外部命令
#set(THRIFT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/mythrift.thrift)
#exec_program("thrift --gen cpp -o ${CMAKE_CURRENT_SOURCE_DIR} ${THRIFT_FILE}")

#-----------------TODO: 如有需要，请添加测试并安装目标。
