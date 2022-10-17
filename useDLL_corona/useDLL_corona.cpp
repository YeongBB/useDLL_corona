#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

class corona
{
public:
	corona(string name, int occur, int death);
	void print_inf();
	string n_name;
	int n_occur;
	int n_death;
	double n_death_n;
};

template<class T>
class DLLNode
{
public:
	DLLNode()
	{
		next = prev = NULL;
	}
	DLLNode(const T& el, DLLNode* n = NULL, DLLNode* p = NULL)
	{
		info = el;
		next = n;
		prev = p;
	}
	T info;
	DLLNode* next, * prev;
};

template<class T>
class DLL
{
public:
	DLL()
	{
		head = NULL;
	}

	~DLL()
	{
		for (DLLNode<T>* p = NULL; p != NULL; )
		{
			p = head->next;
			delete head;
			head = p;
		}
	}

	void Add_DLL_sort(const T& el)					//����   ���� �����Ѱ��� �ֱ�
	{
		DLLNode<T>* temp = new DLLNode<T>;
		temp->info = el;
		if (head == NULL)
		{
			head = temp;
			temp->prev = NULL;
			temp->next = NULL;
		}
		else
		{
			DLLNode<T>* pt = head;
			if (pt->head == NULL)					// ��������� ���
			{
				pt->head = el;
				temp = pt->prev;
				pt->prev = temp;
				pt = pt->next;
			}
			else									// ������ ���� ������庸�� Ŭ��
			{
				if (el.n_name > pt->info.n_name)
				{
					while (1)
					{
						if (el.name > pt->info.n_name)
						{
							break;
						}
						pt = pt->next;
					}

				}

				pt->head = pt->next;
				temp = pt->head;
				pt->next->prev = pt->ptev;

			}
		}

	}
	void delete_DLL_sort(const string& name)		//����	������ �̸��� �־������� �����ϱ�
	{
		DLLNode<T>* pt = head;
		while (pt)
		{
			if (pt->info.n_name == name)
			{
				if (pt->prev)
				{
					pt->next->prev = NULL;
					head = pt->next;
				}
				else if (pt->next)
				{
					pt->prev->next = NULL;
				}
				else
				{
					pt->next->prev = pt->ptev;
					pt->prev->next = pt->next;
				}
				delete pt;
				break;
			}
		}
	}
	void print_DLL_sort()							//����
	{
		DLLNode<T>* pt = head;
		while (pt->next != NULL)
		{
			pt->info.print_inf();
			pt = pt->next;
		}
	}

private:
	DLLNode<T>* head;
};

corona::corona(string name, int occur, int death)
{
	n_name = name;
	n_occur = occur;
	n_death = death;
	n_death_n = (n_death / n_occur) * 100.0;
}
void corona::print_inf()
{
	cout.width(10);
	cout << n_name;
	cout.width(10);
	cout << n_occur;
	cout.width(10);
	cout << n_death;
	cout.width(10);
	cout << n_death_n;
}

int main()
{
	DLL<corona> data_;

	data_.Add_DLL_sort(corona("usa", 121231, 12442));
	data_.Add_DLL_sort(corona("china", 15151, 1594));
	data_.Add_DLL_sort(corona("japan", 8135, 4548));

	data_.print_DLL_sort();			// �������� �̸������� ����

	string input;
	cout << "�����ϰ� ���� ���� �̸��� �Է��ϼ���" << " : ";
	cin >> input;
	data_.delete_DLL_sort(input);
	data_.print_DLL_sort();		// �����Ѱ� ���

}

