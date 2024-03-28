#include "gtest/gtest.h"  // Do��cz bibliotek� Google Test
#include "C:\Users\a\source\repos\projekt_rozwiazywanie_testow\projekt_rozwiazywanie_testow\�r�d�o.cpp"

// Testy jednostkowe dla klasy TestManager

TEST(TestManagerTest, DisplayTests) {
    TestManager testManager;
    testing::internal::CaptureStdout(); // Przechwy� standardowe wyj�cie
    testManager.displayTests();
    std::string output = testing::internal::GetCapturedStdout(); // Pobierz przechwycone wyj�cie
    EXPECT_EQ("Witaj w programie testowym!\n1. Test 1\n2. Test 2\n3. Test 3\n4. Test 4\n5. Test 5\n6. Wyjscie\n", output);
}

TEST(TestManagerTest, GetTestChoice_ValidInput) {
    TestManager testManager;
    std::istringstream input("3");
    std::cin.rdbuf(input.rdbuf()); // Przekieruj wej�cie do strumienia
    int choice = testManager.getTestChoice();
    EXPECT_EQ(3, choice);
}

TEST(TestManagerTest, GetTestChoice_InvalidInput) {
    TestManager testManager;
    std::istringstream input("abc\n3");
    std::cin.rdbuf(input.rdbuf()); // Przekieruj wej�cie do strumienia
    testing::internal::CaptureStdout(); // Przechwy� standardowe wyj�cie
    int choice = testManager.getTestChoice();
    std::string output = testing::internal::GetCapturedStdout(); // Pobierz przechwycone wyj�cie
    EXPECT_EQ("Wybierz test: Nieprawidlowy wybor. Sprobuj ponownie.\nWybierz test: ", output);
    EXPECT_EQ(3, choice);
}

TEST(TestManagerTest, RunTest_TestChoice6) {
    TestManager testManager;
    std::istringstream input("6");
    std::cin.rdbuf(input.rdbuf()); // Przekieruj wej�cie do strumienia
    testing::internal::CaptureStdout(); // Przechwy� standardowe wyj�cie
    testManager.runTest(testManager.getTestChoice());
    std::string output = testing::internal::GetCapturedStdout(); // Pobierz przechwycone wyj�cie
    EXPECT_EQ("Koniec.\n", output);
}

TEST(TestManagerTest, RunTest_TestChoiceNot6) {
    TestManager testManager;
    std::istringstream input("3\ny\n");
    std::cin.rdbuf(input.rdbuf()); // Przekieruj wej�cie do strumienia
    testing::internal::CaptureStdout(); // Przechwy� standardowe wyj�cie
    testManager.runTest(testManager.getTestChoice());
    std::string output = testing::internal::GetCapturedStdout(); // Pobierz przechwycone wyj�cie
    EXPECT_EQ("Wybierz odpowiedz: Czy na pewno chcesz zatwierdzic odpowiedz? (y/n)\nTest zakonczony.\n", output);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
