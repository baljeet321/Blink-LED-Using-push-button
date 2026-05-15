# Blink LED Using Push Button

Simple bare-metal STM32 project using direct register manipulation.

## Board

* STM32 NUCLEO-F446RE

## GPIO Mapping

| Component        | Pin  |
| ---------------- | ---- |
| LED (LD2)        | PA5  |
| USER Button (B1) | PC13 |

## Functionality

* Press button → LED ON
* Release button → LED OFF

## Concepts Used

* RCC clock enable
* GPIO MODER
* GPIO IDR
* GPIO ODR
* Bit masking
* Bare-metal programming

## Build & Run

1. Open project in STM32CubeIDE
2. Connect board using USB
3. Build project
4. Flash and run

## Demo Video

https://github.com/user-attachments/assets/e66f6882-a6b3-424d-802b-b779d809216e

## Author

Baljeet Singh
