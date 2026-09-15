# ⚙️ Stepper Motor Precise Angle Positioning & Microstepping Controller

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-00f0ff?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ALWINTR/stepper-motor-angle-controller)
[![Developer](https://img.shields.io/badge/Developer-Alwin_T_R-0284c7?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alwintr)
[![Platform](https://img.shields.io/badge/Platform-Arduino_&_A4988_Stepper-38bdf8?style=for-the-badge&logo=espressif&logoColor=white)](https://github.com/ALWINTR)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

Precision stepper motor angle positioning and microstepping acceleration firmware for Arduino and A4988/ULN2003.

---

## 📌 Overview & Motion Control Architecture

A high-precision motion control library and firmware for bipolar (NEMA 17) and unipolar (28BYJ-48) stepper motors, delivering smooth trapezoidal acceleration ramping, degree-to-step resolution mapping, and serial angle positioning commands.

```
       ┌──────────────────────────────┐
       │  Target Angle Command (0-360)│
       └──────────────┬───────────────┘
                      │
                      ▼
       ┌──────────────────────────────┐
       │  Step Calculation Engine     │
       │  Steps = (Angle / 1.8°) * MS │
       └──────────────┬───────────────┘
                      │
                      ▼
       ┌──────────────────────────────┐
       │ Trapezoidal Acceleration RAMP│
       │ • Linear Frequency Stepping  │
       │ • Minimized Inertial Jitter  │
       └──────────────────────────────┘
```

---

## ⚙️ Hardware Components & Drivers

| Component | Technical Specification | Function |
| :--- | :--- | :--- |
| **Microcontroller** | Arduino Uno / Nano (ATmega328P) | Precision timer pulse generation |
| **Stepper Motor** | NEMA 17 (1.8° Step Angle, 200 Steps/Rev) | High-torque mechanical positioning |
| **Driver Module** | A4988 / DRV8825 Microstepping Driver | Up to 1/16 (A4988) or 1/32 (DRV8825) Microstepping |
| **Power Supply** | 12V 2A Regulated DC Power Supply | Motor coil driving rail (with 100µF capacitor) |

---

## 🔌 Circuit Pinout Table (A4988 Driver)

| A4988 Pin | Arduino Pin | Description |
| :--- | :--- | :--- |
| **STEP** | Digital Pin D3 | Step pulse input (High-to-Low transition) |
| **DIR** | Digital Pin D4 | Direction control (HIGH = CW, LOW = CCW) |
| **ENABLE** | Digital Pin D5 | Motor coil energize (Active LOW) |
| **MS1, MS2, MS3** | Digital Pins D6, D7, D8 | Microstepping resolution selector |
| **VMOT / GND** | External 12V / GND | Motor power rail with 100µF bulk capacitor |

---

## 👨‍💻 Author

**Alwin T R** — Robotics & Automation Engineer  
- 💼 LinkedIn: [linkedin.com/in/alwintr](https://www.linkedin.com/in/alwintr)  
- 🌌 Portfolio: [alwintr.github.io](https://alwintr.github.io)  
- 💻 GitHub: [github.com/ALWINTR](https://github.com/ALWINTR)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.
