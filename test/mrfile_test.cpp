#include <gtest/gtest.h>
#include "mrfile.h"

using namespace mrio;

// Test constructor.
TEST(MrFile, Constructor) {

    MrFile mrFile;
    ASSERT_EQ(false, mrFile.isOpen());
    ASSERT_EQ(false, mrFile.isEof());
    ASSERT_EQ(0, mrFile.getFileSize());
}

// Test not open.
TEST(MrFile, Notopen) {

    MrFile mrFile;
    ASSERT_EQ(0, mrFile.getFileSize());
    ASSERT_EQ(false, mrFile.isEof());
    ASSERT_EQ(-1, mrFile.write(NULL, 0));
    ASSERT_EQ(-1, mrFile.read(NULL, 0));
    ASSERT_EQ(-1, mrFile.writeText(""));
}
