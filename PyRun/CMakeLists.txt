INCLUDE_DIRECTORIES(/home/zyw/Public/PublicSource/)

AUX_SOURCE_DIRECTORY(. SOURCE)

AUX_SOURCE_DIRECTORY(/home/zyw/Public/PublicSource/python3.6/ PyLibDir) #添加python库目录
AUX_SOURCE_DIRECTORY(/home/zyw/Public/PublicSource/boost/ BoostLibDir)

ADD_LIBRARY(PyObj ${SOURCE})
TARGET_LINK_LIBRARIES(PyObj python3.6m)