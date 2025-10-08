# ⚡ DVFS Simulator (C++)

A **Dynamic Voltage and Frequency Scaling (DVFS)** simulator written in **C++**, modeling how modern processors save power by dynamically adjusting **clock frequency** and **supply voltage** based on CPU load or thermal conditions.  

This project demonstrates how **hardware-aware power management** works inside real processors — such as those in laptops, smartphones, and data centers — without requiring any actual hardware.  

---

## 🚀 Highlights

✅ Models CPU frequency & voltage levels  
✅ Simulates workload-dependent scaling  
✅ Tracks power and energy consumption  
✅ Temperature-based throttling (thermal awareness)  
✅ AI-assisted data visualization with Python  
✅ Educational and research-friendly (no hardware required)

---

## 🧠 Concept Overview

**Dynamic Voltage and Frequency Scaling (DVFS)** is a technique used in modern CPUs and SoCs to **reduce power consumption** and **heat generation** by lowering the frequency and voltage when the system load is low.

### 🔋 Power Equation

The total dynamic power consumed by a CPU is approximately:

> **P = C × V² × f**

Where:
- `C` = Capacitance load  
- `V` = Supply voltage  
- `f` = Clock frequency  

Reducing `V` or `f` lowers power consumption quadratically.

---

## ⚙️ Features Simulated

| Feature | Description |
|:--|:--|
| 🕒 Frequency Scaling | CPU frequency changes based on workload |
| 🔌 Voltage Scaling | Voltage changes proportional to frequency |
| 🌡️ Thermal Throttling | Temperature limits maximum frequency |
| 📈 Power Tracking | Computes instantaneous and total energy |
| 🧮 Efficiency Metrics | Shows performance per watt |
| 🧠 AI Visualization | Animated frequency–power relationship |

---

## 📂 Repository Structure
```
DVFS_Simulator/
│
├── dvfs_simulator.cpp # Main C++ simulation code
├── config.txt # Optional: pre-defined workload pattern
├── results.csv # Simulation log (auto-generated)
├── visualize_dvfs.py # Python visualization (AI-assisted)
└── README.md # Documentation
```

---

## ⚙️ How to Compile and Run

### 1️⃣ Compile

```bash
g++ dvfs_simulator.cpp -o dvfs_simulator
```
### 2️⃣ Run Simulation
```
./dvfs_simulator
```

### 🧾 Output

### 📊 Data Logging

Each simulation step is recorded into results.csv with:

Time, Workload, Frequency(GHz), Voltage(V), Power(W), Energy(J), Temperature(C)
0, 30, 1.0, 0.9, 9.3, 9.3, 45
1, 65, 2.0, 1.1, 23.8, 33.1, 58
...

### 📈 AI-Assisted Visualization (Python)

Visualize how the system dynamically scales frequency and power.

Install Requirements
```
pip install pandas matplotlib
``` 
Run
```
python visualize_dvfs.py
```
Output
```
Animated line plot showing frequency, power, and temperature over time
```
Optional AI-based trend prediction (future scaling behavior)

🧮 Example DVFS Policy (Simplified)
Workload (%)	Frequency (GHz)	Voltage (V)	Mode
0–30	0.8	0.85	Power Save
31–70	1.6	1.0	Balanced
71–100	2.2	1.15	Performance

You can modify this logic inside dvfs_simulator.cpp for experimentation.

🔬 Educational Value

This simulator helps you understand:

How hardware and firmware manage performance and energy

What parameters affect CPU power efficiency

How DVFS contributes to thermal management

How embedded power control algorithms work in real systems

🧠 Possible Extensions

Add PID-based temperature control

Integrate real workload traces (CSV input)

Add AI-based predictive DVFS policy

Implement battery modeling

Connect with a GUI dashboard (React + Flask)

🧑‍💻 Author

Amirtha K
Final-year ECE Student | Embedded Systems & AI Enthusiast


🪪 License

This project is released under the MIT License — free for educational and research use.
