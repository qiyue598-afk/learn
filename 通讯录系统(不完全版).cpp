#include<iostream>
#include<string>
#include<limits>
using namespace std;
#define MAX 1000
#define AGEUP 200



struct Person //联系人结构体
{
	string m_Name;//姓名
	int m_Sex;//性别 1.男 2.女
	int m_Age;//年龄
	string m_Phone ;//电话
	string m_Address ;//地址
	int m_Size = 0;
};
 

struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size = 0;
};
//函数声明
void ShowMenu();//菜单面板
void AddPerson(Addressbooks* abs);//添加联系人
void ShowPerson(Addressbooks* abs);//显示通讯录联系人
void deletePerson(Addressbooks* abs,int number);//删除联系人
int itExist(Addressbooks *abs, int size);//参数一通讯录 参数二人物编号
int FindPerson(Addressbooks* abs, string name ,int con);
int ChangePerson(Addressbooks* abs);



int main() {
	
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	

	//用户选择变量
	int select = 0;

	while (true)
	{
		//菜单的调用
		ShowMenu();
		cin >> select;
		switch (select)
		{
		case 1:  //添加联系人
		{
			system("cls");
			AddPerson(&abs); //利用地址传递可以修改实际参数
			break;
		}
		case 2:  //显示联系人
		{
			system("cls");
			ShowPerson(&abs);
			break;
		}
		case 3:  //删除联系人
		{
			int size;
			cout << "请输入要删除的联系人编号，编号为名字前数字，如忘记编号请输入0返回查看" << endl;
			cin >> size;
			if (size == 0)
			{
				system("cls");
				continue;
			}
			else
			{
				int res = itExist(&abs, size);
				if (res == -1)
				{
					cout << "未查询到此联系人请确定编号正确" << endl;
					system("pause");
					system("cls");
					continue;
				}
				else
				{
					int selectsure = 0;
					cout << "此联系人的名字为 ：" << abs.personArray[res].m_Name << endl << "是否确认删除\n删除请按1 取消请按2" << endl;
					cin >> selectsure;
					if (selectsure == 1)
					{
						deletePerson(&abs, res);
						cout << "删除成功" << endl;
						system("pause");
						system("cls");
						continue;
					}
					else if (selectsure == 2)
					{
						cout << "你取消了删除行为" << endl;
						system("pause");
						system("cls");
						continue;
					}
					else
					{
						cout << "请输入正确的确认与否此次行为取消" << endl;
						system("pause");
						system("cls");
						continue;
					}

				}
			}
			break;
		}
			
		case 4:  //查找联系人
		{
			int con = 0;
			string name;
			cout << "请输入要查找的联系人姓名" << endl;
			cin >> name;
			while (true)
			{
				int res = FindPerson(&abs, name, con);
				if (res == -1)
				{
					cout << "没有更多联系人" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
						con = res+1;
						continue;
			     }
			

			}
			break;
		}
			
		case 5:  //修改联系人
			ChangePerson(&abs);
			break;
		case 6:  //清空联系人
			break;
		case 8:  //退出通讯录
			system("cls");
			cout << "欢迎再次使用通讯录系统" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	
	

	return 0;
}


//1菜单界面
void ShowMenu()
{
	cout<< "**********************\n"
		<< "*****1.添加联系人*****\n"
		<< "*****2.显示联系人*****\n"
		<< "*****3.删除联系人*****\n"
		<< "*****4.查找联系人*****\n"
		<< "*****5.修改联系人*****\n"
		<< "*****6.清空联系人*****\n"
		<< "*****8.退出通讯录*****\n" 
		<< "**********************\n"
		<< endl;
}






void AddPerson(Addressbooks* abs)
{
	// 判断通讯录是否已经满了，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已经满员" << endl;
		return ;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名 ：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别 : " << endl << "1.男 2.女" << endl;
		

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "请输入正确编号\n 1 -- 男 2 -- 女" << endl;
			}
		}
		
	 
		//年龄
		cout << "请输入年龄" << endl;
		int age = 1;
		while (true)
		{
			
			cin >> age;
			if (cin.fail() || age  > 200 || age < 0)
			{
				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "请输入正确年龄" << endl;
				continue;
			}
			else
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
		}
		
		

		//电话
		cout << "请输入联系电话" << endl;
	
		
		string phone = "0";
		while (true)
		{
			cin >> phone;
			size_t len = phone.size();
			if (len == 11)
			{
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			else
			{
				cout << "请输入正确的11位数电话号码" << endl;
			}
			

		}
		

		//住址
		cout << "请输入家庭住址" << endl;
		string address = "0";
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;

		//更新通讯录人数
		abs->m_Size++;
		abs->personArray[abs->m_Size].m_Size = abs->m_Size;
		cout << abs->personArray[abs->m_Size].m_Size << endl;
		cout << "添加成功 ：" << abs->m_Size << ". " << name << endl;
		system("pause"); //按下任意键继续
		system("cls"); //清屏
		

	}
}


void ShowPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << abs->personArray[i+1].m_Size << ". " << "\t";
			cout << "姓名 :" << abs->personArray[i].m_Name << "\t";
			cout << "年龄 :" << abs->personArray[i].m_Age << "\t";
			if(abs->personArray[i].m_Sex == 1)
			{
				cout << "性别 :男" << "\t";
			}
				
			if (abs->personArray[i].m_Sex == 2)
			{
				cout << "性别 :女" << "\t";
			}
			//cout << "性别 :" << (abs->personArray[i].m_Sex == 1 ?"男":"女") << "\t"; //另一种表达方式
			cout << "手机号 :" << abs->personArray[i].m_Phone << "\t";
			cout << "住址 :" << abs->personArray[i].m_Address << endl;
		}
	}

	system("pause");
	system("cls");
}


int itExist(Addressbooks* abs, int size )
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i+1].m_Size == size)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs , int number)
{
	for (int i = number; i < abs->m_Size;i++)
	{
		abs->personArray[i] = abs->personArray[i + 1];
		abs->personArray[i].m_Size--;
	}
	abs->m_Size--;
	abs->personArray->m_Size--;
	
}





int FindPerson(Addressbooks* abs, string name , int con)
{
	 
	for (int i = con; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
		
			cout << "发现此联系人 :" 
				<< "姓名：" << abs->personArray[i].m_Name << '\t' 
				<< "年龄：" << abs->personArray[i].m_Age << '\t' 
				<< "性别 :" << abs->personArray[i].m_Sex << '\t' 
				<< "电话："  << abs->personArray[i].m_Phone << '\t'
				<< "住址：" << abs->personArray[i].m_Address << '\t' 
				<< "编号：" << abs->personArray[i + 1].m_Size  << endl;
			return i;
		}
		
	}
	return -1;

}
