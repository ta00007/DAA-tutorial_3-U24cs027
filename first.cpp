// // #include <iostream>
// // #include <cstdlib>
// // using namespace std;

// // int main() {
// //     int n;
// //     cout << "Enter the number of elements: ";
// //     cin >> n;

// //     // Dynamically allocate memory for the array
// //     int* arr = (int*)malloc(n * sizeof(int));

// //     cout << "Enter " << n << " elements:" << endl;
// //     for (int i = 0; i < n; i++) {
// //         cin >> arr[i];
// //     }

// //     // Initialize min and max with the first element
// //     int maxVal = arr[0];
// //     int minVal = arr[0];

// //     // Traverse array to find min and max
// //     for (int i = 1; i < n; i++) {
// //         if (arr[i] > maxVal) {
// //             maxVal = arr[i];
// //         }
// //         if (arr[i] < minVal) {
// //             minVal = arr[i];
// //         }
// //     }

// //     cout << "Maximum element = " << maxVal << endl;
// //     cout << "Minimum element = " << minVal << endl;

// //     // Free dynamically allocated memory
// //     free(arr);

// //     return 0;
// // }



// // #include <iostream>
// // using namespace std;

// // int main() {
// //     int n;
// //     cout << "Enter the number of elements: ";
// //     cin >> n;

// //     // Dynamically allocate memory for the array
// //     int *arr = new int[n];

// //     // Input array elements
// //     cout << "Enter " << n << " numbers:" << endl;
// //     for (int i = 0; i < n; i++) {
// //         cin >> arr[i];
// //     }

// //     // Display elements and calculate sum
// //     int sum = 0;
// //     cout << "The entered numbers are: ";
// //     for (int i = 0; i < n; i++) {
// //         cout << arr[i] << " ";
// //         sum += arr[i];
// //     }
// //     cout << endl;
// //     cout << "Sum of the numbers = " << sum << endl;

// //     // Free dynamically allocated memory
// //     delete[] arr;

// //     return 0;
// // }




// #include <bits/stdc++.h>
// using namespace std;
// void toh(int n, string source, string aux, string dest)
// {
//     if (n == 1)
//     {
//         cout << "Move disk 1 from " << source << " to " << dest << endl;
//         return;
//     }
//     toh(n - 1, source, dest, aux);
//     cout << "Move disk " << n << " from " << source << " to " << dest << endl;
//     toh(n - 1, aux, source, dest);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     // source aux dest
//     toh(n,"sour","aux","dest");
//     return 0;
// }


#include <iostream>
#include <conio.h>   // for _kbhit() and _getch()
#include <windows.h> // for Sleep()
#include <cstdlib>   // for rand()
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, foodX, foodY, score;
int tailX[100], tailY[100];  // FIXED: both arrays
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
    nTail = 0;
}

void Draw() {
    system("cls"); // clear the console

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "O";  // head of snake
            else if (i == foodY && j == foodX)
                cout << "F";  // food
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";  // snake tail
                        printTail = true;
                        break;
                    }
                }
                if (!printTail)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
            case 75: // left arrow
                dir = LEFT;
                break;
            case 'd':
            case 77: // right arrow
                dir = RIGHT;
                break;
            case 'w':
            case 72: // up arrow
                dir = UP;
                break;
            case 's':
            case 80: // down arrow
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default:    break;
    }

    // wrap around walls
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    // check collision with tail
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    // if snake eats food
    if (x == foodX && y == foodY) {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        nTail++;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);  // sleep 100 ms
    }
    cout << "Game Over!" << endl;
    cout << "Final Score: " << score << endl;
    return 0;
}
