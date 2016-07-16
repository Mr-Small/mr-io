LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := mrio
LOCAL_SRC_FILES := ../../lib/mrlock.cpp ../../lib/mrstream.cpp ../../lib/mrfile.cpp
LOCAL_C_INCLUDES := ../../include

#include $(BUILD_SHARED_LIBRARY)
include $(BUILD_STATIC_LIBRARY)
