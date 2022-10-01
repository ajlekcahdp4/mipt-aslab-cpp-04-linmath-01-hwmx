/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <tsimmerman.ss@phystech.edu>, <alex.rom23@mail.ru> wrote this file.  As long as you
 * retain this notice you can do whatever you want with this stuff. If we meet
 * some day, and you think this stuff is worth it, you can buy us a beer in
 * return.
 * ----------------------------------------------------------------------------
 */

#include <gtest/gtest.h>
#include <memory>
#include <vector.hpp>
#include <vector>

using vector = typename throttle::containers::vector<int>;

TEST(test_vector, test_ctor) {
  vector a;
  EXPECT_EQ(a.size(), 0);
}

TEST(test_vector, test_push_pop_back) {
  vector a;
  for (auto i = 0; i < 5; i++)
    a.push_back(i);

  EXPECT_EQ(a.size(), 5);

  for (auto i = 4; i >= 0; i--) {
    EXPECT_EQ(a.back(), i);
    a.pop_back();
  }

  EXPECT_EQ(a.size(), 0);
}

TEST(test_vector, test_copy_ctor) {
  vector a;
  for (auto i = 0; i < 5; i++)
    a.push_back(i);

  vector b = a;

  EXPECT_EQ(a.size(), b.size());

  for (auto i = 4; i >= 0; i--) {
    EXPECT_EQ(b.back(), i);
    EXPECT_EQ(a.back(), i);
    b.pop_back();
    a.pop_back();
  }
}

TEST(test_vector, test_reserve_1) {
  vector a;
  a.reserve(7);
  EXPECT_GE(a.capacity(), 7);
  EXPECT_EQ(a.size(), 0);
}

TEST(test_vector, test_reserve_2) {
  vector a;
  a.reserve(7);
  EXPECT_GE(a.capacity(), 7);
  EXPECT_EQ(a.size(), 0);
}

TEST(test_vector, test_reserve_3) {
  vector a;

  for (int i = 0; i < 5; i++)
    a.push_back(i);

  EXPECT_EQ(a.size(), 5);

  a.reserve(7);

  EXPECT_GE(a.capacity(), 7);
  EXPECT_EQ(a.size(), 5);
}

TEST(test_vector, test_iterator_1) {
  vector a;
  for (auto i = 0; i < 4096; i++)
    a.push_back(i);

  int i = 0;
  for (auto &elem : a) {
    EXPECT_EQ(elem, i);
    i++;
  }
}

TEST(test_vector, test_iterator_2) {
  vector a;
  for (auto i = 0; i < 10; i++)
    a.push_back(i);

  int i = 9;
  for (auto it = a.end() - 1; it != a.begin(); it--) {
    EXPECT_EQ(*it, i);
    i--;
  }
}

TEST(test_vector, test_iterator_3) {
  vector a;
  for (auto i = 0; i < 10; i++)
    a.push_back(i);

  auto it = a.begin();

  EXPECT_EQ(*std::next(it, 5), 5);
}

TEST(test_vector, test_iterator_4) {
  vector a;
  for (auto i = 0; i < 10; i++)
    a.push_back(i);

  auto it = a.end();

  EXPECT_EQ(*std::prev(it, 1), 9);
  EXPECT_EQ(*std::prev(it, 5), 5);
}
