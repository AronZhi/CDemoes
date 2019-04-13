INCLUDE_DIRECTORIES(/home/zyw/Public/PublicSource/) 
AUX_SOURCE_DIRECTORY(. SOURCE)
ADD_LIBRARY(PyObj ${SOURCE})
TARGET_LINK_LIBRARIES(PyObj /home/zyw/Public/PublicSource/python3.6/libpython3.6m.so)