#include "pch.h"
#include "CppUnitTest.h"

#include "Aquarium.h"
#include "FishBeta.h"
#include "DecorCastle.h"
#include <memory>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CAquariumTest)
	{
	public:
		/**
		* Create a path to a place to put temporary files
		*/
		wstring TempPath()
		{
			// Create a path to temporary files
			wchar_t path_nts[MAX_PATH];
			GetTempPath(MAX_PATH, path_nts);

			// Convert null terminated string to wstring
			return wstring(path_nts);
		}

		/**
		* Read a file into a wstring and return it.
		* \param filename Name of the file to read
		* \return File contents
		*/
		wstring ReadFile(const wstring& filename)
		{
			ifstream t(filename);
			wstring str((istreambuf_iterator<char>(t)),
				istreambuf_iterator<char>());

			return str;
		}

		/**
		* Test to ensure an aquarium .aqua file is empty
		*/
		void TestEmpty(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			Assert::IsTrue(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua/>")));

		}

		/**
		 *  Populate an aquarium with three Beta fish
		 */
		void PopulateThreeBetas(CAquarium* aquarium)
		{
			const unsigned int RandomSeed = 1238197374;
			srand(RandomSeed);

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
			fish1->SetLocation(100, 200);
			aquarium->Add(fish1);

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(aquarium);
			fish2->SetLocation(400, 400);
			aquarium->Add(fish2);

			shared_ptr<CFishBeta> fish3 = make_shared<CFishBeta>(aquarium);
			fish3->SetLocation(600, 100);
			aquarium->Add(fish3);
		}

		void TestThreeBetas(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml,
				wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
			
		}

		void TestSpeed(wstring filename)
		{
			const unsigned int RandomSeed = 1238197374;
			srand(RandomSeed);

			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

			// Ensure that the speed are correct
			Assert::IsTrue(regex_search(xml, wregex(L"speedX=\"0\\.741508224738304\" speedY=\"0\\.509628589739677\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"speedX=\"0\\.625080111087374\" speedY=\"0\\.893917661061434\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"speedX=\"0\\.118320261238441\" speedY=\"0\\.222876674703207\"")));
		}

		void PopulateAllTypes(CAquarium* aquarium)
		{
			const unsigned int RandomSeed = 1238197374;
			srand(RandomSeed);

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
			fish1->SetLocation(100, 200);
			aquarium->Add(fish1);

			shared_ptr<CCatFish> fish2 = make_shared<CCatFish>(aquarium);
			fish2->SetLocation(400, 400);
			aquarium->Add(fish2);

			shared_ptr<CAngelFish> fish3 = make_shared<CAngelFish>(aquarium);
			fish3->SetLocation(600, 100);
			aquarium->Add(fish3);

			shared_ptr<CDecorCastle> fish4 = make_shared<CDecorCastle>(aquarium);
			fish4->SetLocation(300, 100);
			aquarium->Add(fish4);
		}

		void TestAllTypes(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

			// Ensure the positions are correct
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"300\" y=\"100\"")));

			// Ensure the types are correct
			Assert::IsTrue(regex_search(xml, wregex(L"type=\"beta\"/>")));
			Assert::IsTrue(regex_search(xml, wregex(L"type=\"catfish\"/>")));
			Assert::IsTrue(regex_search(xml, wregex(L"type=\"angelfish\"/>")));
			Assert::IsTrue(regex_search(xml, wregex(L"type=\"castle\"/></aqua>")));
		}

		void TestAllTypeSpeed(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure three items
			Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

			// Ensure that the speed are correct
			Assert::IsTrue(regex_search(xml, wregex(L"speedX=\"1\\.25125888851588E-03\" speedY=\"0\\.56358531449324\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"speedX=\"0\\.193304239020966\" speedY=\"0\\.808740501113926\"")));
			Assert::IsTrue(regex_search(xml, wregex(L"speedX=\"0\\.58500930814539\" speedY=\"0\\.47987304300058\"")));
		}

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCAquariumConstruct)
		{
			CAquarium aquarium;
		}

		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;

			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1,
				L"Testing fish at 100, 200");
		}

		TEST_METHOD(TestCAquariumOverlapTest) 
		{
			CAquarium aquarium;

			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish2->SetLocation(100, 200);
			aquarium.Add(fish2);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish2,
				L"Testing fish1 and fish2 at 100, 200");
		}

		TEST_METHOD(TestCAquariumToEndTest)
		{
			CAquarium aquarium;

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish2->SetLocation(100, 200);
			aquarium.Add(fish2);

			Assert::IsTrue(aquarium.ToEndTest(fish2));
			Assert::IsFalse(aquarium.ToEndTest(fish1));

			aquarium.ToEnd(fish1);
			Assert::IsTrue(aquarium.ToEndTest(fish1));
			Assert::IsFalse(aquarium.ToEndTest(fish2));
		}

		TEST_METHOD(TestCAquariumSave)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create an aquarium
			CAquarium aquarium;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";
			aquarium.Save(file1);

			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);

			TestThreeBetas(file2);
			TestSpeed(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);

			TestAllTypes(file3);
			TestSpeed(file3);
		}

		TEST_METHOD(TestCAquariumClear)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			CAquarium aquarium;

			wstring file1 = path + L"test1.aqua";
			aquarium.Save(file1);

			// File should be empty since nothing is added
			TestEmpty(file1);

			// Add all types to file then save
			PopulateAllTypes(&aquarium);
			aquarium.Save(file1);

			// Test if it is successfully added
			TestAllTypes(file1);
			TestSpeed(file1);

			// Clear all type then save
			aquarium.Clear();
			aquarium.Save(file1);

			// File should be empty again
			TestEmpty(file1);

		}

		TEST_METHOD(TestCAquariumLoad)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create two aquariums
			CAquarium aquarium, aquarium2;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";

			aquarium.Save(file1);
			TestEmpty(file1);

			aquarium2.Load(file1);
			aquarium2.Save(file1);
			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);
			TestThreeBetas(file2);
			TestSpeed(file2);

			aquarium2.Clear();

			aquarium2.Load(file2);
			aquarium2.Save(file2);
			TestThreeBetas(file2);
			TestSpeed(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);
			TestAllTypes(file3);
			TestSpeed(file3);

			aquarium3.Clear();

			aquarium2.Load(file3);
			aquarium2.Save(file3);
			TestAllTypes(file3);
			TestSpeed(file3);
		}
	};
}