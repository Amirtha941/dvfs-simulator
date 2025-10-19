#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

struct CPUState {
    double workload;   // percentage (0–100)
    double frequency;  // GHz
    double voltage;    // V
    double power;      // W
};

// Function to compute power (simplified)
double computePower(double voltage, double frequency) {
    return pow(voltage, 2) * frequency * 10; // scale factor for visualization
}

// Function to adapt voltage based on frequency (approx model)
double getVoltage(double frequency) {
    if (frequency <= 1.0) return 0.9;
    else if (frequency <= 2.0) return 1.0;
    else if (frequency <= 3.0) return 1.1;
    else return 1.2;
}

int main() {
    srand(time(0));

    vector<CPUState> history;
    double freq = 2.0; // start at 2GHz

    cout << "=== Dynamic Power Management Simulator (DVFS) ===" << endl;
    cout << "Simulating CPU power-frequency adaptation..." << endl;

    ofstream logfile("dvfs_log.csv");
    logfile << "Step,Workload(%),Frequency(GHz),Voltage(V),Power(W)\n";

    for (int step = 1; step <= 50; step++) {
        double workload = rand() % 101; // 0–100%

        // Adjust frequency based on workload
        if (workload > 70 && freq < 3.5) freq += 0.2; // scale up
        else if (workload < 30 && freq > 0.8) freq -= 0.2; // scale down

        freq = round(freq * 10) / 10.0; // round to 0.1GHz

        double voltage = getVoltage(freq);
        double power = computePower(voltage, freq);

        CPUState state = {workload, freq, voltage, power};
        history.push_back(state);

        logfile << step << "," << workload << "," << freq << "," << voltage << "," << power << "\n";

        cout << "Step " << step << " | Workload: " << workload << "% | Freq: " << freq
             << " GHz | Volt: " << voltage << " V | Power: " << power << " W" << endl;

        this_thread::sleep_for(chrono::milliseconds(200)); // slow for readability
    }

    logfile.close();
    cout << "\nSimulation complete! Data saved in 'dvfs_log.csv'.\n";
    cout << "You can plot it using Python, Excel, or Google Sheets.\n";

    return 0;
}
