#include <iostream>
#include <string>
using namespace std;

//枚举类：课程类别
enum CourseCategory{
	CAT_UNKNOWN=0,
	COMPULSORY,
	ELECTIVE,
	GENERAL
};

//枚举类：授课专业
enum Major{
	MAJ_UNKNOWN=0,
	CS,
	SE,
	AI,
	DATA_SCIENCE
};

class Course
{
private:
	string courseName;
	double credits;
	int hours;
	CourseCategory category;
	Major major;

	// 私有辅助函数：将课程类别枚举转换为中文字符串用于显示
	string getCategoryName() const{
		switch(category){
		case COMPULSORY: return "必修课";
		case ELECTIVE: return "选修课";
		case GENERAL: return "通识课";
		default: return "未分类";
		}
	}

	// 私有辅助函数：将授课专业枚举转换为中文字符串用于显示
	string getMajorName() const{
		switch(major){
		case CS: return "计算机科学与技术";
		case SE: return "软件工程";
		case AI: return "人工智能";
		case DATA_SCIENCE: return "数据科学与大数据技术";
		default: return "通用专业";
		}
	}

public:
	//默认构造函数
	Course() : courseName("未命名课程"),credits(0.0),hours(0),category(CAT_UNKNOWN),major(MAJ_UNKNOWN) {}
	//带参数的重载构造函数
	Course(string name,double cred,int hrs,CourseCategory cat,Major maj)
		: courseName(name),credits(cred),hours(hrs),category(cat),major(maj) {}
	
	//Setters,设置函数
	void setCourseName(string name){courseName=name;}
	void setCredits(double cred){credits=(credits>0) ? credits : 0.0;}
	void setHours(int hrs){hours=(hrs>0) ? hrs : 0;}
	void setCategory(CourseCategory cat){category=cat;}
	void setMajor(Major maj){major=maj;}
	
	//Getters,获取函数
	string getCourseName() const{return courseName;}
	double getCredits() const{return credits;}
	int getHours() const{return hours;}
	CourseCategory getCategory() const{return category;}
	Major getMajor() const{return major;}

	//显示完整课程信息
	void display() const
	{
		cout<<"课程名称："<<courseName<<endl;
		cout<<"学分："<<credits<<endl;
		cout<<"学时数："<<hours<<"学时"<<endl;
		cout<<"课程类别："<<getCategoryName()<<endl;
		cout<<"授课专业："<<getMajorName()<<endl;
	}
};


int main() {
	//习题5.1，设计并实现类Course
    Course c1("C++程序设计",3.5,56,COMPULSORY,CS);
	c1.display();

	Course c2;
	c2.setCourseName("机器学习导论");
	c2.setCredits(3.6);
	c2.setHours(48);
	c2.setCategory(ELECTIVE);
	c2.setMajor(DATA_SCIENCE);
	c2.display();

    return 0;
}
