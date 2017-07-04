THEOS_DEVICE_IP = 192.168.2.160
TARGET = iphone:latest:8.0
ARCHS = armv7 arm64

include theos/makefiles/common.mk

TWEAK_NAME = WX_SendImage
WX_SendImage_FILES = Tweak.xm
WX_SendImage_FRAMEWORKS = UIKit, Foundation

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 WeChat"
