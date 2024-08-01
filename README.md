# stm32mp-yocto
Creation of Linux Image on STM32MP157F-DK2_ By Gabriel Dibo

This repository is intended to serve as a backup of a core image-minimal of STM32MP157F-DK2. To build this image it is necessary to have 4 meta-layers where information regarding how to build the image is stored. For this you will need:

1) meta-openembedded
2) meta-st-stm32mp
3) poky_mickledore
4) meta-custom (your customized meta-layer with apps and features you want)

After creating these meta-layers you will have a 'Build' directory. This contains the path where the image will be deployed.


