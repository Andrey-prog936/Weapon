#include <iostream>
#include <fstream>
using namespace std;
class Weapon
{
	private:
		int range_shot;
		float caliber;
		int bullets;
		int max_bullets;

public:
	void Initialize()
	{
		range_shot = 50;
		caliber = 9;
		bullets = 12;
		max_bullets = 17;
	}

	bool Shot()
	{
		if (bullets > 0)
			bullets--;
		else
			cout << "The store is empty" << endl;
		return bullets;
	}

	void Recharge()
	{
		bullets = max_bullets;
	}

	void Save() const
	{
		ofstream fout;
		fout.open("Saves.txt",ios_base::app);  // , fstream::app
		bool isOpen = fout.is_open();
		if (isOpen == true)
		{
			// cout << "Fout Opened" << endl;
			ofstream rewrite("Saves.txt");
			rewrite.write("", 0);
			rewrite.close();
			fout << range_shot << endl;
			fout << caliber << endl;
			fout << bullets << endl;
			fout << max_bullets << endl;
		}
		else
			cout << "File not find" << endl;
	}

	void Load()
	{
		ifstream fin;
		fin.open("Saves.txt");
		bool isOpen = fin.is_open();
		if (isOpen == true)
		{
			// cout << "Fin Opened" << endl;
			if (fin)
			{
				fin >> range_shot >> caliber >> bullets >> max_bullets;
			}
			else
				cout << "Error!" << endl;
		}
		else
		{
			cout << "File not find" << endl;
		}
	}
};

int main() {
	Weapon glock;
	glock.Initialize();
	glock.Shot(); // -1 bullets
	// glock.Recharge(); // reload
	glock.Save();
	glock.Load();
	
	system("pause");
	return 0;
}