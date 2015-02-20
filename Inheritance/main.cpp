#include <iostream>
#include "Object.h"

using namespace std;

void show_gen_obj(General_Object & obj)
{
	cout << "Weight of object is " << obj.get_weight() << " grams. Volume is " << obj.get_volume() << " cubic centimertres.";
	cout << " So density is approximately " << obj.get_density() << " grams per cubic centimeter. "; 
	cout << "And it is called \"";
	cout << obj.get_name() << "\"." << endl; 
}

int main()
{
	General_Object book(400, 1500, "Things fall apart"), laptop(2200, 12000, "ProBook 9000"), game(2500, 64000, "Arkham Horror");
	show_gen_obj(book);
	show_gen_obj(laptop);
	show_gen_obj(game);
    system("PAUSE");
    return EXIT_SUCCESS;
}
