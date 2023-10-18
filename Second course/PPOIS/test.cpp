#include "pch.h"
#include "D:\Study\Univer\2 kurs\PPOIS\MULTI\mmultisset.cpp"

class MultisetTest : public ::testing::Test {
protected:
    Multiset m;

    void SetUp() override {
        m.addElement("a");
        m.addElement("b");
        m.addElement("c");
    }
};

TEST_F(MultisetTest, TestConstructor) {
    Multiset A;
    ASSERT_EQ(A.getCardinality(), 0);
    ASSERT_TRUE(A.isEmpty());

    Multiset B("{1, 2, 3, {4, 5}, {{6}}}");
    ASSERT_EQ(B.getCardinality(), 5);
    ASSERT_FALSE(B.isEmpty());

    string set = "{1, {}, 5, {b}}";
    Multiset C(set);
    ASSERT_EQ(C.getCardinality(), 4);
    ASSERT_FALSE(C.isEmpty());

    Multiset D(C);
    ASSERT_EQ(D.getCardinality(), 4);
    ASSERT_FALSE(D.isEmpty());
    ASSERT_TRUE(D == C);
}


TEST_F(MultisetTest, TestAddElement) {
    m.addElement("d");
    m.addElement("1");
    ASSERT_TRUE(m.findEls("d"));
    ASSERT_TRUE(m.findEls("1"));
}

TEST_F(MultisetTest, TestDelElement) {
    m.delElement("b");
    ASSERT_FALSE(m.findEls("b"));
}

TEST_F(MultisetTest, TestFindEls) {
    ASSERT_TRUE(m.findEls("a"));
    ASSERT_FALSE(m.findEls("d"));
}

TEST_F(MultisetTest, TestCountEls) {
    ASSERT_EQ(m.countEls("a"), 1);
    m.addElement("a");
    ASSERT_EQ(m.countEls("a"), 2);
}

TEST_F(MultisetTest, TestAddSubset) {
    Multiset subset("{1, 2, 3, {4, 5}}");
    m.addSubset(subset);
    ASSERT_TRUE(m.findSubs(subset));
    ASSERT_TRUE(m.findSubs("{1, 2, 3, {4, 5}}"));
}

TEST_F(MultisetTest, TestDelSubset) {
    Multiset subset("{a, b, c}");
    m.addSubset(subset);
    ASSERT_TRUE(m.findSubs(subset));
    m.delSubset(subset);
    ASSERT_FALSE(m.findSubs(subset));
}

TEST_F(MultisetTest, TestFindSubset) {
    Multiset subset("{1, {3}, 5}");
    m.addSubset(subset);
    ASSERT_TRUE(m.findSubs(subset));
    ASSERT_TRUE(m.findSubs("{1, {3}, 5}"));
}

TEST_F(MultisetTest, TestCountSubset) {
    Multiset subset("{}");
    m.addSubset(subset);
    ASSERT_EQ(m.countSubs(subset), 1);
    m.addSubset(subset);
    ASSERT_EQ(m.countSubs(subset), 2);
}

TEST_F(MultisetTest, TestOperatorPlusEl) {
    m.addElement("a");
    m.addElement("1");
    m.addElement("1");
    Multiset m2("{a, b, b, d, 2, 2}");
    Multiset m3 = m + m2;
    ASSERT_TRUE(m3.countEls("a"), 2);
    ASSERT_TRUE(m3.countEls("b"), 2);
    ASSERT_TRUE(m3.countEls("c"), 1);
    ASSERT_TRUE(m3.countEls("d"), 1);
    ASSERT_TRUE(m3.countEls("1"), 2);
    ASSERT_TRUE(m3.countEls("2"), 2);
}

TEST_F(MultisetTest, TestOperatorPlusSub) {
    Multiset m2("{{a}, {a}, {b}, {c}, {2}, {2}}");
    Multiset m3("{{a}, {b}, {b}, {d}, {1}, {1}}");
    Multiset m4 = m2 + m3;
    ASSERT_TRUE(m4.countSubs("{a}"), 2);
    ASSERT_TRUE(m4.countSubs("{b}"), 2);
    ASSERT_TRUE(m4.countSubs("{c}"), 1);
    ASSERT_TRUE(m4.countSubs("{d}"), 1);
    ASSERT_TRUE(m4.countSubs("{1}"), 2);
    ASSERT_TRUE(m4.countSubs("{2}"), 2);
}

TEST_F(MultisetTest, TestOperatorMinusEl) {
    Multiset m2;
    m2.addElement("b");
    m.addElement("b");
    Multiset m3 = m - m2;
    ASSERT_FALSE(m3.findEls("a"));
    ASSERT_FALSE(m3.findEls("c"));
    ASSERT_TRUE(m3.findEls("b"));
}

TEST_F(MultisetTest, TestOperatorMinusSub) {
    Multiset m1("{{b}, {b}}");
    Multiset m2("{{b}}");
    Multiset m3 = m1 - m2;
    ASSERT_TRUE(m3.countSubs("{b}"), 1);
}

TEST_F(MultisetTest, TestOperatorMultiplyEl) {
    Multiset m1("{1, 2, 2, 4, 5}");
    Multiset m2("{2, 4, 4, 3, 1}");
    Multiset m3 = m1 * m2;
    ASSERT_FALSE(m3.findEls("5"));
    ASSERT_TRUE(m3.countEls("2"), 1);
    ASSERT_TRUE(m3.countEls("4"), 1);
    ASSERT_TRUE(m3.countEls("1"), 1);
    ASSERT_FALSE(m3.findEls("3"));
}

TEST_F(MultisetTest, TestOperatorMultiplySub) {
    Multiset m1("{{1}, {2}, {2}, {4}, {5}}");
    Multiset m2("{{2}, {4}, {4}, {3}, {1}}");
    Multiset m3 = m1 * m2;
    ASSERT_FALSE(m3.findSubs("{5}"));
    ASSERT_TRUE(m3.countSubs("{2}"), 1);
    ASSERT_TRUE(m3.countSubs("{4}"), 1);
    ASSERT_TRUE(m3.countSubs("{1}"), 1);
    ASSERT_FALSE(m3.findSubs("{3}"));
}

TEST_F(MultisetTest, TestOperatorEqual) {
    Multiset m2;
    m2.addElement("a");
    m2.addElement("b");
    m2.addElement("c");
    ASSERT_TRUE(m == m2);
}

TEST_F(MultisetTest, TestOperatorNotEqual) {
    Multiset m2;
    m2.addElement("a");
    m2.addElement("b");
    ASSERT_TRUE(m != m2);
}

TEST_F(MultisetTest, TestOperatorIndex) {
    ASSERT_TRUE(m["a"]);
    ASSERT_FALSE(m["d"]);
    m.addSubset("{1}");
    ASSERT_TRUE(m["{1}"]);
}

TEST_F(MultisetTest, TestIsEmpty) {
    ASSERT_FALSE(m.isEmpty());
    m.delElement("a");
    m.delElement("b");
    m.delElement("c");
    ASSERT_TRUE(m.isEmpty());
}

TEST_F(MultisetTest, TestToString) {
    ASSERT_EQ(m.toString(), "{a, b, c}");
    Multiset m2("{1, 3, {2}, {4, {7}}}");
    ASSERT_EQ(m2.toString(), "{1, 3, {2}, {4, {7}}}");
}

TEST_F(MultisetTest, TestBoolean) {
    Multiset booleanSet = m.boolean();
    ASSERT_EQ(booleanSet.toString(), "{{}, {a}, {b}, {a, b}, {c}, {a, c}, {b, c}, {a, b, c}}");
}

TEST_F(MultisetTest, TestParsStrToSet) {
    m.parsStrToSet("{d, e, f, {2, {3}}}");
    ASSERT_TRUE(m.findEls("d"));
    ASSERT_TRUE(m.findEls("e"));
    ASSERT_TRUE(m.findEls("f"));
    ASSERT_TRUE(m.findSubs("{2, {3}}"));
}

TEST_F(MultisetTest, TestOperatorPlusEqual) {
    Multiset m2{"{d, {1, 4}}"};
    m += m2;
    ASSERT_TRUE(m.findEls("a"));
    ASSERT_TRUE(m.findEls("b"));
    ASSERT_TRUE(m.findEls("c"));
    ASSERT_TRUE(m.findEls("d"));
    ASSERT_TRUE(m.findSubs("{1, 4}"));
}

TEST_F(MultisetTest, TestOperatorMinusEqual) {
    m.addElement("a");
    m.addSubset("{2}");
    m.addSubset("{2}");
    Multiset m2("{b, a, {2}}");
    m -= m2;
    ASSERT_FALSE(m.findEls("b"));
    ASSERT_TRUE(m.findEls("a"));
    ASSERT_TRUE(m.findSubs("{2}"));
}

TEST_F(MultisetTest, TestOperatorMultiplyEqual) {
    Multiset m2("{b, c, d, {2}}");
    m.addSubset("{2}");
    m *= m2;
    ASSERT_FALSE(m.findEls("a"));
    ASSERT_TRUE(m.findEls("b"));
    ASSERT_TRUE(m.findEls("c"));
    ASSERT_TRUE(m.findSubs("{2}"));
    ASSERT_FALSE(m.findEls("d"));
}

