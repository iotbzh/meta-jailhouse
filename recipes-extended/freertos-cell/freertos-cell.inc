DESCRIPTION = "jailhouse freertos cell"
HOMEPAGE = "https://github.com/siemens/freertos-cell"
LICENSE = "GPLv2"
SECTION = "console/tools"

LIC_FILES_CHKSUM = "file://COPYING;md5=9fa7f895f96bde2d47fd5b7d95b6ba4d"

RDEPENDS_${PN}-demo += "jailhouse"

EXTRA_OEMAKE_append_arm = " ARCH=arm CROSS_COMPILE=${HOST_PREFIX} "
EXTRA_OEMAKE_append = " KDIR=${STAGING_KERNEL_DIR} "

export LDFLAGS=""

#COPYING file is missing upstream
SRC_URI_append = "file://COPYING "
do_configure_prepend() {
    cp ${WORKDIR}/COPYING ${S}
}

do_compile() {
    oe_runmake ; 
}

do_install() {
    mkdir -p ${D}/${datadir}/freertos;
    cp ${S}/freertos-demo.bin ${D}/${datadir}/freertos;
}

PACKAGES =+ " \
            ${PN}-demo \
            "

FILES_${PN}-demo += "${datadir}/*" 
