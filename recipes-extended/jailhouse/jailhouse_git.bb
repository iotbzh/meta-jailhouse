require jailhouse.inc

SRCREV = "e4fe53ab9bf11c40be4ad521e798fa431a2560d8"

S = "${WORKDIR}/git"

SRC_URI = " \
    git://github.com/siemens/jailhouse.git;protocol=https;branch=master \
    "
