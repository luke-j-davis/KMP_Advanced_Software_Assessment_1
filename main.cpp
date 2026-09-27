#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include <psapi.h>
#include <fstream>


#include "KMP.h"
#include "MyAlgorithm.h"
#include "Tests.h"
#include "Naive.h"

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
    size_t myMemory;

    double naiveTime;
    double kmpTime;
    double myTime;

    bool correct;

    long long naiveMemoryDiff;
    long long myMemoryDiff;

    double naiveTimeDiff;
    double myTimeDiff;
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
    // (MyAlgorithm)
    // ==============================================

    size_t memoryBeforeMy = getMemoryUsage();

    auto startMy = chrono::high_resolution_clock::now();

    
    vector<int> myResult = MyAlgorithm(text, pattern);

    auto endMy = chrono::high_resolution_clock::now();

    size_t memoryAfterMy = getMemoryUsage();


    double myTime =chrono::duration<double, milli>(endMy -startMy).count();

    size_t myMemory = memoryAfterMy - memoryBeforeMy;


/////Naive

size_t memoryBeforeNaive = getMemoryUsage();

    auto startNaive = chrono::high_resolution_clock::now();

    vector<int> naiveResult = Naive(text, pattern);

    auto endNaive = chrono::high_resolution_clock::now();

    size_t memoryAfterNaive = getMemoryUsage();

    double naiveTime =chrono::duration<double, milli>(endNaive - startNaive).count();

    size_t naiveMemory =
        memoryAfterNaive - memoryBeforeNaive;


    //end result collectecioon


    //grabbing first  that one of them didnt mess up
    // Check correctness
bool correct = (kmpResult == naiveResult && naiveResult == myResult);
// Differences from KMP
long long naiveMemoryDiff =
    (long long)naiveMemory - (long long)kmpMemory;

long long myMemoryDiff =
    (long long)myMemory - (long long)kmpMemory;

double naiveTimeDiff =
    naiveTime - kmpTime;

double myTimeDiff =
    myTime - kmpTime;

return {
    naiveMemory,
    kmpMemory,
    myMemory,

    naiveTime,
    kmpTime,
    myTime,

    correct,

    naiveMemoryDiff,
    myMemoryDiff,

    naiveTimeDiff,
    myTimeDiff
};

}


int main()
{
    std::vector<TestCase> tests = getTestCases();


    // Want to save the results somewhere
    std::ofstream outputFile("results.csv");

    outputFile << "Test,TextLength,PatternLength,"
               << "KMPTime,KMPMemory,"
               << "NaiveTime,NaiveMemory,"
               << "MyTime,MyMemory,"
               << "NaiveTimeDifference,MyTimeDifference,"
               << "NaiveMemoryDifference,MyMemoryDifference,"
               << "Correct\n";


    for (const TestCase& test : tests)
    {
        TestResult result = runTheTests(
            test.name,
            test.text,
            test.pattern
        );


        // ==============================================
        // Console output
        // ==============================================

        std::cout << "\n========================================\n";
        std::cout << test.name << "\n";

        std::cout << "Text length: "
                  << test.text.length() << "\n";

        std::cout << "Pattern length: "
                  << test.pattern.length() << "\n";


        // ----------------------------------------------
        // KMP
        // ----------------------------------------------

        std::cout << "\nKMP:\n";

        std::cout << "  Time: "
                  << result.kmpTime
                  << " ms\n";

        std::cout << "  Memory: "
                  << result.kmpMemory / 1024.0
                  << " KB\n";


        // ----------------------------------------------
        // Naive
        // ----------------------------------------------

        std::cout << "\nNaive:\n";

        std::cout << "  Time: "
                  << result.naiveTime
                  << " ms\n";

        std::cout << "  Memory: "
                  << result.naiveMemory / 1024.0
                  << " KB\n";


        // ----------------------------------------------
        // MyAlgorithm
        // ----------------------------------------------

        std::cout << "\nMyAlgorithm:\n";

        std::cout << "  Time: "
                  << result.myTime
                  << " ms\n";

        std::cout << "  Memory: "
                  << result.myMemory / 1024.0
                  << " KB\n";


        // ----------------------------------------------
        // Correctness
        // ----------------------------------------------

        std::cout << "\nCorrectness:\n";

        std::cout << "\nCorrect: "
          << (result.correct ? "YES" : "NO")
          << "\n";


        // ----------------------------------------------
        // Time differences
        // ----------------------------------------------

        std::cout << "\nTime difference from KMP:\n";

        std::cout << "  Naive - KMP: "
                  << result.naiveTimeDiff
                  << " ms\n";

        std::cout << "  MyAlgorithm - KMP: "
                  << result.myTimeDiff
                  << " ms\n";


        // ----------------------------------------------
        // Memory differences
        // ----------------------------------------------

        std::cout << "\nMemory difference from KMP:\n";

        std::cout << "  Naive - KMP: "
                  << result.naiveMemoryDiff / 1024.0
                  << " KB\n";

        std::cout << "  MyAlgorithm - KMP: "
                  << result.myMemoryDiff / 1024.0
                  << " KB\n";


        // ==============================================
        // Save to CSV
        // ==============================================

        outputFile << test.name << ","
                   << test.text.length() << ","
                   << test.pattern.length() << ","

                   << result.kmpTime << ","
                   << result.kmpMemory / 1024.0 << ","

                   << result.naiveTime << ","
                   << result.naiveMemory / 1024.0 << ","

                   << result.myTime << ","
                   << result.myMemory / 1024.0 << ","

                   << result.naiveTimeDiff << ","
                   << result.myTimeDiff << ","

                   << result.naiveMemoryDiff / 1024.0 << ","
                   << result.myMemoryDiff / 1024.0 << ","

                   << (result.correct ? "YES" : "NO")

                   << "\n";
    }


    outputFile.close();

    return 0;
}