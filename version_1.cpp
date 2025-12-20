#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

void generateQuestions(int a[], int b[], int correct[]) {
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 20 + 1;
        b[i] = rand() % 20 + 1;
        correct[i] = a[i] + b[i];
    }
}

void startQuiz(int a[], int b[], int correct[], int userAnswers[], int& score) {
    score = 0;
    for (int i = 0; i < 10; i++) {
        cout << " Question " << i + 1 << " of 10\n";

        cout << "   Solve: " << a[i] << " + " << b[i] << " = ";
        cin >> userAnswers[i];

        if (userAnswers[i] == correct[i]) {
            cout << "   Correct!" << endl;
            score++;
        } else {
            cout << "   Incorrect "<< endl;
        }
    }
}

void showResults(int a[], int b[], int correct[], int userAnswers[], int score) {
    cout << "                     RESULTS                         \n";

    cout << " Score: " << score << "/10\n\n";

    cout << " Detailed:\n";
    cout << "-----------------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        cout << " " << (i + 1) << ") "
             << a[i] << " + " << b[i]
             << " = " << correct[i]
             << " | Your answer: " << userAnswers[i];

        cout << endl;
    }

    cout << "-----------------------------------------------------\n";
    cout << " End of Quiz.\n";
}
int main() {
    int a[10], b[10], correct[10], userAnswers[10];
    int score = 0;
    cout << "                    MATH QUIZ                         \n";
    generateQuestions(a, b, correct);
    startQuiz(a, b, correct, userAnswers, score);
    showResults(a, b, correct, userAnswers, score);

    return 0;
}
// this the first version of my math quiz program in C++. It generates 10 random addition questions, collects user answers, and displays the results at the end.