BBB_KERNEL := /home/phong/working_space/00-Project-Management/00-Freelance/BBB/bb-kernel/KERNEL

TOOLCHAIN := /home/phong/working_space/00-Project-Management/00-Freelance/BBB/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/bin

PREFIX := arm-linux-gnueabihf-
CC := gcc
LD := ld

# dtc -I dtb -O dts -o am335x-boneblack.dts am335x-boneblack.dtb

dts:
	make ARCH=arm CROSS_COMPILE=$(TOOLCHAIN)/$(PREFIX) -C $(BBB_KERNEL) dtbs

all :
	make ARCH=arm CROSS_COMPILE=$(TOOLCHAIN)/$(PREFIX) -C $(BBB_KERNEL) M=$(shell pwd)

clean :
	make -C $(BBB_KERNEL) M=$(shell pwd) clean
