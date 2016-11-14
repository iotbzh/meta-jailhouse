DESCRIPTION = "freertos for jailhouse demo"
LICENSE = "GPLv2"
PR = "r1"

inherit packagegroup

    
RDEPENDS_${PN} = "\
    freertos-cell-demo \
    "
