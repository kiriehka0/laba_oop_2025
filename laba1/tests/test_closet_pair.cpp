#include <gtest/gtest.h>
#include <utility>
#include "closet_pair.h"
#include <cmath>

class ClosetPairTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
};

TEST_F(ClosetPairTest, KnownPairs) {
    auto result1 = closet_pair_tonum(6);
    EXPECT_EQ(result1.first, 5);
    EXPECT_EQ(result1.second, 4);
    
    auto result2 = closet_pair_tonum(11);
    EXPECT_EQ(result2.first, 10);
    EXPECT_EQ(result2.second, 6);
    
    auto result3 = closet_pair_tonum(14);
    EXPECT_EQ(result3.first, 13);
    EXPECT_EQ(result3.second, 12);
}

TEST_F(ClosetPairTest, EdgeCases) {
    auto result1 = closet_pair_tonum(3);
    EXPECT_EQ(result1.first, 0);
    EXPECT_EQ(result1.second, 0);
    
    auto result2 = closet_pair_tonum(5);
    EXPECT_EQ(result2.first, 0);
    EXPECT_EQ(result2.second, 0);
    
    auto result3 = closet_pair_tonum(6);
    EXPECT_NE(result3.first, 0);
    EXPECT_NE(result3.second, 0);
}

TEST_F(ClosetPairTest, PairProperties) {
    const int test_limit = 20;
    auto result = closet_pair_tonum(test_limit);
    
    if (result.first != 0) { 
        EXPECT_GT(result.first, 0);
        EXPECT_GT(result.second, 0);
        
        EXPECT_GT(result.first, result.second);
        
        EXPECT_LT(result.first, test_limit);
        EXPECT_LT(result.second, test_limit);
        
        int sum = result.first + result.second;
        int diff = result.first - result.second;
        
        double sqrt_sum = sqrt(sum);
        double sqrt_diff = sqrt(diff);
        
        EXPECT_EQ(sqrt_sum, static_cast<int>(sqrt_sum));
        EXPECT_EQ(sqrt_diff, static_cast<int>(sqrt_diff));
    }
}

TEST_F(ClosetPairTest, MultipleValues) {
    std::vector<int> test_values = {10, 15, 20, 25, 30};
    
    for (int limit : test_values) {
        auto result = closet_pair_tonum(limit);
        
        if (result.first != 0) {
            EXPECT_GT(result.first, result.second);
            EXPECT_LT(result.first, limit);
            
            int sum = result.first + result.second;
            int diff = result.first - result.second;
            
            double sqrt_sum = sqrt(sum);
            double sqrt_diff = sqrt(diff);
            
            EXPECT_EQ(sqrt_sum, static_cast<int>(sqrt_sum));
            EXPECT_EQ(sqrt_diff, static_cast<int>(sqrt_diff));
        }
    }
}

TEST_F(ClosetPairTest, NoPairFound) {
    for (int i = 2; i <= 5; i++) {
        auto result = closet_pair_tonum(i);
        EXPECT_EQ(result.first, 0);
        EXPECT_EQ(result.second, 0);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
