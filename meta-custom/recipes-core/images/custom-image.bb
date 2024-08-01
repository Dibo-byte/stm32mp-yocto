SUMMARY = "My custom Linux image."

IMAGE_INSTALL = "packagegroup-core-boot ${CORE_IMAGE_EXTRA_INSTALL}"

IMAGE_INSTALL:append = " i2c-tools"

IMAGE_INSTALL += "myaccel"
IMAGE_INSTALL += "spidevtest"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image
inherit extrausers

#Set rootfs to 200 MiB by default

IMAGE_OVERHEAD_FACTOR ?= "1.0"
IMAGE_ROOTFS_SIZE ?= "204800"

PASSWD = "\$5\$vk2EY8N.SX77HjEY\$OWJxMZlvhc/Dj51NWsY31ypb.xTbIWzFiFkzbDEobt4"

# Change root password
EXTRA_USERS_PARAMS = "\
    usermod -p '${PASSWD}' root; \
    "


