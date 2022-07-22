#pragma once


namespace  HearderFiles {

    class Question {
    private:
        string _question_text;

        vector<string> _anwes;

        string _answer_1;
        string _answer_2;
        string _answer_3;
        string _answer_4;
        char _correctVariant;
    public:
        Question() = default;

        Question(string question_text, char correctVariant, string _answer1, string answer_2, string answer_3 = "", string answer_4 = "") {
            _question_text = question_text;
            _answer_1 = _answer1;
            _answer_2 = answer_2;
            _answer_3 = answer_3;
            _answer_4 = answer_4;
            _correctVariant = correctVariant;
        }





        string get_text() { return _question_text; }
        string get_answer1() { return _answer_1; }
        string get_answer2() { return _answer_2; }
        string get_answer3() { return _answer_3; }
        string get_answer4() { return _answer_4; }
        char get_answerCorrectVariant() { return _correctVariant; }
    };
}