#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include <psapi.h>


#include "KMP.h"
#include "MyAlgorithm.h"
#include "Tests.h"

using namespace std;
// --------------------------------------------------
// Get current memory usage
// --------------------------------------------------

size_t getMemoryUsage()
{
    PROCESS_MEMORY_COUNTERS pmc;

    GetProcessMemoryInfo(
        GetCurrentProcess(),
        &pmc,
        sizeof(pmc)
    );

    return pmc.WorkingSetSize;
}

//so I can output  the test results
struct TestResult
{
    size_t naiveMemory;
    size_t kmpMemory;

    double naiveTime;
    double kmpTime;

    bool correct;

    long long memoryDiff;
    double timeDiff;
};
//as we want everything in one
TestResult runTheTests(const string& testName, const string& text, const string& pattern)
{

// ==============================================
    // KMP
    // ==============================================

    size_t memoryBeforeKMP = getMemoryUsage();

    auto startKMP = chrono::high_resolution_clock::now();

    vector<int> kmpResult = KMP(text, pattern);

    auto endKMP = chrono::high_resolution_clock::now();

    size_t memoryAfterKMP = getMemoryUsage();


    double kmpTime =
        chrono::duration<double, milli>(
            endKMP - startKMP
        ).count();

    size_t kmpMemory =
        memoryAfterKMP - memoryBeforeKMP;


    // ==============================================
    // Naive(MyAlgorithm)
    // ==============================================

    size_t memoryBeforeNaive = getMemoryUsage();

    auto startNaive = chrono::high_resolution_clock::now();

    
    vector<int> myResult = MyAlgorithm(text, pattern);

    auto endNaive = chrono::high_resolution_clock::now();

    size_t memoryAfterNaive = getMemoryUsage();


    double naiveTime =
        chrono::duration<double, milli>(
            endNaive - startNaive
        ).count();

    size_t naiveMemory = memoryAfterNaive - memoryBeforeNaive;





    //end result collectecioon


    //grabbing first  that one of them didnt mess up
    bool correct = (kmpResult == myResult);

    long long memoryDiff=(long long)naiveMemory - (long long)kmpMemory;

    auto timeDiff = naiveTime - kmpTime;

    return {
    naiveMemory,
    kmpMemory,
    naiveTime,
    kmpTime,
    correct,
    memoryDiff,
    timeDiff
   };

}


int main()
{
   std::vector<TestCase> tests = getTestCases();

    for (const TestCase& test : tests)
    {
        TestResult result = runTheTests(
            test.name,
            test.text,
            test.pattern
        );

        std::cout << "\n========================================\n";
        std::cout << test.name << "\n";
        std::cout << "Text length: " << test.text.length() << "\n";
        std::cout << "Pattern length: " << test.pattern.length() << "\n";

        std::cout << "\nKMP:\n";
        std::cout << "  Time: "
                  << result.kmpTime << " ms\n";

        std::cout << "  Memory: "
                  << result.kmpMemory / 1024.0 << " KB\n";

        std::cout << "\nMyAlgorithm:\n";
        std::cout << "  Time: "
                  << result.naiveTime << " ms\n";

        std::cout << "  Memory: "
                  << result.naiveMemory / 1024.0 << " KB\n";

        std::cout << "\nCorrect: "
                  << (result.correct ? "YES" : "NO")
                  << "\n";

        std::cout << "Time difference: "
                  << result.timeDiff << " ms\n";

        std::cout << "Memory difference: "
                  << result.memoryDiff / 1024.0 << " KB\n";
    }

    return 0;

}