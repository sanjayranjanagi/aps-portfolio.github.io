#include <iostream>
#include <unordered_map>
#include <vector>

struct Job {
    std::string title;
    std::string company;
    std::vector<std::string> skills;
};

int main() {
    std::unordered_map<std::string, std::vector<Job>> jobTable;
    Job job1 = {"Software Engineer", "TechCorp", {"C++", "Algorithms", "Data Structures"}};
    jobTable["Software Engineer"].push_back(job1);

    // Searching for a job
    std::string searchKeyword = "Software Engineer";
    if (jobTable.find(searchKeyword) != jobTable.end()) {
        for (const auto& job : jobTable[searchKeyword]) {
            std::cout << "Title: " << job.title << ", Company: " << job.company << "\n";
        }
    } else {
        std::cout << "No jobs found for " << searchKeyword << "\n";
    }
    return 0;
}
