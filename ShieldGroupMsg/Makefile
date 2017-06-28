THEOS_DEVICE_IP = 192.168.2.158
TARGET = iphone:latest:8.0
ARCHES = armv7 arm64
include theos/makefiles/common.mk

TWEAK_NAME = ShieldGroupMsg
ShieldGroupMsg_FILES = Tweak.xm
ShieldGroupMsg_FRAMEWORKS = UIKit

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 WeChat"
