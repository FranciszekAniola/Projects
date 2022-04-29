#include <iostream>
#include <string>
#include <vector>

struct Answers
{
private:
	std::string Content;
	bool IsRight;
	int Qnumber;

public:
	Answers(std::string content, bool isRight, int QNumber) {
		this->Content = content;
		this->IsRight = isRight;
		this->Qnumber = QNumber;
	}

	void setContent(std::string content) {
		this->Content = content;
	}

	std::string getContent() {
		return Content;
	}

	void setIsRight(bool isRight) {
		this->IsRight = isRight;
	}

	bool getIsRight() {
		return IsRight;
	}

	int getQnumber() {
		return Qnumber;
	}
};

struct Question
{
private:
	std::string QContent;
	std::vector<Answers> vec;
	int Qnumber;
public:
	Question(std::string content) {
		this->QContent = content;
	}

	void setContent(std::string content) {
		this->QContent = content;
	}

	std::string getContentQ() {
		return QContent;
	}

	std::vector<Answers> getVec() {
		return vec;
	}

	void putAnswerToVec(Answers answer) {
		vec.push_back(answer);

	}

	void viewQ() {
		std::cout << QContent << "\n";
	}

	void viewVec() {
		int plus = 0;

		for (Answers x : vec) {
			plus++;
			std::cout << (vec.size() + plus) - vec.size() << ". " << x.getContent() << "\n";
		}
	}

};

void isCorrect(Question q) {
	std::cout << "Chose between 1-3" << "\n";
	int guess;
	std::cin >> guess;
	for (Answers x : q.getVec()) {
		if (guess == x.getQnumber()) {
			if (x.getIsRight()) {
				std::cout << "Correct!" << "\n";
				break;
			}
			else {
				std::cout << "Incorrect! :(" << "\n";
			}
		}
	}
}




int main() {

	Answers firstQA("21", true,1);
	Answers firstQA2("2", false,2);
	Answers firstQA3("5", false,3);

	Question firstQ("which number is the biggest?\n");
	firstQ.putAnswerToVec(firstQA);
	firstQ.putAnswerToVec(firstQA2);
	firstQ.putAnswerToVec(firstQA3);	

	Answers secondQA("warsaw", false,1);
	Answers secondQA2("Berlin", false,2);
	Answers secondQA3("Budapest", true,3);

	Question secondQ("which is the cappital of Hungary?\n");
	secondQ.putAnswerToVec(secondQA);
	secondQ.putAnswerToVec(secondQA2);
	secondQ.putAnswerToVec(secondQA3);

	firstQ.viewQ();
	firstQ.viewVec();

	isCorrect(firstQ);

	secondQ.viewQ();
	secondQ.viewVec();

	isCorrect(secondQ);


}