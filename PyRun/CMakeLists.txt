CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

INCLUDE_DIRECTORIES(../..//PublicSource/)

AUX_SOURCE_DIRECTORY(. SOURCE)

FIND_LIBRARY(PYTHON3_6 python3.6m ../../PublicSource/python3.6/) #添加python库目录
FIND_LIBRARY(GLOG_LIB glog ../../PublicSource/glog/) #添加glog库,glog库编译需要链接多线程库

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") #指定C++标准

ADD_LIBRARY(PyObj ${SOURCE})
TARGET_LINK_LIBRARIES(PyObj ${PYTHON3_6} ${GLOG_LIB} pthread)