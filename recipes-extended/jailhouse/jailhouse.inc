DESCRIPTION = "jailhouse hypervisor"
HOMEPAGE = "https://github.com/siemens/jailhouse"
LICENSE = "GPLv2"
SECTION = "console/tools"

LIC_FILES_CHKSUM = "file://COPYING;md5=9fa7f895f96bde2d47fd5b7d95b6ba4d"

DEPENDS = "virtual/kernel"

#Need to be Check/Fix (seems to not work yocto use host package, not yocto native?)
DEPENDS = "python-mako-native"
DEPENDS = "make-native"
RDEPENDS_${PN} += "python-argparse"
RDEPENDS_${PN} += "python-mako"

inherit module

EXTRA_OEMAKE_append = " CROSS_COMPILE=${HOST_PREFIX} "
EXTRA_OEMAKE_append = " KDIR=${STAGING_KERNEL_DIR} "
EXTRA_OEMAKE_append = " V=1 "

export LDFLAGS=""

do_configure() {
    cp ${STAGING_KERNEL_BUILDDIR}/include/generated/autoconf.h ${S}/hypervisor/include/jailhouse/config.h;
}

do_compile() {
    oe_runmake KERNEL_PATH=${STAGING_KERNEL_DIR}   \
           KERNEL_VERSION=${KERNEL_VERSION}    \
               O=${STAGING_KERNEL_BUILDDIR} 
}

do_install() {
    oe_runmake DESTDIR=${D} \
               DEPMOD=echo INSTALL_MOD_PATH="${D}" \
               O=${STAGING_KERNEL_BUILDDIR} \
               install
    mkdir -p ${D}/${sysconfdir}/bash_completion.d/;
    cp ${S}/tools/jailhouse-completion.bash ${D}/${sysconfdir}/bash_completion.d/;
}

PACKAGES =+ " \
            ${PN}-firmware \
            "
            
            
FILES_${PN} += "${datadir}/*" 
FILES_${PN} += "${sysconfdir}/bash_completion.d/jailhouse-completion.bash" 
FILES_${PN} += "${sbindir}/*" 
FILES_${PN} += "${libexecdir}/*" 

FILES_${PN}-firmware = "${base_libdir}/firmware/*"

KERNEL_MODULE_AUTOLOAD += "jailhouse"
