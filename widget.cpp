#include"widget.h"


/*************************************************************************************************/

button::button()
{
	signal_clicked().connect(sigc::mem_fun(*this, &button::on_button_clicked) );
}


void button::set_name_button(std::string label)
{
	add_label(label);
	set_name(label);
}


void button::on_button_clicked(void)
{
	auto tmp = get_name();
	basicsdisplay(tmp);
	auto tmp2 = property_label();
	display(",Button Clicked");
}


/*************************************************************************************************/

entry::entry()
{
	set_size_request(200,100);
}


void entry::on_button_close(void)
{
	display("Button Close");
}



/*************************************************************************************************/

rowpack::rowpack()
{
	// now pack all objects into one
	row_object.pack_start(m_one);
	row_object.pack_start(s_one);

	row_object.pack_start(m_two);	
	row_object.pack_start(s_two);
	
	row_object.pack_start(m_three);
	row_object.pack_start(s_three);

	row_object.pack_start(m_four);
	row_object.pack_start(s_four);
	
	row_object.pack_start(m_five);
	row_object.pack_start(s_five);

	row_object.pack_start(m_six);	
}



void rowpack::intialize(std::vector<std::string>& label)
{
	auto sz = label.size();
	std::vector<std::string>::size_type index = 0;
	
	if(index < sz) {
		m_one.set_name_button(label.at(index) );
		index = index + 1;
	}
	
	if(index < sz) {
		m_two.set_name_button(label.at(index) );
		index = index + 1;
	}
	
	if(index < sz) {
		m_three.set_name_button(label.at(index) );
		index = index + 1;
	}

	if(index < sz) {
		m_four.set_name_button(label.at(index) );
		index = index + 1;
	}
		
	if(index < sz) {
		m_five.set_name_button(label.at(index) );
		index = index + 1;
	}
	
	if(index < sz) {
		m_six.set_name_button(label.at(index) );
		index = index + 1;
	}
	
}




/*************************************************************************************************/
calculator::calculator()
{
	std::string title {"calculator"};
	set_title(title);
	set_size_request(600, 100);
}




void calculator::run(void)
{	

	// manage display object 
	column_object.pack_start(displ_area);
	column_object.pack_start(displ_sep);
	
		
	// manage first row object
	std::vector<std::string> rone_label{ "7", "8", "9", "/", "bksp", "**"};
	first_robject.intialize(rone_label);
	
	// add the first row object to the main column object
	column_object.pack_start(first_robject.row_object);
	column_object.pack_start(first_sep);


	// manage second row object
	std::vector<std::string> rtwo_label{ "4", "5", "6", "*", "(", ")"};
	second_robject.intialize(rtwo_label);

	// add the second row object to the main column object
	column_object.pack_start(second_robject.row_object);
	column_object.pack_start(second_sep);


	// manage third row object
	std::vector<std::string> rthird_label{ "1", "2", "3", "-", "x^2", "sqrt"};
	third_robject.intialize(rthird_label);

	// add the second row object to the main column object
	column_object.pack_start(third_robject.row_object);
	column_object.pack_start(third_sep);


	// manage four row object
	std::vector<std::string> rfourth_label{ "0", ".", "%", "+", "=", "empt"};
	fourth_robject.intialize(rfourth_label);
	
	// add the second row object to the main column object
	column_object.pack_start(fourth_robject.row_object);


	add(column_object);
	
	show_all_children();
}