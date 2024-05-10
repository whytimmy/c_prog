#include <gtest/gtest.h>
#include "vector.hpp"
#include "vector.cpp"


TEST(vector_push_back, one_time) {
    whytimmy::Vector<int> vec;
	vec.push_back(0);
	ASSERT_EQ(1, vec.get_size())
		<< "Неправильно подсчитан размер вектора" << vec.get_size();
}


TEST(vector_push_back, two_times) {
    whytimmy::Vector<int> vec;
	vec.push_back(0);
	vec.push_back(0);
	ASSERT_EQ(2, vec.get_size())
		<< "Неправильно подсчитан размер вектора" << vec.get_size();
}

TEST(vector_insert, one_time) {
    whytimmy::Vector<int> vec;
	vec.insert(0, 1);
	ASSERT_EQ(1, vec.get_size())
		<< "Неправильно подсчитан размер вектора" << vec.get_size();
}


TEST(vector_insert, two_times) {
    whytimmy::Vector<int> vec;
	vec.insert(0, 1);
	vec.insert(0, 1);
	ASSERT_EQ(2, vec.get_size())
		<< "Неправильно подсчитан размер вектора" << vec.get_size();
}

TEST(vector_remove_first, one_time) {
    whytimmy::Vector<int> vec;
	vec.push_back(1);
	vec.remove_first(1);
	ASSERT_EQ(0, vec.get_size())
		<< "Неправильно подсчитан размер вектора" << vec.get_size();
}

TEST(vector_remove_first, zero_times) {
    whytimmy::Vector<int> vec;
	vec.push_back(1);
	vec.remove_first(2);
	ASSERT_EQ(1, vec.get_size())
		<< "Неправильно подсчитан размер вектора" << vec.get_size();
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
