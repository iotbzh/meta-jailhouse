require freertos-cell.inc

SRCREV = "74560c8c46b71c53f900d4a274efffc51fb7bdb5"

S = "${WORKDIR}/git"

SRC_URI = " \
    git://github.com/siemens/freertos-cell.git;protocol=https;branch=master \
    file://fix_makefile.diff \
    "
