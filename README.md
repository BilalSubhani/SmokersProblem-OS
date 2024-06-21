# SmokersProblem-OS

This project simulates the classic synchronization problem known as the "Cigarette Smoker's Problem" using POSIX semaphores in C programming. The problem involves a dealer and three smokers who each require a unique combination of ingredients (represented as semaphores) to smoke a cigarette. The dealer randomly places two different ingredients on the table, and the smokers must then attempt to acquire the ingredients they need without deadlock.

## Main Features

- **Dealer Simulation**: Randomly selects two ingredients (represented by semaphores) and signals the smokers.
  
- **Smokers**: Three separate programs (`SmokerA.c`, `SmokerB.c`, `SmokerC.c`) each represent a smoker who waits for a specific combination of ingredients to be available, then smokes a cigarette.

- **POSIX Semaphores**: Used for synchronization between processes (`sem_post` for signaling, `sem_wait` for waiting), ensuring proper resource management.

## Getting Started

To run the simulation:

1. Compile each C file separately using a C compiler (e.g., gcc):
   ```bash
   gcc Dealer.c -o Dealer -pthread   # Compile Dealer.c
   gcc SmokerA.c -o SmokerA -pthread # Compile SmokerA.c
   gcc SmokerB.c -o SmokerB -pthread # Compile SmokerB.c
   gcc SmokerC.c -o SmokerC -pthread # Compile SmokerC.c

2.Run each compiled executable in separate terminal windows or tabs:
  ```bash
  ./Dealer   # Run the Dealer simulation
  ./SmokerA  # Run Smoker A simulation
  ./SmokerB  # Run Smoker B simulation
  ./SmokerC  # Run Smoker C simulation
  ```

## Further Information ℹ️

For more detailed explanations, including how semaphores are used for synchronization, check the [Wiki](../../wiki) of this repository.

## Support 🚀

If you encounter any issues or have questions, feel free to reach out by [email](mailto:mailatbilalsubhani@gmail.com).

## Contribute 🌟

Contributions are welcome! Fork the repository and submit a pull request with your enhancements.
