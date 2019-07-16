TEMPLATE  = aux

RESOURCES += \
    white/resource.qrc \
    black/resource.qrc

include(../common.pri)

system(rcc.exe  -binary $$PWD/white/resource.qrc -o $$BIN_PATH/white.rcc)

DISTFILES +=



