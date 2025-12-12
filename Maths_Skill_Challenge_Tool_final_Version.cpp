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

class MathQuiz {
private:
    int difficulty;
    Question questions[10];
    int score;

public:
    MathQuiz() {
        difficulty = 1;
        score = 0;
    }

    void setDifficulty(int level) {
        difficulty = level;
    }

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

            if (difficulty == 3 && rand() % 2 == 0) {
                int c = generateNumber();
                questions[i].text += " + " + to_string(c);
                questions[i].correctAnswer += c;
            }
        }
    }

    void startQuiz() {
        int* scorePtr = &score;

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
                (*scorePtr)++;
            } else {
                cout << "   Incorrect. Correct answer: " << questions[i].correctAnswer << endl;
                questions[i].isCorrect = false;
            }

            cout << "   Progress: " << i + 1 << " out of 10 completed.\n";
        }
    }

    void showResults(string username) {
        cout << "\n============================================================\n";
        cout << "|                           RESULTS                          |\n";
        cout << "============================================================\n";

        cout << "\n Username : " << username << endl;
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

    void showHelp() {
        cout << "\n+--------------------------- HELP MENU -------------------------+\n";
        cout << "|                                                               |\n";
        cout << "|   Easy   : numbers 1-10, simple operations                    |\n";
        cout << "|   Medium : numbers 10-100, mixed operations                   |\n";
        cout << "|   Hard   : large numbers, multi-step and combined operations  |\n";
        cout << "|                                                               |\n";
        cout << "+---------------------------------------------------------------+\n";
    }
};

int main() {
    MathQuiz quiz;
    string username;
    int choice;

    cout << "\n============================================================\n";
    cout << "|                                                          |\n";
    cout << "|                    M A T H   Q U I Z                     |\n";
    cout << "|                                                          |\n";
    cout << "============================================================\n";
    cout << "\n   ***** Welcome to the Ultimate Math Quiz System   *****\n\n";

    cout << "Enter your name: ";
    getline(cin, username);

    do {
        cout << "\n+----------------------------------------------------------+\n";
        cout << "|                        MAIN MENU                         |\n";
        cout << "+----------------------------------------------------------+\n";
        cout << "\n   [1]  Start Quiz\n";
        cout << "   [2]  Help and Instructions\n";
        cout << "   [3]  Exit Program\n";
        cout << "\n------------------------------------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        while (choice < 1 || choice > 3) {
            cout << "Choice out of range. Please enter 1-3: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                int level;

                cout << "\nSelect difficulty level (1-Easy, 2-Medium, 3-Hard): ";
                cin >> level;

                while (level < 1 || level > 3 ) {
                    cout << "Level out of range. Please enter 1-3: ";
                    cin >> level;
                }

                quiz.setDifficulty(level);
                quiz.generateQuestions();
                quiz.startQuiz();
                quiz.showResults(username);
                break;
            }
            case 2:
                quiz.showHelp();
                break;
            case 3:
                cout << "\nExiting program. Goodbye!\n";
                break;
        }

    } while (choice != 3);

    return 0;
}