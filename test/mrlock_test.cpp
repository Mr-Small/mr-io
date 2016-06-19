#include <gtest/gtest.h>
#include "mrlock.h"

using namespace mrio;

// Test default parameters.
TEST(MrLock, Default_Param) {

    MrLock mrLock;
    ASSERT_EQ(false, mrLock.isLocked());
}

// Test lock / unlock.
TEST(MrLock, lock_unlock) {

    MrLock mrLock;
    mrLock.lock();
    ASSERT_EQ(true, mrLock.isLocked());
    mrLock.unlock();
    ASSERT_EQ(false, mrLock.isLocked());
}

// Test already lock / unlock.
TEST(MrLock, already_lock_unlock) {

    MrLock mrLock;
    mrLock.lock();
    mrLock.lock();
    ASSERT_EQ(true, mrLock.isLocked());
    mrLock.unlock();
    mrLock.unlock();
    ASSERT_EQ(false, mrLock.isLocked());
}
