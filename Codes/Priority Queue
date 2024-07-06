#include <iostream>
#include <queue>
#include <vector>

struct Candidate {
    std::string name;
    int score; // higher score means better candidate

    bool operator<(const Candidate& other) const {
        return score < other.score;
    }
};

int main() {
    std::priority_queue<Candidate> candidates;
    candidates.push({"Alice", 95});
    candidates.push({"Bob", 85});
    candidates.push({"Charlie", 90});

    // Hiring the best candidate
    if (!candidates.empty()) {
        Candidate bestCandidate = candidates.top();
        std::cout << "Hired: " << bestCandidate.name << "\n";
    } else {
        std::cout << "No candidates available\n";
    }
    return 0;
}
