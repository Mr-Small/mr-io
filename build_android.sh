#!/usr/bin/env sh

cd platforms/android

ndk-build NDK_PROJECT_PATH=${PWD} NDK_APPLICATION_MK=${PWD}/Application.mk
