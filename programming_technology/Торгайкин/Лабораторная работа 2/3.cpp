#include <iostream>
#include <string>
#include <queue>



using namespace std;

void Push(queue <int>& que)
{
	int num;
	cin >> num;
	que.push(num);
	cout << "ok" << endl;
}

void Pop(queue <int>& que)
{
	cout << que.front() << endl;
	que.pop();
}


void Front(const queue <int>& que)
{
	cout << que.front() << endl;
}


void Size(const queue <int>& que)
{
	cout << que.size() << endl;
}

void Clear(queue <int>& que)
{
	while (!que.empty())
	{
		que.pop();
	}

	cout << "ok" << endl;
}



int main()
{
	queue <int> que;
	string command;
	while (true)
	{
		cin >> command;
		if (command == "push")
		{
			Push(que);
		}
		else if (command == "size")
		{
			Size(que);
		}
		else if (command == "clear")
		{
			Clear(que);
		}
		else if (command == "pop" || command == "front")
		{
			if (!que.empty())
			{
				if (command == "pop")
				{
					Pop(que);
				}
				else if (command == "front")
				{
					Front(que);
				}
			}
			else
			{
				cout << "error" << endl;
			}
		}
		else if (command == "exit")
		{
			cout << "bye" << endl;
			break;
		}
	}

}