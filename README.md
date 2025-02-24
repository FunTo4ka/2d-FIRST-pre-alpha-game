# 2D-FIRST-PRE-ALPHA-GAME

2D-FIRST-PRE-ALPHA-GAME is a simple 2D top-down game created as part of learning C++ programming using the SFML library. The game is in the early development stage (pre-alpha), so functionality may be limited, and bugs may be present.

## How to Run the Game

### Requirements

- C++ compiler (e.g., g++ or MinGW)
- Installed SFML library

### Instructions for Linux

1. Install SFML:

    ```bash
    sudo apt-get install libsfml-dev
    ```

2. Clone the repository or download the source code.

    ```bash
    git clone https://github.com/your-username/2D-FIRST-PRE-ALPHA-GAME.git
    ```

3. Navigate to the project folder:

    ```bash
    cd path/to/project
    ```

4. Compile the project:

    ```bash
    g++ main.cpp Player.cpp Enemy.cpp Fireball.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system
    ```

5. Run the game:

    ```bash
    ./game
    ```

### Instructions for Windows

1. Download and install SFML from the official website.

2. Ensure the compiler (e.g., MinGW) is configured to work with SFML.

3. Clone the repository or download the source code.

4. Navigate to the project folder:

    ```bash
    cd path/to/project
    ```

5. Compile the project:

    ```bash
    g++ main.cpp Player.cpp Enemy.cpp Fireball.cpp -o game.exe -IC:\SFML\include -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system
    ```

6. Run the game:

    ```bash
    game.exe
    ```

## Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **F**: Cast fireball (attack)

## Objective

- Survive as long as possible while avoiding enemies.
- Destroy enemies using fireballs.

Note: The game is in development, so objectives and mechanics may change in the future.
