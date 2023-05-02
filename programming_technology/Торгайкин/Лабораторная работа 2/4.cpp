#include <iostream>
#include <string>
#include <queue>



using namespace std;

void Clear(priority_queue <int>& que)
{
	while (!que.empty())
	{
		que.pop();
	}
}

void Add(priority_queue <int>& que)
{
	int num;
	cin >> num;
	que.push(num);

}

void Extract(priority_queue <int>& que)
{
	if (que.empty())
	{
		cout << "CANNOT" << endl;
	}
	else
	{
		cout << que.top() << endl;
		que.pop();
	}
}


int main()
{
	priority_queue <int> que;
	string command;

	while (cin >> command)
	{

		if (command == "CLEAR")
		{
			Clear(que);
		}
		else if (command == "ADD")
		{

			Add(que);

		}
		else if (command == "EXTRACT")
		{
			Extract(que);
		}

	}

}