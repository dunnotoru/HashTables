#include <iostream>
#include <random>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <time.h>
#include "HashTableLinearProbing.h"
#include "HashTableDoubleHash.h"
#include "HashTableExternalHash.h"

std::unordered_set<int> generateNumbers(int count) {
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, count*10); 
	std::unordered_set<int> numbers;
	
	while (numbers.size() < count*2) {
		numbers.insert(dis(gen));
	}

	std::ofstream out("test_numbers.txt");
	for (const int& n: numbers) {
		out << n << std::endl;
	}
	out.close();

	return numbers;
}

struct TestResult {
	int successTotalTime = 0;
	int failTotalTime = 0;
	float successProbeAverage = 0;
	float failProbeAverage = 0;
};

std::vector<TestResult> testLinearHash(const std::vector<int>& numbers) {
	std::vector<TestResult> results;
	int size = numbers.size();
	for (int percent = 10; percent < 100; percent += 10) {
		TestResult result;
		
		HashTableLinearProbing table(size);
		
		int testSize = static_cast<int>(size * percent / 100);
		for (int i = 0; i < testSize; i++) {
			table.add(numbers[i]);
		}

		int start = clock();
		long probes_count = 0;
		for (int i = 0; i < testSize; i++) {
			table.isExists(numbers[i], probes_count);
		}
		int end = clock();
		result.successProbeAverage = static_cast<float>(probes_count) / testSize;
		result.successTotalTime = end - start;

		probes_count = 0;
		start = clock();
		for (int i = 0; i < testSize; i++) {
			table.isExists(size - i - 1, probes_count);
		}
		end = clock();
		result.failTotalTime = end - start;
		result.failProbeAverage = static_cast<float>(probes_count) / testSize;

		results.push_back(result);
	}
	

	return results;
}

int main()
{
	const int size = 1000003;

	std::vector<int> numbers;
	std::ifstream input("test_numbers.txt");
	int number;
	while (input >> number) {
		numbers.push_back(number);
	}

	input.close();

	std::vector<TestResult> results = testLinearHash(numbers);

	int generalSuccessTime = 0;
	int generalFailTime = 0;
	for (size_t i = 0; i < results.size(); i++) {
		TestResult a = results[i];
		std::cout << "percent: " << (i+1)*10 << std::endl;
		std::cout << "	success total time: " << a.successTotalTime << " ms" << std::endl;
		std::cout << "	fail total time: " << a.failTotalTime << " ms" << std::endl;
		std::cout << "	success average probes: " << a.successProbeAverage << std::endl;
		std::cout << "	fail average probes: " << a.failProbeAverage << std::endl;

		generalFailTime += a.failTotalTime;
		generalSuccessTime += a.successTotalTime;
	}
	std::cout << "general success time: " << generalSuccessTime << std::endl;
	std::cout << "general fail time: " << generalFailTime << std::endl;
}