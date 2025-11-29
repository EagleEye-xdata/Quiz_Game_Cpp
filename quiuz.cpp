#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

// ------------------------------
// Question Class
// ------------------------------
class Question {
private:
    string text;
    vector<string> options;
    int correctIndex;

public:
    Question(string t, vector<string> op, int ci)
        : text(t), options(op), correctIndex(ci) {}

    void display(int qNum) const {
        cout << "\nQuestion " << qNum << ": " << text << "\n";
        for (int i = 0; i < options.size(); i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    void showCorrectAnswer() const {
        cout << "Correct Answer: " << options[correctIndex] << "\n";
    }

    bool checkAnswer(int userChoice) const {
        return (userChoice - 1 == correctIndex);
    }

    int optionCount() const { return options.size(); }
};

// ------------------------------
// Score Manager Class
// ------------------------------
class ScoreManager {
public:
    void saveScore(const string& name, int score, int total) {
        ofstream out("scores.txt", ios::app);
        if (out.is_open()) {
            out << name << " scored " << score << " out of " << total << endl;
        }
        out.close();
    }

    void displayScores() {
        ifstream in("scores.txt");
        string line;

        cout << "\nPrevious Scores:\n";
        if (!in.is_open()) {
            cout << "No scores recorded yet.\n";
            return;
        }

        while (getline(in, line)) {
            cout << line << endl;
        }
    }
};

// ------------------------------
// Quiz Class
// ------------------------------
class Quiz {
private:
    vector<Question> questions;
    ScoreManager scoreManager;
    string playerName;

public:
    Quiz() {
        // 12 questions
        questions = {
            Question("Capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2),
            Question("Largest Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 2),
            Question("Fastest land animal?", {"Cheetah", "Lion", "Tiger", "Leopard"}, 0),
            Question("Binary of 5?", {"101", "110", "111", "100"}, 0),
            Question("Python is a?", {"Snake", "Programming Language", "Game", "IDE"}, 1),
            Question("Sun is a?", {"Planet", "Star", "Moon", "Comet"}, 1),
            Question("Water formula?", {"H2O", "CO2", "O2", "NaCl"}, 0),
            Question("Who landed on the moon first?", {"Buzz", "Armstrong", "Gagarin", "Glenn"}, 1),
            Question("Java creator?", {"Gosling", "Torvalds", "Jobs", "Zuckerberg"}, 0),
            Question("2^5 equals?", {"32", "64", "16", "8"}, 0),
            Question("Which is a mammal?", {"Shark", "Whale", "Octopus", "Tuna"}, 1),
            Question("Which is a planet?", {"Moon", "Sun", "Earth", "Comet"}, 2)
        };
    }

    // FIXED VALIDATED INPUT FUNCTION
    int getValidatedInput(int maxOption) {
        int choice;
        while (true) {
            cout << "Your answer (1-" << maxOption << "): ";

            // Check if input failed (user typed letters, symbols, etc.)
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter numbers only.\n";
                continue;
            }

            // Check if number is out of range
            if (choice < 1 || choice > maxOption) {
                cout << "Invalid option! Choose between 1 and " << maxOption << ".\n";
                continue;
            }

            return choice; // valid input
        }
    }

    void start() {
        cout << "\nEnter your name: ";
        cin >> playerName;

        int score = 0;

        for (int i = 0; i < questions.size(); i++) {
            questions[i].display(i + 1);
            int userChoice = getValidatedInput(questions[i].optionCount());

            if (questions[i].checkAnswer(userChoice)) {
                cout << "Correct!\n";
                score++;
            } else {
                cout << "Wrong!\n";
            }

            questions[i].showCorrectAnswer();
        }

        cout << "\n" << playerName << ", you scored "
             << score << " out of " << questions.size() << "!\n";

        scoreManager.saveScore(playerName, score, questions.size());
        scoreManager.displayScores();
    }
};

// ------------------------------
// MAIN
// ------------------------------
int main() {
    Quiz quiz;
    char replay;

    do {
        quiz.start();

        cout << "\nDo you want to play again? (y/n): ";
        cin >> replay;

    } while (replay == 'y' || replay == 'Y');

    cout << "\nThanks for playing!\n";
    return 0;
}
