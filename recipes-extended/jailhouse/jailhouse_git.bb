require jailhouse.inc

SRCREV = "fbeafd5b3251cec198544865db6d68667548413b"

S = "${WORKDIR}/git"

SRC_URI = " \
    git://github.com/siemens/jailhouse.git;protocol=https;branch=master \
    "
