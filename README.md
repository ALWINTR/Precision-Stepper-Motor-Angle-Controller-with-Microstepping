# Precision Stepper Motor Angle Controller with Microstepping

<div align="center">

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-00f0ff?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ALWINTR/Precision-Stepper-Motor-Angle-Controller-with-Microstepping)
[![Developer](https://img.shields.io/badge/Developer-Alwin_T_R-0284c7?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alwintr)
[![Portfolio](https://img.shields.io/badge/Portfolio-alwintr.github.io-00f0ff?style=for-the-badge&logo=googlechrome&logoColor=black)](https://alwintr.github.io)
[![License](https://img.shields.io/badge/License-MIT-10b981?style=for-the-badge)](LICENSE)

</div>

> High-precision stepper motor positioning firmware implementing sub-degree angle mapping, linear frequency acceleration ramps, and serial CLI angle commands with 1/16 microstepping.

---

## 📌 Executive Overview

High-precision stepper motor positioning firmware implementing sub-degree angle mapping, linear frequency acceleration ramps, and serial CLI angle commands with 1/16 microstepping. This repository contains production-ready firmware implementations, hardware wiring pinouts, signal conditioning routines, and real-time telemetry pipelines engineered for reliable physical operation.

- **Primary Domain**: Embedded Firmware
- **Microcontroller & Hardware Core**: A4988 / Microstepping
- **Specialization**: Motion Control
- **Live Specs & BOM Viewer**: [alwintr.github.io](https://alwintr.github.io)

---

## 📐 System Architecture & Signal Flow

```
+--------------------------------------------------------------+
|            Serial Terminal CLI / Input Angle Target          |
+--------------------------------------------------------------+
        |
        | ASCII Angle Command ("MOVE 45.5")
        v
+--------------------------------------------------------------+
|                  Arduino Uno (ATmega328P)                    |
|  - Degree to Step Conversion   - Trapezoidal Frequency Ramp  |
|  - Microsecond Pulse Timers    - Backlash Compensation Engine|
+--------------------------------------------------------------+
        |
        | STEP (Pulse Frequency) & DIR (Direction Logic)
        v
+--------------------------------------------------------------+
|             A4988 Microstepping Bipolar Driver               |
|  (Configured for 1/16 Microstepping: MS1=H, MS2=H, MS3=H)    |
+--------------------------------------------------------------+
        |
        v 4-Phase Bipolar Current Control
+--------------------------------------------------------------+
|              NEMA 17 High-Torque Stepper Motor               |
+--------------------------------------------------------------+
```

---

## 📋 Hardware Bill of Materials (BOM)

| Component Name | Operating Voltage | Interface / Functionality |
| :--- | :--- | :--- |
| **Arduino Uno R3** | `5V DC` | Step timing microcontroller |
| **NEMA 17 Stepper Motor (17HS4401)** | `12V / 1.7A` | 1.8 deg per step |
| **Allegro A4988 Driver Board** | `12V VMOT / 5V VDD` | 1/16 microstepping |
| **100uF 35V Electrolytic Capacitor** | `Decoupling` | Motor power rail filter |

---

## 🔌 Circuit Pinout & Microcontroller Interconnect

| MCU Pin / Channel | Peripheral Pin | Signal Function / Bus |
| :--- | :--- | :--- |
| `Arduino Pin 3` | `A4988 STEP Pin` | Hardware Timer Step Pulse |
| `Arduino Pin 4` | `A4988 DIR Pin` | Direction Control Logic |
| `Arduino Pin 5, 6, 7` | `A4988 MS1, MS2, MS3` | Microstepping Selection |
| `Arduino Pin 8` | `A4988 ENABLE Pin` | Power Driver Enable Gate |

---

## ⚙️ Firmware Architecture & Control Logic

Integer math degree-to-step resolution mapping with Bresenham-style linear acceleration ramps preventing motor stalls and eliminating step losses.

### Key Firmware Capabilities:
- **Zero-Blocking Architecture**: Real-time non-blocking scheduling eliminating delay() deadlocks.
- **Hardware Interrupt Servicing**: Microsecond-precision edge-triggered pulse detection and safety shutoffs.
- **Diagnostic Telemetry**: Continuous serial datastreaming and state-machine transition logging.

---

## 📁 Repository Structure

```
Precision-Stepper-Motor-Angle-Controller-with-Microstepping/
├── .gitignore
├── LICENSE
├── Stepper_ULN2003.ino
└── README.md
```

---

## 🚀 Build & Deployment Instructions

### 1. Hardware Assembly
- Verify common system ground across all microcontrollers, drivers, and peripheral sensor boards.
- Ensure dedicated power supply rails match the operating voltage specified in the Hardware Bill of Materials.

### 2. Firmware Compilation & Flashing
```bash
# Clone the repository
git clone https://github.com/ALWINTR/Precision-Stepper-Motor-Angle-Controller-with-Microstepping.git

# Navigate to the project directory
cd Precision-Stepper-Motor-Angle-Controller-with-Microstepping
```

- Open the project in **Arduino IDE**, **PlatformIO**, or **ESP-IDF**.
- Select the target board configuration and COM port.
- Compile and upload firmware directly to the microcontroller.

---

## 👨‍💻 Author

**Alwin T R** — Robotics & Automation Engineer  
- 💼 **LinkedIn**: [linkedin.com/in/alwintr](https://www.linkedin.com/in/alwintr)  
- 🌐 **Interactive Portfolio**: [alwintr.github.io](https://alwintr.github.io)  
- 🐙 **GitHub**: [github.com/ALWINTR](https://github.com/ALWINTR)  
- ✉️ **Direct Email**: [alwintr2003@gmail.com](mailto:alwintr2003@gmail.com)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.
