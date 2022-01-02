#include "Map.h"
#include "gtest/gtest.h"
#include <string>

TEST(Constructor, AllConstructors) {
    TemplateMap::Map<std::string, int> map;
    ASSERT_EQ(map.size(), 0);
    ASSERT_EQ(map.isEmpty(), true);
}

TEST(Methods, MainMethods) {
    TemplateMap::Map<std::string, int> map;
    map.insert("hello", 1);
    std::string s1("hello");
    std::string s2("world");
    map.insert(s2, 2);
    ASSERT_EQ(map.size(), 2);
    ASSERT_EQ(map.isEmpty(), false);
    ASSERT_EQ(map.search(s1)->getValue(), 1);
    ASSERT_EQ(map.search("world")->getValue(), 2);
}

TEST(MapIterator, IteratingThru) {
    TemplateMap::Map<std::string, int> map;
    map.insert("a", 1);
    map.insert("abcd", 4);
    map.insert("ab", 2);
    map.insert("abc", 3);
    TemplateMap::Map<std::string, int>::iterator it;
    int i = 1;
    for (it = map.begin(); it != map.end(); ++it, ++i) {
        ASSERT_EQ(it->getValue(), i);
    }
    i = 1;
    // using iterator implicitly
    for (const auto& element : map) {
        ASSERT_EQ(element.getValue(), i);
        ++i;
    }
}

TEST(MapOperators, AllOperators) {
    TemplateMap::Map<std::string, int> map;
    map.insert("a", 1);
    map.insert("abcd", 4);
    map.insert("ab", 2);
    map.insert("abc", 3);
    ASSERT_EQ(map["a"], 1);
    std::string s("abcd");
    ASSERT_EQ(map[s], 4);

    const std::string s_const("abcd");
    ASSERT_EQ(map[s], 4);
    const std::string s_const2("non_exist");
    map[s_const2] = 1;
    ASSERT_EQ(map[s_const2], 1);

    map["abcde"] = 8;
    ASSERT_EQ(map["abcde"], 8);
    map["abcde"] = 9;
    ASSERT_EQ(map["abcde"], 9);
    map["abcdef"];
    ASSERT_EQ(map["abcdef"], 1);

    TemplateMap::Map<std::string, int> map1;
    map1["a"] = 1;
    map1["ab"] = 2;
    std::string str1("abc");
    map1[str1] = 3;
    const std::string str2("abcd");
    map1[str2] = 4;
    ASSERT_EQ(map1["a"], 1);
    ASSERT_EQ(map1["ab"], 2);
    ASSERT_EQ(map1["abc"], 3);
    ASSERT_EQ(map1[str2], 4);
}

TEST(Iterator, IteratorOperands) {
    TemplateMap::Map<std::string, int> map;
    map.insert("a", 1);
    map.insert("abcd", 4);
    map.insert("ab", 2);
    map.insert("abc", 3);
    TemplateMap::Map<std::string, int>::iterator it, it_next;
    it = map.begin();
    it_next = it++;
    ASSERT_EQ(it == it_next, false);
    ASSERT_EQ((*it).getValue(), 2);
    ++it;
    ASSERT_EQ(it != it_next, true);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}