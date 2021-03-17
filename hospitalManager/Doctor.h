#include<string>
using namespace std;
class Doctor {
private:
	string doctorID, name, age, addr, department;
public:
	Doctor();
	string getDoctorID() {
		return this->doctorID;
	}
	void enterDoctorInfo();
	~Doctor();
};