/*
you get the point main lab cpp
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

class PointProcessor {
public:
    void addPoint(double x, double y) {
        points.push_back({x, y});
    }

    double calculateDistance(int index1, int index2) const {
        if (index1 < 0 || index1 >= points.size() || index2 < 0 || index2 >= points.size()) {
            cerr << "Invalid point index." << endl;
            return -1;
        }
        double x1 = points[index1].first;
        double y1 = points[index1].second;
        double x2 = points[index2].first;
        double y2 = points[index2].second;

        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    void printPoints() const {
        cout << "Stored Points:" << endl;
        for (int i = 0; i < points.size(); ++i) {
            cout << "Point " << i + 1 << ": (" << points[i].first << ", " << points[i].second << ")" << endl;
        }
    }

private:
    vector<pair<double, double>> points; 
};

int main() {
    PointProcessor processor;

    processor.addPoint(1.0, 2.0);
    processor.addPoint(4.0, 6.0);
    processor.addPoint(7.5, 1.2);

    processor.printPoints();

    double distance = processor.calculateDistance(0, 1);
    if (distance != -1) {
        cout << "Distance between Point 1 and Point 2: " << distance << endl;
    }

    distance = processor.calculateDistance(1, 2);
    if (distance != -1) {
        cout << "Distance between Point 2 and Point 3: " << distance << endl;
    }

    assert(processor.calculateDistance(0, 1) == sqrt(pow(4.0 - 1.0, 2) + pow(6.0 - 2.0, 2)));

    return 0;
}