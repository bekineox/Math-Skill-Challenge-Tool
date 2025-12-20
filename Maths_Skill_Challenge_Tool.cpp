#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

struct Question {
    string text;
    double correctAnswer;
    double userAnswer;
    bool isCorrect;
};

int difficulty;
Question questions[10];
int score = 0;

int generateNumber() {
    if (difficulty == 1) return rand() % 10 + 1;
    if (difficulty == 2) return rand() % 91 + 10;
    return rand() % 900 + 100;
}

void generateQuestions() {
    for (int i = 0; i < 10; i++) {
        int a = generateNumber();
        int b = generateNumber();
        int op = rand() % 6;

        switch (op) {
            case 0:
                questions[i].text = to_string(a) + " + " + to_string(b);
                questions[i].correctAnswer = a + b;
                break;

            case 1:
                questions[i].text = to_string(a) + " - " + to_string(b);
                questions[i].correctAnswer = a - b;
                break;

            case 2:
                questions[i].text = to_string(a) + " * " + to_string(b);
                questions[i].correctAnswer = a * b;
                break;

            case 3: {
                int exp = rand() % 3 + 2;
                questions[i].text = to_string(a) + "^" + to_string(exp);
                questions[i].correctAnswer = pow(a, exp);
                break;
            }

            case 4:
                questions[i].text = "sqrt(" + to_string(a) + ")";
                questions[i].correctAnswer = sqrt(a);
                break;

            case 5:
                questions[i].text = to_string(a) + " % " + to_string(b);
                questions[i].correctAnswer = a % b;
                break;
        }
    }
}

void startQuiz() {
    score = 0;

    for (int i = 0; i < 10; i++) {
        cout << "\n------------------------------------------------------------\n";
        cout << " Question " << i + 1 << " of 10";
        cout << "                 Difficulty: ";
        if (difficulty == 1) cout << "Easy";
        else if (difficulty == 2) cout << "Medium";
        else cout << "Hard";
        cout << "\n------------------------------------------------------------\n";

        cout << "\n   " << questions[i].text << " = ";
        cin >> questions[i].userAnswer;

        double diff = abs(questions[i].userAnswer - questions[i].correctAnswer);

        if (diff < 0.001) {
            cout << "   Correct.\n";
            questions[i].isCorrect = true;
            score++;
        } else {
            cout << "   Incorrect. Correct answer: " << questions[i].correctAnswer << endl;
            questions[i].isCorrect = false;
        }

        cout << "   Progress: " << i + 1 << " out of 10 completed.\n";
    }
}

void showResults() {
    cout << "\n============================================================\n";
    cout << "|                           RESULTS                          |\n";
    cout << "============================================================\n";

    cout << " Score    : " << score << " / 10" << endl;
    double accuracy = (score / 10.0) * 100;
    cout << " Accuracy : " << accuracy << "%\n";

    cout << " Difficulty Level : ";
    if (difficulty == 1) cout << "Easy\n";
    else if (difficulty == 2) cout << "Medium\n";
    else cout << "Hard\n";

    cout << "\n------------------------------------------------------------\n";
    cout << " Detailed Breakdown:\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        cout << " " << i + 1 << ") " << questions[i].text
             << " \t Correct answer: " << questions[i].correctAnswer
             << " \t Your answer: " << questions[i].userAnswer
             << (questions[i].isCorrect ? " [Correct]" : " [Incorrect]") << endl;
    }

    cout << "------------------------------------------------------------\n";
    cout << " Thank you for playing!\n";
}

int main() {
    int choice;

    cout << "\n============================================================\n";
    cout << "|                                                          |\n";
    cout << "|                    M A T H   Q U I Z                     |\n";
    cout << "|                                                          |\n";
    cout << "============================================================\n";
    cout << "\n   ***** Welcome to the Ultimate Math Quiz System   *****\n\n";

    do {
        cout << "\n+----------------------------------------------------------+\n";
        cout << "|                        MAIN MENU                          |\n";
        cout << "+-----------------------------------------------------------+\n";
        cout << "\n   [1]  Start Quiz\n";
        cout << "   [2]  Exit Program\n";
        cout << "\n------------------------------------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        while (choice < 1 || choice > 2) {
            cout << "Choice out of range. Please enter 1–2: ";
            cin >> choice;
        }

        if (choice == 1) {
            cout << "\nSelect difficulty level (1-Easy, 2-Medium, 3-Hard): ";
            cin >> difficulty;

            while (difficulty < 1 || difficulty > 3) {
                cout << "Level out of range. Please enter 1–3: ";
                cin >> difficulty;
            }

            generateQuestions();
            startQuiz();
            showResults();
        }

    } while (choice != 2);

    cout << "\nGoodbye!\n";
    return 0;
}
