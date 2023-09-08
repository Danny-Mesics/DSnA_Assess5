#include "pch.h"
#include "CppUnitTest.h"
#include "../Dynamic Array/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MostRecentLinkedListUnitTest
{
	TEST_CLASS(MostRecentLinkedListUnitTest)
	{
	public:
		
		TEST_METHOD(TestPushBack)
		{
			List testList;
			int testingValue = 17;

			for (int i = 0; i < 5; i++) {
				testList.PushFront(i);
			}

			testList.PushBack(testingValue);

			Assert::AreEqual(testList.Last(), testingValue);
		}

		TEST_METHOD(TestInsert)
		{
			List testList;
			int testingValue = 701;

			// Populate the list
			for (int i = 0; i < 5; i++) {
				testList.PushBack(i);
			}

			// Call Method to be tested
			testList.Insert(3, testingValue);


			// Check for correct equality
			for (auto i = testList.Begin(); i != testList.End(); i++) {
				if (*i == 3) {
					Assert::AreEqual(*(++i), testingValue);
				}
			}
		}

		TEST_METHOD(TestRemove) {

			List testList;
			int testingValue = 4;
			bool IsValuePresent = false; // A variable to check if the value is in the list

			for (int i = 0; i < 5; i++) {
				testList.PushBack(i);
			}

			// Remove is called on the number 4
			testList.Remove(testingValue);

			// This iteration should set IsValuePresent to true if the value has not been correctly removed
			for (auto i = testList.Begin(); i != testList.End(); i++) {
				if (*i == testingValue) {
					IsValuePresent = true;
				}
			}

			Assert::IsFalse(IsValuePresent);
		}
	};
}
