#include "gtest/gtest.h"
#include "color_parser.h"

TEST(ColorParserTest, hex) {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 0;
    
    ASSERT_EQ(color_parse("#CCDDEEFF", &r, &g, &b, &a), TRUE); 
    ASSERT_EQ(r == 0xCC && g == 0xDD && b == 0xEE && a == 0xFF, TRUE);
    
    ASSERT_EQ(color_parse("#CCDDEE", &r, &g, &b, &a), TRUE); 
    ASSERT_EQ(r == 0xCC && g == 0xDD && b == 0xEE && a == 0xFF, TRUE);
    
    ASSERT_EQ(color_parse("#ccddee", &r, &g, &b, &a), TRUE); 
    ASSERT_EQ(r == 0xCC && g == 0xDD && b == 0xEE && a == 0xFF, TRUE);
    
    ASSERT_EQ(color_parse("#ccdd", &r, &g, &b, &a), FALSE); 
}

TEST(ColorParserTest, name) {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 0;
    
    ASSERT_EQ(color_parse("white", &r, &g, &b, &a), TRUE); 
    ASSERT_EQ(r == 0xFF && g == 0xFF && b == 0xFF && a == 0xFF, TRUE);
    ASSERT_EQ(color_parse("black", &r, &g, &b, &a), TRUE); 
    ASSERT_EQ(r == 0x00 && g == 0x00 && b == 0x00 && a == 0xff, TRUE);
}

TEST(ColorParserTest, rgb) {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 0;
    
    ASSERT_EQ(color_parse("rgb(128, 127, 255)", &r, &g, &b, &a), TRUE); 
    ASSERT_EQ(r == 128 && g == 127 && b == 255 && a == 0xFF, TRUE);
    
    ASSERT_EQ(color_parse("rgba(128, 127, 255, 0)", &r, &g, &b, &a), TRUE); 
    ASSERT_EQ(r == 128 && g == 127 && b == 255 && a == 0, TRUE);
    
    ASSERT_EQ(color_parse("rgba(128, 127, 255, 1)", &r, &g, &b, &a), TRUE); 
    ASSERT_EQ(r == 128 && g == 127 && b == 255 && a == 0xff, TRUE);
}

