#include "pch.h"
#include "CppUnitTest.h"
#include"../lab1 sem 4 DSnA/map.h"
#include"../lab1 sem 4 DSnA/RBTree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1sem4
{
	TEST_CLASS(lab1sem4)
	{
	public:

		TEST_METHOD(TestColor)
		{
			RBTree<int, int> tree;
			tree.insert(10, 10);
			tree.insert(13, 13);
			tree.insert(8, 8);
			Assert::AreEqual(1, tree.findElem(10)->getColor());
			Assert::AreEqual(0, tree.findElem(13)->getColor());
			Assert::AreEqual(0, tree.findElem(8)->getColor());
		}
		TEST_METHOD(TestGetKeys)
		{
			Map<int, int> tree;
			tree.insert(10, 10);
			tree.insert(13, 13);
			tree.insert(8, 8);
			auto key = tree.getkeys();//10-8-13
			Assert::AreEqual(10, key->head->data);
			Assert::AreEqual(8, key->head->next->data);
			Assert::AreEqual(13, key->tail->data);
		}

		TEST_METHOD(TestGetValues)
		{
			Map<int, int> tree;
			tree.insert(10, 10);
			tree.insert(13, 13);
			tree.insert(8, 8);
			auto value = tree.getValues();//10-8-13
			Assert::AreEqual(10, value->head->data);
			Assert::AreEqual(8, value->head->next->data);
			Assert::AreEqual(13, value->tail->data);
		}
		TEST_METHOD(TestFind)
		{
			Map<int, int> tree;
			tree.insert(10, 9);
			tree.insert(13, 11);
			tree.insert(8, 7);
			Assert::AreEqual(9, tree.find(10));
			Assert::AreEqual(11, tree.find(13));
			Assert::AreEqual(7, tree.find(8));
			Assert::AreEqual(0, tree.find(132));
		}
		TEST_METHOD(TestRemove)
		{
			Map<int, int> tree;
			tree.insert(10, 10);
			tree.insert(13, 13);
			tree.insert(8, 8);
			tree.insert(15, 15);
			tree.remove(15);
			auto value = tree.getValues();//10-8-13
			Assert::AreEqual(10, value->head->data);
			Assert::AreEqual(8, value->head->next->data);
			Assert::AreEqual(8, value->tail->prev->data);
			Assert::AreEqual(13, value->tail->data);
		}
		TEST_METHOD(TestClear)
		{
			Map<int, int> tree;
			tree.insert(10, 10);
			tree.insert(13, 13);
			tree.insert(8, 8);
			tree.insert(15, 15);
			tree.clear();
			tree.insert(1, 1);
			auto value = tree.getValues();
			auto key = tree.getkeys(); 
			Assert::AreEqual(1, value->head->data);
			Assert::AreEqual(1, value->tail->data);
		}
	};
}
