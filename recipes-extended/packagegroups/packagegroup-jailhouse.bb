DESCRIPTION = "Jailhouse package"
LICENSE = "GPLv2"
PR = "r1"

inherit packagegroup

JAILHOUSE = " \
    jailhouse-firmware \
    jailhouse \
    kernel-module-jailhouse \
    "
    
RDEPENDS_${PN} = "\
    ${JAILHOUSE} \
    "
