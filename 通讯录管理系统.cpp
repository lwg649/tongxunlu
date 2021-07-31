//封装函数的显示界面  如void showMenu()
//在main 函数中调用封装好的函数
#include<iostream>
#include<string>
#define MAX 1000//最大人数
using namespace std;
//联系人结构体
struct Person
{
	string m_Name;//姓名
	int m_Sex;//性别：1男 2女
	int m_Age;	//年龄
	string m_Phone;//电话
	string m_Addr;//住址
};
//通讯录结构体
struct Addresbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人的个数
	int m_size;
};

//显示所有的联系人
void showPerson(Addresbooks*abs) {
	//判断通讯录中人数是否为零，如果为零，提示记录为空
	//如果不为零，显示记录的联系人的信息
	if (abs->m_size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：  " << abs->personArray[i].m_Name <<"\t" ;
			cout << "姓别：  " << (abs->personArray[i].m_Sex== 1?"男":"女") << "\t";
			cout << "年龄：  " << abs->personArray[i].m_Age << "\t";
			cout << "电话：  " << abs->personArray[i].m_Phone << "\t";
			cout << "住址：  " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

void showMenu() {
	cout << "1,添加联系人" << endl;
	cout << "2,显示联系人" << endl;
	cout << "3,删除联系人" << endl;
	cout << "4,查找联系人" << endl;
	cout << "5,修改联系人" << endl;
	cout << "6,清空联系人" << endl;
	cout << "0,退出联系人" << endl;
}
//添加联系人
void addPerson(Addresbooks* abs) {
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_size == MAX) {
		cout << "通讯录已满， 无法在添加！" << endl;
		return;
	}
	else {
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		//性别
		cout << "请输入性别： " << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
		while (true) {
			//如果输入的时1或者是2可以退出循环
			//如果输入有误，从新输入
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请从新输入：";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;

		//更新通讯录人数
		abs->m_size++;
		cout << "添加成功：" << endl;
		system("pause");//按任意键
		system("cls");//清屏
	}
}


//删除联系人
//封装检测联系人是否存在
//封装联系人函数
//测试联系人功能

//检测联系人是否存在，如果存在，返回联系人所在数组的具体位置，不存在返回-1
//参数1 通讯录  对比姓名
int isExist(Addresbooks* abs, string name) {
	
	for (int i = 0; i < abs->m_size; i++)
	{
		//找到用户输入的姓名了
		if (abs->personArray[i].m_Name == name)
		{
			return i;//找到了，返回这个人在数组中的下标编号
		}
	}
	return -1;//遍历结束都没有找到，返回-1
}

//删除指定的联系人
void delectPerson(Addresbooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//查找到人了，要进行删除操作
		for (int i = ret; i < abs->m_size; i++) {
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;

	}
	else {
		cout << "查无此人" << endl;

	}
	system("cls");

}


//查找联系人
//判断要查找的指定的联系人是否存在

void findPerson(Addresbooks* abs) {
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//找到联系人
	{
		cout << "姓名：  " << abs->personArray[ret].m_Name << "\t";
		cout << "姓别：  " << (abs->personArray[ret].m_Sex ) << "\t";
		cout << "年龄：  " << abs->personArray[ret].m_Age << "\t";
		cout << "电话：  " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：  " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人";
	}
	system("cls");
}


//修改指定的联系人
void modifyPerson(Addresbooks* abs) {
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {//找到联系人
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;


		//性别
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		cin >> sex;
		while (true) {
			if (sex == 1 || sex == 2) {
				//输入正确，退出循环输入
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "输入有误，请从新输入" << endl;

			}
		}
		
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入地址" << endl; 
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功";
	}
	else {
		cout << "查无此人" << endl;

	}
	system("cls");
}


//情空联系人
void cleanPerson(Addresbooks* abs) {
	abs->m_size = 0;//将当期记录联系人数量置为零，做逻辑清空操作
	cout << "通讯录已清空";
	system("cls");
}
int main() {
	//创建通讯录结构体变量
	Addresbooks abs;
	//初始化通讯录中当前人员的个数
	abs.m_size= 0;
	//创建用户选择输入的变量
	int select = 0;
	while(true){
		//菜单调用
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1, 添加联系人
			addPerson(&abs);//利用地址传递
			break;
		case 2://2, 显示联系人
			showPerson(&abs);
			break;
		//case 3://3, 删除联系人
		//{
		//	cout << "请输入删除联系人的姓名" << endl;
		//	string name;
		//	cin >> name;

		//	if (isExist(&abs, name) == -1) {
		//		cout << "查无此人" << endl;
		//	}
		//	else {
		//		cout << "找到此人" << endl;
		//	}
		//}
			delectPerson(&abs);
			break;
		case 4://4, 查找联系人
			findPerson(&abs);
			break;
		case 5://5, 修改联系人
			modifyPerson(&abs);
			break;
		case 6://6, 清空联系人
			cleanPerson(&abs);
			break;
		case 0://0，退出通讯录
			cout << "欢迎再次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
}
}