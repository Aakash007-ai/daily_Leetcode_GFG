#include <iostream>
#include <vector>
#include <algorithm>

enum class PotholeState {
    POTHOLE = 1,
    CLEAN = 2
};

std::vector<std::vector<PotholeState>> readLanes(const std::string& l1, const std::string& l2) {
    std::vector<std::vector<PotholeState>> result(2, std::vector<PotholeState>(l1.size()));

    for (size_t i = 0; i < l1.size(); ++i) {
        result[0][i] = (l1[i] == 'x') ? PotholeState::POTHOLE : PotholeState::CLEAN;
        result[1][i] = (l2[i] == 'x') ? PotholeState::POTHOLE : PotholeState::CLEAN;
    }

    return result;
}

int maxRepairableHelper(const std::vector<PotholeState>& lane1, const std::vector<PotholeState>& lane2) {
    std::vector<int> avoidedPotholes1(lane1.size(), 0);
    std::vector<int> avoidedPotholes2(lane2.size(), 0);

    for (int i = static_cast<int>(lane1.size()) - 2; i >= 0; --i) {
        avoidedPotholes1[i] = avoidedPotholes1[i + 1] + (lane1[i + 1] == PotholeState::POTHOLE);
    }

    for (size_t i = 1; i < lane2.size(); ++i) {
        avoidedPotholes2[i] = avoidedPotholes2[i - 1] + (lane2[i - 1] == PotholeState::POTHOLE);
    }

    int maxRepairable = 0;
    for (size_t i = 0; i < lane1.size(); ++i) {
        maxRepairable = std::max(maxRepairable, avoidedPotholes1[i] + avoidedPotholes2[i]);
    }

    return maxRepairable;
}

int maxRepairableSegments(const std::vector<std::vector<PotholeState>>& road) {
    const auto& lane1 = road[0];
    const auto& lane2 = road[1];

    return std::max(maxRepairableHelper(lane1, lane2), maxRepairableHelper(lane2, lane1));
}

int main() {
    std::string l1 = "xx.x";
    std::string l2 = "..x.";

    std::vector<std::vector<PotholeState>> road = readLanes(l1, l2);

    int result = maxRepairableSegments(road);

    std::cout << "Max repairable segments: " << result << std::endl;

    return 0;
}
