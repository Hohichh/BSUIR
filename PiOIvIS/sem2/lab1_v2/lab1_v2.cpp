#include <iostream>
#include "Set.h"
using namespace std;

void test1() {
    cout << "Test 1: Create and add" << endl;
    cout << "Example 1: " << endl;
    Set s1;
    cout << "Add 1" << endl;
    s1.Add("1");
    cout << "Add 2" << endl;
    s1.Add("2");
    cout << "Add 3" << endl;
    s1.Add("3");
    cout << "Set 1: "<< endl;
    s1.PrintSet();

    cout << "Example 2: " << endl;
    Set s2;
    cout << "Add 3" << endl;
    s2.Add("3");
    cout << "Add 4" << endl;
    s2.Add("4");
    cout << "Add 5" << endl;
    s2.Add("5");
    cout << "Set 2: " << endl;
    s2.PrintSet();
   
}
void test2() {
    cout << "Test 2: Delete " << endl;
    cout << "Example 1: " << endl;
    Set s1;
    cout << "Add 1" << endl;
    s1.Add("1");
    cout << "Add 2" << endl;
    s1.Add("2");
    cout << "Add 3" << endl;
    s1.Add("3");
    cout << "Delete 2" << endl;
    s1.Del("2");
    cout << "Set 1: " << endl;
    s1.PrintSet();

    cout << "Example 2: " << endl;
    Set s2;
    cout << "Add 3" << endl;
    s2.Add("3");
    cout << "Add 4" << endl;
    s2.Add("4");
    cout << "Add 5" << endl;
    s2.Add("5");
    cout << "Delete 3" << endl;
    s2.Del("3");
    cout << "Delete 5" << endl;
    s2.Del("6");
    cout << "Set 2: " << endl;
    s2.PrintSet();
}
void test3() {
    cout << "Test 3: Union " << endl;
    Set s1;
    s1.Add("100");
    s1.Add("2");
    s1.Add("3");
    cout << "Set 1: " << endl;
    s1.PrintSet();

    Set s2;
   /* s2.Add("4a");
    s2.Add("35");
    s2.Add("3");*/
    cout << "Set 2: " << endl;
    s2.PrintSet();

   cout << "Union:\n";
   Set Uni = s1.Union(s2);
   Uni.PrintSet();

}
void test4() {
    cout << "Test 4: Intersection " << endl;
    Set s1;
    s1.Add("100");
    s1.Add("3");
    s1.Add("2");
    cout << "Set 1: " << endl;
    s1.PrintSet();

    Set s2;
    s2.Add("4a");
    s2.Add("35");
    s2.Add("3");
    cout << "Set 2: " << endl;
    s2.PrintSet();

    cout << "Intersection:\n";
    Set Int = s1.Intersec(s2);
    Int.PrintSet();
}
void test5() {
    cout << "Test 5: Find" << endl;
    cout << "Example: " << endl;
    Set s1;
    cout << "Add 1" << endl;
    s1.Add("1");
    cout << "Add 6" << endl;
    s1.Add("6");
    cout << "Add 3" << endl;
    s1.Add("3");
    cout << "Set 1: " << endl;
    s1.PrintSet();
    cout << "Index of element 1:" << s1.Find("1") << endl;
    cout << "Index of element 10:" << s1.Find("10") << endl;
    cout << "Index of element 3:" << s1.Find("3") << endl;
   
}
 
int main()
{
    cout << "Welcome to the test program for library 'Set'!\n\n";
 

        test1();
 
        test2();
  
        test3();
 
        test4();
    
        test5();
 
        
        return 0;

}

