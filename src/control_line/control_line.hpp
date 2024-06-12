#ifndef CONTROL_LINE
#define CONTROL_LINE

#include <string>

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>

class ControlLine: public QWidget
{
	Q_OBJECT
	
public:
  ControlLine(QWidget *parent = nullptr);

	void changeScore(int score);
	void changeTime(std::string time);
	void showTime(bool show);
	void pauseBtnFunc();

private:
	QBoxLayout *main_layout;
	QPushButton *start_btn;
	QPushButton *pause_btn;
	QLabel *score;
	QLabel *time;

private slots:
	void startBtnFunc();
};

#endif
