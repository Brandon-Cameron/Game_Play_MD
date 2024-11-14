#include <iostream>
#include <vector>

class ArrayState
{
public:
	int arrayElements[6];
	int count;

	void init(int t_array[], int t_count)
	{
		count = t_count;
		for (int i = 0; i < 6; i++)
		{
			arrayElements[i] = t_array[i];
		}
	};
};

void InsertElement()
{

}

int main()
{
	int array[6] = {1, 4, 6, 8};
	

	std::vector<ArrayState> arrayStates;
	ArrayState arrayState;

	arrayState.init(array, 4);
	arrayStates.push_back(arrayState);
}