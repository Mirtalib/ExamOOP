#pragma once

namespace  HearderFiles {

	class Guest : public Users
	{
	public:
		Guest(string adminName);

        void topScoreWriteFile(size_t& correct, size_t& wrong, size_t& passed); 
	};


    void Guest::topScoreWriteFile(size_t& correct, size_t& wrong, size_t& passed) {
        size_t size;
        ofstream fout("Score.txt", ios::app);
        size = correct - wrong;

        if (!fout)
            throw"File can not created";

        if (!fout.is_open()) {
            throw"File can not opened";
        }
        fout << Guest::getUserName() << endl << size << endl;
        fout.close();
    }

	Guest::Guest(string adminName)
		:Users(adminName)
	{

	}

}