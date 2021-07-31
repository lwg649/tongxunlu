//��װ��������ʾ����  ��void showMenu()
//��main �����е��÷�װ�õĺ���
#include<iostream>
#include<string>
#define MAX 1000//�������
using namespace std;
//��ϵ�˽ṹ��
struct Person
{
	string m_Name;//����
	int m_Sex;//�Ա�1�� 2Ů
	int m_Age;	//����
	string m_Phone;//�绰
	string m_Addr;//סַ
};
//ͨѶ¼�ṹ��
struct Addresbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ���
	int m_size;
};

//��ʾ���е���ϵ��
void showPerson(Addresbooks*abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ�㣬���Ϊ�㣬��ʾ��¼Ϊ��
	//�����Ϊ�㣬��ʾ��¼����ϵ�˵���Ϣ
	if (abs->m_size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������  " << abs->personArray[i].m_Name <<"\t" ;
			cout << "�ձ�  " << (abs->personArray[i].m_Sex== 1?"��":"Ů") << "\t";
			cout << "���䣺  " << abs->personArray[i].m_Age << "\t";
			cout << "�绰��  " << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��  " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

void showMenu() {
	cout << "1,�����ϵ��" << endl;
	cout << "2,��ʾ��ϵ��" << endl;
	cout << "3,ɾ����ϵ��" << endl;
	cout << "4,������ϵ��" << endl;
	cout << "5,�޸���ϵ��" << endl;
	cout << "6,�����ϵ��" << endl;
	cout << "0,�˳���ϵ��" << endl;
}
//�����ϵ��
void addPerson(Addresbooks* abs) {
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_size == MAX) {
		cout << "ͨѶ¼������ �޷�����ӣ�" << endl;
		return;
	}
	else {
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true) {
			//��������ʱ1������2�����˳�ѭ��
			//����������󣬴�������
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "����������������룺";
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;

		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ���" << endl;
		system("pause");//�������
		system("cls");//����
	}
}


//ɾ����ϵ��
//��װ�����ϵ���Ƿ����
//��װ��ϵ�˺���
//������ϵ�˹���

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ����������ľ���λ�ã������ڷ���-1
//����1 ͨѶ¼  �Ա�����
int isExist(Addresbooks* abs, string name) {
	
	for (int i = 0; i < abs->m_size; i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�ҵ��ˣ�����������������е��±���
		}
	}
	return -1;//����������û���ҵ�������-1
}

//ɾ��ָ������ϵ��
void delectPerson(Addresbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//���ҵ����ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_size; i++) {
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;//����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;

	}
	else {
		cout << "���޴���" << endl;

	}
	system("cls");

}


//������ϵ��
//�ж�Ҫ���ҵ�ָ������ϵ���Ƿ����

void findPerson(Addresbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{
		cout << "������  " << abs->personArray[ret].m_Name << "\t";
		cout << "�ձ�  " << (abs->personArray[ret].m_Sex ) << "\t";
		cout << "���䣺  " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��  " << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��  " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴���";
	}
	system("cls");
}


//�޸�ָ������ϵ��
void modifyPerson(Addresbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {//�ҵ���ϵ��
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;


		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		cin >> sex;
		while (true) {
			if (sex == 1 || sex == 2) {
				//������ȷ���˳�ѭ������
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "�����������������" << endl;

			}
		}
		
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "�������ַ" << endl; 
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "�޸ĳɹ�";
	}
	else {
		cout << "���޴���" << endl;

	}
	system("cls");
}


//�����ϵ��
void cleanPerson(Addresbooks* abs) {
	abs->m_size = 0;//�����ڼ�¼��ϵ��������Ϊ�㣬���߼���ղ���
	cout << "ͨѶ¼�����";
	system("cls");
}
int main() {
	//����ͨѶ¼�ṹ�����
	Addresbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա�ĸ���
	abs.m_size= 0;
	//�����û�ѡ������ı���
	int select = 0;
	while(true){
		//�˵�����
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1, �����ϵ��
			addPerson(&abs);//���õ�ַ����
			break;
		case 2://2, ��ʾ��ϵ��
			showPerson(&abs);
			break;
		//case 3://3, ɾ����ϵ��
		//{
		//	cout << "������ɾ����ϵ�˵�����" << endl;
		//	string name;
		//	cin >> name;

		//	if (isExist(&abs, name) == -1) {
		//		cout << "���޴���" << endl;
		//	}
		//	else {
		//		cout << "�ҵ�����" << endl;
		//	}
		//}
			delectPerson(&abs);
			break;
		case 4://4, ������ϵ��
			findPerson(&abs);
			break;
		case 5://5, �޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6, �����ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�ٴ�ʹ��" << endl;
			return 0;
			break;
		default:
			break;
		}
}
}