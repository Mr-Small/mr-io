LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := mrio
LOCAL_SRC_FILES := ../../mrlock.cpp ../../mrstream.cpp ../../mrfile.cpp
LOCAL_C_INCLUDES := ../../include

include $(BUILD_SHARED_LIBRARY)
