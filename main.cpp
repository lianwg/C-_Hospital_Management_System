// C++ program to implement the Hospital 
// Management System 
//#include <bits/stdc++.h> 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;

// Store the data of Hospital 
class Hospital {
public:
	string H_name;
	string location;
	int available_beds;
	float rating;
	string contact;
	string doctor_name;
	int price;
	Hospital() {
		H_name = "nothing";
	}
};

// Stores the data of Patient 
class Patient : public Hospital {
public:
	Patient(){
		H_name = "Nothing";
	}
	string P_name;
	int P_id;
	string P_contact;//患者联系方式
	int Patient_Expenditure;//患者花费
};

// Hospital Data 
// 打印医院信息
void PrintHospitalData(
	vector<Hospital>& hospitals)
{
	cout << setiosflags(ios::left) << setw(15) << "HospitalName"
		<< setiosflags(ios::left) << setw(15) << "Location"
		<< setiosflags(ios::left) << setw(17) << "Beds_Available"
		<< setiosflags(ios::left) << setw(10) << "Rating"
		<< setiosflags(ios::left) << setw(20) << "Hospital_Contact"
		<< setiosflags(ios::left) << setw(15) << "Doctor_Name"
		<< "Price_Per_Bed\n";

	for (int i = 0; i < hospitals.size(); i++) {
		cout << setiosflags(ios::left) << setw(15) << hospitals[i].H_name
			<< setiosflags(ios::left) << setw(15) << hospitals[i].location
			<< setiosflags(ios::left) << setw(17) << hospitals[i].available_beds
			<< setiosflags(ios::left) << setw(10) << hospitals[i].rating
			<< setiosflags(ios::left) << setw(20) << hospitals[i].contact
			<< setiosflags(ios::left) << setw(15) << hospitals[i].doctor_name
			<< hospitals[i].price
			<< endl;
	}
}

// Function to print the patient 
// data in the hospital 
// 打印患者信息
void PrintPatientData(
	vector<Patient>& patients)
{
	cout << setiosflags(ios::left) << setw(15) << "Patient_Name"
		<< setiosflags(ios::left) << setw(15) << "Patient_Id"
		<< setiosflags(ios::left) << setw(18) << "Patient_Contact"
		<< setiosflags(ios::left) << setw(20) << "Alloted_Hospital"
		<< "Patient_Expenditure	 \n";

	for (int i = 0; i < patients.size(); i++) {
		cout << setiosflags(ios::left) << setw(15) << patients[i].P_name
			<< setiosflags(ios::left) << setw(15) << patients[i].P_id
			<< setiosflags(ios::left) << setw(18) << patients[i].P_contact
			<< setiosflags(ios::left) << setw(20) << patients[i].H_name
			<< patients[i].Patient_Expenditure
			<< endl;
	}
}

// Comparator function to sort the 
// hospital data by name 
bool name_up(Hospital& A, Hospital& B)
{
	return A.H_name < B.H_name;
}

bool name_down(Hospital& A, Hospital& B)
{
	return A.H_name > B.H_name;
}

// Function to sort the hospital 
// data by name 
// 医院按名字排序
void SortHospitalByName(
	vector<Hospital> hospitals, int UporDown)
{
	// Sort the date 
	cout << endl;
	vector<Hospital> temp = hospitals;
	string str;
	if (UporDown == 1) {
		str = "=========按名字升序=========";
		sort(temp.begin(), temp.end(), name_up);
	} else {
		str = "=========按名字降序=========";
		sort(temp.begin(), temp.end(), name_down);
	}
	cout << str << endl;
	PrintHospitalData(temp);
	cout << "===========打印结束===========" << endl;
}

// Comparator function to sort the 
// hospital data by rating 
bool rating_up(Hospital& A, Hospital& B)
{
	return A.rating < B.rating;
}

bool rating_down(Hospital& A, Hospital& B)
{
	return A.rating > B.rating;
}

// Function to sort the hospital 
// data by namerating 
// 医院按评分排序
void SortHospitalByRating(vector<Hospital> hospitals, int UporDown)
{
	cout << endl;
	vector<Hospital> temp = hospitals;
	string str;
	if (UporDown == 1) {
		str = "=========按评分升序=========";
		sort(temp.begin(), temp.end(), rating_up);
	} else {
		str = "=========按评分降序=========";
		sort(temp.begin(), temp.end(), rating_down);
	}
	cout << str << endl;
	PrintHospitalData(temp);
	cout << "===========打印结束===========" << endl;
}

// Comparator function to sort the 
// hospital data by Bed Available 
bool beds_up(Hospital& A, Hospital& B)
{
	return A.available_beds < B.available_beds;
}

bool beds_down(Hospital& A, Hospital& B)
{
	return A.available_beds > B.available_beds;
}

// Function to sort the hospital 
// data by Bed Available 
// 医院床位数量排序
void SortByBedsAvailable(
	vector<Hospital> hospitals, int UporDown)
{
	cout << endl;
	vector<Hospital> temp = hospitals;
	string str;
	if (UporDown == 1) {
		str = "=========按床位数量升序=========";
		sort(temp.begin(), temp.end(), beds_up);
	} else {
		str = "=========按床位数量降序=========";
		sort(temp.begin(), temp.end(), beds_down);
	}
	cout << str << endl;
	PrintHospitalData(temp);
	cout << "==============打印结束==============" << endl;
}

// Comparator function to sort the 
// hospital data by Bed Price 
bool beds_price_up(Hospital& A, Hospital& B)
{
	return A.price < B.price;
}

bool beds_price_down(Hospital& A, Hospital& B)
{
	return A.price > B.price;
}

// Function to sort the hospital 
// data by Bed Price 
// 医院床位价格排序
void SortByBedsPrice(
	vector<Hospital> hospitals, int UporDown)
{
	cout << endl;
	vector<Hospital> temp = hospitals;
	string str;
	if (UporDown == 1) {
		str = "=========按床位价格升序=========";
		sort(temp.begin(), temp.end(), beds_price_up);
	} else {
		str = "=========按床位价格降序=========";
		sort(temp.begin(), temp.end(), beds_price_down);
	}
	cout << str << endl;
	PrintHospitalData(temp);
	cout << "==============打印结束==============" << endl;
}

// Comparator function to sort the 
// hospital data by City 
// 查找医院城市
vector<Hospital> FindHospitalBycity(
	string city, vector<Hospital> hospitals)
{
	vector<Hospital>res;
	for (int i = 0; i < hospitals.size(); i++) {
		if (hospitals[i].location == city) {
			res.push_back(hospitals[i]);
		}
	}
	return res;
}

// Function to implement Hospital 
// Management System 
class HospitalManagement{
private:
	// Stores the Hospital data 
	// and user data 
	vector<Hospital> hospitals;
	int hospitals_Num;
	// Stores the patient data 
	vector<Patient> patients;
	int patients_Num;
	// 根据名字查找医院
	Hospital checkHosName(string name) {
		Hospital res;
		for (int i = 0; i < hospitals.size(); i++) {
			if (hospitals[i].H_name == name) {
				return hospitals[i];
			}
		}
		return res;
	}
	// 新增患者
	bool AddNewPatient(string name, string contact, string H_name, int expense) {
		Hospital hos = checkHosName(H_name);
		if (hos.H_name == "nothing") {
			// 如果没有这个医院
			return false;
		}
		Patient newP;
		newP.P_name = name;
		newP.P_id = ++patients_Num;
		newP.P_contact = contact;
		newP.Patient_Expenditure = expense;
		// 继承属性
		newP.H_name = hos.H_name;
		newP.location = hos.location;
		newP.available_beds = hos.available_beds;
		newP.contact = hos.contact;
		newP.doctor_name = hos.doctor_name;
		newP.price = hos.price;
		newP.rating = hos.rating;
		
		patients.push_back(newP);
		return true;
	} 
	// 新增医院
	bool AddNewHospital(string name,string address,int beds,
	float rate,string contact,string Doctor_name,int price) {
		Hospital hos = checkHosName(name);
		if (hos.H_name != "nothing") {
			// 如果已经有这个医院了这个医院
			return false;
		}
		hos.available_beds = beds;
		hos.contact = contact;
		hos.doctor_name = Doctor_name;
		hos.H_name = name;
		hos.location = address;
		hos.price = price;
		hos.rating = rate;
		hospitals_Num++;
		hospitals.push_back(hos);
		return true;
	}
	// 根据名字查找患者
	vector<Patient> checkPatName(string name) {
		vector<Patient> res;
		for (int i = 0; i < patients.size(); i++) {
			if (patients[i].P_name == name) {
				res.push_back(patients[i]);
			}
		}
		return res;
	}
public:
	//初始化构造函数
	HospitalManagement(
	string patient_Name[], int patient_Id[],
	string patient_Contact[], int bookingCost[], string patient_Hospital[], int patient_Num,
	string hospital_Name[], string locations[], int beds[],
	float ratings[], string hospital_Contact[], 
	string doctor_Name[], int prices[], int Hospital_Num)
{
	// Initialize the data 
	// Create Objects for hospital 
	// and the users 
	Hospital h;
	for (int i = 0; i < patient_Num; i++) {
		h.H_name = hospital_Name[i];
		h.location = locations[i];
		h.available_beds = beds[i];
		h.rating = ratings[i];
		h.contact = hospital_Contact[i];
		h.doctor_name = doctor_Name[i];
		h.price = prices[i];
		hospitals.push_back(h);
	}
	// Initialize the data 
	Patient p;
	for (int i = 0; i < Hospital_Num; i++) {
		p.P_name = patient_Name[i];
		p.P_id = patient_Id[i];
		p.P_contact = patient_Contact[i];
		p.Patient_Expenditure = bookingCost[i];
		Hospital temp = checkHosName(patient_Hospital[i]);
		p.H_name = temp.H_name;
		p.available_beds = temp.available_beds;
		p.contact = temp.contact;
		p.doctor_name = temp.doctor_name;
		p.location = temp.location;
		p.price = temp.price;
		p.rating = temp.rating;
		patients.push_back(p);
	}
	hospitals_Num = hospitals.size();
	patients_Num = patients.size();
	management_Login();
}
	// 登录界面
	void management_Login() {
		while (1) {
			cout << endl;
			cout << "=========欢迎登录医疗管理系统=========" << endl;
			cout << "请选择您的身份"  << endl;
			cout << "患者(请输入1)" << endl;
			cout << "医院(请输入2)" << endl;
			cout << "管理员(请输入3)" << endl;
			int choose;
			int flag = 0;
			while (1) {
				cout << "请输入: ";
				cin >> choose;
				switch (choose)
				{
				case 1:
					flag = 1;
					patient_System();
					break;
				case 2:
					flag = 1;
					Hospital_System();
					break;
				case 3:
					flag = 1;
					Manager_System();
					break;
				default:
					cout << "输入错误，请重新输入" << endl;
					break;
				}
				if (flag) break;
			}
		}
	}
	// 患者系统
	void patient_System() {
		while (1) {
			cout << endl;
			cout << "=========欢迎来到患者系统，请选择您要进行的操作========="<< endl;
			cout << "患者注册(请输入1)" << endl;
			cout << "打印患者信息(请输入2)" << endl;
			cout << "返回登录界面(请输入3)" << endl;
			int choose;
			int flag  = 0;
			while (1) {
				cout << "请输入: ";
				cin >> choose;
				switch (choose)
				{
				case 1:
					flag = 1;
					patient_Register();
					break;
				case 2:
					flag = 1;
					patient_Print();
					break;
				case 3:
					return;
				default:
					cout << "输入错误，请重新输入" << endl;
					break;
				}
				if (flag) break;
			}
		}
	}
		// 患者_患者注册
	void patient_Register() {
		string name;
		string contact;
		string H_name;
		int expense;
		while (1) {
			cout << endl;
			cout << "=========患者注册=========" << endl;
			cout << "请输入您的信息" <<endl;
			cout << "请输入您的名字: ";
			cin >> name;
			cout << "请输入您的联系方式: ";
			cin >> contact;
			cout << "请输入您的就治医院名字: ";
			cin >> H_name;
			cout << "请输入您的花销: ";
			cin >> expense;
			int is_ok;
			cout << endl << "请确认您的输入" << endl;
			cout << "名字: " << name << endl;
			cout << "联系方式: " << contact << endl;
			cout << "就治医院: " << H_name << endl;
			cout << "花销: " << expense << endl;
			cout << endl << "如果没有问题请输入1, 否则请输入0" << endl;
			cout << "请输入: " ;
			cin >> is_ok;
			if (is_ok) break;
			cout << "输入已取消" << endl;
		}
		cout << "输入已确认, 即将为您注册患者信息" << endl;
		bool is_success = AddNewPatient(name, contact, H_name, expense);
		if (!is_success) {
			cout << "您所输入的就治医院不存在, 患者注册失败!" << endl;
		} else {
			cout << "患者注册成功!" << endl;
		}
	}
		// 患者_打印患者信息
	void patient_Print() {
		cout << endl;
		cout << "=========打印患者信息========="<< endl;
		PrintPatientData(patients);
		cout << "===========打印结束===========" << endl;
	}
	
	// 医院系统
	void Hospital_System() {
		while (1) {
			cout << endl;
			cout << "=========欢迎来到医院系统，请选择您要进行的操作========="<< endl;
			cout << "医院注册(请输入1)" << endl;
			cout << "打印医院信息(请输入2)" << endl;
			cout << "返回登录界面(请输入3)" << endl;
			int choose;
			int flag = 0;
			while (1) {
				cout << "请输入: ";
				cin >> choose;
				switch (choose)
				{
				case 1:
					flag = 1;
					Hospital_Register();
					break;
				case 2:
					flag = 1;
					Hospital_Print();
					break;
				case 3:
					return;
				default:
					cout << "输入错误，请重新输入" << endl;
					break;
				}
				if (flag) break;
			}
		}
	}
		// 医院_医院注册
	void Hospital_Register() {
		string name;
		string address;
		int beds;
		float rate;
		string contact;
		string Doctor_name;
		int price;
		while (1) {
			cout << endl;
			cout << "=========医院注册=========" << endl;
			cout << "请输入医院的信息" <<endl;
			cout << "请输入医院的名字: ";
			cin >> name;
			cout << "请输入医院的地址: ";
			cin >> address;
			cout << "请输入医院可用床位数: ";
			cin >> beds;
			cout << "请输入医院的评分: ";
			cin >> rate;
			cout << "请输入医院的联系方式: ";
			cin >> contact;
			cout << "请输入医院的医生姓名: ";
			cin >> Doctor_name;
			cout << "请输入医院的床位价格: ";
			cin >> price;
			int is_ok;
			cout << endl << "请确认您的输入" << endl;
			cout << "名字: " << name << endl;
			cout << "地址: " << address << endl;
			cout << "可用床位数: " << beds << endl;
			cout << "评分: " << rate << endl;
			cout << "联系方式: " << contact << endl;
			cout << "医生姓名: " << Doctor_name << endl;
			cout << "床位价格: " << price << endl;
			cout << endl << "如果没有问题请输入1, 否则请输入0" << endl;
			cout << "请输入: " ;
			cin >> is_ok;
			if (is_ok) break;
			cout << "输入已取消" << endl;
		}
		cout << "输入已确认, 即将为您注册医院信息" << endl;
		bool is_success = AddNewHospital(name, address, beds, rate, contact, Doctor_name, price);
		if (!is_success) {
			cout << "您所输入的医院名字已经存在, 医院注册失败!" << endl;
		} else {
			cout << "医院注册成功!" << endl;
		}
	}
		// 医院_打印医院信息
	void Hospital_Print() {
		cout << endl;
		cout << "=========打印医院信息=========" << endl;
		PrintHospitalData(hospitals);
		cout << "===========打印结束===========" << endl;
		while (1) {
			int is_exit;
			cout << endl << "是否退出打印？(是则输入1,否则输入2)" << endl;
			cout << "请输入: ";
			cin >> is_exit;
			if (is_exit < 1 or is_exit > 2) {
				cout << "输入错误, 请重新输入" <<endl;
				cout << "请输入: ";
				cin >> is_exit;
			}
			if (is_exit == 1) {
				cout << "已退出医院打印" << endl;
				return;
			}
			int is_city;
			cout << endl << "是否搜索城市?(是则输入1,否则输入2)"<<endl;
			cout << "请输入: ";
			cin >> is_city;
			while (is_city < 1 or is_city > 2) {
				cout << "输入错误, 请重新输入" <<endl;
				cout << "请输入: ";
				cin >> is_city;
			}
			vector<Hospital> printHospital;
			if (is_city == 1) {
				// 只保留location为city的医院信息
				string city;
				cout << "请输入您想要搜索的城市名: ";
				cin >> city;
				printHospital = FindHospitalBycity(city, hospitals);
			} else {
				printHospital = hospitals;
			}
			int choose;
			cout << endl << "您可以选择打印方式: " << endl;
			cout << "按名字(请输入1)" << endl;
			cout << "按可用床位数(请输入2)" << endl;
			cout << "按评分(请输入3)" << endl;
			cout << "按床位费(请输入4) " << endl;
			cout << "请输入: ";
			cin >> choose;
			while (choose < 1 or choose > 6) {
				cout << "输入错误, 请重新输入" <<endl;
				cout << "请输入: ";
				cin >> choose;
			}
			int UporDown = 1;
			if (choose != 6) {
				cout << "您可以选择升降序: " << endl;
				cout << "升序(请输入1)" << endl;
				cout << "降序(请输入2)" << endl;
				cout << "请输入: ";
				cin >> UporDown;
				while (UporDown < 1 or UporDown > 2) {
					cout << "输入错误, 请重新输入" <<endl;
					cout << "请输入: ";
					cin >> UporDown;
				}
			}
			switch (choose) {					
				case 1:
					SortHospitalByName(printHospital, UporDown);
					break;
				case 2:
					SortByBedsAvailable(printHospital, UporDown);
					break;
				case 3:
					SortHospitalByRating(printHospital, UporDown);
					break;
				case 4:
					SortByBedsPrice(printHospital, UporDown);
					break;
				default:
					break;
			}
		}
	}
	
	//管理者系统
	void Manager_System() {
		while (1) {
			cout << endl;
			cout << "=========欢迎来到管理员系统，请选择您要进行的操作========="<< endl;
			cout << "患者注册(请输入1)" << endl;
			cout << "医院注册(请输入2)" << endl;
			cout << "患者搜索(请输入3)" << endl;
			cout << "医院搜索(请输入4)" << endl;
			cout << "返回登录界面(请输入5)" << endl;
			int choose;
			int flag = 0;
			while (1) {
				cout << "请输入: ";
				cin >> choose;
				switch (choose)
				{
				case 1:
					flag = 1;
					Manager_patient_Register();
					break;
				case 2:
					flag = 1;
					Manager_Hospital_Register();
					break;
				case 3:
					flag = 1;
					Manager_SearchPatient();
					break;
				case 4:
					flag = 1;
					Manager_SearchHospital();
					break;
				case 5:
					return;
				default:
					cout << "输入错误，请重新输入" << endl;
					break;
				}
				if (flag) break;
			}
		}
	}
		// 管理者_患者注册
	void Manager_patient_Register() {
		string name;
		string contact;
		string H_name;
		int expense;
		while (1) {
			cout << endl;
			cout << "=========患者注册=========" << endl;
			cout << "请输入患者的信息" <<endl;
			cout << "请输入患者的名字: ";
			cin >> name;
			cout << "请输入患者的联系方式: ";
			cin >> contact;
			cout << "请输入患者的就治医院名字: ";
			cin >> H_name;
			cout << "请输入患者的花销: ";
			cin >> expense;
			int is_ok;
			cout << endl << "请确认您的输入" << endl;
			cout << "名字: " << name << endl;
			cout << "联系方式: " << contact << endl;
			cout << "就治医院: " << H_name << endl;
			cout << "花销: " << expense << endl;
			cout << endl << "如果没有问题请输入1, 否则请输入0" << endl;
			cout << "请输入: " ;
			cin >> is_ok;
			if (is_ok) break;
			cout << "输入已取消" << endl;
		}
		cout << "输入已确认, 即将为您注册患者信息" << endl;
		bool is_success = AddNewPatient(name, contact, H_name, expense);
		if (!is_success) {
			cout << "您所输入的就治医院不存在, 患者注册失败!" << endl;
		} else {
			cout << "患者注册成功!" << endl;
		}
	}
		// 管理者_医院注册
	void Manager_Hospital_Register() {
		string name;
		string address;
		int beds;
		float rate;
		string contact;
		string Doctor_name;
		int price;
		while (1) {
			cout << endl;
			cout << "=========医院注册=========" << endl;
			cout << "请输入医院的信息" <<endl;
			cout << "请输入医院的名字: ";
			cin >> name;
			cout << "请输入医院的地址: ";
			cin >> address;
			cout << "请输入医院可用床位数: ";
			cin >> beds;
			cout << "请输入医院的评分: ";
			cin >> rate;
			cout << "请输入医院的联系方式: ";
			cin >> contact;
			cout << "请输入医院的医生姓名: ";
			cin >> Doctor_name;
			cout << "请输入医院的床位价格: ";
			cin >> price;
			int is_ok;
			cout << endl << "请确认您的输入" << endl;
			cout << "名字: " << name << endl;
			cout << "地址: " << address << endl;
			cout << "可用床位数: " << beds << endl;
			cout << "评分: " << rate << endl;
			cout << "联系方式: " << contact << endl;
			cout << "医生姓名: " << Doctor_name << endl;
			cout << "床位价格: " << price << endl;
			cout << endl << "如果没有问题请输入1, 否则请输入0" << endl;
			cout << "请输入: " ;
			cin >> is_ok;
			if (is_ok) break;
			cout << "输入已取消" << endl;
		}
		cout << "输入已确认, 即将为您注册医院信息" << endl;
		bool is_success = AddNewHospital(name, address, beds, rate, contact, Doctor_name, price);
		if (!is_success) {
			cout << "您所输入的医院名字已经存在, 医院注册失败!" << endl;
		} else {
			cout << "医院注册成功!" << endl;
		}
	}
		// 管理者_患者搜索
	void Manager_SearchPatient() {
		string name;
		cout << endl << "请输入您想搜索的患者姓名: ";
		cin >> name;
		vector<Patient> find = checkPatName(name);
		cout << "=========打印姓名为\""<< name <<"\"的患者信息:=========" << endl;
		PrintPatientData(find);
		cout << "================打印结束================" << endl;
	}
		// 管理员_医院搜索
	void Manager_SearchHospital() {
		string name;
		cout << endl << "请输入您想搜索的医院姓名: ";
		cin >> name;
		Hospital find = checkHosName(name);
		vector<Hospital> temp;
		temp.push_back(find);
		cout << "=========打印名字为\""<< name <<"\"的医院信息:=========" << endl;
		PrintHospitalData(temp);
		cout << "================打印结束================" << endl;
	}
};

// Driver Code 
int main()
{
	// Stores hospital data and 
	// the user data 
	string patient_Name[] = { "P1", "P2", "P3", "P4" };
	int patient_Id[] = { 1, 2, 3, 4 };
	string patient_Contact[]
		= { "234534XXX7", "234576XXX2", "857465XXX9",
			"567657XXX0" };
	int bookingCost[] = { 1000, 1200, 1100, 600 };
	string patient_Hospital[] = {"H1", "H2", "H4", "H3"};

	string hospital_Name[] = { "H1", "H2", "H3", "H4" };
	string locations[] = { "Bangalore", "Bangalore",
						"Mumbai ", "Prayagraj" };
	int beds[] = { 4, 5, 6, 9 };
	float ratings[] = { 5.2, 4.1, 3.4, 5.9 };
	string hospital_Contact[]
		= { "657534XXX7", "298766XXX2", "324565XXX9",
			"343456XXX4" };
	string doctor_Name[] = { "D1", "D4", "D3", "D2" };
	int prices[] = { 100, 200, 100, 290 };

	// Function Call 
	HospitalManagement a(
	patient_Name, patient_Id, patient_Contact,
	bookingCost, patient_Hospital, 4, 
	hospital_Name, locations, beds,
	ratings, hospital_Contact, doctor_Name, prices, 4);
	return 0;
}
