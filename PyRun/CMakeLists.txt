CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(PyRun)

INCLUDE_DIRECTORIES(../../CLib)

AUX_SOURCE_DIRECTORY(. SOURCE)

FIND_LIBRARY(PYTHON3_6 python3.6m /python3.6/config-3.6m-x86_64-linux-gnu) #添加python库目录
FIND_LIBRARY(GLOG_LIB libglog.a ../../CLib/glog/) #添加glog库,glog库编译需要链接多线程库

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") #指定C++标准

ADD_EXECUTABLE(PyRun ${SOURCE})

#链接库
TARGET_LINK_LIBRARIES(PyRun ${PYTHON3_6} ${GLOG_LIB} pthread)