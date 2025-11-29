Quiz Game in C++

This project is a console-based Quiz Application written in C++.
It allows users to attempt a series of multiple-choice questions, get their score, and even save previous results for future reference.

✨ Features
1. Question Class

Stores each question, its options, and the correct answer index.

Displays questions and options to the user.

Validates the user's answer and checks correctness.

Shows the correct answer after each attempt.

2. Score Manager

Saves the player’s name and score into a scores.txt file.

Displays all previously recorded scores.

Helps maintain a simple "high-scores" system for replay sessions.

3. Quiz System

Contains a set of 12 pre-defined general knowledge and programming questions.

Uses a validated input method to prevent invalid user entries (letters, symbols, wrong numbers).

Calculates the final score and stores it using ScoreManager.

Allows the user to replay the quiz as many times as they want.

4. Clean Input Validation

Ensures users enter only valid integers within the allowed option range.

Prevents crashes caused by invalid input.

🛠️ How It Works

Program starts by asking the user’s name.

Each question is displayed with four options.

Player selects an answer → program checks correctness.

After all questions:

Total score is shown.

Score is saved into scores.txt.

All previous scores are displayed.

User can choose to replay the quiz.

📦 Files

main.cpp → Entire quiz logic (questions, scoring, input handling).

scores.txt → Gets auto-created to store past results.

🎯 Purpose of the Project

This project demonstrates:

Object-oriented programming in C++

Class design (Question, ScoreManager, Quiz)

File handling (fstream)

Input validation and error handling

Looping and conditional logic

Basic console-based interaction

Perfect for beginners practicing C++ OOP and console applications
