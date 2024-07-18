# LCD driver library

## About

This repository contains a library that allows the tms320F28069M to use a 1602 V1.2 LCD screen. This screen came from an arduino kit, and the library was created by looking through the data sheet

### Built With

IDE: Code Composer Studio v12
Compiler: TI v22.6.1 LTS

## Target

Microcontroller: Texas Instruments TMS320F28069M

## Project Structure

The project is structured as a Code Composer Studio project.

### Prerequisites

1. Download Code Composer Studio.
2. Obtain a tms320F28069M
3. Obtain a 1602A V1.2 LCD screen

### Opening the Project

To run the project for development:

1. Clone the repo
2. Open Code Composer Studio at the directory the repository is located in such as `C:\MyProjects\LCD\`
3. Import the project

### Running the Project for Development

To run the project for development:

1. From Code Composer Studio, click Build (hammer icon).
2. Attach a XDS510USB debugger to the development board.
3. Click Debug (bug icon).
4. After the target has been flashed, click the start button (play icon).
5. This screen should show up in the serial terminal, follow directions to change wave.
![image](https://github.com/user-attachments/assets/20328408-a91d-4a27-ae49-3265f13b7e54)


### Running the Tests

Unit tests currently aren't integrated into this project.

### Workflow

The development workflow used to develop this project is [GitHub Flow](https://docs.github.com/en/get-started/quickstart/github-flow).

In summary:

1. Create a branch.
2. Make changes.
3. Create a Pull Request.
4. Address Review Comments.
5. Merge your Pull Request.
6. Delete your branch.
   
## Acknowledgements

This project has been developed by Ethan Robotham.
