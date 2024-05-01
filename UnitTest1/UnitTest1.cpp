#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../ap_12.7/Source.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Node* head = nullptr;
            head = addNode(head, 1.5);
            head = addNode(head, 2.0);
            head = addNode(head, 3.0);
            head = addNode(head, 4.0);
            head = addNode(head, 5.0);
            head = addNode(head, 6.0);

            rearrangeList(head);

            Assert::AreEqual(6.0, head->value);

            std::vector<double> expected_values = { 6.0, 1.5, 2.0, 3.0, 4.0, 5.0 };
            Node* current = head;
            size_t index = 0;
            while (current != nullptr) {
                Assert::AreEqual(expected_values[index], current->value);
                current = current->next;
                ++index;
            }
		}
	};
}
