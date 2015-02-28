#include <iostream>
#include "Object.h"

using namespace std;

void show_met_obj(Metric_Object & obj)
{
	cout << "Weight of object is " << obj.get_weight() << " grams. Volume is " << obj.get_volume() << " cubic centimertres.";
	cout << " So density is approximately " << obj.get_density() << " grams per cubic centimeter. "; 
	cout << "And it is called \"";
	cout << obj.get_name() << "\"." << endl; 
}

void show_brit_obj(British_Object & obj)
{
	cout << "Weight of object is " << obj.get_weight() << " pounds. Volume is " << obj.get_volume() << " cubic inches.";
	cout << " So density is approximately " << obj.get_density() << " punds per cubic inch. "; 
	cout << "And it is called \"";
	cout << obj.get_name() << "\"." << endl;	
}

int main()
{
	{
		Metric_Object book(400, 1500, "Things fall apart"), laptop(2200, 12000, "ProBook 9000"), board_game(2500, 64000, "Arkham Horror");
		show_met_obj(book);
		show_met_obj(laptop);
		show_met_obj(board_game);
	}
	
	cout << endl;
	
	{
		British_Object book(400, 1500, "Great Expextations"), laptop(2200, 12000, "Dixons Retail"), board_game(2500, 64000, "Lost in London");
		show_brit_obj(book);
		show_brit_obj(laptop);
		show_brit_obj(board_game);
	}
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
