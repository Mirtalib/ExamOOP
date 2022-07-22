#pragma once

namespace HearderFiles {

    class quizes {
    private:
        vector<Question> appliers;
        string _name;
    public:
        quizes() = default;

        quizes(string name) {
            _name = name;
        }

        void add(Question cv) {
            appliers.push_back(cv);
        }

        void writeToFile() {
            _name.append(".txt");
            ofstream fout(_name, ios::app);


            if (!fout)
                throw"File can not created";

            if (!fout.is_open()) {
                throw"File can not opened";
            }

            for (size_t i = 0; i < appliers.size(); i++)
            {
                fout << appliers[i].get_text() << endl
                    << appliers[i].get_answer1() << endl
                    << appliers[i].get_answer2() << endl;

                if (appliers[i].get_answer3() == "")
                {
                    fout << appliers[i].get_answer3() << endl
                        << appliers[i].get_answerCorrectVariant() << endl;
                }
                else
                {
                    fout << appliers[i].get_answer3() << endl;
                    if (appliers[i].get_answer4() != "")
                    {
                        fout << appliers[i].get_answer4() << endl << ""
                            << appliers[i].get_answerCorrectVariant() << endl;
                    }
                    else
                    {
                        fout << appliers[i].get_answer4() << endl
                            <<  appliers[i].get_answerCorrectVariant() << endl;
                    }
                }
            }
            fout.close();
        }
    };
}