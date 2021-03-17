#include <string>
using namespace std;

class Patient {
private:
	string identifyNumb, name, addr, phone;
public:
	Patient();
	virtual void enterPatientInfo();
	virtual void getPatientInfo();
	~Patient();

};