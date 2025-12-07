# Multitasking LED Control System using FreeRTOS on ESP32

This project demonstrates a research-oriented exploration of **real-time multitasking**, **task scheduling**, and **deterministic execution** using **FreeRTOS on ESP32**.  
Two independent LED-control tasks are executed in parallel, each configured with distinct timing behavior to showcase how an RTOS handles concurrency through task priorities and time-sliced scheduling.

## 🚀 Project Overview

Traditional microcontroller programs rely on delays and blocking loops, limiting responsiveness.  
This project implements a **FreeRTOS-based task framework** where each LED operates under its own real-time task, enabling:

- Parallel execution  
- Deterministic timing  
- Improved modularity  
- Real-time responsiveness  

The goal is to illustrate how embedded systems handle concurrent workloads using an RTOS kernel.

## 🧠 Key Features

- Two parallel FreeRTOS tasks controlling LEDs at different intervals  
- Demonstration of task priorities (e.g., high-frequency vs low-frequency tasks)  
- Use of vTaskDelay() for accurate time-based scheduling**  
- Non-blocking execution through cooperative multitasking  
- Clean modular code structure  
- Educational example for understanding scheduling behavior**



## 📁 Project Structure

