THEOS_DEVICE_IP = 192.168.2.160
TARGET = iphone:latest:8.0
ARCHS = arm64 armv7

include theos/makefiles/common.mk

TWEAK_NAME = AgreeFriendRequest
AgreeFriendRequest_FILES = Tweak.xm

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 WeChat"
