/*
 *
 *   "Lottery Analysis" by Ethan Och (c) 2017
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	string cont = "";
	while (!(cont == "n" || cont == "N" || cont == "0"))
	{
		cout << "----------------------------------------" << endl;
		cout << "\"Lottery Analysis\" by Ethan Och (c) 2017" << endl;
		cout << "----------------------------------------" << endl << endl;

		string mode = "", type = "", entry = "", filename = "";
		int first[250], second[250], third[250], fourth[250], fifth[250], sixth[250], index = 0, x = 0;

		for (int i = 0; i < 250; i++)
		{
			first[i] = 0;
			second[i] = 0;
			third[i] = 0;
			fourth[i] = 0;
			fifth[i] = 0;
			sixth[i] = 0;
		}

		cout << "Choose mode: MANUAL entry or AUTOMATIC entry." << endl;

		while (!(mode == "m" || mode == "M" || mode == "1" || mode == "a" || mode == "A" || mode == "2"))
		{
			cin >> mode;
			mode = mode.at(0);
		}

		cout << endl;

		if (mode == "m" || mode == "M" || mode == "1")
		{
			cout << "Choose type: FIVE number or SIX number." << endl;

			while (!(type == "f" || type == "F" || type == "5" || type == "s" || type == "S" || type == "6"))
			{
				cin >> type;
				type = type.at(0);
			}

			cout << endl;

			if (type == "f" || type == "F" || type == "5")
			{
				cout << "Enter numbers in the form: XX XX XX XX XX." << endl << "Enter END to stop." << endl;

				while (!(cin >> x))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				while (!(entry == "end" || entry == "END"))
				{
					if (isdigit(entry[0]))
					{
						x = atoi(entry.c_str());
					}
					first[index] = x;

					while (!(cin >> x))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					second[index] = x;

					while (!(cin >> x))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					third[index] = x;

					while (!(cin >> x))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					fourth[index] = x;

					while (!(cin >> x))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					fifth[index] = x;

					index++;

					cin >> entry;
				}

				cout << endl;
			}
			else
			{
				cout << "Enter numbers in the form: XX XX XX XX XX XX." << endl << "Enter END to stop." << endl;

				while (!(cin >> x))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				while (!(entry == "end" || entry == "END"))
				{
					if (isdigit(entry[0]))
					{
						x = atoi(entry.c_str());
					}
					first[index] = x;

					while (!(cin >> x))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					second[index] = x;

					while (!(cin >> x))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					third[index] = x;

					while (!(cin >> x))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					fourth[index] = x;

					while (!(cin >> x))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					fifth[index] = x;

					while (!(cin >> x))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					sixth[index] = x;

					index++;

					cin >> entry;
				}

				cout << endl;
			}
		}
		else
		{
			ifstream file;
			int date;
			char fill;

			cout << "Choose type: FIVE number or SIX number." << endl;

			while (!(type == "f" || type == "F" || type == "5" || type == "s" || type == "S" || type == "6"))
			{
				cin >> type;
				type = type.at(0);
			}

			cout << endl;

			if (type == "f" || type == "F" || type == "5")
			{
			enterfive:

				cout << "Enter name of text file to analyze: ";
				cin >> filename;

				file.open(filename.c_str());

				if (file.is_open())
				{
					cout << "Reading data..." << endl;
					file >> date;

					while (true)
					{
						file >> fill;
						file >> date;
						file >> fill;
						file >> date;

						file >> first[index];
						file >> second[index];
						file >> third[index];
						file >> fourth[index];
						file >> fifth[index];

						cout << first[index] << " " << second[index] << " " << third[index] << " " << fourth[index] << " " << fifth[index] << endl;

						file >> date;
						index++;

						if (file.eof())
						{
							break;
						}
					}

					cout << "Done." << endl << endl;
				}
				else
				{
					cout << "Error opening file." << endl << "Aborted." << endl << endl;

					goto enterfive;
				}

				file.close();
			}
			else
			{
			entersix:

				cout << "Enter name of text file to analyze: ";
				cin >> filename;

				file.open(filename.c_str());

				if (file.is_open())
				{
					cout << "Reading data..." << endl;
					file >> date;

					while (true)
					{
						file >> fill;
						file >> date;
						file >> fill;
						file >> date;

						file >> first[index];
						file >> second[index];
						file >> third[index];
						file >> fourth[index];
						file >> fifth[index];
						file >> sixth[index];

						cout << first[index] << " " << second[index] << " " << third[index] << " " << fourth[index] << " " << fifth[index] << " " << sixth[index] << endl;

						file >> fill;
						file >> date;
						file >> date;
						index++;

						if (file.eof())
						{
							break;
						}
					}

					cout << "Done." << endl << endl;
				}
				else
				{
					cout << "Error opening file." << endl << "Aborted." << endl << endl;

					goto entersix;
				}

				file.close();
			}
		}

		cout << "Results:" << endl;

		int total = 0;
		double one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;

		index = 0;

		while (!(first[index] == 0))
		{
			total++;
			index++;
		}

		for (int i = 0; i < total; i++)
		{
			one = one + first[i];
			two = two + second[i];
			three = three + third[i];
			four = four + fourth[i];
			five = five + fifth[i];
			six = six + sixth[i];
		}

		one = one / total;
		two = two / total;
		three = three / total;
		four = four / total;
		five = five / total;
		six = six / total;

		one = round(one);
		two = round(two);
		three = round(three);
		four = round(four);
		five = round(five);
		six = round(six);

		cout << "Average numbers: " << one << " " << two << " " << three << " " << four << " " << five;

		if (type == "s" || type == "S" || type == "6")
		{
			cout << " " << six;
		}

		cout << endl;

		int occur = 0;
		double rate = 0;

		for (int i = 0; i < total; i++)
		{
			if (first[i] == one)
			{
				occur++;
			}
		}

		cout << "Occurrences of first number: " << occur << endl;

		rate = ((occur * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		occur = 0;

		for (int i = 0; i < total; i++)
		{
			if (second[i] == two)
			{
				occur++;
			}
		}

		cout << "Occurrences of second number: " << occur << endl;

		rate = ((occur * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		occur = 0;

		for (int i = 0; i < total; i++)
		{
			if (third[i] == three)
			{
				occur++;
			}
		}

		cout << "Occurrences of third number: " << occur << endl;

		rate = ((occur * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		occur = 0;

		for (int i = 0; i < total; i++)
		{
			if (fourth[i] == four)
			{
				occur++;
			}
		}

		cout << "Occurrences of fourth number: " << occur << endl;

		rate = ((occur * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		occur = 0;

		for (int i = 0; i < total; i++)
		{
			if (fifth[i] == five)
			{
				occur++;
			}
		}

		cout << "Occurrences of fifth number: " << occur << endl;

		rate = ((occur * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		if (type == "s" || type == "S" || type == "6")
		{
			occur = 0;

			for (int i = 0; i < total; i++)
			{
				if (sixth[i] == six)
				{
					occur++;
				}
			}

			cout << "Occurrences of sixth number: " << occur << endl;

			rate = ((occur * 1.0) / (total * 1.0)) * 100.0;

			cout << "Rate of occurrence: " << rate << "%" << endl;
		}

		int nums[100], count[250];

		cout << endl << "Most frequent numbers:";

		for (int i = 0; i < 100; i++)
		{
			nums[i] = i + 1;
		}

		for (int i = 0; i < 250; i++)
		{
			count[i] = 0;
		}

		for (int i = 0; i < total; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (first[i] == nums[j])
				{
					count[j] += 1;
				}
			}
		}

		int maxone = count[0];

		for (int i = 1; i < 100; i++)
		{
			if (count[i - 1] <= count[i])
			{
				maxone = count[i];
			}
			else
			{
				maxone = count[i - 1];
				count[i] = count[i - 1];
			}
		}

		for (int i = 0; i < total; i++)
		{
			if (maxone == count[i])
			{
				one = i + 1;
				cout << " " << one;
				break;
			}
		}

		for (int i = 0; i < 250; i++)
		{
			count[i] = 0;
		}

		for (int i = 0; i < total; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (second[i] == nums[j])
				{
					count[j] += 1;
				}
			}
		}

		int maxtwo = count[0];

		for (int i = 1; i < 100; i++)
		{
			if (count[i - 1] <= count[i])
			{
				maxtwo = count[i];
			}
			else
			{
				maxtwo = count[i - 1];
				count[i] = count[i - 1];
			}
		}

		for (int i = 0; i < total; i++)
		{
			if (maxtwo == count[i])
			{
				two = i + 1;
				cout << " " << two;
				break;
			}
		}

		for (int i = 0; i < 250; i++)
		{
			count[i] = 0;
		}

		for (int i = 0; i < total; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (third[i] == nums[j])
				{
					count[j] += 1;
				}
			}
		}

		int maxthree = count[0];

		for (int i = 1; i < 100; i++)
		{
			if (count[i - 1] <= count[i])
			{
				maxthree = count[i];
			}
			else
			{
				maxthree = count[i - 1];
				count[i] = count[i - 1];
			}
		}

		for (int i = 0; i < total; i++)
		{
			if (maxthree == count[i])
			{
				three = i + 1;
				cout << " " << three;
				break;
			}
		}

		for (int i = 0; i < 250; i++)
		{
			count[i] = 0;
		}

		for (int i = 0; i < total; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (fourth[i] == nums[j])
				{
					count[j] += 1;
				}
			}
		}

		int maxfour = count[0];

		for (int i = 1; i < 100; i++)
		{
			if (count[i - 1] <= count[i])
			{
				maxfour = count[i];
			}
			else
			{
				maxfour = count[i - 1];
				count[i] = count[i - 1];
			}
		}

		for (int i = 0; i < total; i++)
		{
			if (maxfour == count[i])
			{
				four = i + 1;
				cout << " " << four;
				break;
			}
		}

		for (int i = 0; i < 250; i++)
		{
			count[i] = 0;
		}

		for (int i = 0; i < total; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (fifth[i] == nums[j])
				{
					count[j] += 1;
				}
			}
		}

		int maxfive = count[0];

		for (int i = 1; i < 100; i++)
		{
			if (count[i - 1] <= count[i])
			{
				maxfive = count[i];
			}
			else
			{
				maxfive = count[i - 1];
				count[i] = count[i - 1];
			}
		}

		for (int i = 0; i < total; i++)
		{
			if (maxfive == count[i])
			{
				five = i + 1;
				cout << " " << five;
				break;
			}
		}

		int maxsix;

		if (type == "s" || type == "S" || type == "6")
		{
			for (int i = 0; i < 250; i++)
			{
				count[i] = 0;
			}

			for (int i = 0; i < total; i++)
			{
				for (int j = 0; j < 100; j++)
				{
					if (sixth[i] == nums[j])
					{
						count[j] += 1;
					}
				}
			}

			maxsix = count[0];

			for (int i = 1; i < 100; i++)
			{
				if (count[i - 1] <= count[i])
				{
					maxsix = count[i];
				}
				else
				{
					maxsix = count[i - 1];
					count[i] = count[i - 1];
				}
			}

			for (int i = 0; i < total; i++)
			{
				if (maxsix == count[i])
				{
					six = i + 1;
					cout << " " << six;
					break;
				}
			}
		}

		cout << endl;

		cout << "Occurrences of first number: " << maxone << endl;

		rate = ((maxone * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		cout << "Occurrences of second number: " << maxtwo << endl;

		rate = ((maxtwo * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		cout << "Occurrences of third number: " << maxthree << endl;

		rate = ((maxthree * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		cout << "Occurrences of fourth number: " << maxfour << endl;

		rate = ((maxfour * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		cout << "Occurrences of fifth number: " << maxfive << endl;

		rate = ((maxfive * 1.0) / (total * 1.0)) * 100.0;

		cout << "Rate of occurrence: " << rate << "%" << endl;

		if (type == "s" || type == "S" || type == "6")
		{
			cout << "Occurrences of sixth number: " << maxsix << endl;

			rate = ((maxsix * 1.0) / (total * 1.0)) * 100.0;

			cout << "Rate of occurrence: " << rate << "%" << endl;
		}

		cout << endl << "Would you like to enter another set of numbers?" << endl << "Choose one: YES or NO" << endl;
		cin >> cont;
		cont = cont.at(0);

		cout << endl << endl << endl;
	}

	return 0;
}