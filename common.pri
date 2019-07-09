#项目通用配置文件

#全局变量
SRC_ROOT = $$PWD
BUILD_PATH = $$PWD/../build
THIRPARTY_PATH = $$PWD/ThirdParty

#依赖第三方----------------------------------
THIRPARTY_LIB_PATH = $$THIRPARTY_PATH/lib
THIRPARTY_INCLUDE_PATH = $$THIRPARTY_PATH/include

#配置输出路径----------------------------------
OUTPUT_PATH =
CONFIG(debug,debug|release){
   OUTPUT_PATH = $$BUILD_PATH/debug
}else{
   OUTPUT_PATH = $$BUILD_PATH/release
}
message($$OUTPUT_PATH)

LIB_PATH = $$OUTPUT_PATH/lib
BIN_PATH = $$OUTPUT_PATH/bin

#库和exe
contains(TEMPLATE,app){
DESTDIR = $$BIN_PATH
}else{
contains(TEMPLATE,lib)
DESTDIR = $$LIB_PATH
DLLDESTDIR = $$BIN_PATH
}


#全局的配置
INCLUDEPATH +=  $$PWD\
     $$SRC_ROOT/Constants




