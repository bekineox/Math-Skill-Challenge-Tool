#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

struct Question {
    string text;
    double correctAnswer;
    double userAnswer;
    bool isCorrect;
};

void generateQuestions(Question q[]) {
    for (int i = 0; i < 10; i++) {
        int a = rand() % 30 + 1;
        int b = rand() % 30 + 1;
        q[i].text = to_string(a) + " - " + to_string(b);
        q[i].correctAnswer = a - b;
        q[i].isCorrect = false;
    }
}

int startQuiz(Question q[]) {
    int score = 0;

    for (int i = 0; i < 10; i++) {
        cout << "\n------------------------------------------------\n";
        cout << " Question " << i + 1 << " of 10\n";
        cout << "------------------------------------------------\n";
        cout << "   " << q[i].text << " = ";

        cin >> q[i].userAnswer;

        if (fabs(q[i].userAnswer - q[i].correctAnswer) < 0.001) {
            cout << "   Correct!\n";
            q[i].isCorrect = true;
            score++;
        } else {
            cout << "   Incorrect! Correct answer: "
                 << q[i].correctAnswer << endl;
        }
    }

    return score;
}

void showResults(Question q[], int score) {
    cout << "\n====================================================\n";
    cout << "                     RESULTS                          \n";
    cout << "====================================================\n";

    cout << " Score: " << score << "/10\n\n";

    cout << " Detailed Breakdown:\n";
    cout << "----------------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        cout << " " << (i + 1) << ") " << q[i].text
             << " | Correct: " << q[i].correctAnswer
             << " | Your: " << q[i].userAnswer;

        if (q[i].isCorrect)
            cout << "  [Correct]";
        else
            cout << "  [Incorrect]";

        cout << endl;
    }

    cout << "----------------------------------------------------\n";
}

int main() {
    Question q[10];
    int score;

    cout << "====================================================\n";
    cout << "                    MATH QUIZ                       \n";
    cout << "====================================================\n";

    generateQuestions(q);
    score = startQuiz(q);
    showResults(q, score);

    return 0;
}
