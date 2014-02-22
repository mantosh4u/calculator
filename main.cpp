#include "widget.h"
 
int main(int argc, char *argv[]) 
{
    // Initialization
    Gtk::Main kit(argc, argv);
 
    // Create a hello world window object
    calculator example;
 	example.run();
 	
    // gtkmm main loop
    Gtk::Main::run(example);
    
    return 0;
}
